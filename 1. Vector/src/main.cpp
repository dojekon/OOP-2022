/*********************************************************
* Файл: main.cpp
* Назначение: Главная функция программы 
* 2022 SPBSTU Alexander Iliakhinsky
********************************************************/

#include <iostream>
#include <vector>
#include <chrono>
#include "./include/VectorMaster.h"

int main(int argc, char const *argv[])
{
    std::vector<int> mainVec; // Основной вектор
    VectorMaster::fillVector(mainVec, 10000, -100, 100); // Заполняем целыми случайными числами


    /*  Копируем основнйо вектор в дополнительные для чистоты эксперимента,
        при сравнивании времени выполнения сортировок                   */
    std::vector<int> sortSquareVec = mainVec;
    std::vector<int> sortAtVec = mainVec;
    std::vector<int> insertSortVec = mainVec;
    std::vector<int> sortVec = mainVec;

    // Пузырьковая сортировка с обращением через оператор []
    auto sortSquareStart = std::chrono::steady_clock::now();
    VectorMaster::sortSquare(sortSquareVec);
    auto sortSquareFinish = std::chrono::steady_clock::now();

    // Пузырьковая сортировка с обращением при помощи метода at()
    auto sortAtStart = std::chrono::steady_clock::now();
    VectorMaster::sortAt(sortAtVec);
    auto sortAtFinish = std::chrono::steady_clock::now();

    // Сортировка вставками, используя итераторы
    auto insertSortStart = std::chrono::steady_clock::now();
    VectorMaster::insertSort(insertSortVec);
    auto insertSortFinish = std::chrono::steady_clock::now();

    // STL Sort
    auto sortStart = std::chrono::steady_clock::now();
    VectorMaster::sort(sortVec);
    auto sortFinish = std::chrono::steady_clock::now();

    // Вычисление, затраченного на каждый алгоритм, времени
    auto sortSquareTime = 
    std::chrono::duration_cast<std::chrono::milliseconds>(sortSquareFinish - sortSquareStart);
    auto sortAtTime = 
    std::chrono::duration_cast<std::chrono::milliseconds>(sortAtFinish - sortAtStart);
    auto insertSortTime = 
    std::chrono::duration_cast<std::chrono::milliseconds>(insertSortFinish - insertSortStart);
    auto sortTime = 
    std::chrono::duration_cast<std::chrono::milliseconds>(sortFinish - sortStart);

    // Вывод затраченного времени
    std::cout << "sortSquare: " << sortSquareTime.count() << " ms\n";
    std::cout << "sortAt: " << sortAtTime.count() << " ms\n";
    std::cout << "insertSort: " << insertSortTime.count() << " ms\n";
    std::cout << "sort: " << sortTime.count() << " ms\n";
   
   return 0;
}
