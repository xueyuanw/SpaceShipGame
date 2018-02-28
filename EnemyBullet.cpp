//
//  EnemyBullet.cpp
//  Mac
//
//  Created by Sherry on 7/10/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#include "EnemyBullet.h"


// Parameter Constructor
// Purpose: Pass in attributes
// Input: Attributes
EnemyBullet::EnemyBullet( int x, int y, GImage* image) {
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
void EnemyBullet::draw(GWindow& gw) {
    gw.draw(mImage, mXOrigin, mYOrigin);
}

// Function: move
// Purpose: Change X and Y Origin
// Input: None
// Output: None
void EnemyBullet::move(){
    // MyBullet moves down by 8
    mYOrigin += 8;
}


int EnemyBullet::getXOrigin(){
    return mXOrigin;
}

int EnemyBullet::getYOrigin(){
    return mYOrigin;
}

int EnemyBullet::getWidth(){
    return mWidth;
}

int EnemyBullet::getHeight(){
    return mHeight;
}
