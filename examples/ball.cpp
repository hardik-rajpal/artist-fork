/*=============================================================================
   Copyright (c) 2016-2020 Joel de Guzman

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#include "app.hpp"
#include <cstdlib>
#include<vector>
using namespace cycfi::artist;

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
int velx = 5;
int vely = 5;
constexpr auto accelleration = 0.05;
auto repaint_color = rgb(0,0,0);
constexpr auto portion = 360.0f/total;
auto balls = image{ "src.png" };
float dots[total];
float dots_vel[total];
float opacity = 1.0;

float random_size()
{
   return float(std::rand()) / (RAND_MAX);
}

void rain(canvas& cnv)
{
   //do: repaint the canvas as repaint_color
   // std::vector<cycfi::artist::color> colorList;
   // colorList.push_back(colors::indian_red);colorList.push_back(colors::alice_blue);colorList.push_back(colors::aquamarine);
   // colorList.push_back(colors::azure);colorList.push_back(colors::bisque);colorList.push_back(colors::blanched_almond);
   // colorList.push_back(colors::blue_violet);colorList.push_back(colors::sky_blue);colorList.push_back(colors::sea_green);
   // colorList.push_back(colors::lavender);
   // repaint_color=colorList[rand()%colorList.size()].opacity(1);


   cnv.fill_style(repaint_color);
   cnv.fill_rect({ 0, 0, window_size });

   cnv.draw(balls,posx,posy);
   
   // cnv.arc(point(posx,posy),radius,0.0f,360.0f);
   // cnv.fill_style(colors::blue_violet);
   // cnv.fill();
   // cnv.stroke();
   posx+=velx;
   posy+=vely;
   if(posx>window_size.x){velx=-velx;posx=window_size.x-1;}
   else if(posx<0){posx=1;velx=-velx;}
   if(posy>window_size.y){vely=-vely;posy=window_size.y-1;}
   else if(posy<0){posy=1;vely=-vely;}
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
}

int main(int argc, char const* argv[])
{
   init();
   return run_app(argc, argv, window_size, colors::gray[10], true);
}

