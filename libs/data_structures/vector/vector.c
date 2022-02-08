#include "vector.h"

#define EXIT_CODE 1

#define throwExceptionBadAlloc() fprintf(stderr, "bad alloc"); exit(EXIT_CODE)
#define throwExceptionIndexError(...) fprintf(stderr, "IndexError: a[%zu] is not exists", index); exit(EXIT_CODE)
#define throwExceptionEmptyVector() fprintf(stderr, "IndexError: a[] is an empty vector"); exit(EXIT_CODE)

// Выводит сообщение об ошибке, если ОП не может предоставить нужный объем памяти под размещение динамического массива
void check_memoryVoid(const int *data){
    if (data == NULL){
        throwExceptionBadAlloc();
    }
}

vector createVector(const size_t n){
    int *data = NULL;

    if (n > 0){
        data = (int *) malloc(n * sizeof(int));

        check_memoryVoid(data);
    }

    return (vector){data, 0, n};
}

void reserve(vector *v, const size_t newCapacity){
    v->capacity = newCapacity;
    if (newCapacity < v->size)
        v->size = newCapacity;

    if (v->capacity > 0){
        v->data = (int *) realloc(v->data, newCapacity * sizeof(int));
        check_memoryVoid(v->data);
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
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}

bool isEmpty(const vector v){
    return v.size == 0;
}

bool isFull(const vector v){
    return v.size == v.capacity;
}

int getVectorValue(const vector v, const size_t index){
    if (index >= v.size){
        throwExceptionIndexError(index);
    }

    return v.data[index];
}

// Возвращает "истину", если вектор - нулевой, иначе - "ложь"
bool isZeroVector(vector v){
    return v.capacity == 0;
}

void pushBack(vector *v, const int x){
    if (isZeroVector(*v)){
        reserve(v, v->capacity + 1);
        v->data[v->size++] = x;
    }
    else if (isFull(*v)){
        reserve(v, v->capacity * 2);
        v->data[v->size++] = x;
    }
    else
        v->data[v->size++] = x;
}

void popBack(vector *v){
    if (isEmpty(*v)){
        throwExceptionEmptyVector();
    }

    v->size--;
}

int* atVector(const vector v, const size_t index){
    if (index >= v.size){
        throwExceptionIndexError(index);
    }

    return &v.data[index];
}

int* back(const vector v){
    if (isEmpty(v)){
        throwExceptionEmptyVector();
    }

    return &v.data[v.size - 1];
}

int* front(const vector v){
    if (isEmpty(v)){
        throwExceptionEmptyVector();
    }

    return &v.data[0];
}











