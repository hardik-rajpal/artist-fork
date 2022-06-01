#include "CycText.h"
CycText::CycText(CycCanvas &cyccnv, float cx, float cy, std::string value, float fontsz, cycfi::artist::color fillColor, cycfi::artist::color strokeColor) : CycShape(cyccnv, cx, cy, fillColor, strokeColor)
{
    this->value = value;
    this->fontsz = fontsz;
}
void CycText::render(cycfi::artist::canvas &cnv)
{
    cnv.fill_style(fillColor);
    cnv.stroke_style(strokeColor);
    cnv.font(cycfi::artist::font_descr{"Open Sans", fontsz});
    cnv.fill_text(this->value, cx, cy);
}
bool CycText::inRange(float x, float y)
{
    return true;
}
