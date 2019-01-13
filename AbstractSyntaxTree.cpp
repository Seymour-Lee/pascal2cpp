//
//  <文件名>：AbstractSyntaxTree.cpp 
//  <文件内容>：该文件包含语法树各结点类的构造和析构函数
//
//  <创建日期>：06/03/2017

//  包含头文件
#include "AbstractSyntaxTree.h"

Program::Program() {
    head = NULL;
    body = NULL;
}

Program::~Program() {
    delete head;
    delete body;
}

ProgramHead::ProgramHead() {
    id = "";
    identifierList.clear();
}

ProgramBody::ProgramBody() {
    constDeclarations.clear();
    typeDeclarations.clear();
    varDeclarations.clear();
    subprogramDeclarations.clear();
    compoundStatement = NULL;
}

ProgramBody::~ProgramBody() {
    std::vector<ConstDeclaration*>::iterator iter;
    for (iter = constDeclarations.begin(); iter != constDeclarations.end(); iter++) {
        delete *iter;
    }
    constDeclarations.clear();
    
    std::vector<TypeDeclaration*>::iterator iter2;
    for (iter2 = typeDeclarations.begin(); iter2 != typeDeclarations.end(); iter2++) {
        delete *iter2;
    }
    typeDeclarations.clear();
    
    std::vector<VarDeclaration*>::iterator iter3;
    for (iter3 = varDeclarations.begin(); iter3 != varDeclarations.end(); iter3++) {
        delete *iter3;
    }
    varDeclarations.clear();
    
    std::vector<SubprogramDeclaration*>::iterator iter4;
    for (iter4 = subprogramDeclarations.begin(); iter4 != subprogramDeclarations.end(); iter4++) {
        delete *iter4;
    }
    subprogramDeclarations.clear();
    
    delete compoundStatement;
}

ConstDeclaration::ConstDeclaration() {
    id = "";
    constVariable = NULL;
}

ConstDeclaration::~ConstDeclaration() {
    delete constVariable;
}

UnsignedIdentifierFD::UnsignedIdentifierFD() {
    id = "";
}

SignedIdentifierFD::SignedIdentifierFD() {
    sign = false;
    id = "";
}

UnsignedNumFD::UnsignedNumFD() {
    num = "";
}

SignedNumFD::SignedNumFD() {
    sign = false;
    num = "";
}

LettersFD::LettersFD() {
    letters = "";
}

TypeDeclaration::TypeDeclaration() {
    id = "";
    type = NULL;
}

TypeDeclaration::~TypeDeclaration() {
    delete type;
}

VarDeclaration::VarDeclaration() {
    identifierList.clear();
    type = NULL;
}

VarDeclaration::~VarDeclaration() {
    delete type;
}

RecordType::RecordType() {
    varDeclarations.clear();
}

RecordType::~RecordType() {
    std::vector<VarDeclaration*>::iterator iter;
    for (iter = varDeclarations.begin(); iter != varDeclarations.end(); iter++) {
        delete *iter;
    }
    varDeclarations.clear();
}

ArrayType::ArrayType() {
    periods.clear();
    type = NULL;
}

ArrayType::~ArrayType() {
    std::vector<Period*>::iterator iter;
    for (iter = periods.begin(); iter != periods.end(); iter++) {
        delete *iter;
    }
    periods.clear();
    
    delete type;
}

Period::Period() {
    lower = NULL;
    upper = NULL;
}

Period::~Period() {
    delete lower;
    delete upper;
}

SubprogramDeclaration::SubprogramDeclaration() {
    head = NULL;
    body = NULL;
}

SubprogramDeclaration::~SubprogramDeclaration() {
    delete head;
    delete body;
}

SubprogramHead::SubprogramHead() {
    id = "";
    parameterLists.clear();
    ret = NULL;
}

SubprogramHead::~SubprogramHead() {
    std::vector<ParameterList*>::iterator iter;
    for (iter = parameterLists.begin(); iter != parameterLists.end(); iter++) {
        delete *iter;
    }
    parameterLists.clear();
    
    delete ret;
}

SubprogramBody::SubprogramBody() {
    constDeclarations.clear();
    typeDeclarations.clear();
    varDeclarations.clear();
    subprogramDeclarations.clear();
    compoundStatement = NULL;
}

SubprogramBody::~SubprogramBody() {
    std::vector<ConstDeclaration*>::iterator iter;
    for (iter = constDeclarations.begin(); iter != constDeclarations.end(); iter++) {
        delete *iter;
    }
    constDeclarations.clear();
    
    std::vector<TypeDeclaration*>::iterator iter2;
    for (iter2 = typeDeclarations.begin(); iter2 != typeDeclarations.end(); iter2++) {
        delete *iter2;
    }
    typeDeclarations.clear();
    
    std::vector<VarDeclaration*>::iterator iter3;
    for (iter3 = varDeclarations.begin(); iter3 != varDeclarations.end(); iter3++) {
        delete *iter3;
    }
    varDeclarations.clear();
    
    std::vector<SubprogramDeclaration*>::iterator iter4;
    for (iter4 = subprogramDeclarations.begin(); iter4 != subprogramDeclarations.end(); iter4++) {
        delete *iter4;
    }
    subprogramDeclarations.clear();
    
    delete compoundStatement;
}

