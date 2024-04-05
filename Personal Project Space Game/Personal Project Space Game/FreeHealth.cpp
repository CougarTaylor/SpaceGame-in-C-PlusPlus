#include <raylib.h>
#include "FreeHealth.h"

FreeHealth::FreeHealth(int x, int y, int width, int height, int speed, int y_speed)
   : Box(x, y, width, height, speed, y_speed) {
   _type = "freeHealth";
}

void FreeHealth::AffectPlayer(Player& player1) {
   if (player1._health < 5) {
      player1._health += 1;
   }
}