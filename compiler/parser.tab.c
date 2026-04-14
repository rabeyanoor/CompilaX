/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include "ast.h"
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int line_num;
void yyerror(const char* s);

ASTNode* root;

#line 85 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_NUMBER = 4,                     /* NUMBER  */
  YYSYMBOL_STRING_LITERAL = 5,             /* STRING_LITERAL  */
  YYSYMBOL_LET = 6,                        /* LET  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_PRINT = 10,                     /* PRINT  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_FN = 12,                        /* FN  */
  YYSYMBOL_FOR = 13,                       /* FOR  */
  YYSYMBOL_TYPE = 14,                      /* TYPE  */
  YYSYMBOL_MOD = 15,                       /* MOD  */
  YYSYMBOL_COUT = 16,                      /* COUT  */
  YYSYMBOL_LSHIFT = 17,                    /* LSHIFT  */
  YYSYMBOL_BREAK = 18,                     /* BREAK  */
  YYSYMBOL_QMARK = 19,                     /* QMARK  */
  YYSYMBOL_COLON = 20,                     /* COLON  */
  YYSYMBOL_ASSIGN = 21,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 22,                      /* PLUS  */
  YYSYMBOL_MINUS = 23,                     /* MINUS  */
  YYSYMBOL_MULT = 24,                      /* MULT  */
  YYSYMBOL_DIV = 25,                       /* DIV  */
  YYSYMBOL_LT = 26,                        /* LT  */
  YYSYMBOL_GT = 27,                        /* GT  */
  YYSYMBOL_EQ = 28,                        /* EQ  */
  YYSYMBOL_NE = 29,                        /* NE  */
  YYSYMBOL_LE = 30,                        /* LE  */
  YYSYMBOL_GE = 31,                        /* GE  */
  YYSYMBOL_AND = 32,                       /* AND  */
  YYSYMBOL_OR = 33,                        /* OR  */
  YYSYMBOL_INC = 34,                       /* INC  */
  YYSYMBOL_DEC = 35,                       /* DEC  */
  YYSYMBOL_NOT = 36,                       /* NOT  */
  YYSYMBOL_ADD_ASSIGN = 37,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 38,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 39,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 40,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 41,                /* MOD_ASSIGN  */
  YYSYMBOL_LPAREN = 42,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 43,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 44,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 45,                    /* RBRACE  */
  YYSYMBOL_SEMICOLON = 46,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 47,                     /* COMMA  */
  YYSYMBOL_THEN = 48,                      /* THEN  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_program = 50,                   /* program  */
  YYSYMBOL_statement_list = 51,            /* statement_list  */
  YYSYMBOL_statement = 52,                 /* statement  */
  YYSYMBOL_break_stmt = 53,                /* break_stmt  */
  YYSYMBOL_cout_stmt = 54,                 /* cout_stmt  */
  YYSYMBOL_cout_expr_list = 55,            /* cout_expr_list  */
  YYSYMBOL_type_specifier = 56,            /* type_specifier  */
  YYSYMBOL_var_decl = 57,                  /* var_decl  */
  YYSYMBOL_declarator_list = 58,           /* declarator_list  */
  YYSYMBOL_declarator = 59,                /* declarator  */
  YYSYMBOL_assignment = 60,                /* assignment  */
  YYSYMBOL_if_stmt = 61,                   /* if_stmt  */
  YYSYMBOL_while_stmt = 62,                /* while_stmt  */
  YYSYMBOL_for_stmt = 63,                  /* for_stmt  */
  YYSYMBOL_update = 64,                    /* update  */
  YYSYMBOL_print_stmt = 65,                /* print_stmt  */
  YYSYMBOL_func_decl = 66,                 /* func_decl  */
  YYSYMBOL_params = 67,                    /* params  */
  YYSYMBOL_return_stmt = 68,               /* return_stmt  */
  YYSYMBOL_block = 69,                     /* block  */
  YYSYMBOL_expression = 70,                /* expression  */
  YYSYMBOL_term = 71,                      /* term  */
  YYSYMBOL_unary = 72,                     /* unary  */
  YYSYMBOL_factor = 73,                    /* factor  */
  YYSYMBOL_func_call = 74,                 /* func_call  */
  YYSYMBOL_args = 75                       /* args  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  67
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   493

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  187

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46,    47,    48
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    43,    43,    47,    52,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    76,    80,    84,
      87,    95,    96,   100,   101,   105,   106,   110,   111,   115,
     118,   122,   126,   130,   134,   137,   140,   143,   146,   152,
     155,   161,   167,   172,   180,   183,   186,   189,   192,   198,
     204,   207,   213,   214,   215,   218,   219,   225,   231,   234,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   255,   256,   257,   258,   262,   263,   264,   268,
     269,   270,   271,   272,   276,   282,   283,   284
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER", "NUMBER",
  "STRING_LITERAL", "LET", "IF", "ELSE", "WHILE", "PRINT", "RETURN", "FN",
  "FOR", "TYPE", "MOD", "COUT", "LSHIFT", "BREAK", "QMARK", "COLON",
  "ASSIGN", "PLUS", "MINUS", "MULT", "DIV", "LT", "GT", "EQ", "NE", "LE",
  "GE", "AND", "OR", "INC", "DEC", "NOT", "ADD_ASSIGN", "SUB_ASSIGN",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "SEMICOLON", "COMMA", "THEN", "$accept", "program",
  "statement_list", "statement", "break_stmt", "cout_stmt",
  "cout_expr_list", "type_specifier", "var_decl", "declarator_list",
  "declarator", "assignment", "if_stmt", "while_stmt", "for_stmt",
  "update", "print_stmt", "func_decl", "params", "return_stmt", "block",
  "expression", "term", "unary", "factor", "func_call", "args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-127)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     105,   385,    17,    -2,     8,    10,    90,    32,    11,    29,
      28,    18,    51,    53,    62,    57,  -127,   105,  -127,  -127,
      63,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
      21,    90,    24,    33,    90,    90,    90,    90,    90,    90,
      60,    36,    37,    90,    90,    90,    45,  -127,  -127,    90,
      90,    90,   147,     3,  -127,  -127,  -127,    46,     7,  -127,
      90,    43,  -127,    44,    52,  -127,    47,  -127,  -127,    -6,
      54,  -127,   168,  -127,  -127,   189,   210,   231,   252,   273,
     115,    48,    90,  -127,    17,   336,   354,    58,  -127,  -127,
     372,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,  -127,    90,    90,    90,     9,   395,    17,    90,
      90,   420,  -127,  -127,  -127,  -127,     9,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,    90,  -127,   450,  -127,   105,   105,
      56,  -127,   435,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,  -127,  -127,  -127,    73,   100,    67,   294,
     315,  -127,    79,  -127,   116,  -127,  -127,    90,     9,    78,
      83,    13,    13,    83,   105,   450,  -127,     9,  -127,   -10,
     127,   128,    92,    93,  -127,  -127,  -127,    90,  -127,  -127,
    -127,  -127,   105,   105,   450,  -127,  -127
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,     0,     2,     3,    10,    11,
       0,     5,     6,     7,     8,    14,     9,    12,    13,    16,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    85,
      27,     0,    25,     0,     0,    85,    81,    79,    80,     0,
       0,     0,     0,    60,    72,    76,    82,     0,     0,    22,
       0,     0,    17,     0,     0,    59,     0,     1,     4,    27,
       0,    15,     0,    30,    31,     0,     0,     0,     0,     0,
      86,     0,     0,    23,     0,     0,     0,     0,    77,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    57,     0,     0,     0,    52,     0,     0,     0,
       0,    19,    18,    32,    33,    58,    52,    24,    29,    34,
      35,    36,    37,    38,    85,    84,    28,    26,     0,     0,
       0,    83,     0,    61,    62,    63,    64,    67,    68,    65,
      66,    69,    70,    75,    73,    74,    53,     0,     0,     0,
       0,    20,     0,    87,    39,    41,    49,     0,    52,    55,
       0,     0,     0,     0,     0,    71,    54,    52,    50,     0,
       0,     0,     0,     0,    51,    40,    56,     0,    45,    46,
      47,    48,     0,     0,    44,    42,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,     5,  -120,  -127,  -127,    22,    -7,    95,     1,
    -127,    96,  -127,  -127,  -127,   -12,  -127,  -127,  -109,  -127,
    -126,    -5,   392,   -44,  -127,     0,   -41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    15,    16,    17,    18,    19,    61,    20,    21,    70,
      42,    22,    23,    24,    25,   172,    26,    27,   148,    28,
      29,    80,    53,    54,    55,    56,    81
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      30,    52,    59,    41,    87,    88,    89,   152,   154,   155,
     107,   177,   146,     2,    30,    82,   169,    30,   103,    66,
      40,     9,    68,     9,   178,   179,    72,   104,   105,    75,
      76,    77,    78,    79,   168,    57,   116,   174,    85,    86,
      43,    12,    13,     9,   175,    60,    90,   170,   171,   166,
      44,   108,    45,    58,    63,   111,    64,    67,   176,   143,
     144,   145,   185,   186,    62,     1,    69,    71,     2,     3,
      73,     4,     5,     6,     7,     8,     9,   126,    10,    74,
      11,    82,    83,   153,    84,   127,   132,    39,   106,   112,
     113,   125,   115,    46,    47,    48,    12,    13,   114,   147,
     117,   130,   156,   159,   149,   150,    14,    65,     1,   147,
     160,     2,     3,    49,     4,     5,     6,     7,     8,     9,
     158,    10,   163,    11,   164,   167,    50,    14,    30,    30,
     180,   181,    51,   151,    91,   182,   183,    92,    93,    12,
      13,    94,    95,    96,    97,    98,    99,   100,   101,    14,
     173,   147,   165,   109,   110,     0,     0,     0,     0,     0,
     147,     0,   124,     0,    30,     0,    91,     0,     0,    92,
      93,     0,   184,    94,    95,    96,    97,    98,    99,   100,
     101,     0,    30,    30,     0,     0,     0,    91,     0,     0,
      92,    93,     0,   102,    94,    95,    96,    97,    98,    99,
     100,   101,     0,     0,     0,     0,     0,     0,    91,     0,
       0,    92,    93,     0,   118,    94,    95,    96,    97,    98,
      99,   100,   101,     0,     0,     0,     0,     0,     0,    91,
       0,     0,    92,    93,     0,   119,    94,    95,    96,    97,
      98,    99,   100,   101,     0,     0,     0,     0,     0,     0,
      91,     0,     0,    92,    93,     0,   120,    94,    95,    96,
      97,    98,    99,   100,   101,     0,     0,     0,     0,     0,
       0,    91,     0,     0,    92,    93,     0,   121,    94,    95,
      96,    97,    98,    99,   100,   101,     0,     0,     0,     0,
       0,     0,    91,     0,     0,    92,    93,     0,   122,    94,
      95,    96,    97,    98,    99,   100,   101,     0,     0,     0,
       0,     0,     0,    91,     0,     0,    92,    93,     0,   123,
      94,    95,    96,    97,    98,    99,   100,   101,     0,     0,
       0,     0,     0,     0,    91,     0,     0,    92,    93,     0,
     161,    94,    95,    96,    97,    98,    99,   100,   101,     0,
       0,     0,     0,     0,     0,    91,     0,     0,    92,    93,
       0,   162,    94,    95,    96,    97,    98,    99,   100,   101,
       0,     0,     0,    91,     0,     0,    92,    93,     0,   128,
      94,    95,    96,    97,    98,    99,   100,   101,     0,     0,
       0,    91,     0,     0,    92,    93,     0,   129,    94,    95,
      96,    97,    98,    99,   100,   101,    31,     0,     0,     0,
       0,     0,     0,     0,     0,   131,    31,     0,     0,    32,
      33,     0,    34,    35,    36,    37,    38,    39,     0,    32,
      33,     0,    34,    35,    36,    37,    38,    60,     0,    91,
       0,     0,    92,    93,     0,     0,    94,    95,    96,    97,
      98,    99,   100,   101,    91,   157,     0,    92,    93,     0,
       0,    94,    95,    96,    97,    98,    99,   100,   101,    91,
       0,     0,    92,    93,     0,     0,    94,    95,    96,    97,
      98,    99,   100,   101,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142
};

static const yytype_int16 yycheck[] =
{
       0,     6,     9,     2,    45,    49,    50,   116,   128,   129,
       3,    21,     3,     6,    14,    21,     3,    17,    15,    14,
       3,    14,    17,    14,    34,    35,    31,    24,    25,    34,
      35,    36,    37,    38,   160,     3,    42,   163,    43,    44,
      42,    34,    35,    14,   164,    17,    51,    34,    35,   158,
      42,    58,    42,    42,     3,    60,     3,     0,   167,   103,
     104,   105,   182,   183,    46,     3,     3,    46,     6,     7,
      46,     9,    10,    11,    12,    13,    14,    82,    16,    46,
      18,    21,    46,   124,    47,    84,    91,    42,    42,    46,
      46,    43,    45,     3,     4,     5,    34,    35,    46,   106,
      46,    43,    46,     3,   109,   110,    44,    45,     3,   116,
      43,     6,     7,    23,     9,    10,    11,    12,    13,    14,
      47,    16,    43,    18,     8,    47,    36,    44,   128,   129,
       3,     3,    42,   111,    19,    43,    43,    22,    23,    34,
      35,    26,    27,    28,    29,    30,    31,    32,    33,    44,
     162,   158,   157,    58,    58,    -1,    -1,    -1,    -1,    -1,
     167,    -1,    47,    -1,   164,    -1,    19,    -1,    -1,    22,
      23,    -1,   177,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,   182,   183,    -1,    -1,    -1,    19,    -1,    -1,
      22,    23,    -1,    46,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,
      -1,    22,    23,    -1,    46,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    -1,    22,    23,    -1,    46,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    -1,    -1,    22,    23,    -1,    46,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    -1,    22,    23,    -1,    46,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    -1,    -1,    22,    23,    -1,    46,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    -1,    22,    23,    -1,    46,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    -1,    -1,    22,    23,    -1,
      46,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    22,    23,
      -1,    46,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    19,    -1,    -1,    22,    23,    -1,    43,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    19,    -1,    -1,    22,    23,    -1,    43,    26,    27,
      28,    29,    30,    31,    32,    33,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    21,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    17,    -1,    19,
      -1,    -1,    22,    23,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    19,    20,    -1,    22,    23,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    19,
      -1,    -1,    22,    23,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     6,     7,     9,    10,    11,    12,    13,    14,
      16,    18,    34,    35,    44,    50,    51,    52,    53,    54,
      56,    57,    60,    61,    62,    63,    65,    66,    68,    69,
      74,    21,    34,    35,    37,    38,    39,    40,    41,    42,
       3,    58,    59,    42,    42,    42,     3,     4,     5,    23,
      36,    42,    70,    71,    72,    73,    74,     3,    42,    56,
      17,    55,    46,     3,     3,    45,    51,     0,    51,     3,
      58,    46,    70,    46,    46,    70,    70,    70,    70,    70,
      70,    75,    21,    46,    47,    70,    70,    75,    72,    72,
      70,    19,    22,    23,    26,    27,    28,    29,    30,    31,
      32,    33,    46,    15,    24,    25,    42,     3,    56,    57,
      60,    70,    46,    46,    46,    45,    42,    46,    46,    46,
      46,    46,    46,    46,    47,    43,    70,    58,    43,    43,
      43,    43,    70,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    72,    72,    72,     3,    56,    67,    70,
      70,    55,    67,    75,    52,    52,    46,    20,    47,     3,
      43,    46,    46,    43,     8,    70,    67,    47,    69,     3,
      34,    35,    64,    64,    69,    52,    67,    21,    34,    35,
       3,     3,    43,    43,    70,    52,    52
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    53,    54,    55,
      55,    56,    56,    57,    57,    58,    58,    59,    59,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    61,
      61,    62,    63,    63,    64,    64,    64,    64,    64,    65,
      66,    66,    67,    67,    67,    67,    67,    68,    69,    69,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    71,    71,    71,    72,    72,    72,    73,
      73,    73,    73,    73,    74,    75,    75,    75
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     2,     3,     2,
       3,     1,     2,     3,     3,     1,     3,     1,     3,     4,
       3,     3,     3,     3,     4,     4,     4,     4,     4,     5,
       7,     5,     8,     8,     3,     2,     2,     2,     2,     5,
       6,     6,     0,     1,     3,     2,     4,     3,     3,     2,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     1,     3,     3,     3,     1,     2,     2,     1,
       1,     1,     1,     3,     4,     0,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: statement_list  */
