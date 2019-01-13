/*pascal2c-2017.3.13 */

%code requires{
#include "AbstractSyntaxtree.h"


}

%code top{
#include "syntax.tab.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int yylex();

//void errok(const char * msg);

void yyerror(Program ** root, const char * s);

extern int yylineno;
extern int yyrowno;

extern char* yytext;
extern int yyleng;

}



%locations

%parse-param { Program **astRoot }

%token ASSIGNOP ":="

%token DOT "."

%token DOTDOT ".."

%token COMMA ","

%token SEMICOLON ";"

%token COLON ":"

%token LPAREN "("

%token RPAREN ")"

%token LSQUARE "["

%token RSQUARE "]"

%token PROGRAM "program"

%token VAR "var"

%token ARRAY "array"

%token OF "of"

%token RECORD "record"

%token END "end"

%token AND "and"

%token INTEGER "integer"

%token REAL "real"

%token BOOLEAN "boolean"

%token FUNCTION "function"

%token PROCEDURE "procedure"

%token BEIGN "beign"

%token IF "if"

%token THEN "then"

%token ELSE "else"

%token WHILE "while"

%token DO "do"

%token NOT "not"

%token READ "read"

%token WRITE "write"

%token TRUE "true"

%token FALSE "false"

%token CONST "const"

%token EQUAL "="

%token POSITIVE "+"

%token NEGATIVE "-"

%token CHAR "char"

%token CASE "case"

%token REPEAT "repeat"

%token UNTIL "until"

%token FOR "for"

%token TYPE "type"

%token SINGLEQUOTE "'"


%union {
    std::string * str;

    Program * program;
    ProgramHead * programHead;
    ProgramBody * programBody;
    std::vector<std::string> * identifierList;
    std::vector<ConstDeclaration *> * constDeclarations;

    ConstVariable * constVariable;
//    SignedIdentifierFD * signedIdentifierFD;
//    UnsignedIdentifierFD * unsignedIndentifierFD;
//    SignedNumFD * signedNumFD;
//    UnsignedNumFD * unsignedNumFD;
//    LetterFD * letterFD;
    std::vector<TypeDeclaration *> * typeDeclarations;
    Type * type;
    StandardType * standardType;
//    RecordType * recordType;
//    ArrayType * arrayType;
//    IntegerType * integerType;
//    RealType * realType;
//    BooleanType * booleanType;
//    CharType * charType;
    std::vector<VarDeclaration *> * varDeclarations;
    std::vector<Period *> * periods;
    Period * period;

    std::vector<SubprogramDeclaration *> * subprogramDeclarations;
    SubprogramDeclaration * subprogramDeclaration;
    SubprogramHead * subprogramHead;
    SubprogramBody * subprogramBody;
    std::vector<ParameterList *> * parameterLists;
    ParameterList * parameterList;
    std::vector<Statement *> * statements;
    Statement * statement;
    CompoundStatement * compoundStatement;
//    AssignStatement * assignStatement;
//    IfStatement * ifStatement;
//    CaseStatement * caseStatement;
//    WhileStatement * whileStatement;
//    RepeatStatement * repeatStatement;
//    ForStatement * forStatement;
//    ReadStatement * readStatement;
//    WriteStatement * writeStatement;
    Variable * variable;
    std::vector<IdVarPart *> * idVarParts;
    IdVarPart * idVarPart;
//    ArrayPart * arrayPart;
//    MemberPart * memberPart;
    std::vector<Branch *> * branchs;
    Branch * branch;
    std::vector<ConstVariable *> * constVariables;
//    KeyTo * keyTo;
//    KeyDownto * keyDownTo;
    CallProcedureStatement * callProcedureStatement;
    std::vector<Expression *> * expressions;
    BinaryExpression * binaryExpression;
    SimpleExpression * simpleExpression;
//    SignedTerm * signedTerm;
//    BinarySimpleExpression * binarySimpleExpression;
    BinaryTerm * binaryTerm;
    Factor * factor;
//    FunctionCall * functionCall;
//    Parenthesis * parenthesis;
//    Boolean * boolean;
//    Not * not;

    UnsignedConst * unsignedConst;
    Num * num;
    Letters * letters;


}

