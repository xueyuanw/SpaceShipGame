//
//  Meteor.cpp
//  Mac
//
//  Created by Sherry on 7/10/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#include "Meteor.h"


// Parameter Constructor
// Purpose: Pass in attributes
// Input: Attributes
Meteor::Meteor( int x, int y, GImage* image) {
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
void Meteor::draw(GWindow& gw) {
    gw.draw(mImage, mXOrigin, mYOrigin);
}

// Function: move
// Purpose: Change X and Y Origin
// Input: None
// Output: None
void Meteor::move(){
    // MyBullet moves down 10
    mYOrigin += 10;
}


int Meteor::getXOrigin(){
    return mXOrigin;
}

int Meteor::getYOrigin(){
    return mYOrigin;
}

int Meteor::getWidth(){
    return mWidth;
}

int Meteor::getHeight(){
    return mHeight;
}
