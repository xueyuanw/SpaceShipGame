// ITP 365 Summer 2017
// HW5 - Let's Play a Game
// Name: Xueyuan Wang
// Email: xueyuanw@usc.edu
// Platform: Mac OS

#include <iostream>
#include <ctime>
#include "vector.h"
#include "map.h"

#include <string>
#include <sstream>

#include "gobjects.h"
#include "gwindow.h"
#include "gtypes.h"
#include "gevents.h"
#include "ginteractors.h"

#include "Entity.h"
#include "MyJet.h"
#include "MyBullet.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "Heart.h"
#include "EnemyBoss.h"
#include "BossBullet.h"
#include "BulletBonus.h"
#include "Meteor.h"

using namespace std;

const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 600;
int score = 0;

void drawScreen(GWindow& gw, Vector<Enemy*>& enemies, MyJet* player,
                Vector< MyBullet*>& playerBullets,Vector<EnemyBullet*>& enemyBullets,
                Vector<Heart*>& hearts, Vector<EnemyBoss*>& bigEs, Vector<BulletBonus*>& bonuses,
                Vector<Meteor*>& meteors, Vector<BossBullet*>& bossBs, Entity*& background
                ) {
    //	gw.clear();
    background->draw(gw);
    for (Enemy* e : enemies) {
        e->draw(gw);
    }
    for(MyBullet* bullet: playerBullets){
        bullet->draw(gw);
    }
    for(EnemyBullet* bullet: enemyBullets){
        bullet->draw(gw);
    }
    for(Heart* heart: hearts){
        heart->draw(gw);
    }
    player->draw(gw);
    for(EnemyBoss*e : bigEs){
        e->draw(gw);
    }
    for(BulletBonus* b: bonuses){
        b->draw(gw);
    }
    for(Meteor* m: meteors){
        m->draw(gw);
    }
    for(BossBullet* b: bossBs){
        b->draw(gw);
    }
}




// Function: createEnemies
// Purpose: Add enemy to enemies vector
// Input: enemies Vector, GImage
// Output: None
void createEnemies(Vector<Enemy*>& enemies, GImage* gi) {
    
    Enemy* e = new Enemy((rand()%6)*120,(rand()%11)*15, gi);
    //    Enemy* e = new Enemy(100,0, gi);
    enemies.add(e);
    
}

// Function: createBEs
// Purpose: Add an EnemyBoss to bigEs vector
// Input: enemyBoss Vector, GImage
// Output: None
void createBEs(Vector<EnemyBoss*>& bigEs, GImage* gi) {
    
    EnemyBoss* e = new EnemyBoss((rand()%6)*120, 0, gi);
    bigEs.add(e);
}

// Function: createHeart
// Purpose: Add Heart to hearts vector
// Input: hearts Vector, GImage
// Output: None
void createHeart(Vector<Heart*>& hearts, GImage* gi) {
    Heart* h = new Heart( (rand()%100)*6, 1, gi);
    hearts.add(h);
    
}


// Function: createBonus
// Purpose: Add bulletBonus to bonuses vector
// Input: bonues Vector, GImage
// Output: None
void createBonus(Vector<BulletBonus*>& bonuses, GImage* gi) {
    BulletBonus* b = new BulletBonus( (rand()%200)*3, 1, gi);
    bonuses.add(b);
    
}

// Function: createMeteor
// Purpose: Add Meteor to meteors vector
// Input: Meteor Vector, GImage
// Output: None
void createMeteor(Vector<Meteor*>& meteors, GImage* gi) {
    Meteor* m = new Meteor( (rand()%200)*3, 1, gi);
    meteors.add(m);
    
}

// Function: loadBullet
// Purpose: Add bullet to playerBullets vector
// Input: Player, playerBullets Vector, GImage
// Output: None
void loadBullet(MyJet* player, GImage* gi,
                Vector<MyBullet*>& playerBullets){
    int XOrigin = player->getXOrigin() + player->getWidth()/2;
    int YOrigin = player->getYOrigin() + player->getHeight();
    MyBullet* bullet = new MyBullet(XOrigin, YOrigin, gi);
    playerBullets.add(bullet);
    
    
}


