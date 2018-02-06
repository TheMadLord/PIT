#include "../inc/pit_ERROR.h"

char* ErrorType(int error){
    char* type;
    switch(error){
        case NO_ERROR:
            type = "Not an Error"; break;
        #ifdef isDebug
        case ERR_OUT_OFF_BOUNDS:
            type = "Out of Bounds Error"; break;
        #endif

        default:
            type = "Unkown Error"; break;
    }
    return type;
}
