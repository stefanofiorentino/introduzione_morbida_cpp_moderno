#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <memory>

struct base {
    base() {
        std::cout << "base ctor" << std::endl;
    }

    void hello() const {
        std::cout << "Hello, I'm base" << std::endl;
    }

    ~base() {
        std::cout << "base d'ctor" << std::endl;
    }
};

namespace {
    void hello(base *bp) { // legacy code
        bp->hello();
        // delete bp; // in this case you should not delete
    }

    void hello(std::weak_ptr<base> weak_base) {
        if(auto b_ptr = weak_base.lock()) { // doesn't lock
            b_ptr->hello();
        }
    }
}

int main() {
    {
        std::shared_ptr<base> b_ptr = std::make_shared<base>();
        ::hello(b_ptr.get());
        ::hello(b_ptr);
    }
    return 0;
}
