#include <algorithm>
#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <ranges>

using namespace std::chrono_literals;

enum Status {   failure = 0,
                success = 1
            };

void downloadPackages(std::promise<bool>&& ready) {
    // std::this_thread::sleep_for(2000ms);
    try {
        ready.set_value(Status::success);
    } catch(...) {
        ready.set_exception(std::current_exception());
    }
}
void downloadAssets(std::promise<bool>&& ready) { ready.set_value(Status::success); }
void setGeolocation(std::promise<bool>&& ready) { ready.set_value(Status::success); }
void setSystemSettings(std::promise<bool>&& ready) { ready.set_value(Status::success); }

int main() {
    constexpr size_t taskNum = 4;
    constexpr std::array tasks = {downloadPackages, downloadAssets, setGeolocation, setSystemSettings};
    std::vector<std::future<bool>> isReady(taskNum);
    std::vector<std::jthread> threads;

    for(size_t i = 0; i < taskNum; i++) {
        std::promise<bool> ready;
        isReady.emplace_back(ready.get_future());
        threads.emplace_back(tasks[i], std::move(ready));
    }
    
    std::cout << "Installing...\n";

    if(!std::ranges::all_of(isReady, [](auto& future){ return future.get(); }))
    return 0;
}
