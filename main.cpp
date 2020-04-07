#include <iostream>

struct base {
    base() {
        std::cout << "base ctor" << std::endl;
    }

    ~base() {

        std::cout << "base d'ctor" << std::endl;
    }
};

int main() {
    {
        base b; // creo un istanza dell'oggetto base chiamata b
    } // all'uscita dallo scope, la distruggo
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
