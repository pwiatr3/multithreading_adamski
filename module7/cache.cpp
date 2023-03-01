#include <iostream>
#include <optional>
#include <ranges>
#include<boost/circular_buffer.hpp>

struct Image { 
    std::string name_; 
    friend std::ostream& operator<<(std::ostream& os, const Image& img) {
        os << img.name_;
        return os;
    }
};

class Downloader {
public:
    std::optional<Image> download(const std::string& name) {
        if (const auto it = std::ranges::find(cache_, name, &Image::name_) ; it != cache_.end()) {
            return *it;
        }
        std::cout << "Download new image: " << name << '\n';
        cache_.push_back(Image{name});

        return cache_.back();
    }
    void print_cbuffer() {
        std::cout << "cache_ = { ";
        // auto it = begin(cache_);
        // std::cout << *it <<" ";
        for(auto it = begin(cache_); it!= end(cache_); it++) {
            std::cout << *it <<" ";
        }
        std::cout << " }\n";
    }
private:
    boost::circular_buffer<Image> cache_{5};
};

int main() {
    boost::circular_buffer<int> cb(3);
    
    Downloader downloader;
    for (int i = 0 ; i < 5 ; ++i) {
        downloader.download(std::string("image") + std::to_string(i));
    }
    downloader.print_cbuffer();
    std::cout << std::string(30, '-') << '\n';
    for (int i = 0 ; i < 7 ; ++i) {
        downloader.download(std::string("image") + std::to_string(i));
    }
    downloader.print_cbuffer();
    std::cout << std::string(30, '-') << '\n';
    // Worst scenarion we start downloading from image1 and override image 2
    // then image2 need bo downloaded once agian and override image3 and so one
    for (int i = 1 ; i < 7 ; ++i) {
        downloader.download(std::string("image") + std::to_string(i));
    }
    downloader.print_cbuffer();
}