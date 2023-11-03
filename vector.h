#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#define RAD 0.0174533

class pvector{
    public:
        pvector(float dir, float mag);

        float getDir();
        float getMagnitude();
        float getDeltaX();
        float getDeltaY();

        float setDir(float angle);
        float setMagnitude(float magnitude);

    private:
        float va;

        float vdx;
        float vdy;

        float vm;
};
