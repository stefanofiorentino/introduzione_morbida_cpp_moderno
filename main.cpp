#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define _USE_MATH_DEFINES
#include <cmath>

using float_vector = std::vector<float>;

int main() {
    {
        constexpr auto N = 101; // since C++11
        constexpr auto step = M_PI / (N-1);

        float_vector target;
        target.reserve(N); // size=0, capacity=N

        for(auto it = 0; it < N; ++it) {
            target.emplace_back(it*step);
        }
        std::for_each(std::begin(target), std::end(target), [](decltype(target)::value_type &v) { // decltype: since C++11
            v = std::sin(v);
        });

        auto sum = std::accumulate(std::begin(target), std::end(target), 0.f) / N;
        std::cout << sum << std::endl;
    }
    return 0;
}
