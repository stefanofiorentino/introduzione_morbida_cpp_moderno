#include <iostream>

template<typename F, typename... Args>
void hello(F &&f, Args... args) {
    std::puts(__PRETTY_FUNCTION__);
    f(std::forward<Args>(args)...);
}

int main() {
    bool print{true};
    hello([print](std::string const &name) {
        if(print) {
            std::cout << "Hello " << name << std::endl;
        }
    }, "folks!");
    return 0;
}
