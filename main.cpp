#include <iostream>

struct base {
    base() {
        std::cout << "base ctor" << std::endl;
    }

    virtual ~base();

    virtual void hello() {
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

    void hello() override {
        std::cout << "Hello, I'm derived" << std::endl;
    }
};

namespace {
    void hello(base &b) {
        b.hello();
    }
}

int main() {
    {
        base b; // creo un istanza dell'oggetto base chiamata b
    } // all'uscita dallo scope, la distruggo
    {
        derived d; // crea un istanza dell'oggetto derived chiamando i due costruttori
    } // all'uscita dallo scope, le istrugge in ordine inverso
    {
        base b;
        b.hello();
        derived d;
        d.hello();
    }
    {
        base b;
        ::hello(b);
        derived d;
        ::hello(d);
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
