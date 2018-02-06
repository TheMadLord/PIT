#ifndef PIT_ERROR_H_INCLUDED
#include "pit_Debug.h"

#define PIT_ERROR_H_INCLUDED
#define NO_ERROR 1
#ifdef isDebug
#define NOT_DEFINED_YET 0
#endif
#define ERR_OUT_OFF_BOUNDS -1

char* ErrorType(int error);
#endif // PIT_ERROR_H_INCLUDED
