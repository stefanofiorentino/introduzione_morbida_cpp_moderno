#include <iostream>

struct base {
    base() {
        std::cout << "base ctor" << std::endl;
    }

    virtual ~base();
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
};

int main() {
    {
        base b; // creo un istanza dell'oggetto base chiamata b
    } // all'uscita dallo scope, la distruggo
    {
        derived d; // crea un istanza dell'oggetto derived chiamando i due costruttori
    } // all'uscita dallo scope, le istrugge in ordine inverso
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
