/*********************************************************
* Файл: main.cpp
* Назначение: Главная функция программы 
* 2022 SPBSTU Alexander Iliakhinsky
********************************************************/

#include <chrono>
#include "./include/VectorMaster.h"

int main(int argc, char const *argv[])
{
    std::vector<int> mainVec; // Основной вектор
    VectorMaster::fillVector(mainVec, 10000, -100, 100); // Заполняем целыми случайными числами

    /*  Копируем основной вектор в дополнительные для чистоты эксперимента,
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

    std::cout << "• Написание алгоритмов сортировки с различным вариациями доступа к элементам вектора" << std::endl << "На выполнение алгоримов затрачено:" << std::endl;
    // Вывод затраченного времени
    std::cout << "sortSquare: " << sortSquareTime.count() << " ms\n";
    std::cout << "sortAt: " << sortAtTime.count() << " ms\n";
    std::cout << "insertSort: " << insertSortTime.count() << " ms\n";
    std::cout << "sort: " << sortTime.count() << " ms\n";

    std::cout << std::endl << "• Чтение из файла в массив и копирование в вектор: " << std::endl;
    std::vector<char> charVector;
    VectorMaster::readFromFile(charVector, "../input/input.txt");
    // Вывод содержимого
    for (std::vector<char>::iterator it = charVector.begin() ; it!=charVector.end() ; ++it)
        std::cout<<*it;
    std::cout << std::endl;
    
    // TODO: Пятое задание
    std::cout << std::endl << "• Пятое задание" << std::endl;
    std::vector<int> five;
    VectorMaster::readInputEdit(five);
    for (size_t i = 0; i < five.size(); i++)    {
        std::cout << five[i] << " "; 
    }
    


    std::cout << std::endl << "• Функция заполнения вектора случайными числами от -1.0 до 1.0";

    std::vector<double> doubleVec;
    std::vector<int> sizeVec{5,10,25,50,100};

    for (auto size : sizeVec) {
         std::cout << std::endl;
        std::cout << "Размер: " << size << std::endl;
        VectorMaster::fillRandom(doubleVec, size);
        VectorMaster::sort(doubleVec);
        // Вывод содержимого
        std::cout << std::endl;
        for (std::vector<double>::iterator it = doubleVec.begin() ; it!=doubleVec.end() ; ++it)
            std::cout<<*it<<" ";
        std::cout << std::endl;
    }



   return 0;
}
