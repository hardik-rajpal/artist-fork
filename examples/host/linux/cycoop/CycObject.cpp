#include"CycObject.h"
using namespace std;
CycObject::CycObject(CycCanvas &cyccnv,float cx, float cy){
    this->cx=cx;
    this->cy=cy;
    cyccnv.objects.push_back(this);
    this->cyccnv = &cyccnv;
}
CycObject::CycObject(){};
void CycObject::setVis(bool isVis){
    this->isVis=isVis;
}
void CycObject::move(float x, float y){
    this->cx = x;
    this->cy = y;
    if(isPenDown){
        this->paths[this->paths.size()-1].addPoint(x,y);
    }
}
void CycObject::moveBy(float dx, float dy){
    this->cx+=dx;
    this->cy+=dy;
    if(isPenDown){
        this->paths[this->paths.size()-1].addPointRelative(dx,dy);
    }
}
void CycObject::update(cycfi::artist::canvas &cnv){
    if(isVis){
        render(cnv);
    }
}
void CycObject::togglePen(){
    isPenDown = !isPenDown;
    if(isPenDown){
        paths.push_back(CycPath(*cyccnv,cx,cy));
    }
}
