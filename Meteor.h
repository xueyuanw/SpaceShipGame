//
//  Meteor.h
//  Mac
//
//  Created by Sherry on 7/10/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#pragma once

#include "Entity.h"

class Meteor:public Entity{
private:
    
public:
    // Parameter Constructor
    // Purpose: Pass in attributes
    // Input: Attributes
    Meteor(int mXOrigin, int mYOrigin, GImage* image);
    
    // Function: draw
    // Purpose: draw the image on GWindow
    // Input: Gwindow
    // Output: None
    void draw(GWindow& gw);
    
    // Function: move
    // Purpose: Change X and Y Origin
    // Input: None
    // Output: None
    void move();
    
    // Get XOrigin, YOrigin, Width, Height of this object
    int getXOrigin();
    int getYOrigin();
    int getWidth();
    int getHeight();
    
};
