#include <iostream>
#include <vector>
#include <algorithm>

template<class T> using vector = std::vector<T>; // introduced in C++11 (modern??)

using int_vector = vector<int>; // introduced in C++11 (modern??)

int main() {
    {
        vector<int> values = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        for(auto const &v : values) {
            std::cout << v;
        }
        std::cout << std::endl;
    }
    {
        int_vector values = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        for(auto const &v : values) {
            std::cout << v;
        }
        std::cout << std::endl;
    }
    {
        int_vector values = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        int_vector target;
//        std::copy(std::rbegin(values), std::rend(values), std::back_inserter(target));
        target.assign(std::rbegin(values), std::rend(values));
        for(auto const &v : target) {
            std::cout << v;
        }
        std::cout << std::endl;
    }
    return 0;
}
