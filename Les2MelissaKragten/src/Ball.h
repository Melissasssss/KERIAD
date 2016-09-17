#pragma once

#include "ofMain.h"


class Ball {

    public:

		Ball();

        void setup();

        void update();

        void draw();
		void mousePressed(int x, int y, int button);

        // variables
        float x;
        float y;
        float speedY;
        float speedX;
        int radius;
        ofColor color;


    private:

};
