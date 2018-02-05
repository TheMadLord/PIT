#include <stdio.h>
#include <stdlib.h>
#include "../inc/pit_ERROR.h"

#define IN_RANGE(x,min,max) ((x)>=(min) &&  (x)<=(max))
#define __unix
int screenWidth = 0;
int screenHeight = 0;

void initScreen();
int* convert(float x, float y);

void initScreen(){
    #ifdef __unix
    //getScreenWidth
    screenWidth = 800;
    //getScreenHeight
    screenHeight = 600;
    #else
    //getScreenWidth
    screenWidth = 800;
    //getScreenHeight
    screenHeight = 600;
    #endif // __unix
}

int mouseDownAt(float percentX, float percentY){
    int* point;
    if(IN_RANGE(percentX,0,1.0f) && IN_RANGE(percentY,0,1.0f)){
        point = convert(percentX, percentY);
        //generate mousedown
        #ifdef __unix
        printf("Mouse down @ %d , %d\n",point[0],point[1]);
        #endif // __unix
        return NO_ERROR;
    }else{
        return ERR_OUT_OFF_BOUNDS;
    }
}

int mouseUpAt(float percentX, float percentY){
    int* point;
    if(IN_RANGE(percentX,0,1.0f) && IN_RANGE(percentY,0,1.0f)){
        point = convert(percentX, percentY);
        //generate mousedown
        #ifdef __unix
        printf("Mouse Up @ %d , %d\n",point[0],point[1]);
        #endif // __unix
        return NO_ERROR;
    }else{
        return ERR_OUT_OFF_BOUNDS;
    }
}

int touchDownAt(float percentX, float percentY){
    /*if(IN_RANGE(percentX,0,1.0f) && IN_RANGE(percentY,0,1.0f)){
        printf("test2");
    }*/
    return NOT_DEFINED_YET;
}

/**
Converts percent of screen space into pixel coordantes.
*/

int* convert(float x, float y){
    static int point[2] = {-1,-1};
    if(screenWidth == 0){
        initScreen();
    }
    point[0] = (int)(x * screenWidth);
    point[1] = (int)(y * screenHeight);
    return point;
}
