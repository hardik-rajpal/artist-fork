#ifndef CYCSHAPE_H
#define CYCSHAPE_H
#include"CycObject.h"
#include<artist/color.hpp>
namespace art = cycfi::artist;
class CycShape:public CycObject{
    public:
    art::color fillColor = art::colors::white;
    art::color strokeColor = art::colors::black;
    CycShape(float cx, float cy);
    CycShape(float cx, float cy, art::color fillColor,art::color strokeColor);
};

class CycCircle:public CycShape{
    public:
    float radius;
    void render(art::canvas &cnv);
    CycCircle(float cx, float cy, float radius,art::color fillColor,art::color strokeColor);
    CycCircle(float cx, float cy, float radius);
};
#endif