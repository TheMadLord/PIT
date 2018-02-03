#ifndef PIT_TOUCHOUT_H_INCLUDED
#define PIT_TOUCHOUT_H_INCLUDED
void mouseDownAt(float, float);

void mouseUpAt(float, float);

void mouseClickAt(float x, float y){
    mouseDownAt(x,y); mouseUpAt(x,y);
}

void touchDownAt(float percentX, float percentY);
#endif // PIT_TOUCHOUT_H_INCLUDED
