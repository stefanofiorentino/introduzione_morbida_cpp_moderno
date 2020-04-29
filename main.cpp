#include <iostream>

//double abs(double x) {
//    return (x >= 0) ? x : -x;
//}
//
//int abs(int x) {
//    return (x >= 0) ? x : -x;
//}

template<typename T>
T abs(T x) {
    return (x >= 0) ? x : -x;
}

int main() {
    std::cout << abs(-3.) << std::endl;
    std::cout << abs(-30) << std::endl;

    double (*dabsd)(double) = abs<double>;
    std::cout << dabsd(-3.) << std::endl;
    std::cout << abs<int>(-3) << std::endl;

    static_assert(std::is_same_v<double, decltype(abs<double>(-3))>, "");
    static_assert(std::is_same_v<int, decltype(abs<int>(-3.))>, "");

    return 0;
}
