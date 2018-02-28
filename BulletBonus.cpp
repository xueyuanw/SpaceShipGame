//
//  BulletBonus.cpp
//  Mac
//
//  Created by Sherry on 6/28/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#include "BulletBonus.h"

// Parameter Constructor
// Purpose: Pass in attributes
// Input: Attributes
BulletBonus::BulletBonus( int x, int y, GImage* image) {
    mXOrigin = x;
    mYOrigin = y;
    mImage = image;
    mWidth = mImage->getWidth();
    mHeight = mImage->getHeight();

}

// Function: draw
// Purpose: draw the image on GWindow
// Input: Gwindow
// Output: None
void::BulletBonus::draw(GWindow& gw) {
    gw.draw(mImage, mXOrigin, mYOrigin);
}

// Function: move
// Purpose: Change X and Y Origin
// Input: None
// Output: None
void BulletBonus::move(){
    // Bullet moves by 5 pixel in y(down) directions
    mYOrigin += 5;
}

int BulletBonus::getWidth(){
    return mWidth;
}
int BulletBonus::getHeight(){
    return mHeight;
}

int BulletBonus::getXOrigin(){
    return mXOrigin;
}

int BulletBonus::getYOrigin(){
    return mYOrigin;
}