#line 43 "parser.y"
                   { root = create_node(NODE_PROGRAM, NULL, (yyvsp[0].nval), NULL, NULL); }
#line 1328 "parser.tab.c"
    break;

  case 3: /* statement_list: statement  */
#line 47 "parser.y"
              { 
        ASTNode* last = (yyvsp[0].nval);
        while (last->next) last = last->next;
        (yyval.nval) = (yyvsp[0].nval); 
    }
#line 1338 "parser.tab.c"
    break;

  case 4: /* statement_list: statement statement_list  */
#line 52 "parser.y"
                               { 
        ASTNode* last = (yyvsp[-1].nval);
        while (last->next) last = last->next;
        last->next = (yyvsp[0].nval); 
        (yyval.nval) = (yyvsp[-1].nval); 
    }
#line 1349 "parser.tab.c"
    break;

  case 5: /* statement: var_decl  */
#line 61 "parser.y"
             { (yyval.nval) = (yyvsp[0].nval); }
#line 1355 "parser.tab.c"
    break;

  case 6: /* statement: assignment  */
#line 62 "parser.y"
                 { (yyval.nval) = (yyvsp[0].nval); }
#line 1361 "parser.tab.c"
    break;

  case 7: /* statement: if_stmt  */
#line 63 "parser.y"
              { (yyval.nval) = (yyvsp[0].nval); }
