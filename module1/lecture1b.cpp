#include <algorithm>
#include <cmath>
#include <future>
#include <iostream>
#include <ranges>
#include <mutex>
#include <thread>
#include <vector>
#include <numeric>

using namespace std::chrono_literals;

std::mutex mtx {};

enum Status {   failure = 0,
                success = 1
            };

float median(std::vector<int> v) {
    std::sort(begin(v), end(v));
    float middle_elem = v.size() / 2.0;
    // check if length of the vector is odd number
    if(v.size() % 2 != 0) {      
        return (v[floor(middle_elem)] + v[ceil(middle_elem)]) / 2.0;
    }
    else {
        return v[middle_elem];
    }
}

void average(const std::shared_future<std::vector<int>>& dataAvailable) {
    const auto data = dataAvailable.get();
    float average = std::accumulate(begin(data), end(data), 0) / static_cast<float>(data.size());
    std::lock_guard lock(mtx);
    std::cout << "Average = " << average << '\n';
}

void median(const std::shared_future<std::vector<int>>& dataAvailable) { 
    auto data = dataAvailable.get();
    std::lock_guard lock(mtx);
    std::cout << "Median = " << median(data) << '\n';
}

void chart(const std::shared_future<std::vector<int>>& dataAvailable) {
    const auto data = dataAvailable.get();
    std::lock_guard lock(mtx);
    std::cout << "Draw chart!\n"; 
}

void save(const std::shared_future<std::vector<int>>& dataAvailable) {
    const auto data = dataAvailable.get();
    std::lock_guard lock(mtx);
    std::cout << "Data saved!\n"; 
}


int main() {
    std::cout << "Start\n";
    constexpr size_t taskNum = 4;
    constexpr std::array<void(*)(const std::shared_future<std::vector<int>>& dataAvailable), 4> tasks = {average, median, chart, save};
    std::promise<std::vector<int>> setData;
    std::shared_future<std::vector<int>> future = setData.get_future();
    std::vector<std::thread> threads;

    for(size_t i = 0; i < taskNum; i++) {
        threads.emplace_back(tasks[i], future);
    }
    
    std::this_thread::sleep_for(3s);
    std::cout << "Set value\n";
    setData.set_value({1, 2, 3, 4, 7});
    // Join threads
    for(size_t i = 0; i < taskNum; i++) {
        threads[i].join();
    }
    return 0;
}
