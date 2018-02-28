//
//  MyJet.h
//  Mac
//
//  Created by Sherry on 6/28/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#pragma once
#include "Entity.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "Heart.h"
#include "BulletBonus.h"
#include "Meteor.h"
#include "BossBullet.h"

class MyJet:public Entity{
private:
    int blood;
    int bullet;
    
public:
    // Parameter Constructor
    // Purpose: Pass in attributes
    // Input: Attributes
    MyJet(int mXOrigin, int mYOrigin, GImage* image);
    
    // Function: draw
    // Purpose: draw the image on GWindow
    // Input: Gwindow
    // Output: None
    void draw(GWindow& gw);
    

    
    // Reset the Origin of MyJet
    void setOrigin(int x, int y);
    
    // Get XOrigin, YOrigin, Width, Height of this object
    int getXOrigin();
    int getYOrigin();
    int getWidth();
    int getHeight();
    
    // Get the blood value
    int getBlood();
    // Get the bullet number
    int getBullet();
    
    // Reduce blood by 1
    void getHurt();
    

    
    // Check overlap between player and enemyBullet, Enemey, Heart, BulletBonus, Meteor, BossEnemy, BossBullet
    bool contains(EnemyBullet* bullet);
    bool contains(Enemy* enemy);
    bool contains(Heart* heart);
    bool contains(BulletBonus* bonus);
    bool contains(Meteor* meteor);
    bool contains(BossBullet* bossB);
    
    // Increase the blood level
    void increaseBlood();
    
    // Increase Bullet number by 1
    void increaseBullet();
    

    
};
