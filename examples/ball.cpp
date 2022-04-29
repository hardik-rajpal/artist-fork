/*=============================================================================
   Copyright (c) 2016-2020 Joel de Guzman

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#include "app.hpp"
#include <cstdlib>
#include<vector>
#include<unistd.h>
#include<iostream>
#include<thread>
using namespace cycfi::artist;
#include"host/linux/cycoop/CycShape.h"
#include"host/linux/cycoop/CycCanvas.h"
#include"host/linux/cycoop/CycSprite.h"

///////////////////////////////////////////////////////////////////////////////
// Ported from Rainbow Rain animation:
// https://onaircode.com/awesome-html5-canvas-examples-source-code/
///////////////////////////////////////////////////////////////////////////////

#if defined(ARTIST_SKIA) && !defined(linux)
constexpr auto persistence = 0.10;
#else
constexpr auto persistence = 0.04;
#endif
constexpr auto window_size = extent{ 640, 360 };
constexpr float radius = 10;
float posx = 100;
float posy = 100;
int velx[5];
int vely[5];
float opacity = 1.0;
int numRuns = 0;
int main(int argc, char const* argv[])
{
   
   CycCanvas c(argc, argv, window_size,colors::gray[10]);   
   // CycCanvas c2(argc, argv, window_size,colors::gray[10]);
   CycSprite s(c,{"src.png","dest.png"},50, 50);
   while(c.globStatus!=0){
      s.nextImage();
      usleep(500000);
      // s.moveBy(-10,10);
   }
   srand(0);
   
}

