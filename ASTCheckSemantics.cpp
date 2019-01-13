 
//  <文件名>：ASTCheckSemantics.cpp 
//  <文件内容>：该文件包含语法树各结点类的类型检查函数的实现 
//
//  <创建日期>：15/03/2017

//  包含头文件
#include <iostream>
#include "stdlib.h"
#include <sstream>
#include <ctime>
#include "AbstractSyntaxTree.h"
#include "SymbolTable.h"

//  命名空间声明
using namespace std;

//  全局变量声明 
int typeerror = 0;  //记录语义分析错误数目 

SymbolType* currentPtr = NULL;	//对当前正在操作的类型指针进行记录，用来进行某些操作的回溯 
int branchNum;		//记录在子函数中遇到的分支的数量 
int retNumInBranch;	//记录在分支中返回值的个数 
int retNumInBody;	//记录在函数体中返回值的个数 
bool flag;  

//  <函数名>：TYPES find_type(Type * type)
//  <函数功能说明>：根据语法树中不同的类返回具体的类型，返回值为枚举类型 
TYPES find_type(Type * type)
{
    if (dynamic_cast<IntegerType *>(type)!=NULL)
        return INT_T;
    else if (dynamic_cast<RealType *>(type)!=NULL)
        return REAL_T;
    else if (dynamic_cast<BooleanType *>(type)!=NULL)
        return BOOL_T;
    else if (dynamic_cast<CharType *>(type)!=NULL)
        return CHAR_T;
    else if (dynamic_cast<ArrayType *>(type)!=NULL)
        return ARRAY_T;
    else if (dynamic_cast<RecordType *>(type)!=NULL)
        return RECORD_T;
    return ERROR_T;
}

//  <函数名>：TYPES find_SymbolType(SymbolType * type)
//  <函数功能说明>：将符号表中储存的元素的类型转化为枚举类型TYPES    
TYPES find_SymbolType(SymbolType * type)
{
    if (dynamic_cast<Const *>(type)!=NULL) 
        //return CONST_T;
        return find_SymbolType(dynamic_cast<Const *>(type)->getType());
    else if (dynamic_cast<Integer *>(type)!=NULL)
        return INT_T;
    else if (dynamic_cast<Bool *>(type)!=NULL)
        return BOOL_T;
    else if (dynamic_cast<Real *>(type)!=NULL)
        return REAL_T;
    else if (dynamic_cast<Char *>(type)!=NULL)
        return CHAR_T;
    else if (dynamic_cast<Array *>(type)!=NULL)
        return ARRAY_T;
    else if (dynamic_cast<Record *>(type)!=NULL)
        return RECORD_T;
    else if (dynamic_cast<Function *>(type)!=NULL)
        return FUNCTION_T;
    return ERROR_T;
}

//  <函数名>：TYPES find_FD(ConstVariable * constVariable)
//  <函数功能说明>：返回const类型的变量的具体类型TYPES 
TYPES find_FD(ConstVariable * constVariable)
{
    if (dynamic_cast<UnsignedIdentifierFD *>(constVariable)!=NULL)
    {
    	if (SymbolTable::getInstance()->find_in_global(dynamic_cast<UnsignedIdentifierFD *>(constVariable)->id))
    		return find_SymbolType(SymbolTable::getInstance()->getType(dynamic_cast<UnsignedIdentifierFD *>(constVariable)->id));
    	else
    	{
    		//typeerror++;
    		//cout<<"\nError: semantic error "<<typeerror<<" at Line "<<dynamic_cast<UnsignedIdentifierFD *>(constVariable)->lineNo<<":\n       常量右值ID或数组下标ID未定义！"<<endl;
    		return ERROR_T;
    	}
    }
    else if (dynamic_cast<SignedIdentifierFD *>(constVariable)!=NULL)
    {
    	if (SymbolTable::getInstance()->find_in_global(dynamic_cast<SignedIdentifierFD *>(constVariable)->id))
    		return find_SymbolType(SymbolTable::getInstance()->getType(dynamic_cast<SignedIdentifierFD *>(constVariable)->id));
    	else
    	{
    		//typeerror++;
    		//cout<<"\nError: semantic error "<<typeerror<<" at Line "<<dynamic_cast<SignedIdentifierFD *>(constVariable)->lineNo<<":\n       常量右值ID或数组下标ID未定义！"<<endl;
    		return ERROR_T;
    	}
    }
    else if (dynamic_cast<UnsignedNumFD *>(constVariable)!=NULL)
    {
    	if(dynamic_cast<UnsignedNumFD *>(constVariable)->num.find(".") != dynamic_cast<UnsignedNumFD *>(constVariable)->num.npos)
    		return REAL_T;
    	else 
    		return INT_T;
	}
    else if (dynamic_cast<SignedNumFD *>(constVariable)!=NULL)
    {
    	if(dynamic_cast<SignedNumFD *>(constVariable)->num.find(".") != dynamic_cast<SignedNumFD *>(constVariable)->num.npos)
    		return REAL_T;
    	else 
    		return INT_T;
    }
    else if (dynamic_cast<LettersFD *>(constVariable)!=NULL)
        return CHAR_T;
    return ERROR_T;
}

//  <函数名>：void Program::checkType()
//  <函数功能说明>：根节点的语义检查函数调用 
void Program::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    body->checkType();
    if(typeerror==0)
    	cout<<"\n\n（2）语义分析完成，未发现错误！"<<endl<<endl;
    else
    	cout<<"\n\n（2）语义分析完成，发现 "<<typeerror<<" 个错误，已列出！"<<endl<<endl;
    //cout<<typeid(this).name()<<"::checkType() end"<<endl;
}

