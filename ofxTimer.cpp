#include "ofxTimer.h"

ofEvent<ofVec2f> ofxTimer::timerFin = ofEvent<ofVec2f>();

ofxTimer::ofxTimer() {
    startTime = ofGetElapsedTimeMillis();
    endTime = ofGetElapsedTimeMillis() +100;
    TimerReached = true;
    mappedTime = 255;
}
//--------------------------
ofxTimer::~ofxTimer() {
    startTime = 0;
    endTime = 0;
    TimerReached = true;
    mappedTime = 255;
    
}

void ofxTimer::timer(float start,bool fade,bool _sel){
    sel = _sel;
    startTime = ofGetElapsedTimeMillis();  // get the start time
    endTime = start; 
    TimerReached = false;
    fadeUpDown = fade;
}


float ofxTimer::update(){
    if(!TimerReached){
   float timerZ =  ofGetElapsedTimeMillis() - startTime;
    if(timerZ >= endTime && !TimerReached) {
        TimerReached = true;
        if(sel){
        ofVec2f temp = ofVec2f(0,0);
        ofNotifyEvent(timerFin, temp);
            sel = false;
        }
    }
        if(fadeUpDown){
     mappedTime = ofMap(ofGetElapsedTimeMillis(), startTime, startTime + endTime , 255, 0,true);
        }
        else{
       mappedTime = ofMap(ofGetElapsedTimeMillis(), startTime, startTime + endTime , 0, 255,true);
        }
    }
       return mappedTime;
}



