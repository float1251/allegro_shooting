#include "alternas_s.h"

GameObject* GameObject_new() {
    GameObject* g = malloc(sizeof(GameObject)); 
    g->x = 0;
    g->y = 0;
    g->render = NULL;
    g->delete = NULL;
    return g;
}
