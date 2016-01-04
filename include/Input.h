#ifndef INPUT_H
#define INPUT_H

typedef struct {
    bool up;
    bool down;
    bool left;
    bool right;
} Input;

Input* Input_new();
void Input_update(Input *i,ALLEGRO_EVENT *ev);
#endif
