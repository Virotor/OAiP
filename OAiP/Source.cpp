#include <iostream>
#include <vector>
#include <iomanip>
#include "Arrays.h"
using namespace std;

//int Partition(vector<int>& values, int l, int r) {
//	int x = values[r];
//	int less = l;
//
//	for (int i = l; i < r; ++i) {
//		if (values[i] <= x) {
//			swap(values[i], values[less]);
//			++less;
//		}
//	}
//	swap(values[less], values[r]);
//	return less;
//}
//
//void QuickSortImpl(vector<int>& values, int l, int r) {
//	if (l < r) {
//		int q = Partition(values, l, r);
//		QuickSortImpl(values, l, q - 1);
//		QuickSortImpl(values, q + 1, r);
//	}
//}
//
//
//void QuickSort(vector<int>& values) {
//	if (!values.empty()) {
//		QuickSortImpl(values, 0, values.size() - 1);
//	}
//}
//
//
//template<typename T>
//int Partition(T* values, int l, int r, bool (*comparator)(T, T)) {
//	int x = values[r];
//	int less = l;
//
//	for (int i = l; i < r; ++i) {
//		if (comparator(values[i],x)) {
//			swap(values[i], values[less]);
//			++less;
//		}
//	}
//	swap(values[less], values[r]);
//	return less;
//}
//
//template<typename T>
//void QuickSortImp(T* array, size_t left, size_t right, bool comparator(T, T)) {
//	if (left < right) {
//		int q = Partition(array, left, right, comparator);
//		QuickSortImp(array, left, q - 1, comparator);
//		QuickSortImp(array, q + 1, right, comparator);
//	}
//}
//
//template<typename T>
//void QuickSort(T* array, size_t size, bool (*comparator)(T,T) ) {
//	if (array !=nullptr and size > 2) {9
//		QuickSortImp<T>(array, 0, size-1, comparator);
//	}
//}
//
//
//void PrintArray(int* array, size_t size) {
//	for (int i = 0; i < size; i++) {
//		cout << setw(5) << array[i];
//	}
//	cout << endl;
//}
//



int main() {

	vector<int> temp{ 1,2,3,45,46,12,23,543,123,435,123,543 };




	int arrayDesc[] = { 1,2,3,45,46,12,23,543,123,435,123,543 };
	int arrayAsc[] = { 1,2,3,45,46,12,23,543,123,435,123,543 };
	auto asc = [](auto left, auto right) {return left >= right; };
	auto desc = [](auto left, auto right) {return !(left >= right); };

	return 0;
}