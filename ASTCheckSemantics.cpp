#include <iostream>
#include "stdlib.h"
#include <sstream>
#include <ctime>
#include "AbstractSyntaxTree.h"
#include "SymbolTable.h"

using namespace std;

int typeerror = 0; 

SymbolType* currentPtr = NULL;
int branchNum;
int retNumInBranch;
int retNumInBody;
bool flag;  

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

TYPES find_FD(ConstVariable * constVariable)
{
    if (dynamic_cast<UnsignedIdentifierFD *>(constVariable)!=NULL)
    {
    	if (SymbolTable::getInstance()->find_in_global(dynamic_cast<UnsignedIdentifierFD *>(constVariable)->id))
    		return find_SymbolType(SymbolTable::getInstance()->getType(dynamic_cast<UnsignedIdentifierFD *>(constVariable)->id));
    	else
    	{
    		//typeerror++;
    		//cout<<"\nError: semantic error "<<typeerror<<" at Line "<<dynamic_cast<UnsignedIdentifierFD *>(constVariable)->lineNo<<":\n       "<<endl;
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
    		//cout<<"\nError: semantic error "<<typeerror<<" at Line "<<dynamic_cast<SignedIdentifierFD *>(constVariable)->lineNo<<":\n      "<<endl;
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

void Program::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    body->checkType();
    if(typeerror==0)
    	cout<<"\n\n"<<endl<<endl;
    else
    	cout<<"\n\n "<<typeerror<<" "<<endl<<endl;
    //cout<<typeid(this).name()<<"::checkType() end"<<endl;
}

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

void ConstDeclaration::checkType()
{ 
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    Const* newTemp = new Const();
	if (SymbolTable::getInstance()->find(id))
	{
		typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       Const!" << endl;
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
				cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       Const" << endl;
			}
		}
		else
		{
			typeerror++;
			cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       Const" << endl;
		}
	}
	SymbolTable::getInstance()->insert(newTemp);
	//cout<<typeid(this).name()<<"::checkType() end"<<endl;
}

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
				cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n      ." << endl;
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
					cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n      Record." << endl;
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

void RecordType::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    for (int i = 0; i < varDeclarations.size(); i++)
    {
        varDeclarations[i]->checkType();
    }
    //cout<<typeid(this).name()<<"::checkType() end"<<endl;
}

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

void Period::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
	int head = 1;
	int tail = 0;
	Array* temp = dynamic_cast<Array*>(currentPtr);
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
				cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n      ." << endl;
			}
			temp->setInfo(tail - head + 1, head);		
		}
		else	temp->setInfo(0,0);
			
	}
	else
	{
		typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n      ." << endl;
	}
	//cout<<typeid(this).name()<<"::checkType() end"<<endl;
}

int LettersFD::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    return letters.c_str()[1];
    //cout<<typeid(this).name()<<"::checkType() end"<<endl;
}

int UnsignedNumFD::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
	/*if(num.find(".") != num.npos)
	{
		typeerror++;
		cout << "�" << endl;
	}*/
    return atoi(num.c_str());
    //cout<<typeid(this).name()<<"::checkType() end"<<endl;
}

int SignedNumFD::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
	/*if(num.find(".") != num.npos)
	{
		typeerror++;
		cout << "" << endl;
	}*/
    if (sign)
        return atoi(num.c_str());
    else
        return -atoi(num.c_str());
    //cout<<typeid(this).name()<<"::checkType() end"<<endl;
}

void IntegerType::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    //Only Array
    Array* temp = dynamic_cast<Array*>(currentPtr);
    Integer* newType = new Integer();
    temp->insert(newType);
    //cout<<typeid(this).name()<<"::checkType() end"<<endl;
}

void RealType::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    Array* temp = dynamic_cast<Array*>(currentPtr);
    Real* newType = new Real();
    temp->insert(newType);
    //cout<<typeid(this).name()<<"::checkType() end"<<endl;
}

void BooleanType::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    Array* temp = dynamic_cast<Array*>(currentPtr);
    Bool* newType = new Bool();
    temp->insert(newType);
}

void CharType::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    Array* temp = dynamic_cast<Array*>(currentPtr);
    Char* newType = new Char();
    temp->insert(newType);
}

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
			//cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n      ." << endl;
	    }
}

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
					cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       " << endl;
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

