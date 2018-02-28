//
//  EnemyBoss.cpp
//  Mac
//
//  Created by Sherry on 6/28/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#include "EnemyBoss.h"

// Parameter Constructor
// Purpose: Pass in attributes
// Input: Attributes
EnemyBoss::EnemyBoss(int x, int y, GImage* image) {
    mXOrigin = x;
    mYOrigin = y;
    mImage = image;
    heart = 8;
    
    //Randomize the movement Get -1, 0, or 1
    mXMove = (rand() % 3 - 1);
    mYMove = 1;
    
    mWidth = image->getWidth();
    mHeight = image->getHeight();
    
}

// Function: draw
// Purpose: draw the image on GWindow
// Input: Gwindow
// Output: None
void::EnemyBoss::draw(GWindow& gw) {
    gw.draw(mImage, mXOrigin, mYOrigin);
}

// Function: move
// Purpose: Change X and Y Origin
// Input: None
// Output: None
void EnemyBoss::move(){
    // EnemyBoss moves by 2 pixel in the x(right) and 4 in y(down) directions
    mXOrigin+= mXMove;
    mYOrigin+= mYMove;
}



int EnemyBoss::getBlood(){
    return heart;
}

int EnemyBoss::getXOrigin(){
    return mXOrigin;
}

int EnemyBoss::getYOrigin(){
    return mYOrigin;
}

int EnemyBoss::getWidth(){
    return mWidth;
}

int EnemyBoss::getHeight(){
    return mHeight;
}


bool EnemyBoss::contains(MyBullet* bullet) {
    //Check if the current entity overlaps 'other'
    //We do this by checking the four corners of 'other'
    int leftX = bullet->getXOrigin();
    int topY = bullet->getYOrigin();
    int rightX = leftX + bullet->getWidth();
    int bottomY = topY + bullet->getHeight();
    
    if (mImage->contains(leftX, topY) || mImage->contains(leftX, bottomY) ||
        mImage->contains(rightX, topY) || mImage->contains(rightX, bottomY)) {
        //We have an overlap
        return true;
    }
    
    //No overlap
    return false;
}

void EnemyBoss::getHurt(){
    heart -= 1;
    
}
