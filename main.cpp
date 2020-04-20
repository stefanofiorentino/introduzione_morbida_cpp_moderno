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
        else {
            std::cout << "b_ptr is nullptr" << std::endl;
        }
    }
}

int main() {
    {
        std::shared_ptr<base> bs_ptr = std::make_unique<base>();
        std::unique_ptr<base> bu_ptr; // = std::make_shared<base>(); // does not compile!

        bs_ptr = std::move(bu_ptr);
        // bu_ptr = std::move(bs_ptr); // does not compile
    }
    return 0;
}
