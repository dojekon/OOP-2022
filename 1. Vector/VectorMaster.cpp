#include "VectorMaster.h"

VectorMaster::VectorMaster() {

}


static void SortSquare(std::vector<int> &vect) {
    for (std::size_t i = 0; i < vect.size(); i++)    {
        for (std::size_t j = 0; j < vect.size(); j++)        {
            if (vect[i] > vect[j]) {
                int temp = vect[i];
                vect[i] = vect[j];
                vect[j] = temp;
            }
        }
    }
    
}
