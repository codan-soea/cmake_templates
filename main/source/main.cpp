#include <iostream>

#include "io.h"
#include "main.h"

int main() {

    std::cout << "Simple Cmake Template...." << std::endl;
    
    std::cout << "Main Module = " << MAIN_MODULE_NAME << std::endl;

    std::cout << "Lib Module  = " << LIB_MODULE_NAME << std::endl;
}
