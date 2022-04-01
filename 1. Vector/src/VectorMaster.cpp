/*********************************************************
* Файл: VectorMaster.h
* Назначение: Инициализация методов класса 
* 2022 SPBSTU Alexander Iliakhinsky
********************************************************/

#include "./include/VectorMaster.h"
#include <algorithm>
#include <string>
#include <fstream>
#include <ctime>

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

void VectorMaster::sortAt(std::vector<int> &vect) {
    for (std::size_t i = 0; i < vect.size(); i++) {
        for (std::size_t j = 0; j < vect.size(); j++) {
            if (vect.at(i) < vect.at(j)) {
                int temp = vect.at(i);
                vect.at(i) = vect.at(j);
                vect.at(j) = temp;
            }
        }
    }
}

void VectorMaster::sortAt(std::vector<int> &vect, bool mode) {
    if (mode == true) {
        for (std::size_t i = 0; i < vect.size(); i++) {
            for (std::size_t j = 0; j < vect.size(); j++) {
                if (vect.at(i) < vect.at(j)) {
                    int temp = vect.at(i);
                    vect.at(i) = vect.at(j);
                    vect.at(j) = temp;
                }
            }
        }
    } else {
        for (std::size_t i = 0; i < vect.size(); i++) {
            for (std::size_t j = 0; j < vect.size(); j++) {
                if (vect.at(i) > vect.at(j)) {
                    int temp = vect.at(i);
                    vect.at(i) = vect.at(j);
                    vect.at(j) = temp;
                }
            }
        }
    }
}

void VectorMaster::insertSort(std::vector<int> &vect) {
    int tmp;
    for (std::vector<int>::iterator i = vect.begin() + 1, j; i != vect.end(); ++i)
    {
        tmp = *i;
        for (j = i - 1; j >= vect.begin() && *j > tmp; --j)
            *(j + 1) = *j;
        *(j + 1) = tmp;
    }
}

void VectorMaster::sort(std::vector<int> &vect) {
    std::sort(vect.begin(), vect.end());
}

void VectorMaster::sort(std::vector<double> &vect) {
    std::sort(vect.begin(), vect.end());
}

void VectorMaster::fillRandom(std::vector<double> &vect, int size) {
  double doubleRandMax = RAND_MAX;
  vect.clear();
  srand(time(0)); // Рандомизация.
  for (size_t i = 0; i < size; i++) {
      vect.push_back((rand() / doubleRandMax) * 2 - 1);
  }
}

void VectorMaster::fillVector(std::vector<int>& vec, const size_t count, const int min, const int max){
  vec.clear();
  srand(time(0)); // Рандомизация.
  for (size_t i = 0; i < count; i++)  {
    vec.push_back(rand() % (max - min + 1) + min); // Случайные числа из отрезка [min; max].
  }
}

void VectorMaster::readFromFile(std::vector<char> &vect, std::string fileName) {
    std::ifstream file(fileName);
    size_t capacity = 1; 
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
    vect.clear();
    vect = std::vector<char> (data, data + size); // Копирование одной строчкой
} 