 
//  <文件名>：SymbolTable.h 
//  <文件内容>：该文件包含与符号表相关的各类的定义。
//
//  <创建日期>：12/03/2017

#ifndef SymbolTable_h
#define SymbolTable_h

//  包含头文件
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stdarg.h>

//  命名空间声明
using namespace std;

//<类名>；class SymbolType
//<类功能说明>：为变量、自定义类型、函数的基类，所有的标识符都在其中保存
class SymbolType
{
private:
    string name;		//保存变量、自定义类型、函数的名字
    bool isReference; 	//保存函数参数是否为引用调用，isReference=1为引用调用
public:
    SymbolType();
    void setReference();		//设置参数为引用调用
    bool getReference(); 
    void setName(string name);
    string getName();
    virtual bool find(string name){}
    //virtual void dynamic(){}
    virtual void insert(SymbolType* type){}		//虚函数，在不同子类中有不同的作用，基本上都是向其中插入一个类型
    virtual void setPrevious(SymbolType* previous){}	
    virtual SymbolType* getPrevious(){}					
};

//<类名>；class Integer
//<类功能说明>：保存类型为int的变量
class Integer :public SymbolType
{
public :
    Integer(){}
    Integer(string name);
};

//<类名>；class Real
//<类功能说明>：保存类型为Real的变量
class Real :public SymbolType
{
public:
    Real(){}
    Real(string name);
};

//<类名>；class Char
//<类功能说明>：保存类型为Char的变量
class Char :public SymbolType
{
public:
    Char(){}
    Char(string name);
};

//<类名>；class Bool
//<类功能说明>：保存类型为Bool的变量
class Bool:public SymbolType
{
public:
    Bool(){}
    Bool(string name);
};

//<类名>；class Const
//<类功能说明>：保存Const类型的常量标识符
class Const :public SymbolType
{
private:
    SymbolType* type;	//储存通过识别判断出的Const的类型
public:
    Const();
    ~Const();
    void insert(SymbolType* type);	
    SymbolType* getType();
};

//<类名>；class Record
//<类功能说明>：保存结构体的相关信息
class Record :public SymbolType
{
private:
    vector<SymbolType*> content;	//保存结构体中的成员
    SymbolType* previous;			//指针域，在插入成员时使用，如果Record的成员构成嵌套结构，用来保存其上一级的类型指针
public:
    Record();
    Record(string name);
    ~Record();
    bool find(string name);
    void insert(SymbolType* type);	//向Record中插入成员属性
    SymbolType* getType(string name);	//返回一个名字为name的成员的类型指针
    void setPrevious(SymbolType* previous);	
    SymbolType* getPrevious();
};

//<类名>；class Array
//<类功能说明>：保存数组的相关信息
class Array :public SymbolType
{
private:
    int dimension;	//?数组维度
    vector<int> length;	//?数组每一维的长度
    vector<char> head;	//?数组头
    SymbolType* type;   //数组类型
    SymbolType* previous;	//指针域，在插入成员时使用，如果Record的成员构成嵌套结构，用来保存其上一级的类型指针
public:
    Array();
    Array(string name);
    ~Array();
    int getDim();
    void setDim(int dimension);
    void setInfo(int length, char head);    //设置数组当前维长度和头
    void insert(SymbolType* type);          //插入数组的类型
    void setPrevious(SymbolType* previous); 
    int getLength(int location);
    char getHead(int location);
    SymbolType* getPrevious();
    SymbolType* getType(){return type;}     //返回数组的类型
};

//<类名>；class Typedef
//<类功能说明>：用type定义的新类型
class Typedef :public SymbolType
{
private:
    SymbolType* type_def;   //type定义的类型的具体类型的指针，也可以是一个type
public:
    Typedef();
    Typedef(string name, SymbolType* type_def); 
    ~Typedef();
};

//<类名>；class Function
//<类功能说明>：储存函数或过程的相关信息
class Function:public SymbolType
{
private:
    vector<SymbolType*> paraList;		//参数列表
    SymbolType* retType;		//如果是函数，retType为函数的返回值，否则为null
public:
    Function(string name);
    ~Function();
    void addPara(SymbolType* para);         //向参数列表中添加一个参数
    void setRetType(SymbolType* retType);   //设置函数的返回值
    SymbolType* getRetType();               
    bool findpara(string name);             //判断参数列表中是否存在一个名字为name的参数
    int retParaNum();                       //返回参数的个数
    SymbolType* getParaType(string name);   //得到名字为name的参数的类型
    SymbolType* getParaType(int location);  //得到在参数列表中第location+1个被声明的参数的类型
};

//<类名>；class SymbolTable
//<类功能说明>：符号表，所有的标识符(包括函数和自定义类型)，都储存在这张表中
//              由于是栈式符号表，因此在查询时
class SymbolTable 
{
private:
    vector<SymbolType *> table;     //将所有的标识符储存在这个vector中，模拟栈式符号表的结构，vector的末尾即为在当前块进行插入操作
    vector<int> ptr;	            //储存在table中每一个新块开始的位置
public:
    SymbolTable();                  //初始化将0插入到ptr中，表示主块的开始
    static SymbolTable* getInstance();  //采用单例模式
    void insert(SymbolType* type);  //向符号表中插入一个新的标识符
    bool find(string name);         //在当前块中查找名字为name的标识符是否存在
    bool isParaReference(string func_name,int location);       //给出函数名和参数的声明位置，判断该参数是否为引用调用
    bool isParaReference(int func_location,string para_name);  //给出函数的声明次序，以及参数的名字，判断该参数是否为引用调用
    bool find_in_global(string name);       //在当前块和全局找名字为name的标识符是否存在
    SymbolType* getType(string name);       //返回名字为name的标识符的类型
    void reLocation();              //重定位函数
    void print();
};

#endif /* SymbolTable_h */