//  <函数名>：void ProgramBody::checkType()
//  <函数功能说明>：主函数体的类型检查 
void ProgramBody::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    for (int i = 0; i < constDeclarations.size(); i++)
    {
        constDeclarations[i]->checkType();
    }
    for (int i = 0; i < typeDeclarations.size(); i++)
    {
        typeDeclarations[i]->checkType();
    }
    for (int i = 0; i < varDeclarations.size(); i++)
    {
        varDeclarations[i]->checkType();
    }
    for (int i = 0; i < subprogramDeclarations.size(); i++)
    {
        subprogramDeclarations[i]->checkType();
    }
    compoundStatement->checkType();
    //cout<<typeid(this).name()<<"::checkType() end"<<endl;
}

//  <函数名>：void ConstDeclaration::checkType()
//  <函数功能说明>：对Const类型的变量声明进行相关的类型检查以及符号表的插入 
void ConstDeclaration::checkType()
{ 
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    Const* newTemp = new Const();
	if (SymbolTable::getInstance()->find(id))//如果在当前块中找到了同名的变量
	{
		typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       Const的变量名重定义!" << endl;
		return;
	}
	newTemp->setName(id);
	SymbolType* temp=NULL;
	if (find_FD(constVariable) == INT_T)//int
	{
		temp = new Integer();
		newTemp->insert(temp);
	}
	else if (find_FD(constVariable) == REAL_T)//real
	{
		temp = new Real();
		newTemp->insert(temp);
	}
	else if (find_FD(constVariable) == CHAR_T)//char
	{
		temp = new Char();
		newTemp->insert(temp);
	}
	else//id
	{
		string right="";
		if (dynamic_cast<UnsignedIdentifierFD *>(constVariable)!=NULL)
			right=dynamic_cast<UnsignedIdentifierFD *>(constVariable)->id;
   		else if (dynamic_cast<SignedIdentifierFD *>(constVariable)!=NULL)
			right=dynamic_cast<SignedIdentifierFD *>(constVariable)->id;
		//如果为Const赋值的是变量，变量的类型即为Const的类型 
		if (SymbolTable::getInstance()->find_in_global(right))
		{
			temp=SymbolTable::getInstance()->getType(right);
			if (dynamic_cast<Const*>(temp)!=NULL)
			{
				newTemp->insert(dynamic_cast<Const*>(temp)->getType());
			}		
			else if (find_SymbolType(temp)==INT_T || find_SymbolType(temp)==REAL_T || find_SymbolType(temp)==BOOL_T || find_SymbolType(temp)==CHAR_T)
			{
				newTemp->insert(temp);
			}
			else
			{
				typeerror++;
				cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       Const定义类型不符合要求！" << endl;
			}
		}
		//id为未声明标识符 
		else
		{
			typeerror++;
			cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       Const定义右值为未知id！" << endl;
		}
	}
	SymbolTable::getInstance()->insert(newTemp);
	//cout<<typeid(this).name()<<"::checkType() end"<<endl;
}

//  <函数名>：void TypeDeclaration::checkType()
//  <函数功能说明>：对type定义的新类型的相关类型检查以及符号表的插入 
void TypeDeclaration::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    SymbolType* temp;
    switch (find_type(type))
    {
        case INT_T:
            temp = new Integer();
            break;
        case REAL_T:
            temp = new Real();
            break;
        case BOOL_T:
            temp = new Bool();
            break;
        case CHAR_T:
            temp = new Char();
            break;
        case RECORD_T:
            temp = new Record();
            currentPtr = temp;
            type->checkType();
            currentPtr = NULL;
            break;
        default:
            temp = new Array();
            currentPtr = temp;
            type->checkType();
            currentPtr = NULL;
            break;
    }
    Typedef* newType = new Typedef(id,temp);
    SymbolTable::getInstance()->insert(newType);
    //cout<<typeid(this).name()<<"::checkType() end"<<endl;
}

//  <函数名>：void VarDeclaration::checkType()
//  <函数功能说明>：对变量的声明进行 相关类型检查以及符号表的插入 
void VarDeclaration::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    SymbolType* temp=NULL;
    if(currentPtr==NULL)
    {
        for (int i = 0; i < identifierList.size(); i++)
        {
            switch(find_type(type))
            {
                case INT_T:
                    temp = new Integer();
                    break;
                case REAL_T:
                    temp=new Real();
                    break;
                case BOOL_T:
                    temp=new Bool();
                    break;
                case CHAR_T:
                    temp=new Char();
                    break;
                case RECORD_T:
                    temp=new Record();
                    break;
                default:
                    temp=new Array();
                    break;
            }
            if(SymbolTable::getInstance()->find(identifierList[i]))
			{
				typeerror++;
				cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n      变量重定义." << endl;
				return;
			} 
            temp->setName(identifierList[i]);
            SymbolTable::getInstance()->insert(temp);
            if(find_type(type)==RECORD_T)//record
            {
                currentPtr=temp;
                type->checkType();
                currentPtr=NULL;
            }
            else if(find_type(type)==ARRAY_T)//array
            {
                currentPtr=temp;
                type->checkType();
                currentPtr=NULL;
            }
        }
    }
    else
    {
        for (int i = 0; i < identifierList.size(); i++)
        {
            switch(find_type(type))
            {
                case INT_T:
                    temp=new Integer();
                    break;
                case REAL_T:
                    temp=new Real();
                    break;
                case BOOL_T:
                    temp=new Bool();
                    break;
                case CHAR_T:
                    temp=new Char();
                    break;
                case RECORD_T:
                    temp=new Record();
                    break;
                default:
                    temp=new Array();
                    break;
            }
            temp->setName(identifierList[i]);
            if(dynamic_cast<Record*>(currentPtr)!=NULL)
            {
            	if(currentPtr->find(identifierList[i]))
            	{
            		typeerror++;
					cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n      Record中变量重定义." << endl;
            	}
            }
            currentPtr->insert(temp);
            if(find_type(type)==RECORD_T)//record
            {
                temp->setPrevious(temp);
                currentPtr=temp;
                type->checkType();
                currentPtr=temp->getPrevious();
            }
            else if(find_type(type)==ARRAY_T)//array
            {
                temp->setPrevious(currentPtr);
                currentPtr=temp;
                type->checkType();
                currentPtr=temp->getPrevious();
            }
            
        }
    }
    //cout<<typeid(this).name()<<"::checkType() end"<<endl;
}

