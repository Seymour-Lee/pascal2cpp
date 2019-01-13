#include "SymbolTable.h"

SymbolType::SymbolType()
{
	this->isReference=0;
}

void SymbolType::setReference()
{
	this->isReference=1;
}

bool SymbolType::getReference()
{
	return this->isReference;
}

void SymbolType::setName(string name)
{
    this->name = name;
}

string SymbolType::getName()
{
    return name;
}

Integer::Integer(string name)
{
    setName(name);
}

Real::Real(string name)
{
    setName(name);
}

Char::Char(string name)
{
    setName(name);
}

Bool::Bool(string name)
{
    setName(name);
}

Const::Const()
{
	this->type==NULL;
}

Const::~Const()
{
	delete this->type;
}

void Const::insert(SymbolType* type)
{
    this->type = type;
}

SymbolType* Const::getType()
{
	return this->type;
}

Record::Record()
{
	this->previous=NULL;
}

Record::Record(string name)
{
	this->previous=NULL;
    setName(name);
}

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

void Record::insert(SymbolType* type)
{
    content.push_back(type);
}

SymbolType* Record::getType(string name)
{
    for (int i = 0;i<content.size();i++)
    {
        if (content.at(i)->getName() == name)
            return content.at(i);
    }
    return NULL;
}

void Record::setPrevious(SymbolType* previous)
{
    this->previous = previous;
}

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

Array::Array()
{
	this->previous=NULL;
	this->type=NULL;
}

Array::Array(string name)
{
	this->previous=NULL;
	this->type=NULL;
    setName(name);
    dimension = 0;
}

Array::~Array()
{
	if(previous!=NULL)
		delete previous;
	if(type!=NULL)
   	 	delete type;
   
}

int Array::getDim()
{
    return dimension;
}

void Array::setDim(int dimension)
{
    this->dimension = dimension;
}

void Array::setInfo(int length, char head)
{
    this->length.push_back(length);
    this->head.push_back(head);
}

void Array::insert(SymbolType* type)
{
    this->type = type;
}

void Array::setPrevious(SymbolType* previous)
{
    this->previous = previous;
}

char Array::getHead(int location)
{
	return this->head.at(location);
}

int Array::getLength(int location)
{
	return this->length.at(location);   
}

SymbolType* Array::getPrevious()
{
    return previous;
}

Typedef::Typedef()
{
	this->type_def=NULL;
}

Typedef::Typedef(string name, SymbolType* type_def)
{
    setName(name);
    this->type_def = type_def;
}

Typedef::~Typedef()
{
    delete type_def;
}

Function::Function(string name)
{
    this->setName(name);
    retType = NULL;
}

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

void Function::addPara(SymbolType* para)
{
    if (para == NULL)
        return;
    paraList.push_back(para);
}

void Function::setRetType(SymbolType* retType)
{
    if (retType == NULL)
        return;
    this->retType = retType;
}

SymbolType* Function::getRetType()
{
    return retType;
}

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

int Function::retParaNum()
{
	if(!paraList.empty())
    	return paraList.size();
}

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

SymbolType* Function::getParaType(int location)
{
    if (paraList.empty())
        return NULL;
    return paraList.at(location);
}

SymbolTable::SymbolTable()
{
    ptr.push_back(0);
}

SymbolTable* SymbolTable::getInstance()
{
    static SymbolTable* symbolTable = new SymbolTable();
    return symbolTable;
}

void SymbolTable::insert(SymbolType* type)
{
    table.push_back(type);
    if (dynamic_cast<Function *>(type)!=NULL)
        ptr.push_back(table.size() - 1);
}

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

bool SymbolTable::isParaReference(int func_location,string para_name)
{
	if(func_location<=0||func_location>ptr.size()-1)
		return false;
	
	Function* temp=dynamic_cast<Function*>(table.at(ptr.at(func_location)));
	
	if(temp->getParaType(para_name)!=NULL)
		return temp->getParaType(para_name)->getReference();
	return false;
}

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


