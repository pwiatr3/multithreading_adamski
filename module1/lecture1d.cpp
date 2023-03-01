#include <iostream>
#include <thread>
#include <future>
#include <chrono>

using namespace std::chrono_literals;


int main() {
    std::promise<std::string> promise;
    std::future<std::string> future = promise.get_future();
    auto lambda = [] (std::promise<std::string> promise) {
        std::this_thread::sleep_for(5s);
        promise.set_value("Ala has a cat");
    };

    std::thread t(lambda, std::move(promise));

    std::future_status status;
    do {
        switch(status = future.wait_for(1500ms); status) {
            case std::future_status::deferred: 
                std::cout << "Task may never be executed!" << std::endl;
                return 0;
            case std::future_status::timeout:
                std::cout << "Still waiting for an answer, do another job" << std::endl;
                // doSthElse();
                break;
            case std::future_status::ready:
                std::cout << "Result is: " << future.get() << std::endl;
        }
    } while (status != std::future_status::ready);

    return 0;

}