//  <函数名>：void RecordType::checkType()
//  <函数功能说明>：record类型的类型检查 
void RecordType::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    for (int i = 0; i < varDeclarations.size(); i++)
    {
        varDeclarations[i]->checkType();
    }
    //cout<<typeid(this).name()<<"::checkType() end"<<endl;
}

//  <函数名>：void ArrayType::checkType()
//  <函数功能说明>：array类型的类型检查 
void ArrayType::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    Array* temp = dynamic_cast<Array*>(currentPtr);
    temp->setDim(periods.size());
    for (int i = 0; i < periods.size(); i++)
    {
        periods[i]->checkType();
    }
    if (find_type(type) == ARRAY_T)
    {
        Array* newTemp = new Array();
        currentPtr->insert(newTemp);
        newTemp->setPrevious(currentPtr);
        currentPtr = newTemp;
        type->checkType();
        currentPtr = newTemp->getPrevious();
    }
    else if (find_type(type) == RECORD_T)
    {
    	Record* newTemp = new Record();
        currentPtr->insert(newTemp);
        newTemp->setPrevious(currentPtr);
        currentPtr = newTemp;
        type->checkType();
        currentPtr = newTemp->getPrevious();
    }
    else
    {
        type->checkType();
        currentPtr = NULL;
    }
    //cout<<typeid(this).name()<<"::checkType() end"<<endl;
}

//  <函数名>：void Period::checkType()
//  <函数功能说明>：检查数组每一维的上下界，完善已经插入到符号表中的array的信息 
void Period::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
	int head = 1;
	int tail = 0;
	Array* temp = dynamic_cast<Array*>(currentPtr);
	//判断上下界类型是否相等
	if ((find_FD(lower) ==INT_T || find_FD(lower) ==CHAR_T)&&(find_FD(upper) ==INT_T || find_FD(upper) ==CHAR_T))
	{
		if(dynamic_cast<UnsignedIdentifierFD*>(lower)==NULL&&dynamic_cast<SignedIdentifierFD*>(lower)==NULL
			&&dynamic_cast<UnsignedIdentifierFD*>(upper)==NULL&&dynamic_cast<SignedIdentifierFD*>(upper)==NULL)
		{
			head = lower->checkType();
			tail = upper->checkType();
			if(tail<=head)
			{
				typeerror++;
				cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n      数组上下界矛盾." << endl;
			}
			temp->setInfo(tail - head + 1, head);		
		}
		else	temp->setInfo(0,0);
			
	}
	else
	{
		typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n      数组上下界类型不匹配." << endl;
	}
	//cout<<typeid(this).name()<<"::checkType() end"<<endl;
}

//  <函数名>：int LettersFD::checkType()
//  <函数功能说明>：将语法树识别出来的字符转换成ascii码返回 
int LettersFD::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    return letters.c_str()[1];
    //cout<<typeid(this).name()<<"::checkType() end"<<endl;
}

//  <函数名>：int UnsignedNumFD::checkType()
//  <函数功能说明>：将无符号数转换成数值返回 
int UnsignedNumFD::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
	/*if(num.find(".") != num.npos)
	{
		typeerror++;
		cout << "数组下标类型错误！" << endl;
	}*/
    return atoi(num.c_str());
    //cout<<typeid(this).name()<<"::checkType() end"<<endl;
}

//  <函数名>：int SignedNumFD::checkType()
//  <函数功能说明>：将有符号数转换成数值返回 
int SignedNumFD::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
	/*if(num.find(".") != num.npos)
	{
		typeerror++;
		cout << "数组下标类型错误！" << endl;
	}*/
    if (sign)
        return atoi(num.c_str());
    else
        return -atoi(num.c_str());
    //cout<<typeid(this).name()<<"::checkType() end"<<endl;
}

//  <函数名>：void IntegerType::checkType()
//  <函数功能说明>：识别出array的类型为int，插入到当前操作的array指针中 
void IntegerType::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    //Only Array
    Array* temp = dynamic_cast<Array*>(currentPtr);
    Integer* newType = new Integer();
    temp->insert(newType);
    //cout<<typeid(this).name()<<"::checkType() end"<<endl;
}

//  <函数名>：void RealType::checkType()
//  <函数功能说明>：识别出array的类型为real，插入到当前操作的array指针中 
void RealType::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    Array* temp = dynamic_cast<Array*>(currentPtr);
    Real* newType = new Real();
    temp->insert(newType);
    //cout<<typeid(this).name()<<"::checkType() end"<<endl;
}

//  <函数名>：void BooleanType::checkType()
//  <函数功能说明>：识别出array的类型为boolean，插入到当前操作的array指针中 
void BooleanType::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    Array* temp = dynamic_cast<Array*>(currentPtr);
    Bool* newType = new Bool();
    temp->insert(newType);
}

//  <函数名>：void CharType::checkType()
//  <函数功能说明>：识别出array的类型为char，插入到当前操作的array指针中 
void CharType::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    Array* temp = dynamic_cast<Array*>(currentPtr);
    Char* newType = new Char();
    temp->insert(newType);
}

