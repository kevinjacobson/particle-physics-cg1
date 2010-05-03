#include "drawableparticle.h"

using namespace pengine;

void DrawableParticle::getColor(real* color)
{
    color = this->color;
}

real* DrawableParticle::getColor()
{
    return this->color;
}

real DrawableParticle::getRed(){
    return color[0];
}

real DrawableParticle::setRed(real red){
    real temp = color[0];
    color[0] = red;
    return temp;
}

real DrawableParticle::setGreen(real green){
    real temp = color[1];
    color[1] = green;
    return temp;
}

