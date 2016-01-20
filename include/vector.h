#ifndef VECTOR_H
#define VECTOR_H

typedef struct{
    double x;
    double y;
} Vector;

Vector* Vector_new();
void Vector_delete(Vector* v);

void Vector_normalize(Vector* v, Vector* out);
double Vector_distance(Vector* v1, Vector* v2);
double distance(double x1, double y1, double x2, double y2);
#endif
