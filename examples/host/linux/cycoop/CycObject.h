#ifndef CYCOBJECT_H
#define CYCOBJECT_H
#define CYCOOP
#include<artist/canvas.hpp>
#include<vector>
#include<functional>
#include"CycCanvas.h"
class CycCanvas;
class CycObject;
class CycObject{
    public:
    bool isVis = true;
    float cx,cy;
    std::function<void(float,float,int)> onClick=NULL;
    std::function<void(int)> onKeyPress=NULL;
    CycObject();
    CycObject(CycCanvas &cyccnv,float cx, float cy);
    virtual void render(cycfi::artist::canvas &cnv)=0;
    virtual bool inRange(float x, float y)=0;
    void update(cycfi::artist::canvas &cnv);
    void move(float x, float y);
    void moveBy(float dx, float dy);
    void setVis(bool isVis);
};
#endif