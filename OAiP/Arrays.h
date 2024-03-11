#pragma once

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

     \return ---
    */
    void static printArray(size_t size, auto* array);
    
    /**
      \brief Шаблонная функция для обхода по `array` размера `size` и удаления из `array` всех элементов,
      для которых `filterFunc` возвращает false.
   
     \tparam T - любой тип, для которого определен оператор необходимый для функции фильтрации

     \param [size_t&] size Размер массива для вывода
     \param [T*] array Указатель на массив, который необходимо отфильтровать
     \param [bool] filterFunc Функция которая выполняет проверку, удовлетворяет ли элемент массива условию фильтрации
     
     \return ---
   */
    template<typename T>
    void static filter(size_t& size, T* array, bool filterFunc(T element));


    /**
      \brief Шаблонная функция для заполнения *array* размера *size* при помощи функции *generator*

     \tparam T - любой тип, для которого определен набор функций необходимый для generator и определен оператор присваивания 

     \param [size_t&] size Размер массива для вывода
     \param [T*] array Указатель на массив, который необходимо отфильтровать
     \param [T] generator Функция которая генерирует новый элемент

     \return ---
   */
    template <typename T>
    void static fillArray(size_t size, T* array, T generator());

    /**
      \brief Шаблонная функция для обхода по `array` размера `size` и сдвига всех элементов, который стоят справа от `from` вправо на один элемент

     \tparam auto - любой тип

     \param [size_t&] size Размер массива для сдвига
     \param [T*] array Указатель на массив, элементы которого необходимо сдвинуть
     \param [size_t] from Индекс элемента, с которого необходимо сдвинуть

     \return ---
   */
    void static shiftLeft(size_t size, size_t from, auto* array);
};






