#pragma once
#include <raylib.h>
#include "Box.h"
#include "Player.h"

class Asteroid : public Box {
public:
   Asteroid(int x, int y, int width, int height, int speed, float y_speed);
   virtual void AffectPlayer(Player& player1) override;
};
