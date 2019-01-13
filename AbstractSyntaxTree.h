//
//  <文件名>：AbstractSyntaxTree.h
//  <文件内容>：该文件包含语法树各结点的类定义，为整个程序的串联数据结构
//
//  <创建日期>：06/03/2017

#ifndef AbstractSyntaxTree_h
#define AbstractSyntaxTree_h

//  包含头文件
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>

#include "SymbolTable.h"

//  语法树各结点的类声明 
class Program;
class ProgramHead;
class ProgramBody;
class ConstDeclaration;
class ConstVariable;
class UnsignedIdentifierFD;
class SignedIdentifierFD;
class UnsignedNumFD;
class SignedNumFD;
class LettersFD;
class TypeDeclaration;
class VarDeclaration;
class Type;
class StandardType;
class RecordType;
class ArrayType;
class Period;
class IntegerType;
class RealType;
class BooleanType;
class CharType;
class SubprogramDeclaration;
class SubprogramHead;
class SubprogramBody;
class ParameterList;
class Statement;
class AssignStatement;
class CallProcedureStatement;
class CompoundStatement;
class IfStatement;
class CaseStatement;
class Branch;
class WhileStatement;
class RepeatStatement;
class ForStatement;
class ReadStatement;
class WriteStatement;
class Expression;
class BinaryExpression;
class SimpleExpression;
class BinarySimpleExpression;
class Term;
class SignedTerm;
class BinaryTerm;
class Factor;
class UnsignedConst;
class Variable;
class IdVarPart;
class ArrayPart;
class MemberPart;
class FunctionCall;
class Parenthesis;
class Not;
class Boolean;
class Num;
class Letters;

//
//  <枚举名>：TYPES
//  <枚举变量说明>：枚举所需类型，方便使用 
enum TYPES {
    CONST_T,
    INT_T,
    REAL_T,
    BOOL_T,
    CHAR_T,
    ARRAY_T,
    RECORD_T,
    FUNCTION_T,//function or procedure
    ERROR_T
};

//
//  <类名>：Program
//  <类功能说明>：作为语法树的根结点 
class Program {
public:
    ProgramHead* head;
    ProgramBody* body;
    void checkType();
    void printCodes(char* outName);
    Program();
    ~Program();
	int lineNo;//记录行号，下同 
};

//
//  <类名>：ProgramHead
//  <类功能说明>：作为语法树的内部结点 
class ProgramHead {
public:
    std::string id;
    std::vector<std::string> identifierList;
    void printCodes();
    ProgramHead();
	int lineNo;
};

//
//  <类名>：ProgramBody 
//  <类功能说明>：作为语法树的内部结点 
class ProgramBody {
public:
    std::vector<ConstDeclaration*> constDeclarations;
    std::vector<TypeDeclaration*> typeDeclarations;
    std::vector<VarDeclaration*> varDeclarations;
    std::vector<SubprogramDeclaration*> subprogramDeclarations;
    CompoundStatement* compoundStatement;
    void checkType();
    void printCodes();
    ProgramBody();
    ~ProgramBody();
	int lineNo;
};

//
//  <类名>：ConstDeclaration
//  <类功能说明>：作为语法树的内部结点 
class ConstDeclaration {
public:
    std::string id;
    ConstVariable* constVariable;
    void checkType();
    void printCodes();
    ConstDeclaration();
    ~ConstDeclaration();
	int lineNo;
};

//
//  <类名>：ConstVariable
//  <类功能说明>：作为语法树的内部结点 
class ConstVariable {
public:
    virtual int checkType()=0;
    virtual void printCodes()=0;
};

//
//  <类名>：UnsignedIdentifierFD
//  <类功能说明>：ConstVariable类的子类，作为语法树的内部结点
class UnsignedIdentifierFD : public ConstVariable {//For Declaration
public:
    std::string id;
    UnsignedIdentifierFD();
    virtual int checkType(){return 0;}
    virtual void printCodes();
	int lineNo;
};