#line 1367 "parser.tab.c"
    break;

  case 8: /* statement: while_stmt  */
#line 64 "parser.y"
                 { (yyval.nval) = (yyvsp[0].nval); }
#line 1373 "parser.tab.c"
    break;

  case 9: /* statement: print_stmt  */
#line 65 "parser.y"
                 { (yyval.nval) = (yyvsp[0].nval); }
#line 1379 "parser.tab.c"
    break;

  case 10: /* statement: break_stmt  */
#line 66 "parser.y"
                 { (yyval.nval) = (yyvsp[0].nval); }
#line 1385 "parser.tab.c"
    break;

  case 11: /* statement: cout_stmt  */
#line 67 "parser.y"
                { (yyval.nval) = (yyvsp[0].nval); }
#line 1391 "parser.tab.c"
    break;

  case 12: /* statement: func_decl  */
#line 68 "parser.y"
                { (yyval.nval) = (yyvsp[0].nval); }
#line 1397 "parser.tab.c"
    break;

  case 13: /* statement: return_stmt  */
#line 69 "parser.y"
                  { (yyval.nval) = (yyvsp[0].nval); }
#line 1403 "parser.tab.c"
    break;

  case 14: /* statement: for_stmt  */
#line 70 "parser.y"
               { (yyval.nval) = (yyvsp[0].nval); }
