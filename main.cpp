#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <memory>

struct base {
    base() {
        std::cout << "base ctor" << std::endl;
    }

    virtual ~base();

    virtual void hello() const {
        std::cout << "Hello, I'm base" << std::endl;
    }
};

base::~base() {
    std::cout << "base d'ctor" << std::endl;
}

struct derived : public base {
    derived() {
        std::cout << "derived ctor" << std::endl;
    }

    ~derived() override {
        std::cout << "derived d'ctor" << std::endl;
    }

    void hello() const override {
        std::cout << "Hello, I'm derived" << std::endl;
    }
};

namespace {
    void hello(std::unique_ptr<base> bp) {
        bp->hello();
    } // qui avviene la distruzione
}

int main() {
    {
        std::unique_ptr<base> bp = std::make_unique<base>();
        hello(std::move(bp)); // after this line bp is not pointing anymore to a base instance

        std::unique_ptr<derived> dp = std::make_unique<derived>();
        hello(std::move(dp));
    }
    return 0;
}