%token <str> ID NUM DIGITS RELOP ADDOP MULOP LETTER UPDOWN

%type <program> program

%type <programHead> program_head

%type <programBody> program_body

%type <identifierList> identifier_list

%type <constDeclarations> const_declarations const_declaration

%type <constVariable> const_variable;

//%type <signedIdentifierFD> const_variable
//
//%type <unsignedIdentifierFD> const_variable
//
//%type <signedNumFD> const_variable
//
//%type <unsignedNumFD> const_variable
//
//%type <letterFD> const_variable

%type <typeDeclarations> type_declarations type_declaration

//%type <recordType> type
//
//%type <arrayType> type
//
//%type <integerType> standard_type
//
//%type <realType> standard_type
//
//%type <booleanType> standard_type
//
//%type <charType> standard_type

%type <type> type

%type <standardType> standard_type

%type <varDeclarations> record_body var_declarations var_declaration

%type <periods> periods

%type <period> period


%type <subprogramDeclarations> subprogram_declarations

%type <subprogramDeclaration> subprogram_declaration

%type <subprogramHead> subprogram_head

%type <subprogramBody> subprogram_body

%type <parameterLists> formal_parameter parameter_lists

%type <parameterList> value_parameter var_parameter parameter_list

%type <compoundStatement> compound_statement

%type <statements> statement_list

%type <statement> statement else_part

//%type <assignStatement> statement
//
//%type <ifStatement> statement
//
//%type <caseStatement> statement
//
//%type <whileStatement> statement
//
//%type <repeatStatement> statement
//
//%type <forStatement> statement
//
//%type <readStatement> statement
//
//%type <writeStatement> statement

%type <variable> variable

%type <idVarParts> id_varparts

%type <idVarPart> id_varpart

//%type <arrayPart> id_varpart
//
//%type <memberPart> id_varpart

%type <branchs> case_body branch_list

%type <branch> branch

%type <constVariables> const_list

//%type <keyTo> updown
//
//%type <keyDownTo> updown

%type <callProcedureStatement> call_procedure_statement

%type <expressions> expression_list

%type <binaryExpression> expression

%type <simpleExpression> simple_expression

//%type <signedTerm> simple_expression
//
//%type <binarySimpleExpression> simple_expression

%type <binaryTerm> term

%type <factor> factor

//%type <functionCall> factor
//
//%type <parenthesis> factor
//
//%type <boolean> factor
//
//%type <not> factor
//
%type <unsignedConst> unsign_const

//%type <identifier> factor
//
//%type <num> factor
//
//%type <letters> factor







%%
program : program_head program_body DOT{
    $$ = new Program;
    $$->head = $1;
    $$->body = $2;
	$$->lineNo=yylineno;
    *astRoot = $$;
    //printf("program -> program_head program_body DOT\n");
}
| error program_body DOT{
	yyerrok;
	$$ = new Program;
	$$->head = NULL;
	$$->body = $2;
	$$->lineNo=yylineno;
	*astRoot = $$;
}

program_head : PROGRAM ID LPAREN identifier_list RPAREN SEMICOLON{
    $$ = new ProgramHead;
    $$->id = *$2;
    delete $2;
    $$->identifierList = *$4;
    delete $4;
	$$->lineNo=yylineno;
    //printf("program_head : PROGRAM ID LPAREN identifier_list RPAREN SEMICOLON\n");
}

program_body : const_declarations type_declarations var_declarations subprogram_declarations compound_statement{
    $$ = new ProgramBody;
    $$->constDeclarations = *$1;
    delete $1;
    $$->typeDeclarations = *$2;
    delete $2;
    $$->varDeclarations = *$3;
    delete $3;
    $$->subprogramDeclarations = *$4;
    delete $4;
    $$->compoundStatement = $5;
	$$->lineNo=yylineno;
    //printf("program_body : const_declarations type_declarations var_declarations subprogram_declarations compound_statement\n");
}