#line 1409 "parser.tab.c"
    break;

  case 15: /* statement: func_call SEMICOLON  */
#line 71 "parser.y"
                          { (yyval.nval) = (yyvsp[-1].nval); }
#line 1415 "parser.tab.c"
    break;

  case 16: /* statement: block  */
#line 72 "parser.y"
            { (yyval.nval) = (yyvsp[0].nval); }
#line 1421 "parser.tab.c"
    break;

  case 17: /* break_stmt: BREAK SEMICOLON  */
#line 76 "parser.y"
                    { (yyval.nval) = create_node(NODE_BREAK, NULL, NULL, NULL, NULL); }
#line 1427 "parser.tab.c"
    break;

  case 18: /* cout_stmt: COUT cout_expr_list SEMICOLON  */
#line 80 "parser.y"
                                  { (yyval.nval) = (yyvsp[-1].nval); }
#line 1433 "parser.tab.c"
    break;

  case 19: /* cout_expr_list: LSHIFT expression  */
#line 84 "parser.y"
                      { 
        (yyval.nval) = create_node(NODE_PRINT, NULL, (yyvsp[0].nval), NULL, NULL); 
    }
#line 1441 "parser.tab.c"
    break;

  case 20: /* cout_expr_list: LSHIFT expression cout_expr_list  */
#line 87 "parser.y"
                                       { 
        ASTNode* p = create_node(NODE_PRINT, NULL, (yyvsp[-1].nval), NULL, NULL); 
        p->next = (yyvsp[0].nval); 
        (yyval.nval) = p; 
    }
#line 1451 "parser.tab.c"
    break;

  case 21: /* type_specifier: TYPE  */
#line 95 "parser.y"
         { (yyval.nval) = NULL; }
#line 1457 "parser.tab.c"
    break;

  case 22: /* type_specifier: TYPE type_specifier  */
#line 96 "parser.y"
                          { (yyval.nval) = NULL; }
#line 1463 "parser.tab.c"
    break;

  case 23: /* var_decl: LET declarator_list SEMICOLON  */
#line 100 "parser.y"
                                  { (yyval.nval) = (yyvsp[-1].nval); }
