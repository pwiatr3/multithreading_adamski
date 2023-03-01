#include  <iostream>

int& foo() {
    int x = 3;
    return x;
}
int main() {
    std::cout << foo;
    return 0;
}