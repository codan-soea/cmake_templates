#include <fstream>
#include <string>

std::string get_data() {
    std::ifstream ifs("resources/hello.txt");
    using It = std::istreambuf_iterator<char>;
    return std::string(It(ifs), It());
}
