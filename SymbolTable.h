#ifndef SymbolTable_h
#define SymbolTable_h

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stdarg.h>

using namespace std;

class SymbolType
{
private:
    string name;
    bool isReference;
public:
    SymbolType();
    void setReference();
    bool getReference(); 
    void setName(string name);
    string getName();
    virtual bool find(string name){}
    //virtual void dynamic(){}
    virtual void insert(SymbolType* type){}
    virtual void setPrevious(SymbolType* previous){}	
    virtual SymbolType* getPrevious(){}					
};

class Integer :public SymbolType
{
public :
    Integer(){}
    Integer(string name);
};

class Real :public SymbolType
{
public:
    Real(){}
    Real(string name);
};

class Char :public SymbolType
{
public:
    Char(){}
    Char(string name);
};

class Bool:public SymbolType
{
public:
    Bool(){}
    Bool(string name);
};

class Const :public SymbolType
{
private:
    SymbolType* type;
public:
    Const();
    ~Const();
    void insert(SymbolType* type);	
    SymbolType* getType();
};

class Record :public SymbolType
{
private:
    vector<SymbolType*> content;
    SymbolType* previous;
public:
    Record();
    Record(string name);
    ~Record();
    bool find(string name);
    void insert(SymbolType* type);
    SymbolType* getType(string name);
    void setPrevious(SymbolType* previous);	
    SymbolType* getPrevious();
};

class Array :public SymbolType
{
private:
    int dimension;
    vector<int> length;
    vector<char> head;
    SymbolType* type;
    SymbolType* previous;
public:
    Array();
    Array(string name);
    ~Array();
    int getDim();
    void setDim(int dimension);
    void setInfo(int length, char head);
    void insert(SymbolType* type);
    void setPrevious(SymbolType* previous); 
    int getLength(int location);
    char getHead(int location);
    SymbolType* getPrevious();
    SymbolType* getType(){return type;}
};

class Typedef :public SymbolType
{
private:
    SymbolType* type_def;
public:
    Typedef();
    Typedef(string name, SymbolType* type_def); 
    ~Typedef();
};

class Function:public SymbolType
{
private:
    vector<SymbolType*> paraList;
    SymbolType* retType;
public:
    Function(string name);
    ~Function();
    void addPara(SymbolType* para);
    void setRetType(SymbolType* retType);
    SymbolType* getRetType();               
    bool findpara(string name);
    int retParaNum();
    SymbolType* getParaType(string name);
    SymbolType* getParaType(int location);
};

class SymbolTable 
{
private:
    vector<SymbolType *> table;
    vector<int> ptr;
public:
    SymbolTable();
    static SymbolTable* getInstance();
    void insert(SymbolType* type);
    bool find(string name);
    bool isParaReference(string func_name,int location);
    bool isParaReference(int func_location,string para_name);
    bool find_in_global(string name);
    SymbolType* getType(string name);
    void reLocation();
    void print();
};

#endif /* SymbolTable_h */