identifier_list : identifier_list COMMA ID{
    $1->push_back(*$3);
    delete $3;
    $$ = $1;
    //printf("identifier_list : identifier_list COMMA ID\n");
}
| ID{
    $$ = new std::vector<std::string>();
    $$->push_back(*$1);
    delete $1;
    //printf("identifier_list : ID\n");
}

const_declarations : CONST const_declaration SEMICOLON{
    $$ = $2;
    //printf("const_declarations : CONST const_declaration SEMICOLON\n");
}
| {
    $$ = new std::vector<ConstDeclaration *>();
    //printf("const_declarations : \n");
}

const_declaration : const_declaration SEMICOLON ID EQUAL const_variable{
    $$ = $1;
    ConstDeclaration * temp = new ConstDeclaration;
    temp->id = *$3;
    delete $3;
    temp->constVariable = $5;
	temp->lineNo=yylineno;
    $$->push_back(temp);
    //printf("const_declaration : const_declaration SEMICOLON ID EQUAL const_variable\n");
}
| ID EQUAL const_variable{
    $$ = new std::vector<ConstDeclaration *>();
    ConstDeclaration * temp = new ConstDeclaration;
    temp->id = *$1;
    temp->constVariable = $3;
	temp->lineNo=yylineno;
    $$->push_back(temp);
    //printf("const_declaration : ID EQUAL const_variable\n");
}

const_variable : POSITIVE ID{
    SignedIdentifierFD * temp = new SignedIdentifierFD;
    temp->sign = true;
    temp->id = *$2;
	temp->lineNo=yylineno;
    delete $2;
    $$=temp;
    //printf("const_variable : POSITIVE ID\n");
}
| NEGATIVE ID{
    SignedIdentifierFD * temp = new SignedIdentifierFD;
    temp->sign = false;
    temp->id = *$2;
	temp->lineNo=yylineno;
    delete $2;
    $$=temp;
    //printf("const_variable : NEGATIVE ID\n");
}
| ID {
    UnsignedIdentifierFD * temp =new UnsignedIdentifierFD;
    temp->id = *$1;
	temp->lineNo=yylineno;
    delete $1;
    $$=temp;
    //printf("const_variable : ID\n");
}
| POSITIVE NUM{
    SignedNumFD * temp = new SignedNumFD;
    temp->sign = true;
    temp->num = *$2;
	temp->lineNo=yylineno;
    delete $2;
    $$=temp;
    //printf("const_variable : POSITIVE NUM\n");
}
| NEGATIVE NUM{
    SignedNumFD * temp = new SignedNumFD;
    temp->sign = false;
    temp->num = *$2;
	temp->lineNo=yylineno;
    delete $2;
    $$=temp;
    //printf("const_variable : NEGATIVE NUM\n");
}
| NUM{
    UnsignedNumFD * temp = new UnsignedNumFD;
    temp->num = *$1;
	temp->lineNo=yylineno;
    delete $1;
    $$=temp;
    //printf("const_variable : NUM\n");
}
| LETTER{
    LettersFD * temp = new LettersFD;
    temp->letters = *$1;
	temp->lineNo=yylineno;
    delete $1;
    $$=temp;
    //printf("const_variable : LETTER \n");
}

type_declarations : TYPE type_declaration SEMICOLON{
    $$ = $2;
    //printf("type_declarations : TYPE type_declaration SEMICOLON\n");
}
| {
    $$ = new std::vector<TypeDeclaration *>();
    //printf("type_declarations : \n");
}

