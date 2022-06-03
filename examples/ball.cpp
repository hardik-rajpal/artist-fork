#include "app.hpp"
#include <cstdlib>
#include <vector>
#include <unistd.h>
#include <iostream>
#include <thread>
using namespace cycfi::artist;
#include "host/linux/cycoop/CycLib.h"

int rando(int m, int M)
{
    return (rand() % (M - m)) + m;
}
std::vector<color> colorops = {
    colors::red,
    colors::alice_blue,
    colors::green,
    colors::azure,
    colors::purple,
    colors::dark_olive_green};
int main(int argc, char const *argv[])
{
    constexpr auto window_size = extent{600, 600};
    srand(0);
    CycCanvas c(argc, argv, window_size, colors::pink);
    CycPoly p[50];
    int nps = 50;
    sleep(5);
    for (int i = 0; i < nps; i++)
    {
        p[i].moveTo(window_size.x / 2 + rand() % 200 - 100, (window_size.y / 2) + rand() % 200 - 100);
        p[i].setStrokeWidth(2);
        p[i].fill(colorops[rand() % 6]);
        p[i].setPolyParams(rando(20, 80), rando(3, 12));
        p[i].setCanvas(c);
    }
    for (int i = 0; i < nps; i++)
    {
        p[i].setPenType(5, colorops[rand() % 6]);
        p[i].togglePen();
    }
    for (int j = 0; j < 500; j++)
    {
        for (int i = 0; i < nps; i++)
        {
            p[i].moveBy(rando(-20, 20), rando(-20, 20));
        }
        usleep(100000);
    }
    for (int i = 0; i < nps; i++)
    {
        p[i].setVis(false);
    }
    sleep(10);
}