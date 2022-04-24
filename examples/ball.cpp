/*=============================================================================
   Copyright (c) 2016-2020 Joel de Guzman

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#include "app.hpp"
#include <cstdlib>
#include<vector>
using namespace cycfi::artist;
#include"cycoop/CycShape.h"
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
constexpr auto w = window_size.x;
constexpr auto h = window_size.y;
constexpr int total = w;
constexpr float radius = 10;
 float posx = 100;
 float posy = 100;
int velx[5];
int vely[5];
constexpr auto accelleration = 0.05;
auto repaint_color = rgb(0,0,0);
constexpr auto portion = 360.0f/total;
auto balls = image{ "src.png" };
float dots[total];
float dots_vel[total];
float opacity = 1.0;
CycCircle *ball[5];
CycRect *myrect;
float random_size()
{
   return float(std::rand()) / (RAND_MAX);
}

void rain(canvas& cnv)
{
   cnv.fill_style(repaint_color);
   cnv.fill_rect({ 0, 0, window_size });
   myrect->update(cnv);
   myrect->moveBy(1,1);
   for(int i=0;i<5;i++){
      ball[i]->update(cnv);
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
   print_elapsed(cnv, window_size, colors::black.opacity(0.1),colors::white.opacity(1));
}

void draw(canvas& cnv)
{  
   //draw must be a repeatedly called function.
   //it calls rain only once and rain moves all drops only once.
   static auto offscreen = image{ window_size };
   {
      auto ctx = offscreen_image{ offscreen };
      auto offscreen_cnv = canvas{ ctx.context() };
      rain(offscreen_cnv);
   }
   cnv.draw(offscreen);
}

void init()
{
   srand(0);
   for (auto i = 0; i < total; ++i)
   {
      dots[i] = h;
      dots_vel[i] = 10;
   }
   for(int i=0;i<5;i++){
      velx[i]=5;vely[i]=5;
   ball[i] = new CycCircle(posx+(rand()%10)*10*i,posy-(rand()%10)*10*i,radius,cycfi::artist::colors::blue_violet,cycfi::artist::colors::sea_green);
   }
   myrect = new CycRect(5,5,50, 50);
   myrect->fill(colors::pink);
   myrect->stroke(colors::red);
}

int main(int argc, char const* argv[])
{
   init();
   return run_app(argc, argv, window_size, colors::gray[10], true);
}

