#include <raylib.h>
#include "Player.h"
#include "raylib.h" // Assuming raylib.h is the appropriate header for Raylib in C++

Player::Player(int x, int y, int width, int height, int speed, int health, int screenwidth, int screenheight, int player_num)
   : _speed(speed), _health(health), _screenwidth(screenwidth), _screenheight(screenheight), _player_num(player_num) {
   body.x = x;
   body.y = y;
   body.width = width;
   body.height = height;
}

void Player::MoveRectangle() {
   if (_player_num == 1) {
      if (IsKeyDown(KEY_DOWN)) {
         if (body.y < (_screenheight - body.height)) {
            body.y += _speed;
            if (body.y > (_screenheight - body.height)) {
               body.y = _screenheight - body.height;
            }
         }
      }
      if (IsKeyDown(KEY_UP)) {
         if (body.y > 0) {
            body.y -= _speed;
            if (body.y < (0)) {
               body.y = 0;
            }
         }
      }
      if (IsKeyDown(KEY_LEFT)) {
         if (body.x > 0) {
            body.x -= _speed;
            if (body.x < (0)) {
               body.x = 0;
            }
         }
      }
      if (IsKeyDown(KEY_RIGHT)) {
         if (body.x < _screenwidth - body.width) {
            body.x += _speed;
            if (body.x > (_screenwidth - body.width)) {
               body.x = _screenwidth - body.width;
            }
         }
      }
   }
   else {
      if (IsKeyDown(KEY_S)) {
         if (body.y < (_screenheight - body.height)) {
            body.y += _speed;
            if (body.y > (_screenheight - body.height)) {
               body.y = _screenheight - body.height;
            }
         }
      }
      if (IsKeyDown(KEY_W)) {
         if (body.y > 0) {
            body.y -= _speed;
            if (body.y < (0)) {
               body.y = 0;
            }
         }
      }
      if (IsKeyDown(KEY_A)) {
         if (body.x > 0) {
            body.x -= _speed;
            if (body.x < (0)) {
               body.x = 0;
            }
         }
      }
      if (IsKeyDown(KEY_D)) {
         if (body.x < _screenwidth - body.width) {
            body.x += _speed;
            if (body.x > (_screenwidth - body.width)) {
               body.x = _screenwidth - body.width;
            }
         }
      }
   }
}
