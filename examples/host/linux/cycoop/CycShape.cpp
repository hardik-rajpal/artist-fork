#include"CycShape.h"

CycShape::CycShape(float cx, float cy):CycObject(cx,cy){}

CycShape::CycShape(float cx, float cy, cycfi::artist::color fillColor,cycfi::artist::color strokeColor):CycObject(cx,cy){
    this->fillColor=fillColor;
    this->strokeColor=strokeColor;
}
void CycShape::fill(art::color fillColor){
    this->fillColor=fillColor;
}
void CycShape::stroke(art::color strokeColor){
    this->strokeColor=strokeColor;
}
void CycShape::setStrokeWidth(float strokeWidth){
    this->strokeWidth=strokeWidth;
}
CycCircle::CycCircle(float cx, float cy, float radius,art::color fillColor,art::color strokeColor):CycShape(cx,cy, fillColor,strokeColor){
    this->radius = radius;
}
CycCircle::CycCircle(float cx, float cy, float radius):CycShape(cx,cy){
    this->radius = radius;
}
void CycCircle::render(art::canvas &cnv){
    cnv.line_width(this->strokeWidth);
    cnv.stroke_color(strokeColor);
    cnv.arc(this->cx, this->cy,radius,0.0f,360.0f,false);
    cnv.fill_style(fillColor);
    cnv.fill();
    cnv.arc(this->cx, this->cy,radius,0.0f,360.0f,false);
    cnv.stroke();
}
CycRect::CycRect(float cx, float cy, float width, float height):CycShape(cx, cy){
    this->width = width;this->height = height;
}
void CycRect::render(art::canvas &cnv){
    float tx = cx - width/2;
    float ty = cy - height/2;
    cnv.line_width(this->strokeWidth);
    cnv.stroke_color(strokeColor);
    cnv.stroke_rect(tx,ty,width,height);
    cnv.fill_style(fillColor);
    cnv.fill_rect(tx,ty, width,height);
    cnv.fill();
    cnv.stroke();
}
CycPoly::CycPoly(float cx, float cy, float radius, int numsides):CycShape(cx, cy){
    this->radius = radius;
    this->numsides = numsides;
}
void CycPoly::render(art::canvas &cnv){
    
}