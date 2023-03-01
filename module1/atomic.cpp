#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <ranges>



int main() {
    std::vector<int> toBeSummed;
    for(int i = 0; i < 30000; i++) {
        toBeSummed.push_back(rand());
    }

    long sum = 0;
    for(int i = 0; i < toBeSummed.size(); i++) {
        sum += toBeSummed[i];
    }

    printf("The sum was %ld\n", sum);
}