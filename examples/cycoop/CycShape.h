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
    fill(art::color fillColor);
    stroke(art::color strokeColor);
};

class CycCircle:public CycShape{
    public:
    float radius;
    void render(art::canvas &cnv);
    CycCircle(float cx, float cy, float radius,art::color fillColor,art::color strokeColor);
    CycCircle(float cx, float cy, float radius);
};
class CycRect:public CycShape{
    public:
    float width;
    float height;
    void render(art::canvas &cnv);
    CycRect(float cx, float cy, float width, float height);
    CycRect(float cx, float cy, float width, float height,art::color fillColor,art::color strokeColor);
};
#endif
