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
#line 1 "language.y"

#include <iostream>
#include "tables.h"
extern int yylex();
int yyerror(const char* s);
extern FILE* yyin; 
extern int line_nr;
using namespace std;

bool ok = true;

struct vec{
    int nr_elem = 0;
    char* value[10];
};

struct expr_symbol
{
    bool bool_value;
    char* value;
    char* type;
};

struct par
{
    char* type;
    char* value;
};

struct call_parameters
{
    int cnt = 0;
    par* parameters[100];
};



#line 109 "language.tab.c"

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

#include "language.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID_VAL = 3,                     /* ID_VAL  */
  YYSYMBOL_INT_TYPE = 4,                   /* INT_TYPE  */
  YYSYMBOL_FLOAT_TYPE = 5,                 /* FLOAT_TYPE  */
  YYSYMBOL_CHAR_TYPE = 6,                  /* CHAR_TYPE  */
  YYSYMBOL_STRING_TYPE = 7,                /* STRING_TYPE  */
  YYSYMBOL_BOOL_TYPE = 8,                  /* BOOL_TYPE  */
  YYSYMBOL_VOID_TYPE = 9,                  /* VOID_TYPE  */
  YYSYMBOL_CLASS_TYPE = 10,                /* CLASS_TYPE  */
  YYSYMBOL_FOR_INST = 11,                  /* FOR_INST  */
  YYSYMBOL_WHILE_INST = 12,                /* WHILE_INST  */
  YYSYMBOL_IF_INST = 13,                   /* IF_INST  */
  YYSYMBOL_ELSE_INST = 14,                 /* ELSE_INST  */
  YYSYMBOL_DO_INST = 15,                   /* DO_INST  */
  YYSYMBOL_INT_VAL = 16,                   /* INT_VAL  */
  YYSYMBOL_FLOAT_VAL = 17,                 /* FLOAT_VAL  */
  YYSYMBOL_CHAR_VAL = 18,                  /* CHAR_VAL  */
  YYSYMBOL_STRING_VAL = 19,                /* STRING_VAL  */
  YYSYMBOL_BOOL_VAL = 20,                  /* BOOL_VAL  */
  YYSYMBOL_READ = 21,                      /* READ  */
  YYSYMBOL_WRITE = 22,                     /* WRITE  */
  YYSYMBOL_FUNC = 23,                      /* FUNC  */
  YYSYMBOL_MAIN_PRG = 24,                  /* MAIN_PRG  */
  YYSYMBOL_EVAL = 25,                      /* EVAL  */
  YYSYMBOL_TYPEOF = 26,                    /* TYPEOF  */
  YYSYMBOL_RETURN = 27,                    /* RETURN  */
  YYSYMBOL_PLUS = 28,                      /* PLUS  */
  YYSYMBOL_MINUS = 29,                     /* MINUS  */
  YYSYMBOL_MULT = 30,                      /* MULT  */
  YYSYMBOL_DIV = 31,                       /* DIV  */
  YYSYMBOL_MOD = 32,                       /* MOD  */
  YYSYMBOL_ASSIGN = 33,                    /* ASSIGN  */
  YYSYMBOL_INC = 34,                       /* INC  */
  YYSYMBOL_DEC = 35,                       /* DEC  */
  YYSYMBOL_EQ = 36,                        /* EQ  */
  YYSYMBOL_NEQ = 37,                       /* NEQ  */
  YYSYMBOL_LT = 38,                        /* LT  */
  YYSYMBOL_LE = 39,                        /* LE  */
  YYSYMBOL_GT = 40,                        /* GT  */
  YYSYMBOL_GE = 41,                        /* GE  */
  YYSYMBOL_AND = 42,                       /* AND  */
  YYSYMBOL_OR = 43,                        /* OR  */
  YYSYMBOL_LET = 44,                       /* LET  */
  YYSYMBOL_GET = 45,                       /* GET  */
  YYSYMBOL_NOT = 46,                       /* NOT  */
  YYSYMBOL_47_ = 47,                       /* '{'  */
  YYSYMBOL_48_ = 48,                       /* '}'  */
  YYSYMBOL_49_ = 49,                       /* ','  */
  YYSYMBOL_50_ = 50,                       /* '('  */
  YYSYMBOL_51_ = 51,                       /* ')'  */
  YYSYMBOL_52_ = 52,                       /* '['  */
  YYSYMBOL_53_ = 53,                       /* ']'  */
  YYSYMBOL_54_ = 54,                       /* ';'  */
  YYSYMBOL_55_ = 55,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 56,                  /* $accept  */
  YYSYMBOL_prog = 57,                      /* prog  */
  YYSYMBOL_58_1 = 58,                      /* $@1  */
  YYSYMBOL_global_variables = 59,          /* global_variables  */
  YYSYMBOL_classes = 60,                   /* classes  */
  YYSYMBOL_class = 61,                     /* class  */
  YYSYMBOL_class_declaration = 62,         /* class_declaration  */
  YYSYMBOL_class_name = 63,                /* class_name  */
  YYSYMBOL_body_class = 64,                /* body_class  */
  YYSYMBOL_class_var_list = 65,            /* class_var_list  */
  YYSYMBOL_class_var = 66,                 /* class_var  */
  YYSYMBOL_functions = 67,                 /* functions  */
  YYSYMBOL_function = 68,                  /* function  */
  YYSYMBOL_function_name = 69,             /* function_name  */
  YYSYMBOL_function_parameters = 70,       /* function_parameters  */
  YYSYMBOL_parameter = 71,                 /* parameter  */
  YYSYMBOL_body = 72,                      /* body  */
  YYSYMBOL_instr = 73,                     /* instr  */
  YYSYMBOL_write = 74,                     /* write  */
  YYSYMBOL_read = 75,                      /* read  */
  YYSYMBOL_control = 76,                   /* control  */
  YYSYMBOL_for = 77,                       /* for  */
  YYSYMBOL_while = 78,                     /* while  */
  YYSYMBOL_if = 79,                        /* if  */
  YYSYMBOL_do = 80,                        /* do  */
  YYSYMBOL_condition = 81,                 /* condition  */
  YYSYMBOL_expression = 82,                /* expression  */
  YYSYMBOL_assignement = 83,               /* assignement  */
  YYSYMBOL_call_params = 84,               /* call_params  */
  YYSYMBOL_call_param = 85,                /* call_param  */
  YYSYMBOL_declaration = 86,               /* declaration  */
  YYSYMBOL_vector = 87,                    /* vector  */
  YYSYMBOL_type = 88,                      /* type  */
  YYSYMBOL_value = 89,                     /* value  */
  YYSYMBOL_return = 90                     /* return  */
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   490

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  208

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


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
      50,    51,     2,     2,    49,     2,    55,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    54,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
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
      45,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    85,    85,    85,    88,    89,    92,    93,    96,    99,
     101,   104,   107,   108,   109,   112,   114,   115,   118,   119,
     120,   123,   127,   130,   131,   135,   138,   146,   147,   150,
     151,   152,   153,   154,   157,   159,   173,   174,   175,   176,
     178,   183,   194,   204,   212,   215,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   255,   267,   291,   310,   331,
     335,   340,   358,   387,   423,   442,   456,   477,   487,   499,
     508,   509,   517,   533,   584,   611,   612,   620,   621,   622,
     623,   624,   625,   628,   629,   630,   631,   632,   635
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
  "\"end of file\"", "error", "\"invalid token\"", "ID_VAL", "INT_TYPE",
  "FLOAT_TYPE", "CHAR_TYPE", "STRING_TYPE", "BOOL_TYPE", "VOID_TYPE",
  "CLASS_TYPE", "FOR_INST", "WHILE_INST", "IF_INST", "ELSE_INST",
  "DO_INST", "INT_VAL", "FLOAT_VAL", "CHAR_VAL", "STRING_VAL", "BOOL_VAL",
  "READ", "WRITE", "FUNC", "MAIN_PRG", "EVAL", "TYPEOF", "RETURN", "PLUS",
  "MINUS", "MULT", "DIV", "MOD", "ASSIGN", "INC", "DEC", "EQ", "NEQ", "LT",
  "LE", "GT", "GE", "AND", "OR", "LET", "GET", "NOT", "'{'", "'}'", "','",
  "'('", "')'", "'['", "']'", "';'", "'.'", "$accept", "prog", "$@1",
  "global_variables", "classes", "class", "class_declaration",
  "class_name", "body_class", "class_var_list", "class_var", "functions",
  "function", "function_name", "function_parameters", "parameter", "body",
  "instr", "write", "read", "control", "for", "while", "if", "do",
  "condition", "expression", "assignement", "call_params", "call_param",
  "declaration", "vector", "type", "value", "return", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-114)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     475,  -114,  -114,  -114,  -114,  -114,  -114,    14,  -114,   475,
      21,  -114,     3,  -114,   -25,    27,   475,  -114,    39,   -29,
      22,    42,    17,   152,   378,  -114,    73,  -114,    30,  -114,
     475,  -114,  -114,   475,   -39,  -114,  -114,  -114,  -114,  -114,
      35,    36,   152,   443,  -114,    34,    38,  -114,    39,    42,
      41,    45,   -34,  -114,    93,    52,    94,   152,   152,   111,
     152,   152,   152,   152,   152,  -114,  -114,  -114,    71,  -114,
    -114,  -114,   399,   475,    75,    79,  -114,   443,     8,  -114,
    -114,   340,   348,  -114,   455,   455,    40,    40,    40,    78,
     -27,    82,    87,    88,    97,   144,   152,   201,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,   339,
      92,   152,  -114,  -114,  -114,    92,   152,    98,   410,   149,
     475,   110,   110,   399,  -114,   443,  -114,  -114,   152,   176,
     105,   101,  -114,    33,  -114,   443,  -114,    15,   120,   123,
     141,   132,   110,   395,   443,   405,   222,   443,  -114,   142,
    -114,  -114,  -114,    92,  -114,   162,   166,   152,   110,  -114,
     110,   110,   110,   110,   110,   110,   110,   110,   164,   168,
     205,  -114,  -114,   152,   152,   443,   121,    18,    18,  -114,
    -114,   156,   425,  -114,  -114,   399,   399,   169,   443,   443,
     152,   247,   268,   110,   358,  -114,   204,   415,   173,   -11,
    -114,   399,   399,  -114,   293,   314,  -114,  -114
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,    87,    88,    90,    91,    89,    92,     0,     7,     5,
       0,     1,    17,     4,    80,     0,     0,     6,    14,     0,
       0,    17,     0,     0,     0,    10,     0,    15,     8,    13,
       5,     2,    16,    24,    64,    93,    94,    95,    96,    97,
       0,     0,     0,    81,    65,     0,     0,    21,     0,    17,
       0,     0,     0,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    62,    63,    84,    82,    12,
      11,     9,     0,     0,     0,    25,    67,    79,     0,    78,
      68,     0,     0,    61,    56,    57,    58,    59,    60,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,    32,
      33,    31,    38,    37,    36,    39,    30,    29,    22,     0,
       0,     0,    66,    69,    70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    35,    34,     3,    27,     0,     0,
       0,     0,    77,     0,    86,    71,    75,     0,     0,     0,
       0,     0,     0,     0,    55,     0,     0,    98,    20,     0,
      19,    26,    83,     0,    74,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,    85,     0,     0,    76,     0,    46,    47,    48,
      50,    53,    52,    49,    51,     0,     0,     0,    73,    72,
       0,     0,     0,     0,     0,    41,    42,     0,     0,     0,
      45,     0,     0,    44,     0,     0,    40,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -114,  -114,  -114,    13,  -114,  -114,  -114,  -114,  -114,  -114,
     184,   -16,  -114,  -114,  -114,   148,  -102,   -85,  -114,  -114,
    -114,  -114,  -114,    37,  -114,  -113,   -23,  -114,   122,   127,
       1,  -114,   -13,   -20,   112
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,    51,     8,    12,    17,    18,    19,    50,    28,
      29,    20,    21,    22,    52,    53,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   143,   144,   106,    78,    79,
     107,   133,    10,    44,   130
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      43,     9,    93,    26,    46,    32,   116,   129,    23,   145,
       9,    55,   127,    15,    11,    73,    56,    74,    30,    59,
      54,   146,    13,   117,    14,   118,    16,    24,   119,   159,
      25,     9,    77,    70,    81,    82,   202,    84,    85,    86,
      87,    88,    27,    49,   127,   176,    31,   177,   178,   179,
     180,   181,   182,   183,   184,    34,   162,   111,   163,   112,
      54,   127,   166,   167,   111,    16,   154,    33,    35,    36,
      37,    38,    39,   125,    65,    66,    47,    40,    41,    48,
     197,   152,   153,   191,   192,    57,    58,    67,    77,    71,
     131,    68,    72,   135,    77,   134,    75,    80,   139,   204,
     205,    34,    42,    76,    89,   147,   127,   127,    35,    36,
      37,    38,    39,    34,    35,    36,    37,    38,    39,   127,
     127,   141,   109,    40,    41,   115,    35,    36,    37,    38,
      39,   110,   120,   172,   175,    40,    41,   121,   122,    60,
      61,    62,    63,    64,   123,    65,    66,   124,    42,   136,
     188,   189,   140,   150,   151,    34,   142,   160,   161,   162,
      42,   163,    83,   164,   165,   166,   167,   194,    35,    36,
      37,    38,    39,   155,   157,   190,   156,    40,    41,    90,
       1,     2,     3,     4,     5,     6,   158,    91,    92,    93,
     171,    94,   160,   161,   162,   173,   163,    95,    96,   174,
     166,   167,    42,   128,    90,     1,     2,     3,     4,     5,
       6,   185,    91,    92,    93,   186,    94,   187,   199,   193,
     201,   108,    95,    96,   148,    90,     1,     2,     3,     4,
       5,     6,    69,    91,    92,    93,   203,    94,   132,   137,
       0,   149,     0,    95,    96,     0,     0,     0,     0,   126,
      90,     1,     2,     3,     4,     5,     6,     0,    91,    92,
      93,     0,    94,     0,     0,     0,     0,     0,    95,    96,
     170,    90,     1,     2,     3,     4,     5,     6,     0,    91,
      92,    93,     0,    94,     0,     0,     0,     0,     0,    95,
      96,     0,     0,     0,     0,   195,    90,     1,     2,     3,
       4,     5,     6,     0,    91,    92,    93,     0,    94,     0,
       0,     0,     0,     0,    95,    96,   196,    90,     1,     2,
       3,     4,     5,     6,     0,    91,    92,    93,     0,    94,
       0,     0,     0,     0,     0,    95,    96,     0,     0,     0,
       0,   206,    90,     1,     2,     3,     4,     5,     6,     0,
      91,    92,    93,     0,    94,     0,     0,     0,     0,     0,
      95,    96,   207,     0,     0,     0,   128,     0,    60,    61,
      62,    63,    64,     0,    65,    66,    60,    61,    62,    63,
      64,    45,    65,    66,     0,     0,    60,    61,    62,    63,
      64,   113,    65,    66,    35,    36,    37,    38,    39,   114,
       0,     0,    90,     1,     2,     3,     4,     5,     6,   198,
      91,    92,    93,   138,    94,     0,     0,     0,     0,     0,
      95,    96,     0,     0,     0,     0,    35,    36,    37,    38,
      39,   160,   161,   162,     0,   163,     0,   164,   165,   166,
     167,   160,   161,   162,     0,   163,   168,   164,   165,   166,
     167,   160,   161,   162,     0,   163,   169,   164,   165,   166,
     167,   160,   161,   162,     0,   163,   200,   164,     0,   166,
     167,    60,    61,    62,    63,    64,     0,    65,    66,     1,
       2,     3,     4,     5,     6,    62,    63,    64,     0,    65,
      66
};

