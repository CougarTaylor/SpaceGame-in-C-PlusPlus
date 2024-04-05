#pragma once
#include <raylib.h>

#include "Box.h"
#include "Player.h"
#ifndef DODGEME_H
#define DODGEME_H

class DodgeMe : public Box {
public:
   DodgeMe(int x, int y, int width, int height, int speed, int y_speed);
   virtual void AffectPlayer(Player& player1) override;
};

#endif // DODGEME_H