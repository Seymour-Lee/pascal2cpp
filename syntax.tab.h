/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
/* Line 2058 of yacc.c  */
#line 3 "syntax.y"

#include "AbstractSyntaxtree.h"




/* Line 2058 of yacc.c  */
#line 53 "syntax.tab.h"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ASSIGNOP = 258,
     DOT = 259,
     DOTDOT = 260,
     COMMA = 261,
     SEMICOLON = 262,
     COLON = 263,
     LPAREN = 264,
     RPAREN = 265,
     LSQUARE = 266,
     RSQUARE = 267,
     PROGRAM = 268,
     VAR = 269,
     ARRAY = 270,
     OF = 271,
     RECORD = 272,
     END = 273,
     AND = 274,
     INTEGER = 275,
     REAL = 276,
     BOOLEAN = 277,
     FUNCTION = 278,
     PROCEDURE = 279,
     BEIGN = 280,
     IF = 281,
     THEN = 282,
     ELSE = 283,
     WHILE = 284,
     DO = 285,
     NOT = 286,
     READ = 287,
     WRITE = 288,
     TRUE = 289,
     FALSE = 290,
     CONST = 291,
     EQUAL = 292,
     POSITIVE = 293,
     NEGATIVE = 294,
     CHAR = 295,
     CASE = 296,
     REPEAT = 297,
     UNTIL = 298,
     FOR = 299,
     TYPE = 300,
     SINGLEQUOTE = 301,
     ID = 302,
     NUM = 303,
     DIGITS = 304,
     RELOP = 305,
     ADDOP = 306,
     MULOP = 307,
     LETTER = 308,
     UPDOWN = 309
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 124 "syntax.y"

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




/* Line 2058 of yacc.c  */
#line 198 "syntax.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
extern YYLTYPE yylloc;
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (Program **astRoot);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */
