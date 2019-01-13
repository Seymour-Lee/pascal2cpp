//
//  <文件名>：Writer.cpp
//  <文件内容说明>：该文件实现了Writer类的所以成员函数
//  <创建日期>：16/03/2017

//包含头文件
#include "Writer.h"

//
//  <函数名>：Writer& Writer::getInstance()
//  <函数功能说明>：该函数用于单例化Writer类的对象，使用Writer时先调用该函数获取对象
Writer& Writer::getInstance() {
    static Writer instance;
    return instance;
}

//
//  <函数名>：std::streambuf * Writer::rdbuf() const
//  <函数功能说明>：该函数用于获取输出缓冲区指针
std::streambuf * Writer::rdbuf() const {
    return stream.rdbuf();
}

//
//  <函数名>：std::streambuf * Writer::rdbuf(std::streambuf * sb)
//  <函数功能说明>：该函数用于重定向输出流
std::streambuf * Writer::rdbuf(std::streambuf * sb) {
    return stream.rdbuf(sb);
}

//
//  <函数名>：Writer::operator std::ostream&()
//  <函数功能说明>：该函数用于返回私有的stream成员
Writer::operator std::ostream&() {
    return stream;
}

//
//  <函数名>：Writer::Writer() : stream(std::cout.rdbuf())
//  <函数功能说明>：构造函数
Writer::Writer() : stream(std::cout.rdbuf()) {
    tabCounter=0;
}

//
//  <函数名>：void Writer::addTabCounter()
//  <函数功能说明>：增加缩进数
void Writer::addTabCounter(){
    tabCounter++;
}

//
//  <函数名>：void Writer::decTabCounter()
//  <函数功能说明>：减少缩进数
void Writer::decTabCounter(){
    tabCounter--;
}

//
//  <函数名>：void Writer::printTabs()
//  <函数功能说明>：打印缩进
void Writer::printTabs(){
    std::ostream& cout=Writer::getInstance();
    for (int i=0; i<tabCounter; i++) {
        cout<<"    ";
    }
}

