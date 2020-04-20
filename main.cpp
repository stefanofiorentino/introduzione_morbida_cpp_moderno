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
};

namespace {
    void hello(base *bp) { // legacy code
        bp->hello();
        delete bp; // this is missing in 80% of code, so it leaks
    }
}

int main() {
    {
        base *legacy_bp = new base; // ** PLEASE ** don't try this at work
        hello(legacy_bp);

        std::unique_ptr<base> bup = std::make_unique<base>();
        hello(bup.release()); // only for legacy code: release the ownership
    }
    return 0;
}
