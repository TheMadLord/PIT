#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDED
#define isDebug 0
#ifdef isDebug
    #define onDebug(stmt) stmt
#else
    #define onDebug(stmt)
#endif

#endif // DEBUG_H_INCLUDED