void AssignStatement::func(Variable* variable,Expression* expression)
{
	if(!SymbolTable::getInstance()->find_in_global(variable->id))
	{
		typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       "<<variable->id<<"" << endl;
		return;
	}
	if(dynamic_cast<Const*>(SymbolTable::getInstance()->getType(variable->id))!=NULL)
	{
		typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       "<<variable->id<<"" << endl;
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
				cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       " << endl;
			}
		}
		else
		{
			if(variable->checkType()!=expression->checkType())
			{
				
				typeerror++;
				cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       " << endl;
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
			
			cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       " << endl;
		}
	}			 
}

void AssignStatement::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
	
	func(variable,expression);

	currentPtr = NULL;
}

TYPES Variable::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
	return find_SymbolType(this->varRetType());	
}

SymbolType* Variable::varRetType()
{
	//cout<<typeid(this).name()<<"::varRetType() begin"<<endl;
	if (!(SymbolTable::getInstance()->find_in_global(id)))
	{
		typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       "<<id<<"" << endl;
		return NULL;
	}
	
	if (find_SymbolType(SymbolTable::getInstance()->getType(id)) == INT_T || find_SymbolType(SymbolTable::getInstance()->getType(id)) == BOOL_T || find_SymbolType(SymbolTable::getInstance()->getType(id)) == REAL_T || find_SymbolType(SymbolTable::getInstance()->getType(id)) == CHAR_T)
	{
		if (idVarParts.size() == 0)
			return SymbolTable::getInstance()->getType(id);
		else
		{
			typeerror++;
			cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       " << endl;
		}
	}

	//function  
	if(find_SymbolType(SymbolTable::getInstance()->getType(id)) == FUNCTION_T)
	{
		Function* fun=dynamic_cast<Function*>(SymbolTable::getInstance()->getType(id));
		if(fun->getRetType()==NULL)
		{
			typeerror++;
			cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       " << endl;
		}
		else
		{
			return fun->getRetType();
		}
	} 
	
	if (find_SymbolType(SymbolTable::getInstance()->getType(id)) == ARRAY_T)
	{
		currentPtr = SymbolTable::getInstance()->getType(id);
		

		for (int i = 0; i < idVarParts.size(); i++)
		{
			
			if (i == 0)
			{
				Array* temp = dynamic_cast<Array*>(currentPtr);
				if (temp->getDim() != dynamic_cast<ArrayPart*>(idVarParts[i])->expressionList.size())
				{
					typeerror++;
					cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       " << endl;
					return NULL;
				}
				idVarParts[i]->checkType();
				currentPtr = temp->getType();
				if (find_SymbolType(currentPtr) == INT_T || find_SymbolType(currentPtr) == BOOL_T || find_SymbolType(currentPtr) == REAL_T || find_SymbolType(currentPtr) == CHAR_T)
				{
					if (i != idVarParts.size() - 1)
					{
						typeerror++;
						
						cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       " << endl;
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
				if (find_SymbolType(currentPtr)==ARRAY_T) 
				{
					Array* temp = dynamic_cast<Array*>(currentPtr);
					if (temp->getDim() != dynamic_cast<ArrayPart*>(idVarParts[i])->expressionList.size())
					{
						typeerror++;
						cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n      " << endl;
						return NULL;
					}
					idVarParts[i]->checkType();
					currentPtr = temp->getType();
					if (find_SymbolType(currentPtr) == INT_T || find_SymbolType(currentPtr) == BOOL_T || find_SymbolType(currentPtr) == REAL_T || find_SymbolType(currentPtr) == CHAR_T)
					{
						
						if (i != idVarParts.size() - 1)
						{
							typeerror++;
							
							cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       " << endl;
							return NULL;
						}
						else
						{
							return currentPtr;
						}
					}
				}
				else if (find_SymbolType(currentPtr)==RECORD_T)
				{
					Record* temp = dynamic_cast<Record*>(currentPtr);
					
					if (temp->getType(dynamic_cast<MemberPart*>(idVarParts[i])->id) == NULL)
					{
						typeerror++;
						cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       ." << endl;
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
					cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       ." << endl;
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
							
							cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       " << endl;
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
						
						cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       " << endl;
						return NULL;
				}
				else if (find_SymbolType(currentPtr)==ARRAY_T)
				{
					Array* temp = dynamic_cast<Array*>(currentPtr);
					if (temp->getDim() != dynamic_cast<ArrayPart*>(idVarParts[i])->expressionList.size())
					{
						typeerror++;
						cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       " << endl;
						return NULL;
					}
					idVarParts[i]->checkType();
					currentPtr = temp->getType();
					if (find_SymbolType(currentPtr) == INT_T || find_SymbolType(currentPtr) == BOOL_T || find_SymbolType(currentPtr) == REAL_T || find_SymbolType(currentPtr) == CHAR_T)
					{
						if (i != idVarParts.size() - 1)
						{
							typeerror++;
							cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       " << endl;
							return NULL;
						}
						else
						{
							return currentPtr;
						}
					}
				}
				else if (find_SymbolType(currentPtr)==RECORD_T)
				{
					Record* temp = dynamic_cast<Record*>(currentPtr);
					if (temp->getType(dynamic_cast<MemberPart*>(idVarParts[i])->id) == NULL)
					{
						typeerror++;
						cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       ." << endl;
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
								cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       " << endl;
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
						cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       ." << endl;
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
						cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       ." << endl;
					}
				}
				
			}
	
        expressionList[i]->checkType();
    }
}

TYPES MemberPart::checkType(){}

void CallProcedureStatement::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
	if (!SymbolTable::getInstance()->find_in_global(id))
	{
		typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n      " << endl;
		return;
	}	
	if (find_SymbolType(SymbolTable::getInstance()->getType(id)) == FUNCTION_T)
	{
		Function *temp = dynamic_cast<Function*>(SymbolTable::getInstance()->getType(id));
		if (temp->retParaNum() != expressionList.size())
		{
			typeerror++;
			cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n      " << endl;
			return;
		}
		for (int i = 0; i < expressionList.size(); i++)
		{
			if (find_SymbolType(temp->getParaType(i)) != expressionList[i]->checkType())
			{
				typeerror++;
				cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       " << endl;
				return;
			}
			if(temp->getParaType(i)->getReference())
			{
				if(dynamic_cast<Variable*>(expressionList[i])==NULL)
				{
					typeerror++;
					cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n      " << endl;
					return ;
				}
				else
				{
					if(!dynamic_cast<Variable*>(expressionList[i])->idVarParts.empty())
					{
					typeerror++;
					cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       " << endl;
					return ;
					}
				}
				
			}	
		}
	}	
	else
	{
		typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       " << endl;
	}
}

void IfStatement::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
	
    if (expression->checkType() != BOOL_T) 
	{
        typeerror++;
        cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       If" << endl; 
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

void CaseStatement::checkType()	
{
	
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    if (expression->checkType() != BOOL_T && expression->checkType() != INT_T && expression->checkType() != CHAR_T)
	{
        typeerror++;
        cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       Case" << endl;    
    }
    for (int i = 0; i < branchList.size(); i++)
	{
		branchNum++;
		flag=true;
		if (branchList[i]->checkType() != expression->checkType())
		{
			typeerror++;
			cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       Case" << endl;
		}
		flag=false;
    }
}

TYPES Branch::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
	TYPES temp = find_FD(constVariable.at(0));
	for (int i = 0; i < constVariable.size(); i++)
	{
		if (find_FD(constVariable.at(i)) != temp)//num
		{
			typeerror++;
			cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n      " << endl;
			return ERROR_T;
		}
	}
	statement->checkType();
	return temp;
}

void WhileStatement::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    if (expression->checkType() != BOOL_T)
	{
        typeerror++;
        cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n      " << endl;
    }
    statement->checkType();
}

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
        cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n      " << endl;                        
    }
}

