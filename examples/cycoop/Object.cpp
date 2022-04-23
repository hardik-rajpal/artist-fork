#include"Object.h"
using namespace std;
Object::Object(float cx, float cy){
    this->cx=cx;
    this->cy=cy;
}
void Object::setVis(bool isVis){
    this->isVis=isVis;
}
void Object::move(float x, float y){
    this->cx = x;
    this->cy = y;
}
void Object::moveBy(float dx, float dy){
    this->cx+=dx;
    this->cy+=dy;
}