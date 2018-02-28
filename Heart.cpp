//
//  Heart.cpp
//  Mac
//
//  Created by Sherry on 6/28/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#include "Heart.h"


// Parameter Constructor
// Purpose: Pass in attributes
// Input: Attributes
Heart::Heart( int x, int y, GImage* image) {
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
void::Heart::draw(GWindow& gw) {
    gw.draw(mImage, mXOrigin, mYOrigin);
}

// Function: move
// Purpose: Change X and Y Origin
// Input: None
// Output: None
void Heart::move(){
    // Heart moves by 5 pixel in the Y down directions
    mYOrigin += 5;
}

int Heart::getXOrigin(){
    return mXOrigin;
}

int Heart::getYOrigin(){
    return mYOrigin;
}

int Heart::getWidth(){
    return mWidth;
}

int Heart::getHeight(){
    return mHeight;
}
