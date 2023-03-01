#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <ranges>

using namespace std::chrono_literals;

int add(int lhs, int rhs) { return lhs + rhs; }

int main() {
    auto result = std::async(add, 10, 20);
    std::cout << result.get();
}