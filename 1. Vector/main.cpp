/*********************************************************
* Файл: main.cpp
* Назначение: Главная функция программы 
* 2022 SPBSTU Alexander Iliakhinsky
********************************************************/

#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <fstream>
#include "VectorMaster.h"

int main(int argc, char const *argv[])
{
    std::vector<int> vec{ 1,5,2,7,3,4,9,8,6 };

    VectorMaster::insertSort(vec);

    for (std::vector<int>::iterator it = vec.begin() ; it!=vec.end() ; ++it)
        std::cout<<*it<<" ";


    std::vector<int> mainVec;
    VectorMaster::fillVector(mainVec, 10000, -100, 100);

    std::vector<int> sortSquareVec = mainVec;
    std::vector<int> sortAtVec = mainVec;
    std::vector<int> insertSortVec = mainVec;
    std::vector<int> sortVec = mainVec;

    auto sortSquareStart = std::chrono::steady_clock::now();
    VectorMaster::sortSquare(sortSquareVec);
    auto sortSquareFinish = std::chrono::steady_clock::now();

    auto sortAtStart = std::chrono::steady_clock::now();
    VectorMaster::sortAt(sortAtVec);
    auto sortAtFinish = std::chrono::steady_clock::now();

    auto insertSortStart = std::chrono::steady_clock::now();
    VectorMaster::insertSort(insertSortVec);
    auto insertSortFinish = std::chrono::steady_clock::now();

    auto sortStart = std::chrono::steady_clock::now();
    VectorMaster::sort(sortVec);
    auto sortFinish = std::chrono::steady_clock::now();

    auto sortSquareTime = 
    std::chrono::duration_cast<std::chrono::milliseconds>(sortSquareFinish - sortSquareStart);
    auto sortAtTime = 
    std::chrono::duration_cast<std::chrono::milliseconds>(sortAtFinish - sortAtStart);
    auto insertSortTime = 
    std::chrono::duration_cast<std::chrono::milliseconds>(insertSortFinish - insertSortStart);
    auto sortTime = 
    std::chrono::duration_cast<std::chrono::milliseconds>(sortFinish - sortStart);

    std::cout << "sortSquare: " << sortSquareTime.count() << "ms\n";
    std::cout << "sortAt: " << sortAtTime.count() << "ms\n";
    std::cout << "insertSort: " << insertSortTime.count() << "ms\n";
    std::cout << "sort: " << sortTime.count() << "ms\n";

    std::string fileName = "input.txt";
    std::ifstream file(fileName);
    size_t capacity = 1; // 
    size_t size = 0;
    char* data = new char[capacity];

    while (file) {
        file.read(data + size, capacity - size);
        size += file.gcount();
        if (size == capacity) {
            capacity *= 2;
            char* temp = new char[capacity];
            std::move(data, data + size, temp);
            data = std::move(temp);
        }
    }

    file.close();
    std::vector<char> charVec(data, data + size);
    for (size_t i = 0; i < size; i++) {
        std::cout << charVec[i] << " ";
    }
    std::cout << "\n";

    
   
   
   return 0;
}
