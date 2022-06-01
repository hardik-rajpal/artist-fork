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
    return (rand() % (M - m)) + m;
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
std::vector<color> colorops =
    {
        colors::red,
        colors::alice_blue,
        colors::green,
        colors::azure,
        colors::purple,
        colors::dark_olive_green};
int main(int argc, char const *argv[])
{
    srand(0);
    CycCanvas c(argc, argv, window_size, colors::pink);
    CycPoly p[2];
    int nps = 2;
    sleep(5);
    for (int i = 0; i < nps; i++)
    {
        p[i].moveTo(window_size.x / 2 + rand() % 200 - 100, (window_size.y / 2) + rand() % 200 - 100);
        p[i].setStrokeWidth(2);
        p[i].fillColor = colorops[rand() % 6];
        p[i].setPolyParams(rando(20, 80), rando(3, 12));
        p[i].setCanvas(c);
    }
    // for (int i = 0; i < nps; i++)
    // {
    //     p[i].togglePen();
    //     p[i].setZIndex(1);
    // }
    for (int j = 0; j < 500; j++)
    {
        for (int i = 0; i < nps; i++)
        {
            p[i].moveBy(rando(-20, 20), rando(-20, 20));
        }
        usleep(100000);
    }
    sleep(10);
}