//
//  <类名>：SignedIdentifierFD
//  <类功能说明>：ConstVariable类的子类，作为语法树的内部结点
class SignedIdentifierFD : public ConstVariable {
public:
    bool sign;//True:+ False:-
    std::string id;
    SignedIdentifierFD();
    virtual int checkType(){return 0;}
    virtual void printCodes();
	int lineNo;
};

//
//  <类名>：UnsignedNumFD
//  <类功能说明>：ConstVariable类的子类，作为语法树的内部结点
class UnsignedNumFD : public ConstVariable {
public:
    std::string num;
    virtual int checkType();
    virtual void printCodes();
    UnsignedNumFD();
	int lineNo;
};

//
//  <类名>：SignedNumFD
//  <类功能说明>：ConstVariable类的子类，作为语法树的内部结点
class SignedNumFD : public ConstVariable {
public:
    bool sign;//True:+ False:-
    std::string num;
    virtual int checkType();
    virtual void printCodes();
    SignedNumFD();
	int lineNo;
};

//
//  <类名>：LettersFD
//  <类功能说明>：ConstVariable类的子类，作为语法树的内部结点
class LettersFD : public ConstVariable {
public:
    std::string letters;
    virtual int checkType();
    virtual void printCodes();
    LettersFD();
	int lineNo;
};

//
//  <类名>：TypeDeclaration
//  <类功能说明>：作为语法树的内部结点
class TypeDeclaration {
public:
    std::string id;
    Type* type;
    void checkType();
    void printCodes();
    TypeDeclaration();
    ~TypeDeclaration();
	int lineNo;
};

//
//  <类名>：VarDeclaration
//  <类功能说明>：作为语法树的内部结点
class VarDeclaration {
public:
    std::vector<std::string> identifierList;
    Type* type;
    void checkType();
    void printCodes();
    VarDeclaration();
    ~VarDeclaration();
	int lineNo;
};

//
//  <类名>：Type
//  <类功能说明>：作为语法树的内部结点
class Type {
public:
    virtual void printCodes() = 0;
    virtual void checkType() = 0;
};

//
//  <类名>：StandardType
//  <类功能说明>：Type类的子类，作为语法树的内部结点
class StandardType : public Type {};

//
//  <类名>：RecordType
//  <类功能说明>：Type类的子类，作为语法树的内部结点
class RecordType : public Type {
public:
    std::vector<VarDeclaration*> varDeclarations;
    virtual void checkType();
    virtual void printCodes();
    RecordType();
    ~RecordType();
	int lineNo;
};

//
//  <类名>：ArrayType
//  <类功能说明>：Type类的子类，作为语法树的内部结点
class ArrayType : public Type {
public:
    std::vector<Period*> periods;
    Type* type;
    virtual void checkType();
    virtual void printCodes();
    void printType();
    void printPeriods();
    ArrayType();
    ~ArrayType();
	int lineNo;
};

//
//  <类名>：Period
//  <类功能说明>：作为语法树的内部结点
class Period {
public:
    ConstVariable* lower;
    ConstVariable* upper;
    void checkType();
    void printCodes();
    Period();
    ~Period();
	int lineNo;
};

//
//  <类名>：IntegerType
//  <类功能说明>：StandardType类的子类，作为语法树的内部结点
class IntegerType : public StandardType {
public:
    virtual void checkType();
    virtual void printCodes();
};

//
//  <类名>：RealType
//  <类功能说明>：StandardType类的子类，作为语法树的内部结点
class RealType : public StandardType {
public:
    virtual void checkType();
    virtual void printCodes();
};

//
//  <类名>：BooleanType
//  <类功能说明>：StandardType类的子类，作为语法树的内部结点
class BooleanType : public StandardType {
public:
    virtual void checkType();
    virtual void printCodes();
};

//
//  <类名>：CharType
//  <类功能说明>：StandardType类的子类，作为语法树的内部结点
class CharType : public StandardType {
public:
    virtual void checkType();
    virtual void printCodes();
};

