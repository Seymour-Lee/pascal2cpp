#include <iostream>
#include <fstream>

#include "Controller.h"

int main(int argc, const char * argv[]) {
    std::string filepath;
    
    if (argc > 1) {
        ifstream fin(argv[1]);
        if (!fin) {
            std::cout<<"Invalid File Path"<<std::endl;
            std::cout<<"Program terminate."<<std::endl;
            return 1;
        }
        else{
            fin.close();
        }
    }
    
    
    Controller * controller = new Controller;
    
    controller->parsing(argv[1]);

    controller->typeChecking();
    
    controller->codeGeneration(argv[1]);
    
    delete controller;
    
    return 0;
}

