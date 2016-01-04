#ifndef VECTOR_H
#define VECTOR_H

typedef struct{
    double x;
    double y;
} Vector;

Vector* Vector_new();
void Vector_delete(Vector* v);

void Vector_normalize(Vector* v, Vector* out);
#endif
