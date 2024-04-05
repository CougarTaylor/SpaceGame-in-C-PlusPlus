#pragma once
#include <raylib.h>
#include "Box.h"
#include "Player.h"

class HitMe : public Box {
public:
   HitMe(int x, int y, int width, int height, int speed, int y_speed);
   virtual void AffectPlayer(Player& player1) override;
};
