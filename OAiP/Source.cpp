#include <iostream>
#include <vector>
#include <iomanip>
#include "Arrays.h"
using namespace std;



int main() {
	size_t size = 10;
	int* array = new int[size];
	srand(time(NULL));
	Arrays::fillArray<int>(size, array, []() {return rand() % 5 + 1; });
	Arrays::printArray<int>(size, array);
	Arrays arrays;
	std::cout << "Array is polyndrom = " << arrays.isPolyndrom(size, array);
	return 0;
}

