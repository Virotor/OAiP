#pragma once
#include <iostream>
/**
   \brief Класс для работы с массивами
   Данный класс предоставляет шаблонный код с различными функциями для работы с массивами

  */

class Arrays {

public:
	/**
	 \brief Шаблонная функция вывода элементов массива

	 \tparam auto - любой тип, для которого определен оператор вывода в поток

	 \param [size_t] size Размер массива для вывода
	 \param [auto*] array Массив, который необходимо выввести в консоль
	 \code{cpp}

	 size_t size = 10;

	 int* array = new int[size] { 1, 2, 3, 5, 6, 7, 10, 11, 21, 12 };

	 Arrays::printArray<int>(size, array); // 1, 2, 3, 5, 6, 7, 10, 11, 21, 12

	 \endcode
	 \return ---
	*/
	void static printArray(size_t size, auto* array) {
		for (int j = 0; j < size; j++) {
			std::cout << std::setw(6) << array[j];
		}
		std::cout << std::endl;
	}

	/**
	  \brief Шаблонная функция для обхода по `array` размера `size` и удаления из `array` всех элементов,
	  для которых `filterFunc` возвращает false.

	 \tparam T - любой тип, для которого определен оператор необходимый для функции фильтрации

	 \param [size_t&] size Размер массива для вывода
	 \param [T*] array Указатель на массив, который необходимо отфильтровать
	 \param [bool] filterFunc Функция которая выполняет проверку, удовлетворяет ли элемент массива условию фильтрации

	 \code{cpp}

	 size_t size = 10;

	 int* array = new int[size] { 1, 2, 3, 5, 6, 7, 10, 11, 21, 12 };

	 Arrays::printArray<int>(size, array);
	 Arrays arrays;

	 arrays.filter<int>(size, array, [](int element) {return element % 2 == 0; });
	 Arrays::printArray<int>(size, array);
	 \endcode

	 \return ---
   */
	template<typename T>
	void  filter(size_t& size, T* array, bool (*filterFunc)(T element))
	{
		int tempCake;
		for (int i = 0; i < size; i++) {
			if (!filterFunc(array[i])) {
				this->shiftLeft(size, i, array);
				size--;
				i--;
			}
		}
	}


	/**
	  \brief Шаблонная функция для заполнения *array* размера *size* при помощи функции *generator*

	 \tparam T - любой тип, для которого определен набор функций необходимый для generator и определен оператор присваивания

	 \param [size_t&] size Размер массива для вывода
	 \param [T*] array Указатель на массив, который необходимо отфильтровать
	 \param [T] generator Функция которая генерирует новый элемент
	 \code{cpp}

	 size_t size = 10;
	 int* array = new int[size];
	 srand(time(NULL));
	 Arrays::fillArray<int>(size, array, []() {return rand() % 100 + 1; }); 
	 Arrays::printArray<int>(size, array); 

	 \endcode
	 \return ---
   */
	template <typename T>
	void static fillArray(size_t size, T* array, T(*generator)())
	{
		for (int i = 0; i < size; i++) {
			array[i] = generator();
		}
	}



	/**
	 \brief Шаблонная функция для сортировки  `array` размера `size` при помощи быстрой сортировки по функции *comparator*

	\tparam auto - любой тип

	\param [size_t] size Размер массива для сдвига
	\param [T*] array Указатель на массив, элементы которого необходимо сдвинуть
	\param [bool] comparator(T,T) Функция, по которой будет происходить упорядочивание элементов


	\code{cpp}

	 int* array = new int[10] { 1, 2, 3, 5, 6, 7, 10, 11, 21, 12 };

	 Arrays::printArray<int>(10, array);

	 Arrays arrays;

	 arrays.QuickSort<int>(array, 10, [](int left, int right) {return left < right; });
	 Arrays::printArray<int>(10, array);
	\endcode
	\return ---
  */
	template<typename T>
	void QuickSort(T* array, size_t size, bool (*comparator)(T left, T right)) {
		if (array != nullptr and size > 2) {
			QuickSortImp<T>(array, 0, size - 1, comparator);
		}
	}


private:

	template<typename T>
	int Partition(T* values, size_t l, size_t r, bool (*comparator)(T, T)) {
		T x = values[r];
		T less = l;

		for (int i = l; i < r; ++i) {
			if (comparator(values[i], x)) {
				std::swap(values[i], values[less]);
				++less;
			}
		}
		std::swap(values[less], values[r]);
		return less;
	}

	template<typename T>
	void QuickSortImp(T* array, size_t left, size_t right, bool (*comparator)(T, T)) {
		if (left < right) {
			int q = Partition(array, left, right, comparator);
			QuickSortImp(array, left, q - 1, comparator);
			QuickSortImp(array, q + 1, right, comparator);
		}
	}


	/**
	\brief Шаблонная функция для обхода по `array` размера `size` и сдвига всех элементов, который стоят справа от `from` вправо на один элемент

	\tparam auto - любой тип

	\param [size_t&] size Размер массива для сдвига
	\param [T*] array Указатель на массив, элементы которого необходимо сдвинуть
	\param [size_t] from Индекс элемента, с которого необходимо сдвинуть

	\return ---
	*/
	void  shiftLeft(size_t size, size_t from, auto* array) {
		for (int i = from; i < size - 1; i++) {
			array[i] = array[i + 1];
		}
	}

};






