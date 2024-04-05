#include <raylib.h>
#include "HitMe.h"

HitMe::HitMe(int x, int y, int width, int height, int speed, int y_speed)
   : Box(x, y, width, height, speed, y_speed) {
   _type = "hitMe";
}

void HitMe::AffectPlayer(Player& player1) {
   player1._speed = 8;
}