#line 1469 "parser.tab.c"
    break;

  case 24: /* var_decl: type_specifier declarator_list SEMICOLON  */
#line 101 "parser.y"
                                               { (yyval.nval) = (yyvsp[-1].nval); }
#line 1475 "parser.tab.c"
    break;

  case 25: /* declarator_list: declarator  */
#line 105 "parser.y"
               { (yyval.nval) = (yyvsp[0].nval); }
#line 1481 "parser.tab.c"
    break;

  case 26: /* declarator_list: declarator COMMA declarator_list  */
#line 106 "parser.y"
                                       { (yyvsp[-2].nval)->next = (yyvsp[0].nval); (yyval.nval) = (yyvsp[-2].nval); }
#line 1487 "parser.tab.c"
    break;

  case 27: /* declarator: IDENTIFIER  */
#line 110 "parser.y"
               { (yyval.nval) = create_node(NODE_VAR_DECL, (yyvsp[0].sval), NULL, NULL, NULL); }
#line 1493 "parser.tab.c"
    break;

  case 28: /* declarator: IDENTIFIER ASSIGN expression  */
#line 111 "parser.y"
                                   { (yyval.nval) = create_node(NODE_VAR_DECL, (yyvsp[-2].sval), (yyvsp[0].nval), NULL, NULL); }
#line 1499 "parser.tab.c"
    break;

  case 29: /* assignment: IDENTIFIER ASSIGN expression SEMICOLON  */
#line 115 "parser.y"
                                           {
        (yyval.nval) = create_node(NODE_ASSIGN, (yyvsp[-3].sval), (yyvsp[-1].nval), NULL, NULL);
    }
#line 1507 "parser.tab.c"
    break;

  case 30: /* assignment: IDENTIFIER INC SEMICOLON  */
#line 118 "parser.y"
                               {
        /* Pseudo-assignment for x++ */
        (yyval.nval) = create_node(NODE_ASSIGN, (yyvsp[-2].sval), create_node(NODE_BINARY_OP, "+", create_node(NODE_IDENTIFIER, (yyvsp[-2].sval), NULL, NULL, NULL), NULL, create_node(NODE_NUMBER, "1", NULL, NULL, NULL)), NULL, NULL);
    }
#line 1516 "parser.tab.c"
    break;

  case 31: /* assignment: IDENTIFIER DEC SEMICOLON  */
#line 122 "parser.y"
                               {
        /* Pseudo-assignment for x-- */
        (yyval.nval) = create_node(NODE_ASSIGN, (yyvsp[-2].sval), create_node(NODE_BINARY_OP, "-", create_node(NODE_IDENTIFIER, (yyvsp[-2].sval), NULL, NULL, NULL), NULL, create_node(NODE_NUMBER, "1", NULL, NULL, NULL)), NULL, NULL);
    }
#line 1525 "parser.tab.c"
    break;

  case 32: /* assignment: INC IDENTIFIER SEMICOLON  */
#line 126 "parser.y"
                               {
        /* Pre-increment: ++x */
        (yyval.nval) = create_node(NODE_ASSIGN, (yyvsp[-1].sval), create_node(NODE_BINARY_OP, "+", create_node(NODE_IDENTIFIER, (yyvsp[-1].sval), NULL, NULL, NULL), NULL, create_node(NODE_NUMBER, "1", NULL, NULL, NULL)), NULL, NULL);
    }
#line 1534 "parser.tab.c"
    break;

  case 33: /* assignment: DEC IDENTIFIER SEMICOLON  */
#line 130 "parser.y"
                               {
        /* Pre-decrement: --x */
        (yyval.nval) = create_node(NODE_ASSIGN, (yyvsp[-1].sval), create_node(NODE_BINARY_OP, "-", create_node(NODE_IDENTIFIER, (yyvsp[-1].sval), NULL, NULL, NULL), NULL, create_node(NODE_NUMBER, "1", NULL, NULL, NULL)), NULL, NULL);
    }
#line 1543 "parser.tab.c"
    break;

  case 34: /* assignment: IDENTIFIER ADD_ASSIGN expression SEMICOLON  */
#line 134 "parser.y"
                                                 {
        (yyval.nval) = create_node(NODE_ASSIGN, (yyvsp[-3].sval), create_node(NODE_BINARY_OP, "+", create_node(NODE_IDENTIFIER, (yyvsp[-3].sval), NULL, NULL, NULL), NULL, (yyvsp[-1].nval)), NULL, NULL);
    }
#line 1551 "parser.tab.c"
    break;

  case 35: /* assignment: IDENTIFIER SUB_ASSIGN expression SEMICOLON  */
#line 137 "parser.y"
                                                 {
        (yyval.nval) = create_node(NODE_ASSIGN, (yyvsp[-3].sval), create_node(NODE_BINARY_OP, "-", create_node(NODE_IDENTIFIER, (yyvsp[-3].sval), NULL, NULL, NULL), NULL, (yyvsp[-1].nval)), NULL, NULL);
    }
#line 1559 "parser.tab.c"
    break;

  case 36: /* assignment: IDENTIFIER MUL_ASSIGN expression SEMICOLON  */
#line 140 "parser.y"
                                                 {
        (yyval.nval) = create_node(NODE_ASSIGN, (yyvsp[-3].sval), create_node(NODE_BINARY_OP, "*", create_node(NODE_IDENTIFIER, (yyvsp[-3].sval), NULL, NULL, NULL), NULL, (yyvsp[-1].nval)), NULL, NULL);
    }
