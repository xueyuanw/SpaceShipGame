//
//  Enemy.cpp
//  Mac
//
//  Created by Sherry on 6/28/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#include "Enemy.h"

// Parameter Constructor
// Purpose: Pass in attributes
// Input: Attributes
Enemy::Enemy(int x, int y, GImage* image) {
    mXOrigin = x;
    mYOrigin = y;
    mImage = image;
    heart = 2;
    
    //Randomize the movement x-> Get -1, 0, or 1
    mXMove = (rand() % 3 - 1);;
    mYMove = 1;
    
    //    mXMove = 1;
    //    mYMove = 1;
    
    mWidth = image->getWidth();
    mHeight = image->getHeight();
    
}

// Function: draw
// Purpose: draw the image on GWindow
// Input: Gwindow
// Output: None
void::Enemy::draw(GWindow& gw) {
    gw.draw(mImage, mXOrigin, mYOrigin);
}

// Function: move
// Purpose: Change X and Y Origin
// Input: None
// Output: None
void Enemy::move(){
    // Enemy moves by 2 pixel in the x(right) and 4 in y(down) directions
    mXOrigin+= mXMove;
    mYOrigin+= mYMove;
}


bool Enemy::contains(MyBullet* bullet) {
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

void Enemy::getHurt(){
    heart -= 1;

}

int Enemy::getBlood(){
    return heart;
}

int Enemy::getXOrigin(){
    return mXOrigin;
}

int Enemy::getYOrigin(){
    return mYOrigin;
}

int Enemy::getWidth(){
    return mWidth;
}

int Enemy::getHeight(){
    return mHeight;
}
