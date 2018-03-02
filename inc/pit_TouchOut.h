#ifndef PIT_TOUCHOUT_H_INCLUDED
#define PIT_TOUCHOUT_H_INCLUDED
/**
Generates a mouse down event in percent screen space.

@param x - the percent across the width of the screen to generate the mouse down.
@param y - the percent down the height of the screen to generate the mouse down.
@return an Error code, non zero is error.
*/
int mouseDownAt(float x, float y);

/**
Generates a mouse up event in percent screen space.

@param x - the percent across the width of the screen to generate the mouse down.
@param y - the percent down the height of the screen to generate the mouse down.
@return an Error code non, zero is error.
*/
int mouseUpAt(float x, float y);

/**
Generates a mouse click in percent screen space.

@param x - the percent across the width of the screen to generate the mouse down.
@param y - the percent down the height of the screen to generate the mouse down.
@return an Error code, non zero is error.
*/
int mouseClickAt(float x, float y);

/**
Generates a touch down event in percent screen space.

@param x - the percent across the width of the screen to generate the mouse down.
@param y - the percent down the height of the screen to generate the mouse down.
@return an Error code, non zero is error.
*/
int touchDownAt(float x, float y);


/**
Generates a touch down event in percent screen space, imdentialy followed by an up in the exact same place.

@param x - the percent across the width of the screen to generate the mouse down.
@param y - the percent down the height of the screen to generate the mouse down.
@return an Error code, non zero is error.
*/
int touchClickAt(float x, float y);

/**
Generates a touch up event in percent screen space.

@param x - the percent across the width of the screen to generate the mouse down.
@param y - the percent down the height of the screen to generate the mouse down.
@return an Error code non zero is error.
*/
int touchUpAt(float x, float y);

#endif // PIT_TOUCHOUT_H_INCLUDED
