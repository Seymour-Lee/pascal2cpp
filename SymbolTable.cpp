 
//  <文件名>：SymbolTable.cpp 
//  <文件内容>：该文件包含与符号表相关的各类的实现。
//
//  <创建日期>：12/03/2017

//  包含头文件
#include "SymbolTable.h"

//  <函数名>：SymbolType::SymbolType()
//  <函数功能说明>：构造函数。
SymbolType::SymbolType()
{
	this->isReference=0;
}

//  <函数名>：void SymbolType::setReference()
//  <函数功能说明>：设置参数为引用调用
void SymbolType::setReference()
{
	this->isReference=1;
}

//  <函数名>：bool SymbolType::getReference()
//  <函数功能说明>：得到某参数为引用调用还是传值调用
bool SymbolType::getReference()
{
	return this->isReference;
}

//  <函数名>：void SymbolType::setName(string name)
//  <函数功能说明>：设置该标识符的名字
void SymbolType::setName(string name)
{
    this->name = name;
}

//  <函数名>：string SymbolType::getName()
//  <函数功能说明>：得到该标识符的名字
string SymbolType::getName()
{
    return name;
}

//  <函数名>：Integer::Integer(string name)
//  <函数功能说明>：构造函数
Integer::Integer(string name)
{
    setName(name);
}

//  <函数名>：Real::Real(string name)
//  <函数功能说明>：构造函数
Real::Real(string name)
{
    setName(name);
}

//  <函数名>：Char::Char(string name)
//  <函数功能说明>：构造函数
Char::Char(string name)
{
    setName(name);
}

//  <函数名>：Bool::Bool(string name)
//  <函数功能说明>：构造函数
Bool::Bool(string name)
{
    setName(name);
}

//  <函数名>：Const::Const()
//  <函数功能说明>：构造函数
Const::Const()
{
	this->type==NULL;
}

//  <函数名>：Const::~Const()
//  <函数功能说明>：析构函数，删除指向Const具体类型的指针
Const::~Const()
{
	delete this->type;
}

//  <函数名>：void Const::insert(SymbolType* type)
//  <函数功能说明>：将遍历语法树分析得到的类型赋给Const
void Const::insert(SymbolType* type)
{
    this->type = type;
}

//  <函数名>：SymbolType* Const::getType()
//  <函数功能说明>：得到Const的具体类型
SymbolType* Const::getType()
{
	return this->type;
}

//  <函数名>：Record::Record()
//  <函数功能说明>：构造函数
Record::Record()
{
	this->previous=NULL;
}

//  <函数名>：Record::Record(string name)
//  <函数功能说明>：构造函数
Record::Record(string name)
{
	this->previous=NULL;
    setName(name);
}

//  <函数名>：Record::~Record()
//  <函数功能说明>：析构函数，删除指向Record的成员的指针，如果成员中存在Record和array
//	等嵌套结构，删除指向其父节点的指针previous
Record::~Record()
{
    if (!content.empty())
    {
    	for (int i = 0;i<content.size();i++)
        {
            delete content.at(i);
        }
	}
	if(previous!=NULL)
		delete previous;
}

//  <函数名>：void Record::insert(SymbolType* type)
//  <函数功能说明>：向Record中插入一个成员
void Record::insert(SymbolType* type)
{
    content.push_back(type);
}

//  <函数名>：SymbolType* Record::getType(string name)
//  <函数功能说明>：从Record中得到名字为name的成员的类型指针
SymbolType* Record::getType(string name)
{
    for (int i = 0;i<content.size();i++)
    {
        if (content.at(i)->getName() == name)
            return content.at(i);
    }
    return NULL;
}

//  <函数名>：void Record::setPrevious(SymbolType* previous)
//  <函数功能说明>：如果Record中含有嵌套的复杂属性结构，如record和
//	array，则需要记录其父节点，也就是他们所在的Record的指针，用来回溯
void Record::setPrevious(SymbolType* previous)
{
    this->previous = previous;
}

