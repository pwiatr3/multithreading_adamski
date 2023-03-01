#include <iostream>

auto postponeTask(auto&& fun, auto&&... args) {
    return [f = std::move(fun), ... pack = std::move(args)]() {
        return f(pack...);
    };
}
int main() {

    auto task = postponeTask([](const std::string& str, int num) {
        std::cout << str << " | " << num << '\n';
    }, std::string("Ala ma kota"), 42);

    task();
    return 0;
}