#ifndef _ofxTimer
#define _ofxTimer

#include "ofMain.h"



class ofxTimer {
	
private:
	
public:
	
	ofxTimer();
	~ofxTimer();
    static ofEvent<ofVec2f> timerFin;
    void timer(float start,bool fade,bool _sel);
    float update();
    float startTime;
    float endTime;
    float getNumber();
    bool TimerReached;
    float mappedTime;
    bool fadeUpDown;
    bool sel;
};

#endif