void ForStatement::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
	if (!SymbolTable::getInstance()->find_in_global(id))
	{
		typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n     " << endl;
	}
    else if (find_SymbolType(SymbolTable::getInstance()->getType(id)) != INT_T || lower->checkType() != INT_T || upper->checkType() != INT_T)
	{
		typeerror++;
        cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n     " << endl;
    }
    statement->checkType();
}

void WriteStatement::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    for (int i = 0; i < expressionList.size(); i++)
	{
        expressionList[i]->checkType();
    }
}

TYPES BinaryExpression::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    if (left->checkType() != right->checkType())
	{  
		typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n     " << endl;
	}                  
    return BOOL_T;                                  
}

TYPES BinarySimpleExpression::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    if (addop == OR)		
	{                                       
        /*if (!(simpleExpression->checkType() == BOOL_T && term->checkType() == BOOL_T))
		{
            typeerror++;
            cout << "BinarySimpleExpression-OR-type_error" << endl;                         
        }*/
        return BOOL_T;                                      
    }
    else 
	{                                                 
        /*if (simpleExpression->checkType() == INT_T&& term->checkType() == INT_T)
		{
            return TYPES::INT_T;         
        }                                                 
        else if (simpleExpression->checkType() == TYPES::REAL_T && term->checkType() == TYPES::REAL_T)
		{
            return TYPES::REAL_T;           
        }                                                  
        else if (simpleExpresson->checkType() == TYPES::REAL_T && term->checkType() == INT_T)
		{
            return TYPES::REAL_T;                       
        }                                                
        else if (simpleExpression->checkType() == INT_T && term->checkType() == TYPES::REAL_T)
		{
            return TYPES::REAL_T;        
        }
        else
		{                       
            typeerror++;
            cout << "BinarysimpleExpression-PLUS/MINUS-type_error" << endl;      
            return TYPES::ERROR_T;            
		}*/
		if (simpleExpression->checkType() == REAL_T || term->checkType() == REAL_T)
			return REAL_T;
		else
			return INT_T;
    }
}

