#include <iostream>
#include <boost/array.hpp>
#include <boost/format.hpp>
#include  <random>
#include <algorithm>
#include<boost/container/flat_set.hpp>
#include <chrono>
#include <set>

template<typename T>
void print(const std::vector<T>& v) {
    std::copy(begin(v), end(v), std::ostream_iterator<T>(std::cout, " "));
    std::cout << '\n';
}

int main() {
    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(begin(vec), end(vec), g);
    print(vec);

    boost::container::flat_set<int> flat_set;
    auto then = std::chrono::system_clock::now();
    flat_set.reserve(vec.size());
    for(const auto el : vec) {
        flat_set.insert(el);
    }
    auto now = std::chrono::system_clock::now();
    std::cout << "flat set: " << std::chrono::duration_cast<std::chrono::nanoseconds>(now - then).count() << " ns\n";

    std::set<int> set;
    then = std::chrono::high_resolution_clock::now();
    for (auto el : vec) {
        set.insert(el);
    }
    now = std::chrono::high_resolution_clock::now();
    std::cout << "std set:  " << std::chrono::duration_cast<std::chrono::nanoseconds>(now - then).count() << " ns\n";

    return 0;
}