type_declaration : type_declaration SEMICOLON ID EQUAL type{
    $$ = $1;
    TypeDeclaration * temp = new TypeDeclaration;
    temp->id = *$3;
    delete $3;
    temp->type = $5;
	temp->lineNo=yylineno;
    $$->push_back(temp);
    //printf("type_declaration : type_declaration SEMICOLON ID EQUAL type\n");
}
| ID EQUAL type{
    $$ = new std::vector<TypeDeclaration *>();
    TypeDeclaration * temp = new TypeDeclaration;
    temp->id = *$1;
    delete $1;
    temp->type = $3;
	temp->lineNo=yylineno;
    $$->push_back(temp);
    //printf("type_declaration : ID EQUAL type\n");
}

type : standard_type{
    $$ = $1;
    //printf("type : standard\n");
}
| RECORD record_body END{
    RecordType * temp = new RecordType;
    temp->varDeclarations = *$2;
	temp->lineNo=yylineno;
    delete $2;
    $$=temp;
    //printf("type : RECORD record_body END\n");
}
| ARRAY LSQUARE periods RSQUARE OF type{
    ArrayType * temp = new ArrayType;
    temp->periods = *$3;
	temp->lineNo=yylineno;
    delete $3;
    temp->type = $6;
    $$=temp;
    //printf("type : ARRAY LSQUARE periods RSQUARE OF type\n");
}

standard_type : INTEGER{
    $$ = new IntegerType;
	//$$->lineNo=yylineno;
    //printf("standard_type : INTEGER\n");
}
| REAL{
    $$ = new RealType;
	//$$->lineNo=yylineno;
    //printf("standard_type : REAL\n");
}
| BOOLEAN{
    $$ = new BooleanType;
	//$$->lineNo=yylineno;
    //printf("standard_type : BOOLEAN\n");
}
| CHAR{
    $$ = new CharType;
	//$$->lineNo=yylineno;
    //printf("standard_type : CHAR\n");
}

record_body : var_declaration{
    $$ = $1;
    //printf("record_body : var_declaration\n");
}
| {
    $$ = new std::vector<VarDeclaration *>();
    //printf("record_body : \n");
}

periods : periods COMMA period{
    $$ = $1;
    $$->push_back($3);
    //printf("periods : periods COMMA period\n");
}
| period{
    $$ = new std::vector<Period *>();
    $$->push_back($1);
    //printf("periods : period\n");
}

period : const_variable DOTDOT const_variable{
    $$ = new Period;
    $$->lower = $1;
    $$->upper = $3;
	$$->lineNo=yylineno;
    //printf("period : const_variable DOTDOT const_variable\n");
}

var_declarations : VAR var_declaration SEMICOLON{
    $$ = $2;
    //printf("var_declarations : VAR var_declaration SEMICOLON\n");
}
| {
    $$ = new std::vector<VarDeclaration *>();
    //printf("var_declarations : \n");
}

var_declaration : var_declaration SEMICOLON identifier_list COLON type{
    $$ = $1;
    VarDeclaration * temp = new VarDeclaration;
    temp->identifierList = *$3;
    delete $3;
    temp->type = $5;
	temp->lineNo=yylineno;
    $$->push_back(temp);
    //printf("var_declaration : var_declaration SEMICOLON identifier_list COLON type\n");
}
| identifier_list COLON type{
    $$ = new std::vector<VarDeclaration *>();
    VarDeclaration * temp = new VarDeclaration;
    temp->identifierList = *$1;
    delete $1;
    temp->type = $3;
	temp->lineNo=yylineno;
    $$->push_back(temp);
    //printf("var_declaration : identifier_list COLON type\n");
}

subprogram_declarations : subprogram_declarations subprogram_declaration SEMICOLON{
    $1->push_back($2);
    $$ = $1;
    //printf("subprogram_declarations : subprogram_declarations subprogram_declaration SEMICOLON\n");
}
| {
    $$ = new std::vector<SubprogramDeclaration*>();
    //printf("subprogram_declarations : \n");
}

subprogram_declaration : subprogram_head subprogram_body{
    $$ = new SubprogramDeclaration;
    $$->head = $1;
    $$->body = $2;
	$$->lineNo=yylineno;
    //printf("subprogram_declaration : subprogram_head program_body\n");
}

