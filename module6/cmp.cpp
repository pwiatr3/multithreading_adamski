#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <initializer_list>

struct Student {
    auto operator<=>(const Student& other) const {
        return average_ <=> other.average_;
    }
    auto operator==(const Student& other) const {
        return average_ == other.average_;
    }
    std::string name_;
    double average_;
    int index_;
};
class MyVec {
public:
    MyVec();
    MyVec(std::initializer_list<int> init): v_(init) {}
    auto operator<=>(const MyVec& other) const {
        return std::accumulate(begin(v_), end(v_), 0) <=> std::accumulate(begin(other.v_), end(other.v_), 0);
    }
    std::vector<int> v_;
};
int main() {
    // Student student1{.name_ = "Mateusz", .average_ = 4.60, .index_ = 456123};
    // Student student2{.name_ = "Mateusz", .average_ = 4.67, .index_ = 123456};
    // Student student3{.name_ = "Mateusz", .average_ = 4.57, .index_ = 321456};

    // std::cout << "student1 > student2 ? " << (student1 > student2) << '\n';    // T (higher index)
    // std::cout << "student1 < student3 ? " << (student1 < student3) << '\n';    // F (lower average)
    // // This line do not compile :(
    // std::cout << "student1 == student2 ? " << (student1 == student2) << '\n';  // T (the same person)
    MyVec v = {1, 2, 2};
    MyVec v1 = {3, 2, 1};
    std::cout << (v > v1) << '\n';
    return 0;
}