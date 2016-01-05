#include "alternas_s.h"

Input* Input_new() {
    Input* i = malloc(sizeof(Input));
    i->up = false;
    i->down = false;
    i->left = false;
    i->right = false;
    return i;
}

void Input_update(Input* i, ALLEGRO_EVENT *ev) {
    if(ev->type == ALLEGRO_EVENT_KEY_DOWN) {
        switch(ev->keyboard.keycode){
            case ALLEGRO_KEY_UP:
                i->up = true;
                break;
            case ALLEGRO_KEY_DOWN:
                i->down = true;
                break;
            case ALLEGRO_KEY_LEFT:
                i->left = true;
                break;
            case ALLEGRO_KEY_RIGHT:
                i->right = true;
                break;
        }
    } else if(ev->type == ALLEGRO_EVENT_KEY_UP){
        switch(ev->keyboard.keycode){
            case ALLEGRO_KEY_UP:
                i->up = false;
                break;
            case ALLEGRO_KEY_DOWN:
                i->down = false;
                break;
            case ALLEGRO_KEY_LEFT:
                i->left = false;
                break;
            case ALLEGRO_KEY_RIGHT:
                i->right = false;
                break;
        }
    }
}
