//
//  MyBullet.cpp
//  Mac
//
//  Created by Sherry on 6/28/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#include "MyBullet.h"


// Parameter Constructor
// Purpose: Pass in attributes
// Input: Attributes
MyBullet::MyBullet( int x, int y, GImage* image) {
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
void MyBullet::draw(GWindow& gw) {
    gw.draw(mImage, mXOrigin, mYOrigin);
}

// Function: move
// Purpose: Change X and Y Origin
// Input: None
// Output: None
void MyBullet::move(){
    // MyBullet moves by 10 in y(up) directions
    mYOrigin -= 15;
}


int MyBullet::getXOrigin(){
    return mXOrigin;
}

int MyBullet::getYOrigin(){
    return mYOrigin;
}

int MyBullet::getWidth(){
    return mWidth;
}

int MyBullet::getHeight(){
    return mHeight;
}
