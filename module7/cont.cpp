#include <iostream>
#include<boost/context/continuation.hpp>

int main() {
    int a;
    boost::context::continuation source = boost::context::callcc(
        [&a](boost::context::continuation &&sink) {
            a = 0;
            int b = 1;
            for (;;) {
                // suspend here until we call continuation once again
                std::cout << "waiting! ";
                sink = sink.resume();
                std::cout << " woke up!\n";
                int next = a + b;
                a = b;
                b = next;
            }
            return std::move(sink);
        });
    for (int j = 0; j < 10; ++j) {
        std::cout << a << " ";
        source = source.resume();
    }
}