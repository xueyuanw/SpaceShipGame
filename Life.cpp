////
////  Life.cpp
////  Mac
////
////  Created by Sherry on 7/10/17.
////  Copyright © 2017 Sanjay Madhav. All rights reserved.
////
//
//#include "Life.h"
//
//
//// Parameter Constructor
//// Purpose: Pass in attributes
//// Input: Attributes
//Life::Life( int x, int y, GImage* image) {
//    mXOrigin = x;
//    mYOrigin = y;
//    mImage = image;
//    
//    
//    mWidth = image->getWidth();
//    mHeight = image->getHeight();
//}
//
//// Function: draw
//// Purpose: draw the image on GWindow
//// Input: Gwindow
//// Output: None
//void Life::draw(GWindow& gw) {
//    int x = 0;
//    int y = 600;
//    for(int i = 0; i< life; i++){
//        gw.draw(mImage, x, y);
//        x+=10;
//
//    }
//}
//
//
//int Life::getXOrigin(){
//    return mXOrigin;
//}
//
//int Life::getYOrigin(){
//    return mYOrigin;
//}
//
//int Life::getWidth(){
//    return mWidth;
//}
//
//int Life::getHeight(){
//    return mHeight;
//}
//
//void Life::setLife(int num){
//    life = num;
//}