//  <函数名>：void SubprogramDeclaration::checkType()
//  <函数功能说明>：子函数声明的类型检查 
void SubprogramDeclaration::checkType()
{
	branchNum=0;
	retNumInBranch=0;
	retNumInBody=0;
	flag=false;
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    bool isFunc=head->checkType();
    body->checkType();
    SymbolTable::getInstance()->reLocation();
    if(isFunc)
	    if(retNumInBody==0&&retNumInBranch!=branchNum)
	    {
	    	//typeerror++;
			//cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n      不是所有的情况都有返回值." << endl;
	    }
}

//  <函数名>：bool SubprogramHead::checkType()
//  <函数功能说明>：对子函数声明的头部的类型检查，包括函数名，参数，返回值等的检查 
bool SubprogramHead::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    Function* newFunc = new Function(id);
    SymbolType* newTemp;
    if (ret == NULL)
    {
        newTemp = NULL;
    }
    else if (find_type(ret) == INT_T)
    {
        newTemp = new Integer();
    }
    else if (find_type(ret) == CHAR_T)
    {
        newTemp = new Char();
    }
    else if (find_type(ret) == BOOL_T)
    {
        newTemp = new Bool();
    }
    else if (find_type(ret) == REAL_T)
    {
        newTemp = new Real();
    }
    newFunc->setRetType(newTemp);
    SymbolTable::getInstance()->insert(newFunc);
    if (!parameterLists.empty())
    {
        for (int i = 0; i < parameterLists.size(); i++)
        {
            for (int j = 0; j < parameterLists[i]->identifierList.size(); j++)
            {
                if (find_type(parameterLists[i]->type) == INT_T)
                {
                    newTemp = new Integer(parameterLists[i]->identifierList[j]);
                }
                else if (find_type(parameterLists[i]->type) == CHAR_T)
                {
                    newTemp = new Char(parameterLists[i]->identifierList[j]);
                }
                else if (find_type(parameterLists[i]->type) == BOOL_T)
                {
                    newTemp = new Bool(parameterLists[i]->identifierList[j]);
                }
                else if (find_type(parameterLists[i]->type) == REAL_T)
                {
                    newTemp = new Real(parameterLists[i]->identifierList[j]);
                }
                if(parameterLists[i]->byReference==true)
                	newTemp->setReference();
                if(newFunc->findpara(parameterLists[i]->identifierList[j]))
                {
                	typeerror++;
					cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       参数重定义！" << endl;
					srand(unsigned(time(0)));
					string s;
					std::stringstream ss;
					ss<<rand()/RAND_MAX;
					ss>>s;
					newTemp->setName(parameterLists[i]->identifierList[j]+s);
                }
                newFunc->addPara(newTemp);
            }
        }
    }
    if(ret==NULL)
    	return false;
    return true;
}

//  <函数名>：void SubprogramBody::checkType()
//  <函数功能说明>：对子函数体的类型检查，其检查和主函数的函数体检查结构基本相同 
void SubprogramBody::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    for (int i = 0; i < constDeclarations.size(); i++)
    {
        constDeclarations[i]->checkType();
    }
    for (int i = 0; i < typeDeclarations.size(); i++)
    {
        typeDeclarations[i]->checkType();
    }
    for (int i = 0; i < varDeclarations.size(); i++)
    {
        varDeclarations[i]->checkType();
    }
    for (int i = 0; i < subprogramDeclarations.size(); i++)
    {
        subprogramDeclarations[i]->checkType();
    }
    compoundStatement->checkType();
}

//  <函数名>：void CompoundStatement::checkType()
//  <函数功能说明>：对每一个函数的主函数体的类型检查
//	即begin..end部分 
void CompoundStatement::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    for (int i = 0; i < statementList.size(); i++)
    {
    	if(statementList[i]!=NULL)
        	statementList[i]->checkType();
    }
    //cout<<typeid(this).name()<<"::checkType() end"<<endl;
}

//  <函数名>：void AssignStatement::func(Variable* variable,Expression* expression)
//  <函数功能说明>：赋值语句用于进行递归调用的函数，为其checkType的主体 
//	主要思想是根据名字等价和类型等价判断其是否相等 
void AssignStatement::func(Variable* variable,Expression* expression)
{
	if(!SymbolTable::getInstance()->find_in_global(variable->id))
	{
		typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       变量"<<variable->id<<"为未声明标识符！" << endl;
		return;
	}
	if(dynamic_cast<Const*>(SymbolTable::getInstance()->getType(variable->id))!=NULL)
	{
		typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       变量"<<variable->id<<"为常量，不能出现在赋值语句左侧！" << endl;
		return;
	}
	
	if(find_SymbolType(SymbolTable::getInstance()->getType(variable->id)) ==FUNCTION_T)
	{
		if(flag==true)
			retNumInBranch++;
		else
			retNumInBody++;					
	}	
	if (dynamic_cast<Variable *>(expression)!=NULL)
	{
		if ((find_SymbolType(variable->varRetType())==ARRAY_T && find_SymbolType(dynamic_cast<Variable *>(expression)->varRetType())==ARRAY_T)
			||(find_SymbolType(variable->varRetType())==RECORD_T && find_SymbolType(dynamic_cast<Variable *>(expression)->varRetType())==RECORD_T))
		{
			if(variable->varRetType()!=dynamic_cast<Variable *>(expression)->varRetType())
			{
				typeerror++;
				cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       赋值语句左右值类型不兼容！" << endl;
			}
		}
		else
		{
			if(variable->checkType()!=expression->checkType())
			{
				
				typeerror++;
				cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       赋值语句左右值类型不兼容！" << endl;
			}
		}
	}		
	else if (dynamic_cast<Parenthesis *>(expression)!=NULL)
	{
		func(variable,dynamic_cast<Parenthesis *>(expression)->expression);	
	}
	else
	{
		if(variable->checkType()!=expression->checkType())
		{
			typeerror++;
			
			cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       赋值语句左右值类型不兼容！" << endl;
		}
	}			 
}

