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
    float el = window_size.x / 8;
    CycRect rects[64];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            rects[8 * i + j].width = el;
            rects[8 * i + j].height = el;
            rects[8 * i + j].setCanvas(c);
            rects[8 * i + j].setStrokeWidth(0);
            rects[8 * i + j].moveTo(el * i + el / 2, el * j + el / 2);
            rects[8 * i + j].fill(((i + j) % 2 == 0) ? colors::red : colors::white);
        }
    }
    sleep(1000);
}