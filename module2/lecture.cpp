#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <iomanip>
#include <fstream>
#include <filesystem>


namespace fs = std::filesystem;

class Printable {
public:
    Printable() = default;

    Printable(const std::vector<int>& vec, const std::string& str)
        : vec_(vec), str_(str) {}

    std::string prettyPrint() const {
        std::ostringstream os;

        os << "Name: " << str_ << '\n';
        os << "Numbers: { ";
        std::copy(cbegin(vec_), cend(vec_), std::ostream_iterator<int>(os, " "));
        os << "}\n";

        return os.str();
    }

    friend std::ostream& operator<<(std::ostream& os, const Printable& p) {
        os << std::quoted(p.str_) << '\n';
        std::copy(cbegin(p.vec_), cend(p.vec_), std::ostream_iterator<int>(os, " "));
        return os << '\n';
    }

    friend std::istream& operator>>(std::istream& is, Printable& p) {
        is >> std::quoted(p.str_);
        p.vec_.clear();
        std::copy(std::istream_iterator<int>(is), {}, std::back_inserter(p.vec_));

        // Fail to read integer a number, so we need to clear errors.
        if (!is.eof()) {
            is.clear();
        }

        return is;
    }

private:
    std::vector<int> vec_;
    std::string str_;
};
void Foo(int& a) {

}
// int foobar() {

// };

int main() {
    // Printable printable;
    // std::cin >> printable;
    // std::cout << printable;
    // std::cout << printable.prettyPrint();
    //  std::fstream file("example.txt");
    // std::vector<Printable> vec;

    // // Read File
    // std::copy(std::istream_iterator<Printable>(file), {}, std::back_inserter(vec));
    // // Print Collection
    // std::copy(cbegin(vec), cend(vec), std::ostream_iterator<Printable>(std::cout));
    // int j = 0;
    // j = foobar(); // ok, foobar() is an rvalue
    // int* p2 = &foobar(); // error, cannot take the address of an rvalue
    // j = 42; // ok, 42 is an rvalue

    auto tmp_path = fs::temp_directory_path();
    std::cout << tmp_path << '\n';
}