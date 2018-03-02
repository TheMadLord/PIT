#ifndef PIT_ERROR_H_INCLUDED
#include "pit_Debug.h"

#define PIT_ERROR_H_INCLUDED
#define ERR_NONE 0
#if isDebug
#define ERR_NOT_DEFINED_YET 1
#endif
#define ERR_OUT_OF_BOUND -1
#define ERR_FAILED_INIT -2
#define ERR_TOUCH_FAIL -3

/**
Converts an error code to descriptive string.

@param error an Error code.
@return a string that describes the error value given.
*/
char* ErrorType(int error);
char* convertSystemError(int error);
#endif // PIT_ERROR_H_INCLUDED