//
//  <类名>：SubprogramDeclaration
//  <类功能说明>：作为语法树的内部结点
class SubprogramDeclaration {
public:
    SubprogramHead* head;
    SubprogramBody* body;
    void checkType();
    void printCodes();
    SubprogramDeclaration();
    ~SubprogramDeclaration();
	int lineNo;
};

//
//  <类名>：SubprogramHead
//  <类功能说明>：作为语法树的内部结点
class SubprogramHead {
public:
    std::string id;
    std::vector<ParameterList*> parameterLists;
    StandardType* ret;//返回值类型 
    bool checkType();
    void printCodes();
    SubprogramHead();
    ~SubprogramHead();
	int lineNo;
};

//
//  <类名>：SubprogramBody
//  <类功能说明>：作为语法树的内部结点
class SubprogramBody {
public:
    std::vector<ConstDeclaration*> constDeclarations;
    std::vector<TypeDeclaration*> typeDeclarations;
    std::vector<VarDeclaration*> varDeclarations;
    std::vector<SubprogramDeclaration*> subprogramDeclarations;
    CompoundStatement* compoundStatement;
    void checkType();
    void printCodes();
    SubprogramBody();
    ~SubprogramBody();
	int lineNo;
};

//
//  <类名>：ParameterList
//  <类功能说明>：作为语法树的内部结点
class ParameterList {
public:
    bool byReference;//True:by reference False:by value
    std::vector<std::string> identifierList;
    StandardType* type;
    void printCodes();
    ParameterList();
    ~ParameterList();
	int lineNo;
};

//
//  <类名>：Statement
//  <类功能说明>：作为语法树的内部结点
class Statement {
public:
    virtual void checkType()=0;
    virtual void printCodes()=0;
};

//
//  <类名>：AssignStatement
//  <类功能说明>：Statement类的子类，作为语法树的内部结点
class AssignStatement : public Statement {
public:
    Variable* variable;
    Expression* expression;
    void func(Variable* variable,Expression* expression);
    virtual void checkType();
    virtual void printCodes();
    AssignStatement();
    ~AssignStatement();
	int lineNo;
};

//
//  <类名>：CallProcedureStatement
//  <类功能说明>：Statement类的子类，作为语法树的内部结点
class CallProcedureStatement : public Statement {
public:
    std::string id;
    std::vector<Expression*> expressionList;
    virtual void checkType();
    virtual void printCodes();
    CallProcedureStatement();
    ~CallProcedureStatement();
	int lineNo;
};

//
//  <类名>：CompoundStatement
//  <类功能说明>：Statement类的子类，作为语法树的内部结点
class CompoundStatement : public Statement {
public:
    std::vector<Statement*> statementList;
    virtual void checkType();
    virtual void printCodes();
    CompoundStatement();
    ~CompoundStatement();
	int lineNo;
};

//
//  <类名>：IfStatement
//  <类功能说明>：Statement类的子类，作为语法树的内部结点
class IfStatement : public Statement {
public:
    Expression* expression;
    Statement* thenStatement;
    Statement* elseStatement;
    virtual void checkType();
    virtual void printCodes();
    IfStatement();
    ~IfStatement();
	int lineNo;
};

//
//  <类名>：CaseStatement
//  <类功能说明>：Statement类的子类，作为语法树的内部结点
class CaseStatement : public Statement {
public:
    Expression* expression;
    std::vector<Branch*> branchList;
    virtual void checkType();
    virtual void printCodes();
    CaseStatement();
    ~CaseStatement();
	int lineNo;
};

//
//  <类名>：Branch
//  <类功能说明>：作为语法树的内部结点
class Branch {
public:
    std::vector<ConstVariable*> constVariable;
    Statement* statement;
    virtual TYPES checkType();
    virtual void printCodes();
    Branch();
    ~Branch();
	int lineNo;
};

