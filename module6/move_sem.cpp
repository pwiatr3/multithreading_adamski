#include <iostream>

template<typename T>
class SafePtr {
public:

    SafePtr(): ptr_(nullptr) {}
    SafePtr(T* ptr): ptr_(ptr) {}
    SafePtr(const SafePtr& other): ptr_(new T(*other.ptr_)) {
        std::cout << "Copy costructor called\n";
    }
    SafePtr(SafePtr&& other): ptr_(std::move(other.ptr_)) { 
        other.ptr_ = nullptr;
        std::cout << "Move costructor called\n";
    }
    
    SafePtr& operator=(const SafePtr& other) {
        std::cout << "Copy assignment operator called\n";
        delete ptr_;
        ptr_ = new T(*other.ptr_);
        return *this;
    }
    SafePtr& operator=(SafePtr&& other) {
        std::cout << "Move assignment operator called\n";
        delete ptr_;
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;
        return *this;
    }
    ~SafePtr() {
        delete ptr_;
    }
    T* ptr_;
};
    int tab[5];
int main() {

    tab[6] = 3;
    SafePtr<int> ptr{new int(42)};
    // SafePtr<int> ptr2{ptr}; // Copy c'tor
    // SafePtr<int> ptr2 = ptr; // Copy c'tor
    // SafePtr<int> ptr2; // Copy assignment operator
    // ptr2 = ptr;
    // SafePtr<int> ptr2{std::move(ptr)}; // Move c'tor
    SafePtr<int> ptr2;
    ptr2 = std::move(ptr);

    return 0;
}