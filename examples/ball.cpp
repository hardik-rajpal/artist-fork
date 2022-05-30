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
constexpr auto window_size = extent{ 900, 600 };
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
   CycTurtle t(c,100,50);
   t.togglePen();
   float rad = 100;
   float theta = 30;
   // CycRect r(c,100,100,100,100);
   while(c.globStatus!=0){
      if(rad>0){
         t.forward(rad);
         t.rotateBy(theta);
         rad-=2;
         if(int(rad)%4==0){
            t.stamp();
            t.scaleBy(0.95);
         }
      }
      usleep(100000);
   }
   srand(0);
   
}

