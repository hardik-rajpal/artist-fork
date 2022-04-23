#ifndef OBJECT_H
#define OBJECT_H
class Object{
    public:
    bool isVis = true;
    float cx,cy;

    Object(float cx, float cy);
    virtual void render()=0;
    void move(float x, float y);
    void moveBy(float dx, float dy);
    void setVis(bool isVis);
};
#endif