//
//  DrawImage.h
//  Mac
//
//  Created by Sherry on 6/28/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#pragma once

#include "gwindow.h"
#include "gobjects.h"

class DrawImage {
protected:
    GImage* mImage;
    int mXOrigin;
    int mYOrigin;
    
public:
    // Default Constructor
    DrawImage();
    
    // Parameter Constructor
    // Purpose: Pass in attributes
    // Input: Attributes
    DrawImage(int mXOrigin, int mYOrigin, GImage* image);
    
    // Function: draw
    // Purpose: draw the image on GWindow
    // Input: Gwindow
    // Output: None
    virtual void draw(GWindow& gw);
    
    // Function: move
    // Purpose: Change X and Y Origin
    // Input: None
    // Output: None
    virtual void move();
};


// Class Enemy, MyBullet, Heart, Plane, BulletBonus

