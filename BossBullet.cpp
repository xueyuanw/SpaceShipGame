//
//  BossBullet.cpp
//  Mac
//
//  Created by Sherry on 7/10/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#include "BossBullet.h"


// Parameter Constructor
// Purpose: Pass in attributes
// Input: Attributes
BossBullet::BossBullet( int x, int y, GImage* image) {
    mXOrigin = x;
    mYOrigin = y;
    mImage = image;
    
    
    mWidth = image->getWidth();
    mHeight = image->getHeight();
}

// Function: draw
// Purpose: draw the image on GWindow
// Input: Gwindow
// Output: None
void BossBullet::draw(GWindow& gw) {
    gw.draw(mImage, mXOrigin, mYOrigin);
}

// Function: move
// Purpose: Change X and Y Origin
// Input: None
// Output: None
void BossBullet::move(){
    // MyBullet moves down by 10
    mYOrigin += 10;
}


int BossBullet::getXOrigin(){
    return mXOrigin;
}

int BossBullet::getYOrigin(){
    return mYOrigin;
}

int BossBullet::getWidth(){
    return mWidth;
}

int BossBullet::getHeight(){
    return mHeight;
}
