#include <iostream>

template<typename F, typename... Args>
void hello(F &&f, Args... args) {
    std::puts(__PRETTY_FUNCTION__);
    f(std::forward<Args>(args)...);
}

int main() {
    bool printed{false};
    hello([&printed](std::string const &name) {
        std::cout << "Hello " << name << std::endl;
        printed = true;
    }, "folks!");
    if(printed) {
        std::cout << "printed" << std::endl;
    }
    return 0;
}
