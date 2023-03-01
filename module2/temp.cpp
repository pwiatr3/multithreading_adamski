#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>

class Student {

    friend std::ostream& operator<<(std::ostream& os, const Student& s) {
        os << "Student: " << s.name_ << " id: " << s.id_;

        return os;
    }
    friend std::istream& operator>>(std::istream& is, Student& s) {
        is >> s.name_;
        is >> s.id_;

        return is;
    }

private:
    std::string name_;
    size_t id_;
};
int main() {
    std::fstream file("file.txt");
    std::vector<Student> vec;
    std::copy(std::istream_iterator<Student>(file), {}, std::back_insert_iterator<std::vector<Student>>(vec));
    std::copy(begin(vec), end(vec), std::ostream_iterator<Student>(std::cout, "\n"));
    return 0;       
}