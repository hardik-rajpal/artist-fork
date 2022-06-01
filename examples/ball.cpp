#include "app.hpp"
#include <cstdlib>
#include <vector>
#include <unistd.h>
#include <iostream>
#include <thread>
using namespace cycfi::artist;
#include "host/linux/cycoop/CycLib.h"

#if defined(ARTIST_SKIA) && !defined(linux)
constexpr auto persistence = 0.10;
#else
constexpr auto persistence = 0.04;
#endif
constexpr auto window_size = extent{600, 600};
int rando(int m, int M)
{
    int h;
    while (true)
    {
        h = rand();
        if (m < h and h < M)
        {
            return h;
        }
    }
}
void branch(int lob, CycTurtle mm)
{
    if (lob / 80 > 0)
    {
        mm.rotateBy(rando(0, 120) - 60);
        for (int j = 0; j < lob / 40; j++)
        {
            mm.rotateBy(rando(0, 30) - 15);
            mm.forward(20);
            float x1 = mm.cx, y1 = mm.cy;
            int subb = rando(0, 30);
            mm.rotateBy(subb);
            branch(lob / 8, mm);
            mm.rotateBy(-subb);
            mm.moveTo(x1, y1);
            mm.forward(20);
            x1 = mm.cx, y1 = mm.cy;
            subb = rando(0, 30);
            mm.rotateBy(-subb);
            branch(lob / 8, mm);
            mm.rotateBy(subb);
            mm.moveTo(x1, y1);
            if (mm.scale < 0.6)
            {
                mm.scaleTo(1.5);
            }
        }
    }
    else
    {
        mm.rotateBy(rando(0, 120) - 60);
        for (int j = 0; j < lob / 20; j++)
        {
            mm.rotateBy(rando(0, 30) - 15);
            mm.forward(20);
            int subb = rando(0, 30);
            mm.rotateBy(subb);
            mm.forward(10);
            mm.stamp();
            mm.forward(-5);
            mm.rotateBy(-subb);
            mm.forward(20);
            subb = rando(0, 30);
            mm.rotateBy(-subb);
            mm.forward(5);
            mm.stamp();
            mm.forward(-5);
            mm.rotateBy(subb);
        }
    }
}
int main(int argc, char const *argv[])
{
    srand(0);
    CycCanvas c(argc, argv, window_size, colors::pink);
    CycTurtle t[3];
    extent wc = {window_size.x / 2, window_size.y / 2};
    float inRad = 100;
    for (int i = 0; i < 3; i++)
    {
        t[i].setCanvas(c);
        t[i].setStrokeWidth(2);
        t[i].scaleBy(0.5);
        t[i].moveTo(wc.x, wc.y);
        t[i].togglePen();
        t[i].rotateBy(120 * i);
        t[i].forward(inRad);
    }
    sleep(10);
    for (int j = 0; j < 6; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            t[i].rotateBy(-51.43);
            t[i].forward(inRad);
            usleep(1000);
        }
    }
    sleep(10);
}