subprogram_head : FUNCTION ID formal_parameter COLON standard_type SEMICOLON{
    $$ = new SubprogramHead;
    $$->id = *$2;
    delete $2;
    $$->parameterLists = *$3;
    delete $3;
    $$->ret = $5;
	$$->lineNo=yylineno;
    //printf("subprogram_head : FUNCTION ID formal_parameter COLON standard_type SEMICOLON\n");
}
| PROCEDURE ID formal_parameter SEMICOLON{
    $$ = new SubprogramHead;
    $$->id = *$2;
    delete $2;
    $$->parameterLists = *$3;
    delete $3;
    $$->ret = NULL;
	$$->lineNo=yylineno;
    //printf("subprogram_head : PROCEDURE ID formal_parameter SEMICOLON\n");
}

subprogram_body : const_declarations type_declarations var_declarations compound_statement{
    $$ = new SubprogramBody;
    $$->constDeclarations = *$1;
    delete $1;
    $$->typeDeclarations = *$2;
    delete $2;
    $$->varDeclarations = *$3;
    delete $3;
    $$->compoundStatement = $4;
	$$->lineNo=yylineno;
    //printf("program_body : const_declarations type_declarations var_declarations subprogram_declarations compound_statement\n");
}

formal_parameter : LPAREN parameter_lists RPAREN{
    $$ = $2;
    //printf("formal_parameter : LPAREN parameter_lists RPAREN\n");
}
| {
    $$ = new std::vector<ParameterList*>();
    //printf("formal_parameter : \n");
}

parameter_lists : parameter_lists SEMICOLON parameter_list{
    $1->push_back($3);
    $$ = $1;
    //printf("parameter_lists : parameter_lists SEMICOLON parameter_list\n");
}
| parameter_list{
    $$ = new std::vector<ParameterList*>();
    $$->push_back($1);
    //printf("parameter_lists : parameter_list\n");
}

parameter_list : var_parameter{
    $$ = $1;
    //printf("parameter_list : var_parameter\n");
}
| value_parameter{
    $$ = $1;
	$$->byReference = false;
    //printf("parameter_list : value_parameter\n");
}

var_parameter : VAR value_parameter{
    $$ = $2;
	$$->byReference = true;
    //printf("var_parameter : VAR value_parameter\n");
}

value_parameter : identifier_list COLON standard_type{
    $$ = new ParameterList;
    $$->identifierList = *$1;
    delete $1;
    $$->type = $3;
	$$->lineNo=yylineno;
    //printf("value_parameter : identifier_list COLON standard_type\n");
}

compound_statement : BEIGN statement_list END{
    CompoundStatement * temp = new CompoundStatement;
    temp->statementList = *$2;
    delete $2;
	temp->lineNo=yylineno;
    $$=temp;
    //printf("compound_statement : BEIGN statement_list END\n");
}

statement_list : statement_list SEMICOLON statement{
    $1->push_back($3);
    $$ = $1;
    //printf("statement_list : statement_list SEMICOLON statement\n");
}
| statement{
    $$ = new std::vector<Statement*>();
    $$->push_back($1);
    //printf("statement_list : statement\n");
}