void load2Bullets(MyJet* player, GImage* gi,
                  Vector<MyBullet*>& playerBullets){
    int XOrigin = player->getXOrigin() + player->getWidth()/2;
    int YOrigin = player->getYOrigin() + player->getHeight();
    
    MyBullet* bullet = new MyBullet(XOrigin-20, YOrigin, gi);
    playerBullets.add(bullet);
    MyBullet* bullet2 = new MyBullet(XOrigin+15, YOrigin, gi);
    playerBullets.add(bullet2);
    
}


// Function: enemyLoadBullet
// Purpose: Add enemyBullet to enemyBullet Vector
// Input: enemies Vector, GImage, enemyBullets Vector
// Output: None
void enemyLoadBullet(Vector<Enemy*>& enemies,
                     GImage* gi,Vector<EnemyBullet*>& enemyBullets){
    for(Enemy* enemy: enemies){
        int XOrigin = enemy->getXOrigin() + enemy->getWidth()/2;
        int YOrigin = enemy->getYOrigin() + enemy->getHeight()/2;
        if(XOrigin >= 0 && XOrigin <= 600 && YOrigin>=0 && YOrigin <= 600){
            EnemyBullet* bullet = new EnemyBullet(XOrigin, YOrigin, gi);
            enemyBullets.add(bullet);
        }
        
    }
    
}


// Function: bigELoadBullet
// Purpose: Add enemyBullet to enemyBullet Vector, for enemy Boss
// Input: enemyBoss Vector, GImage, enemyBullets Vector
// Output: None
void bigELoadBullet(Vector<EnemyBoss*>& bigEs,Vector<BossBullet*>& bossBs,
                    GImage* gi, GImage* gi2, Vector<EnemyBullet*>& enemyBullets){
    for(EnemyBoss* e: bigEs){
        int XOrigin = e->getXOrigin() + e->getWidth()/2;
        int YOrigin = e->getYOrigin() + e->getHeight()/2;
        
        if(XOrigin >= 0 && XOrigin <= 600 && YOrigin>=0 && YOrigin <= 600){
            EnemyBullet* bullet1 = new EnemyBullet(XOrigin-20, YOrigin, gi);
            enemyBullets.add(bullet1);
            EnemyBullet* bullet2 = new EnemyBullet(XOrigin+10, YOrigin, gi);
            enemyBullets.add(bullet2);
            BossBullet* b = new BossBullet(XOrigin-5, YOrigin+20, gi2);
            bossBs.add(b);
        }
        
    }
    
}


// Function: getHeart
// Purpose: Check Collision Between Player and Heart -> Increase 1 Life
// Input: Player, hearts vector
// Output: None
void getHeart(MyJet* player, Vector<Heart*>& hearts){
    if(hearts.size() > 0){
        for(int j=hearts.size()-1; j >= 0  ; j--){
            if (player->contains(hearts[j])) {
                hearts.remove(j);
                player->increaseBlood();
                score += 10;
                
            }// End if
        }// End for loop
    }// End if
}


// Function: hitBonus
// Purpose: Check Collision Between Player and BulletBonus -> Load 2 Bullets
// Input: Player, bulletbonus vector
// Output: None
void hitBonus(MyJet* player, Vector<BulletBonus*>& bonuses){
    if(bonuses.size() > 0){
        for(int j=bonuses.size()-1; j >= 0  ; j--){
            if (player->contains(bonuses[j])) {
                bonuses.remove(j);
                score += 10;
                player->increaseBullet();
            }
            
        }// End for loop
    }// End if

}


bool playerShot(MyJet* player, Vector<EnemyBullet*>& enemyBullets, Vector<BossBullet*>& bossBs,
                Vector<Enemy*>& enemies, Vector<Meteor*>& meteors
                ){
    bool isDead = false;
    // Collision with EnemyBullets
    for(int j=enemyBullets.size()-1; j >= 0  ; j--){
        if (player->contains(enemyBullets[j])) {
            enemyBullets.remove(j);
            if(player->getBlood() > 0){
                player->getHurt();
            }
            else{
                //Player Dead Game Over;
                isDead = true;
                
            }
        }// End if
    }// End for loop
    
    // Collision with EnemeyBoss
    for(int j=bossBs.size()-1; j >= 0  ; j--){
        if (player->contains(bossBs[j])) {
            bossBs.remove(j);
            if(player->getBlood() > 0){
                player->getHurt();
            }
            else{
                isDead = true;
                
            }
        }// End if
    }// End for loop
    
    // Check Collisions with Enemies
    for(int j=enemies.size()-1; j >= 0  ; j--){
        if (player->contains(enemies[j])) {
            enemies.remove(j);

            if(player->getBlood() > 0){
                // Lost 1 life
                player->getHurt();
            }
            else{
                isDead = true;
                
            }
        }// End if
    }// End for loop
    
    // Check Collision with Meteors
    for(int j=meteors.size()-1; j >= 0  ; j--){
        if (player->contains(meteors[j])) {
            meteors.remove(j);
            if(player->getBlood() > 0){
                // Lost 2 lives
                player->getHurt();
            }
            else{

                isDead = true;
                
            }
        }// End if
    }// End for loop
    
    return isDead;
}


