//
//  <文件名>：main.cpp
//  <文件内容>：该文件包含main函数，为整个程序的入口。
//
//  <创建日期>：06/03/2017

//包含头文件
#include <iostream>
#include <fstream>

#include "Controller.h"

//
//  <函数名>：int main(int argc, const char * argv[])
//  <函数功能说明>：该函数为程序的入口。函数中new出Controller对象，
//  调用成员变量开启编译。
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
    
    controller->parsing(argv[1]);//开启编译，进行词法和语法分析

    controller->typeChecking();//进行语义分析
    
    controller->codeGeneration(argv[1]);//代码生成
    
    delete controller;
    
    return 0;
}