//  <函数名>：void AssignStatement::checkType()
//  <函数功能说明>：对赋值语句进行类型检查，主体是func()函数 
void AssignStatement::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
	
	func(variable,expression);

	currentPtr = NULL;
}

//  <函数名>：TYPES Variable::checkType()
//  <函数功能说明>：返回该变量的类型，用枚举类型TYPE表示 
TYPES Variable::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
	return find_SymbolType(this->varRetType());	
}

//  <函数名>：SymbolType* Variable::varRetType()
//  <函数功能说明>：根据id和idVarParts对一个变量进行相关的类型检查，如果出错返回null，
//	否则返回该变量的类型 

SymbolType* Variable::varRetType()
{
	//cout<<typeid(this).name()<<"::varRetType() begin"<<endl;
	if (!(SymbolTable::getInstance()->find_in_global(id)))
	{
		typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       变量"<<id<<"为未声明标识符！" << endl;
		return NULL;
	}
	
	if (find_SymbolType(SymbolTable::getInstance()->getType(id)) == INT_T || find_SymbolType(SymbolTable::getInstance()->getType(id)) == BOOL_T || find_SymbolType(SymbolTable::getInstance()->getType(id)) == REAL_T || find_SymbolType(SymbolTable::getInstance()->getType(id)) == CHAR_T)
	{
		if (idVarParts.size() == 0)
			return SymbolTable::getInstance()->getType(id);
		else
		{
			typeerror++;
			cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       赋值语句左值类型错误！" << endl;
		}
	}

	//function  
	if(find_SymbolType(SymbolTable::getInstance()->getType(id)) == FUNCTION_T)
	{
		Function* fun=dynamic_cast<Function*>(SymbolTable::getInstance()->getType(id));
		if(fun->getRetType()==NULL)
		{
			typeerror++;
			cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       过程无返回值！" << endl;
		}
		else
		{
			return fun->getRetType();
		}
	} 
	
	if (find_SymbolType(SymbolTable::getInstance()->getType(id)) == ARRAY_T)
	{
		currentPtr = SymbolTable::getInstance()->getType(id);
		
		//用currentPtr记录当前检查到的数组和record,在他们的每一层判断对应的属性,(比如数组的维度),当下面的循环完成之后,判断
		//当前的currentPtr是否是标准类型,如果是,则返回它对应的类型,否则,返回ERROR_T,最后要把currentPtr==NULL;
		for (int i = 0; i < idVarParts.size(); i++)
		{
			
			if (i == 0)
			{
				Array* temp = dynamic_cast<Array*>(currentPtr);
				//判断维度是否相等
				if (temp->getDim() != dynamic_cast<ArrayPart*>(idVarParts[i])->expressionList.size())
				{
					typeerror++;
					cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       数组与定义维度不相等！" << endl;
					return NULL;
				}
				idVarParts[i]->checkType();
				currentPtr = temp->getType();
				if (find_SymbolType(currentPtr) == INT_T || find_SymbolType(currentPtr) == BOOL_T || find_SymbolType(currentPtr) == REAL_T || find_SymbolType(currentPtr) == CHAR_T)
				{
					if (i != idVarParts.size() - 1)
					{
						typeerror++;
						
						cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       赋值语句左值类型错误！" << endl;
						return NULL;
					}
					else
					{
						return currentPtr;
					}
				}
			}
			else
			{
				//如果是array，和i=0时的判断方法相同
				if (find_SymbolType(currentPtr)==ARRAY_T) 
				{
					Array* temp = dynamic_cast<Array*>(currentPtr);
					if (temp->getDim() != dynamic_cast<ArrayPart*>(idVarParts[i])->expressionList.size())
					{
						typeerror++;
						cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       数组与定义维度不相等！" << endl;
						return NULL;
					}
					idVarParts[i]->checkType();
					currentPtr = temp->getType();
					if (find_SymbolType(currentPtr) == INT_T || find_SymbolType(currentPtr) == BOOL_T || find_SymbolType(currentPtr) == REAL_T || find_SymbolType(currentPtr) == CHAR_T)
					{
						
						if (i != idVarParts.size() - 1)
						{
							typeerror++;
							
							cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       赋值语句左值类型错误！" << endl;
							return NULL;
						}
						else
						{
							return currentPtr;
						}
					}
				}
				//如果是record，则返回该id的类型,然后继续循环
				else if (find_SymbolType(currentPtr)==RECORD_T)
				{
					Record* temp = dynamic_cast<Record*>(currentPtr);
					
					if (temp->getType(dynamic_cast<MemberPart*>(idVarParts[i])->id) == NULL)
					{
						typeerror++;
						cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       赋值语句左值变量不存在." << endl;
						return NULL;
					}
					else
					{
						currentPtr = temp->getType(dynamic_cast<MemberPart*>(idVarParts[i])->id);
					}
				}
				//idVarParts[i]->checkType();
			}
		}
	}
	
	//record
	if (find_SymbolType(SymbolTable::getInstance()->getType(id)) == RECORD_T)
	{
		currentPtr = SymbolTable::getInstance()->getType(id);
		//用currentPtr记录当前检查到的数组和record,在他们的每一层判断对应的属性,(比如数组的维度),当下面的循环完成之后,判断
		//当前的currentPtr是否是标准类型,如果是,则返回它对应的类型,否则,返回ERROR_T,最后要把currentPtr==NULL;
		for (int i = 0; i < idVarParts.size(); i++)
		{
			if (i == 0)
			{
				Record* temp = dynamic_cast<Record*>(currentPtr);
				//cout<<"ahhahahahhhahhahahahhahahhahhaahhahahhahahahahhahhahahhahhahahahahahhahahhahahahahhahah"<<endl;
				//cout<<find_SymbolType(currentPtr)<<endl;
				//cout<<find_SymbolType(temp->getType(dynamic_cast<MemberPart*>(idVarParts[i])->id))<<endl;
				if (temp->getType(dynamic_cast<MemberPart*>(idVarParts[i])->id) == NULL)
				{
					typeerror++;
					cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       赋值语句左值变量不存在." << endl;
					return NULL;
				}
				else
				{
					currentPtr = temp->getType(dynamic_cast<MemberPart*>(idVarParts[i])->id);
					//cout<<find_SymbolType(currentPtr)<<endl;
					if (find_SymbolType(currentPtr) == INT_T || find_SymbolType(currentPtr) == BOOL_T || find_SymbolType(currentPtr) == REAL_T || find_SymbolType(currentPtr) == CHAR_T)
					{
						
						if (i != idVarParts.size() - 1)
						{
							typeerror++;
							
							cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       赋值语句左值类型错误！" << endl;
							return NULL;
						}
						else
						{
							return currentPtr;
						}
					}
				}
			}
			else
			{
				if (find_SymbolType(currentPtr) == INT_T || find_SymbolType(currentPtr) == BOOL_T || find_SymbolType(currentPtr) == REAL_T || find_SymbolType(currentPtr) == CHAR_T)
				{
						typeerror++;
						
						cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       赋值语句左值类型错误！" << endl;
						return NULL;
				}
				else if (find_SymbolType(currentPtr)==ARRAY_T)
				{
					Array* temp = dynamic_cast<Array*>(currentPtr);
					if (temp->getDim() != dynamic_cast<ArrayPart*>(idVarParts[i])->expressionList.size())
					{
						typeerror++;
						cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       数组与定义维度不相等！" << endl;
						return NULL;
					}
					idVarParts[i]->checkType();
					currentPtr = temp->getType();
					if (find_SymbolType(currentPtr) == INT_T || find_SymbolType(currentPtr) == BOOL_T || find_SymbolType(currentPtr) == REAL_T || find_SymbolType(currentPtr) == CHAR_T)
					{
						if (i != idVarParts.size() - 1)
						{
							typeerror++;
							cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       赋值语句左值类型错误！" << endl;
							return NULL;
						}
						else
						{
							return currentPtr;
						}
					}
				}
				//如果是record，则返回该id的类型,然后继续循环
				else if (find_SymbolType(currentPtr)==RECORD_T)
				{
					Record* temp = dynamic_cast<Record*>(currentPtr);
					if (temp->getType(dynamic_cast<MemberPart*>(idVarParts[i])->id) == NULL)
					{
						typeerror++;
						cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       赋值语句左值变量不存在." << endl;
						return NULL;
					}
					else
					{
						currentPtr = temp->getType(dynamic_cast<MemberPart*>(idVarParts[i])->id);
						if (find_SymbolType(currentPtr) == INT_T || find_SymbolType(currentPtr) == BOOL_T || find_SymbolType(currentPtr) == REAL_T || find_SymbolType(currentPtr) == CHAR_T)
						{
							if (i != idVarParts.size() - 1)
							{
								typeerror++;
								cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       赋值语句左值类型错误！" << endl;
								return NULL;
							}
							else
							{
								return currentPtr;
							}
						}
					}
				}
			}
		}
	}
	return NULL;
	//cout<<typeid(this).name()<<"::varRetType() end"<<endl;
}