void removeAtBorder(Vector<Enemy*>& enemies, Vector< MyBullet*>& playerBullets,
                    Vector<EnemyBullet*>& enemyBullets,
                    Vector<Heart*>& hearts, Vector<EnemyBoss*>& bigEs,
                    Vector<BulletBonus*>& bonuses, Vector<Meteor*>& meteors,
                    Vector<BossBullet*>& bossBs){
    if(enemies.size() > 0){
//        cout << enemies.size() << endl;
        for(int i= enemies.size()-1; i>=0 ;i--){
            if(enemies[i]->getYOrigin() > WINDOW_HEIGHT || enemies[i]->getYOrigin() < 0 ||
               enemies[i]->getYOrigin() > WINDOW_WIDTH || enemies[i]->getYOrigin() <0 ){
                enemies.remove(i);
            }
        }
    }
 
    if(playerBullets.size() > 0){
        for(int i= playerBullets.size()-1; i>=0 ;i--){
            if(playerBullets[i]->getYOrigin() > WINDOW_HEIGHT || playerBullets[i]->getYOrigin()<0 ||
               playerBullets[i]->getXOrigin() > WINDOW_WIDTH || playerBullets[i]->getXOrigin() <0){
                playerBullets.remove(i);
            }
        }
    }
  
    if(enemyBullets.size() > 0){
        for(int i= enemyBullets.size()-1; i>=0 ;i--){
            if(enemyBullets[i]->getYOrigin() > WINDOW_HEIGHT || enemyBullets[i]->getYOrigin() <0 ||
               enemyBullets[i]->getXOrigin() > WINDOW_WIDTH || enemyBullets[i]->getXOrigin() <0){
                enemyBullets.remove(i);
            }
        }
        
    }

    if(hearts.size()>0){
        for(int i= hearts.size()-1; i>=0 ;i--){
            if(hearts[i]->getYOrigin() > WINDOW_HEIGHT || hearts[i]->getYOrigin() < 0 ||
               hearts[i]->getXOrigin() > WINDOW_WIDTH || hearts[i]->getXOrigin() < 0){
                hearts.remove(i);
            }
        }
        
    }

    if(bigEs.size() > 0){
        for(int i= bigEs.size()-1; i>=0 ;i--){
            if(bigEs[i]->getYOrigin() > WINDOW_HEIGHT || bigEs[i]->getYOrigin() <0 ||
               bigEs[i]->getXOrigin() > WINDOW_WIDTH || bigEs[i]->getXOrigin() < 0){
                bigEs.remove(i);
            }
        }
    }
  
    if(bonuses.size()>0){
        for(int i= bonuses.size()-1; i>=0 ;i--){
            if(bonuses[i]->getYOrigin() > WINDOW_HEIGHT || bonuses[i]->getYOrigin() <0 ||
               bonuses[i]->getXOrigin() > WINDOW_WIDTH || bonuses[i]->getXOrigin() < 0){
                bonuses.remove(i);
            }
        }
    }

    if(meteors.size() > 0){
        for(int i= meteors.size()-1; i>=0 ;i--){
            if(meteors[i]->getYOrigin() > WINDOW_HEIGHT || meteors[i]->getYOrigin() <0 ||
               meteors[i]->getXOrigin() > WINDOW_WIDTH || meteors[i]->getXOrigin() < 0){
                meteors.remove(i);
            }
        }
    }

    if(bossBs.size()>0){
        for(int i= bossBs.size()-1; i>=0 ;i--){
            if(bossBs[i]->getYOrigin() > WINDOW_HEIGHT || bossBs[i]->getYOrigin() <0 ||
               bossBs[i]->getXOrigin() > WINDOW_WIDTH || bossBs[i]->getXOrigin() < 0){
                bossBs.remove(i);
            }
        }
    }

    
}


