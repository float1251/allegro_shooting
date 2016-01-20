#include "alternas_s.h"

GameObject* GameObject_new() {
    GameObject* g = malloc(sizeof(GameObject)); 
    g->x = 0;
    g->y = 0;
    g->angle = 0;
    g->angle_rate = 0;
    g->speed = 0;
    g->speed_rate = 0;
    g->alive = true;
    g->data = NULL;
    g->render = NULL;
    g->delete = NULL;
    g->onCollide = NULL;
    return g;
}

GameObject* GameObject_new_args(float x, float y, 
    float angle, float angle_rate, 
    float speed, float speed_rate, 
    void(*render)(GameObject* g, double dt), 
    void(*delete)(GameObject* g), 
    void(*onCollide)(GameObject* self, GameObject* other)
    ) {
   
    GameObject* g = GameObject_new();
    g->x = x;
    g->y = y;
    g->r = 10;
    g->type = BULLET;
    g->angle = angle;
    g->angle_rate = angle_rate;
    g->speed = speed;
    g->speed_rate = speed_rate;
    g->render = render;
    g->delete = delete;
    g->onCollide = onCollide;
    return g;
}

// g1, g2までの距離とg1のrとg2のrの足した値と比較する
bool isCollide(GameObject *g1, GameObject* g2)
{
    double length = distance(g1->x, g1->y, g2->x, g2->y);
    return length < g1->r + g2->r; 
}
