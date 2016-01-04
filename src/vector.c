#include "alternas_s.h"
Vector* Vector_new() {
    Vector* v = malloc(sizeof(Vector));
    v->x = 0;
    v->y = 0;
    return v;
}
void Vector_delete(Vector* v) {
    if(v != NULL){
        free(v);
    }
}

void Vector_normalize(Vector* v, Vector* out) {
    double length = sqrt(v->x+v->x+v->y*v->y);
    out->x = v->x/length;
    out->y = v->y/length;
}
