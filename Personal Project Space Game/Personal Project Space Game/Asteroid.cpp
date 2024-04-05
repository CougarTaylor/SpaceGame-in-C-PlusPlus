#include "raylib.h"
#include "Box.cpp"
#include "Asteroid.h"

Asteroid::Asteroid(int x, int y, int width, int height, int speed, float y_speed)
   : Box(x, y, width, height, speed, y_speed) {
   _type = "asteroid";
}

void Asteroid::AffectPlayer(Player& player1) {
   player1._health -= 1;
}
