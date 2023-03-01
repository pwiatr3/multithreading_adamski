#include <ranges>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

class Foo {
public:
    explicit Foo(int id)
        : id_(id) { std::cout << "C'tor id: " << id_ << '\n'; }
    ~Foo() { std::cout << "D'tor id:" << id_ << "\n"; }
    Foo(const Foo& foo) {
        id_ = foo.id_;
        std::cout << "Copy C'tor id: " << id_ << '\n';
    }
    Foo& operator=(const Foo& foo) {
        id_ = foo.id_;
        std::cout << "Copy operator= id: " << id_ << '\n';
        return *this;
    }
    Foo(Foo&& foo) noexcept {
        id_ = foo.id_;
        std::cout << "Move C'tor id: " << id_ << '\n';
    }
    Foo& operator=(Foo&& foo) noexcept {
        id_ = foo.id_;
        std::cout << "Move operator= id: " << id_ << '\n';
        return *this;
    }

private:
    friend std::ostream& operator<<(std::ostream& os, const Foo& foo) {
        return os << foo.id_;
    }

    int id_;
};

int main() {    

    // std::vector<Foo> vec;
    // std::cout << "generate!\n";
    // for (int i = 0; i < 4; ++i) {
    //     std::cout << "vec capacity: " << vec.capacity() << "-------------\n";
    //     vec.emplace_back(i);
    // }

    // std::vector<Foo> vec;
    // vec.reserve(3);

    // for (int i = 1; i < 4; ++i) {
    //     vec.emplace_back(i);
    // }

    const std::vector<int> data = {1, 2, 4, 5, 5, 6};
    // auto lower = std::lower_bound(data.begin(), data.end(), 3);
    // std::cout << *lower << '\n';
    auto lower = std::lower_bound(begin(data), end(data), 2);
    std::vector<int> v(5);
    std::iota(begin(v), end(v), 1);
    
    return 0;
}