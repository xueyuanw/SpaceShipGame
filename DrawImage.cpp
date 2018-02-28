//
//  DrawImage.cpp
//  Mac
//
//  Created by Sherry on 6/28/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#include "DrawImage.h"

// Default Constructor
DrawImage::DrawImage(){
    
}

// Parameter Constructor
// Purpose: Pass in attributes
// Input: Attributes
DrawImage::DrawImage( int x, int y, GImage* image) {
    mXOrigin = x;
    mYOrigin = y;
    mImage = image;
}


// Function: draw
// Purpose: draw the image on GWindow
// Input: Gwindow
// Output: None
void::DrawImage::draw(GWindow& gw) {
    gw.draw(mImage, mXOrigin, mYOrigin);
}


// Function: move
// Purpose: Change X and Y Origin
// Input: None
// Output: None
void::DrawImage::move() {
    //Each image moves by 1 pixel in the x and y directions
    mXOrigin++;
    mYOrigin++;
}
