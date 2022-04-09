/*********************************************************
* Файл: VectorMaster.h
* Назначение: Инициализация методов класса 
* 2022 SPBSTU Alexander Iliakhinsky
********************************************************/

#include "./include/VectorMaster.h"


VectorMaster::VectorMaster() {

}

/**
 * @brief  Пузырьковая сортировка с использованием доступа к элементам вектора оператором []
 * @param vect Вектор цельночисленных элементов
 */
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

/**
 * @brief Пузырьковая сортировка с использованием доступа к элементам вектора оператором []
 * 
 * @param vect Вектор цельночисленных элементов
 * @param mode Переключатель режима сортировки. True - ASC, False - DESC
 */
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

/**
 * @brief Пузырьковая сортировка с использованием доступа к элементам вектора оператором at()
 * 
 * @param vect Вектор цельночисленных элементов
 */
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

/**
 * @brief Пузырьковая сортировка с использованием доступа к элементам вектора оператором at()
 * 
 * @param vect Вектор цельночисленных элементов
 * @param mode Переключатель режима сортировки. True - ASC, False - DESC
 */
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

/**
 * @brief Сортировка вставками с использщованием доступа к элементам вектора при помощи итераторов
 * 
 * @param vect Вектор цельночисленных элементов
 */
void VectorMaster::insertSort(std::vector<int> &vect) {
    int tmp;
    for (std::vector<int>::iterator i = vect.begin() + 1, j; i != vect.end(); ++i)    {
        tmp = *i;
        for (j = i - 1; j >= vect.begin() && *j > tmp; --j)
            *(j + 1) = *j;
        *(j + 1) = tmp;
    }
}

/**
 * @brief Сортировка с помоцью STL метода Sort()
 * 
 * @param vect Вектор цельночисленных элементов
 */
void VectorMaster::sort(std::vector<int> &vect) {
    std::sort(vect.begin(), vect.end());
}

/**
 * @brief Сортировка с помоцью STL метода Sort()
 * 
 * @param vect Вектор вещественных элементов двойной точности
 */
void VectorMaster::sort(std::vector<double> &vect) {
    std::sort(vect.begin(), vect.end());
}

/**
 * @brief Заполнение вектора случайными числами в диапазоне от -0.1 до 1.0
 * 
 * @param vect Вектор вещественных элементов двойной точности
 * @param size Размер вектора
 */
void VectorMaster::fillRandom(std::vector<double> &vect, int size) {
  double doubleRandMax = RAND_MAX;
  vect.clear();
  srand(time(0)); // Рандомизация.
  for (size_t i = 0; i < size; i++) {
      vect.push_back((rand() / doubleRandMax) * 2 - 1);
  }
}

/**
 * @brief Заполнение вектора целыми числами в заданном диапазоне
 * 
 * @param vec Вектор цельночисленных элементов
 * @param count Размер вектора
 * @param min Нижняя граница рандомайзера
 * @param max Верхняя граница рандомайзера
 */
void VectorMaster::fillVector(std::vector<int>& vec, const size_t count, const int min, const int max){
  vec.clear();
  srand(time(0)); // Рандомизация.
  for (size_t i = 0; i < count; i++)  {
    vec.push_back(rand() % (max - min + 1) + min); // Случайные числа из отрезка [min; max].
  }
}

/**
 * @brief Чтение из файла в массив и копирование в вектор
 * 
 * @param vect Вектор элементов символьного типа
 * @param fileName Путь до файла
 */
void VectorMaster::readFromFile(std::vector<char>& vect, std::string fileName) {
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

/**
 * @brief Чтение из стандартного потока в вектор и проведение операций из задания над элементами
 * 
 * @param vect Вектор цельночисленных элементов
 */
void VectorMaster::readInputEdit(std::vector<int>& vect) {
    vect.clear();
    while (true) {
        int input;
        std::cin >> input;
        if (input != 0) vect.push_back(input);
        else break;
    }
    if (vect.back() == 1) {
        for (std::vector<int> :: iterator it = vect.end() - 1; it >= vect.begin(); it--) { // по приколу с конца сделал 
            if (*it % 2 == 0) {
                vect.erase(it);
            } 
        }
    } else if (vect.back() == 2) {
        for (std::vector<int>::iterator i = vect.begin() + 1, j; i != vect.end(); ++i) {
            if (*i % 3 == 0) {
                vect.insert(i+1,1);
                vect.insert(i+1,1);
                vect.insert(i+1,1);
            } 
        }
    }
}