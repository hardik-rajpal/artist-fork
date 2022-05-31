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
int rando(int m, int M){
    int h;
    while(true){
        h = rand();
        if (m<h and h<M){
            return h;
        }
    }
}
void branch(int lob, CycTurtle mm){
    if (lob/80 >0) {
        mm.rotateBy(rando(0,120)-60);
        for(int j=0;j<lob/40;j++){
            mm.rotateBy(rando(0, 30)-15);
            mm.forward(20);
            float x1 = mm.cx, y1 = mm.cy;
            int subb = rando(0, 30);
            mm.rotateBy(subb); branch(lob/8, mm);mm.rotateBy(-subb);
            mm.moveTo(x1, y1);
            mm.forward(20);
            x1 = mm.cx, y1 = mm.cy;
            subb = rando(0, 30);
            mm.rotateBy(-subb); branch(lob/8, mm);mm.rotateBy(subb);
            mm.moveTo(x1, y1);
            if (mm.scale<0.6){
                mm.scaleTo(1.5);
            }

        }
    }
    else{
         mm.rotateBy(rando(0, 120)-60);
        for(int j=0;j<lob/20;j++){
            mm.rotateBy(rando(0, 30)-15);
            mm.forward(20);
            int subb = rando(0, 30);
            mm.rotateBy(subb); mm.forward(10); mm.stamp(); mm.forward(-5);mm.rotateBy(-subb);
            mm.forward(20);
            subb = rando(0, 30);
            mm.rotateBy(-subb); mm.forward(5); mm.stamp(); mm.forward(-5);mm.rotateBy(subb);
        }
    }
}
int main(int argc, char const* argv[])
{
   srand(0);
   CycCanvas c(argc, argv, window_size,colors::pink);   
   CycTurtle t(c,100,50);
//    float rad = 100;
//    float theta = 30;
//    // CycRect r(c,100,100,100,100);
//    t.scaleTo(0.1);
//    t.rotateBy(80);
//    t.moveTo(750, 700);
//    t.togglePen();
//    int x0 = t.cx, y0 = t.cy;
//    t.rotateBy(90);
//    t.forward(100);
//    branch(400, t);
//    t.moveTo(x0, y0);
//    t.rotateBy(-30);
   while(c.globStatus!=0){
       t.rotateBy(10);
      usleep(100000);
   }
   
}

