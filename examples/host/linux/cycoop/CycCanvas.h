
#ifndef CYCCANVAS_H
#define CYCCANVAS_H
#include<artist/point.hpp>
#include<artist/color.hpp>
#include<thread>
#include"CycObject.h"
#include<vector>
class CycObject;
class CycCanvas{
    public:
    std::vector<CycObject*> objects = {};
    int globStatus = -1;
    std::thread * t1;
    CycCanvas(int argc, char const* argv[], cycfi::artist::extent window_size, cycfi::artist::color background_color);
    void onClick(float x, float y, int type);
    void onKeyPress(int keyval);
    ~CycCanvas();
};
void runner(CycCanvas *cyccnv,int argc, char const* argv[], cycfi::artist::extent window_size, cycfi::artist::color background_color = cycfi::artist::colors::white, bool animate = false);

#endif