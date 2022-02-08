#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#ifndef LB5B_VECTOR_H
#define LB5B_VECTOR_H

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;

vector createVector(size_t n);

void reserve(vector *v, size_t newCapacity);

void clear(vector *v);

void shrinkToFit(vector *v);

void deleteVector(vector *v);

bool isEmpty(vector v);

bool isFull(vector v);

int getVectorValue(vector v, size_t i);

void pushBack(vector *v, int x);

void popBack(vector *v);

int* atVector(vector v, size_t index);

int* back(vector v);

int* front(vector v);

#endif
