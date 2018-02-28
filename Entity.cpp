#include "Entity.h"
#include <iostream>


// Default Constructor
Entity::Entity(){
    
}

Entity::Entity(int x, int y, GImage* image) {
    mXOrigin = x;
    mYOrigin = y;
    mImage = image;
    mWidth = mImage->getWidth();
    mHeight = mImage->getHeight();
    
}

void Entity::draw(GWindow& gw) {
    gw.draw(mImage, mXOrigin, mYOrigin);
}

void Entity::move() {
    mXOrigin+= 0.2;
    mYOrigin+= 0.1;
}

int Entity::getWidth() {
    return mWidth;
}

int Entity::getHeight() {
    return mHeight;
}

bool Entity::contains(Entity* other) {
    //Check if the current entity overlaps 'other'
    //We do this by checking the four corners of 'other'
    int leftX = other->mXOrigin;
    int topY = other->mYOrigin;
    int rightX = leftX + other->getWidth();
    int bottomY = topY + other->getHeight();
    
    if (mImage->contains(leftX, topY) || mImage->contains(leftX, bottomY) ||
        mImage->contains(rightX, topY) || mImage->contains(rightX, bottomY)) {
        //We have an overlap
        return true;
    }
    
    //No overlap
    return false;
}


