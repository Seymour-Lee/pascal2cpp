/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* "%code top" blocks.  */
/* Line 349 of yacc.c  */
#line 9 "syntax.y"

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



/* Line 349 of yacc.c  */
#line 86 "syntax.tab.c"



/* Copy the first part of user declarations.  */

/* Line 371 of yacc.c  */
#line 93 "syntax.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
/* Line 387 of yacc.c  */
#line 3 "syntax.y"

#include "AbstractSyntaxtree.h"




/* Line 387 of yacc.c  */
#line 129 "syntax.tab.c"

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
/* Line 387 of yacc.c  */
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




/* Line 387 of yacc.c  */
#line 274 "syntax.tab.c"
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



/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 315 "syntax.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   221

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNRULES -- Number of states.  */
#define YYNSTATES  225

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    18,    24,    28,    30,    34,
      35,    41,    45,    48,    51,    53,    56,    59,    61,    63,
      67,    68,    74,    78,    80,    84,    91,    93,    95,    97,
      99,   101,   102,   106,   108,   112,   116,   117,   123,   127,
     131,   132,   135,   142,   147,   152,   156,   157,   161,   163,
     165,   167,   170,   174,   178,   182,   184,   188,   192,   194,
     196,   202,   208,   213,   218,   227,   236,   241,   246,   247,
     250,   253,   254,   258,   261,   264,   265,   267,   268,   272,
     274,   278,   282,   284,   286,   291,   295,   297,   301,   305,
     307,   309,   312,   315,   319,   323,   327,   331,   333,   335,
     337,   342,   346,   349,   351,   353,   355
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      56,     0,    -1,    57,    58,     4,    -1,     1,    58,     4,
      -1,    13,    47,     9,    59,    10,     7,    -1,    60,    63,
      70,    72,    81,    -1,    59,     6,    47,    -1,    47,    -1,
      36,    61,     7,    -1,    -1,    61,     7,    47,    37,    62,
      -1,    47,    37,    62,    -1,    38,    47,    -1,    39,    47,
      -1,    47,    -1,    38,    48,    -1,    39,    48,    -1,    48,
      -1,    53,    -1,    45,    64,     7,    -1,    -1,    64,     7,
      47,    37,    65,    -1,    47,    37,    65,    -1,    66,    -1,
      17,    67,    18,    -1,    15,    11,    68,    12,    16,    65,
      -1,    20,    -1,    21,    -1,    22,    -1,    40,    -1,    71,
      -1,    -1,    68,     6,    69,    -1,    69,    -1,    62,     5,
      62,    -1,    14,    71,     7,    -1,    -1,    71,     7,    59,
       8,    65,    -1,    59,     8,    65,    -1,    72,    73,     7,
      -1,    -1,    74,    75,    -1,    23,    47,    76,     8,    66,
       7,    -1,    24,    47,    76,     7,    -1,    60,    63,    70,
      81,    -1,     9,    77,    10,    -1,    -1,    77,     7,    78,
      -1,    78,    -1,    79,    -1,    80,    -1,    14,    80,    -1,
      59,     8,    66,    -1,    25,    82,    18,    -1,    82,     7,
      83,    -1,    83,    -1,    84,     3,    94,    -1,    84,    37,
      94,    -1,    92,    -1,    81,    -1,    26,    94,    27,    83,
      87,    -1,    41,    94,    16,    88,    18,    -1,    29,    94,
      30,    83,    -1,    42,    82,    43,    94,    -1,    44,    47,
       3,    94,    54,    94,    30,    83,    -1,    44,    47,    37,
      94,    54,    94,    30,    83,    -1,    32,     9,    59,    10,
      -1,    33,     9,    93,    10,    -1,    -1,    47,    85,    -1,
      85,    86,    -1,    -1,    11,    93,    12,    -1,     4,    47,
      -1,    28,    83,    -1,    -1,    89,    -1,    -1,    89,     7,
      90,    -1,    90,    -1,    91,     8,    83,    -1,    91,     6,
      62,    -1,    62,    -1,    47,    -1,    47,     9,    93,    10,
      -1,    93,     6,    94,    -1,    94,    -1,    95,    50,    95,
      -1,    95,    37,    95,    -1,    95,    -1,    96,    -1,    38,
      96,    -1,    39,    96,    -1,    95,    51,    96,    -1,    95,
      38,    96,    -1,    95,    39,    96,    -1,    96,    52,    97,
      -1,    97,    -1,    98,    -1,    84,    -1,    47,     9,    93,
      10,    -1,     9,    94,    10,    -1,    31,    97,    -1,    34,
      -1,    35,    -1,    48,    -1,    53,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   341,   341,   349,   358,   368,   383,   389,   396,   400,
     405,   415,   425,   434,   443,   451,   460,   469,   477,   486,
     490,   495,   505,   516,   520,   528,   538,   543,   548,   553,
     559,   563,   568,   573,   579,   587,   591,   596,   606,   617,
     622,   627,   635,   645,   656,   669,   673,   678,   683,   689,
     693,   699,   705,   714,   723,   728,   734,   742,   750,   754,
     758,   767,   776,   784,   793,   809,   823,   831,   839,   845,
     855,   860,   865,   873,   882,   886,   892,   896,   901,   906,
     912,   921,   926,   932,   939,   949,   954,   960,   978,   987,
     992,   996,  1004,  1012,  1022,  1032,  1043,  1062,  1067,  1071,
    1074,  1084,  1091,  1098,  1105,  1113,  1121
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\":=\"", "\".\"", "\"..\"", "\",\"",
  "\";\"", "\":\"", "\"(\"", "\")\"", "\"[\"", "\"]\"", "\"program\"",
  "\"var\"", "\"array\"", "\"of\"", "\"record\"", "\"end\"", "\"and\"",
  "\"integer\"", "\"real\"", "\"boolean\"", "\"function\"",
  "\"procedure\"", "\"beign\"", "\"if\"", "\"then\"", "\"else\"",
  "\"while\"", "\"do\"", "\"not\"", "\"read\"", "\"write\"", "\"true\"",
  "\"false\"", "\"const\"", "\"=\"", "\"+\"", "\"-\"", "\"char\"",
  "\"case\"", "\"repeat\"", "\"until\"", "\"for\"", "\"type\"", "\"'\"",
  "ID", "NUM", "DIGITS", "RELOP", "ADDOP", "MULOP", "LETTER", "UPDOWN",
  "$accept", "program", "program_head", "program_body", "identifier_list",
  "const_declarations", "const_declaration", "const_variable",
  "type_declarations", "type_declaration", "type", "standard_type",
  "record_body", "periods", "period", "var_declarations",
  "var_declaration", "subprogram_declarations", "subprogram_declaration",
  "subprogram_head", "subprogram_body", "formal_parameter",
  "parameter_lists", "parameter_list", "var_parameter", "value_parameter",
  "compound_statement", "statement_list", "statement", "variable",
  "id_varparts", "id_varpart", "else_part", "case_body", "branch_list",
  "branch", "const_list", "call_procedure_statement", "expression_list",
  "expression", "simple_expression", "term", "factor", "unsign_const", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    56,    57,    58,    59,    59,    60,    60,
      61,    61,    62,    62,    62,    62,    62,    62,    62,    63,
      63,    64,    64,    65,    65,    65,    66,    66,    66,    66,
      67,    67,    68,    68,    69,    70,    70,    71,    71,    72,
      72,    73,    74,    74,    75,    76,    76,    77,    77,    78,
      78,    79,    80,    81,    82,    82,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    84,
      85,    85,    86,    86,    87,    87,    88,    88,    89,    89,
      90,    91,    91,    92,    92,    93,    93,    94,    94,    94,
      95,    95,    95,    95,    95,    95,    96,    96,    97,    97,
      97,    97,    97,    97,    97,    98,    98
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     6,     5,     3,     1,     3,     0,
       5,     3,     2,     2,     1,     2,     2,     1,     1,     3,
       0,     5,     3,     1,     3,     6,     1,     1,     1,     1,
       1,     0,     3,     1,     3,     3,     0,     5,     3,     3,
       0,     2,     6,     4,     4,     3,     0,     3,     1,     1,
       1,     2,     3,     3,     3,     1,     3,     3,     1,     1,
       5,     5,     4,     4,     8,     8,     4,     4,     0,     2,
       2,     0,     3,     2,     2,     0,     1,     0,     3,     1,
       3,     3,     1,     1,     4,     3,     1,     3,     3,     1,
       1,     2,     2,     3,     3,     3,     3,     1,     1,     1,
       4,     3,     2,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     9,     0,     0,     9,     0,     0,    20,     0,     1,
       0,     0,     0,     3,     0,    36,     0,     2,     0,     8,
       0,     0,     0,    40,     7,     0,     0,     0,    14,    17,
      18,    11,     0,     0,    19,     0,     0,     0,     0,     0,
      12,    15,    13,    16,     0,     0,    31,    26,    27,    28,
      29,    22,    23,     0,     0,    35,     0,     0,    68,     0,
       9,     5,     6,     4,    10,     0,     0,    30,     0,    38,
       0,    46,    46,     0,     0,     0,     0,     0,    68,     0,
      71,    59,     0,    55,     0,    58,    39,    20,    41,     0,
       0,    33,    24,     0,    21,     0,     0,     0,     0,     0,
       0,   103,   104,     0,     0,    71,   105,   106,    99,     0,
      89,    90,    97,    98,     0,     0,     0,     0,     0,     0,
       0,    69,    68,    53,     0,     0,    36,     0,     0,     0,
      37,     0,     0,     0,    48,    49,    50,     0,    43,     0,
     102,    91,    92,     0,    68,     0,     0,     0,     0,     0,
       0,    68,     0,     0,    86,    77,     0,     0,     0,     0,
       0,     0,    70,    54,    56,    57,     0,    34,    32,     0,
      51,     0,     0,    45,     0,   101,     0,    75,    88,    94,
      95,    87,    93,    96,    62,    66,     0,    67,    82,     0,
      76,    79,     0,    63,     0,     0,    84,    73,     0,    44,
      25,    52,    47,    42,   100,    68,    60,    85,    61,     0,
       0,    68,     0,     0,    72,    74,    78,    81,    80,     0,
       0,    68,    68,    64,    65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     6,   132,     7,    12,    89,    15,    21,
      51,    52,    66,    90,    91,    23,    36,    37,    59,    60,
      88,    97,   133,   134,   135,   136,    81,    82,    83,   108,
     121,   162,   206,   189,   190,   191,   192,    85,   153,   154,
     110,   111,   112,   113
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -120
static const yytype_int16 yypact[] =
{
      14,   -24,    -4,    52,   -24,    30,    57,    24,    82,  -120,
     101,    84,   118,  -120,    96,   115,   105,  -120,   119,   108,
     126,   129,   105,  -120,  -120,    28,   121,   123,  -120,  -120,
    -120,  -120,   136,    61,   127,   124,   139,    99,   128,   169,
    -120,  -120,  -120,  -120,   119,   166,   105,  -120,  -120,  -120,
    -120,  -120,  -120,   142,    61,   105,   131,   133,   109,   174,
     -24,  -120,  -120,  -120,  -120,   119,   164,   176,    61,  -120,
     141,   175,   175,    32,    32,   177,   178,    32,   109,   138,
      21,  -120,    22,  -120,    11,  -120,  -120,    24,  -120,   183,
      38,  -120,  -120,   105,  -120,    61,     8,   181,   186,    32,
      64,  -120,  -120,    64,    64,   185,  -120,  -120,  -120,   163,
      89,   143,  -120,  -120,   167,   105,    32,   180,     4,    16,
      32,    31,   109,  -120,    32,    32,   115,   119,   119,   182,
    -120,   105,   153,    65,  -120,  -120,  -120,    93,  -120,   189,
    -120,   143,   143,    32,   109,    32,    64,    64,    32,    64,
      64,   109,    87,    90,  -120,   119,    32,    32,    32,    98,
     155,    32,  -120,  -120,  -120,  -120,   179,  -120,  -120,    61,
    -120,    93,     8,  -120,   193,  -120,   110,   173,   -15,   143,
     143,   -15,   143,  -120,  -120,  -120,    32,  -120,  -120,   187,
     196,  -120,   154,  -120,   152,   156,  -120,  -120,    62,  -120,
    -120,  -120,  -120,  -120,  -120,   109,  -120,  -120,  -120,   119,
     119,   109,    32,    32,  -120,  -120,  -120,  -120,  -120,   184,
     188,   109,   109,  -120,  -120
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -120,  -120,  -120,   203,    -9,   148,  -120,   -18,   122,  -120,
     -50,  -117,  -120,  -120,    83,    86,   170,  -120,  -120,  -120,
    -120,   145,  -120,    41,  -120,    88,   -35,   137,  -119,   -57,
    -120,  -120,  -120,  -120,  -120,    12,  -120,  -120,  -110,   -68,
     -38,   -87,   -92,  -120
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -84
static const yytype_int16 yytable[] =
{
      31,    84,    61,   163,    69,   109,   114,    25,   140,   117,
     159,   122,     5,    35,   124,     1,   141,   142,    94,   157,
     174,    84,   131,   146,   147,   177,    64,     2,   -83,   122,
     120,   139,   184,   176,    38,   160,   149,    35,    39,   -83,
     123,    99,   161,     8,   128,   130,    70,   156,   125,   -83,
     129,   198,     9,   158,   201,    24,   164,   165,   183,   179,
     180,    13,   182,   100,   -83,    84,   101,   102,   186,    14,
     103,   104,   172,    99,   214,   173,    45,    11,    46,   105,
     106,    47,    48,    49,    70,   107,   215,    84,   193,   194,
     195,    16,   218,    38,    84,   100,   186,   185,   101,   102,
     187,    50,   223,   224,   186,    17,   152,   178,   196,   167,
     181,   105,   106,    47,    48,    49,   186,   107,   207,   200,
     204,    18,    56,    57,    58,    19,   145,   146,   147,    22,
      38,   199,    54,    50,    58,    73,    34,   188,    74,   148,
     149,    75,    76,    20,   219,   220,    55,    38,    84,    95,
      77,    78,    24,    79,    84,    32,    80,    26,    27,    38,
     210,   171,   211,    33,    84,    84,    28,    29,    40,    41,
      42,    43,    30,    44,    53,    62,    63,    65,    71,    68,
      72,    86,    92,    93,    96,   119,   115,   116,   127,   137,
     144,   188,   217,   138,   143,   150,   155,   151,   169,   175,
     203,   205,   197,   209,    58,   208,   212,    10,    87,   126,
     213,   168,   166,   202,   221,   118,    67,    98,   222,   170,
       0,   216
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-120)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      18,    58,    37,   122,    54,    73,    74,    16,   100,    77,
     120,     7,    36,    22,     3,     1,   103,   104,    68,     3,
     137,    78,    14,    38,    39,   144,    44,    13,     7,     7,
       9,    99,   151,   143,     6,     4,    51,    46,    10,    18,
      18,     9,    11,    47,     6,    95,    55,    43,    37,    28,
      12,   161,     0,    37,   171,    47,   124,   125,   150,   146,
     147,     4,   149,    31,    43,   122,    34,    35,     6,    45,
      38,    39,     7,     9,    12,    10,    15,    47,    17,    47,
      48,    20,    21,    22,    93,    53,   205,   144,   156,   157,
     158,     9,   211,     6,   151,    31,     6,    10,    34,    35,
      10,    40,   221,   222,     6,     4,   115,   145,    10,   127,
     148,    47,    48,    20,    21,    22,     6,    53,   186,   169,
      10,    37,    23,    24,    25,     7,    37,    38,    39,    14,
       6,   166,     8,    40,    25,    26,     7,   155,    29,    50,
      51,    32,    33,    47,   212,   213,     7,     6,   205,     8,
      41,    42,    47,    44,   211,    47,    47,    38,    39,     6,
       6,     8,     8,    37,   221,   222,    47,    48,    47,    48,
      47,    48,    53,    37,    47,    47,     7,    11,    47,    37,
      47,     7,    18,     7,     9,    47,     9,     9,     5,     8,
      27,   209,   210,     7,     9,    52,    16,    30,    16,    10,
       7,    28,    47,     7,    25,    18,    54,     4,    60,    87,
      54,   128,   126,   172,    30,    78,    46,    72,    30,   131,
      -1,   209
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    13,    56,    57,    36,    58,    60,    47,     0,
      58,    47,    61,     4,    45,    63,     9,     4,    37,     7,
      47,    64,    14,    70,    47,    59,    38,    39,    47,    48,
      53,    62,    47,    37,     7,    59,    71,    72,     6,    10,
      47,    48,    47,    48,    37,    15,    17,    20,    21,    22,
      40,    65,    66,    47,     8,     7,    23,    24,    25,    73,
      74,    81,    47,     7,    62,    11,    67,    71,    37,    65,
      59,    47,    47,    26,    29,    32,    33,    41,    42,    44,
      47,    81,    82,    83,    84,    92,     7,    60,    75,    62,
      68,    69,    18,     7,    65,     8,     9,    76,    76,     9,
      31,    34,    35,    38,    39,    47,    48,    53,    84,    94,
      95,    96,    97,    98,    94,     9,     9,    94,    82,    47,
       9,    85,     7,    18,     3,    37,    63,     5,     6,    12,
      65,    14,    59,    77,    78,    79,    80,     8,     7,    94,
      97,    96,    96,     9,    27,    37,    38,    39,    50,    51,
      52,    30,    59,    93,    94,    16,    43,     3,    37,    93,
       4,    11,    86,    83,    94,    94,    70,    62,    69,    16,
      80,     8,     7,    10,    66,    10,    93,    83,    95,    96,
      96,    95,    96,    97,    83,    10,     6,    10,    62,    88,
      89,    90,    91,    94,    94,    94,    10,    47,    93,    81,
      65,    66,    78,     7,    10,    28,    87,    94,    18,     7,
       6,     8,    54,    54,    12,    83,    90,    62,    83,    94,
      94,    30,    30,    83,    83
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (astRoot, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location, astRoot); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, Program **astRoot)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, astRoot)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    Program **astRoot;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (astRoot);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, Program **astRoot)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, astRoot)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    Program **astRoot;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, astRoot);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, Program **astRoot)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, astRoot)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    Program **astRoot;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , astRoot);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, astRoot); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, Program **astRoot)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, astRoot)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    Program **astRoot;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (astRoot);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (Program **astRoot)
#else
int
yyparse (astRoot)
    Program **astRoot;
