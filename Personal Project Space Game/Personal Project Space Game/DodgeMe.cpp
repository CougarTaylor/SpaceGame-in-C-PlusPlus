#include <raylib.h>
#include "DodgeMe.h"

DodgeMe::DodgeMe(int x, int y, int width, int height, int speed, int y_speed)
   : Box(x, y, width, height, speed, y_speed) {
   _type = "dodgeMe";
}

void DodgeMe::AffectPlayer(Player& player1) {
   player1._speed = 2;
}