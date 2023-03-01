#include <iostream>

[[nodiscard]]int foo() {
    return 1;
}

struct Empty {};

struct Filed {
    int val_;
    Empty empty_;
    double val2_;
};

struct Filed2 {
    int val_;
    double val2_;
    [[no_unique_address]] Empty empty_;
};
int main() {
    int i;
    foo();
    static_assert(sizeof(Empty) >= 1);
    std::cout << "sizeof(double): " << sizeof(double) << '\n';  // 24
    std::cout << "sizeof(Empty): " << sizeof(Empty) << '\n';  // 24
    std::cout << "sizeof(Filed): " << sizeof(Filed) << '\n';  // 24
    std::cout << "sizeof(Filed): " << sizeof(Filed2) << '\n'; // 16

    return 0;
}