TYPES SignedTerm::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    return term->checkType();
}

TYPES BinaryTerm::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
	if (term->checkType() == ERROR_T || factor->checkType() == ERROR_T )
	{
        typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n    " << endl;
		return ERROR_T;
    }
	if (mulop == AND)		
	{                                       
		/*if (!(term->checkType() == BOOL_T && factor->checkType() == BOOL_T))
		{
		typeerror++;
		cout << "BinaryTerm-AND-type_error" << endl;                           
		}*/
		return BOOL_T;            
	}
    else if (mulop == INTDIVIDE || mulop == MOD)
	{                
        
        return INT_T;                            
    }
	else   
	{                                             
        /*if (term->checkType() == INT_T && factor->checkType() == INT_T)
		{
            return INT_T;  
        }                                                
        else if (term->checkType() == TYPES::REAL_T && factor->checkType() == TYPES::REAL_T)
		{
            return TYPES::REAL_T;        
        }                                                 
        else if (term->checkType() == TYPES::REAL_T && factor->checkType() == INT_T)
		{
            return TYPES::REAL_T;            
        }                                              
        else if (term->checkType() == INT_T && factor->checkType() == TYPES::REAL_T)
		{
            return TYPES::REAL_T;         
        }
        else 
		{                                           
            typeerror++;
            cout << "BinaryTerm-MULTIPLY/REALDIVIDE-type_error" << endl;     
            return TYPES::REAL_T;   
        }*/
		if (term->checkType() == REAL_T || factor->checkType() == REAL_T)
			return REAL_T;
		else
			return INT_T;
    }
}

TYPES FunctionCall::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
	
	Function* temp = dynamic_cast<Function*> (SymbolTable::getInstance()->getType(id));
	if (!SymbolTable::getInstance()->find_in_global(id))
	{
		typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       " << endl;
		return ERROR_T;
	}
	if (temp->getRetType() == NULL)
	{
		typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n  " << endl;
		return ERROR_T;
	}
	if (temp->retParaNum() != expressionList.size())
	{
		typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       " << endl;
	}
	for (int i = 0; i < expressionList.size(); i++)
	{
		
		/*if (find_SymbolType(temp->getParaType(i)) != expressionList[i]->checkType())
		{
			typeerror++;
			cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       " << endl;
		}*/
		expressionList[i]->checkType();
		if(temp->getParaType(i)->getReference())
		{
			if(dynamic_cast<Variable*>(expressionList[i])==NULL)
			{
				typeerror++;
				cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       " << endl;
			}
			else
			{
				if(!dynamic_cast<Variable*>(expressionList[i])->idVarParts.empty())
				{
				typeerror++;
				cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       " << endl;
				}
			}
			
		}
	}
    return find_SymbolType(temp->getRetType())
}

TYPES Num::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    if (num.find(".") != num.npos)
	{
        return REAL_T;
    }
    else
	{
		return INT_T; 
    }
}

TYPES Letters::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    return CHAR_T; 
}

TYPES Parenthesis::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    return expression->checkType();
}

TYPES Not::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
	if(factor->checkType() == BOOL_T)
    	return  BOOL_T ;
    else
    {
    	typeerror++;
		cout<<"\nError: semantic error "<<typeerror<<" at Line "<<lineNo<<":\n       Not�ڲ��������ʹ���" << endl;
		return ERROR_T;
	} 
}

TYPES Boolean::checkType()
{
	//cout<<typeid(this).name()<<"::checkType() begin"<<endl;
    return  BOOL_T;
}



