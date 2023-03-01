#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <vector>
#include <iomanip>
#include <algorithm>

class Auto {
    friend std::ostream& operator<<(std::ostream& os, const Auto& a) {
        os <<  a.year_ << " " << a.make_ << " " << a.model_ << " " << a.description_ << " " << a.price_ << "\n";

        return os;
    }
    friend std::istream& operator>>(std::istream& is, Auto& a) {
        is  >> a.year_
            >> std::quoted(a.make_, ',')
            >> std::quoted(a.model_, ',','"')
            >> std::quoted(a.description_, ',')
            >> a.price_;

        return is;
    }

private:
    size_t year_;
    std::string make_;
    std::string model_;
    std::string description_;
    float price_;
};
int main() {
    std::fstream file("autos.csv");
    std::vector<Auto> vec;
    std::copy(std::istream_iterator<Auto>(file), {}, std::back_insert_iterator<std::vector<Auto>>(vec));
    std::copy(begin(vec), end(vec), std::ostream_iterator<Auto>(std::cout, "\n"));
    return 0;       
}