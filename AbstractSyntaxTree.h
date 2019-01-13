#ifndef AbstractSyntaxTree_h
#define AbstractSyntaxTree_h

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>

#include "SymbolTable.h"

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

class Program {
public:
    ProgramHead* head;
    ProgramBody* body;
    void checkType();
    void printCodes(char* outName);
    Program();
    ~Program();
	int lineNo;
};

class ProgramHead {
public:
    std::string id;
    std::vector<std::string> identifierList;
    void printCodes();
    ProgramHead();
	int lineNo;
};

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

class ConstVariable {
public:
    virtual int checkType()=0;
    virtual void printCodes()=0;
};

class UnsignedIdentifierFD : public ConstVariable {//For Declaration
public:
    std::string id;
    UnsignedIdentifierFD();
    virtual int checkType(){return 0;}
    virtual void printCodes();
	int lineNo;
};

class SignedIdentifierFD : public ConstVariable {
public:
    bool sign;//True:+ False:-
    std::string id;
    SignedIdentifierFD();
    virtual int checkType(){return 0;}
    virtual void printCodes();
	int lineNo;
};

class UnsignedNumFD : public ConstVariable {
public:
    std::string num;
    virtual int checkType();
    virtual void printCodes();
    UnsignedNumFD();
	int lineNo;
};

class SignedNumFD : public ConstVariable {
public:
    bool sign;//True:+ False:-
    std::string num;
    virtual int checkType();
    virtual void printCodes();
    SignedNumFD();
	int lineNo;
};

class LettersFD : public ConstVariable {
public:
    std::string letters;
    virtual int checkType();
    virtual void printCodes();
    LettersFD();
	int lineNo;
};

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

class Type {
public:
    virtual void printCodes() = 0;
    virtual void checkType() = 0;
};

class StandardType : public Type {};

class RecordType : public Type {
public:
    std::vector<VarDeclaration*> varDeclarations;
    virtual void checkType();
    virtual void printCodes();
    RecordType();
    ~RecordType();
	int lineNo;
};

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

class IntegerType : public StandardType {
public:
    virtual void checkType();
    virtual void printCodes();
};

class RealType : public StandardType {
public:
    virtual void checkType();
    virtual void printCodes();
};

class BooleanType : public StandardType {
public:
    virtual void checkType();
    virtual void printCodes();
};

class CharType : public StandardType {
public:
    virtual void checkType();
    virtual void printCodes();
};

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

class SubprogramHead {
public:
    std::string id;
    std::vector<ParameterList*> parameterLists;
    StandardType* ret;
    bool checkType();
    void printCodes();
    SubprogramHead();
    ~SubprogramHead();
	int lineNo;
};

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

class Statement {
public:
    virtual void checkType()=0;
    virtual void printCodes()=0;
};

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

class CompoundStatement : public Statement {
public:
    std::vector<Statement*> statementList;
    virtual void checkType();
    virtual void printCodes();
    CompoundStatement();
    ~CompoundStatement();
	int lineNo;
};

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

class ReadStatement : public Statement {
public:
    std::vector<std::string> identifierList;
    ReadStatement();
    virtual void checkType(){}
    virtual void printCodes();
	int lineNo;
};

class WriteStatement : public Statement {
public:
    std::vector<Expression*> expressionList;
    virtual void checkType();
    virtual void printCodes();
    WriteStatement();
    ~WriteStatement();
	int lineNo;
};

class Expression {
public:
    virtual TYPES checkType() = 0;
    virtual void printCodes() = 0;
};

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

class SimpleExpression : public Expression {
public:
    virtual TYPES checkType()=0;
    virtual void printCodes()=0;
};

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

class Term : public SimpleExpression {
public:
    virtual TYPES checkType()=0;
    virtual void printCodes()=0;
};

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

class Factor : public Term {
public:
    virtual TYPES checkType()=0;
    virtual void printCodes()=0;
};

class UnsignedConst : public Factor {
public:
    virtual TYPES checkType()=0;
    virtual void printCodes()=0;
};

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

class IdVarPart {
public:
    virtual TYPES checkType() = 0;
    virtual void printCodes() = 0;
};

class ArrayPart : public IdVarPart {
public:
    std::vector <Expression*> expressionList;
    virtual TYPES checkType();
    virtual void printCodes();
    ArrayPart();
    ~ArrayPart();
	int lineNo;
};

class MemberPart : public IdVarPart {
public:
    std::string id;
    virtual TYPES checkType();
    virtual void printCodes();
    MemberPart();
	int lineNo;
};

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

class Parenthesis : public Factor {
public:
    Expression* expression;
    virtual TYPES checkType();
    virtual void printCodes();
    Parenthesis();
    ~Parenthesis();
	int lineNo;
};

class Not : public Factor {
public:
    Factor* factor;
    virtual TYPES checkType();
    virtual void printCodes();
    Not();
    ~Not();
	int lineNo;
};

class Boolean : public Factor {
public:
    bool value;
    virtual TYPES checkType();
    virtual void printCodes();
    Boolean();
	int lineNo;
};

class Num : public UnsignedConst {
public:
    std::string num;
    virtual TYPES checkType();
    virtual void printCodes();
    Num();
	int lineNo;
};

class Letters : public UnsignedConst {
public:
    std::string letters;
    virtual TYPES checkType();
    virtual void printCodes();
    Letters();
	int lineNo;
};

#endif /* AbstractSyntaxTree_h */

