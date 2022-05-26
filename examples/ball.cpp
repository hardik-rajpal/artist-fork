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
#include"host/linux/cycoop/CycLib.h"

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
   CycCanvas c(argc, argv, window_size,colors::pink);   
   CycText t(c,50,50,"nbc",50,cycfi::artist::colors::blue,cycfi::artist::colors::yellow);
   CycCircle m(c,window_size.x/2,window_size.y/2,50,cycfi::artist::colors::alice_blue,cycfi::artist::colors::blanched_almond);

   while(c.globStatus!=0){
      m.moveBy(rand()%20 - 10,rand()%20-10);
      usleep(10000);
   }
   srand(0);
   
}

