//
//  <文件名>：Controller.h
//  <文件内容>：该文件声明了一个Controller的类，用于控制编译过程
//  <创建日期>：06/03/2017

#ifndef Controller_h
#define Controller_h

//  包含头文件
#include "AbstractSyntaxTree.h"
#include "SymbolTable.h"

//  <类名称>：Controller
//  <类功能声明>：该类用于控制编译进程，在main函数中实例化该类，并
//  调用相关接口。
class Controller{
public:
    Controller();//构造函数
    ~Controller();//析构函数
    
    void parsing(const char * fileName);//词法和语法分析
    void typeChecking();//语义分析
    void codeGeneration(const char * fileName);//代码生成
    
private:
    //SymbolTable * symbolTable;
    
    Program * astRoot;//AST root node
    
};

#endif /* Controller_h */

