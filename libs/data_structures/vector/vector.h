#ifndef LB5B_VECTOR_H
#define LB5B_VECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct vector {
    int *data;  // указатель на элементы вектора
    size_t size;  // размера вектора
    size_t capacity;  // выделенная память
} vector;

// Возвращает вектор размером size, в котором хранится мусор
vector createVector(size_t n);

// Резервирует память размером newCapacity для вектора v
void reserve(vector *v, size_t newCapacity);

// Удаляет элементы из контейнера, но не освобождает выделенную память в векторе v
void clear(vector *v);

// Приравнивает capacity к size в векторе v
void shrinkToFit(vector *v);

// Удаляет вектор v
void deleteVector(vector *v);

// Возвращает True, если вектор v пустой, иначе - False
bool isEmpty(vector v);

// Возвращает True, если вектор v полный, иначе - False
bool isFull(vector v);

// Возвращает значение элемента по индексу i в векторе v
int getVectorValue(vector v, size_t i);

// Добавляет в конец вектора v элемент x
void pushBack(vector *v, int x);

// Удаляет последний элемент из вектора
void popBack(vector *v);

// Возвращает адрес элемента по индексу i в векторе v
int* atVector(vector v, size_t index);

// Возвращает адрес последнего элемента в векторе v
int* back(vector v);

// Возвращает адрес первого элемента в векторе v
int* front(vector v);

#endif
