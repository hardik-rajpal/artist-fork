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
   CycCircle *ball[5];
   CycRect *myrect;

   CycCanvas c(argc, argv, window_size,colors::gray[10]);   
   // CycCanvas c2(argc, argv, window_size,colors::gray[10]);   
   
   srand(0);
   for(int i=0;i<5;i++){
      velx[i]=5;vely[i]=5;
      ball[i] = new CycCircle(c,posx+(rand()%10)*10*i,posy-(rand()%10)*10*i,radius,cycfi::artist::colors::blue_violet,cycfi::artist::colors::sea_green);
      ball[i]->onClick = [ball,i](float x, float y, int type){
         ball[i]->strokeColor = colors::blue;
         velx[i]=0;vely[i]=0;
         ball[i]->move(x,y);
      };
      ball[i]->onKeyPress = [ball,i](int keyval){
         if(keyval==112&&rand()%2==i%2){
            velx[i]?ball[i]->stroke(colors::blue):ball[i]->stroke(colors::yellow);
            velx[i] = velx[i]?0:5;vely[i] =vely[i]?0:5;
         }
         // std::cout<<keyval<<std::endl;
      };
   }
   myrect = new CycRect(c,5,5,50, 50);
   myrect->fill(colors::pink);
   myrect->stroke(colors::red);
   myrect->onClick = [myrect](float x,float y,int type){
      if(type==1){
         myrect->stroke(colors::white);
      }
      else{
         myrect->stroke(colors::red);
      }
   };

   while(c.globStatus!=0){
      usleep(50000);
      // myrect->moveBy(1,1);
      for(int i=0;i<5;i++){
         ball[i]->moveBy(velx[i],vely[i]);
         if(ball[i]->cx>window_size.x){
            velx[i]=-velx[i];ball[i]->cx=window_size.x-1;
            ball[i]->fill(colors::green);
            ball[i]->stroke(colors::yellow);
         }
         else if(ball[i]->cx<0){
            ball[i]->cx=1;velx[i]=-velx[i];
            ball[i]->fill(colors::red);
            ball[i]->stroke(colors::yellow);
         }
         if(ball[i]->cy>window_size.y){
            vely[i]=-vely[i];ball[i]->cy=window_size.y-1;
            ball[i]->fill(colors::green);
            ball[i]->stroke(colors::yellow);
         }
         else if(ball[i]->cy<0){
            ball[i]->cy=1;vely[i]=-vely[i];
            ball[i]->fill(colors::red);
            ball[i]->stroke(colors::yellow);
         }
      }

   }
}