#line 1567 "parser.tab.c"
    break;

  case 37: /* assignment: IDENTIFIER DIV_ASSIGN expression SEMICOLON  */
#line 143 "parser.y"
                                                 {
        (yyval.nval) = create_node(NODE_ASSIGN, (yyvsp[-3].sval), create_node(NODE_BINARY_OP, "/", create_node(NODE_IDENTIFIER, (yyvsp[-3].sval), NULL, NULL, NULL), NULL, (yyvsp[-1].nval)), NULL, NULL);
    }
#line 1575 "parser.tab.c"
    break;

  case 38: /* assignment: IDENTIFIER MOD_ASSIGN expression SEMICOLON  */
#line 146 "parser.y"
                                                 {
        (yyval.nval) = create_node(NODE_ASSIGN, (yyvsp[-3].sval), create_node(NODE_BINARY_OP, "%", create_node(NODE_IDENTIFIER, (yyvsp[-3].sval), NULL, NULL, NULL), NULL, (yyvsp[-1].nval)), NULL, NULL);
    }
#line 1583 "parser.tab.c"
    break;

  case 39: /* if_stmt: IF LPAREN expression RPAREN statement  */
#line 152 "parser.y"
                                                     {
        (yyval.nval) = create_node(NODE_IF, NULL, (yyvsp[-2].nval), (yyvsp[0].nval), NULL);
    }
#line 1591 "parser.tab.c"
    break;

  case 40: /* if_stmt: IF LPAREN expression RPAREN statement ELSE statement  */
#line 155 "parser.y"
                                                           {
        (yyval.nval) = create_node(NODE_IF, NULL, (yyvsp[-4].nval), (yyvsp[-2].nval), (yyvsp[0].nval));
    }
#line 1599 "parser.tab.c"
    break;

  case 41: /* while_stmt: WHILE LPAREN expression RPAREN statement  */
#line 161 "parser.y"
                                             {
        (yyval.nval) = create_node(NODE_WHILE, NULL, (yyvsp[-2].nval), (yyvsp[0].nval), NULL);
    }
#line 1607 "parser.tab.c"
    break;

  case 42: /* for_stmt: FOR LPAREN var_decl expression SEMICOLON update RPAREN statement  */
#line 167 "parser.y"
                                                                     {
        /* var_decl already includes SEMICOLON */
        ASTNode* tail = create_node(NODE_PROGRAM, NULL, (yyvsp[-2].nval), (yyvsp[0].nval), NULL);
        (yyval.nval) = create_node(NODE_FOR, NULL, (yyvsp[-5].nval), (yyvsp[-4].nval), tail);
    }
#line 1617 "parser.tab.c"
    break;

  case 43: /* for_stmt: FOR LPAREN assignment expression SEMICOLON update RPAREN statement  */
#line 172 "parser.y"
                                                                         {
        /* assignment already includes SEMICOLON */
        ASTNode* tail = create_node(NODE_PROGRAM, NULL, (yyvsp[-2].nval), (yyvsp[0].nval), NULL);
        (yyval.nval) = create_node(NODE_FOR, NULL, (yyvsp[-5].nval), (yyvsp[-4].nval), tail);
    }
#line 1627 "parser.tab.c"
    break;

  case 44: /* update: IDENTIFIER ASSIGN expression  */
#line 180 "parser.y"
                                 {
        (yyval.nval) = create_node(NODE_ASSIGN, (yyvsp[-2].sval), (yyvsp[0].nval), NULL, NULL);
    }
#line 1635 "parser.tab.c"
    break;

  case 45: /* update: IDENTIFIER INC  */
#line 183 "parser.y"
                     {
        (yyval.nval) = create_node(NODE_ASSIGN, (yyvsp[-1].sval), create_node(NODE_BINARY_OP, "+", create_node(NODE_IDENTIFIER, (yyvsp[-1].sval), NULL, NULL, NULL), NULL, create_node(NODE_NUMBER, "1", NULL, NULL, NULL)), NULL, NULL);
    }
#line 1643 "parser.tab.c"
    break;

  case 46: /* update: IDENTIFIER DEC  */
#line 186 "parser.y"
                     {
        (yyval.nval) = create_node(NODE_ASSIGN, (yyvsp[-1].sval), create_node(NODE_BINARY_OP, "-", create_node(NODE_IDENTIFIER, (yyvsp[-1].sval), NULL, NULL, NULL), NULL, create_node(NODE_NUMBER, "1", NULL, NULL, NULL)), NULL, NULL);
    }
#line 1651 "parser.tab.c"
    break;

  case 47: /* update: INC IDENTIFIER  */
#line 189 "parser.y"
                     {
        (yyval.nval) = create_node(NODE_ASSIGN, (yyvsp[0].sval), create_node(NODE_BINARY_OP, "+", create_node(NODE_IDENTIFIER, (yyvsp[0].sval), NULL, NULL, NULL), NULL, create_node(NODE_NUMBER, "1", NULL, NULL, NULL)), NULL, NULL);
    }
#line 1659 "parser.tab.c"
    break;

  case 48: /* update: DEC IDENTIFIER  */
#line 192 "parser.y"
                     {
        (yyval.nval) = create_node(NODE_ASSIGN, (yyvsp[0].sval), create_node(NODE_BINARY_OP, "-", create_node(NODE_IDENTIFIER, (yyvsp[0].sval), NULL, NULL, NULL), NULL, create_node(NODE_NUMBER, "1", NULL, NULL, NULL)), NULL, NULL);
    }
