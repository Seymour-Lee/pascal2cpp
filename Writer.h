//
//  <文件名>：Writer.h
//  <文件内容说明>：该文件声明了一个Writer类，用于重定向输出流
//  <创建日期>：16/03/2017

#ifndef Writer_h
#define Writer_h

//包含头文件
#include <iostream>
#include <fstream>
#include <string>

//
//  <类名称>：Writer
//  <类功能说明>：该类完成向文件写入数据的功能。在类中重定向
//  输出流。
class Writer{
public:
    //单例Writer对象
    static Writer & getInstance();
        
    // 获取输出流的缓冲区指针
    std::streambuf* rdbuf() const;
    // 重定向输出流的缓冲区指针
    std::streambuf* rdbuf(std::streambuf* sb);
    
    //获取私有的输出流
    operator std::ostream&();
    
    //增加tab符号数量
    void addTabCounter();
    //减少tab符号数量
    void decTabCounter();
    //打印当前行的tab数，进行缩进
    void printTabs();  
    
private:
    Writer();//构造函数
    
    int tabCounter;//记录tab数
    
    std::ostream stream;//输出流
};


#endif /* Writer_h */

