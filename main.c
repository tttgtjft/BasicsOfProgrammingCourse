#include <assert.h>
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector_void//vector_void.h"

void test();

//тесты vector
void test_createVector();
void test_reserve();
void test_pushBack();
void test_popBack();
void test_atVector();
void test_back();
void test_front();

//тесты vectorVoid
void test_createVectorV();
void test_reserveV();
void test_pushBackV();

int main() {
    test();

    return 0;
}

//-------------------------------------TEST----------------------------------------//

void test(){
    test_createVector();
    test_reserve();
    test_pushBack();
    test_popBack();
    test_atVector();
    test_back();
    test_front();

    test_createVectorV();
    test_reserveV();
    test_pushBackV();
}

//--------------------------------VECTOR------------------------------------------//

void test_createVector_capacityEqualsZero(){
    size_t capacity = 0;
    vector v = createVector(capacity);

    assert(v.data == NULL);
    deleteVector(&v);
}

void test_createVector_memoryIsAllocated(){
    size_t capacity = 100;
    vector v = createVector(capacity);

    assert(v.data != NULL);
    deleteVector(&v);
}

void test_createVector(){
    test_createVector_capacityEqualsZero();
    test_createVector_memoryIsAllocated();
}

void test_reserve_newCapacityEqualsZero(){
    vector v = createVector(10);
    size_t newCapacity = 0;
    reserve(&v, newCapacity);

    assert(v.data == NULL);
    deleteVector(&v);
}

void test_reserve_newCapacityLessSize(){
    vector v = createVector(10);
    v.size = 6;
    size_t newCapacity = 4;

    reserve(&v, newCapacity);

    assert(v.size == v.capacity);
    deleteVector(&v);
}

void test_reserve(){
    test_reserve_newCapacityEqualsZero();
    test_reserve_newCapacityLessSize();
}

void test_pushBack_emptyVector(){
    vector v = createVector(0);

    pushBack(&v, 4);

    assert(v.data[0] == 4);
    assert(v.size == 1);
    assert(v.capacity == 1);
    deleteVector(&v);
}

void test_pushBack_fullVector(){
    vector v = createVector(2);
    v.size = 2;

    pushBack(&v, 6);

    assert(v.data[2] == 6);
    assert(v.size == 3);
    assert(v.capacity == 4);
    deleteVector(&v);
}

void test_pushBack_notFullVector(){
    vector v = createVector(4);
    v.size = 2;

    pushBack(&v, 5);

    assert(v.data[2] == 5);
    assert(v.size == 3);
    assert(v.capacity == 4);
    deleteVector(&v);
}

void test_pushBack(){
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_pushBack_notFullVector();
}

void test_popBack_notEmptyVector(){
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);

    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
    deleteVector(&v);
}

void test_popBack(){
    test_popBack_notEmptyVector();
}

void test_atVector_notEmptyVector(){
    vector v = {(int []){1, 3, 4}, 3, 5};

    assert(*atVector(v, 1) == 3);
}

void test_atVector_requestToLastElement(){
    vector v = {(int []){1, 3, 4}, 3, 5};

    assert(*atVector(v, v.size - 1) == 4);
}

void test_atVector(){
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
}

void test_back_oneElementInVector(){
    vector v = {(int []){5}, 1, 1};

    assert(*back(v) == 5);
}

void test_back(){
    test_back_oneElementInVector();
}

void test_front_oneElementInVector(){
    vector v = {(int []){5}, 1, 1};

    assert(*front(v) == 5);
}

void test_front(){
    test_front_oneElementInVector();
}

//--------------------------------VECTOR VOID-----------------------------------------//

/*void test_createVectorV_SIZE_MAX(){
    vectorVoid v = createVectorV(SIZE_MAX, 4); `exit code 1 ~ "bad alloc"`
}*/

void test_createVectorV_capacityEqualsZero(){
    size_t capacity = 0;
    vectorVoid v = createVectorV(capacity, 4);

    assert(v.data == NULL);
    deleteVectorV(&v);
}

void test_createVectorV_memoryIsAllocated(){
    size_t capacity = 100;
    vectorVoid v = createVectorV(capacity, 4);

    assert(v.data != NULL);
    deleteVectorV(&v);
}

void test_createVectorV(){
    test_createVectorV_capacityEqualsZero();
    test_createVectorV_memoryIsAllocated();
}

void test_reserveV_newCapacityEqualsZero(){
    vectorVoid v = createVectorV(10, 2);
    size_t newCapacity = 0;
    reserveV(&v, newCapacity);

    assert(v.data == NULL);
    deleteVectorV(&v);
}

void test_reserveV_newCapacityLessSize(){
    vectorVoid v = createVectorV(10, 1);
    v.size = 6;
    size_t newCapacity = 4;

    reserveV(&v, newCapacity);

    assert(v.size == v.capacity);
    deleteVectorV(&v);
}

void test_reserveV(){
    test_reserveV_newCapacityEqualsZero();
    test_reserveV_newCapacityLessSize();
}

void test_pushBackV_Int(){
    size_t n;
    scanf("%zu", &n);

    vectorVoid v = createVectorV(0, sizeof(int));
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);

        pushBackV(&v, &x);
    }

    for (int i = 0; i < n; ++i) {
        int x;
        getVectorValueV(v, i, &x);

        printf("%d ", x);
    }
}

void test_pushBackV_Float(){
    size_t n;
    scanf("%zu", &n);

    vectorVoid v = createVectorV(0, sizeof(float));
    for (int i = 0; i < n; ++i) {
        float x;
        scanf("%f", &x);

        pushBackV(&v, &x);
    }

    for (int i = 0; i < n; ++i) {
        float x;
        getVectorValueV(v, i, &x);

        printf("%f ", x);
    }
}

void test_pushBackV(){
    test_pushBackV_Int();
    test_pushBackV_Float();
}
