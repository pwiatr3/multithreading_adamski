#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <iomanip>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

int main() {
    string file = "ala.txt";
    std::ifstream file_stream(file);  // Open your input file
    // char ch = 'a';
    ostream_iterator<char> cout_it(cout, " ");
    fs::path dir_path(fs::current_path());
    string file_name = "lecture.cpp";

    // copy(istream_iterator<char>(file_stream), {}, ostream_iterator<char>(std::cout, ""));
    // copy(istream_iterator<char>(file_stream), istream_iterator<char>(), cout_it);
    // cout << count_if(istream_iterator<char>(file_stream), {},[](char ch){ return ch == 'a'; }) << endl;

    // Counts files with .cpp extension
    // cout << count_if(fs::directory_iterator(dir_path), {},[](const fs::directory_entry& entry){ 
    //     return entry.is_regular_file() && entry.path().extension() == ".cpp";
    // }) << endl;
    
    // Prints all file names within current directory
    // transform(fs::directory_iterator(dir_path), {}, ostream_iterator<string>(cout, " "), [](const fs::directory_entry& entry){ 
    //     return entry.path().stem();
    // });

    // Prints size of file of the name filename
    const auto it = find_if(fs::directory_iterator(dir_path), {}, [file_name](const fs::directory_entry& entry){
        auto current_path = fs::path(fs::current_path().append(file_name));
        cout << entry.path() << endl;
        return entry.path() == current_path;
    });

    cout << "File " << file_name << " size is: " << it->file_size() << endl;
}
