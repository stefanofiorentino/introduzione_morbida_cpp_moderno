#include <iostream>
#include <memory>
#include <future>

// Scott Meyers

template<typename F, typename... Ts>
inline auto reallyAsync(F &&f, Ts &&... params) {
    return std::async(std::launch::async, std::forward<F>(f), std::forward<Ts>(params)...);
}

int main() {
    auto printed = std::make_unique<bool>(false);
    auto ra = reallyAsync([&printed](std::string const &name) {
        std::cout << "Hello " << name << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        *printed = true;
    }, "folks!");
    printed.reset(nullptr);
    return 0;
}
