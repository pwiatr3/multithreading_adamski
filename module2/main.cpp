#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <iomanip>
#include <fstream>


class Student {
public:
    Student(): name_(""), id_(0) {}
    friend std::istream& operator>>(std::istream& is, Student& s) {
        is >> std::quoted(s.name_);
        is >> s.id_;

        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const Student& s) {
        os << s.name_ << " " << s.id_ << '\n';
        return os << '\n';
    }
private:
    std::string name_;
    size_t id_;
};
int main() {
    std::fstream file("file.txt");
    std::vector<Student> vec;

    // Read File
    std::copy(std::istream_iterator<Student>(file), {}, std::back_inserter(vec));
    // Print Collection
    std::copy(cbegin(vec), cend(vec), std::ostream_iterator<Student>(std::cout, " "));

}