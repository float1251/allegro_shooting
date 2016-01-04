#include "alternas_s.h"

void Player_render(GameObject* g, double dt){
    if(input->up){
        g->y -= 100 * dt;
    }else if(input->down) {
        g->y += 100 * dt;
    }

    if(input->left) {
        g->x -= 100 * dt;
    } else if(input->right) {
        g->x += 100 * dt;
    }
    //printf("render\n");
    al_draw_filled_circle(g->x, g->y, 10, al_map_rgb(255, 0, 0));
}