statement : variable ASSIGNOP expression{
    AssignStatement * temp = new AssignStatement;
    temp->variable = $1;
    temp->expression = $3;
	temp->lineNo=yylineno;
    $$=temp;
    //printf("statement : variable ASSIGNOP expression\n");
}
| variable EQUAL expression{
    AssignStatement * temp = new AssignStatement;
    temp->variable = $1;
    temp->expression = $3;
	temp->lineNo=yylineno;
    $$=temp;
    //printf("statement : variable EQUAL expression\n");
}
| call_procedure_statement{
    $$ = $1;
    //printf("statement : call_procedure_statement\n");
}
| compound_statement{
    $$ = $1;
    //printf("statement : compound_statement\n");
}
| IF expression THEN statement else_part{
    IfStatement * temp = new IfStatement;
    temp->expression = $2;
    temp->thenStatement = $4;
    temp->elseStatement = $5;
	temp->lineNo=yylineno;
    $$=temp;
    //printf("statement : IF expression THEN statement else_part\n");
}
| CASE expression OF case_body END{
    CaseStatement * temp = new CaseStatement;
    temp->expression = $2;
    temp->branchList = *$4;
    delete $4;
	temp->lineNo=yylineno;
    $$=temp;
    //printf("statement : CASE expression OF case_body END\n");
}
| WHILE expression DO statement{
    WhileStatement * temp = new WhileStatement;
    temp->expression = $2;
    temp->statement = $4;
	temp->lineNo=yylineno;
    $$=temp;
    //printf("statement : WHILE expression DO statement\n");
}
| REPEAT statement_list UNTIL expression{
    RepeatStatement * temp = new RepeatStatement;
    temp->statementList = *$2;
    delete $2;
    temp->expression = $4;
	temp->lineNo=yylineno;
    $$=temp;
    //printf("statement : REPEAT statement_list UNTIL expression\n");
}
| FOR ID ASSIGNOP expression UPDOWN expression DO statement{
    ForStatement * temp = new ForStatement;
    temp->id=*$2;
    delete $2;
    temp->lower = $4;
    if(*$5 == "to")
    temp->updown = ForStatement::TO;
    else if(*$5 == "downto")
    temp->updown = ForStatement::DOWNTO;
    delete $5;
    temp->upper = $6;
    temp->statement = $8;
	temp->lineNo=yylineno;
    $$=temp;
    //printf("statement : FOR ID ASSIGNOP expression UPDOWN expression DO statement\n");
}
| FOR ID EQUAL expression UPDOWN expression DO statement{
    ForStatement * temp = new ForStatement;
    temp->lower = $4;
    if(*$5 == "to")
    temp->updown = ForStatement::TO;
    else if(*$5 == "downto")
    temp->updown = ForStatement::DOWNTO;
    delete $5;
    temp->upper = $6;
    temp->statement = $8;
	temp->lineNo=yylineno;
    $$=temp;
    //printf("statement : FOR ID EQUAL expression UPDOWN expression DO statement\n");
}
| READ LPAREN identifier_list RPAREN{
    ReadStatement * temp = new ReadStatement;
    temp->identifierList = *$3;
	delete $3;
	temp->lineNo=yylineno;
    $$=temp;
    //printf("statement : READ LPAREN identifier_list RPAREN\n");
}
| WRITE LPAREN expression_list RPAREN{
    WriteStatement * temp = new WriteStatement;
    temp->expressionList = *$3;
	delete $3;
	temp->lineNo=yylineno;
    $$=temp;
    //printf("statement : WRITE LPAREN expression_list RPAREN\n");
}
| {
    Statement *temp = NULL;
    $$ = temp;
    //printf("statement : \n");
}

variable : ID id_varparts{
    $$ = new Variable;
    $$->id = *$1;
    delete $1;
    $$->idVarParts = *$2;
    delete $2;
	$$->lineNo=yylineno;
    //printf("variable : ID id_varparts\n");
}

id_varparts : id_varparts id_varpart{
    $$ = $1;
    $$->push_back($2);
    //printf("id_varparts : id_varparts id_varpart\n");
}
| {
    $$ = new std::vector<IdVarPart*>();
    //printf("id_varparts : \n");
}

id_varpart : LSQUARE expression_list RSQUARE{
    ArrayPart * temp = new ArrayPart;
    temp->expressionList = *$2;
    delete $2;
	temp->lineNo=yylineno;
    $$=temp;
    //printf("id_varpart : LSQUARE expression_list RSQUARE\n");
}
| DOT ID{
    MemberPart * temp =new MemberPart;
    temp->id = *$2;
    delete $2;
	temp->lineNo=yylineno;
    $$=temp;
    //printf("id_varpart : DOT ID\n");
}

else_part : ELSE statement{
    $$ = $2;
    //printf("else_part : ELSE statement\n");
}
| {
    Statement *temp = NULL;
    $$ = temp;
    //printf("else_part : \n");
}