//
//  <类名>：WhileStatement
//  <类功能说明>：Statement类的子类，作为语法树的内部结点
class WhileStatement : public Statement {
public:
    Expression* expression;
    Statement* statement;
    virtual void checkType();
    virtual void printCodes();
    WhileStatement();
    ~WhileStatement();
	int lineNo;
};

//
//  <类名>：RepeatStatement
//  <类功能说明>：Statement类的子类，作为语法树的内部结点
class RepeatStatement : public Statement {
public:
    std::vector<Statement*> statementList;
    Expression* expression;
    virtual void checkType();
    virtual void printCodes();
    RepeatStatement();
    ~RepeatStatement();
	int lineNo;
};

//
//  <类名>：ForStatement
//  <类功能说明>：Statement类的子类，作为语法树的内部结点
class ForStatement : public Statement {
public:
    std::string id;
    Expression* lower;
    enum Updown {
        TO,
        DOWNTO
    } updown;
    Expression* upper;
    Statement* statement;
    virtual void checkType();
    virtual void printCodes();
    ForStatement();
    ~ForStatement();
	int lineNo;
};

//
//  <类名>：ReadStatement
//  <类功能说明>：Statement类的子类，作为语法树的内部结点
class ReadStatement : public Statement {
public:
    std::vector<std::string> identifierList;
    ReadStatement();
    virtual void checkType(){}
    virtual void printCodes();
	int lineNo;
};

//
//  <类名>：WriteStatement
//  <类功能说明>：Statement类的子类，作为语法树的内部结点
class WriteStatement : public Statement {
public:
    std::vector<Expression*> expressionList;
    virtual void checkType();
    virtual void printCodes();
    WriteStatement();
    ~WriteStatement();
	int lineNo;
};

//
//  <类名>：Expression
//  <类功能说明>：作为语法树的内部结点
class Expression {
public:
    virtual TYPES checkType() = 0;
    virtual void printCodes() = 0;
};

//
//  <类名>：BinaryExpression
//  <类功能说明>：Expression类的子类，作为语法树的内部结点
class BinaryExpression : public Expression {
public:
    SimpleExpression* left;
    enum Relop {
        EQUAL, //=
        NOTEQUAL, //!=
        LESSTHAN, //<
        LESSEQUAL, //<=
        GREATERTHAN, //>
        GREATEREQUAL //>=
    } relop;
    SimpleExpression* right;
    virtual TYPES checkType();
    virtual void printCodes();
    BinaryExpression();
    ~BinaryExpression();
	int lineNo;
};

//
//  <类名>：SimpleExpression
//  <类功能说明>：Expression类的子类，作为语法树的内部结点
class SimpleExpression : public Expression {
public:
    virtual TYPES checkType()=0;
    virtual void printCodes()=0;
};

//
//  <类名>：BinarySimpleExpression
//  <类功能说明>：SimpleExpression类的子类，作为语法树的内部结点
class BinarySimpleExpression : public SimpleExpression {
public:
    SimpleExpression* simpleExpression;
    enum Addop {
        PLUS, //+
        MINUS, //-
        OR //or
    } addop;
    Term* term;
    virtual TYPES checkType();
    virtual void printCodes();
    BinarySimpleExpression();
    ~BinarySimpleExpression();
	int lineNo;
};

//
//  <类名>：Term
//  <类功能说明>：SimpleExpression类的子类，作为语法树的内部结点
class Term : public SimpleExpression {
public:
    virtual TYPES checkType()=0;
    virtual void printCodes()=0;
};

//
//  <类名>：SignedTerm
//  <类功能说明>：SimpleExpression类的子类，作为语法树的内部结点
class SignedTerm : public SimpleExpression {
public:
    bool sign;//True:+ False:-
    Term* term;
    virtual TYPES checkType();
    virtual void printCodes();
    SignedTerm();
    ~SignedTerm();
	int lineNo;
};