//  <函数名>：TYPES ArrayPart::checkType()
//  <函数功能说明>：对类型为array的变量括号中的每一部分进行类型检查 
TYPES ArrayPart::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
	Array *temp = dynamic_cast<Array*>(currentPtr);
	for (int i = 0; i < expressionList.size(); i++)
	{
		
			if(dynamic_cast<Num *> (expressionList[i])!=NULL)
			{
				if(temp->getLength(i)!=0)
				{
					if(atoi(dynamic_cast<Num *> (expressionList[i])->num.c_str())+temp->getHead(i)>temp->getLength(i)||atoi(dynamic_cast<Num *> (expressionList[i])->num.c_str())<temp->getHead(i))	
					{
						typeerror++;
						cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       数组越界." << endl;
					}
				}
				
			}
			else if(dynamic_cast<Letters *> (expressionList[i])!=NULL)
			{
				if(temp->getLength(i)!=0)
				{
					if(dynamic_cast<Letters *> (expressionList[i])->letters.c_str()[1] + temp->getHead(i) > temp->getLength(i)||atoi(dynamic_cast<Num *> (expressionList[i])->num.c_str())<temp->getHead(i))	
					{
						typeerror++;
						cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       数组越界." << endl;
					}
				}
				
			}
	
        expressionList[i]->checkType();
    }
}

//  <函数名>：TYPES MemberPart::checkType()
//  <函数功能说明>：其检查Record成员的功能已经在VarRetType()中实现 
TYPES MemberPart::checkType(){}

//  <函数名>：void CallProcedureStatement::checkType()
//  <函数功能说明>：在调用一个过程时对其进行类型检查 
void CallProcedureStatement::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
	if (!SymbolTable::getInstance()->find_in_global(id))		//如果不是一个函数
	{
		typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       该函数未定义！" << endl;
		return;
	}	
	if (find_SymbolType(SymbolTable::getInstance()->getType(id)) == FUNCTION_T)
	{
		Function *temp = dynamic_cast<Function*>(SymbolTable::getInstance()->getType(id));
		if (temp->retParaNum() != expressionList.size())
		{
			typeerror++;
			cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       函数或过程参数数目不匹配！" << endl;
			return;
		}
		for (int i = 0; i < expressionList.size(); i++)
		{
			if (find_SymbolType(temp->getParaType(i)) != expressionList[i]->checkType())
			{
				typeerror++;
				cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       函数或过程参数类型不匹配！" << endl;
				return;
			}
			if(temp->getParaType(i)->getReference())
			{
				if(dynamic_cast<Variable*>(expressionList[i])==NULL)
				{
					typeerror++;
					cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       函数参数不能作为引用调用！" << endl;
					return ;
				}
				else
				{
					if(!dynamic_cast<Variable*>(expressionList[i])->idVarParts.empty())
					{
					typeerror++;
					cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       函数参数不能作为引用调用！" << endl;
					return ;
					}
				}
				
			}	
		}
	}	
	else
	{
		typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       这是一个过程，无返回值！" << endl;
	}
}

