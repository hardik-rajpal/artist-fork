#ifndef CYCTEXT_H
#define CYCTEXT_H
#include"CycShape.h"
#include<string>
class CycText:public CycShape{
    public:
    std::string value;
    float fontsz;
    void render(cycfi::artist::canvas &cnv);
    bool inRange(float x, float y);
    CycText();
    CycText(
        CycCanvas &cyccnv
        ,float cx
        ,float cy
        ,std::string value
        ,float fontsz
        ,cycfi::artist::color fillColor=cycfi::artist::colors::black
        ,cycfi::artist::color strokeColor=cycfi::artist::colors::gray[10]);
};
#endif