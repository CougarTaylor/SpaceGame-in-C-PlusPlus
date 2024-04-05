#pragma once

#include "raylib.h"
#include <string>
#include "Player.h" // Assuming Player class is defined in Player.h

class Box {
public:
   int _speed;
   float _y_speed;
   Rectangle body;
   std::string _type;

   Box(int x, int y, int width, int height, int speed, float y_speed);

   void MoveLeft();

   void MoveVertical();

   virtual void AffectPlayer(Player player1);
};