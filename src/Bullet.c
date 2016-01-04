#include "alternas_s.h"

void PlayerBullet_render(struct GameObject* g, double dt) {
    if(g->data != NULL) {
        Vector* v = g->data;
        g->x += v->x;
        g->y += v->y;
    }
    al_draw_filled_circle(g->x, g->y, 10, al_map_rgb(255, 0, 0));
}

void PlayerBullet_delete(struct GameObject* g) {
    if(g == NULL) return;
    if(g->data != NULL) {
        free(g->data);
    }
    free(g);
}
