#include <stdio.h>
#include <stdlib.h>

#define IN_RANGE(x,min,max) ((x)>=(min) &&  (x)<=(max))

void mouseDownAt(float percentX, float percentY){
    int x = 0;
    int y = 0;
    if(IN_RANGE(percentX,0,1.0f) && IN_RANGE(percentY,0,1.0f)){
        convert(&percentX, &percentY);
        x = (int)percentX;
        y = (int)percentY;
        //generate mouseclick
        #ifdef __unix
            printf("Mouse click @ %d , %d",x,y);
        #endif // __unix
    }else{
        //throw error about off of screen
    }
}

void mouseUpAt(float percentX, float percentY){}

void touchDownAt(float percentX, float percentY){
    /*if(IN_RANGE(percentX,0,1.0f) && IN_RANGE(percentY,0,1.0f)){
        printf("test2");
    }*/
}

/**
Converts percent of screen space into pixel coordantes.
*/

void convert(float* x, float* y){
    int w = 800;
    int h = 600;

    if(IN_RANGE(*x,0,1.0f) && IN_RANGE(*y,0,1.0f)){
        //get sceen res
        //calc pixel positions
        *x = *x * w;
        *y = *y * h;
    }
}
ssss
