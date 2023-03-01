#include <ranges>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ranges>
#include <string_view> 

template<typename T>
void print(T t) {
    std::cout << t << '\n';
}
void print(double t) {
    std::cout << std::setprecision(3) << t << '\n';
}

struct Student {
    int index_;
    std::string name_;
    double average_;
};
using namespace std::literals;

int main() {    
    auto const ints = {0, 1, 2, 3, 4, 5};
    auto even = [](int i) { return 0 == i % 2; };
    auto square = [](int i) { return i * i; };

    for (int i : ints | std::views::filter(even) | std::views::transform(square)) {
        std::cout << i << ' ';
    }
    // print(100);
    // print("ala");
    // print(1.2345);
    // float a = 123.123;
    // print(a);


    // std::vector<Student> students{{.index_ = 123456, .name_ = "Jordan", .average_ = 4.53},
    //                               {.index_ = 654321, .name_ = "Michael", .average_ = 4.51},
    //                               {.index_ = 246892, .name_ = "John", .average_ = 4.56},
    //                               {.index_ = 743561, .name_ = "Jane", .average_ = 4.44},
    //                               {.index_ = 811111, .name_ = "Anna", .average_ = 4.46}};

    // // std::sort(begin(students), end(students), [](const auto& lhs, const auto& rhs){
    // //    return lhs.average_ < rhs.average_;
    // // });
    // // container, comparator, projection

    // std::ranges::sort(students, {}, &Student::average_);
    // for (const auto& [index, name, average] : students) {
    //     std::cout << "student: " << name << " | index: " << index << " | avergae: " << average << '\n';
    // }
    // std::vector<std::pair<std::string, int>> v1 {{"ala", 1}, {"ma", 1}, {"kota", 1}};
    // decltype(v1)::value_type::second_type v2; 

   
    // for (auto s :std::views::repeat)
    std::cout << "moo\n"sv;
    std::string_view s{ "Hello, world!" }; // now a std::string_view
    std::string_view* svPtr = &s;


    return 0;
}