#include <cstring>
#include <iostream>

class Foo {
public:
    Foo(): data_(new char[sizeof("Hello, World!")]) {
        std::strcpy(data_, "Hello, World!");
    }

    Foo(const Foo& other) = delete;             // disable copy construction
    Foo& operator=(const Foo& other) = delete;  // disable assignment

    ~Foo(void) { delete[] data_; }

private:
    friend std::ostream& operator<<(std::ostream& os, const Foo& foo) {
        os << foo.data_;
        return os;
    }

    char* data_;
};

int main() {
    Foo foo;
    std::cout << foo << std::endl;
}
