#include"CycObject.h"
using namespace std;
CycObject::CycObject(CycCanvas &cyccnv,float cx, float cy){
    this->cx=cx;
    this->cy=cy;
    cyccnv.objects.push_back(this);
}
void CycObject::setVis(bool isVis){
    this->isVis=isVis;
}
void CycObject::move(float x, float y){
    this->cx = x;
    this->cy = y;
}
void CycObject::moveBy(float dx, float dy){
    this->cx+=dx;
    this->cy+=dy;
}
void CycObject::update(cycfi::artist::canvas &cnv){
    if(isVis){
        render(cnv);
    }
}