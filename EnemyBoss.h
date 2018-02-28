//
//  EnemyBoss.h
//  Mac
//
//  Created by Sherry on 6/28/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#pragma once
#include "Entity.h"
#include "MyBullet.h"

class EnemyBoss:public Entity{
private:
    // Inherit From DrawImage
    int mXMove;
    int mYMove;
    int heart;
    
    
public:
    // Parameter Constructor
    // Purpose: Pass in attributes
    // Input: Attributes
    EnemyBoss(int mXOrigin, int mYOrigin, GImage* image);
    
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

    
    // Getters
    int getBlood();
    
    int getXOrigin();
    int getYOrigin();
    int getWidth();
    int getHeight();
    
    // Check collision of player's bullet
    bool contains(MyBullet* bullet);
    
    // Reduce heart by 1
    void getHurt();
    
};
