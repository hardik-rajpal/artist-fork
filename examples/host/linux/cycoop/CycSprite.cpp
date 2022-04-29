#include<iostream>
#include"CycSprite.h"
#include<unistd.h>
CycSprite::CycSprite():CycObject(){
    this->updInterval = 1000000;
};
CycSprite::CycSprite(CycCanvas &cyccnv,std::vector<std::string> fnames, float cx, float cy):CycObject(cyccnv, cx, cy){
    cycfi::artist::extent sz = cycfi::artist::image{fnames[0].c_str()}.size();
    for(auto fname:fnames){
        this->images.push_back(cycfi::artist::image{fname.c_str()});
        if(this->images[this->images.size()-1].size()!=sz){
            std::cout<<"All images in a sprite must have same dimensions."<<std::endl;
        }
    }

}
void CycSprite::render(cycfi::artist::canvas &cnv){
    cnv.draw(this->images[this->currentImage],this->cx,this->cy);
}
void CycSprite::toNextImage(){
        int temp=(this->currentImage+1)%(this->images.size());
        this->currentImage = this->nextImage;
        this->nextImage = temp;
}
void CycSprite::resetImages(std::vector<std::string> fnames){
    this->images = std::vector<cycfi::artist::image>();
    std::cout<<__LINE__<<std::endl;
    cycfi::artist::extent sz = cycfi::artist::image{fnames[0].c_str()}.size();
    std::cout<<__LINE__<<std::endl;
    for(auto fname:fnames){
        std::cout<<__LINE__<<std::endl;

        this->images.push_back(cycfi::artist::image{fname.c_str()});
        if(this->images[this->images.size()-1].size()!=sz){
            std::cout<<"All images in a sprite must have same dimensions."<<std::endl;
        }
    }
}
void CycSprite::startImageLoop(int startFrom, int lbAt,int udt){
    currentImage = startFrom;
    changeImage = true;
    looper = new std::thread([udt,startFrom,lbAt,this](){
        while(changeImage){
            int temp;
            if(nextImage==lbAt){temp = startFrom;}
            else{temp = nextImage+1;}
            currentImage = nextImage;
            nextImage = temp;
            usleep(udt);
        }
        return;
    });
}
void CycSprite::stopImageLoop(int stopAt){
    this->changeImage = false;
    looper->join();
    return;
}
bool CycSprite::inRange(float x, float y){
    return false;
}

