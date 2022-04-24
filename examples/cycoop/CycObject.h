#ifndef CYCOBJECT_H
#define CYCOBJECT_H
#define CYCOOP
#include<artist/canvas.hpp>
class CycObject{
    public:
    bool isVis = true;
    float cx,cy;
    CycObject(float cx, float cy);
    virtual void render(cycfi::artist::canvas &cnv)=0;
    void update(cycfi::artist::canvas &cnv);
    void move(float x, float y);
    void moveBy(float dx, float dy);
    void setVis(bool isVis);
};
#endif