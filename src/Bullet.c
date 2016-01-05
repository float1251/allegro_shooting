#include "alternas_s.h"

void Bullet_render(struct GameObject* g, double dt) {
    // 角度をラジアンに変換する
    double rad = g->angle * M_PI * 2;

    // 角度と速度を使って座標を更新する
    g->x += g->speed * cos(rad);
    g->y += g->speed * sin(rad);

    // 角度に角速度を加算する
    g->angle += g->angle_rate;

    // 速度に加速度を加算する
    g->speed += g->speed_rate;

    // TODO 画面外に出たら削除する
    if(g->x< 0 || g->x>SCREEN_W || g->y<0 || g->y>SCREEN_H) {
        g->alive = false; 
    } 

    al_draw_filled_circle(g->x, g->y, 10, al_map_rgb(255, 0, 0));
}

void Bullet_delete(GameObject* g) {
    if(g == NULL) return;
    if(g->data != NULL) {
        free(g->data);
    }
    free(g);
}
