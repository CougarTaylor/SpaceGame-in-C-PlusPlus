#include "raylib.h"
#include <string>
#include "Box.h"

Box::Box(int x, int y, int width, int height, int speed, float y_speed)
   : _speed(speed), _y_speed(y_speed) {
   body.x = x;
   body.y = y;
   body.width = width;
   body.height = height;
}

void Box::MoveLeft() {
   body.x -= _speed;
}

void Box::MoveVertical() {
   body.y += _y_speed;
}

void Box::AffectPlayer(Player player1) 
{
   // To be changed
}