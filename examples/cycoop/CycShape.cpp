#include"CycShape.h"

CycShape::CycShape(float cx, float cy):CycObject(cx,cy){}

CycShape::CycShape(float cx, float cy, cycfi::artist::color fillColor,cycfi::artist::color strokeColor):CycObject(cx,cy){
    this->fillColor=fillColor;
    this->strokeColor=strokeColor;
}
CycCircle::CycCircle(float cx, float cy, float radius,art::color fillColor,art::color strokeColor):CycShape(cx,cy, fillColor,strokeColor){
    this->radius = radius;
}
CycCircle::CycCircle(float cx, float cy, float radius):CycShape(cx,cy){
    this->radius = radius;
}
void CycCircle::render(art::canvas &cnv){
   cnv.arc(this->cx, this->cy,radius,0.0f,360.0f);
   cnv.fill_style(fillColor);
   cnv.stroke_style(strokeColor);
   cnv.fill();
   cnv.stroke();
}