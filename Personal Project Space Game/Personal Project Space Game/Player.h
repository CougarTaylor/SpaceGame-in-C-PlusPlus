#pragma once
#include <raylib.h>

#include "raylib.h" // Assuming raylib.h is the appropriate header for Raylib in C++

class Player {
public:
   int _speed;
   int _health;
   int _screenwidth;
   int _screenheight;
   int _player_num;
   Rectangle body;

   Player(int x, int y, int width, int height, int speed, int health, int screenwidth, int screenheight, int player_num);

   void MoveRectangle();
};

