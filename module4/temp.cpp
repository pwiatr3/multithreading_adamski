#include <ranges>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ranges>

int main() {    
    std::vector<int> rg1{1, 2, 3, 4};
    std::vector<int> rg2{5, 6, 7};
    std::vector<int> rg3{8, 9, 10, 11, 12, 13};
    std::vector<int> rangeOfRanges[] {rg1, rg2, rg3};

    auto jv = std::ranges::join_view(rangeOfRanges);

    for (auto& e : jv)
    {
        std::cout << e << " ";
    }    
}