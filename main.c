#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "libs/data_structures/vector/vector.h"

void test_createVector();
void test_reserve();

int main() {
    test_createVector();
    test_reserve();

    return 0;
}

void test_createVector_capacityEqualsZero(){
    size_t capacity = 0;
    vector v = createVector(capacity);

    assert(v.data == NULL);
}

void test_createVector_memoryIsAllocated(){
    size_t capacity = 100;
    vector v = createVector(capacity);

    assert(v.data != NULL);
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
}

void test_reserve_newCapacityLessSize(){
    vector v = createVector(10);
    v.size = 6;
    size_t newCapacity = 4;

    reserve(&v, newCapacity);

    assert(v.size == v.capacity);
}

void test_reserve(){
    test_reserve_newCapacityEqualsZero();
    test_reserve_newCapacityLessSize();
}
