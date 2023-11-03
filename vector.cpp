#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#define RAD 0.0174533

pvector::pvector(float dir, float mag){
    va=dir;

    vdx=cos(dir*RAD);
    vdy=sin(dir*RAD);

    vm=mag;
}

float pvector::getDir(){
    return va;
}

float pvector::getDeltaX(){
    return vdx;
}

float pvector::getDeltaY(){
    return vdy;
}

float pvector::getMagnitude(){
    return vm;
}

float pvector::setDir(float angle){
    va=angle;

    vdx=cos(angle*RAD);
    vdy=sin(angle*RAD);
}

float pvector::setMagnitude(float magnitude){
    vm=magnitude;
}