ParameterList::ParameterList() {
	byReference = false;
    identifierList.clear();
    type = NULL;
}

ParameterList::~ParameterList() {
    delete type;
}

AssignStatement::AssignStatement() {
    variable = NULL;
    expression = NULL;
}

AssignStatement::~AssignStatement() {
    delete variable;
    delete expression;
}

CallProcedureStatement::CallProcedureStatement() {
    id = "";
    expressionList.clear();
}

CallProcedureStatement::~CallProcedureStatement() {
    std::vector<Expression*>::iterator iter;
    for (iter = expressionList.begin(); iter != expressionList.end(); iter++) {
        delete *iter;
    }
    expressionList.clear();
}

CompoundStatement::CompoundStatement() {
    statementList.clear();
}

CompoundStatement::~CompoundStatement() {
    std::vector<Statement*>::iterator iter;
    for (iter = statementList.begin(); iter != statementList.end(); iter++) {
        delete *iter;
    }
    statementList.clear();
}

IfStatement::IfStatement() {
    expression = NULL;
    thenStatement = NULL;
    elseStatement = NULL;
}

IfStatement::~IfStatement() {
    delete expression;
    delete thenStatement;
    delete elseStatement;
}

CaseStatement::CaseStatement() {
    expression = NULL;
    branchList.clear();
}

CaseStatement::~CaseStatement() {
    std::vector<Branch*>::iterator iter;
    for (iter = branchList.begin(); iter != branchList.end(); iter++) {
        delete *iter;
    }
    branchList.clear();
    
    delete expression;
}

Branch::Branch() {
    constVariable.clear();
    statement = NULL;
}

Branch::~Branch() {
    std::vector<ConstVariable*>::iterator iter;
    for (iter = constVariable.begin(); iter != constVariable.end(); iter++) {
        delete *iter;
    }
    constVariable.clear();
    
    delete statement;
}

WhileStatement::WhileStatement() {
    expression = NULL;
    statement = NULL;
}

WhileStatement::~WhileStatement() {
    delete expression;
    delete statement;
}

RepeatStatement::RepeatStatement() {
    statementList.clear();
    expression = NULL;
}

RepeatStatement::~RepeatStatement() {
    std::vector<Statement*>::iterator iter;
    for (iter = statementList.begin(); iter != statementList.end(); iter++) {
        delete *iter;
    }
    statementList.clear();
    
    delete expression;
}

ForStatement::ForStatement() {
    id = "";
    lower = NULL;
    upper = NULL;
    statement = NULL;
}

ForStatement::~ForStatement() {
    delete lower;
    delete upper;
    delete statement;
}

ReadStatement::ReadStatement() {
    identifierList.clear();
}

WriteStatement::WriteStatement() {
    expressionList.clear();
}

WriteStatement::~WriteStatement() {
    std::vector<Expression*>::iterator iter;
    for (iter = expressionList.begin(); iter != expressionList.end(); iter++) {
        delete *iter;
    }
    expressionList.clear();
}

BinaryExpression::BinaryExpression() {
    left = NULL;
    right = NULL;
}

BinaryExpression::~BinaryExpression() {
    delete left;
    delete right;
}

BinarySimpleExpression::BinarySimpleExpression() {
    simpleExpression = NULL;
    term = NULL;
}

BinarySimpleExpression::~BinarySimpleExpression() {
    delete simpleExpression;
    delete term;
}

SignedTerm::SignedTerm() {
    sign = false;
    term = NULL;
}

SignedTerm::~SignedTerm() {
    delete term;
}

BinaryTerm::BinaryTerm() {
    term = NULL;
    factor = NULL;
}

BinaryTerm::~BinaryTerm() {
    delete term;
    delete factor;
}

Variable::Variable() {
    id = "";
    idVarParts.clear();
}

Variable::~Variable() {
    std::vector<IdVarPart*>::iterator iter;
    for (iter = idVarParts.begin(); iter != idVarParts.end(); iter++) {
        delete *iter;
    }
    idVarParts.clear();
}

ArrayPart::ArrayPart() {
    expressionList.clear();
}

ArrayPart::~ArrayPart() {
    std::vector<Expression*>::iterator iter;
    for (iter = expressionList.begin(); iter != expressionList.end(); iter++) {
        delete *iter;
    }
    expressionList.clear();
}

MemberPart::MemberPart() {
    id = "";
}

FunctionCall::FunctionCall() {
    id = "";
    expressionList.clear();
}

FunctionCall::~FunctionCall() {
    std::vector<Expression*>::iterator iter;
    for (iter = expressionList.begin(); iter != expressionList.end(); iter++) {
        delete *iter;
    }
    expressionList.clear();
}

Parenthesis::Parenthesis() {
    expression = NULL;
}

Parenthesis::~Parenthesis() {
    delete expression;
}

Not ::Not() {
    factor = NULL;
}

Not ::~Not() {
    delete factor;
}

Boolean::Boolean() {
    value = false;
}

Num::Num() {
    num = "";
}

Letters::Letters() {
    letters = "";
}

