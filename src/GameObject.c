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
    return g;
}

GameObject* GameObject_new_args(float x, float y, 
    float angle, float angle_rate, 
    float speed, float speed_rate, 
    void(*render)(GameObject* g, double dt), 
    void(*delete)(GameObject* g)) {
   
    GameObject* g = GameObject_new();
    g->x = x;
    g->y = y;
    g->type = BULLET;
    g->angle = angle;
    g->angle_rate = angle_rate;
    g->speed = speed;
    g->speed_rate = speed_rate;
    g->render = render;
    g->delete = delete;
    return g;

}
