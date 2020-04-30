#include <iostream>

template<typename F, typename... Args>
void hello(F &&f, Args... args) {
    f(std::forward<Args>(args)...);
}

int main() {
    hello([]() {
        std::cout << "Hello" << std::endl;
    });
    return 0;
}
