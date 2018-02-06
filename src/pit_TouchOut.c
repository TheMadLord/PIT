#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

#include "../inc/pit_ERROR.h"

#define IN_RANGE(x,min,max) ((x)>=(min) &&  (x)<=(max))

int screenWidth = 0;
int screenHeight = 0;

void initScreen();
int* convert(float x, float y);

/*
int getRootWindowSize(int *w, int *h)
{
    Display* pdsp = NULL;
    Window wid = 0;
    XWindowAttributes xwAttr;
    pdsp = XOpenDisplay( NULL );
    if ( !pdsp ) {
        printf("Failed to open default display.\n");
        return -1;
    }
    wid = DefaultRootWindow( pdsp );
    if ( 0 > wid ) {
        printf("Failed to obtain the root windows Id of the default screen of given display.\n");
        return -2;
    }
    Status ret = XGetWindowAttributes( pdsp, wid, &xwAttr );
    *w = xwAttr.width;
    *h = xwAttr.height;
    XCloseDisplay( pdsp );
    return 0;
}*/


void initScreen(){
    #ifdef __unix
    //linux code goes here
    //getScreenWidth
    screenWidth = 800;
    //getScreenHeight
    screenHeight = 600;
    #else
    //windows code goes here
    //getScreenWidth
    screenWidth = 800;
    //getScreenHeight
    screenHeight = 600;
    #endif // __unix
    onDebug(printf("Screen Set to %d x %d\n", screenWidth, screenHeight));
}

int mouseDownAt(float percentX, float percentY){
    int* point;
    if(IN_RANGE(percentX,0,1.0f) && IN_RANGE(percentY,0,1.0f)){
        point = convert(percentX, percentY);
        //generate mousedown
        #ifdef __unix
            //linux code goes here
        #endif // __unix
        #ifdef __windows
            //windows code goes here
        #endif // __windows
        onDebug(printf("Mouse down @ %d %d \n",point[0],point[1]));
        free(point);
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
        #endif // __unix
        onDebug(printf("Mouse Up @ %d , %d\n",point[0],point[1]));
        free(point);
        return NO_ERROR;
    }else{
        return ERR_OUT_OFF_BOUNDS;
    }
}

int touchDownAt(float percentX, float percentY){
    return NOT_DEFINED_YET;
}
int touchUpAt(){
    return NOT_DEFINED_YET;
}

/**
Converts percent of screen space into pixel coordantes.
*/

int* convert(float x, float y){
    int * point = malloc(sizeof(int));
    if(screenWidth == 0){
        initScreen();
    }
    point[0] = (int)(x * screenWidth);
    point[1] = (int)(y * screenHeight);
    return point;
}
