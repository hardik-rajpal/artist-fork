#include"CycPath.h"
#include<iostream>
CycPath::CycPath(){};
CycPath::CycPath(CycCanvas &cyccnv,float cx, float cy):CycObject(cyccnv,cx,cy){
    pts.push_back({cx,cy});
};
CycPath::CycPath(CycCanvas &cyccnv,float cx, float cy,float strokeWidth,cycfi::artist::color strokeColor):CycObject(cyccnv,cx,cy){
    pts.push_back({cx,cy});
    std::cout<<__LINE__;
    this->strokeColor = strokeColor;
    std::cout<<__LINE__;
    this->strokeWidth = strokeWidth;
    std::cout<<__LINE__;

}

void CycPath::render(cycfi::artist::canvas &cnv){
    using namespace cycfi::artist;
    cnv.line_width(strokeWidth);
    cnv.line_cap(cnv.butt);
    cnv.stroke_style(strokeColor);
    cnv.begin_path();
    cnv.line_join(cnv.bevel_join);
    cnv.move_to(pts[0]);
    for (int i=1;i<pts.size();i++){
        cnv.line_to(pts[i].x, pts[i].y);
    }
    cnv.stroke();
}

bool CycPath::inRange(float x, float y){
    //TODO HR
    return true;
}
void CycPath::addPoint(float x,float y){
    cx=x;cy=y;
    pts.push_back({cx,cy});
}
void CycPath::addPointRelative(float dx, float dy){
    cx=cx+dx;cy=cy+dy;
    pts.push_back({cx,cy});
}
cycfi::artist::point CycPath::getHead(){
    return {cx,cy};
}
