#include <iostream>
#include <thread>
#include <future>
#include <string>
#include <chrono>
#include <exception>
// #include <stdexcept>

using namespace std::chrono_literals;
float foo(int a) {
    return a / 0;
}
int main() {
    std::promise<float> promise;
    std::future<float> future = promise.get_future(); 
    auto lambda = [] (std::promise<float> promise) {
        int a = 4;
        bool failed = false;
        try {
            throw std::logic_error("aaaa");
        } catch (const std::exception& ex) {
            // promise.set_exception(std::current_exception());
            promise.set_exception_at_thread_exit(std::current_exception());
            std::cout << "Here main thread still waiting for the result" << std::endl;
            failed = true;
        }
        
        promise.set_value(a / 0);
    };

    std::thread t(lambda, std::move(promise));
    try {
        std::cout << future.get() << std::endl;
    } catch (...) {}
    t.join();
    // try {
    //     float b = foo(3);
    // } catch(const std::exception& ex) {
    //     std::cout << ex.what();
    // }
}