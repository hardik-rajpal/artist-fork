#include<iostream>
#include"CycSprite.h"
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
    if(this->images.size()>1){
        this->currentImage = (this->currentImage+1)%(this->images.size());
    }
    cnv.draw(this->images[this->currentImage],this->cx,this->cy);
    
}
void CycSprite::nextImage(){
    this->currentImage+=1;
}

bool CycSprite::inRange(float x, float y){
    return false;
}

