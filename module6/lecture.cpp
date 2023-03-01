#include <iostream>

struct Student {
    // auto operator<=>(const Student& other) const = default;
    std::partial_ordering operator<=>(const Student& other) const {
         if (const auto res = average_ <=> other.average_; res != 0) {
            return res;
        }
        return name_ <=> other.name_;    
    }

    std::string name_;
    double average_;
    int index_;
};

int main() {
    int val1(1234);
    int val2(12345);
    auto res = val1 <=> val2;
    if (res < 0) 
        std::cout << "val1 < val2" << std::endl;
    else if (res == 0) 
        std::cout << "val1 == val2" << std::endl;
    else if (res > 0) 
        std::cout << "val1 > val2" << std::endl;
    // Student student1{.name_ = "Mateusz", .average_ = 4.67, .index_ = 456123};
    // Student student2{.name_ = "Mateusz", .average_ = 4.67, .index_ = 123456};
    // Student student3{.name_ = "Mateusz", .average_ = 4.57, .index_ = 321456};

    // std::cout << "student1 > student2 ? " << (student1 > student2) << '\n';    // T (higher index)
    // std::cout << "student1 < student3 ? " << (student1 < student3) << '\n';    // F (lower average)
    // This line do not compile :(
    // std::cout << "student1 == student1 ? " << (student1 == student1) << '\n';  // T (the same person)
    return 0;
}