// Function: hitEnemies
// Purpose: Check if a bullet hits an enemy, 3 hit -> enemy dead
// Input: enemies Vector, playerBullets vector
// Output: None
void hitEnemies(Vector< Enemy*>& enemies, Vector< MyBullet*>& playerBullets) {
    
    for (int i = enemies.size()-1 ; i >= 0 ; i-- ) {
//        cout << "i: " << i << endl;
        for(int j=playerBullets.size()-1; j >= 0  ; j--){
            //cout << "here" << endl;
            if(enemies.size() > 0 && playerBullets.size() > 0) {
                //cout << "here 2 i: " << i << endl;
                if (enemies[i]->contains(playerBullets[j])) {
                    playerBullets.remove(j);
                    
                    if(enemies[i]->getBlood() > 0){
                        enemies[i]->getHurt();
                        score += 20;
                    }
                    else{
                        //delete enemy;
                        enemies.remove(i);
                        score += 40;
                        break;
                    }
                    
                }
                
            }// End if
            
        }// End bullet for loop

    }// End enemy for loop
}


// Function: hitBoss
// Purpose: Check if a bullet hits an enemy boss, 8 hit -> enemyBoss dead
// Input: enemyBoss Vector, playerBullets vector
// Output: None
void hitBoss(Vector< EnemyBoss*>& bigEs, Vector< MyBullet*>& playerBullets) {
    
    for (int i = bigEs.size()-1 ; i >= 0 ; i-- ) {
        for(int j=playerBullets.size()-1; j >= 0  ; j--){
//            cout << "here" << endl;
            if(bigEs.size() > 0 && playerBullets.size() > 0) {
//                cout << "HERE 2 "<< endl;
                if (bigEs[i]->contains(playerBullets[j])) {
                    cout << "Have an overlap\n";
                    playerBullets.remove(j);
                    
                    if(bigEs[i]->getBlood() > 0){
                        bigEs[i]->getHurt();
                        score += 20;
                    }
                    else{
                        
                        //delete enemy;
                       
                        bigEs.remove(i);
                        score += 80;
                        break;
                        
                    }
                    
                }
               
            }// End if
            
        }// End bullet for loop
       
    }// End enemy for loop
}









