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
   std::vector<std::string> rnames = {},lnames={};
   int numImages = 8;
   for(int i=0;i<numImages;i++){
      rnames.push_back(std::to_string(i)+"0.png");
      lnames.push_back(std::to_string(i)+"1.png");
   }
   CycCanvas c(argc, argv, window_size,colors::gray[10]);   
   CycSprite s(c,rnames,50, 50);
   s.startImageLoop(0,s.images.size()-1,100000);
   int vx = 10;
   while(c.globStatus!=0){
      while(s.cx<window_size.x){
         usleep(100000);
         // std::cout<<s.cx<<" "<<window_size.x<<std::endl;
         s.moveBy(vx,0);
         if(s.cx+vx>window_size.x){
            s.cx= window_size.x-1;
            vx = -vx;
            s.stopImageLoop(0);
            s.resetImages(lnames);
            s.startImageLoop(0,s.images.size()-1,100000);
         }
         else if(s.cx+vx<0){
            s.cx = 1; 
            vx = -vx;
            s.stopImageLoop(0);
            std::cout<<__LINE__<<std::endl;
            s.resetImages(rnames);
            std::cout<<__LINE__<<std::endl;
            s.startImageLoop(0,s.images.size()-1,100000);
            std::cout<<__LINE__<<std::endl;

         }
      }

   }
   srand(0);
   
}

