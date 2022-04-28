#ifndef CYCSHAPE_H
#define CYCSHAPE_H
#include"CycObject.h"
#include<artist/color.hpp>

namespace art = cycfi::artist;
class CycShape:public CycObject{
    public:
    art::color fillColor = art::colors::white;
    art::color strokeColor = art::colors::black;
    float strokeWidth=10;
    CycShape(CycCanvas &cyccnv,float cx, float cy);
    CycShape(CycCanvas &cyccnv,float cx, float cy, art::color fillColor,art::color strokeColor);
    void fill(art::color fillColor);
    void stroke(art::color strokeColor);
    void setStrokeWidth(float strokeWidth);
};
class CycCircle:public CycShape{
    public:
    float radius;
    void render(art::canvas &cnv);
    bool inRange(float x, float y);
    CycCircle(CycCanvas &cyccnv,float cx, float cy, float radius,art::color fillColor,art::color strokeColor);
    CycCircle(CycCanvas &cyccnv,float cx, float cy, float radius);
};
class CycRect:public CycShape{
    public:
    float width;
    float height;
    void render(art::canvas &cnv);
    bool inRange(float x, float y);
    CycRect(CycCanvas &cyccnv,float cx, float cy, float width, float height);
    CycRect(CycCanvas &cyccnv,float cx, float cy, float width, float height,art::color fillColor,art::color strokeColor);
};
class CycPoly:public CycShape{
    public:
    int numsides;
    float radius;
    void render(art::canvas &cnv);
    CycPoly(CycCanvas &cyccnv,float cx, float cy, float radius, int numsides);
};
#endif
