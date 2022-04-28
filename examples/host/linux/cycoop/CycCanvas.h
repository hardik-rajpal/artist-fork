
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
    std::function<void(float x, float y, int type)> onClick=NULL;
    std::function<void(int type)> onKeyPress=NULL;
    CycCanvas(int argc, char const* argv[], cycfi::artist::extent window_size, cycfi::artist::color background_color);
    void click(float x, float y, int type);
    void keyPress(int keyval);
    ~CycCanvas();
};
void runner(CycCanvas *cyccnv,int argc, char const* argv[], cycfi::artist::extent window_size, cycfi::artist::color background_color = cycfi::artist::colors::white, bool animate = false);

#endif