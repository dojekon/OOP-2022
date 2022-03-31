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

};

#endif