//
//  <类名>：BinaryTerm
//  <类功能说明>：Term类的子类，作为语法树的内部结点
class BinaryTerm : public Term {
public:
    Term* term;
    enum Mulop {
        MULTIPLY,
        REALDIVIDE, // /
        INTDIVIDE, // div
        MOD, // mod
        AND // and
    } mulop;
    Factor* factor;
    virtual TYPES checkType();
    virtual void printCodes();
    BinaryTerm();
    ~BinaryTerm();
	int lineNo;
};

//
//  <类名>：BinaryTerm
//  <类功能说明>：Term类的子类，作为语法树的内部结点
class Factor : public Term {
public:
    virtual TYPES checkType()=0;
    virtual void printCodes()=0;
};

//
//  <类名>：UnsignedConst
//  <类功能说明>：Factor类的子类，作为语法树的内部结点
class UnsignedConst : public Factor {
public:
    virtual TYPES checkType()=0;
    virtual void printCodes()=0;
};

//
//  <类名>：Variable
//  <类功能说明>：Factor类的子类，作为语法树的内部结点
class Variable : public Factor{
public:
    std::string id;
    std::vector<IdVarPart*> idVarParts;
    virtual TYPES checkType();
    virtual void printCodes();
    SymbolType* varRetType();
    Variable();
    ~Variable();
	int lineNo;
};

//
//  <类名>：IdVarPart
//  <类功能说明>：作为语法树的内部结点
class IdVarPart {
public:
    virtual TYPES checkType() = 0;
    virtual void printCodes() = 0;
};

//
//  <类名>：ArrayPart
//  <类功能说明>：IdVarPart类的子类，作为语法树的内部结点
class ArrayPart : public IdVarPart {
public:
    std::vector <Expression*> expressionList;
    virtual TYPES checkType();
    virtual void printCodes();
    ArrayPart();
    ~ArrayPart();
	int lineNo;
};

//
//  <类名>：MemberPart
//  <类功能说明>：IdVarPart类的子类，作为语法树的内部结点
class MemberPart : public IdVarPart {
public:
    std::string id;
    virtual TYPES checkType();
    virtual void printCodes();
    MemberPart();
	int lineNo;
};

//
//  <类名>：FunctionCall
//  <类功能说明>：Factor类的子类，作为语法树的内部结点
class FunctionCall : public Factor {
public:
    std::string id;
    std::vector<Expression*> expressionList;
    virtual TYPES checkType();
    virtual void printCodes();
    FunctionCall();
    ~FunctionCall();
	int lineNo;
};

//
//  <类名>：Parenthesis
//  <类功能说明>：Factor类的子类，作为语法树的内部结点
class Parenthesis : public Factor {
public:
    Expression* expression;
    virtual TYPES checkType();
    virtual void printCodes();
    Parenthesis();
    ~Parenthesis();
	int lineNo;
};

//
//  <类名>：Not
//  <类功能说明>：Factor类的子类，作为语法树的内部结点
class Not : public Factor {
public:
    Factor* factor;
    virtual TYPES checkType();
    virtual void printCodes();
    Not();
    ~Not();
	int lineNo;
};

//
//  <类名>：Boolean
//  <类功能说明>：Factor类的子类，作为语法树的内部结点
class Boolean : public Factor {
public:
    bool value;
    virtual TYPES checkType();
    virtual void printCodes();
    Boolean();
	int lineNo;
};

//
//  <类名>：Num
//  <类功能说明>：UnsignedConst类的子类，作为语法树的内部结点 
class Num : public UnsignedConst {
public:
    std::string num;
    virtual TYPES checkType();
    virtual void printCodes();
    Num();
	int lineNo;
};

//
//  <类名>：Letters 
//  <类功能说明>：UnsignedConst类的子类，作为语法树的内部结点 
class Letters : public UnsignedConst {
public:
    std::string letters;
    virtual TYPES checkType();
    virtual void printCodes();
    Letters();
	int lineNo;
};

#endif /* AbstractSyntaxTree_h */