#line 1667 "parser.tab.c"
    break;

  case 49: /* print_stmt: PRINT LPAREN args RPAREN SEMICOLON  */
#line 198 "parser.y"
                                       {
        (yyval.nval) = create_node(NODE_PRINT, NULL, (yyvsp[-2].nval), NULL, NULL);
    }
#line 1675 "parser.tab.c"
    break;

  case 50: /* func_decl: FN IDENTIFIER LPAREN params RPAREN block  */
#line 204 "parser.y"
                                             {
        (yyval.nval) = create_node(NODE_FUNC_DECL, (yyvsp[-4].sval), (yyvsp[-2].nval), (yyvsp[0].nval), NULL);
    }
#line 1683 "parser.tab.c"
    break;

  case 51: /* func_decl: type_specifier IDENTIFIER LPAREN params RPAREN block  */
#line 207 "parser.y"
                                                           {
        (yyval.nval) = create_node(NODE_FUNC_DECL, (yyvsp[-4].sval), (yyvsp[-2].nval), (yyvsp[0].nval), NULL);
    }
#line 1691 "parser.tab.c"
    break;

  case 52: /* params: %empty  */
#line 213 "parser.y"
                { (yyval.nval) = NULL; }
#line 1697 "parser.tab.c"
    break;

  case 53: /* params: IDENTIFIER  */
#line 214 "parser.y"
                 { (yyval.nval) = create_node(NODE_PARAM_LIST, (yyvsp[0].sval), NULL, NULL, NULL); }
#line 1703 "parser.tab.c"
    break;

  case 54: /* params: IDENTIFIER COMMA params  */
#line 215 "parser.y"
                              {
        (yyval.nval) = create_node(NODE_PARAM_LIST, (yyvsp[-2].sval), NULL, NULL, (yyvsp[0].nval));
    }
#line 1711 "parser.tab.c"
    break;

  case 55: /* params: type_specifier IDENTIFIER  */
#line 218 "parser.y"
                                { (yyval.nval) = create_node(NODE_PARAM_LIST, (yyvsp[0].sval), NULL, NULL, NULL); }
#line 1717 "parser.tab.c"
    break;

  case 56: /* params: type_specifier IDENTIFIER COMMA params  */
#line 219 "parser.y"
                                             {
        (yyval.nval) = create_node(NODE_PARAM_LIST, (yyvsp[-2].sval), NULL, NULL, (yyvsp[0].nval));
    }
#line 1725 "parser.tab.c"
    break;

  case 57: /* return_stmt: RETURN expression SEMICOLON  */
#line 225 "parser.y"
                                {
        (yyval.nval) = create_node(NODE_RETURN, NULL, (yyvsp[-1].nval), NULL, NULL);
    }
#line 1733 "parser.tab.c"
    break;

  case 58: /* block: LBRACE statement_list RBRACE  */
#line 231 "parser.y"
                                 {
        (yyval.nval) = create_node(NODE_BLOCK, NULL, (yyvsp[-1].nval), NULL, NULL);
    }
#line 1741 "parser.tab.c"
    break;

  case 59: /* block: LBRACE RBRACE  */
#line 234 "parser.y"
                    {
        (yyval.nval) = create_node(NODE_BLOCK, NULL, NULL, NULL, NULL);
    }
#line 1749 "parser.tab.c"
    break;

  case 60: /* expression: term  */
#line 240 "parser.y"
         { (yyval.nval) = (yyvsp[0].nval); }
#line 1755 "parser.tab.c"
    break;

  case 61: /* expression: expression PLUS term  */
#line 241 "parser.y"
                           { (yyval.nval) = create_node(NODE_BINARY_OP, "+", (yyvsp[-2].nval), NULL, (yyvsp[0].nval)); }
#line 1761 "parser.tab.c"
    break;

  case 62: /* expression: expression MINUS term  */
#line 242 "parser.y"
                            { (yyval.nval) = create_node(NODE_BINARY_OP, "-", (yyvsp[-2].nval), NULL, (yyvsp[0].nval)); }
#line 1767 "parser.tab.c"
    break;

  case 63: /* expression: expression LT term  */
#line 243 "parser.y"
                         { (yyval.nval) = create_node(NODE_BINARY_OP, "<", (yyvsp[-2].nval), NULL, (yyvsp[0].nval)); }
#line 1773 "parser.tab.c"
    break;

  case 64: /* expression: expression GT term  */
#line 244 "parser.y"
                         { (yyval.nval) = create_node(NODE_BINARY_OP, ">", (yyvsp[-2].nval), NULL, (yyvsp[0].nval)); }
#line 1779 "parser.tab.c"
    break;

  case 65: /* expression: expression LE term  */
#line 245 "parser.y"
                         { (yyval.nval) = create_node(NODE_BINARY_OP, "<=", (yyvsp[-2].nval), NULL, (yyvsp[0].nval)); }
#line 1785 "parser.tab.c"
    break;

  case 66: /* expression: expression GE term  */
#line 246 "parser.y"
                         { (yyval.nval) = create_node(NODE_BINARY_OP, ">=", (yyvsp[-2].nval), NULL, (yyvsp[0].nval)); }
#line 1791 "parser.tab.c"
    break;

  case 67: /* expression: expression EQ term  */
