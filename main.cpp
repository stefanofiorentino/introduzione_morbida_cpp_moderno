#include <iostream>
#include <memory>
//struct int_list {
//    int data;
//    int_list *next;
//};
//
//struct double_list {
//    double data;
//    double_list *next;
//};

template<typename T>
struct list {
    T data;
    std::unique_ptr<list<T>> next;
};

int main() {

    auto head = std::make_unique<list<int>>();
    head->data = -3;

    auto node = std::make_unique<list<int>>();
    node->data = 42;
    head->next = std::move(node);

    for(auto it = head.get(); it != nullptr; it = it->next.get()) {
        std::cout << it->data << std::endl;
    }
    return 0;
}
