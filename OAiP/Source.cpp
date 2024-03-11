#include <iostream>
#include <vector>
#include <iomanip>
#include "Arrays.h"
using namespace std;



int main() {
    size_t size = 10;

    int* array = new int[size] { 1, 2, 3, 5, 6, 7, 10, 11, 21, 12 };

    Arrays::printArray<int>(size, array);
    Arrays arrays;
    
    Arrays::filter<int>(size, array, [](int element) {return element % 2 == 0; });
    Arrays::printArray<int>(size, array);
    return 0;
}

