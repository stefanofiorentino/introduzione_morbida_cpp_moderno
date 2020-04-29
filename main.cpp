#include <iostream>
#include <memory>

template<typename Implementer>
struct Interface
{
    void hello()
    {
        static_cast<Implementer *>(this)->helloImpl();
    }
};

struct Hello : public Interface<Hello>
{
    void helloImpl() {
        std::cout << "Hello" << std::endl;
    }
};

struct NotDerivedFromInterface{};

int main() {
    std::make_unique<Hello>()->hello();
    static_assert(std::is_base_of_v<Interface<Hello>, Hello>, "");
    static_assert(!std::is_base_of_v<Interface<NotDerivedFromInterface>, NotDerivedFromInterface>, "");

    return 0;
}