case_body : branch_list{
    $$ = $1;
    //printf("case_body : branch_list\n");
}
| {
    $$ = new std::vector<Branch*>();
    //printf("case_body : \n");
}

branch_list : branch_list SEMICOLON branch{
    $1->push_back($3);
    $$ = $1;
    //printf("branch_list : branch_list SEMICOLON branch\n");
}
| branch{
    $$ = new std::vector<Branch*>();
    $$->push_back($1);
    //printf("branch_list : branch\n");
}

branch : const_list COLON statement{
    $$ = new Branch;
    $$->constVariable = *$1;
    delete $1;
    $$->statement = $3;
	$$->lineNo=yylineno;
    //printf("branch : const_list COLON statement\n");
}

const_list : const_list COMMA const_variable{
    $1->push_back($3);
    $$ = $1;
    //printf("const_list : const_list COMMA const_variable\n");
}
| const_variable{
    $$ = new std::vector<ConstVariable*>();
    $$->push_back($1);
    //printf("const_list : const_variable\n");
}

call_procedure_statement : ID{
    $$ = new CallProcedureStatement;
    $$->id = *$1;
    delete $1;
	$$->lineNo=yylineno;
    //printf("call_procedure_statement : ID\n");
}
| ID LPAREN expression_list RPAREN{
    $$ = new CallProcedureStatement;
    $$->id = *$1;
    delete $1;
    $$->expressionList = *$3;
    delete $3;
	$$->lineNo=yylineno;
    //printf("call_procedure_statement : ID LPAREN expression_list RPAREN\n");
}

expression_list : expression_list COMMA expression{
    $1->push_back($3);
    $$ = $1;
    //printf("expression_list : expression_list COMMA expression\n");
}
| expression{
    $$ = new std::vector<Expression*>();
    $$->push_back($1);
    //printf("expression_list : expression\n");
}

expression : simple_expression RELOP simple_expression{
    $$ = new BinaryExpression;
    $$->left = $1;
    if(*$2 == "<>")
    $$->relop = BinaryExpression::NOTEQUAL;
    else if(*$2 == "<")
    $$->relop = BinaryExpression::LESSTHAN;
    else if(*$2 == "<=")
    $$->relop = BinaryExpression::LESSEQUAL;
    else if(*$2 == ">")
    $$->relop = BinaryExpression::GREATERTHAN;
    else if(*$2 == ">=")
    $$->relop = BinaryExpression::GREATEREQUAL;
    delete $2;
    $$->right = $3;
	$$->lineNo=yylineno;
    //printf("expression : simple_expression RELOP simple_expression\n");
}
| simple_expression EQUAL simple_expression{
    $$ = new BinaryExpression;
    $$->left = $1;
    $$->relop = BinaryExpression::EQUAL;
    //delete $2;
    $$->right = $3;
	$$->lineNo=yylineno;
    //printf("expression : simple_expression EQUAL simple_expression\n");
}
| simple_expression{
    $$ = (BinaryExpression*)$1;
    //printf("expression : simple_expression\n");
}

