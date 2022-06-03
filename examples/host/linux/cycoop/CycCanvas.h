
#ifndef CYCCANVAS_H
#define CYCCANVAS_H
#include <artist/point.hpp>
#include <artist/color.hpp>
#include <thread>
#include "CycObject.h"
#include <vector>
#include <map>
#include <string>
class CycObject;
class CycCanvas
{
public:
    cycfi::artist::color background_color = cycfi::artist::colors::white;
    std::vector<CycObject *> objects = {};
    const int statusClosed = 0;
    int globStatus = -1;
    std::map<int, std::string> keyMap = {
        {65362, "up"},
        {65364, "down"},
        {65361, "left"},
        {65363, "right"},
        {65505, "shift"},
        {65506, "shift"},
        {65507, "ctrll"},
        {65508, "ctrlr"},
        {65509, "caps"},
        {65513, "altl"},
        {65514, "altr"},
        {32, "space"},
        {65289, "enter"},
        {65293, "tab"},
        {65288, "backspace"},
        {65535, "delete"},
        {65307, "esc"},
        // TODO HR: numbers.

    };
    std::thread *t1;
    std::function<void(float x, float y, int type)> onClick = NULL;
    std::function<void(int type, std::string name)> onKeyPress = NULL;
    CycCanvas(int argc, char const *argv[], cycfi::artist::extent window_size, cycfi::artist::color background_color);
    void click(float x, float y, int type);
    void keyPress(int keyval);
    ~CycCanvas();
};
void runner(CycCanvas *cyccnv, int argc, char const *argv[], cycfi::artist::extent window_size, cycfi::artist::color background_color = cycfi::artist::colors::white, bool animate = false);

#endif