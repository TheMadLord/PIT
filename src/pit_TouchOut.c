#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
    #include <windows.h>
#endif // __windows
//#include <X11/Xlib.h>

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
    //linux code
    screenWidth = 800;
    screenHeight = 600;
    #endif // __unix
    #ifdef _WIN32
    //windows code
    //windows uses relative screen space (0,0) = upper left, (65535,65535) = lower, right.
    screenWidth = 65535;
    screenHeight = 65535;
    #endif
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
        #ifdef _WIN32
            //windows code goes here
            mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE,point[0],point[1],0,0);
            mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
        #endif // _WIN32
        //MOUSEEVENTF_ABSOLUTE
        onDebug(printf("Mouse down @ %d, %d \n",point[0],point[1]));
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
            //linux code goes here
        #endif // __unix
        #ifdef _WIN32
            //windows code goes here
            mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE,point[0],point[1],0,0);
            mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
        #endif // _WIN32
        onDebug(printf("Mouse Up   @ %d, %d\n",point[0],point[1]));
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
Converts percent of screen space into pixel coordinate.
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