simple_expression : term{
    $$ = $1;
    //printf("simple_expression : term\n");
}
| POSITIVE term{
    SignedTerm * temp = new SignedTerm;
    temp->sign = true;
    temp->term = $2;
	temp->lineNo=yylineno;
    $$=temp;
    //printf("simple_expression : POSITIVE term\n");
}
| NEGATIVE term{
    SignedTerm * temp = new SignedTerm;
    temp->sign = false;
    temp->term = $2;
	temp->lineNo=yylineno;
    $$=temp;
    //printf("simple_expression : NEGATIVE term\n");
}
| simple_expression ADDOP term{
    BinarySimpleExpression * temp = new BinarySimpleExpression;
    temp->simpleExpression = $1;
    temp->addop = BinarySimpleExpression::OR;
    delete $2;
    temp->term = $3;
	temp->lineNo=yylineno;
    $$=temp;
    //printf("simple_expression : simple_expression ADDOP term\n");
}
| simple_expression POSITIVE term{
    BinarySimpleExpression * temp = new BinarySimpleExpression;
    temp->simpleExpression = $1;
    temp->addop = BinarySimpleExpression::PLUS;
    //delete $2;
    temp->term = $3;
	temp->lineNo=yylineno;
    $$=temp;
    //printf("simple_expression : simple_expression POSITIVE term\n");
}
| simple_expression NEGATIVE term{
    BinarySimpleExpression * temp = new BinarySimpleExpression;
    temp->simpleExpression = $1;
    temp->addop = BinarySimpleExpression::MINUS;
    //delete $2;
    temp->term = $3;
	temp->lineNo=yylineno;
    $$=temp;
    //printf("simple_expression : simple_expression NEGATIVE term\n");
}

term : term MULOP factor{
    BinaryTerm * temp = new BinaryTerm;
    temp->term = $1;
    if(*$2 == "*")
    temp->mulop = BinaryTerm::MULTIPLY;
    else if(*$2 == "/")
    temp->mulop = BinaryTerm::REALDIVIDE;
    else if(*$2 == "div")
    temp->mulop = BinaryTerm::INTDIVIDE;
    else if(*$2 == "mod")
    temp->mulop = BinaryTerm::MOD;
    else if(*$2 == "and")
    temp->mulop = BinaryTerm::AND;
    delete $2;
    temp->factor = $3;
	temp->lineNo=yylineno;
    $$=temp;
    //printf("term : term MULOP factor\n");
}
| factor{
    $$ = (BinaryTerm*)$1;
    //printf("term : factor\n");
}

factor : unsign_const{
    $$ = $1;
    //printf("factor : unsign_const\n");
}
| variable{
    $$ = $1;
    //printf("factor : variable\n");
}| ID LPAREN expression_list RPAREN{
    FunctionCall * temp = new FunctionCall;
    temp->id = *$1;
    delete $1;
    temp->expressionList = *$3;
    delete $3;
	temp->lineNo=yylineno;
    $$=temp;
    //printf("factor : ID LPAREN expression_list RPAREN\n");
}
| LPAREN expression RPAREN{
    Parenthesis * temp = new Parenthesis;
    temp->expression = $2;
	temp->lineNo=yylineno;
    $$=temp;
    //printf("factor : LPAREN expression RPAREN\n");
}
| NOT factor{
    Not * temp = new Not;
    temp->factor = $2;
	temp->lineNo=yylineno;
    $$=temp;
    //printf("factor : NOT factor\n");
}
| TRUE{//
    Boolean * temp = new Boolean;
    temp->value = true;
	temp->lineNo=yylineno;
    $$=temp;
    //printf("factor : TRUE\n");
}
| FALSE{//
    Boolean * temp = new Boolean;
    temp->value = false;
	temp->lineNo=yylineno;
    $$=temp;
    //printf("factor : FALSE\n");
}

unsign_const : NUM{
    Num * temp = new Num;
    temp->num = *$1;
    delete $1;
	temp->lineNo=yylineno;
    $$=temp;
    //printf("unsign_const : NUM\n");
}
| LETTER{
    Letters * temp = new Letters;
    temp->letters = *$1;
    delete $1;
	temp->lineNo=yylineno;
    $$=temp;
    //printf("unsign_const : LETTER\n");
}


%%

void yyerror(Program ** root,const char * msg){
	printf("\nError: %s \n       at Line %d,Row %d-%d:\n",msg,yylineno,yyrowno-yyleng,yyrowno);
    printf("       when encounted %s.\nPlease check the source file!" ,yytext);
}

//void errok(const char * msg){
//	//printf("\nError: syntax error on %s \n       at Line %d,Row %d-%d:\n",msg,yylineno,yyrowno-yyleng,yyrowno);
//    //printf("       when encounted %s.\nPlease check the source file!" ,yytext);
//}
