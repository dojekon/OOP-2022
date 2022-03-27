#include <iostream>
#include <vector>
#include "VectorMaster.h"

int main(int argc, char const *argv[])
{
    std::vector<int> vec{ 1,5,2,7,3,4,9,8,6 };

    VectorMaster::SortSquare(vec, true);       

    for (std::vector<int>::iterator it = vec.begin() ; it!=vec.end() ; ++it)
        std::cout<<*it;
    return 0;
}
