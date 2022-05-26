#ifndef CYC_PATH_H
#define CYC_PATH_H
#include<artist/canvas.hpp>
#include"CycObject.h"
#include<vector>
class CycPath:public CycObject{
    public:
    cycfi::artist::color strokeColor = cycfi::artist::colors::black;
    float strokeWidth=10;
    std::vector<cycfi::artist::point> pts;
    CycPath(CycCanvas &cyccnv,float cx, float cy);
    CycPath(CycCanvas &cyccnv,float cx, float cy,float strokeWidth,cycfi::artist::color strokeColor);
    void render(cycfi::artist::canvas &cnv);
    bool inRange(float x,float y);
    void addPoint(float x, float y);
    void addPointRelative(float dx, float dy);
    cycfi::artist::point getHead();
};
#endif