#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif // __windows
//#include <X11/Xlib.h>

#include "pit_ERROR.h"

#define IN_RANGE(x,min,max) ((x)>=(min) &&  (x)<=(max))


#define INIT_MASK_SCREEN 1
#define INIT_MASK_TOUCH  2

int screenWidth = 0;
int screenHeight = 0;
byte initMask = 0;

int initScreen();
int initTouch();
int* convert(float x, float y, bool);

/**
Initializes all screen space variables.

@return an Error code, non zero is error
*/
int initScreen() {
#ifdef __unix
	//linux code
	screenWidth = 800;
	screenHeight = 600;
#endif // __unix
#ifdef _WIN32
	//windows code
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	screenWidth = desktop.right;
	screenHeight = desktop.bottom;
#endif
	onDebug(printf("Screen Set to %d x %d\n", screenWidth, screenHeight));
	initMask = initMask | INIT_MASK_SCREEN;
	return ERR_NONE;
}
/**
Initializes touch systems

@return an Error code, non zero is error
*/
int initTouch() {
	#ifdef _WIN32
	if (InitializeTouchInjection(10, TOUCH_FEEDBACK_DEFAULT)) {
		onDebug(printf("<Windows Only> Init Touch Injection System\n"));
		initMask = initMask | INIT_MASK_TOUCH;
		return ERR_NONE;
	}
	#endif // _WIN32
	return ERR_FAILED_INIT;
}

int mouseDownAt(float percentX, float percentY) {
	int* point;
	if (IN_RANGE(percentX, 0, 1.0f) && IN_RANGE(percentY, 0, 1.0f)) {
		point = convert(percentX, percentY, true);
		//generate mousedown
#ifdef __unix
		//linux code goes here
#endif // __unix
#ifdef _WIN32
		//windows code goes here
		mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, point[0], point[1], 0, 0);
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
#endif // _WIN32
		//MOUSEEVENTF_ABSOLUTE
		onDebug(printf("Mouse down @ %d, %d \n", point[0], point[1]));;
		return ERR_NONE;
	}
	else {
		return ERR_OUT_OF_BOUND;
	}
}

int mouseUpAt(float percentX, float percentY) {
	int* point;
	
	if (IN_RANGE(percentX, 0, 1.0f) && IN_RANGE(percentY, 0, 1.0f)) {
		point = convert(percentX, percentY, true);
		//generate mousedown
#ifdef __unix
		//linux code goes here
#endif // __unix
#ifdef _WIN32
		//windows code goes here

		mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, point[0], point[1], 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
#endif // _WIN32
		onDebug(printf("Mouse Up   @ %d, %d\n", point[0], point[1]));
		return ERR_NONE;
	}
	else {
		return ERR_OUT_OF_BOUND;
	}
}

int mouseClickAt(float x, float y) {
	int i = mouseDownAt(x, y);
	if (i) { return i; }
	i = mouseUpAt(x, y);
	if (i) { return i; }
	return ERR_NONE;
}

int touchDownAt(float percentX, float percentY) {
	if (!(initMask & INIT_MASK_TOUCH)) {
		 initTouch();
	}
	int* point = convert(percentX, percentY, false);
#ifdef _WIN32
	POINTER_TOUCH_INFO contact;
	BOOL bRet = TRUE;
	// initialize the touch info structure 
	memset(&contact, 0, sizeof(POINTER_TOUCH_INFO));

	contact.pointerInfo.pointerType = PT_TOUCH; //we're sending touch input 
	contact.pointerInfo.pointerId = 1;          //contact 0 
	contact.pointerInfo.ptPixelLocation.x = point[0];
	contact.pointerInfo.ptPixelLocation.y = point[1];
	contact.pointerInfo.pointerFlags = POINTER_FLAG_DOWN | POINTER_FLAG_INRANGE | POINTER_FLAG_INCONTACT;
	contact.touchFlags = TOUCH_FLAG_NONE;
	contact.touchMask = TOUCH_MASK_NONE;

	bRet = InjectTouchInput(1, &contact);
	// if touch down was succesfull, send a touch up 
	if (bRet) {
		onDebug(printf("Touch Down @ %d, %d\n", contact.pointerInfo.ptPixelLocation.x, contact.pointerInfo.ptPixelLocation.y));
		return ERR_NONE;
	}
	return ERR_TOUCH_FAIL;
#endif // _WIN32
}

int touchUpAt(float percentX, float percentY) {
	if (!(initMask & INIT_MASK_TOUCH)) {
		initTouch();
	}
	int* point = convert(percentX, percentY, false);

#ifdef _WIN32
	POINTER_TOUCH_INFO contact;
	BOOL bRet = TRUE;
	// initialize the touch info structure 
	memset(&contact, 0, sizeof(POINTER_TOUCH_INFO));

	contact.pointerInfo.pointerType = PT_TOUCH; //we're sending touch input 
	contact.pointerInfo.pointerId = 1;          //contact 0 
	contact.pointerInfo.ptPixelLocation.x = point[0];
	contact.pointerInfo.ptPixelLocation.y = point[1];
	contact.pointerInfo.pointerFlags = POINTER_FLAG_UP;// | POINTER_FLAG_INRANGE;
	contact.touchFlags = TOUCH_FLAG_NONE;
	contact.touchMask = TOUCH_MASK_NONE;

	bRet = InjectTouchInput(1, &contact);
	// if touch down was succesfull, send a touch up 
	if (bRet) {
		onDebug(printf("Touch Up @ %d, %d\n", contact.pointerInfo.ptPixelLocation.x, contact.pointerInfo.ptPixelLocation.y));
		return ERR_NONE;
	}
	onDebug(printf("%s\n", convertSystemError(GetLastError())));
	return ERR_TOUCH_FAIL;
#endif // _WIN32
}

int touchClickAt(float x, float y) {
	int i = touchDownAt(x, y);
	if (i) { return i; }
	i = touchUpAt(x, y);
	if (i) { return i; }
	return ERR_NONE;
}

int* convert(float x, float y, bool useWinRealitive) {
	int * point = (int*)malloc(sizeof(int));
	if (!(initMask & INIT_MASK_SCREEN)) {
		initScreen();
	}
	if (useWinRealitive) {
		point[0] = (int)(x * 65535);
		point[1] = (int)(y * 65535);
	}else{
		point[0] = (int)(x * screenWidth);
		point[1] = (int)(y * screenHeight);
	}
	return point;
}
