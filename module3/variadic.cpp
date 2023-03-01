#include <ranges>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

template<typename T>
void print(T t) {
    cout << t << '\n';
}

template<typename T, typename... Args>
void print(T t, Args... args) {
    cout << t << " ";
    print(args...);
}

int main() {
    print(1, 2, 3.14, "ala");
} 