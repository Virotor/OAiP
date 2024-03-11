#include "Arrays.h"
#include <iostream>



template <typename T>
void static Arrays::fillArray(size_t size, T* array, T generator())
{
    for (int i = 0; i < size; i++) {
        array[i] = generator();
    }
}

void static Arrays::printArray(size_t size, auto* array)
{
    for (int j = 0; j < size; j++) {
        std::cout << j + 1 << ": " << array[j] << std::endl;
    }
}

template<typename T>
void static Arrays::filter(size_t& size, T* array, bool filterFunc(T element))
{
    int tempCake;
    for (int i = 0; i < size; i++) {
        if (!filterFunc(array[i])) {
            Arrays::shiftLeft(size, i, array);
            size--;
            i--;
        }
    }
}


void static Arrays::shiftLeft(size_t size, size_t from, auto* array) {
    for (int i = from; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
}
