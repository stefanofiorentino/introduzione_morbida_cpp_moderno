#include <iostream>

// Arthur O'Dwyer

template<typename T, typename... Us>
void f(Us... us) {
    std::puts(__PRETTY_FUNCTION__);
}

int main() {
    f<char>(0, 1, 2);
    f<char, char>(0, 1, 2);
    f<char, char>(0, 1, 2, 4, 5, 6, 7);
    return 0;
}
