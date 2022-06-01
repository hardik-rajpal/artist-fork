#include "CycShape.h"
#include <math.h>
#include <utility>
#include <iostream>
float degToRad(float deg)
{
    return (deg / 180.0) * M_PI;
}
std::pair<float, float> thetaToSinCos(float thetaDeg)
{
    return std::pair<float, float>(cos(degToRad(thetaDeg)), sin(degToRad(thetaDeg)));
}
CycShape::CycShape() : CycObject() {}
CycShape::CycShape(CycCanvas &cyccnv, float cx, float cy) : CycObject(cyccnv, cx, cy) {}

CycShape::CycShape(CycCanvas &cyccnv, float cx, float cy, cycfi::artist::color fillColor, cycfi::artist::color strokeColor) : CycObject(cyccnv, cx, cy)
{
    this->fillColor = fillColor;
    this->strokeColor = strokeColor;
}
void CycShape::fill(art::color fillColor)
{
    this->fillColor = fillColor;
}
void CycShape::stroke(art::color strokeColor)
{
    this->strokeColor = strokeColor;
}
void CycShape::setStrokeWidth(float strokeWidth)
{
    this->strokeWidth = strokeWidth;
}
CycCircle::CycCircle() : CycShape() {}
CycCircle::CycCircle(CycCanvas &cyccnv, float cx, float cy, float radius, art::color fillColor, art::color strokeColor) : CycShape(cyccnv, cx, cy, fillColor, strokeColor)
{
    this->radius = radius;
}
CycCircle::CycCircle(CycCanvas &cyccnv, float cx, float cy, float radius) : CycShape(cyccnv, cx, cy)
{
    this->radius = radius;
}
void CycCircle::render(art::canvas &cnv)
{
    cnv.line_width(this->strokeWidth);
    cnv.stroke_color(strokeColor);
    cnv.arc(this->cx, this->cy, radius, 0.0f, 360.0f, false);
    cnv.fill_style(fillColor);
    cnv.fill();
    cnv.arc(this->cx, this->cy, radius, 0.0f, 360.0f, false);
    cnv.stroke();
}
bool CycCircle::inRange(float x, float y)
{
    return sqrt((x - cx) * (x - cx) + (y - cy) * (y - cy)) < (radius + strokeWidth);
}
CycRect::CycRect() : CycShape() {}
CycRect::CycRect(CycCanvas &cyccnv, float cx, float cy, float width, float height) : CycShape(cyccnv, cx, cy)
{
    this->width = width;
    this->height = height;
}
void CycRect::render(art::canvas &cnv)
{
    float tx = cx - width / 2;
    float ty = cy - height / 2;
    cnv.line_width(this->strokeWidth);
    cnv.stroke_color(strokeColor);
    cnv.stroke_rect(tx, ty, width, height);
    cnv.fill_style(fillColor);
    cnv.fill_rect(tx, ty, width, height);
    cnv.fill();
    cnv.stroke();
}
bool CycRect::inRange(float x, float y)
{
    return (abs(cx - x) < (width + strokeWidth) / 2) && (abs(y - cy) < (height + strokeWidth) / 2);
}
CycPoly::CycPoly(CycCanvas &cyccnv, float cx, float cy, float radius, int numsides) : CycShape(cyccnv, cx, cy)
{
    this->radius = radius;
    this->numsides = numsides;
}
void CycPoly::render(art::canvas &cnv)
{
    float inrad = radius;
    cnv.line_width(strokeWidth);
    cnv.stroke_color(strokeColor);
    cnv.begin_path();
    std::pair<float, float> cs = thetaToSinCos(0);
    cnv.move_to(cx + (inrad * cs.first), cy + (inrad * cs.second));
    for (int i = 1; i < numsides; i++)
    {
        cs = thetaToSinCos(120 * i);
        cnv.line_to(cx + (inrad * cs.first), cy + (inrad * cs.second));
    }

    cnv.fill_style(fillColor);
    cnv.close_path();
    cnv.fill();

    cnv.begin_path();
    cs = thetaToSinCos(0);
    cnv.move_to(cx + (inrad * cs.first), cy + (inrad * cs.second));
    for (int i = 1; i < numsides; i++)
    {
        cs = thetaToSinCos(120 * i);
        cnv.line_to(cx + (inrad * cs.first), cy + (inrad * cs.second));
    }
    cnv.fill_style(fillColor);
    cnv.close_path();
    cnv.stroke();
}
bool CycPoly::inRange(float x, float y)
{
    return true;
}
CycTurtle::CycTurtle() : CycShape()
{
    fillColor = art::colors::red;
}
CycTurtle::CycTurtle(CycCanvas &cyccnv, float cx, float cy) : CycShape(cyccnv, cx, cy, cycfi::artist::colors::red, cycfi::artist::colors::black)
{
    strokeWidth = 3;
}
void CycTurtle::render(art::canvas &cnv)
{
    float inrad = scale * edgeLength / sqrt(3);
    cnv.line_width(strokeWidth);
    cnv.stroke_color(strokeColor);
    cnv.begin_path();
    std::pair<float, float> cs = thetaToSinCos(theta);
    cnv.move_to(cx + (inrad * cs.first), cy + (inrad * cs.second));
    cs = thetaToSinCos(120 + theta);
    cnv.line_to(cx + (inrad * cs.first), cy + (inrad * cs.second));
    cs = thetaToSinCos(240 + theta);
    cnv.line_to(cx + (inrad * cs.first), cy + (inrad * cs.second));
    cnv.fill_style(fillColor);
    cnv.close_path();
    cnv.fill();

    cnv.begin_path();
    cs = thetaToSinCos(theta);
    cnv.move_to(cx + (inrad * cs.first), cy + (inrad * cs.second));
    cs = thetaToSinCos(120 + theta);
    cnv.line_to(cx + (inrad * cs.first), cy + (inrad * cs.second));
    cs = thetaToSinCos(240 + theta);
    cnv.line_to(cx + (inrad * cs.first), cy + (inrad * cs.second));
    cnv.fill_style(fillColor);
    cnv.close_path();
    cnv.stroke();
}
bool CycTurtle::inRange(float x, float y)
{
    return true;
}
void CycTurtle::forward(float dx)
{
    std::pair<float, float> cs = thetaToSinCos(theta);
    moveBy(cs.first * dx, cs.second * dx);
}
void CycTurtle::rotateBy(float dTheta)
{
    theta += dTheta;
}
void CycTurtle::rotateTo(float theta)
{
    this->theta = theta;
}
void CycTurtle::stamp()
{
    CycTurtle *stamp = new CycTurtle(*cyccnv, cx, cy);
    stamp->rotateTo(theta);
    stamp->scaleTo(scale);
}
void CycTurtle::scaleBy(float dScale)
{
    scale *= dScale;
}
void CycTurtle::scaleTo(float newScale)
{
    scale = newScale;
}
