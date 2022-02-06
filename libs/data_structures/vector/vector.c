#include "vector.h"
#include <stdbool.h>
#include <malloc.h>

void check_memory(const int *data){
    if (data == NULL){
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

vector createVector(const size_t n){
    int *data = NULL;

    if (n > 0){
        data = (int *) malloc(n * sizeof(int));

        check_memory(data);
    }

    return (vector){data, 0, n};
}

void reserve(vector *v, const size_t newCapacity){
    v->capacity = newCapacity;
    if (newCapacity < v->size)
        v->size = newCapacity;

    if (v->capacity > 0){
        v->data = (int *) realloc(v->data, newCapacity * sizeof(int));
        check_memory(v->data);
    }
    else
        v->data = NULL;
}

void clear(vector *v){
    v->size = 0;
}

void shrinkToFit(vector *v){
    reserve(v, v->size);
}

void deleteVector(vector *v){
    reserve(v, 0);
}








