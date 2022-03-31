/*********************************************************
* Файл: VectorMaster.h
* Назначение: Инициализация методов класса 
* 2022 SPBSTU Alexander Iliakhinsky
********************************************************/

#include "VectorMaster.h"

VectorMaster::VectorMaster() {

}

void VectorMaster::sortSquare(std::vector<int> &vect) {
    for (std::size_t i = 0; i < vect.size(); i++) {
        for (std::size_t j = 0; j < vect.size(); j++) {
            if (vect[i] < vect[j]) {
                int temp = vect[i];
                vect[i] = vect[j];
                vect[j] = temp;
            }
        }
    }
}

void VectorMaster::sortSquare(std::vector<int> &vect, bool mode) {
    if (mode == true) {
            for (std::size_t i = 0; i < vect.size(); i++) {
        for (std::size_t j = 0; j < vect.size(); j++) {
            if (vect[i] < vect[j]) {
                int temp = vect[i];
                vect[i] = vect[j];
                vect[j] = temp;
            }
        }
    }
    } else {
            for (std::size_t i = 0; i < vect.size(); i++) {
        for (std::size_t j = 0; j < vect.size(); j++) {
            if (vect[i] > vect[j]) {
                int temp = vect[i];
                vect[i] = vect[j];
                vect[j] = temp;
            }
        }
    }
    } 
    
}