int main(int argc, char** argv) {
    srand( static_cast<unsigned int>(time(0)));
    
    cout << "need a cout\n";
    
    GWindow gw(WINDOW_WIDTH, WINDOW_HEIGHT);
    
    GLabel* text = new GLabel("Enter your Name:");
    gw.addToRegion(text, "NORTH");
    
    GLabel* gameOver = new GLabel("Game Over!");

    
    
    GTextField* name = new GTextField(12);
    gw.addToRegion(name, "NORTH");
    
    GButton* playButton = new GButton("Start");
    gw.addToRegion(playButton, "NORTH");
    
    GButton* stopButton = new GButton("Stop");
    gw.addToRegion(stopButton, "NORTH");
    
    
    playButton->setActionCommand("play");
    stopButton -> setActionCommand("stop");
    
    
    // Create Background Image
    GImage *backgroundImg = new GImage("background.jpg");
    Entity* background = new Entity(-2200,-1230, backgroundImg);
    background->draw(gw);
    
    //Vector<Entity*> entities;
    Vector<Enemy*> enemies;
    Vector<MyBullet*> playerBullets;
    Vector<EnemyBullet*> enemyBullets;
    Vector<Heart*> hearts;
    Vector<EnemyBoss*> bigEs;
    Vector<BossBullet*> bossBs;
    Vector<BulletBonus*> bonuses;
    Vector<Meteor*> meteors;
    
    
    
    GImage* enemy1 = new GImage("Enemy1.png");
    GImage* myJetImg = new GImage("fighter.png");
    GImage* myBullet = new GImage("myBullet.png");
    GImage* enemyBullet = new GImage("enemyBullet.png");
    GImage* heart = new GImage("heart.png");
    GImage* boss = new GImage("enemyBoss.png");
    GImage* bossBullet = new GImage("bossB.png");
    GImage* bonus = new GImage("bonus.png");
    GImage* meteorImg = new GImage("meteor.png");
    
    
    bool isDead = false;
    
    GTimer* timer = new GTimer(25.0);

    MyJet* player = new MyJet(270, 500, myJetImg);
    
    Map<string, int> scores;
    int counter = 0;
    
    while (true) {
        
        GEvent g = waitForEvent();
        
        switch (g.getEventClass()) {
            default:
                break;
                
            case TIMER_EVENT:
          
                removeAtBorder(enemies, playerBullets, enemyBullets, hearts, bigEs, bonuses, meteors, bossBs);
                drawScreen(gw, enemies, player, playerBullets, enemyBullets, hearts, bigEs, bonuses, meteors, bossBs, background);
                if(counter % 10 == 0){
                    
                    int bullet = player->getBullet();
                    if(bullet == 2){
                        load2Bullets(player, myBullet, playerBullets);
                    }
                    else{
                        loadBullet(player, myBullet, playerBullets);
                    }
                    
                }
                if(counter % 40 == 0){
                    enemyLoadBullet(enemies, enemyBullet, enemyBullets);
                }
                if(counter % 70 == 0 ){
                    createEnemies(enemies, enemy1);
                }
                
                if(counter % 300 == 0) {
                    // Create a Meteor
                    createMeteor(meteors, meteorImg);
                }
                
                if(counter % 400 == 0){
                    // Create a Heart Bonus
                    createHeart(hearts, heart);
                }
                
                if(counter% 100 == 0){
                    createBonus(bonuses, bonus);
                }
                
                if(counter% 600 == 0){
                    // Create an EnemyBoss
                    createBEs(bigEs, boss);
                    bigELoadBullet(bigEs, bossBs, enemyBullet, bossBullet, enemyBullets);
 
                }
                
                // Move Everything
                for (Enemy* e : enemies) {
                    e->move();
                }
                
                
                for(MyBullet* b: playerBullets){
                    b->move();
                }
                for(EnemyBullet* b: enemyBullets){
                    b->move();
                }
                
                for(Heart* h: hearts){
                    h->move();
                }
                for(EnemyBoss* e: bigEs){
                    e->move();
                }
                for(BulletBonus* b: bonuses){
                    b->move();
                }
                for(Meteor* m: meteors){
                    m->move();
                }
                for(BossBullet* b:bossBs){
                    b ->move();
                }
                
                background -> move();
                
                
                
                isDead = playerShot(player, enemyBullets, bossBs, enemies, meteors);
                getHeart(player, hearts);
                hitBonus(player, bonuses);
                hitBoss(bigEs, playerBullets);
                hitEnemies(enemies, playerBullets);
               

    
                if(isDead == true){
                    timer -> stop();
       
                    gw.addToRegion(gameOver, "SOUTH");
                    
                    string playerName = name->getText();
                    scores.put(playerName, score);
                    score = 0;
                    cout << playerName << endl;
                    cout << scores[playerName] << endl;
                    
                    enemies.clear();
                    playerBullets.clear();
                    enemyBullets.clear();
                    hearts.clear();
                    bigEs.clear();
                    bonuses.clear();
                    meteors.clear();
                    bossBs.clear();
                    counter = 0;
                    delete player;
                    delete background;
                    player = new MyJet(270, 500, myJetImg);
                    background = new Entity(-2200,-1230, backgroundImg);
                    
                    drawScreen(gw, enemies, player, playerBullets, enemyBullets, hearts, bigEs, bonuses, meteors, bossBs, background);
                    
                }

                counter++;
                drawScreen(gw, enemies, player, playerBullets, enemyBullets, hearts, bigEs, bonuses, meteors, bossBs, background);
                
                break;
                
                
            case ACTION_EVENT:
                if (GActionEvent(g).getActionCommand() == "play") {
                    timer->start();
                    gw.remove(gameOver);
                    
                }
                else if(GActionEvent(g).getActionCommand() == "stop"){
                    timer->stop();
                    
                    
                }
                
                break;
                
                
                
            case MOUSE_EVENT:{
                //This is where you go when the user does something with the mouse - moving, clicking, etc.
                //This also happens when a button is clicked on.
                if (GMouseEvent(g).getEventType() == MOUSE_MOVED) {
                    int x = GMouseEvent(g).getX();
                    int y = GMouseEvent(g).getY();
                    
                    if(x >= 0 && x <= 600 && y>=0 && y<=600){
                        player->setOrigin(x-player->getWidth()/2, y-player->getHeight()/2);
                    }
                    
                }
                
                break;
            }// End Mouse Event
                
                
                
        }// End Switch
        
        
        
        
        
    }// End While
    
    return 0;
}
