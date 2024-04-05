#include "raylib.h" // Assuming raylib.h is the appropriate header for Raylib in C++
#include "Player.h"
#include "WorldManager.h"
#include <iostream>
#include <chrono>

int main() {
   int screenwidth = 1200; //800
   int screenheight = 800; //450
   std::vector<Player> Players = {
       Player(200, 200, 35, 20, 5, 5, screenwidth, screenheight, 2),
       Player(200, 200, 35, 20, 5, 5, screenwidth, screenheight, 1)
   };
   WorldManager NewWorld(screenwidth, screenheight);

   InitWindow(screenwidth, screenheight, "The Game");
   SetTargetFPS(50);
   auto endTime = std::chrono::system_clock::now();
   NewWorld.ShowHealth(Players[0]);
   int points = 0;

   while (!WindowShouldClose()) {
      auto startTime = std::chrono::system_clock::now();

      BeginDrawing();
      ClearBackground(BLACK);

      for (Box lives : NewWorld.Lives) {
         DrawRectangleRec(lives.body, GOLD);
      }

      for (Stars stars : NewWorld.AllStar) {
         DrawRectangleRec(stars.body, RAYWHITE);
      }

      for (Box item : NewWorld.Particles) {
         if (item._type == "asteroid") {
            DrawRectangleRec(item.body, GRAY);
         }
         else if (item._type == "hitMe") {
            DrawRectangleRec(item.body, BLUE);
         }
         else if (item._type == "freeHealth") {
            DrawRectangleRec(item.body, PURPLE);
         }
         else if (item._type == "dodgeMe") {
            DrawRectangleRec(item.body, RED);
         }
      }

      DrawText(TextFormat("%i", points), screenwidth - 80, 20, 20, LIGHTGRAY);
      DrawRectangleRec(Players[0].body, DARKGRAY);
      DrawRectangleRec(Players[1].body, LIME);
      EndDrawing();

      for (int i = 0; i < NewWorld.AllStar.size(); i++) {
         NewWorld.AllStar[i].MoveLeft();
         if (NewWorld.AllStar[i].body.x < 0 - NewWorld.AllStar[i].body.width) {
            NewWorld.AllStar.erase(NewWorld.AllStar.begin() + i);
         }
      }

      for (int i = 0; i < NewWorld.Particles.size(); i++) {
         NewWorld.Particles[i].MoveLeft();
         NewWorld.Particles[i].MoveVertical();
         if (NewWorld.Particles[i].body.x < 0 - NewWorld.Particles[i].body.width) {
            NewWorld.Particles.erase(NewWorld.Particles.begin() + i);
         }

         for (Player& player : Players) {
            if (CheckCollisionRecs(player.body, NewWorld.Particles[i].body)) {
               if (NewWorld.Particles[i]._type == "hitMe") {
                  NewWorld.Particles[i].AffectPlayer(player);
                  endTime = startTime + std::chrono::seconds(4);
                  NewWorld.Particles.erase(NewWorld.Particles.begin() + i);
               }
               else if (NewWorld.Particles[i]._type == "freeHealth") {
                  NewWorld.Particles[i].AffectPlayer(player);
                  NewWorld.ShowHealth(player);
                  NewWorld.Particles.erase(NewWorld.Particles.begin() + i);
                  if (player._health == 5) {
                     points += 1000;
                  }
               }
               else if (NewWorld.Particles[i]._type == "dodgeMe") {
                  NewWorld.Particles[i].AffectPlayer(player);
                  endTime = startTime + std::chrono::seconds(4);
                  NewWorld.Particles.erase(NewWorld.Particles.begin() + i);
               }
               else if (NewWorld.Particles[i]._type == "asteroid") {
                  NewWorld.Particles[i].AffectPlayer(player);
                  NewWorld.ShowHealth(player);

                  if (player._health > 0) {
                     NewWorld.Particles.erase(NewWorld.Particles.begin() + i);
                  }
                  else {
                     return 0;
                  }
               }
               if (startTime >= endTime) {
                  player._speed = 5;
               }
            }
         }
      }
      points++;
      NewWorld.SeeTheStars();
      NewWorld.RandomHitMe();
      NewWorld.RandomFreeHealth();
      NewWorld.RandomDodgeMe();
      NewWorld.SendAsteroid();
      Players[0].MoveRectangle();
      Players[1].MoveRectangle();
   }
   CloseWindow();
   return 0;
}