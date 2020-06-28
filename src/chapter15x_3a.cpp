// Copyright 2020 Magellan
#include <iostream>
#include <memory>

class Resource {
 public:
    Resource() {
        std::cout << "Resource acquired" << std::endl;
    }

    ~Resource() {
        std::cout << "Resource destroyed" << std::endl;
    }
};

int main() {
    // Change the below lines.
    // Resource *res = new Resource;
    // std::shared_ptr<Resource> ptr1(res);
    // std::shared_ptr<Resource> ptr2(res);
    std::shared_ptr<Resource> ptr1{ std::make_unique<Resource>() };
    std::shared_ptr<Resource> ptr2{ ptr1 };

    return (0);
}
