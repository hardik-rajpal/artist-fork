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
   CycCanvas c(argc, argv, window_size,colors::gray[10]);   
   CycText t(c,50,50,"nbc",50,cycfi::artist::colors::blue,cycfi::artist::colors::yellow);
   c.onKeyPress = [&t](int keyval){
      switch(keyval){
         case 65361:
            t.moveBy(0,-10);
            break;
         case 65362:
            t.moveBy(10,0);
            break;
         case 65363:
            t.moveBy(10,0);
            break;
         case 65364:
            t.moveBy(0,10);
            break;
      }
   };
   while(c.globStatus!=0){
      usleep(1000000);
   }
   srand(0);
   
}