//  <函数名>：SymbolType* Record::getPrevious()
//  <函数功能说明>：得到某一属性值的父节点
SymbolType* Record::getPrevious()
{
    return previous;
}

bool Record::find(string name)
{
	for(int i=0;i<content.size();i++)
	{
		if(content.at(i)->getName()==name)
			return true;
		
	}
	return false;
}

//  <函数名>：Array::Array()
//  <函数功能说明>：构造函数。
Array::Array()
{
	this->previous=NULL;
	this->type=NULL;
}

//  <函数名>：Array::Array(string name)
//  <函数功能说明>：构造函数
Array::Array(string name)
{
	this->previous=NULL;
	this->type=NULL;
    setName(name);
    dimension = 0;
}

//  <函数名>：Array::~Array()
//  <函数功能说明>：析构函数，删除可能存在的父节点指针
//	以及该array的类型指针
Array::~Array()
{
	if(previous!=NULL)
		delete previous;
	if(type!=NULL)
   	 	delete type;
   
}

//  <函数名>：int Array::getDim()
//  <函数功能说明>：得到数组的维度
int Array::getDim()
{
    return dimension;
}

//  <函数名>：void Array::setDim(int dimension)
//  <函数功能说明>：设置数组的维度
void Array::setDim(int dimension)
{
    this->dimension = dimension;
}

//  <函数名>：void Array::setInfo(int length, char head)
//  <函数功能说明>：设置数组当前维长度和头
void Array::setInfo(int length, char head)
{
    this->length.push_back(length);
    this->head.push_back(head);
}

//  <函数名>：void Array::insert(SymbolType* type)
//  <函数功能说明>：插入数组的类型

void Array::insert(SymbolType* type)
{
    this->type = type;
}

//  <函数名>：void Array::setPrevious(SymbolType* previous)
//  <函数功能说明>：与Record相似，当遇到嵌套类型时，记录其父节点
void Array::setPrevious(SymbolType* previous)
{
    this->previous = previous;
}

//  <函数名>：void Array::getHead(int location)
//  <函数功能说明>：返回数组每一维的首元素 
char Array::getHead(int location)
{
	return this->head.at(location);
}

//  <函数名>：void Array::getLength(int location)
//  <函数功能说明>：返回数组每一维的长度 
int Array::getLength(int location)
{
	return this->length.at(location);   
}


//  <函数名>：SymbolType* Array::getPrevious()
//  <函数功能说明>：得到嵌套类型的父节点
SymbolType* Array::getPrevious()
{
    return previous;
}

//  <函数名>：Typedef::Typedef()
//  <函数功能说明>：构造函数
Typedef::Typedef()
{
	this->type_def=NULL;
}

//  <函数名>：Typedef::Typedef(string name, SymbolType* type_def)
//  <函数功能说明>：设置type定义的类型的名字，以及其定义的类型，该类型
//	可以为除Function以外的任意类型
Typedef::Typedef(string name, SymbolType* type_def)
{
    setName(name);
    this->type_def = type_def;
}

//  <函数名>：Typedef::~Typedef()
//  <函数功能说明>：析构函数
Typedef::~Typedef()
{
    delete type_def;
}

//  <函数名>：Function::Function(string name)
//  <函数功能说明>：构造函数
Function::Function(string name)
{
    this->setName(name);
    retType = NULL;
}

//  <函数名>：Function::~Function()
//  <函数功能说明>：析构函数，删除函数或过程可能有的所有参数
//	对于函数，删除其返回值
Function::~Function()
{
    if (!paraList.empty())
    {
        for (int i = 0;i < paraList.size();i++)
        {
            delete paraList.at(i);
        }
    }
    if (retType != NULL)
    {
        delete retType;
    }
}

//  <函数名>：void Function::addPara(SymbolType* para)
//  <函数功能说明>：向该函数中添加一个参数
void Function::addPara(SymbolType* para)
{
    if (para == NULL)
        return;
    paraList.push_back(para);
}

//  <函数名>：void Function::setRetType(SymbolType* retType)
//  <函数功能说明>：设置函数的返回值
void Function::setRetType(SymbolType* retType)
{
    if (retType == NULL)
        return;
    this->retType = retType;
}

