#include "CycObject.h"
#include "CycPath.h"
using namespace std;
CycObject::CycObject(CycCanvas &cyccnv, float cx, float cy)
{
    this->cx = cx;
    this->cy = cy;
    cyccnv.objects.push_back(this);
    this->cyccnv = &cyccnv;
}
CycObject::CycObject(){};
void CycObject::setCanvas(CycCanvas &cyccnv)
{
    cyccnv.objects.push_back(this);
    this->cyccnv = &cyccnv;
}
void CycObject::setVis(bool isVis)
{
    this->isVis = isVis;
}
void CycObject::moveTo(float x, float y)
{
    this->cx = x;
    this->cy = y;
    if (isPenDown)
    {
        this->paths[this->paths.size() - 1]->addPoint(x, y);
    }
}
void CycObject::moveBy(float dx, float dy)
{
    this->cx += dx;
    this->cy += dy;
    if (isPenDown)
    {
        this->paths[this->paths.size() - 1]->addPointRelative(dx, dy);
    }
}
void CycObject::update(cycfi::artist::canvas &cnv)
{
    if (isVis)
    {
        render(cnv);
    }
}
void CycObject::setPenType(float penStrokeWidth, cycfi::artist::color penStrokeColor)
{
    this->penStrokeColor = penStrokeColor;
    this->penStrokeWidth = penStrokeWidth;
}
bool CycObject::togglePen()
{
    isPenDown = !isPenDown;
    if (isPenDown)
    {
        paths.push_back(new CycPath(*cyccnv, cx, cy, penStrokeWidth, penStrokeColor));
    }
    return isPenDown;
}
