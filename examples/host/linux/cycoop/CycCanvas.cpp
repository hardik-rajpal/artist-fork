#include"CycCanvas.h"
#include"../../../app.hpp"
#include<thread>
CycCanvas::CycCanvas(int argc, char const* argv[], cycfi::artist::extent window_size, cycfi::artist::color background_color){
   t1 =  new std::thread(runner,this,argc,argv,window_size,colors::gray[10],true);
}
CycCanvas::~CycCanvas(){
    t1->join();
}
void runner(CycCanvas*cyccnv,int argc, char const* argv[], extent window_size, color background_color, bool animate){
   cyccnv->globStatus = run_app(argc,argv,window_size,&(cyccnv->objects),background_color,animate);
}
