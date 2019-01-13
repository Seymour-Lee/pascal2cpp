%{
    #include <stdio.h>
    #include <string.h>
    #include "syntax.tab.h"
    
    int yyrowno=1;
       
    extern YYSTYPE yylval;
    extern YYLTYPE yylloc;
    
    //int yywrap(void);
%}

%option yylineno

comments1  "{"[^}]*"}"
comments2  "(*"[^*]*[*]+([^*)][^*]*[*]+)*[*]*")"


space  [' ']*
wrap   [\n]
wrap2  [\t]
wrap3  [\r]
letter [A-Za-z]
digit  [0-9]


id  {letter}({letter}|{digit})*

character [\']({letter}|[' '])[\']

num {digit}+(\.{digit}+)?(E[+\-]?{digit}+)?

relop \<\>|\<|\<\=|\>|\>\=
mulop \*|\/|div|mod|and
assignop \:\=
equal \=
positive \+
negative \-


%%

[Aa][Nn][Dd] {yylval.str=new std::string("and"); yyrowno+=yylval.str->size(); return MULOP;}
[Aa][Rr][Rr][Aa][Yy] {yylval.str=new std::string("array"); yyrowno+=yylval.str->size(); return ARRAY;}
[Bb][Ee][Gg][Ii][Nn] {yylval.str=new std::string("beign"); yyrowno+=yylval.str->size(); return BEIGN;}
[Bb][Oo][Oo][Ll][Ee][Aa][Nn] {yylval.str=new std::string("boolean"); yyrowno+=yylval.str->size(); return BOOLEAN;}
[Cc][Aa][Ss][Ee] {yyrowno+=yylval.str->size(); return CASE;}
[Cc][Oo][Nn][Ss][Tt] {yylval.str=new std::string("const"); yyrowno+=yylval.str->size(); return CONST;}
[Dd][Ii][Vv] {yylval.str=new std::string("div"); yyrowno+=yylval.str->size(); return MULOP;}
[Dd][Oo] {yylval.str=new std::string("do"); yyrowno+=yylval.str->size(); return DO;}
[Dd][Oo][Ww][Nn][Tt][Oo] {yylval.str=new std::string("downto"); yyrowno+=yylval.str->size(); return UPDOWN;}
[Ee][Ll][Ss][Ee] {yylval.str=new std::string("else"); yyrowno+=yylval.str->size(); return ELSE;}
[Ee][Nn][Dd] {yylval.str=new std::string("end"); yyrowno+=yylval.str->size(); return END;}
[Ff][Aa][Ll][Ss][Ee] {yylval.str=new std::string("false"); yyrowno+=yylval.str->size(); return FALSE;}
[Ff][Oo][Rr] {yylval.str=new std::string("for"); yyrowno+=yylval.str->size(); return FOR;}
[Ff][Uu][Nn][Cc][Tt][Ii][Oo][Nn] {yylval.str=new std::string("function"); yyrowno+=yylval.str->size(); return FUNCTION;}
[Ii][Ff] {yylval.str=new std::string("if"); yyrowno+=yylval.str->size(); return IF;}
[Ii][Nn][Tt][Ee][Gg][Ee][Rr] {yylval.str=new std::string("integer"); yyrowno+=yylval.str->size(); return INTEGER;}
[Mm][Oo][Dd] {yylval.str=new std::string("mod"); yyrowno+=yylval.str->size(); return MULOP;}
[Nn][Oo][Tt] {yylval.str=new std::string("not"); yyrowno+=yylval.str->size(); return NOT;}
[Oo][Ff] {yylval.str=new std::string("of"); yyrowno+=yylval.str->size(); return OF;}
[Oo][Rr] {yylval.str=new std::string("or"); yyrowno+=yylval.str->size(); return ADDOP;}
[Pp][Rr][Oo][Cc][Ee][Dd][Uu][Rr][Ee] {yylval.str=new std::string("procedure"); yyrowno+=yylval.str->size(); return PROCEDURE;}
[Pp][Rr][Oo][Gg][Rr][Aa][Mm] {yylval.str=new std::string("program");yyrowno+=yylval.str->size();  return PROGRAM;}
[Rr][Ee][Aa][Ll] {yylval.str=new std::string("real"); yyrowno+=yylval.str->size(); return REAL;}
[Rr][Ee][Cc][Oo][Rr][Dd] {yylval.str=new std::string("record"); yyrowno+=yylval.str->size(); return RECORD;}
[Rr][Ee][Pp][Ee][Aa][Tt] {yylval.str=new std::string("repeat"); yyrowno+=yylval.str->size(); return REPEAT;}
[Tt][Hh][Ee][Nn] {yylval.str=new std::string("then"); yyrowno+=yylval.str->size(); return THEN;}
[Tt][Oo] {yylval.str=new std::string("to"); yyrowno+=yylval.str->size(); return UPDOWN;}
[Tt][Rr][Uu][Ee] {yylval.str=new std::string("true"); yyrowno+=yylval.str->size(); return TRUE;}
[Tt][Yy][Pp][Ee] {yylval.str=new std::string("type"); yyrowno+=yylval.str->size(); return TYPE;}
[Uu][Nn][Tt][Ii][Ll] {yylval.str=new std::string("until"); yyrowno+=yylval.str->size(); return UNTIL;}
[Vv][Aa][Rr] {yylval.str=new std::string("var"); yyrowno+=yylval.str->size(); return VAR;}
[Ww][Hh][Ii][Ll][Ee] {yylval.str=new std::string("while"); yyrowno+=yylval.str->size(); return WHILE;}
[Cc][Hh][Aa][Rr] {yylval.str=new std::string("char"); yyrowno+=yylval.str->size(); return CHAR;}

[Rr][Ee][Aa][Dd]        {yylval.str=new std::string("read"); yyrowno+=yylval.str->size(); return READ;}
[Ww][Rr][Ii][Tt][Ee]    {yylval.str=new std::string("write"); yyrowno+=yylval.str->size(); return WRITE;}

{comments1} {yyrowno+=yyleng;}
{comments2} {yyrowno+=yyleng;}

{num}       {yylval.str=new std::string(yytext);
            yyrowno+=yyleng;
            return NUM;
            }
{character} {yylval.str=new std::string(yytext);
            yyrowno+=yyleng;
            return LETTER;
			}
{relop}     {yylval.str=new std::string(yytext);
            yyrowno+=yyleng;
            return RELOP;
            }
{mulop}     {yylval.str=new std::string(yytext);
            yyrowno+=yyleng;
            return MULOP;
            }
{assignop}  {yylval.str=new std::string(yytext);
            yyrowno+=yyleng;
            return ASSIGNOP;
            }
{id}        {yylval.str=new std::string(yytext);
            yyrowno+=yyleng;
            return ID;
            }
{equal}     {yylval.str=new std::string(yytext);
            yyrowno+=yyleng;
            return EQUAL;
            }
{positive}  {yylval.str=new std::string(yytext);
            yyrowno+=yyleng;
            return POSITIVE;
            }
{negative}  {yylval.str=new std::string(yytext);
            yyrowno+=yyleng;
            return NEGATIVE;
            }


[,]         {yylval.str=new std::string(yytext); yyrowno+=yyleng; return COMMA;}
[;]         {yylval.str=new std::string(yytext); yyrowno+=yyleng; return SEMICOLON;}
[.]         {yylval.str=new std::string(yytext); yyrowno+=yyleng; return DOT;}
[(]         {yylval.str=new std::string(yytext); yyrowno+=yyleng; return LPAREN;}
[)]         {yylval.str=new std::string(yytext); yyrowno+=yyleng; return RPAREN;}
[\[]        {yylval.str=new std::string(yytext); yyrowno+=yyleng; return LSQUARE;}
[\]]        {yylval.str=new std::string(yytext); yyrowno+=yyleng; return RSQUARE;}
[:]         {yylval.str=new std::string(yytext); yyrowno+=yyleng; return COLON;}
["\'"]      {yylval.str=new std::string(yytext); yyrowno+=yyleng; return SINGLEQUOTE;}
[.][.]      {yylval.str=new std::string(yytext); yyrowno+=yyleng; return DOTDOT;}

{space}     {yyrowno+=yyleng;}
{wrap}      {yyrowno=1;}
{wrap2}     {yyrowno+=4;}
{wrap3}     {yyrowno=1;}

.           {printf("\nError: lexical error \n       at Line %d, Row %d-%d:\n",yylineno,yyrowno-yyleng,yyrowno);
            printf("       unknown symbol: %s.\nPlease check the source file!\n",yytext);
            yyrowno+=yyleng;
            }


%%

int yywrap(void){
    return 1;
}

