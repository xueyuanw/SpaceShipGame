//
//  MyJet.cpp
//  Mac
//
//  Created by Sherry on 6/28/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#include "MyJet.h"

// Parameter Constructor
// Purpose: Pass in attributes
// Input: Attributes
MyJet::MyJet( int x, int y, GImage* image) {
    mXOrigin = x;
    mYOrigin = y;
    mImage = image;

    mWidth = image->getWidth();
    mHeight = image->getHeight();
    
    // Set Initial Blood Value of 5 and bullet Value of 1
    blood = 5;
    bullet = 1;
}


// Function: draw
// Purpose: draw the image on GWindow
// Input: Gwindow
// Output: None
void::MyJet::draw(GWindow& gw) {
    gw.draw(mImage, mXOrigin, mYOrigin);
}



// Getter Functions

int MyJet::getXOrigin(){
    return mXOrigin;
}

int MyJet::getYOrigin(){
    return mYOrigin;
}

int MyJet::getHeight(){
    return mHeight;
}

int MyJet::getWidth(){
    return mWidth;
}

int MyJet::getBlood(){
    return blood;
}


int MyJet::getBullet(){
    return bullet;
}

// Purpose: Set Origin by Mouse in main
void MyJet::setOrigin(int x, int y){
    mXOrigin = x;
    mYOrigin = y;
    
}

// Purpose: Reduce blood by 1, Put bullet number back to one
void MyJet::getHurt(){
    blood --;
    bullet = 1;
    cout << "PLAYER BLODD: " << blood << endl;
}


// Check overlap between player and enemyBullet, Enemey, Heart, BulletBonus, Meteor, BossEnemy, BossBullet

bool MyJet::contains(EnemyBullet* bullet) {
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

bool MyJet::contains(Enemy* enemy) {
    
    int leftX = enemy->getXOrigin();
    int topY = enemy->getYOrigin();
    int rightX = leftX + enemy->getWidth();
    int bottomY = topY + enemy->getHeight();
    
    if (mImage->contains(leftX, topY) || mImage->contains(leftX, bottomY) ||
        mImage->contains(rightX, topY) || mImage->contains(rightX, bottomY)) {
        //We have an overlap
        return true;
    }
    
    //No overlap
    return false;
}

bool MyJet::contains(Heart* heart) {
    int leftX = heart->getXOrigin();
    int topY = heart->getYOrigin();
    int rightX = leftX + heart->getWidth();
    int bottomY = topY + heart->getHeight();
    
    if (mImage->contains(leftX, topY) || mImage->contains(leftX, bottomY) ||
        mImage->contains(rightX, topY) || mImage->contains(rightX, bottomY)) {
        //We have an overlap
        return true;
    }
    
    //No overlap
    return false;
}


bool MyJet::contains(BulletBonus* bonus) {
    int leftX = bonus->getXOrigin();
    int topY = bonus->getYOrigin();
    int rightX = leftX + bonus->getWidth();
    int bottomY = topY + bonus->getHeight();
    
    if (mImage->contains(leftX, topY) || mImage->contains(leftX, bottomY) ||
        mImage->contains(rightX, topY) || mImage->contains(rightX, bottomY)) {
        //We have an overlap
        return true;
    }
    
    //No overlap
    return false;
}

bool MyJet::contains(Meteor* meteor) {
    int leftX = meteor->getXOrigin();
    int topY = meteor->getYOrigin();
    int rightX = leftX + meteor->getWidth();
    int bottomY = topY + meteor->getHeight();
    
    if (mImage->contains(leftX, topY) || mImage->contains(leftX, bottomY) ||
        mImage->contains(rightX, topY) || mImage->contains(rightX, bottomY)) {
        //We have an overlap
        return true;
    }
    
    //No overlap
    return false;
}


bool MyJet::contains(BossBullet* bossB) {
    int leftX = bossB->getXOrigin();
    int topY = bossB->getYOrigin();
    int rightX = leftX + bossB->getWidth();
    int bottomY = topY + bossB->getHeight();
    
    if (mImage->contains(leftX, topY) || mImage->contains(leftX, bottomY) ||
        mImage->contains(rightX, topY) || mImage->contains(rightX, bottomY)) {
        //We have an overlap
        return true;
    }
    
    //No overlap
    return false;
}

// Purpose" increase blood level by 1
void MyJet::increaseBlood(){
    blood ++;
    
}

// Increae bullet number to 2
void MyJet::increaseBullet(){
    bullet  = 2;
}

