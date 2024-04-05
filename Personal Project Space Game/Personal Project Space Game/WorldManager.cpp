#include <raylib.h>
#include <cstring>
#include "WorldManager.h"
#include <cstdlib> // for random numbers
#include <ctime> // for seeding random number generator
#include "Stars.h"
WorldManager::WorldManager(int screenwidth, int screenheight)
   : _screenwidth(screenwidth), _screenheight(screenheight) {
   // Seed the random number generator
   std::srand(static_cast<unsigned int>(std::time(nullptr)));

   // Initialize vertical speeds
   VerticleSpeeds = { -0.5f, 0, 0, 0, 0, 0, 0.5f, -0.3f, 0.3f };
}

void WorldManager::RandomDodgeMe() {
   if (_dodgemecounter == 100) {
      int randomWidth = std::rand() % 8 + 13;
      int randomHeight = std::rand() % 8 + 13;
      int random_y_Value = std::rand() % (_screenheight - randomHeight);
      int randomSpeed = std::rand() % 5 + 5;
      DodgeMe dodgeme(_screenwidth, random_y_Value, randomWidth, randomHeight, randomSpeed, 0);
      Particles.push_back(dodgeme);
      _dodgemecounter = 0;
   }
   _dodgemecounter++;
}

void WorldManager::RandomHitMe() {
   if (_hitMecounter == 200) {
      int randomWidth = std::rand() % 8 + 13;
      int randomHeight = std::rand() % 8 + 13;
      int random_y_Value = std::rand() % (_screenheight - randomHeight);
      int randomSpeed = std::rand() % 5 + 5;
      HitMe hitMe(_screenwidth, random_y_Value, randomWidth, randomHeight, randomSpeed, 0);
      Particles.push_back(hitMe);
      _hitMecounter = 0;
   }
   _hitMecounter++;
}

void WorldManager::RandomFreeHealth() {
   if (_freeHealthcounter == 200) {
      int randomWidth = std::rand() % 8 + 13;
      int randomHeight = std::rand() % 8 + 13;
      int random_y_Value = std::rand() % (_screenheight - randomHeight);
      int randomSpeed = std::rand() % 5 + 5;
      FreeHealth freeHealth(_screenwidth, random_y_Value, randomWidth, randomHeight, randomSpeed, 0);
      Particles.push_back(freeHealth);
      _freeHealthcounter = 0;
   }
   _freeHealthcounter++;
}

void WorldManager::SendAsteroid() {
   if (_asteroidcounter >= _AteroidSpawnTime) {
      int randomWidth = std::rand() % 11 + 30;
      int random_y_Value = std::rand() % (_screenheight - randomWidth);
      int randomSpeed = std::rand() % 3 + 4;
      float random_y_speed = VerticleSpeeds[std::rand() % VerticleSpeeds.size()];
      Asteroid asteroid(_screenwidth, random_y_Value, randomWidth, randomWidth, randomSpeed, random_y_speed);
      Particles.push_back(asteroid);
      _asteroidcounter = 0;
   }
   _asteroidcounter++;
   _StartOfGameTimer++;
   if (_StartOfGameTimer >= 500) {
      _AteroidSpawnTime -= 2;
      _StartOfGameTimer = 0;
   }
}

void WorldManager::SeeTheStars() {
   int randomWidth = std::rand() % 3 + 5;
   int randomHeight = std::rand() % 3 + 5;
   int random_y_Value = std::rand() % (_screenheight - randomHeight);
   int randomSpeed = std::rand() % 6 + 8;
   Stars stars(_screenwidth, random_y_Value, randomWidth, randomHeight, randomSpeed);
   AllStar.push_back(stars);
}

void WorldManager::ShowHealth(Player player1) {
   Lives.clear();
   for (int i = 0; i < player1._health; i++) {
      int Width = 8;
      int Height = 12;
      int x_Value = 5 + (i * 10);
      Box life(x_Value, 5, Width, Height, 0, 0);
      Lives.push_back(life);
   }
}