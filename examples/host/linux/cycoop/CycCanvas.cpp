#include"CycCanvas.h"
#include"../../../app.hpp"
#include<thread>
#include<iostream>
CycCanvas::CycCanvas(int argc, char const* argv[], cycfi::artist::extent window_size, cycfi::artist::color background_color){
   t1 =  new std::thread(runner,this,argc,argv,window_size,colors::gray[10],true);
}
void CycCanvas::click(float x, float y, int type){
   if(onClick!=NULL){
      onClick(x,y,type);
   }
   for(auto obj:objects){
      if(obj->inRange(x,y)&&obj->onClick!=NULL){
         obj->onClick(x,y,type);
      }
   }
}
void CycCanvas::keyPress(int keyval){
   if(onKeyPress!=NULL){
      onKeyPress(keyval);
   }
   std::cout<<"Key pressed"<<std::endl;
   for(auto obj:objects){
      if(obj->onKeyPress!=NULL){
         obj->onKeyPress(keyval);
      }
   }
};

CycCanvas::~CycCanvas(){
    t1->join();
}
void runner(CycCanvas*cyccnv,int argc, char const* argv[], extent window_size, color background_color, bool animate){
   cyccnv->globStatus = run_app(argc,argv,window_size,cyccnv,background_color,animate);
}