#line 247 "parser.y"
                         { (yyval.nval) = create_node(NODE_BINARY_OP, "==", (yyvsp[-2].nval), NULL, (yyvsp[0].nval)); }
#line 1797 "parser.tab.c"
    break;

  case 68: /* expression: expression NE term  */
#line 248 "parser.y"
                         { (yyval.nval) = create_node(NODE_BINARY_OP, "!=", (yyvsp[-2].nval), NULL, (yyvsp[0].nval)); }
#line 1803 "parser.tab.c"
    break;

  case 69: /* expression: expression AND term  */
#line 249 "parser.y"
                          { (yyval.nval) = create_node(NODE_BINARY_OP, "&&", (yyvsp[-2].nval), NULL, (yyvsp[0].nval)); }
#line 1809 "parser.tab.c"
    break;

  case 70: /* expression: expression OR term  */
#line 250 "parser.y"
                         { (yyval.nval) = create_node(NODE_BINARY_OP, "||", (yyvsp[-2].nval), NULL, (yyvsp[0].nval)); }
#line 1815 "parser.tab.c"
    break;

  case 71: /* expression: expression QMARK expression COLON expression  */
#line 251 "parser.y"
                                                   { (yyval.nval) = create_node(NODE_TERNARY, NULL, (yyvsp[-4].nval), (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 1821 "parser.tab.c"
    break;

  case 72: /* term: unary  */
#line 255 "parser.y"
          { (yyval.nval) = (yyvsp[0].nval); }
#line 1827 "parser.tab.c"
    break;

  case 73: /* term: term MULT unary  */
#line 256 "parser.y"
                      { (yyval.nval) = create_node(NODE_BINARY_OP, "*", (yyvsp[-2].nval), NULL, (yyvsp[0].nval)); }
#line 1833 "parser.tab.c"
    break;

  case 74: /* term: term DIV unary  */
#line 257 "parser.y"
                     { (yyval.nval) = create_node(NODE_BINARY_OP, "/", (yyvsp[-2].nval), NULL, (yyvsp[0].nval)); }
#line 1839 "parser.tab.c"
    break;

  case 75: /* term: term MOD unary  */
#line 258 "parser.y"
                     { (yyval.nval) = create_node(NODE_BINARY_OP, "%", (yyvsp[-2].nval), NULL, (yyvsp[0].nval)); }
#line 1845 "parser.tab.c"
    break;

  case 76: /* unary: factor  */
#line 262 "parser.y"
           { (yyval.nval) = (yyvsp[0].nval); }
#line 1851 "parser.tab.c"
    break;

  case 77: /* unary: MINUS unary  */
#line 263 "parser.y"
                  { (yyval.nval) = create_node(NODE_UNARY_OP, "-", (yyvsp[0].nval), NULL, NULL); }
#line 1857 "parser.tab.c"
    break;

  case 78: /* unary: NOT unary  */
#line 264 "parser.y"
                { (yyval.nval) = create_node(NODE_UNARY_OP, "!", (yyvsp[0].nval), NULL, NULL); }
#line 1863 "parser.tab.c"
    break;

  case 79: /* factor: NUMBER  */
#line 268 "parser.y"
           { (yyval.nval) = create_node(NODE_NUMBER, (yyvsp[0].sval), NULL, NULL, NULL); }
#line 1869 "parser.tab.c"
    break;

  case 80: /* factor: STRING_LITERAL  */
#line 269 "parser.y"
                     { (yyval.nval) = create_node(NODE_STRING, (yyvsp[0].sval), NULL, NULL, NULL); }
#line 1875 "parser.tab.c"
    break;

  case 81: /* factor: IDENTIFIER  */
#line 270 "parser.y"
                 { (yyval.nval) = create_node(NODE_IDENTIFIER, (yyvsp[0].sval), NULL, NULL, NULL); }
#line 1881 "parser.tab.c"
    break;

  case 82: /* factor: func_call  */
#line 271 "parser.y"
                { (yyval.nval) = (yyvsp[0].nval); }
#line 1887 "parser.tab.c"
    break;

  case 83: /* factor: LPAREN expression RPAREN  */
#line 272 "parser.y"
                               { (yyval.nval) = (yyvsp[-1].nval); }
#line 1893 "parser.tab.c"
    break;

  case 84: /* func_call: IDENTIFIER LPAREN args RPAREN  */
#line 276 "parser.y"
                                  {
        (yyval.nval) = create_node(NODE_CALL, (yyvsp[-3].sval), (yyvsp[-1].nval), NULL, NULL);
    }
#line 1901 "parser.tab.c"
    break;

  case 85: /* args: %empty  */
#line 282 "parser.y"
                { (yyval.nval) = NULL; }
#line 1907 "parser.tab.c"
    break;

  case 86: /* args: expression  */
#line 283 "parser.y"
                 { (yyval.nval) = create_node(NODE_ARG_LIST, NULL, (yyvsp[0].nval), NULL, NULL); }
#line 1913 "parser.tab.c"
    break;

  case 87: /* args: expression COMMA args  */
#line 284 "parser.y"
                            {
        (yyval.nval) = create_node(NODE_ARG_LIST, NULL, (yyvsp[-2].nval), NULL, (yyvsp[0].nval));
    }
#line 1921 "parser.tab.c"
    break;


#line 1925 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

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
                      yytoken, &yylval);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 289 "parser.y"


void yyerror(const char* s) {
    fprintf(stderr, "Error at line %d: %s\n", line_num, s);
}
