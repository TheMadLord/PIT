#ifndef PIT_TOUCHOUT_H_INCLUDED
#define PIT_TOUCHOUT_H_INCLUDED
int mouseDownAt(float, float);

int mouseUpAt(float, float);

void mouseClickAt(float x, float y){
    mouseDownAt(x,y);/*wait?*/ mouseUpAt(x,y);
}

int touchDownAt(float percentX, float percentY);

int touchUpAt(float percentX, float percentY);

#endif // PIT_TOUCHOUT_H_INCLUDED
