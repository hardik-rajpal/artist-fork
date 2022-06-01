#ifndef CYCSHAPE_H
#define CYCSHAPE_H
#include "CycObject.h"
#include <artist/color.hpp>

namespace art = cycfi::artist;
class CycShape : public CycObject
{
public:
    art::color fillColor = art::colors::white;
    art::color strokeColor = art::colors::black;
    float strokeWidth = 10;
    CycShape();
    CycShape(CycCanvas &cyccnv, float cx, float cy);
    CycShape(CycCanvas &cyccnv, float cx, float cy, art::color fillColor, art::color strokeColor);
    void fill(art::color fillColor);
    void stroke(art::color strokeColor);
    void setStrokeWidth(float strokeWidth);
};
class CycCircle : public CycShape
{
public:
    float radius;
    void render(art::canvas &cnv);
    bool inRange(float x, float y);
    CycCircle();
    CycCircle(CycCanvas &cyccnv, float cx, float cy, float radius, art::color fillColor, art::color strokeColor);
    CycCircle(CycCanvas &cyccnv, float cx, float cy, float radius);
};
class CycRect : public CycShape
{
public:
    float width;
    float height;
    void render(art::canvas &cnv);
    bool inRange(float x, float y);
    CycRect();
    CycRect(CycCanvas &cyccnv, float cx, float cy, float width, float height);
    CycRect(CycCanvas &cyccnv, float cx, float cy, float width, float height, art::color fillColor, art::color strokeColor);
};
class CycPoly : public CycShape
{
public:
    int numsides;
    float radius;
    bool inRange(float x, float y);
    void render(art::canvas &cnv);
    void setPolyParams(float radius, int numsides);
    CycPoly();
    CycPoly(CycCanvas &cyccnv, float cx, float cy, float radius, int numsides);
};
class CycTurtle : public CycShape
{
public:
    float edgeLength = 50;
    float theta = 0;
    float scale = 1;
    CycTurtle();
    CycTurtle(CycCanvas &cyccnv, float cx, float cy);
    void render(art::canvas &cnv);
    bool inRange(float x, float y);
    void forward(float dx);
    void rotateBy(float dTheta);
    void rotateTo(float theta);
    void stamp();
    void scaleBy(float dScale);
    void scaleTo(float newScale);
};
#endif