#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 341 "syntax.y"
    {
    (yyval.program) = new Program;
    (yyval.program)->head = (yyvsp[(1) - (3)].programHead);
    (yyval.program)->body = (yyvsp[(2) - (3)].programBody);
	(yyval.program)->lineNo=yylineno;
    *astRoot = (yyval.program);
    //printf("program -> program_head program_body DOT\n");
}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 349 "syntax.y"
    {
	yyerrok;
	(yyval.program) = new Program;
	(yyval.program)->head = NULL;
	(yyval.program)->body = (yyvsp[(2) - (3)].programBody);
	(yyval.program)->lineNo=yylineno;
	*astRoot = (yyval.program);
}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 358 "syntax.y"
    {
    (yyval.programHead) = new ProgramHead;
    (yyval.programHead)->id = *(yyvsp[(2) - (6)].str);
    delete (yyvsp[(2) - (6)].str);
    (yyval.programHead)->identifierList = *(yyvsp[(4) - (6)].identifierList);
    delete (yyvsp[(4) - (6)].identifierList);
	(yyval.programHead)->lineNo=yylineno;
    //printf("program_head : PROGRAM ID LPAREN identifier_list RPAREN SEMICOLON\n");
}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 368 "syntax.y"
    {
    (yyval.programBody) = new ProgramBody;
    (yyval.programBody)->constDeclarations = *(yyvsp[(1) - (5)].constDeclarations);
    delete (yyvsp[(1) - (5)].constDeclarations);
    (yyval.programBody)->typeDeclarations = *(yyvsp[(2) - (5)].typeDeclarations);
    delete (yyvsp[(2) - (5)].typeDeclarations);
    (yyval.programBody)->varDeclarations = *(yyvsp[(3) - (5)].varDeclarations);
    delete (yyvsp[(3) - (5)].varDeclarations);
    (yyval.programBody)->subprogramDeclarations = *(yyvsp[(4) - (5)].subprogramDeclarations);
    delete (yyvsp[(4) - (5)].subprogramDeclarations);
    (yyval.programBody)->compoundStatement = (yyvsp[(5) - (5)].compoundStatement);
	(yyval.programBody)->lineNo=yylineno;
    //printf("program_body : const_declarations type_declarations var_declarations subprogram_declarations compound_statement\n");
}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 383 "syntax.y"
    {
    (yyvsp[(1) - (3)].identifierList)->push_back(*(yyvsp[(3) - (3)].str));
    delete (yyvsp[(3) - (3)].str);
    (yyval.identifierList) = (yyvsp[(1) - (3)].identifierList);
    //printf("identifier_list : identifier_list COMMA ID\n");
}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 389 "syntax.y"
    {
    (yyval.identifierList) = new std::vector<std::string>();
    (yyval.identifierList)->push_back(*(yyvsp[(1) - (1)].str));
    delete (yyvsp[(1) - (1)].str);
    //printf("identifier_list : ID\n");
}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 396 "syntax.y"
    {
    (yyval.constDeclarations) = (yyvsp[(2) - (3)].constDeclarations);
    //printf("const_declarations : CONST const_declaration SEMICOLON\n");
}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 400 "syntax.y"
    {
    (yyval.constDeclarations) = new std::vector<ConstDeclaration *>();
    //printf("const_declarations : \n");
}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 405 "syntax.y"
    {
    (yyval.constDeclarations) = (yyvsp[(1) - (5)].constDeclarations);
    ConstDeclaration * temp = new ConstDeclaration;
    temp->id = *(yyvsp[(3) - (5)].str);
    delete (yyvsp[(3) - (5)].str);
    temp->constVariable = (yyvsp[(5) - (5)].constVariable);
	temp->lineNo=yylineno;
    (yyval.constDeclarations)->push_back(temp);
    //printf("const_declaration : const_declaration SEMICOLON ID EQUAL const_variable\n");
}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 415 "syntax.y"
    {
    (yyval.constDeclarations) = new std::vector<ConstDeclaration *>();
    ConstDeclaration * temp = new ConstDeclaration;
    temp->id = *(yyvsp[(1) - (3)].str);
    temp->constVariable = (yyvsp[(3) - (3)].constVariable);
	temp->lineNo=yylineno;
    (yyval.constDeclarations)->push_back(temp);
    //printf("const_declaration : ID EQUAL const_variable\n");
}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 425 "syntax.y"
    {
    SignedIdentifierFD * temp = new SignedIdentifierFD;
    temp->sign = true;
    temp->id = *(yyvsp[(2) - (2)].str);
	temp->lineNo=yylineno;
    delete (yyvsp[(2) - (2)].str);
    (yyval.constVariable)=temp;
    //printf("const_variable : POSITIVE ID\n");
}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 434 "syntax.y"
    {
    SignedIdentifierFD * temp = new SignedIdentifierFD;
    temp->sign = false;
    temp->id = *(yyvsp[(2) - (2)].str);
	temp->lineNo=yylineno;
    delete (yyvsp[(2) - (2)].str);
    (yyval.constVariable)=temp;
    //printf("const_variable : NEGATIVE ID\n");
}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 443 "syntax.y"
    {
    UnsignedIdentifierFD * temp =new UnsignedIdentifierFD;
    temp->id = *(yyvsp[(1) - (1)].str);
	temp->lineNo=yylineno;
    delete (yyvsp[(1) - (1)].str);
    (yyval.constVariable)=temp;
    //printf("const_variable : ID\n");
}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 451 "syntax.y"
    {
    SignedNumFD * temp = new SignedNumFD;
    temp->sign = true;
    temp->num = *(yyvsp[(2) - (2)].str);
	temp->lineNo=yylineno;
    delete (yyvsp[(2) - (2)].str);
    (yyval.constVariable)=temp;
    //printf("const_variable : POSITIVE NUM\n");
}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 460 "syntax.y"
    {
    SignedNumFD * temp = new SignedNumFD;
    temp->sign = false;
    temp->num = *(yyvsp[(2) - (2)].str);
	temp->lineNo=yylineno;
    delete (yyvsp[(2) - (2)].str);
    (yyval.constVariable)=temp;
    //printf("const_variable : NEGATIVE NUM\n");
}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 469 "syntax.y"
    {
    UnsignedNumFD * temp = new UnsignedNumFD;
    temp->num = *(yyvsp[(1) - (1)].str);
	temp->lineNo=yylineno;
    delete (yyvsp[(1) - (1)].str);
    (yyval.constVariable)=temp;
    //printf("const_variable : NUM\n");
}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 477 "syntax.y"
    {
    LettersFD * temp = new LettersFD;
    temp->letters = *(yyvsp[(1) - (1)].str);
	temp->lineNo=yylineno;
    delete (yyvsp[(1) - (1)].str);
    (yyval.constVariable)=temp;
    //printf("const_variable : LETTER \n");
}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 486 "syntax.y"
    {
    (yyval.typeDeclarations) = (yyvsp[(2) - (3)].typeDeclarations);
    //printf("type_declarations : TYPE type_declaration SEMICOLON\n");
}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 490 "syntax.y"
    {
    (yyval.typeDeclarations) = new std::vector<TypeDeclaration *>();
    //printf("type_declarations : \n");
}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 495 "syntax.y"
    {
    (yyval.typeDeclarations) = (yyvsp[(1) - (5)].typeDeclarations);
    TypeDeclaration * temp = new TypeDeclaration;
    temp->id = *(yyvsp[(3) - (5)].str);
    delete (yyvsp[(3) - (5)].str);
    temp->type = (yyvsp[(5) - (5)].type);
	temp->lineNo=yylineno;
    (yyval.typeDeclarations)->push_back(temp);
    //printf("type_declaration : type_declaration SEMICOLON ID EQUAL type\n");
}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 505 "syntax.y"
    {
    (yyval.typeDeclarations) = new std::vector<TypeDeclaration *>();
    TypeDeclaration * temp = new TypeDeclaration;
    temp->id = *(yyvsp[(1) - (3)].str);
    delete (yyvsp[(1) - (3)].str);
    temp->type = (yyvsp[(3) - (3)].type);
	temp->lineNo=yylineno;
    (yyval.typeDeclarations)->push_back(temp);
    //printf("type_declaration : ID EQUAL type\n");
}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 516 "syntax.y"
    {
    (yyval.type) = (yyvsp[(1) - (1)].standardType);
    //printf("type : standard\n");
}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 520 "syntax.y"
    {
    RecordType * temp = new RecordType;
    temp->varDeclarations = *(yyvsp[(2) - (3)].varDeclarations);
	temp->lineNo=yylineno;
    delete (yyvsp[(2) - (3)].varDeclarations);
    (yyval.type)=temp;
    //printf("type : RECORD record_body END\n");
}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 528 "syntax.y"
    {
    ArrayType * temp = new ArrayType;
    temp->periods = *(yyvsp[(3) - (6)].periods);
	temp->lineNo=yylineno;
    delete (yyvsp[(3) - (6)].periods);
    temp->type = (yyvsp[(6) - (6)].type);
    (yyval.type)=temp;
    //printf("type : ARRAY LSQUARE periods RSQUARE OF type\n");
}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 538 "syntax.y"
    {
    (yyval.standardType) = new IntegerType;
	//$$->lineNo=yylineno;
    //printf("standard_type : INTEGER\n");
}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 543 "syntax.y"
    {
    (yyval.standardType) = new RealType;
	//$$->lineNo=yylineno;
    //printf("standard_type : REAL\n");
}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 548 "syntax.y"
    {
    (yyval.standardType) = new BooleanType;
	//$$->lineNo=yylineno;
    //printf("standard_type : BOOLEAN\n");
}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 553 "syntax.y"
    {
    (yyval.standardType) = new CharType;
	//$$->lineNo=yylineno;
    //printf("standard_type : CHAR\n");
}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 559 "syntax.y"
    {
    (yyval.varDeclarations) = (yyvsp[(1) - (1)].varDeclarations);
    //printf("record_body : var_declaration\n");
}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 563 "syntax.y"
    {
    (yyval.varDeclarations) = new std::vector<VarDeclaration *>();
    //printf("record_body : \n");
}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 568 "syntax.y"
    {
    (yyval.periods) = (yyvsp[(1) - (3)].periods);
    (yyval.periods)->push_back((yyvsp[(3) - (3)].period));
    //printf("periods : periods COMMA period\n");
}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 573 "syntax.y"
    {
    (yyval.periods) = new std::vector<Period *>();
    (yyval.periods)->push_back((yyvsp[(1) - (1)].period));
    //printf("periods : period\n");
}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 579 "syntax.y"
    {
    (yyval.period) = new Period;
    (yyval.period)->lower = (yyvsp[(1) - (3)].constVariable);
    (yyval.period)->upper = (yyvsp[(3) - (3)].constVariable);
	(yyval.period)->lineNo=yylineno;
    //printf("period : const_variable DOTDOT const_variable\n");
}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 587 "syntax.y"
    {
    (yyval.varDeclarations) = (yyvsp[(2) - (3)].varDeclarations);
    //printf("var_declarations : VAR var_declaration SEMICOLON\n");
}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 591 "syntax.y"
    {
    (yyval.varDeclarations) = new std::vector<VarDeclaration *>();
    //printf("var_declarations : \n");
}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 596 "syntax.y"
    {
    (yyval.varDeclarations) = (yyvsp[(1) - (5)].varDeclarations);
    VarDeclaration * temp = new VarDeclaration;
    temp->identifierList = *(yyvsp[(3) - (5)].identifierList);
    delete (yyvsp[(3) - (5)].identifierList);
    temp->type = (yyvsp[(5) - (5)].type);
	temp->lineNo=yylineno;
    (yyval.varDeclarations)->push_back(temp);
    //printf("var_declaration : var_declaration SEMICOLON identifier_list COLON type\n");
}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 606 "syntax.y"
    {
    (yyval.varDeclarations) = new std::vector<VarDeclaration *>();
    VarDeclaration * temp = new VarDeclaration;
    temp->identifierList = *(yyvsp[(1) - (3)].identifierList);
    delete (yyvsp[(1) - (3)].identifierList);
    temp->type = (yyvsp[(3) - (3)].type);
	temp->lineNo=yylineno;
    (yyval.varDeclarations)->push_back(temp);
    //printf("var_declaration : identifier_list COLON type\n");
}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 617 "syntax.y"
    {
    (yyvsp[(1) - (3)].subprogramDeclarations)->push_back((yyvsp[(2) - (3)].subprogramDeclaration));
    (yyval.subprogramDeclarations) = (yyvsp[(1) - (3)].subprogramDeclarations);
    //printf("subprogram_declarations : subprogram_declarations subprogram_declaration SEMICOLON\n");
}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 622 "syntax.y"
    {
    (yyval.subprogramDeclarations) = new std::vector<SubprogramDeclaration*>();
    //printf("subprogram_declarations : \n");
}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 627 "syntax.y"
    {
    (yyval.subprogramDeclaration) = new SubprogramDeclaration;
    (yyval.subprogramDeclaration)->head = (yyvsp[(1) - (2)].subprogramHead);
    (yyval.subprogramDeclaration)->body = (yyvsp[(2) - (2)].subprogramBody);
	(yyval.subprogramDeclaration)->lineNo=yylineno;
    //printf("subprogram_declaration : subprogram_head program_body\n");
}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 635 "syntax.y"
    {
    (yyval.subprogramHead) = new SubprogramHead;
    (yyval.subprogramHead)->id = *(yyvsp[(2) - (6)].str);
    delete (yyvsp[(2) - (6)].str);
    (yyval.subprogramHead)->parameterLists = *(yyvsp[(3) - (6)].parameterLists);
    delete (yyvsp[(3) - (6)].parameterLists);
    (yyval.subprogramHead)->ret = (yyvsp[(5) - (6)].standardType);
	(yyval.subprogramHead)->lineNo=yylineno;
    //printf("subprogram_head : FUNCTION ID formal_parameter COLON standard_type SEMICOLON\n");
}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 645 "syntax.y"
    {
    (yyval.subprogramHead) = new SubprogramHead;
    (yyval.subprogramHead)->id = *(yyvsp[(2) - (4)].str);
    delete (yyvsp[(2) - (4)].str);
    (yyval.subprogramHead)->parameterLists = *(yyvsp[(3) - (4)].parameterLists);
    delete (yyvsp[(3) - (4)].parameterLists);
    (yyval.subprogramHead)->ret = NULL;
	(yyval.subprogramHead)->lineNo=yylineno;
    //printf("subprogram_head : PROCEDURE ID formal_parameter SEMICOLON\n");
}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 656 "syntax.y"
    {
    (yyval.subprogramBody) = new SubprogramBody;
    (yyval.subprogramBody)->constDeclarations = *(yyvsp[(1) - (4)].constDeclarations);
    delete (yyvsp[(1) - (4)].constDeclarations);
    (yyval.subprogramBody)->typeDeclarations = *(yyvsp[(2) - (4)].typeDeclarations);
    delete (yyvsp[(2) - (4)].typeDeclarations);
    (yyval.subprogramBody)->varDeclarations = *(yyvsp[(3) - (4)].varDeclarations);
    delete (yyvsp[(3) - (4)].varDeclarations);
    (yyval.subprogramBody)->compoundStatement = (yyvsp[(4) - (4)].compoundStatement);
	(yyval.subprogramBody)->lineNo=yylineno;
    //printf("program_body : const_declarations type_declarations var_declarations subprogram_declarations compound_statement\n");
}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 669 "syntax.y"
    {
    (yyval.parameterLists) = (yyvsp[(2) - (3)].parameterLists);
    //printf("formal_parameter : LPAREN parameter_lists RPAREN\n");
}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 673 "syntax.y"
    {
    (yyval.parameterLists) = new std::vector<ParameterList*>();
    //printf("formal_parameter : \n");
}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 678 "syntax.y"
    {
    (yyvsp[(1) - (3)].parameterLists)->push_back((yyvsp[(3) - (3)].parameterList));
    (yyval.parameterLists) = (yyvsp[(1) - (3)].parameterLists);
    //printf("parameter_lists : parameter_lists SEMICOLON parameter_list\n");
}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 683 "syntax.y"
    {
    (yyval.parameterLists) = new std::vector<ParameterList*>();
    (yyval.parameterLists)->push_back((yyvsp[(1) - (1)].parameterList));
    //printf("parameter_lists : parameter_list\n");
}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 689 "syntax.y"
    {
    (yyval.parameterList) = (yyvsp[(1) - (1)].parameterList);
    //printf("parameter_list : var_parameter\n");
}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 693 "syntax.y"
    {
    (yyval.parameterList) = (yyvsp[(1) - (1)].parameterList);
	(yyval.parameterList)->byReference = false;
    //printf("parameter_list : value_parameter\n");
}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 699 "syntax.y"
    {
    (yyval.parameterList) = (yyvsp[(2) - (2)].parameterList);
	(yyval.parameterList)->byReference = true;
    //printf("var_parameter : VAR value_parameter\n");
}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 705 "syntax.y"
    {
    (yyval.parameterList) = new ParameterList;
    (yyval.parameterList)->identifierList = *(yyvsp[(1) - (3)].identifierList);
    delete (yyvsp[(1) - (3)].identifierList);
    (yyval.parameterList)->type = (yyvsp[(3) - (3)].standardType);
	(yyval.parameterList)->lineNo=yylineno;
    //printf("value_parameter : identifier_list COLON standard_type\n");
}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 714 "syntax.y"
    {
    CompoundStatement * temp = new CompoundStatement;
    temp->statementList = *(yyvsp[(2) - (3)].statements);
    delete (yyvsp[(2) - (3)].statements);
	temp->lineNo=yylineno;
    (yyval.compoundStatement)=temp;
    //printf("compound_statement : BEIGN statement_list END\n");
}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 723 "syntax.y"
    {
    (yyvsp[(1) - (3)].statements)->push_back((yyvsp[(3) - (3)].statement));
    (yyval.statements) = (yyvsp[(1) - (3)].statements);
    //printf("statement_list : statement_list SEMICOLON statement\n");
}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 728 "syntax.y"
    {
    (yyval.statements) = new std::vector<Statement*>();
    (yyval.statements)->push_back((yyvsp[(1) - (1)].statement));
    //printf("statement_list : statement\n");
}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 734 "syntax.y"
    {
    AssignStatement * temp = new AssignStatement;
    temp->variable = (yyvsp[(1) - (3)].variable);
    temp->expression = (yyvsp[(3) - (3)].binaryExpression);
	temp->lineNo=yylineno;
    (yyval.statement)=temp;
    //printf("statement : variable ASSIGNOP expression\n");
}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 742 "syntax.y"
    {
    AssignStatement * temp = new AssignStatement;
    temp->variable = (yyvsp[(1) - (3)].variable);
    temp->expression = (yyvsp[(3) - (3)].binaryExpression);
	temp->lineNo=yylineno;
    (yyval.statement)=temp;
    //printf("statement : variable EQUAL expression\n");
}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 750 "syntax.y"
    {
    (yyval.statement) = (yyvsp[(1) - (1)].callProcedureStatement);
    //printf("statement : call_procedure_statement\n");
}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 754 "syntax.y"
    {
    (yyval.statement) = (yyvsp[(1) - (1)].compoundStatement);
    //printf("statement : compound_statement\n");
}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 758 "syntax.y"
    {
    IfStatement * temp = new IfStatement;
    temp->expression = (yyvsp[(2) - (5)].binaryExpression);
    temp->thenStatement = (yyvsp[(4) - (5)].statement);
    temp->elseStatement = (yyvsp[(5) - (5)].statement);
	temp->lineNo=yylineno;
    (yyval.statement)=temp;
    //printf("statement : IF expression THEN statement else_part\n");
}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 767 "syntax.y"
    {
    CaseStatement * temp = new CaseStatement;
    temp->expression = (yyvsp[(2) - (5)].binaryExpression);
    temp->branchList = *(yyvsp[(4) - (5)].branchs);
    delete (yyvsp[(4) - (5)].branchs);
	temp->lineNo=yylineno;
    (yyval.statement)=temp;
    //printf("statement : CASE expression OF case_body END\n");
}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 776 "syntax.y"
    {
    WhileStatement * temp = new WhileStatement;
    temp->expression = (yyvsp[(2) - (4)].binaryExpression);
    temp->statement = (yyvsp[(4) - (4)].statement);
	temp->lineNo=yylineno;
    (yyval.statement)=temp;
    //printf("statement : WHILE expression DO statement\n");
}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 784 "syntax.y"
    {
    RepeatStatement * temp = new RepeatStatement;
    temp->statementList = *(yyvsp[(2) - (4)].statements);
    delete (yyvsp[(2) - (4)].statements);
    temp->expression = (yyvsp[(4) - (4)].binaryExpression);
	temp->lineNo=yylineno;
    (yyval.statement)=temp;
    //printf("statement : REPEAT statement_list UNTIL expression\n");
}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 793 "syntax.y"
    {
    ForStatement * temp = new ForStatement;
    temp->id=*(yyvsp[(2) - (8)].str);
    delete (yyvsp[(2) - (8)].str);
    temp->lower = (yyvsp[(4) - (8)].binaryExpression);
    if(*(yyvsp[(5) - (8)].str) == "to")
    temp->updown = ForStatement::TO;
    else if(*(yyvsp[(5) - (8)].str) == "downto")
    temp->updown = ForStatement::DOWNTO;
    delete (yyvsp[(5) - (8)].str);
    temp->upper = (yyvsp[(6) - (8)].binaryExpression);
    temp->statement = (yyvsp[(8) - (8)].statement);
	temp->lineNo=yylineno;
    (yyval.statement)=temp;
    //printf("statement : FOR ID ASSIGNOP expression UPDOWN expression DO statement\n");
}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 809 "syntax.y"
    {
    ForStatement * temp = new ForStatement;
    temp->lower = (yyvsp[(4) - (8)].binaryExpression);
    if(*(yyvsp[(5) - (8)].str) == "to")
    temp->updown = ForStatement::TO;
    else if(*(yyvsp[(5) - (8)].str) == "downto")
    temp->updown = ForStatement::DOWNTO;
    delete (yyvsp[(5) - (8)].str);
    temp->upper = (yyvsp[(6) - (8)].binaryExpression);
    temp->statement = (yyvsp[(8) - (8)].statement);
	temp->lineNo=yylineno;
    (yyval.statement)=temp;
    //printf("statement : FOR ID EQUAL expression UPDOWN expression DO statement\n");
}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 823 "syntax.y"
    {
    ReadStatement * temp = new ReadStatement;
    temp->identifierList = *(yyvsp[(3) - (4)].identifierList);
	delete (yyvsp[(3) - (4)].identifierList);
	temp->lineNo=yylineno;
    (yyval.statement)=temp;
    //printf("statement : READ LPAREN identifier_list RPAREN\n");
}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 831 "syntax.y"
    {
    WriteStatement * temp = new WriteStatement;
    temp->expressionList = *(yyvsp[(3) - (4)].expressions);
	delete (yyvsp[(3) - (4)].expressions);
	temp->lineNo=yylineno;
    (yyval.statement)=temp;
    //printf("statement : WRITE LPAREN expression_list RPAREN\n");
}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 839 "syntax.y"
    {
    Statement *temp = NULL;
    (yyval.statement) = temp;
    //printf("statement : \n");
}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 845 "syntax.y"
    {
    (yyval.variable) = new Variable;
    (yyval.variable)->id = *(yyvsp[(1) - (2)].str);
    delete (yyvsp[(1) - (2)].str);
    (yyval.variable)->idVarParts = *(yyvsp[(2) - (2)].idVarParts);
    delete (yyvsp[(2) - (2)].idVarParts);
	(yyval.variable)->lineNo=yylineno;
    //printf("variable : ID id_varparts\n");
}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 855 "syntax.y"
    {
    (yyval.idVarParts) = (yyvsp[(1) - (2)].idVarParts);
    (yyval.idVarParts)->push_back((yyvsp[(2) - (2)].idVarPart));
    //printf("id_varparts : id_varparts id_varpart\n");
}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 860 "syntax.y"
    {
    (yyval.idVarParts) = new std::vector<IdVarPart*>();
    //printf("id_varparts : \n");
}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 865 "syntax.y"
    {
    ArrayPart * temp = new ArrayPart;
    temp->expressionList = *(yyvsp[(2) - (3)].expressions);
    delete (yyvsp[(2) - (3)].expressions);
	temp->lineNo=yylineno;
    (yyval.idVarPart)=temp;
    //printf("id_varpart : LSQUARE expression_list RSQUARE\n");
}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 873 "syntax.y"
    {
    MemberPart * temp =new MemberPart;
    temp->id = *(yyvsp[(2) - (2)].str);
    delete (yyvsp[(2) - (2)].str);
	temp->lineNo=yylineno;
    (yyval.idVarPart)=temp;
    //printf("id_varpart : DOT ID\n");
}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 882 "syntax.y"
    {
    (yyval.statement) = (yyvsp[(2) - (2)].statement);
    //printf("else_part : ELSE statement\n");
}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 886 "syntax.y"
    {
    Statement *temp = NULL;
    (yyval.statement) = temp;
    //printf("else_part : \n");
}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 892 "syntax.y"
    {
    (yyval.branchs) = (yyvsp[(1) - (1)].branchs);
    //printf("case_body : branch_list\n");
}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 896 "syntax.y"
    {
    (yyval.branchs) = new std::vector<Branch*>();
    //printf("case_body : \n");
}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 901 "syntax.y"
    {
    (yyvsp[(1) - (3)].branchs)->push_back((yyvsp[(3) - (3)].branch));
    (yyval.branchs) = (yyvsp[(1) - (3)].branchs);
    //printf("branch_list : branch_list SEMICOLON branch\n");
}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 906 "syntax.y"
    {
    (yyval.branchs) = new std::vector<Branch*>();
    (yyval.branchs)->push_back((yyvsp[(1) - (1)].branch));
    //printf("branch_list : branch\n");
}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 912 "syntax.y"
    {
    (yyval.branch) = new Branch;
    (yyval.branch)->constVariable = *(yyvsp[(1) - (3)].constVariables);
    delete (yyvsp[(1) - (3)].constVariables);
    (yyval.branch)->statement = (yyvsp[(3) - (3)].statement);
	(yyval.branch)->lineNo=yylineno;
    //printf("branch : const_list COLON statement\n");
}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 921 "syntax.y"
    {
    (yyvsp[(1) - (3)].constVariables)->push_back((yyvsp[(3) - (3)].constVariable));
    (yyval.constVariables) = (yyvsp[(1) - (3)].constVariables);
    //printf("const_list : const_list COMMA const_variable\n");
}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 926 "syntax.y"
    {
    (yyval.constVariables) = new std::vector<ConstVariable*>();
    (yyval.constVariables)->push_back((yyvsp[(1) - (1)].constVariable));
    //printf("const_list : const_variable\n");
}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 932 "syntax.y"
    {
    (yyval.callProcedureStatement) = new CallProcedureStatement;
    (yyval.callProcedureStatement)->id = *(yyvsp[(1) - (1)].str);
    delete (yyvsp[(1) - (1)].str);
	(yyval.callProcedureStatement)->lineNo=yylineno;
    //printf("call_procedure_statement : ID\n");
}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 939 "syntax.y"
    {
    (yyval.callProcedureStatement) = new CallProcedureStatement;
    (yyval.callProcedureStatement)->id = *(yyvsp[(1) - (4)].str);
    delete (yyvsp[(1) - (4)].str);
    (yyval.callProcedureStatement)->expressionList = *(yyvsp[(3) - (4)].expressions);
    delete (yyvsp[(3) - (4)].expressions);
	(yyval.callProcedureStatement)->lineNo=yylineno;
    //printf("call_procedure_statement : ID LPAREN expression_list RPAREN\n");
}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 949 "syntax.y"
    {
    (yyvsp[(1) - (3)].expressions)->push_back((yyvsp[(3) - (3)].binaryExpression));
    (yyval.expressions) = (yyvsp[(1) - (3)].expressions);
    //printf("expression_list : expression_list COMMA expression\n");
}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 954 "syntax.y"
    {
    (yyval.expressions) = new std::vector<Expression*>();
    (yyval.expressions)->push_back((yyvsp[(1) - (1)].binaryExpression));
    //printf("expression_list : expression\n");
}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 960 "syntax.y"
    {
    (yyval.binaryExpression) = new BinaryExpression;
    (yyval.binaryExpression)->left = (yyvsp[(1) - (3)].simpleExpression);
    if(*(yyvsp[(2) - (3)].str) == "<>")
    (yyval.binaryExpression)->relop = BinaryExpression::NOTEQUAL;
    else if(*(yyvsp[(2) - (3)].str) == "<")
    (yyval.binaryExpression)->relop = BinaryExpression::LESSTHAN;
    else if(*(yyvsp[(2) - (3)].str) == "<=")
    (yyval.binaryExpression)->relop = BinaryExpression::LESSEQUAL;
    else if(*(yyvsp[(2) - (3)].str) == ">")
    (yyval.binaryExpression)->relop = BinaryExpression::GREATERTHAN;
    else if(*(yyvsp[(2) - (3)].str) == ">=")
    (yyval.binaryExpression)->relop = BinaryExpression::GREATEREQUAL;
    delete (yyvsp[(2) - (3)].str);
    (yyval.binaryExpression)->right = (yyvsp[(3) - (3)].simpleExpression);
	(yyval.binaryExpression)->lineNo=yylineno;
    //printf("expression : simple_expression RELOP simple_expression\n");
}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 978 "syntax.y"
    {
    (yyval.binaryExpression) = new BinaryExpression;
    (yyval.binaryExpression)->left = (yyvsp[(1) - (3)].simpleExpression);
    (yyval.binaryExpression)->relop = BinaryExpression::EQUAL;
    //delete $2;
    (yyval.binaryExpression)->right = (yyvsp[(3) - (3)].simpleExpression);
	(yyval.binaryExpression)->lineNo=yylineno;
    //printf("expression : simple_expression EQUAL simple_expression\n");
}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 987 "syntax.y"
    {
    (yyval.binaryExpression) = (BinaryExpression*)(yyvsp[(1) - (1)].simpleExpression);
    //printf("expression : simple_expression\n");
}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 992 "syntax.y"
    {
    (yyval.simpleExpression) = (yyvsp[(1) - (1)].binaryTerm);
    //printf("simple_expression : term\n");
}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 996 "syntax.y"
    {
    SignedTerm * temp = new SignedTerm;
    temp->sign = true;
    temp->term = (yyvsp[(2) - (2)].binaryTerm);
	temp->lineNo=yylineno;
    (yyval.simpleExpression)=temp;
    //printf("simple_expression : POSITIVE term\n");
}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 1004 "syntax.y"
    {
    SignedTerm * temp = new SignedTerm;
    temp->sign = false;
    temp->term = (yyvsp[(2) - (2)].binaryTerm);
	temp->lineNo=yylineno;
    (yyval.simpleExpression)=temp;
    //printf("simple_expression : NEGATIVE term\n");
}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 1012 "syntax.y"
    {
    BinarySimpleExpression * temp = new BinarySimpleExpression;
    temp->simpleExpression = (yyvsp[(1) - (3)].simpleExpression);
    temp->addop = BinarySimpleExpression::OR;
    delete (yyvsp[(2) - (3)].str);
    temp->term = (yyvsp[(3) - (3)].binaryTerm);
	temp->lineNo=yylineno;
    (yyval.simpleExpression)=temp;
    //printf("simple_expression : simple_expression ADDOP term\n");
}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 1022 "syntax.y"
    {
    BinarySimpleExpression * temp = new BinarySimpleExpression;
    temp->simpleExpression = (yyvsp[(1) - (3)].simpleExpression);
    temp->addop = BinarySimpleExpression::PLUS;
    //delete $2;
    temp->term = (yyvsp[(3) - (3)].binaryTerm);
	temp->lineNo=yylineno;
    (yyval.simpleExpression)=temp;
    //printf("simple_expression : simple_expression POSITIVE term\n");
}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 1032 "syntax.y"
    {
    BinarySimpleExpression * temp = new BinarySimpleExpression;
    temp->simpleExpression = (yyvsp[(1) - (3)].simpleExpression);
    temp->addop = BinarySimpleExpression::MINUS;
    //delete $2;
    temp->term = (yyvsp[(3) - (3)].binaryTerm);
	temp->lineNo=yylineno;
    (yyval.simpleExpression)=temp;
    //printf("simple_expression : simple_expression NEGATIVE term\n");
}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 1043 "syntax.y"
    {
    BinaryTerm * temp = new BinaryTerm;
    temp->term = (yyvsp[(1) - (3)].binaryTerm);
    if(*(yyvsp[(2) - (3)].str) == "*")
    temp->mulop = BinaryTerm::MULTIPLY;
    else if(*(yyvsp[(2) - (3)].str) == "/")
    temp->mulop = BinaryTerm::REALDIVIDE;
    else if(*(yyvsp[(2) - (3)].str) == "div")
    temp->mulop = BinaryTerm::INTDIVIDE;
    else if(*(yyvsp[(2) - (3)].str) == "mod")
    temp->mulop = BinaryTerm::MOD;
    else if(*(yyvsp[(2) - (3)].str) == "and")
    temp->mulop = BinaryTerm::AND;
    delete (yyvsp[(2) - (3)].str);
    temp->factor = (yyvsp[(3) - (3)].factor);
	temp->lineNo=yylineno;
    (yyval.binaryTerm)=temp;
    //printf("term : term MULOP factor\n");
}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 1062 "syntax.y"
    {
    (yyval.binaryTerm) = (BinaryTerm*)(yyvsp[(1) - (1)].factor);
    //printf("term : factor\n");
}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 1067 "syntax.y"
    {
    (yyval.factor) = (yyvsp[(1) - (1)].unsignedConst);
    //printf("factor : unsign_const\n");
}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 1071 "syntax.y"
    {
    (yyval.factor) = (yyvsp[(1) - (1)].variable);
    //printf("factor : variable\n");
}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 1074 "syntax.y"
    {
    FunctionCall * temp = new FunctionCall;
    temp->id = *(yyvsp[(1) - (4)].str);
    delete (yyvsp[(1) - (4)].str);
    temp->expressionList = *(yyvsp[(3) - (4)].expressions);
    delete (yyvsp[(3) - (4)].expressions);
	temp->lineNo=yylineno;
    (yyval.factor)=temp;
    //printf("factor : ID LPAREN expression_list RPAREN\n");
}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 1084 "syntax.y"
    {
    Parenthesis * temp = new Parenthesis;
    temp->expression = (yyvsp[(2) - (3)].binaryExpression);
	temp->lineNo=yylineno;
    (yyval.factor)=temp;
    //printf("factor : LPAREN expression RPAREN\n");
}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 1091 "syntax.y"
    {
    Not * temp = new Not;
    temp->factor = (yyvsp[(2) - (2)].factor);
	temp->lineNo=yylineno;
    (yyval.factor)=temp;
    //printf("factor : NOT factor\n");
}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 1098 "syntax.y"
    {//
    Boolean * temp = new Boolean;
    temp->value = true;
	temp->lineNo=yylineno;
    (yyval.factor)=temp;
    //printf("factor : TRUE\n");
}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 1105 "syntax.y"
    {//
    Boolean * temp = new Boolean;
    temp->value = false;
	temp->lineNo=yylineno;
    (yyval.factor)=temp;
    //printf("factor : FALSE\n");
}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 1113 "syntax.y"
    {
    Num * temp = new Num;
    temp->num = *(yyvsp[(1) - (1)].str);
    delete (yyvsp[(1) - (1)].str);
	temp->lineNo=yylineno;
    (yyval.unsignedConst)=temp;
    //printf("unsign_const : NUM\n");
}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 1121 "syntax.y"
    {
    Letters * temp = new Letters;
    temp->letters = *(yyvsp[(1) - (1)].str);
    delete (yyvsp[(1) - (1)].str);
	temp->lineNo=yylineno;
    (yyval.unsignedConst)=temp;
    //printf("unsign_const : LETTER\n");
}
    break;


/* Line 1792 of yacc.c  */
#line 3106 "syntax.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (astRoot, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (astRoot, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc, astRoot);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp, astRoot);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (astRoot, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, astRoot);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, astRoot);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 1131 "syntax.y"


void yyerror(Program ** root,const char * msg){
	printf("\nError: %s \n       at Line %d,Row %d-%d:\n",msg,yylineno,yyrowno-yyleng,yyrowno);
    printf("       when encounted %s.\nPlease check the source file!" ,yytext);
}

//void errok(const char * msg){
//	//printf("\nError: syntax error on %s \n       at Line %d,Row %d-%d:\n",msg,yylineno,yyrowno-yyleng,yyrowno);
//    //printf("       when encounted %s.\nPlease check the source file!" ,yytext);
//}
