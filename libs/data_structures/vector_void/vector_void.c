#include "vector_void.h"

#define EXIT_CODE 1

#define throwExceptionBadAlloc() fprintf(stderr, "bad alloc"); exit(EXIT_CODE)
#define throwExceptionIndexError(...) fprintf(stderr, "IndexError: a[%zu] is not exists", index); exit(EXIT_CODE)
#define throwExceptionEmptyVector() fprintf(stderr, "IndexError: a[] is an empty vector"); exit(EXIT_CODE)

// Выводит сообщение об ошибке, если ОП не может предоставить нужный объем памяти под размещение динамического массива
void check_memory(const void *data){
    if (data == NULL){
        throwExceptionBadAlloc();
    }
}

vectorVoid createVectorV(const size_t n, const size_t baseTypeSize){
    void *data = NULL;

    if (n > 0){
        data = (void *) malloc(n * baseTypeSize);

        check_memory(data);
    }

    return (vectorVoid){data, 0, n, baseTypeSize};
}

void reserveV(vectorVoid *v, const size_t newCapacity){
    v->capacity = newCapacity;
    if (newCapacity < v->size)
        v->size = newCapacity;

    if (v->capacity > 0){
        v->data = (void *) realloc(v->data, newCapacity * v->baseTypeSize);
        check_memory(v->data);
    }
    else
        v->data = NULL;
}

void shrinkToFitV(vectorVoid *v){
    reserveV(v, v->size);
}

void clearV(vectorVoid *v){
    v->size = 0;
}

void deleteVectorV(vectorVoid *v){
    free(v->data);
    v->size = 0;
    v->capacity = 0;
    v->baseTypeSize = 0;
}

bool isEmptyV(const vectorVoid v){
    return v.size == 0;
}

bool isFullV(const vectorVoid v){
    return v.size == v.capacity;
}

void getVectorValueV(const vectorVoid v, const size_t index, void *destination) {
    if (index >= v.size) {
        throwExceptionIndexError(index);
    }

    char *source = (char *) v.data + index * v.baseTypeSize;
    memcpy(destination, source, v.baseTypeSize);
}

void setVectorValueV(vectorVoid *v, const size_t index, void *source) {
    if (index >= v->capacity) {
        throwExceptionIndexError(index);
    }

    char *destination = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

// Возвращает "истину", если вектор - нулевой, иначе - "ложь"
bool isZeroVectorV(vectorVoid v){
    return v.capacity == 0;
}

void pushBackV(vectorVoid *v, void *source){
    if (isZeroVectorV(*v))
        reserveV(v, v->capacity + 1);
    else if (isFullV(*v))
        reserveV(v, v->capacity * 2);

    setVectorValueV(v, v->size++, source);
}

void popBackV(vectorVoid *v){
    if (isEmptyV(*v)){
        throwExceptionEmptyVector();
    }

    v->size--;
}