static const yytype_int16 yycheck[] =
{
      23,     0,    13,    16,    24,    21,    33,   109,    33,   122,
       9,    50,    97,    10,     0,    49,    55,    51,    47,    42,
      33,   123,     9,    50,     3,    52,    23,    52,    55,   142,
       3,    30,    55,    49,    57,    58,    47,    60,    61,    62,
      63,    64,     3,    30,   129,   158,    24,   160,   161,   162,
     163,   164,   165,   166,   167,     3,    38,    49,    40,    51,
      73,   146,    44,    45,    49,    23,    51,    50,    16,    17,
      18,    19,    20,    96,    34,    35,     3,    25,    26,    49,
     193,    48,    49,   185,   186,    50,    50,    53,   111,    48,
     110,    53,    47,   116,   117,   115,     3,     3,   118,   201,
     202,     3,    50,    51,    33,   128,   191,   192,    16,    17,
      18,    19,    20,     3,    16,    17,    18,    19,    20,   204,
     205,   120,    47,    25,    26,    47,    16,    17,    18,    19,
      20,    52,    50,   153,   157,    25,    26,    50,    50,    28,
      29,    30,    31,    32,    47,    34,    35,     3,    50,    51,
     173,   174,     3,    48,    53,     3,    46,    36,    37,    38,
      50,    40,    51,    42,    43,    44,    45,   190,    16,    17,
      18,    19,    20,    53,    33,    54,    53,    25,    26,     3,
       4,     5,     6,     7,     8,     9,    54,    11,    12,    13,
      48,    15,    36,    37,    38,    33,    40,    21,    22,    33,
      44,    45,    50,    27,     3,     4,     5,     6,     7,     8,
       9,    47,    11,    12,    13,    47,    15,    12,    14,    50,
      47,    73,    21,    22,    48,     3,     4,     5,     6,     7,
       8,     9,    48,    11,    12,    13,   199,    15,   111,   117,
      -1,   129,    -1,    21,    22,    -1,    -1,    -1,    -1,    48,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      13,    -1,    15,    -1,    -1,    -1,    -1,    -1,    21,    22,
      48,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    13,    -1,    15,    -1,    -1,    -1,    -1,    -1,    21,
      22,    -1,    -1,    -1,    -1,    48,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    13,    -1,    15,    -1,
      -1,    -1,    -1,    -1,    21,    22,    48,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    13,    -1,    15,
      -1,    -1,    -1,    -1,    -1,    21,    22,    -1,    -1,    -1,
      -1,    48,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    13,    -1,    15,    -1,    -1,    -1,    -1,    -1,
      21,    22,    48,    -1,    -1,    -1,    27,    -1,    28,    29,
      30,    31,    32,    -1,    34,    35,    28,    29,    30,    31,
      32,     3,    34,    35,    -1,    -1,    28,    29,    30,    31,
      32,    51,    34,    35,    16,    17,    18,    19,    20,    51,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    51,
      11,    12,    13,     3,    15,    -1,    -1,    -1,    -1,    -1,
      21,    22,    -1,    -1,    -1,    -1,    16,    17,    18,    19,
      20,    36,    37,    38,    -1,    40,    -1,    42,    43,    44,
      45,    36,    37,    38,    -1,    40,    51,    42,    43,    44,
      45,    36,    37,    38,    -1,    40,    51,    42,    43,    44,
      45,    36,    37,    38,    -1,    40,    51,    42,    -1,    44,
      45,    28,    29,    30,    31,    32,    -1,    34,    35,     4,
       5,     6,     7,     8,     9,    30,    31,    32,    -1,    34,
      35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     6,     7,     8,     9,    57,    59,    86,
      88,     0,    60,    59,     3,    10,    23,    61,    62,    63,
      67,    68,    69,    33,    52,     3,    88,     3,    65,    66,
      47,    24,    67,    50,     3,    16,    17,    18,    19,    20,
      25,    26,    50,    82,    89,     3,    89,     3,    49,    59,
      64,    58,    70,    71,    88,    50,    55,    50,    50,    82,
      28,    29,    30,    31,    32,    34,    35,    53,    53,    66,
      67,    48,    47,    49,    51,     3,    51,    82,    84,    85,
       3,    82,    82,    51,    82,    82,    82,    82,    82,    33,
       3,    11,    12,    13,    15,    21,    22,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    83,    86,    71,    47,
      52,    49,    51,    51,    51,    47,    33,    50,    52,    55,
      50,    50,    50,    47,     3,    82,    48,    73,    27,    72,
      90,    89,    85,    87,    89,    82,    51,    84,     3,    89,
       3,    86,    46,    81,    82,    81,    72,    82,    48,    90,
      48,    53,    48,    49,    51,    53,    53,    33,    54,    81,
      36,    37,    38,    40,    42,    43,    44,    45,    51,    51,
      48,    48,    89,    33,    33,    82,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    47,    47,    12,    82,    82,
      54,    72,    72,    50,    82,    48,    48,    81,    51,    14,
      51,    47,    47,    79,    72,    72,    48,    48
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    58,    57,    59,    59,    60,    60,    61,    62,
      63,    64,    65,    65,    65,    66,    67,    67,    68,    68,
      68,    69,    70,    70,    70,    71,    71,    72,    72,    73,
      73,    73,    73,    73,    74,    75,    76,    76,    76,    76,
      77,    78,    79,    79,    79,    80,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    83,    83,    83,    83,    83,    83,    84,    84,    85,
      86,    86,    86,    86,    86,    87,    87,    88,    88,    88,
      88,    88,    88,    89,    89,    89,    89,    89,    90
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     8,     2,     0,     2,     0,     2,     4,
       2,     2,     3,     1,     0,     1,     2,     0,     8,     7,
       7,     3,     3,     1,     0,     2,     5,     2,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     1,
      11,     7,     7,    11,     9,     8,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     1,     3,     3,     3,     3,
       3,     3,     2,     2,     1,     1,     4,     3,     3,     4,
       4,     3,     6,     6,     4,     3,     5,     3,     1,     1,
       2,     4,     5,     9,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2
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
  case 2: /* $@1: %empty  */
#line 85 "language.y"
                                                    {char m[] = "main"; updateLastScope(m); updateLastFuncScope(m);}
#line 1380 "language.tab.c"
    break;

  case 9: /* class_declaration: class_name '{' body_class '}'  */
#line 99 "language.y"
                                                     {char g[] = "Global"; addClass((yyvsp[-3].string_val)); updateLastScope(g); updateLastFuncScope(g); }
#line 1386 "language.tab.c"
    break;

  case 10: /* class_name: CLASS_TYPE ID_VAL  */
#line 101 "language.y"
                                   { (yyval.string_val) = (yyvsp[0].string_val); updateLastClassName((yyvsp[0].string_val)); updateLastFuncScope(strdup((yyvsp[0].string_val))); updateLastScope(strdup((yyvsp[0].string_val)));}
#line 1392 "language.tab.c"
    break;

  case 15: /* class_var: ID_VAL  */
#line 112 "language.y"
                      {updateLastType(lastClassName); char c[] ="Class"; addSymbol("Variable", strdup((yyvsp[0].string_val)), NULL, c); addVariableClass(lastClassName, strdup((yyvsp[0].string_val))); }
#line 1398 "language.tab.c"
    break;

  case 18: /* function: function_name '(' function_parameters ')' '{' body return '}'  */
#line 118 "language.y"
                                                                           {if(strcmp((yyvsp[-1].expr)->type,lastDeclaredFunctionType)) {yyerror("Error! Wrong conversion type!"); return -1;}  addFunction(strdup((yyvsp[-7].string_val)), (yyvsp[-5].params)->type, (yyvsp[-5].params)->type_and_name); }
#line 1404 "language.tab.c"
    break;

  case 19: /* function: function_name '(' function_parameters ')' '{' return '}'  */
#line 119 "language.y"
                                                                        {if(strcmp((yyvsp[-1].expr)->type,lastDeclaredFunctionType)) {yyerror("Error! Wrong conversion type!"); return -1;} addFunction((yyvsp[-6].string_val), (yyvsp[-4].params)->type, (yyvsp[-4].params)->type_and_name);}
#line 1410 "language.tab.c"
    break;

  case 20: /* function: function_name '(' function_parameters ')' '{' body '}'  */
#line 120 "language.y"
                                                                      {char v[] = "void"; addFunctionType(v); addFunction(strdup((yyvsp[-6].string_val)), (yyvsp[-4].params)->type, (yyvsp[-4].params)->type_and_name); }
#line 1416 "language.tab.c"
    break;

  case 21: /* function_name: FUNC type ID_VAL  */
#line 123 "language.y"
                                 {(yyval.string_val) = strdup((yyvsp[0].string_val)); updateLastFuncScope(strdup((yyvsp[0].string_val))); updateLastScope(strdup((yyvsp[0].string_val))); addFunctionType(strdup((yyvsp[-1].string_val)));}
#line 1422 "language.tab.c"
    break;

  case 22: /* function_parameters: function_parameters ',' parameter  */
#line 127 "language.y"
                                                         {(yyval.params)->type_and_name = strcat(strdup((yyvsp[-2].params)->type_and_name), strcat(strdup(","), strdup((yyvsp[0].params)->type_and_name)));
                                             (yyval.params)->type = strcat((yyvsp[-2].params)->type,(yyvsp[0].params)->type);
                                             }
#line 1430 "language.tab.c"
    break;

  case 23: /* function_parameters: parameter  */
#line 130 "language.y"
                            {(yyval.params) = (yyvsp[0].params);}
#line 1436 "language.tab.c"
    break;

  case 24: /* function_parameters: %empty  */
#line 131 "language.y"
                  {(yyval.params)->type_and_name = strdup("No parameters"); (yyval.params)->type = strdup("No parameters");}
#line 1442 "language.tab.c"
    break;

  case 25: /* parameter: type ID_VAL  */
#line 135 "language.y"
                         { char z[] = "0"; addSymbol("Variable",strdup((yyvsp[0].string_val)), z, strdup((yyvsp[-1].string_val)));
                         (yyval.params)->type_and_name = strcat(strdup((yyvsp[-1].string_val)), (strcat(strdup(" "), strdup((yyvsp[0].string_val)))));
                         (yyval.params)->type = strdup((yyvsp[-1].string_val));}
#line 1450 "language.tab.c"
    break;

  case 26: /* parameter: type ID_VAL '[' value ']'  */
#line 138 "language.y"
                                          {addSymbol("Vector",strdup((yyvsp[-3].string_val)), strdup((yyvsp[-1].string_val)), strdup((yyvsp[-4].string_val)));
                         (yyval.params)->type_and_name = strcat(strdup((yyvsp[-4].string_val)), (strcat(strdup(" "), strdup((yyvsp[-3].string_val)))));
                         (yyval.params)->type = strdup((yyvsp[-4].string_val));}
#line 1458 "language.tab.c"
    break;

  case 35: /* read: READ ID_VAL  */
#line 160 "language.y"
    {
        int s = search(strdup((yyvsp[0].string_val)));
        if(s == -1)
        {
            yyerror("Error! Variable uninitialised!");
            return -1;
        }
        char z[] = "0";
        modifyVarValue(s,z);
    }
#line 1473 "language.tab.c"
    break;

  case 40: /* for: FOR_INST '(' declaration ';' condition ';' expression ')' '{' body '}'  */
#line 179 "language.y"
    {
        cout<<"FOR!"<<'\n'; // Execute the body of the for statement
    }
#line 1481 "language.tab.c"
    break;

  case 41: /* while: WHILE_INST '(' condition ')' '{' body '}'  */
#line 184 "language.y"
    {
        if ((yyvsp[-4].expr)->bool_value == true) {
             cout<<"TRUE"<<'\n';  // Execute the body of the if statement
        }
        else
        {
            cout<<"FALSE"<<'\n';
        }
    }
#line 1495 "language.tab.c"
    break;

  case 42: /* if: IF_INST '(' condition ')' '{' body '}'  */
#line 195 "language.y"
    {
        if ((yyvsp[-4].expr)->bool_value == true) {
             cout<<"TRUE"<<'\n';  // Execute the body of the if statement
        }
        else
        {
            cout<<"FALSE"<<'\n';
        }
    }
#line 1509 "language.tab.c"
    break;

  case 43: /* if: IF_INST '(' condition ')' '{' body '}' ELSE_INST '{' body '}'  */
#line 205 "language.y"
    {
        if ((yyvsp[-8].expr) -> bool_value == true) {
            cout<<"TRUE"<<'\n'; // Execute the body of the if statement
        } else {
            cout<<"FALSE"<<'\n'; // Execute the body of the else statement
        }
    }
#line 1521 "language.tab.c"
    break;

  case 46: /* condition: condition EQ condition  */
#line 217 "language.y"
                                  { if(strcmp((yyvsp[-2].expr)->type, (yyvsp[0].expr)->type)) {yyerror("Error! Wrong conversion type!"); return -1;}(yyval.expr)->type = (yyvsp[-2].expr)->type; if(strcmp((yyvsp[-2].expr)->value,(yyvsp[0].expr)->value) == 0) {(yyval.expr)->bool_value = true; strcpy((yyval.expr)->value,"1");} else {(yyval.expr)->bool_value = false; strcpy((yyval.expr)->value,"0");}}
#line 1527 "language.tab.c"
    break;

  case 47: /* condition: condition NEQ condition  */
#line 218 "language.y"
                                   { if(strcmp((yyvsp[-2].expr)->type, (yyvsp[0].expr)->type)) {yyerror("Error! Wrong conversion type!"); return -1;}(yyval.expr)->type = (yyvsp[-2].expr)->type; if(strcmp((yyvsp[-2].expr)->value,(yyvsp[0].expr)->value)) {(yyval.expr)->bool_value = true; strcpy((yyval.expr)->value,"1");} else {(yyval.expr)->bool_value = false; strcpy((yyval.expr)->value,"0");}}
#line 1533 "language.tab.c"
    break;

  case 48: /* condition: condition LT condition  */
#line 219 "language.y"
                                  { if(strcmp((yyvsp[-2].expr)->type, (yyvsp[0].expr)->type)) {yyerror("Error! Wrong conversion type!"); return -1;}(yyval.expr)->type = (yyvsp[-2].expr)->type; if((yyvsp[-2].expr)->value < (yyvsp[0].expr)->value) {(yyval.expr)->bool_value = true; strcpy((yyval.expr)->value,"1");} else {(yyval.expr)->bool_value = false; strcpy((yyval.expr)->value,"0");}}
#line 1539 "language.tab.c"
    break;

  case 49: /* condition: condition LET condition  */
#line 220 "language.y"
                                   { if(strcmp((yyvsp[-2].expr)->type, (yyvsp[0].expr)->type)) {yyerror("Error! Wrong conversion type!"); return -1;}(yyval.expr)->type = (yyvsp[-2].expr)->type; if((yyvsp[-2].expr)->value <= (yyvsp[0].expr)->value) {(yyval.expr)->bool_value = true; strcpy((yyval.expr)->value,"1");} else {(yyval.expr)->bool_value = false; strcpy((yyval.expr)->value,"0");}}
#line 1545 "language.tab.c"
    break;

  case 50: /* condition: condition GT condition  */
#line 221 "language.y"
                                  { if(strcmp((yyvsp[-2].expr)->type, (yyvsp[0].expr)->type)) {yyerror("Error! Wrong conversion type!"); return -1;}(yyval.expr)->type = (yyvsp[-2].expr)->type; if((yyvsp[-2].expr)->value > (yyvsp[0].expr)->value) {(yyval.expr)->bool_value = true; strcpy((yyval.expr)->value,"1");} else {(yyval.expr)->bool_value = false; strcpy((yyval.expr)->value,"0");}}
#line 1551 "language.tab.c"
    break;

  case 51: /* condition: condition GET condition  */
#line 222 "language.y"
                                   { if(strcmp((yyvsp[-2].expr)->type, (yyvsp[0].expr)->type)) {yyerror("Error! Wrong conversion type!"); return -1;}(yyval.expr)->type = (yyvsp[-2].expr)->type; if((yyvsp[-2].expr)->value >= (yyvsp[0].expr)->value) {(yyval.expr)->bool_value = true; strcpy((yyval.expr)->value,"1");} else {(yyval.expr)->bool_value = false; strcpy((yyval.expr)->value,"0");}}
#line 1557 "language.tab.c"
    break;

  case 52: /* condition: condition OR condition  */
#line 223 "language.y"
                                  { if(strcmp((yyvsp[-2].expr)->type, (yyvsp[0].expr)->type)) {yyerror("Error! Wrong conversion type!"); return -1;}(yyval.expr)->type = (yyvsp[-2].expr)->type; if((yyvsp[-2].expr)->bool_value || (yyvsp[0].expr)->bool_value) {(yyval.expr)->bool_value = true; strcpy((yyval.expr)->value,"1");} else {(yyval.expr)->bool_value = false; strcpy((yyval.expr)->value,"0");}}
#line 1563 "language.tab.c"
    break;

  case 53: /* condition: condition AND condition  */
#line 224 "language.y"
                                   { if(strcmp((yyvsp[-2].expr)->type, (yyvsp[0].expr)->type)) {yyerror("Error! Wrong conversion type!"); return -1;}(yyval.expr)->type = (yyvsp[-2].expr)->type; if((yyvsp[-2].expr)->bool_value && (yyvsp[0].expr)->bool_value) {(yyval.expr)->bool_value = true; strcpy((yyval.expr)->value,"1");} else {(yyval.expr)->bool_value = false; strcpy((yyval.expr)->value,"0");}}
#line 1569 "language.tab.c"
    break;

  case 54: /* condition: NOT condition  */
#line 225 "language.y"
                         { (yyvsp[0].expr)->bool_value = !(yyvsp[0].expr)->bool_value; (yyval.expr) = (yyvsp[0].expr);}
#line 1575 "language.tab.c"
    break;

  case 55: /* condition: expression  */
#line 226 "language.y"
                     {(yyval.expr) = (yyvsp[0].expr);}
#line 1581 "language.tab.c"
    break;

  case 56: /* expression: expression PLUS expression  */
#line 230 "language.y"
                                       {if(strcmp((yyvsp[-2].expr)->type, (yyvsp[0].expr)->type) || (strcmp((yyvsp[-2].expr)->type,"int") && strcmp((yyvsp[-2].expr)->type,"float"))) {yyerror("Error! Wrong conversion type!"); return -1;}(yyval.expr)->type = (yyvsp[-2].expr)->type;  strcpy((yyval.expr)->value,itoa(atoi((yyvsp[-2].expr)->value) + atoi((yyvsp[0].expr)->value))); strcmp((yyval.expr)->value,"0") == 0 ? (yyval.expr)->bool_value = true : (yyval.expr)->bool_value = false;}
#line 1587 "language.tab.c"
    break;

  case 57: /* expression: expression MINUS expression  */
#line 231 "language.y"
                                       { if(strcmp((yyvsp[-2].expr)->type, (yyvsp[0].expr)->type) ||(strcmp((yyvsp[-2].expr)->type,"int") && strcmp((yyvsp[-2].expr)->type,"float"))) {yyerror("Error! Wrong conversion type!"); return -1;}(yyval.expr)->type = (yyvsp[-2].expr)->type;  strcpy((yyval.expr)->value,itoa(atoi((yyvsp[-2].expr)->value) - atoi((yyvsp[0].expr)->value))); strcmp((yyval.expr)->value,"0") == 0 ? (yyval.expr)->bool_value = true : (yyval.expr)->bool_value = false;}
#line 1593 "language.tab.c"
    break;

  case 58: /* expression: expression MULT expression  */
#line 232 "language.y"
                                      { if(strcmp((yyvsp[-2].expr)->type, (yyvsp[0].expr)->type) ||(strcmp((yyvsp[-2].expr)->type,"int") && strcmp((yyvsp[-2].expr)->type,"float"))) {yyerror("Error! Wrong conversion type!"); return -1;}(yyval.expr)->type = (yyvsp[-2].expr)->type;  strcpy((yyval.expr)->value,itoa(atoi((yyvsp[-2].expr)->value) * atoi((yyvsp[0].expr)->value))); strcmp((yyval.expr)->value,"0") == 0 ? (yyval.expr)->bool_value = true : (yyval.expr)->bool_value = false;}
#line 1599 "language.tab.c"
    break;

  case 59: /* expression: expression DIV expression  */
#line 233 "language.y"
                                     { if(strcmp((yyvsp[-2].expr)->type, (yyvsp[0].expr)->type) || (strcmp((yyvsp[-2].expr)->type,"int") && strcmp((yyvsp[-2].expr)->type,"float"))) {yyerror("Error! Wrong conversion type!"); return -1;} if(strcmp((yyvsp[0].expr)->value,"0") == 0) {yyerror("Error! Cannot divide by 0!"); return -1;} (yyval.expr)->type = (yyvsp[-2].expr)->type;  strcpy((yyval.expr)->value,itoa(atoi((yyvsp[-2].expr)->value) / atoi((yyvsp[0].expr)->value))); strcmp((yyval.expr)->value,"0") == 0 ? (yyval.expr)->bool_value = true : (yyval.expr)->bool_value = false;}
#line 1605 "language.tab.c"
    break;

  case 60: /* expression: expression MOD expression  */
#line 234 "language.y"
                                     { if(strcmp((yyvsp[-2].expr)->type, (yyvsp[0].expr)->type) || (strcmp((yyvsp[-2].expr)->type,"int") && strcmp((yyvsp[-2].expr)->type,"float"))) {yyerror("Error! Wrong conversion type!"); return -1;}if(strcmp((yyvsp[0].expr)->value,"0") == 0) {yyerror("Error! Cannot divide by 0!"); return -1;} (yyval.expr)->type = (yyvsp[-2].expr)->type; strcpy((yyval.expr)->value,itoa(atoi((yyvsp[-2].expr)->value) % atoi((yyvsp[0].expr)->value))); strcmp((yyval.expr)->value,"0") == 0 ? (yyval.expr)->bool_value = true : (yyval.expr)->bool_value = false;}
#line 1611 "language.tab.c"
    break;

  case 61: /* expression: '(' expression ')'  */
#line 235 "language.y"
                              {(yyval.expr) = (yyvsp[-1].expr);}
#line 1617 "language.tab.c"
    break;

  case 62: /* expression: expression INC  */
#line 236 "language.y"
                        {if(strcmp((yyvsp[-1].expr)->type,"int")) {yyerror("Error! You can't increment on a non integer!"); return -1;} (yyval.expr)->type = (yyvsp[-1].expr)->type; strcpy((yyval.expr)->value,itoa(atoi((yyvsp[-1].expr)->value) + 1)); strcmp((yyval.expr)->value,"0") == 0 ? (yyval.expr)->bool_value = true : (yyval.expr)->bool_value = false;}
#line 1623 "language.tab.c"
    break;

  case 63: /* expression: expression DEC  */
#line 237 "language.y"
                        {if(strcmp((yyvsp[-1].expr)->type,"int")) {yyerror("Error! You can't decrement on a non integer!"); return -1;} (yyval.expr)->type = (yyvsp[-1].expr)->type; strcpy((yyval.expr)->value,itoa(atoi((yyvsp[-1].expr)->value) - 1)); strcmp((yyval.expr)->value,"0") == 0 ? (yyval.expr)->bool_value = true : (yyval.expr)->bool_value = false;}
#line 1629 "language.tab.c"
    break;

  case 64: /* expression: ID_VAL  */
#line 239 "language.y"
         {
            int s = search(strdup((yyvsp[0].string_val)));
            if(s == -1 || symbol_table[s].value == NULL)
            {
                yyerror("Error! Variable uninitialised!");
                return -1;
            }
            (yyval.expr)->value = (char*) malloc (60);
            strcpy((yyval.expr)->value, symbol_table[s].value);
            (yyval.expr)->type = (char*) malloc(60);
            strcpy((yyval.expr)->type, symbol_table[s].var_type);
            if(strcmp(symbol_table[s].value,"0"))
                (yyval.expr)->bool_value = false;
            else
                (yyval.expr)->bool_value = true;
         }
#line 1650 "language.tab.c"
    break;

  case 65: /* expression: value  */
#line 256 "language.y"
         {
            int s = search(strdup((yyvsp[0].string_val)));
            (yyval.expr)->value = (char*) malloc (60);
            strcpy((yyval.expr)->value, symbol_table[s].value);
            (yyval.expr)->type = (char*) malloc(60);
            strcpy((yyval.expr)->type, symbol_table[s].var_type);
            if(strcmp(symbol_table[s].value,"0"))
                (yyval.expr)->bool_value = false;
            else
                (yyval.expr)->bool_value = true;
         }
#line 1666 "language.tab.c"
    break;

  case 66: /* expression: ID_VAL '(' call_params ')'  */
#line 268 "language.y"
         {
            int s = searchFunction(strdup((yyvsp[-3].string_val)));
            if(s == -1 )
            {
                yyerror("Error! Variable uninitialised!");
                return -1;
            }
            char *r = (char*) malloc(100);
            for(int i = 0; i < (yyvsp[-1].paramets)->cnt; i++)
            {
                strcat(r,(yyvsp[-1].paramets)->parameters[i]->type);
            }
            if(strcmp(r,function_table[s].type_parameters))
            {
                yyerror("Error! Incorrect parameters!");
                return -1;
            }
            (yyval.expr)->value = (char*) malloc (60);
            strcpy((yyval.expr)->value,"0");
            (yyval.expr)->type = (char*) malloc(60);
            strcpy((yyval.expr)->type,function_table[s].var_type);
            (yyval.expr)->bool_value = true;
         }
#line 1694 "language.tab.c"
    break;

  case 67: /* expression: ID_VAL '(' ')'  */
#line 292 "language.y"
         {
            int s = searchFunction(strdup((yyvsp[-2].string_val)));
            if(s == -1 )
            {
                yyerror("Error! Variable uninitialised!");
                return -1;
            }
            if(strcmp(function_table[s].type_parameters,"No parameters"))
            {
                yyerror("Error! Incorrect parameters!");
                return -1;
            }
            (yyval.expr)->value = (char*) malloc (60);
            strcpy((yyval.expr)->value,"0");
            (yyval.expr)->type = (char*) malloc(60);
            strcpy((yyval.expr)->type,function_table[s].var_type);
            (yyval.expr)->bool_value = true;
         }
#line 1717 "language.tab.c"
    break;

  case 68: /* expression: ID_VAL '.' ID_VAL  */
#line 311 "language.y"
         {
            char* r = (char*)malloc(100);
            strcpy(r,(yyvsp[-2].string_val));
            strcat(r,".");
            strcat(r,(yyvsp[0].string_val));
            int s = search(r);
            if(s == -1 || symbol_table[s].value == NULL)
            {
                yyerror("Error! Value uninitialised!");
                return -1;
            }
            (yyval.expr)->value = (char*) malloc (60);
            strcpy((yyval.expr)->value,symbol_table[s].value);
            (yyval.expr)->type = (char*) malloc(60);
            strcpy((yyval.expr)->type,function_table[s].var_type);
            if(strcmp(symbol_table[s].value,"0"))
                (yyval.expr)->bool_value = false;
            else
                (yyval.expr)->bool_value = true;
         }
#line 1742 "language.tab.c"
    break;

  case 69: /* expression: EVAL '(' expression ')'  */
#line 332 "language.y"
         {
            (yyval.expr) = (yyvsp[-1].expr);
         }
#line 1750 "language.tab.c"
    break;

  case 70: /* expression: TYPEOF '(' expression ')'  */
#line 336 "language.y"
         {
            (yyval.expr) = (yyvsp[-1].expr);
         }
#line 1758 "language.tab.c"
    break;

  case 71: /* assignement: ID_VAL ASSIGN expression  */
#line 340 "language.y"
                                      {int s = search(strdup((yyvsp[-2].string_val)));  if(s == -1) //x = 5
    {
        yyerror("Error! Undeclared variable!");
        return -1;
    }
    else
    {
        if(strcmp(symbol_table[s].var_type,(yyvsp[0].expr)->type) == 0)
        {
            modifyVarValue(s,(yyvsp[0].expr)->value);
        }
        else
        {
            yyerror("Error! Wrong conversion type.");
            return -1;
        }
    }
    }
#line 1781 "language.tab.c"
    break;

  case 72: /* assignement: ID_VAL '[' value ']' ASSIGN expression  */
#line 359 "language.y"
    {
        int s = search(strdup((yyvsp[-5].string_val)));
        if(s == -1)
        {
            yyerror("Error! Uninitialised value!");
            return -1;
        }
        if(strcmp((yyvsp[0].expr)->type,symbol_table[s].var_type))
        {
            yyerror("Error! Wrong conversion type!");
            return -1;
        }

        int i = search(strdup((yyvsp[-3].string_val)));
        if(strcmp(symbol_table[i].var_type,"int") || symbol_table[i].value[0] == '-')
        {
            yyerror("Error! Unavailable index!");
            return -1;
        }
        
        int x = search(getVectorIndexName(strdup((yyvsp[-5].string_val)),strdup((yyvsp[-3].string_val))));
        if(x == -1)
        {
            yyerror("Error! Unavailable index!");
            return -1;
        }
        modifyVarValue(x,(yyvsp[0].expr)->value);
    }
#line 1814 "language.tab.c"
    break;

  case 73: /* assignement: ID_VAL '[' ID_VAL ']' ASSIGN expression  */
#line 387 "language.y"
                                            {
        int s = search(strdup((yyvsp[-5].string_val)));
        if(s == -1)
        {
            yyerror("Error! Uninitialised value!");
            return -1;
        }
        int v = search(strdup((yyvsp[-3].string_val)));
        if(v == -1 || symbol_table[v].value == NULL)
        {
            yyerror("Error! Uninitialised value!");
            return -1;
        }
        if(strcmp(symbol_table[v].var_type,"int") || symbol_table[v].value[0] == '-' )
        {
            yyerror("Error! Unavailable index!");
            return -1;
        }
        if(strcmp(symbol_table[v].type,"Variable") && strcmp(symbol_table[v].type,"Constant"))
        {
            yyerror("Error! Index type is not correct!");
            return -1;
        }
        int a = search(makeVectorName(strdup((yyvsp[-5].string_val)),atoi(symbol_table[v].value)));
        if(a == -1)
        {
            yyerror("Error! Unavailable index!");
            return -1;
        }
        if(strcmp(symbol_table[s].var_type,(yyvsp[0].expr)->type))
        {
            yyerror("Error! Wrong conversion type.");
            return -1;
        }
        modifyVarValue(a,(yyvsp[0].expr)->value);
    }
#line 1855 "language.tab.c"
    break;

  case 74: /* assignement: ID_VAL '(' call_params ')'  */
#line 424 "language.y"
    {
        int s = searchFunction(strdup((yyvsp[-3].string_val)));
        if(s == -1)
        {
            yyerror("Error! Function non-existant!");
            return -1;
        }
        char *r = (char*) malloc(100);
        for(int i = 0; i < (yyvsp[-1].paramets)->cnt; i++)
        {
            strcat(r,(yyvsp[-1].paramets)->parameters[i]->type);
        }
        if(strcmp(r,function_table[s].type_parameters))
        {
            yyerror("Error! Incorrect parameters!");
            return -1;
        }
    }
#line 1878 "language.tab.c"
    break;

  case 75: /* assignement: ID_VAL '(' ')'  */
#line 443 "language.y"
    {
        int s = searchFunction(strdup((yyvsp[-2].string_val)));
        if(s == -1)
        {
            yyerror("Error! Function non-existant!");
            return -1;
        }
        if(strcmp(function_table[s].type_parameters,"No parameters"))
        {
            yyerror("Error! Incorrect parameters!");
            return -1;
        }
    }
#line 1896 "language.tab.c"
    break;

  case 76: /* assignement: ID_VAL '.' ID_VAL ASSIGN expression  */
#line 457 "language.y"
    {
        char* r = (char*)malloc(100);
        strcpy(r,(yyvsp[-4].string_val));
        strcat(r,".");
        strcat(r,(yyvsp[-2].string_val));
        int s = search(r);
        if(s == -1 || symbol_table[s].value == NULL)
        {
            yyerror("Error! Value uninitialised!");
            return -1;
        }
        if(strcmp(symbol_table[s].var_type,(yyvsp[0].expr)->type))
        {
            yyerror("Error! Wrong conversion type!");
            return -1;
        }
        modifyVarValue(s,(yyvsp[0].expr)->value);
    }
#line 1919 "language.tab.c"
    break;

  case 77: /* call_params: call_params ',' call_param  */
#line 478 "language.y"
    {
        (yyvsp[-2].paramets)->parameters[(yyvsp[-2].paramets)->cnt] = new par;
        (yyvsp[-2].paramets)->parameters[(yyvsp[-2].paramets)->cnt]->type = (char*)malloc(20);
        (yyvsp[-2].paramets)->parameters[(yyvsp[-2].paramets)->cnt]->value = (char*)malloc(60);
        strcpy((yyvsp[-2].paramets)->parameters[(yyvsp[-2].paramets)->cnt]->type,(yyvsp[0].paramet)->type);
        strcpy((yyvsp[-2].paramets)->parameters[(yyvsp[-2].paramets)->cnt]->value,(yyvsp[0].paramet)->value);
        (yyvsp[-2].paramets)->cnt++;
        (yyval.paramets) = (yyvsp[-2].paramets);
    }
#line 1933 "language.tab.c"
    break;

  case 78: /* call_params: call_param  */
#line 487 "language.y"
                {
        (yyval.paramets) = new call_parameters;
        (yyval.paramets)->cnt = 0;
        (yyval.paramets)->parameters[0] = new par;
        (yyval.paramets)->parameters[0]->type = (char*)malloc(20);
        (yyval.paramets)->parameters[0]->value = (char*)malloc(60);
        strcpy((yyval.paramets)->parameters[(yyval.paramets)->cnt]->type,(yyvsp[0].paramet)->type);
        strcpy((yyval.paramets)->parameters[(yyval.paramets)->cnt]->value,(yyvsp[0].paramet)->value);
        (yyval.paramets)->cnt++;
    }
#line 1948 "language.tab.c"
    break;

  case 79: /* call_param: expression  */
#line 500 "language.y"
    {
        (yyval.paramet) = new par;
        (yyval.paramet)->type = (char*)malloc(20);
        strcpy((yyval.paramet)->type,(yyvsp[0].expr)->type);
        (yyval.paramet)->value = (char*)malloc(60);
        strcpy((yyval.paramet)->value,(yyvsp[0].expr)->value);
    }
#line 1960 "language.tab.c"
    break;

  case 80: /* declaration: type ID_VAL  */
#line 508 "language.y"
                        { addSymbol("Variable", strdup((yyvsp[0].string_val)), NULL, strdup((yyvsp[-1].string_val))); }
#line 1966 "language.tab.c"
    break;

  case 81: /* declaration: type ID_VAL ASSIGN expression  */
#line 509 "language.y"
                                   { //int x = 5
        if(strcmp((yyvsp[0].expr)->type, lastType)!=0)
        {
            yyerror("Error! Wrong conversion type.");
            return -1;
        }
        addSymbol("Variable", strdup((yyvsp[-2].string_val)), (yyvsp[0].expr)->value, strdup((yyvsp[-3].string_val)));
    }
#line 1979 "language.tab.c"
    break;

  case 82: /* declaration: type ID_VAL '[' value ']'  */
#line 518 "language.y"
    {
        int i = search(strdup((yyvsp[-1].string_val)));
        if(strcmp(symbol_table[i].var_type,"int") || symbol_table[i].value[0] == '-')
        {
            yyerror("Error! Unavailable index!");
            return -1;
        }
        int v = search(strdup((yyvsp[-3].string_val)));
        if(v!=-1)
        {
            yyerror("Error! Redeclaration of variable!");
            return -1;
        }
        addSymbol("Vector", strdup((yyvsp[-3].string_val)),strdup((yyvsp[-1].string_val)),strdup((yyvsp[-4].string_val)));
    }
#line 1999 "language.tab.c"
    break;

  case 83: /* declaration: type ID_VAL '[' value ']' ASSIGN '{' vector '}'  */
#line 534 "language.y"
    {
        int s = search(strdup((yyvsp[-7].string_val)));
        if(s != -1)
        {
            yyerror("Error! Redeclaration of variable!");
            return -1;
        }
        int v = search(strdup((yyvsp[-5].string_val)));
        if(strcmp(symbol_table[v].var_type,"int") || symbol_table[v].value[0] == '-')
        {
            yyerror("Error! Unavailable index!");
            return -1;
        }
        addSymbol("Vector",strdup((yyvsp[-7].string_val)),strdup((yyvsp[-5].string_val)),strdup((yyvsp[-8].string_val)));
        if((yyvsp[-1].vec_type)->nr_elem > atoi((yyvsp[-5].string_val)))
        {
            yyerror("Error! Too many elements in the vector.");
            return -1;
        }
        for(int i = 0; i < (yyvsp[-1].vec_type)->nr_elem; i++)
        {
            s = search(makeVectorName(strdup((yyvsp[-7].string_val)),i));
            int e = search((yyvsp[-1].vec_type)->value[i]);
            if(strcmp(lastType,symbol_table[e].var_type))
            {
                yyerror("Error! An element in the vector is of the wrong type!");
                return -1;
            }
            modifyVarValue(s,symbol_table[e].value);
        }
        if(strcmp(lastType,"int")==0)
        {
            for(int i = (yyvsp[-1].vec_type)->nr_elem; i < atoi(strdup((yyvsp[-5].string_val))); i++)
                {
                    s = search(makeVectorName(strdup((yyvsp[-7].string_val)),i));
                    char zero[] = "0";
                    modifyVarValue(s,zero);
                }
        }
        else if(strcmp(lastType,"float") == 0)
        {
            for(int i = (yyvsp[-1].vec_type)->nr_elem; i < atoi(strdup((yyvsp[-5].string_val))); i++)
                {
                    s = search(makeVectorName(strdup((yyvsp[-7].string_val)),i));
                    char zero[] = "0.0";
                    modifyVarValue(s,zero);
                }
        }
    }
#line 2053 "language.tab.c"
    break;

  case 84: /* declaration: type ID_VAL '[' ID_VAL ']'  */
#line 584 "language.y"
                                {
        int i = search(strdup((yyvsp[-1].string_val)));
        if(i == -1)
        {
            yyerror("Error! Uninitialised value!");
            return -1;
        }  
        int v = search(strdup((yyvsp[-3].string_val)));
        if(v!=-1)
        {
            yyerror("Error! Redeclaration of variable!");
            return -1;
        } 
        if(strcmp(symbol_table[i].type,"Variable") && strcmp(symbol_table[i].type,"Constant"))
        {
            yyerror("Error! Index type is not correct!");
            return -1;
        }
        if(strcmp(symbol_table[i].var_type,"int") || symbol_table[i].value[0] == '-')
        {
            yyerror("Error! Unavailable index!");
            return -1;
        }
        addSymbol("Vector", strdup((yyvsp[-3].string_val)),symbol_table[i].value,strdup((yyvsp[-4].string_val)));
    }
#line 2083 "language.tab.c"
    break;

  case 85: /* vector: vector ',' value  */
#line 611 "language.y"
                         { strcpy((yyvsp[-2].vec_type)->value[(yyvsp[-2].vec_type)->nr_elem],(yyvsp[0].string_val)); (yyvsp[-2].vec_type)->nr_elem++; (yyval.vec_type) = (yyvsp[-2].vec_type); }
#line 2089 "language.tab.c"
    break;

  case 86: /* vector: value  */
#line 612 "language.y"
            {
    (yyval.vec_type) = new vec;
    for(int i = 0; i < 100; i++)
        (yyval.vec_type)->value[i] = (char*)malloc(10);     
    (yyval.vec_type)->nr_elem = 0; strcpy((yyval.vec_type)->value[(yyval.vec_type)->nr_elem],(yyvsp[0].string_val)); (yyval.vec_type)->nr_elem++;
    }
#line 2100 "language.tab.c"
    break;

  case 87: /* type: INT_TYPE  */
#line 620 "language.y"
              {updateLastType(strdup((yyvsp[0].string_val))); (yyval.string_val) = (yyvsp[0].string_val);}
#line 2106 "language.tab.c"
    break;

  case 88: /* type: FLOAT_TYPE  */
#line 621 "language.y"
                {updateLastType(strdup((yyvsp[0].string_val))); (yyval.string_val) = (yyvsp[0].string_val);}
#line 2112 "language.tab.c"
    break;

  case 89: /* type: BOOL_TYPE  */
#line 622 "language.y"
               {updateLastType(strdup((yyvsp[0].string_val))); (yyval.string_val) = (yyvsp[0].string_val);}
#line 2118 "language.tab.c"
    break;

  case 90: /* type: CHAR_TYPE  */
#line 623 "language.y"
               {updateLastType(strdup((yyvsp[0].string_val))); (yyval.string_val) = (yyvsp[0].string_val);}
#line 2124 "language.tab.c"
    break;

  case 91: /* type: STRING_TYPE  */
#line 624 "language.y"
                 {updateLastType(strdup((yyvsp[0].string_val))); (yyval.string_val) = (yyvsp[0].string_val);}
#line 2130 "language.tab.c"
    break;

  case 92: /* type: VOID_TYPE  */
#line 625 "language.y"
               {updateLastType(strdup((yyvsp[0].string_val))); (yyval.string_val) = (yyvsp[0].string_val);}
#line 2136 "language.tab.c"
    break;

  case 93: /* value: INT_VAL  */
#line 628 "language.y"
              {char var_type[] = "int"; addSymbol("Constant", strdup((yyvsp[0].string_val)), strdup((yyvsp[0].string_val)), var_type); (yyval.string_val) = (yyvsp[0].string_val);}
#line 2142 "language.tab.c"
    break;

  case 94: /* value: FLOAT_VAL  */
#line 629 "language.y"
               {char var_type[] = "float"; addSymbol("Constant", strdup((yyvsp[0].string_val)), strdup((yyvsp[0].string_val)), var_type); (yyval.string_val) = (yyvsp[0].string_val);}
#line 2148 "language.tab.c"
    break;

  case 95: /* value: CHAR_VAL  */
#line 630 "language.y"
              {char var_type[] = "char"; addSymbol("Constant", strdup((yyvsp[0].string_val)), strdup((yyvsp[0].string_val)), var_type); (yyval.string_val) = (yyvsp[0].string_val);}
#line 2154 "language.tab.c"
    break;

  case 96: /* value: STRING_VAL  */
#line 631 "language.y"
                {char var_type[] = "string"; addSymbol("Constant", strdup((yyvsp[0].string_val)), strdup((yyvsp[0].string_val)), var_type); (yyval.string_val) = (yyvsp[0].string_val);}
#line 2160 "language.tab.c"
    break;

  case 97: /* value: BOOL_VAL  */
#line 632 "language.y"
              {char var_type[] = "bool"; addSymbol("Constant", strdup((yyvsp[0].string_val)), strdup((yyvsp[0].string_val)), var_type); (yyval.string_val) = (yyvsp[0].string_val);}
#line 2166 "language.tab.c"
    break;

  case 98: /* return: RETURN expression  */
#line 636 "language.y"
    {
        (yyval.expr)->type = (char*)malloc(20);
        (yyval.expr)->value = (char*)malloc(60);
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2176 "language.tab.c"
    break;


#line 2180 "language.tab.c"

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

#line 642 "language.y"

int yyerror(const char* s){
    ok = false;
    printf("Line %d: %s\n",line_nr+1, s);
    return -1;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s input_file\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    yyin = file; // Set the input file for Flex

    yyparse();
    printSymbolsToFile();
    if(ok)
        cout<<"Compilation was successful!\n";
    fclose(file);

    return 0;
}
