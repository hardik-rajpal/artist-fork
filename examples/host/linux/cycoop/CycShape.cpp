#include"CycShape.h"

CycShape::CycShape(std::vector<CycObject*> &objectList,float cx, float cy):CycObject(cx,cy,objectList){}

CycShape::CycShape(std::vector<CycObject*> &objectList,float cx, float cy, cycfi::artist::color fillColor,cycfi::artist::color strokeColor):CycObject(cx,cy,objectList){
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
CycCircle::CycCircle(std::vector<CycObject*> &objectList,float cx, float cy, float radius,art::color fillColor,art::color strokeColor):CycShape(objectList,cx,cy, fillColor,strokeColor){
    this->radius = radius;
}
CycCircle::CycCircle(std::vector<CycObject*> &objectList,float cx, float cy, float radius):CycShape(objectList,cx,cy){
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
CycRect::CycRect(std::vector<CycObject*> &objectList,float cx, float cy, float width, float height):CycShape(objectList,cx, cy){
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
CycPoly::CycPoly(std::vector<CycObject*> &objectList,float cx, float cy, float radius, int numsides):CycShape(objectList,cx, cy){
    this->radius = radius;
    this->numsides = numsides;
}
void CycPoly::render(art::canvas &cnv){
    
}