// C++ program to illustrate time point
// and system clock functions
#include <iostream>
#include <chrono>
#include <ctime>
#include <format>

using namespace std::literals::chrono_literals;
// Function to calculate
// Fibonacci series
long fibonacci(unsigned n)
{
	if (n < 2) return n;
	return fibonacci(n-1) + fibonacci(n-2);
}
void blink(std::chrono::milliseconds time) {
    std::cout << time.count() << '\n';
}
int main()
{
	// Using time point and system_clock
	// std::chrono::time_point<std::chrono::system_clock> start, end;

	// start = std::chrono::system_clock::now();
	// std::cout << "f(42) = " << fibonacci(42) << '\n';
	// end = std::chrono::system_clock::now();

	// std::chrono::duration<double> elapsed_seconds = end - start;
	// std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	// std::cout << "finished computation at " << std::ctime(&end_time)
	// 		<< "elapsed time: " << elapsed_seconds.count() << "s\n";

    auto now = std::chrono::system_clock::now();
	std
    // auto time = std::chrono::system_clock::to_time_t(now);
    // std::cout << "Time: " << std::ctime(&time) << '\n';
    // blink(1ms);

}
