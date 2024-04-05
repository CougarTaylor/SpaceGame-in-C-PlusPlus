#pragma once
#include <raylib.h>

#include "Box.h"

class Stars : public Box 
{
public:
   Stars(int x, int y, int width, int height, int speed);
};

