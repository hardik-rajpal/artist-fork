#ifndef CYCSPRITE_H
#define CYCSPRITE_H
#include"CycObject.h"
#include"CycCanvas.h"
#include <infra/support.hpp>
#include <artist/canvas.hpp>
#include<string>
#include<vector>
#include<thread>

class CycSprite: public CycObject{
    public:
    int updInterval;
    int currentImage = 0;
    int nextImage = 1;
    bool changeImage = true;
    // float width, height;
    std::thread *looper;
    std::vector<cycfi::artist::image> images;
    CycSprite();
    CycSprite(CycCanvas &cyccnv,std::vector<std::string> fnames, float cx, float cy);
    void render(cycfi::artist::canvas &cnv);
    bool inRange(float x, float y);
    void toNextImage();
    void resetImages(std::vector<std::string> fnames);
    void startImageLoop(int startFrom, int lbAt, int udt);
    void stopImageLoop(int stopAt);

};
#endif