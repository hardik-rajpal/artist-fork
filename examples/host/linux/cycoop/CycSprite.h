#ifndef CYCSPRITE_H
#define CYCSPRITE_H
#include"CycObject.h"
#include"CycCanvas.h"
#include <infra/support.hpp>
#include <artist/canvas.hpp>
#include<string>
#include<vector>

class CycSprite: public CycObject{
    public:
    std::vector<std::string> fnames;
    int updInterval;
    int currentImage = 0;
    // float width, height;
    std::vector<cycfi::artist::image> images;
    CycSprite();
    CycSprite(CycCanvas &cyccnv,std::vector<std::string> fnames, float cx, float cy);
    void render(cycfi::artist::canvas &cnv);
    bool inRange(float x, float y);
    void nextImage();

};
#endif