//  <函数名>：void IfStatement::checkType()
//  <函数功能说明>：对if语句的类型检查 
void IfStatement::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
	
    if (expression->checkType() != BOOL_T) 
	{
        typeerror++;
        cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       If语句判断条件类型不匹配！" << endl; 
    }
    if (thenStatement != NULL)
	{
		flag=true;
    	thenStatement->checkType();
    	branchNum++;
    	flag=false;
    }
    if (elseStatement != NULL)
	{
		flag=true;
        elseStatement->checkType();
        branchNum++;
        flag=false;
    }
    //cout<<typeid(this).name()<<"::checkType() end"<<endl;
}

//  <函数名>：void CaseStatement::checkType()
//  <函数功能说明>：对case语句的类型检查 
void CaseStatement::checkType()	//不能瞎强制类型转换
{
	
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    if (expression->checkType() != BOOL_T && expression->checkType() != INT_T && expression->checkType() != CHAR_T)
	{
        typeerror++;
        cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       Case语句判断条件类型不匹配！" << endl;    
    }
    for (int i = 0; i < branchList.size(); i++)
	{
		branchNum++;
		flag=true;
		if (branchList[i]->checkType() != expression->checkType())
		{
			typeerror++;
			cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       Case语句判断条件类型不匹配！" << endl;
		}
		flag=false;
    }
}

//  <函数名>：TYPES Branch::checkType()
//  <函数功能说明>：对case的每一个分支的类型检查 
TYPES Branch::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
	TYPES temp = find_FD(constVariable.at(0));
	for (int i = 0; i < constVariable.size(); i++)
	{
		if (find_FD(constVariable.at(i)) != temp)//num
		{
			typeerror++;
			cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       Case语句判断条件类型不匹配！" << endl;
			return ERROR_T;
		}
	}
	statement->checkType();//即使条件错误，仍然判断其正确性
	return temp;
}

//  <函数名>：void WhileStatement::checkType()
//  <函数功能说明>：对while循环的类型检查 
void WhileStatement::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    if (expression->checkType() != BOOL_T)
	{
        typeerror++;
        cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       While语句判断条件类型不匹配！" << endl;
    }
    statement->checkType();
}

//  <函数名>：void RepeatStatement::checkType()
//  <函数功能说明>：对repeat语句的类型检查 
void RepeatStatement::checkType()
{ 
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    for (int i = 0; i < statementList.size(); i++)
	{
        statementList[i]->checkType();
    }            
    if (expression->checkType() != BOOL_T)
	{
        typeerror++;
        cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       Repeat语句判断条件类型不匹配！" << endl;                        
    }
}

//  <函数名>：void ForStatement::checkType()
//  <函数功能说明>：对for循环的类型检查 
void ForStatement::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
	if (!SymbolTable::getInstance()->find_in_global(id))
	{
		typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       For语句判断条件id未定义！" << endl;
	}
    else if (find_SymbolType(SymbolTable::getInstance()->getType(id)) != INT_T || lower->checkType() != INT_T || upper->checkType() != INT_T)
	{
		typeerror++;
        cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       For语句判断条件类型不匹配！" << endl;
    }
    statement->checkType();
}

//  <函数名>：void WriteStatement::checkType()
//  <函数功能说明>：对write语句的类型检查 
void WriteStatement::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    for (int i = 0; i < expressionList.size(); i++)
	{
        expressionList[i]->checkType();
    }
}

//  <函数名>：TYPES BinaryExpression::checkType()
//  <函数功能说明>：对二元比较运算符如=，!=，>,<等的类型检查，返回true或null 
TYPES BinaryExpression::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    if (left->checkType() != right->checkType())
	{  //左右类型是否一致
		typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       左右表达式类型不匹配！" << endl;
	}                   //关系运算符两边的类型不对，报错  
    return BOOL_T;                                  //表达式的类型为boolean
}

//  <函数名>：TYPES BinarySimpleExpression::checkType()
//  <函数功能说明>：对+，-，or等运算的类型检查，如果是or返回BOOL_T
//	+或-返回其运算结果的类型 
TYPES BinarySimpleExpression::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    if (addop == OR)		//什么基本类型都能判断
	{                                       //若为OR,左右为BooleanType
        /*if (!(simpleExpression->checkType() == BOOL_T && term->checkType() == BOOL_T))
		{
            typeerror++;
            cout << "BinarySimpleExpression-OR-type_error" << endl;                           //类型不对，报错
        }*/
        return BOOL_T;                                       //表达式类型为BooleanType
    }
    else 
	{                                                  //若为+、-,左右都为int
        /*if (simpleExpression->checkType() == INT_T&& term->checkType() == INT_T)
		{
            return TYPES::INT_T;         //返回int
        }                                                  //若为+、-,左右都为real
        else if (simpleExpression->checkType() == TYPES::REAL_T && term->checkType() == TYPES::REAL_T)
		{
            return TYPES::REAL_T;           //返回real 
        }                                                  //若为+、-,左为real右为int
        else if (simpleExpresson->checkType() == TYPES::REAL_T && term->checkType() == INT_T)
		{
            return TYPES::REAL_T;          //返回real                         
        }                                                  //若为+、-,左为int右为real
        else if (simpleExpression->checkType() == INT_T && term->checkType() == TYPES::REAL_T)
		{
            return TYPES::REAL_T;           //返回real  
        }
        else
		{                           //不符合上述情况
            typeerror++;
            cout << "BinarysimpleExpression-PLUS/MINUS-type_error" << endl;       //类型不对，报错 
            return TYPES::ERROR_T;            //返回real  
		}*/
		if (simpleExpression->checkType() == REAL_T || term->checkType() == REAL_T)
			return REAL_T;
		else
			return INT_T;
    }
}

