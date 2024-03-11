#include <iostream>
#include <vector>
#include <iomanip>
#include "Arrays.h"
using namespace std;



int main() {
	size_t size = 10;
	int* array = new int[size];
	srand(time(NULL));
	Arrays::fillArray<int>(size, array, []() {return rand() % 100 + 1; }); 
	Arrays::printArray<int>(size, array); 
	return 0;
}