//  <函数名>：SymbolType* Function::getRetType()
//  <函数功能说明>：得到函数的返回值
SymbolType* Function::getRetType()
{
    return retType;
}

//  <函数名>：bool Function::findpara(string name)
//  <函数功能说明>：判断参数列表中是否存在一个名字为name的参数
bool Function::findpara(string name)
{
    if (paraList.empty())
        return false;
    for (int i = 0;i < paraList.size() ;i++)
    {
        if (paraList.at(i)->getName() == name)
            return true;
    }
    return false;
}

//  <函数名>：int Function::retParaNum()
//  <函数功能说明>：返回参数的个数
int Function::retParaNum()
{
	if(!paraList.empty())
    	return paraList.size();
}

//  <函数名>：SymbolType* Function::getParaType(string name)
//  <函数功能说明>：得到名字为name的参数的类型
SymbolType* Function::getParaType(string name)
{
    if (paraList.empty())
        return NULL;
    for (int i = 0;i < paraList.size();i++)
    {
        if (paraList.at(i)->getName() == name)
            return paraList.at(i);
    }
    return NULL;
}

//  <函数名>：SymbolType* Function::getParaType(int location)
//  <函数功能说明>：得到在参数列表中第location+1个被声明的参数的类型
SymbolType* Function::getParaType(int location)
{
    if (paraList.empty())
        return NULL;
    return paraList.at(location);
}

//  <函数名>：SymbolTable::SymbolTable()
//  <函数功能说明>：构造函数，将主函数的开始位置设为0，插入到指向
//	块开始位置的ptr中
SymbolTable::SymbolTable()
{
    ptr.push_back(0);
}

//  <函数名>：SymbolTable* SymbolTable::getInstance()
//  <函数功能说明>：单例模式，返回SymbolTable* 类型的指针以调用函数
SymbolTable* SymbolTable::getInstance()
{
    static SymbolTable* symbolTable = new SymbolTable();
    return symbolTable;
}

//  <函数名>：void SymbolTable::insert(SymbolType* type)
//  <函数功能说明>：向符号表中插入一个类型为type的标识符，
void SymbolTable::insert(SymbolType* type)
{
    table.push_back(type);
    if (dynamic_cast<Function *>(type)!=NULL)
        ptr.push_back(table.size() - 1);
}

//  <函数名>：bool SymbolTable::find(string name)
//  <函数功能说明>：在当前块中查找名字为name的变量是否存在
//	如果在子块中，函数的参数也要查找，
bool SymbolTable::find(string name)
{
	if(table.size()==0)
		return false;
    for (int i = table.size() - 1;i >= ptr.at(ptr.size()-1);i--)
    {
        if (name == table.at(i)->getName())
            return true;
        //
        if (i == ptr.at(ptr.size()-1)&& i != 0)
        {
            Function* temp = dynamic_cast<Function*>(table.at(i));
            if (temp->findpara(name))
                return true;
        }
        
    }
    return false;
}

//  <函数名>：bool SymbolTable::isParaReference(string func_name,int location)
//  <函数功能说明>：判断在名字为func_name，参数声明位置为location+1的参数是否为
//	引用调用
bool SymbolTable::isParaReference(string func_name,int location)
{
	
	for(int i=ptr.size()-1;i>0;i--)
	{
		
		if(table.at(ptr.at(i))->getName()==func_name)
		{
			Function* temp=dynamic_cast<Function*>(table.at(ptr.at(i)));
			return temp->getParaType(location)->getReference();
		} 
	}
	return false;
}

//  <函数名>：bool SymbolTable::isParaReference(int func_location,string para_name)
//  <函数功能说明>：判断第func_location个声明的函数中，名字为para_name的变量是否
//	为引用调用
bool SymbolTable::isParaReference(int func_location,string para_name)
{
	if(func_location<=0||func_location>ptr.size()-1)
		return false;
	
	Function* temp=dynamic_cast<Function*>(table.at(ptr.at(func_location)));
	
	if(temp->getParaType(para_name)!=NULL)
		return temp->getParaType(para_name)->getReference();
	return false;
}

