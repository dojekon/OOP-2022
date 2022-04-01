/*********************************************************
* Файл: VectorMaster.h
* Назначение: Объявление методов класса VectorMaster 
* 2022 SPBSTU Alexander Iliakhinsky
********************************************************/

#ifndef VECTORMASTER_H
#define VECTORMASTER_H

#include <vector>

class VectorMaster
{
private:
    /* data */
public:
    VectorMaster();

    static void sortSquare(std::vector<int> &vect);

    static void sortSquare(std::vector<int> &vect, bool mode); // Не знаю, можео ли использовать элементы СТЛ, поэтому будет бул для переключения режимов

    static void sortAt(std::vector<int> &vect);

    static void sortAt(std::vector<int> &vect, bool mode);

    static void insertSort(std::vector<int> &vect);

    static void sort(std::vector<int> &vect); 

    static void fillRandom(std::vector<double> &vect, int size);

    static void fillVector(std::vector<int>& vec, const std::size_t count, const int min, const int max);

    static std::vector<char> readFromFile(std::vector<char> &vect);

};

#endif