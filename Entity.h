#pragma once

#include "gwindow.h"
#include "gobjects.h"
#include <string>
#include <ostream>

using namespace std;

class Entity {
protected:
    GImage* mImage;
    int mXOrigin;
    int mYOrigin;
    int mXMove;
    int mYMove;
    int mWidth;
    int mHeight;
    
public:
    Entity();
    Entity(int mXOrigin, int mYOrigin, GImage* image);
    void draw(GWindow& gw);
    virtual void move();
    virtual bool contains(Entity* other);
    virtual int getWidth();
    virtual int getHeight();

};

