#pragma once

#include <vector>
#include "Box.h"
#include "Stars.h"
#include "DodgeMe.h"
#include "HitMe.h"
#include "FreeHealth.h"
#include "Asteroid.h"
#include "Player.h"

class WorldManager {
private:
   int _screenwidth;
   int _screenheight;
   int _dodgemecounter = 0;
   int _hitMecounter = 0;
   int _asteroidcounter = 0;
   int _StartOfGameTimer = 0;
   int _AteroidSpawnTime = 30;
   int _freeHealthcounter = 0;

public:
   std::vector<Stars> AllStar;
   std::vector<Box> Particles;
   std::vector<Box> Lives;
   std::vector<float> VerticleSpeeds;
   WorldManager(int screenwidth, int screenheight);
   void RandomDodgeMe();
   void RandomHitMe();
   void RandomFreeHealth();
   void SendAsteroid();
   void SeeTheStars();
   void ShowHealth(Player player1);
};