//  <函数名>：bool SymbolTable::find_in_global(string name)
//  <函数功能说明>：在全局以及当前块中查找名字为name的标识符是否存在
//	在这里由于打印语句需要查找符号表，因此没有进行重定位操作，所以在
//	这里查找表的范围不再是全表查找，而是首先判断当前表是否为空，然后
//	判断当前表是否小于两个块，如果是的话，就进行全表查找，否则就查找
//	当前块以及第一个子块和主块之间的部分
bool SymbolTable::find_in_global(string name)
{
	if(table.size()==0)
		return false;
	if(ptr.size()<=2)
	{
		for (int i = (table.size() - 1);i >= 0;i--)
	    {
	        if (name == table.at(i)->getName())
	        {
	        	
	        	return true;
	        }
	            
	        //?áπ?∑√??μΩ?à∫???μ??∑,aπ“?∑√??∫???μ?≤????–±ì
	        if (i == ptr.at(ptr.size()-1) && i != 0)
	        {
	        	
	            Function* temp = dynamic_cast<Function*>(table.at(i));
	            if (temp->findpara(name))
	                return true;
	        	
	        }
	       
    	}
     	return false;
	}
	else
	{
		for(int i=table.size()-1;i>=ptr.at(ptr.size()-1);i--)
		{
			if (name==table.at(i)->getName())
	        	return true;
		}
		for (int i = (ptr.at(1));i >= 0;i--)
	    {
	        if (name == table.at(i)->getName())
	            return true;    
    	}
     	return false;
	}
	return false;
}

//  <函数名>：SymbolType* SymbolTable::getType(string name)
//  <函数功能说明>：返回名字为name的标识符类型，由于在返回类型之前
//	一定要进行查找操作，因此，名为name的标识符一定存在，
//	同样，由于没有进行重定位操作，因此查找表的方法也要发生变化，和
//	find_in_globalI()大致相同，不再赘述
SymbolType* SymbolTable::getType(string name)
{ 
	if(table.size()==0)
		return NULL;
	if(ptr.size()<=2)
	{
		for (int i = (table.size() - 1);i >= 0;i--)
	    {
	        if (name == table.at(i)->getName())
	            return table.at(i);
	        if (i == ptr.at(ptr.size()-1)&&i!=0)
	        {
	            Function* temp = dynamic_cast<Function*>(table.at(i));
	            if (temp->findpara(name))
	                return temp->getParaType(name);
	        }
	        
	    }
	}
    else
    {
    	for (int i = (table.size() - 1);i >= ptr.at(ptr.size()-1);i--)
	    {
	        if (name == table.at(i)->getName())
	            return table.at(i);
	        if (i == ptr.at(ptr.size()-1)&&i!=0)
	        {
	            Function* temp = dynamic_cast<Function*>(table.at(i));
	            if (temp->findpara(name))
	                return temp->getParaType(name);
	        }   
	    }
	    for(int i = (ptr.at(1));i>=0;i--)
	    {
	    	if (name == table.at(i)->getName())
	            return table.at(i);
	        if (i == ptr.at(ptr.size()-1)&&i!=0)
	        {
	            Function* temp = dynamic_cast<Function*>(table.at(i));
	            if (temp->findpara(name))
	                return temp->getParaType(name);
	        }   
	    }
    }
    return NULL;
}

//  <函数名>：void SymbolTable::reLocation()
//  <函数功能说明>：对函数进行重定位，删除当前块中的所有指针
//	但是由于打印代码的时候需要用到所有块中的信息，因此没有调用

void SymbolTable::print()
{
	for(int i=0;i<table.size();i++)
	{
		cout<<table.at(i)->getName()<<endl;
	}
}

void SymbolTable::reLocation()
{/*
    int pos = ptr.at(ptr.size()-1);
    for (int i = (table.size() - 1);i > pos;i--)
        delete table.at(i);*/
}


