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
    double length = sqrt(v->x*v->x+v->y*v->y);
    out->x = v->x/length;
    out->y = v->y/length;
}

double Vector_distance(Vector* v1, Vector* v2){
    double x = v2->x - v1->x;
    double y = v2->y - v1->y;
    return sqrt(x*x+y*y);
}

double distance(double x1, double y1, double x2, double y2){
    double x = x2 - x1;
    double y = y2 - y1;
    return sqrt(x*x+y*y);
}