//  <函数名>：TYPES SignedTerm::checkType()
//  <函数功能说明>：有符号项的类型检查 
TYPES SignedTerm::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    return term->checkType();
}

//  <函数名>：TYPES BinaryTerm::checkType()
//  <函数功能说明>：对AND，以及乘除的类型检查 ，返回其结果的类型 
TYPES BinaryTerm::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
	if (term->checkType() == ERROR_T || factor->checkType() == ERROR_T )
	{
        typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       运算类型错误！" << endl;
		return ERROR_T;
    }
	if (mulop == AND)		//什么基本类型都能判断
	{                                       //若为and,左右d都为BooleanType
		/*if (!(term->checkType() == BOOL_T && factor->checkType() == BOOL_T))
		{
		typeerror++;
		cout << "BinaryTerm-AND-type_error" << endl;                            //类型不对，报错
		}*/
		return BOOL_T;             //表达式类型为Boolean
	}
    else if (mulop == INTDIVIDE || mulop == MOD)
	{                 //若为div、mod,左右为int 
        
        return INT_T;                                  //表达式类型为int
    }
	else            //+,-仍然什么类型都可以运算
	{                                                    //若为*、/,左右都为int
        /*if (term->checkType() == INT_T && factor->checkType() == INT_T)
		{
            return INT_T;         //返回int
        }                                                  //若为*、/,左右都为real
        else if (term->checkType() == TYPES::REAL_T && factor->checkType() == TYPES::REAL_T)
		{
            return TYPES::REAL_T;           //返回real 
        }                                                  //若为*、/,左为real右为int
        else if (term->checkType() == TYPES::REAL_T && factor->checkType() == INT_T)
		{
            return TYPES::REAL_T;          //返回real                         
        }                                                  //若为*、/,左为int右为real
        else if (term->checkType() == INT_T && factor->checkType() == TYPES::REAL_T)
		{
            return TYPES::REAL_T;           //返回real  
        }
        else 
		{                                             //不符合上述情况
            typeerror++;
            cout << "BinaryTerm-MULTIPLY/REALDIVIDE-type_error" << endl;       //类型不对，报错 
            return TYPES::REAL_T;            //返回real  
        }*/
		if (term->checkType() == REAL_T || factor->checkType() == REAL_T)
			return REAL_T;
		else
			return INT_T;
    }
}

//  <函数名>：TYPES FunctionCall::checkType()
//  <函数功能说明>：对函数调用的类型检查，具体为参数列表等的检查，返回函数的返回值 
TYPES FunctionCall::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
	
	Function* temp = dynamic_cast<Function*> (SymbolTable::getInstance()->getType(id));
	if (!SymbolTable::getInstance()->find_in_global(id))
	{
		typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       该函数或过程未定义！" << endl;
		return ERROR_T;
	}
	if (temp->getRetType() == NULL)
	{
		typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       是过程而不是一个函数！" << endl;
		return ERROR_T;
	}
	if (temp->retParaNum() != expressionList.size())
	{
		typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       该函数或过程调用参数数目不匹配！" << endl;
	}
	for (int i = 0; i < expressionList.size(); i++)
	{
		
		/*if (find_SymbolType(temp->getParaType(i)) != expressionList[i]->checkType())
		{
			typeerror++;
			cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       该函数或过程调用参数类型不匹配！" << endl;
		}*/
		expressionList[i]->checkType();
		if(temp->getParaType(i)->getReference())
		{
			if(dynamic_cast<Variable*>(expressionList[i])==NULL)
			{
				typeerror++;
				cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       函数参数不能作为引用调用！" << endl;
			}
			else
			{
				if(!dynamic_cast<Variable*>(expressionList[i])->idVarParts.empty())
				{
				typeerror++;
				cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       函数参数不能作为引用调用！" << endl;
				}
			}
			
		}
	}
    return find_SymbolType(temp->getRetType());                //查找符号表,得到函数返回值类型并返回
}

//  <函数名>：TYPES Num::checkType()
//  <函数功能说明>：对Num的类型检查，返回INT_T或BOOL_T 
TYPES Num::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    if (num.find(".") != num.npos)
	{          //有小数点,返回real
        return REAL_T;
    }
    else
	{
		return INT_T;                           //否则返回int
    }
}

//  <函数名>：TYPES Letters::checkType()
//  <函数功能说明>：对字符的类型检查，返回CHAR_T 
TYPES Letters::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    return CHAR_T; 
}

//  <函数名>：TYPES Parenthesis::checkType()
//  <函数功能说明>：用于Parenetthesis类的类型检查 
TYPES Parenthesis::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    return expression->checkType();
}

//  <函数名>：TYPES Not::checkType()
//  <函数功能说明>：对Not语句的类型检查 
TYPES Not::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
	if(factor->checkType() == BOOL_T)
    	return  BOOL_T ;
    else
    {
    	typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       Not内部参数类型错误！" << endl;
		return ERROR_T;
	} 
}

//  <函数名>：TYPES Boolean::checkType()
//  <函数功能说明>：对布尔值(true或false)的类型检查 
TYPES Boolean::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    return  BOOL_T;
}



