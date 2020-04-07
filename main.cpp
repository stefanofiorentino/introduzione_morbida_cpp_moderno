#include <iostream>
#include <string>

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
    {
        using string = std::string;

        string s;

        s = "I'm a string";
        std::cout << s << std::endl;

        s += ".";
        std::cout << s << std::endl;
        std::cout << s.capacity() << std::endl;
        std::cout << s.size() << std::endl;
        std::cout << std::endl;

        s.shrink_to_fit();
        std::cout << s.capacity() << std::endl;
        std::cout << std::endl;

        s += s;
        std::cout << s.capacity() << std::endl;
        std::cout << s.size() << std::endl;
        std::cout << std::endl;

        s.shrink_to_fit();  // introduced in C++11 (modern??)
        std::cout << s.capacity() << std::endl;
        std::cout << s.size() << std::endl;
        std::cout << std::endl;

        string a = "I'm another string"; // string creation
        a += "."; // string manipulation
        for(auto it = 0u; it < 15u; it++) {
            a += a; // appending allthings
        }
        std::cout << a.capacity() << std::endl; // capacity is twice the size (!!)
        std::cout << a.size() << std::endl;
        std::cout << std::endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
