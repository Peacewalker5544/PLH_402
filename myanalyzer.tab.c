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
#line 1 "myanalyzer.y"

 #include <stdio.h>
 #include "cgen.h"
 #include <string.h>
	
 extern int yylex(void);
 extern char* yytext;

 extern int line_num;

 char* comp_type;
 char* comp_func;
 char* null;
 char* func_names;
 char* ident;
 char* new_ident;

#line 89 "myanalyzer.tab.c"

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

#include "myanalyzer.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KEYWORD_INTEGER = 3,            /* KEYWORD_INTEGER  */
  YYSYMBOL_KEYWORD_SCALAR = 4,             /* KEYWORD_SCALAR  */
  YYSYMBOL_KEYWORD_STR = 5,                /* KEYWORD_STR  */
  YYSYMBOL_KEYWORD_BOOL = 6,               /* KEYWORD_BOOL  */
  YYSYMBOL_KEYWORD_TRUE = 7,               /* KEYWORD_TRUE  */
  YYSYMBOL_KEYWORD_FALSE = 8,              /* KEYWORD_FALSE  */
  YYSYMBOL_KEYWORD_CONST = 9,              /* KEYWORD_CONST  */
  YYSYMBOL_KEYWORD_IF = 10,                /* KEYWORD_IF  */
  YYSYMBOL_KEYWORD_ELSE = 11,              /* KEYWORD_ELSE  */
  YYSYMBOL_KEYWORD_ENDIF = 12,             /* KEYWORD_ENDIF  */
  YYSYMBOL_KEYWORD_FOR = 13,               /* KEYWORD_FOR  */
  YYSYMBOL_KEYWORD_IN = 14,                /* KEYWORD_IN  */
  YYSYMBOL_KEYWORD_ENDFOR = 15,            /* KEYWORD_ENDFOR  */
  YYSYMBOL_KEYWORD_WHILE = 16,             /* KEYWORD_WHILE  */
  YYSYMBOL_KEYWORD_ENDWHILE = 17,          /* KEYWORD_ENDWHILE  */
  YYSYMBOL_KEYWORD_BREAK = 18,             /* KEYWORD_BREAK  */
  YYSYMBOL_KEYWORD_CONTINUE = 19,          /* KEYWORD_CONTINUE  */
  YYSYMBOL_KEYWORD_DEF = 20,               /* KEYWORD_DEF  */
  YYSYMBOL_KEYWORD_ENDDEF = 21,            /* KEYWORD_ENDDEF  */
  YYSYMBOL_KEYWORD_MAIN = 22,              /* KEYWORD_MAIN  */
  YYSYMBOL_KEYWORD_RETURN = 23,            /* KEYWORD_RETURN  */
  YYSYMBOL_KEYWORD_COMP = 24,              /* KEYWORD_COMP  */
  YYSYMBOL_KEYWORD_ENDCOMP = 25,           /* KEYWORD_ENDCOMP  */
  YYSYMBOL_KEYWORD_OF = 26,                /* KEYWORD_OF  */
  YYSYMBOL_DELIM_SEMICOLON = 27,           /* DELIM_SEMICOLON  */
  YYSYMBOL_DELIM_COMMA = 28,               /* DELIM_COMMA  */
  YYSYMBOL_DELIM_COLON = 29,               /* DELIM_COLON  */
  YYSYMBOL_OP_HASHTAG = 30,                /* OP_HASHTAG  */
  YYSYMBOL_CONST_INTEGER = 31,             /* CONST_INTEGER  */
  YYSYMBOL_CONST_FLOAT = 32,               /* CONST_FLOAT  */
  YYSYMBOL_CONST_STRING = 33,              /* CONST_STRING  */
  YYSYMBOL_IDENTIFIER = 34,                /* IDENTIFIER  */
  YYSYMBOL_DELIM_DOT = 35,                 /* DELIM_DOT  */
  YYSYMBOL_DELIM_LPAR = 36,                /* DELIM_LPAR  */
  YYSYMBOL_DELIM_RPAR = 37,                /* DELIM_RPAR  */
  YYSYMBOL_DELIM_LBRAC = 38,               /* DELIM_LBRAC  */
  YYSYMBOL_DELIM_RBRAC = 39,               /* DELIM_RBRAC  */
  YYSYMBOL_OP_POWER = 40,                  /* OP_POWER  */
  YYSYMBOL_OP_SIGN = 41,                   /* OP_SIGN  */
  YYSYMBOL_OP_PROD = 42,                   /* OP_PROD  */
  YYSYMBOL_OP_DIV = 43,                    /* OP_DIV  */
  YYSYMBOL_OP_MOD = 44,                    /* OP_MOD  */
  YYSYMBOL_OP_PLUS = 45,                   /* OP_PLUS  */
  YYSYMBOL_OP_MINUS = 46,                  /* OP_MINUS  */
  YYSYMBOL_OP_SMALLER = 47,                /* OP_SMALLER  */
  YYSYMBOL_OP_SMALLER_EQ = 48,             /* OP_SMALLER_EQ  */
  YYSYMBOL_OP_BIGGER = 49,                 /* OP_BIGGER  */
  YYSYMBOL_OP_BIGGER_EQ = 50,              /* OP_BIGGER_EQ  */
  YYSYMBOL_OP_EQUALS = 51,                 /* OP_EQUALS  */
  YYSYMBOL_OP_NOT_EQUALS = 52,             /* OP_NOT_EQUALS  */
  YYSYMBOL_KEYWORD_NOT = 53,               /* KEYWORD_NOT  */
  YYSYMBOL_KEYWORD_AND = 54,               /* KEYWORD_AND  */
  YYSYMBOL_KEYWORD_OR = 55,                /* KEYWORD_OR  */
  YYSYMBOL_OP_ASSIGN = 56,                 /* OP_ASSIGN  */
  YYSYMBOL_OP_ASSIGN_PLUS = 57,            /* OP_ASSIGN_PLUS  */
  YYSYMBOL_OP_ASSIGN_MINUS = 58,           /* OP_ASSIGN_MINUS  */
  YYSYMBOL_OP_ASSIGN_PROD = 59,            /* OP_ASSIGN_PROD  */
  YYSYMBOL_OP_ASSIGN_DIV = 60,             /* OP_ASSIGN_DIV  */
  YYSYMBOL_OP_ASSIGN_MOD = 61,             /* OP_ASSIGN_MOD  */
  YYSYMBOL_OP_ASSIGN_ARR = 62,             /* OP_ASSIGN_ARR  */
  YYSYMBOL_YYACCEPT = 63,                  /* $accept  */
  YYSYMBOL_input = 64,                     /* input  */
  YYSYMBOL_program = 65,                   /* program  */
  YYSYMBOL_program_main = 66,              /* program_main  */
  YYSYMBOL_declare_comp = 67,              /* declare_comp  */
  YYSYMBOL_68_1 = 68,                      /* $@1  */
  YYSYMBOL_comp_members_var = 69,          /* comp_members_var  */
  YYSYMBOL_comp_members_method = 70,       /* comp_members_method  */
  YYSYMBOL_member_method = 71,             /* member_method  */
  YYSYMBOL_member_var = 72,                /* member_var  */
  YYSYMBOL_member_var_identifiers = 73,    /* member_var_identifiers  */
  YYSYMBOL_method_arg = 74,                /* method_arg  */
  YYSYMBOL_declare_const = 75,             /* declare_const  */
  YYSYMBOL_declare_var = 76,               /* declare_var  */
  YYSYMBOL_declare_func = 77,              /* declare_func  */
  YYSYMBOL_declare_main = 78,              /* declare_main  */
  YYSYMBOL_func_body = 79,                 /* func_body  */
  YYSYMBOL_expression = 80,                /* expression  */
  YYSYMBOL_expr_identifiers = 81,          /* expr_identifiers  */
  YYSYMBOL_expr = 82,                      /* expr  */
  YYSYMBOL_method_n_expr = 83,             /* method_n_expr  */
  YYSYMBOL_func_call = 84,                 /* func_call  */
  YYSYMBOL_n_expr = 85,                    /* n_expr  */
  YYSYMBOL_statements = 86,                /* statements  */
  YYSYMBOL_instruction = 87,               /* instruction  */
  YYSYMBOL_func_arg = 88,                  /* func_arg  */
  YYSYMBOL_var_identifiers = 89,           /* var_identifiers  */
  YYSYMBOL_data_type = 90,                 /* data_type  */
  YYSYMBOL_data_const = 91                 /* data_const  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1086

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  305

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   317


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   113,   113,   144,   145,   146,   147,   148,   152,   153,
     157,   157,   166,   167,   168,   172,   173,   174,   179,   189,
     203,   204,   205,   209,   210,   214,   215,   216,   217,   218,
     222,   227,   233,   234,   238,   240,   245,   252,   253,   254,
     255,   259,   263,   264,   265,   266,   274,   275,   276,   277,
     278,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   316,   317,   318,   322,   326,
     327,   328,   332,   333,   341,   342,   344,   347,   350,   352,
     354,   355,   356,   357,   358,   361,   362,   369,   370,   371,
     372,   373,   377,   378,   383,   384,   385,   386,   387,   393,
     394,   395,   396,   397
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
  "\"end of file\"", "error", "\"invalid token\"", "KEYWORD_INTEGER",
  "KEYWORD_SCALAR", "KEYWORD_STR", "KEYWORD_BOOL", "KEYWORD_TRUE",
  "KEYWORD_FALSE", "KEYWORD_CONST", "KEYWORD_IF", "KEYWORD_ELSE",
  "KEYWORD_ENDIF", "KEYWORD_FOR", "KEYWORD_IN", "KEYWORD_ENDFOR",
  "KEYWORD_WHILE", "KEYWORD_ENDWHILE", "KEYWORD_BREAK", "KEYWORD_CONTINUE",
  "KEYWORD_DEF", "KEYWORD_ENDDEF", "KEYWORD_MAIN", "KEYWORD_RETURN",
  "KEYWORD_COMP", "KEYWORD_ENDCOMP", "KEYWORD_OF", "DELIM_SEMICOLON",
  "DELIM_COMMA", "DELIM_COLON", "OP_HASHTAG", "CONST_INTEGER",
  "CONST_FLOAT", "CONST_STRING", "IDENTIFIER", "DELIM_DOT", "DELIM_LPAR",
  "DELIM_RPAR", "DELIM_LBRAC", "DELIM_RBRAC", "OP_POWER", "OP_SIGN",
  "OP_PROD", "OP_DIV", "OP_MOD", "OP_PLUS", "OP_MINUS", "OP_SMALLER",
  "OP_SMALLER_EQ", "OP_BIGGER", "OP_BIGGER_EQ", "OP_EQUALS",
  "OP_NOT_EQUALS", "KEYWORD_NOT", "KEYWORD_AND", "KEYWORD_OR", "OP_ASSIGN",
  "OP_ASSIGN_PLUS", "OP_ASSIGN_MINUS", "OP_ASSIGN_PROD", "OP_ASSIGN_DIV",
  "OP_ASSIGN_MOD", "OP_ASSIGN_ARR", "$accept", "input", "program",
  "program_main", "declare_comp", "$@1", "comp_members_var",
  "comp_members_method", "member_method", "member_var",
  "member_var_identifiers", "method_arg", "declare_const", "declare_var",
  "declare_func", "declare_main", "func_body", "expression",
  "expr_identifiers", "expr", "method_n_expr", "func_call", "n_expr",
  "statements", "instruction", "func_arg", "var_identifiers", "data_type",
  "data_const", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-221)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-103)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,    25,    61,  -221,  -221,   568,     1,    38,    -9,    49,
      56,    60,    62,   114,    13,  -221,  -221,    80,  -221,  -221,
    -221,   -10,   568,   568,   568,   568,   118,   748,  -221,  -221,
     113,   119,   125,    55,  -221,  -221,  -221,  -221,  -221,   122,
      10,   133,   568,   568,   821,   982,   982,   163,   586,    10,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     135,   126,   143,   136,   145,  -221,  -221,  -221,  -221,  -221,
    -221,  -221,   568,   962,    -4,   894,  -221,    35,   962,  -221,
     962,   999,   999,   999,  1014,  1014,  1025,  1025,  1025,  1025,
     163,   163,   207,    87,    87,    87,    87,    87,    87,    87,
     150,     2,    41,   148,   143,  -221,   123,   154,    10,   917,
     568,  -221,  -221,   131,  -221,    10,   147,   153,   -25,   152,
     168,  -221,   161,    10,    10,  -221,  -221,   962,   675,   160,
      51,    89,  -221,   170,    71,  -221,   151,   101,   167,    81,
    -221,   172,   182,  -221,  -221,   568,   174,   177,   178,   189,
     198,  -221,   162,  -221,    75,   201,   202,  -221,   598,  -221,
      10,    10,   197,   224,    10,   199,   210,   208,  -221,  -221,
    -221,  -221,   700,   568,   232,   568,  -221,  -221,  -221,   624,
     550,   211,  -221,  -221,  -221,  -221,  -221,   219,  -221,   221,
     223,    10,   102,   846,   233,   871,  -221,   136,   568,    10,
    -221,    10,   245,    88,   236,   246,   247,   568,   249,   240,
    -221,   357,   248,  -221,    10,   254,   -24,   270,  -221,   772,
    -221,   568,   162,  -221,   251,   280,  -221,   261,    95,   295,
     568,   388,   796,   291,   650,    10,   326,    10,    10,   276,
     287,   290,   -35,  -221,   724,   292,     5,  -221,   299,   293,
     296,   301,   304,   308,  -221,  -221,   568,   309,  -221,   285,
     329,  -221,  -221,    10,   419,   940,  -221,   317,   316,   450,
     323,   325,   332,   491,    10,   328,   162,  -221,  -221,   336,
     341,   324,   348,   532,  -221,  -221,   335,   350,   351,   352,
    -221,  -221,    10,   355,  -221
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     2,     1,     0,     0,     0,   102,     0,
       0,     0,     0,     0,     0,   112,   113,     0,   109,   110,
     111,    42,     0,     0,     0,     0,    47,     0,    48,    46,
       0,     0,     0,     0,     4,     5,     6,     7,     9,     0,
       0,    43,    79,     0,     0,    53,    54,    66,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,    12,     0,     0,   103,   104,   105,   106,   107,
     108,    31,     0,    80,     0,     0,    51,    42,    49,    30,
      52,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    67,    68,    69,    70,    71,    72,    73,    74,
       0,     0,     0,     0,    10,    13,     0,     0,     0,     0,
       0,    78,    45,    75,    37,     0,     0,     0,     0,    23,
      15,    14,     0,     0,     0,    32,    44,    81,    76,     0,
       0,     0,    98,     0,     0,    37,     0,     0,     0,     0,
      16,     0,     0,    33,    50,     0,     0,     0,     0,     0,
       0,    36,     0,    95,    42,     0,     0,    96,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    17,
      24,    20,    77,     0,     0,     0,    91,    92,    93,     0,
       0,     0,    38,    39,    41,    99,   100,     0,    35,     0,
       0,     0,    25,     0,     0,     0,    94,   109,     0,     0,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     101,     0,     0,    21,     0,     0,     0,     0,    82,     0,
      82,     0,     0,    22,    26,     0,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    42,    83,     0,     0,     0,    34,    94,    27,
       0,     0,    28,     0,    82,    84,     0,     0,    90,     0,
       0,    19,    37,     0,     0,     0,    82,     0,     0,     0,
      29,     0,     0,     0,     0,     0,     0,    85,    82,     0,
       0,     0,     0,     0,    87,    88,     0,     0,     0,     0,
      18,    86,     0,     0,    89
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,   234,   271,
    -221,  -221,   384,   390,  -221,  -221,  -143,  -220,  -221,    -5,
    -221,  -221,   274,  -196,  -209,   192,  -221,   -43,  -221
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     3,     9,   130,   114,   149,   150,   115,
     116,   214,   165,   166,    12,    13,   141,   167,    26,   168,
     139,    28,    84,   239,   169,   112,    14,    81,    29
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,    42,   173,    43,   145,   236,    89,    -8,    76,    77,
      78,    79,   243,    76,    77,    78,    79,    44,    45,    46,
      47,   146,   237,    30,   120,     4,    42,   191,    43,    33,
     253,   125,   253,   121,   241,    31,   269,    83,    85,    80,
     126,    39,    40,    88,    80,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   253,   292,   221,   274,   127,
       5,   123,    32,    43,   253,   135,    34,   119,   128,   155,
     283,     6,   142,    35,   253,     7,    73,    36,   121,    37,
     152,   153,   293,   246,    74,     8,    15,    16,     5,   156,
     171,   148,   157,  -102,  -102,   158,   178,   159,   160,   172,
     161,    42,   162,   190,    41,   137,   163,   224,   138,    17,
      18,    19,    20,   164,   248,    22,   225,   195,   196,   279,
     -97,   199,   175,   249,    23,    24,   213,   191,    15,    16,
     176,    38,    25,    64,    65,    66,    67,    68,    69,    70,
     182,   132,   133,    48,    72,    71,    75,   189,   212,   -79,
     111,    17,    18,    19,    20,    21,   220,    22,   222,    15,
      16,    82,   110,   113,   118,   117,    23,    24,   203,   124,
     205,   234,   129,   134,    25,    85,   143,   144,   148,   188,
     147,   151,    17,    18,    19,    20,    21,   154,    22,   170,
     174,   177,   259,   219,   261,   262,   180,    23,    24,   181,
     183,   184,   229,   270,   185,    25,   186,    62,    63,    64,
      65,    66,    67,    68,    69,   187,   242,   244,   192,   193,
     280,    15,    16,     5,   156,   254,   197,   157,   200,   201,
     158,   290,   159,   160,   202,   198,   204,   162,   209,   208,
     210,   163,   211,   231,    17,    18,    19,    20,   164,   303,
      22,   275,    63,    64,    65,    66,    67,    68,    69,    23,
      24,   217,   223,   226,   227,   233,   228,    25,   230,   -98,
      50,   244,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,   235,    62,    63,    64,    65,    66,    67,
      68,    69,    15,    16,   238,   156,   250,   251,   157,   245,
     247,   158,   257,   159,   160,   263,   264,   265,   162,   268,
     -41,   -99,   163,   271,   277,    17,    18,    19,    20,   252,
     272,    22,  -100,    15,    16,     5,   156,   273,   276,   157,
      23,    24,   158,   278,   159,   160,   284,   260,    25,   162,
     285,  -101,   287,   163,   291,   296,    17,    18,    19,    20,
     164,   288,    22,   294,    15,    16,     5,   156,   295,   297,
     157,    23,    24,   158,   299,   159,   160,   300,   301,    25,
     232,   302,   304,   179,   163,   131,    10,    17,    18,    19,
      20,   164,    11,    22,   215,    15,    16,   140,   156,     0,
       0,   157,    23,    24,   158,   255,   159,   160,     0,     0,
      25,   162,     0,     0,     0,   163,     0,     0,    17,    18,
      19,    20,   252,     0,    22,     0,    15,    16,     0,   156,
       0,   281,   157,    23,    24,   158,     0,   159,   160,     0,
       0,    25,   162,     0,     0,     0,   163,     0,     0,    17,
      18,    19,    20,   252,     0,    22,     0,    15,    16,     5,
     156,     0,     0,   157,    23,    24,   158,     0,   159,   160,
       0,     0,    25,   286,     0,     0,     0,   163,     0,     0,
      17,    18,    19,    20,   164,     0,    22,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    24,     0,    15,    16,
       0,   156,     0,    25,   157,     0,   289,   158,     0,   159,
     160,     0,     0,     0,   162,     0,     0,     0,   163,     0,
       0,    17,    18,    19,    20,   252,     0,    22,     0,     0,
       0,     0,     0,     0,     0,     0,    23,    24,     0,    15,
      16,     0,   156,     0,    25,   157,     0,   298,   158,     0,
     159,   160,     0,     0,     0,   162,     0,    15,    16,   163,
       0,     0,    17,    18,    19,    20,   252,     0,    22,     0,
       0,     0,     0,     0,     0,    15,    16,    23,    24,     0,
      17,   207,    19,    20,    21,    25,    22,     0,     0,    74,
       0,     0,     0,    15,    16,    23,    24,     0,    17,    18,
      19,    20,    21,    25,    22,     0,     0,     0,     0,     0,
       0,     0,     0,    23,    24,     0,    17,    18,    19,    20,
      87,    25,    22,     0,     0,   194,     0,     0,     0,     0,
       0,    23,    24,     0,     0,     0,     0,     0,    50,    25,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,   206,    62,    63,    64,    65,    66,    67,    68,    69,
       0,     0,     0,     0,    50,     0,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,   258,    62,    63,
      64,    65,    66,    67,    68,    69,     0,     0,     0,     0,
      50,     0,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,   -80,    62,    63,    64,    65,    66,    67,
      68,    69,     0,     0,     0,    50,     0,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,   -81,    62,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
      50,     0,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,   266,    62,    63,    64,    65,    66,    67,
      68,    69,     0,   267,    50,     0,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    49,    62,    63,
      64,    65,    66,    67,    68,    69,     0,     0,    50,     0,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,   240,    62,    63,    64,    65,    66,    67,    68,    69,
       0,     0,    50,     0,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,   256,    62,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    50,     0,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,     0,
      62,    63,    64,    65,    66,    67,    68,    69,    86,     0,
       0,    50,     0,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,     0,    62,    63,    64,    65,    66,
      67,    68,    69,   216,     0,     0,    50,     0,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,     0,
      62,    63,    64,    65,    66,    67,    68,    69,   218,     0,
       0,    50,     0,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,     0,    62,    63,    64,    65,    66,
      67,    68,    69,   122,    50,     0,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,     0,    62,    63,
      64,    65,    66,    67,    68,    69,   136,    50,     0,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
       0,    62,    63,    64,    65,    66,    67,    68,    69,   282,
      50,     0,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,     0,    62,    63,    64,    65,    66,    67,
      68,    69,    50,     0,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,     0,    62,    63,    64,    65,
      66,    67,    68,    69,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,     0,    62,    63,    64,    65,
      66,    67,    68,    69,    54,    55,    56,    57,    58,    59,
      60,    61,     0,    62,    63,    64,    65,    66,    67,    68,
      69,    56,    57,    58,    59,    60,    61,     0,    62,    63,
      64,    65,    66,    67,    68,    69,    60,    61,     0,    62,
      63,    64,    65,    66,    67,    68,    69
};

static const yytype_int16 yycheck[] =
{
       5,    36,   145,    38,    29,    29,    49,     0,     3,     4,
       5,     6,   232,     3,     4,     5,     6,    22,    23,    24,
      25,    46,    46,    22,    28,     0,    36,    62,    38,    38,
     239,    29,   241,    37,   230,    34,    31,    42,    43,    34,
      38,    28,    29,    48,    34,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,   274,   286,   210,   264,    28,
       9,    36,    34,    38,   283,   118,    27,    82,    37,    28,
     276,    20,   125,    27,   293,    24,    31,    27,    37,    27,
     133,   134,   288,   236,    39,    34,     7,     8,     9,    10,
      29,    20,    13,    28,    29,    16,    25,    18,    19,    38,
      21,    36,    23,    38,    34,   120,    27,    29,   123,    30,
      31,    32,    33,    34,    29,    36,    38,   170,   171,   272,
      28,   174,    31,    38,    45,    46,    34,    62,     7,     8,
      39,    27,    53,    56,    57,    58,    59,    60,    61,    36,
     155,    28,    29,    35,    29,    36,    34,   162,   201,    28,
      34,    30,    31,    32,    33,    34,   209,    36,   211,     7,
       8,    38,    37,    30,    29,    39,    45,    46,   183,    29,
     185,   224,    34,    29,    53,   190,    39,    34,    20,    27,
      38,    30,    30,    31,    32,    33,    34,    37,    36,    29,
      49,    34,   245,   208,   247,   248,    34,    45,    46,    27,
      36,    34,   217,   256,    36,    53,    27,    54,    55,    56,
      57,    58,    59,    60,    61,    27,   231,   232,    27,    27,
     273,     7,     8,     9,    10,   240,    39,    13,    39,    29,
      16,   284,    18,    19,    36,    21,    14,    23,    29,    38,
      29,    27,    29,    13,    30,    31,    32,    33,    34,   302,
      36,   266,    55,    56,    57,    58,    59,    60,    61,    45,
      46,    38,    27,    37,    28,    27,    29,    53,    29,    28,
      40,   286,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    39,    54,    55,    56,    57,    58,    59,
      60,    61,     7,     8,    34,    10,    11,    12,    13,    29,
      49,    16,    21,    18,    19,    39,    29,    27,    23,    27,
      21,    28,    27,    27,    39,    30,    31,    32,    33,    34,
      29,    36,    28,     7,     8,     9,    10,    29,    29,    13,
      45,    46,    16,    14,    18,    19,    29,    21,    53,    23,
      34,    28,    27,    27,    26,    31,    30,    31,    32,    33,
      34,    29,    36,    27,     7,     8,     9,    10,    27,    21,
      13,    45,    46,    16,    39,    18,    19,    27,    27,    53,
      23,    29,    27,   149,    27,   114,     2,    30,    31,    32,
      33,    34,     2,    36,   202,     7,     8,   123,    10,    -1,
      -1,    13,    45,    46,    16,    17,    18,    19,    -1,    -1,
      53,    23,    -1,    -1,    -1,    27,    -1,    -1,    30,    31,
      32,    33,    34,    -1,    36,    -1,     7,     8,    -1,    10,
      -1,    12,    13,    45,    46,    16,    -1,    18,    19,    -1,
      -1,    53,    23,    -1,    -1,    -1,    27,    -1,    -1,    30,
      31,    32,    33,    34,    -1,    36,    -1,     7,     8,     9,
      10,    -1,    -1,    13,    45,    46,    16,    -1,    18,    19,
      -1,    -1,    53,    23,    -1,    -1,    -1,    27,    -1,    -1,
      30,    31,    32,    33,    34,    -1,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,     7,     8,
      -1,    10,    -1,    53,    13,    -1,    15,    16,    -1,    18,
      19,    -1,    -1,    -1,    23,    -1,    -1,    -1,    27,    -1,
      -1,    30,    31,    32,    33,    34,    -1,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,     7,
       8,    -1,    10,    -1,    53,    13,    -1,    15,    16,    -1,
      18,    19,    -1,    -1,    -1,    23,    -1,     7,     8,    27,
      -1,    -1,    30,    31,    32,    33,    34,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    -1,     7,     8,    45,    46,    -1,
      30,    31,    32,    33,    34,    53,    36,    -1,    -1,    39,
      -1,    -1,    -1,     7,     8,    45,    46,    -1,    30,    31,
      32,    33,    34,    53,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    30,    31,    32,    33,
      34,    53,    36,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    45,    46,    -1,    -1,    -1,    -1,    -1,    40,    53,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    27,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    40,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    27,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      40,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    28,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    40,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    28,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      40,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    29,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    39,    40,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    29,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    40,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    29,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    40,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    29,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    40,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    56,    57,    58,    59,    60,    61,    37,    -1,
      -1,    40,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    37,    -1,    -1,    40,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    56,    57,    58,    59,    60,    61,    37,    -1,
      -1,    40,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    39,    40,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    39,    40,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    39,
      40,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    56,    57,    58,    59,
      60,    61,    40,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    64,    65,    66,     0,     9,    20,    24,    34,    67,
      75,    76,    77,    78,    89,     7,     8,    30,    31,    32,
      33,    34,    36,    45,    46,    53,    81,    82,    84,    91,
      22,    34,    34,    38,    27,    27,    27,    27,    27,    28,
      29,    34,    36,    38,    82,    82,    82,    82,    35,    29,
      40,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    54,    55,    56,    57,    58,    59,    60,    61,
      36,    36,    29,    31,    39,    34,     3,     4,     5,     6,
      34,    90,    38,    82,    85,    82,    37,    34,    82,    90,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      37,    34,    88,    30,    69,    72,    73,    39,    29,    82,
      28,    37,    39,    36,    29,    29,    38,    28,    37,    34,
      68,    72,    28,    29,    29,    90,    39,    82,    82,    83,
      85,    79,    90,    39,    34,    29,    46,    38,    20,    70,
      71,    30,    90,    90,    37,    28,    10,    13,    16,    18,
      19,    21,    23,    27,    34,    75,    76,    80,    82,    87,
      29,    29,    38,    79,    49,    31,    39,    34,    25,    71,
      34,    27,    82,    36,    34,    36,    27,    27,    27,    82,
      38,    62,    27,    27,    27,    90,    90,    39,    21,    90,
      39,    29,    36,    82,    14,    82,    27,    31,    38,    29,
      29,    29,    90,    34,    74,    88,    37,    38,    37,    82,
      90,    79,    90,    27,    29,    38,    37,    28,    29,    82,
      29,    13,    23,    27,    90,    39,    29,    46,    34,    86,
      29,    86,    82,    80,    82,    29,    79,    49,    29,    38,
      11,    12,    34,    87,    82,    17,    29,    21,    27,    90,
      21,    90,    90,    39,    29,    27,    29,    39,    27,    31,
      90,    27,    29,    29,    86,    82,    29,    39,    14,    79,
      90,    12,    39,    86,    29,    34,    23,    27,    29,    15,
      90,    26,    80,    86,    27,    27,    31,    21,    15,    39,
      27,    27,    29,    90,    27
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    65,    65,    65,    65,    65,    66,    66,
      68,    67,    69,    69,    69,    70,    70,    70,    71,    71,
      72,    72,    72,    73,    73,    74,    74,    74,    74,    74,
      75,    76,    76,    76,    77,    77,    78,    79,    79,    79,
      79,    80,    81,    81,    81,    81,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    83,    83,    83,    84,    85,
      85,    85,    86,    86,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    88,    88,    88,
      88,    88,    89,    89,    90,    90,    90,    90,    90,    91,
      91,    91,    91,    91
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     3,     3,     3,     3,     0,     3,
       0,     7,     0,     1,     2,     0,     1,     2,    14,     9,
       4,     7,     8,     2,     4,     0,     3,     5,     5,     7,
       4,     3,     5,     6,    13,     8,     7,     0,     3,     3,
       2,     2,     1,     2,     5,     4,     1,     1,     1,     3,
       6,     3,     3,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     0,     1,     3,     4,     0,
       1,     3,     0,     2,     8,    11,    14,    12,    12,    16,
       8,     2,     2,     2,     3,     1,     1,     0,     3,     5,
       5,     7,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
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
  case 2: /* input: program_main  */
#line 114 "myanalyzer.y"
  {
     if (yyerror_count == 0) {
       puts(c_prologue);
       printf("%s", (yyvsp[0].str));
     }else{
     	 printf("Error num: %d",yyerror_count);
     }
 	}
#line 1529 "myanalyzer.tab.c"
    break;

  case 3: /* program: %empty  */
#line 144 "myanalyzer.y"
               {(yyval.str) = template("");}
#line 1535 "myanalyzer.tab.c"
    break;

  case 4: /* program: program declare_comp DELIM_SEMICOLON  */
#line 145 "myanalyzer.y"
                                             {(yyval.str) = template("%s\n%s", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 1541 "myanalyzer.tab.c"
    break;

  case 5: /* program: program declare_const DELIM_SEMICOLON  */
#line 146 "myanalyzer.y"
                                               {(yyval.str) = template("%s\n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 1547 "myanalyzer.tab.c"
    break;

  case 6: /* program: program declare_var DELIM_SEMICOLON  */
#line 147 "myanalyzer.y"
                                             {(yyval.str) = template("%s\n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 1553 "myanalyzer.tab.c"
    break;

  case 7: /* program: program declare_func DELIM_SEMICOLON  */
#line 148 "myanalyzer.y"
                                             {(yyval.str) = template("%s\n\n%s", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 1559 "myanalyzer.tab.c"
    break;

  case 8: /* program_main: %empty  */
#line 152 "myanalyzer.y"
               {(yyval.str) = template("");}
#line 1565 "myanalyzer.tab.c"
    break;

  case 9: /* program_main: program declare_main DELIM_SEMICOLON  */
#line 153 "myanalyzer.y"
                                              {(yyval.str) = template("%s\n\n%s\n", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 1571 "myanalyzer.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 157 "myanalyzer.y"
                                                             { comp_type = (yyvsp[-2].str); }
#line 1577 "myanalyzer.tab.c"
    break;

  case 11: /* declare_comp: KEYWORD_COMP IDENTIFIER DELIM_COLON comp_members_var $@1 comp_members_method KEYWORD_ENDCOMP  */
#line 158 "myanalyzer.y"
        {	
		(yyval.str) = template("#define SELF struct %s *self\ntypedef struct %s {\n%s%s}%s;\n\n%s\n%s ctor_%s = {%s};\n#undef SELF\n",(yyvsp[-5].str), (yyvsp[-5].str), (yyvsp[-3].str),comp_func,(yyvsp[-5].str), (yyvsp[-1].str), (yyvsp[-5].str), (yyvsp[-5].str), func_names);
		comp_func = template("");
		func_names = template("");}
#line 1586 "myanalyzer.tab.c"
    break;

  case 12: /* comp_members_var: %empty  */
#line 166 "myanalyzer.y"
               {(yyval.str) = template("");}
#line 1592 "myanalyzer.tab.c"
    break;

  case 13: /* comp_members_var: member_var  */
#line 167 "myanalyzer.y"
                    {(yyval.str) = template("%s;\n", (yyvsp[0].str));}
#line 1598 "myanalyzer.tab.c"
    break;

  case 14: /* comp_members_var: comp_members_var member_var  */
#line 168 "myanalyzer.y"
                                     {(yyval.str) = template("%s%s;\n", (yyvsp[-1].str), (yyvsp[0].str));}
#line 1604 "myanalyzer.tab.c"
    break;

  case 15: /* comp_members_method: %empty  */
#line 172 "myanalyzer.y"
               {(yyval.str) = template("");}
#line 1610 "myanalyzer.tab.c"
    break;

  case 16: /* comp_members_method: member_method  */
#line 173 "myanalyzer.y"
                       {(yyval.str) = template("%s;\n", (yyvsp[0].str));}
#line 1616 "myanalyzer.tab.c"
    break;

  case 17: /* comp_members_method: comp_members_method member_method  */
#line 174 "myanalyzer.y"
                                           {(yyval.str) = template("%s\n%s;\n", (yyvsp[-1].str), (yyvsp[0].str));}
#line 1622 "myanalyzer.tab.c"
    break;

  case 18: /* member_method: KEYWORD_DEF IDENTIFIER DELIM_LPAR method_arg DELIM_RPAR OP_MINUS OP_BIGGER data_type DELIM_COLON func_body KEYWORD_RETURN expression KEYWORD_ENDDEF DELIM_SEMICOLON  */
#line 180 "myanalyzer.y"
        {(yyval.str) = template("%s %s(SELF%s){%s\nreturn %s\n}", (yyvsp[-6].str), (yyvsp[-12].str), (yyvsp[-10].str), (yyvsp[-4].str), (yyvsp[-2].str));
	if (comp_func != null) {
		comp_func = template("%s (*%s) (SELF%s);\n%s", (yyvsp[-6].str), (yyvsp[-12].str), (yyvsp[-10].str), comp_func);
		func_names = template(".%s = %s,%s", (yyvsp[-12].str), (yyvsp[-12].str), func_names);
	}else{
		comp_func = template("%s (*%s) (SELF%s);\n", (yyvsp[-6].str), (yyvsp[-12].str), (yyvsp[-10].str));
		func_names = template(".%s = %s", (yyvsp[-12].str), (yyvsp[-12].str));
	}	
	}
#line 1636 "myanalyzer.tab.c"
    break;

  case 19: /* member_method: KEYWORD_DEF IDENTIFIER DELIM_LPAR method_arg DELIM_RPAR DELIM_COLON func_body KEYWORD_ENDDEF DELIM_SEMICOLON  */
#line 190 "myanalyzer.y"
        {(yyval.str) = template("void %s(SELF%s){%s\n}", (yyvsp[-7].str), (yyvsp[-5].str), (yyvsp[-2].str));
	if (comp_func != null) {
		comp_func = template("void (*%s) (SELF%s);\n%s", (yyvsp[-7].str), (yyvsp[-5].str), comp_func);
		func_names = template(".%s = %s,%s", (yyvsp[-7].str), (yyvsp[-7].str), func_names);
	}else{
		comp_func = template("void (*%s) (SELF%s);\n", (yyvsp[-7].str), (yyvsp[-5].str));
		func_names = template(".%s = %s", (yyvsp[-7].str), (yyvsp[-7].str));
	}
	}
#line 1650 "myanalyzer.tab.c"
    break;

  case 20: /* member_var: member_var_identifiers DELIM_COLON data_type DELIM_SEMICOLON  */
#line 203 "myanalyzer.y"
                                                                     {(yyval.str) = template("%s %s", (yyvsp[-1].str), (yyvsp[-3].str));}
#line 1656 "myanalyzer.tab.c"
    break;

  case 21: /* member_var: OP_HASHTAG IDENTIFIER DELIM_LBRAC DELIM_RBRAC DELIM_COLON data_type DELIM_SEMICOLON  */
#line 204 "myanalyzer.y"
                                                                                             {(yyval.str) = template("%s* %s", (yyvsp[-1].str), (yyvsp[-5].str));}
#line 1662 "myanalyzer.tab.c"
    break;

  case 22: /* member_var: OP_HASHTAG IDENTIFIER DELIM_LBRAC CONST_INTEGER DELIM_RBRAC DELIM_COLON data_type DELIM_SEMICOLON  */
#line 205 "myanalyzer.y"
                                                                                                           {(yyval.str) = template("%s %s[%s]", (yyvsp[-1].str), (yyvsp[-6].str), (yyvsp[-4].str));}
#line 1668 "myanalyzer.tab.c"
    break;

  case 23: /* member_var_identifiers: OP_HASHTAG IDENTIFIER  */
#line 209 "myanalyzer.y"
                              {(yyval.str) = (yyvsp[0].str);}
#line 1674 "myanalyzer.tab.c"
    break;

  case 24: /* member_var_identifiers: member_var_identifiers DELIM_COMMA OP_HASHTAG IDENTIFIER  */
#line 210 "myanalyzer.y"
                                                                  {(yyval.str) = template("%s, %s", (yyvsp[-3].str), (yyvsp[0].str));}
#line 1680 "myanalyzer.tab.c"
    break;

  case 25: /* method_arg: %empty  */
#line 214 "myanalyzer.y"
               {(yyval.str) = template("");}
#line 1686 "myanalyzer.tab.c"
    break;

  case 26: /* method_arg: IDENTIFIER DELIM_COLON data_type  */
#line 215 "myanalyzer.y"
                                          {(yyval.str) = template(" ,%s %s", (yyvsp[0].str), (yyvsp[-2].str));}
#line 1692 "myanalyzer.tab.c"
    break;

  case 27: /* method_arg: IDENTIFIER DELIM_LBRAC DELIM_RBRAC DELIM_COLON data_type  */
#line 216 "myanalyzer.y"
                                                                  {(yyval.str) = template(" ,%s* %s", (yyvsp[0].str), (yyvsp[-4].str));}
#line 1698 "myanalyzer.tab.c"
    break;

  case 28: /* method_arg: func_arg DELIM_COMMA IDENTIFIER DELIM_COLON data_type  */
#line 217 "myanalyzer.y"
                                                               {(yyval.str) = template(" ,%s, %s %s", (yyvsp[-4].str), (yyvsp[0].str), (yyvsp[-2].str));}
#line 1704 "myanalyzer.tab.c"
    break;

  case 29: /* method_arg: func_arg DELIM_COMMA IDENTIFIER DELIM_LBRAC DELIM_RBRAC DELIM_COLON data_type  */
#line 218 "myanalyzer.y"
                                                                                       {(yyval.str) = template(" ,%s, %s* %s", (yyvsp[-6].str), (yyvsp[0].str), (yyvsp[-4].str));}
#line 1710 "myanalyzer.tab.c"
    break;

  case 30: /* declare_const: KEYWORD_CONST expr DELIM_COLON data_type  */
#line 222 "myanalyzer.y"
                                                 {(yyval.str) = template("%s %s", (yyvsp[0].str), (yyvsp[-2].str));}
#line 1716 "myanalyzer.tab.c"
    break;

  case 31: /* declare_var: var_identifiers DELIM_COLON data_type  */
#line 227 "myanalyzer.y"
                                              {
		if ( !strcmp((yyvsp[0].str),"int") || !strcmp((yyvsp[0].str),"char*") || !strcmp((yyvsp[0].str),"double") ){
			(yyval.str) = template("%s %s", (yyvsp[0].str), (yyvsp[-2].str));
		}else{
			(yyval.str) = template("%s %s = %s", comp_type, (yyvsp[-2].str), (yyvsp[0].str));
		};}
#line 1727 "myanalyzer.tab.c"
    break;

  case 32: /* declare_var: IDENTIFIER DELIM_LBRAC DELIM_RBRAC DELIM_COLON data_type  */
#line 233 "myanalyzer.y"
                                                                  {(yyval.str) = template("%s* %s", (yyvsp[0].str), (yyvsp[-4].str));}
#line 1733 "myanalyzer.tab.c"
    break;

  case 33: /* declare_var: IDENTIFIER DELIM_LBRAC CONST_INTEGER DELIM_RBRAC DELIM_COLON data_type  */
#line 234 "myanalyzer.y"
                                                                                {(yyval.str) = template("%s %s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));}
#line 1739 "myanalyzer.tab.c"
    break;

  case 34: /* declare_func: KEYWORD_DEF IDENTIFIER DELIM_LPAR func_arg DELIM_RPAR OP_MINUS OP_BIGGER data_type DELIM_COLON func_body KEYWORD_RETURN expression KEYWORD_ENDDEF  */
#line 239 "myanalyzer.y"
        {(yyval.str) = template("%s %s(%s){%s\nreturn %s\n}", (yyvsp[-5].str), (yyvsp[-11].str), (yyvsp[-9].str), (yyvsp[-3].str), (yyvsp[-1].str));}
#line 1745 "myanalyzer.tab.c"
    break;

  case 35: /* declare_func: KEYWORD_DEF IDENTIFIER DELIM_LPAR func_arg DELIM_RPAR DELIM_COLON func_body KEYWORD_ENDDEF  */
#line 241 "myanalyzer.y"
        {(yyval.str) = template("void %s(%s){%s\n}", (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-1].str));}
#line 1751 "myanalyzer.tab.c"
    break;

  case 36: /* declare_main: KEYWORD_DEF KEYWORD_MAIN DELIM_LPAR DELIM_RPAR DELIM_COLON func_body KEYWORD_ENDDEF  */
#line 245 "myanalyzer.y"
                                                                                            {(yyval.str) = template("void main() {%s\n}", (yyvsp[-1].str));}
#line 1757 "myanalyzer.tab.c"
    break;

  case 37: /* func_body: %empty  */
#line 252 "myanalyzer.y"
               {(yyval.str) = template("");}
#line 1763 "myanalyzer.tab.c"
    break;

  case 38: /* func_body: func_body declare_const DELIM_SEMICOLON  */
#line 253 "myanalyzer.y"
                                                 {(yyval.str) = template("%s\n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 1769 "myanalyzer.tab.c"
    break;

  case 39: /* func_body: func_body declare_var DELIM_SEMICOLON  */
#line 254 "myanalyzer.y"
                                               {(yyval.str) = template("%s\n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 1775 "myanalyzer.tab.c"
    break;

  case 40: /* func_body: func_body instruction  */
#line 255 "myanalyzer.y"
                          {(yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str));}
#line 1781 "myanalyzer.tab.c"
    break;

  case 41: /* expression: expr DELIM_SEMICOLON  */
#line 259 "myanalyzer.y"
                             {(yyval.str) = template("%s;", (yyvsp[-1].str));}
#line 1787 "myanalyzer.tab.c"
    break;

  case 42: /* expr_identifiers: IDENTIFIER  */
#line 263 "myanalyzer.y"
                   {(yyval.str) = (yyvsp[0].str);}
#line 1793 "myanalyzer.tab.c"
    break;

  case 43: /* expr_identifiers: OP_HASHTAG IDENTIFIER  */
#line 264 "myanalyzer.y"
                               {(yyval.str) = template("self->%s", (yyvsp[0].str));}
#line 1799 "myanalyzer.tab.c"
    break;

  case 44: /* expr_identifiers: OP_HASHTAG IDENTIFIER DELIM_LBRAC expr DELIM_RBRAC  */
#line 265 "myanalyzer.y"
                                                            {(yyval.str) = template("self->%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str));}
#line 1805 "myanalyzer.tab.c"
    break;

  case 45: /* expr_identifiers: IDENTIFIER DELIM_LBRAC expr DELIM_RBRAC  */
#line 266 "myanalyzer.y"
                                                 {(yyval.str) = template("%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str));}
#line 1811 "myanalyzer.tab.c"
    break;

  case 46: /* expr: data_const  */
#line 274 "myanalyzer.y"
                   {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 1817 "myanalyzer.tab.c"
    break;

  case 47: /* expr: expr_identifiers  */
#line 275 "myanalyzer.y"
                          {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 1823 "myanalyzer.tab.c"
    break;

  case 48: /* expr: func_call  */
#line 276 "myanalyzer.y"
                   {(yyval.str) = template("%s",(yyvsp[0].str));}
#line 1829 "myanalyzer.tab.c"
    break;

  case 49: /* expr: expr_identifiers DELIM_DOT expr  */
#line 277 "myanalyzer.y"
                                     {(yyval.str) = template("%s.%s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1835 "myanalyzer.tab.c"
    break;

  case 50: /* expr: expr_identifiers DELIM_DOT IDENTIFIER DELIM_LPAR method_n_expr DELIM_RPAR  */
#line 278 "myanalyzer.y"
                                                                                    {(yyval.str) = template("%s.%s(&%s%s)", (yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-5].str), (yyvsp[-1].str));}
#line 1841 "myanalyzer.tab.c"
    break;

  case 51: /* expr: DELIM_LPAR expr DELIM_RPAR  */
#line 281 "myanalyzer.y"
                                    {(yyval.str) = template("(%s)",(yyvsp[-1].str));}
#line 1847 "myanalyzer.tab.c"
    break;

  case 52: /* expr: expr OP_POWER expr  */
#line 282 "myanalyzer.y"
                            {(yyval.str) = template("pow(%s, %s)", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1853 "myanalyzer.tab.c"
    break;

  case 53: /* expr: OP_PLUS expr  */
#line 283 "myanalyzer.y"
                                    {(yyval.str) = template("+%s",(yyvsp[0].str));}
#line 1859 "myanalyzer.tab.c"
    break;

  case 54: /* expr: OP_MINUS expr  */
#line 284 "myanalyzer.y"
                                     {(yyval.str) = template("-%s",(yyvsp[0].str));}
#line 1865 "myanalyzer.tab.c"
    break;

  case 55: /* expr: expr OP_PROD expr  */
#line 285 "myanalyzer.y"
                           {(yyval.str) = template("%s * %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1871 "myanalyzer.tab.c"
    break;

  case 56: /* expr: expr OP_DIV expr  */
#line 286 "myanalyzer.y"
                          {(yyval.str) = template("%s / %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1877 "myanalyzer.tab.c"
    break;

  case 57: /* expr: expr OP_MOD expr  */
#line 287 "myanalyzer.y"
                          {(yyval.str) = template("%s %% %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1883 "myanalyzer.tab.c"
    break;

  case 58: /* expr: expr OP_PLUS expr  */
#line 288 "myanalyzer.y"
                           {(yyval.str) = template("%s + %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1889 "myanalyzer.tab.c"
    break;

  case 59: /* expr: expr OP_MINUS expr  */
#line 289 "myanalyzer.y"
                            {(yyval.str) = template("%s - %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1895 "myanalyzer.tab.c"
    break;

  case 60: /* expr: expr OP_SMALLER expr  */
#line 291 "myanalyzer.y"
                              {(yyval.str) = template("%s < %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1901 "myanalyzer.tab.c"
    break;

  case 61: /* expr: expr OP_SMALLER_EQ expr  */
#line 292 "myanalyzer.y"
                                 {(yyval.str) = template("%s <= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1907 "myanalyzer.tab.c"
    break;

  case 62: /* expr: expr OP_BIGGER expr  */
#line 293 "myanalyzer.y"
                             {(yyval.str) = template("%s > %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1913 "myanalyzer.tab.c"
    break;

  case 63: /* expr: expr OP_BIGGER_EQ expr  */
#line 294 "myanalyzer.y"
                                {(yyval.str) = template("%s >= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1919 "myanalyzer.tab.c"
    break;

  case 64: /* expr: expr OP_EQUALS expr  */
#line 295 "myanalyzer.y"
                             {(yyval.str) = template("%s == %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1925 "myanalyzer.tab.c"
    break;

  case 65: /* expr: expr OP_NOT_EQUALS expr  */
#line 296 "myanalyzer.y"
                                 {(yyval.str) = template("%s != %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1931 "myanalyzer.tab.c"
    break;

  case 66: /* expr: KEYWORD_NOT expr  */
#line 297 "myanalyzer.y"
                          {(yyval.str) = template("!%s", (yyvsp[0].str));}
#line 1937 "myanalyzer.tab.c"
    break;

  case 67: /* expr: expr KEYWORD_AND expr  */
#line 298 "myanalyzer.y"
                               {(yyval.str) = template("%s && %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1943 "myanalyzer.tab.c"
    break;

  case 68: /* expr: expr KEYWORD_OR expr  */
#line 299 "myanalyzer.y"
                              {(yyval.str) = template("%s || %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1949 "myanalyzer.tab.c"
    break;

  case 69: /* expr: expr OP_ASSIGN expr  */
#line 300 "myanalyzer.y"
                             {(yyval.str) = template("%s = %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1955 "myanalyzer.tab.c"
    break;

  case 70: /* expr: expr OP_ASSIGN_PLUS expr  */
#line 301 "myanalyzer.y"
                                  {(yyval.str) = template("%s += %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1961 "myanalyzer.tab.c"
    break;

  case 71: /* expr: expr OP_ASSIGN_MINUS expr  */
#line 302 "myanalyzer.y"
                                   {(yyval.str) = template("%s -= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1967 "myanalyzer.tab.c"
    break;

  case 72: /* expr: expr OP_ASSIGN_PROD expr  */
#line 303 "myanalyzer.y"
                                  {(yyval.str) = template("%s *= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1973 "myanalyzer.tab.c"
    break;

  case 73: /* expr: expr OP_ASSIGN_DIV expr  */
#line 304 "myanalyzer.y"
                                 {(yyval.str) = template("%s /= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1979 "myanalyzer.tab.c"
    break;

  case 74: /* expr: expr OP_ASSIGN_MOD expr  */
#line 305 "myanalyzer.y"
                                 {(yyval.str) = template("%s %= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1985 "myanalyzer.tab.c"
    break;

  case 75: /* method_n_expr: %empty  */
#line 316 "myanalyzer.y"
               {(yyval.str) = template("");}
#line 1991 "myanalyzer.tab.c"
    break;

  case 76: /* method_n_expr: expr  */
#line 317 "myanalyzer.y"
              {(yyval.str) = template(",%s", (yyvsp[0].str));}
#line 1997 "myanalyzer.tab.c"
    break;

  case 77: /* method_n_expr: n_expr DELIM_COMMA expr  */
#line 318 "myanalyzer.y"
                                 {(yyval.str) = template("%s, %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2003 "myanalyzer.tab.c"
    break;

  case 78: /* func_call: IDENTIFIER DELIM_LPAR n_expr DELIM_RPAR  */
#line 322 "myanalyzer.y"
                                                 {(yyval.str) = template("%s(%s)", (yyvsp[-3].str), (yyvsp[-1].str));}
#line 2009 "myanalyzer.tab.c"
    break;

  case 79: /* n_expr: %empty  */
#line 326 "myanalyzer.y"
               {(yyval.str) = template("");}
#line 2015 "myanalyzer.tab.c"
    break;

  case 80: /* n_expr: expr  */
#line 327 "myanalyzer.y"
              {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2021 "myanalyzer.tab.c"
    break;

  case 81: /* n_expr: n_expr DELIM_COMMA expr  */
#line 328 "myanalyzer.y"
                                 {(yyval.str) = template("%s, %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2027 "myanalyzer.tab.c"
    break;

  case 82: /* statements: %empty  */
#line 332 "myanalyzer.y"
               {(yyval.str) = template("");}
#line 2033 "myanalyzer.tab.c"
    break;

  case 83: /* statements: statements instruction  */
#line 333 "myanalyzer.y"
                                {(yyval.str) = template("%s%s", (yyvsp[-1].str), (yyvsp[0].str));}
#line 2039 "myanalyzer.tab.c"
    break;

  case 84: /* instruction: KEYWORD_IF DELIM_LPAR expr DELIM_RPAR DELIM_COLON statements KEYWORD_ENDIF DELIM_SEMICOLON  */
#line 341 "myanalyzer.y"
                                                                                                   {(yyval.str) = template("if (%s){\n%s};", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2045 "myanalyzer.tab.c"
    break;

  case 85: /* instruction: KEYWORD_IF DELIM_LPAR expr DELIM_RPAR DELIM_COLON statements KEYWORD_ELSE DELIM_COLON statements KEYWORD_ENDIF DELIM_SEMICOLON  */
#line 343 "myanalyzer.y"
        {(yyval.str) = template("if (%s){\n%s}else{\n%s}", (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2051 "myanalyzer.tab.c"
    break;

  case 86: /* instruction: KEYWORD_FOR IDENTIFIER KEYWORD_IN DELIM_LBRAC expr DELIM_COLON expr DELIM_COLON expr DELIM_RBRAC DELIM_COLON statements KEYWORD_ENDFOR DELIM_SEMICOLON  */
#line 346 "myanalyzer.y"
        {(yyval.str) = template("for (int %s = %s ; %s < %s ; %s += %s){\n%s}", (yyvsp[-12].str), (yyvsp[-9].str), (yyvsp[-12].str), (yyvsp[-7].str), (yyvsp[-12].str), (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2057 "myanalyzer.tab.c"
    break;

  case 87: /* instruction: KEYWORD_FOR IDENTIFIER KEYWORD_IN DELIM_LBRAC expr DELIM_COLON expr DELIM_RBRAC DELIM_COLON statements KEYWORD_ENDFOR DELIM_SEMICOLON  */
#line 349 "myanalyzer.y"
        {(yyval.str) = template("for (int %s = %s ; %s < %s ; %s += 1){\n%s;}", (yyvsp[-10].str), (yyvsp[-7].str), (yyvsp[-10].str), (yyvsp[-5].str), (yyvsp[-10].str), (yyvsp[-2].str));}
#line 2063 "myanalyzer.tab.c"
    break;

  case 88: /* instruction: IDENTIFIER OP_ASSIGN_ARR DELIM_LBRAC expr KEYWORD_FOR expr DELIM_COLON CONST_INTEGER DELIM_RBRAC DELIM_COLON data_type DELIM_SEMICOLON  */
#line 351 "myanalyzer.y"
        {(yyval.str) = template("%s* %s = (%s*)malloc(%s * sizeof(%s)); \nfor (int %s = 0; %s < %s; ++%s){\n%s[%s] = %s;\n}", (yyvsp[-1].str), (yyvsp[-11].str), (yyvsp[-1].str), (yyvsp[-4].str), (yyvsp[-1].str), (yyvsp[-6].str), (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-6].str), (yyvsp[-11].str), (yyvsp[-6].str), (yyvsp[-8].str));}
#line 2069 "myanalyzer.tab.c"
    break;

  case 89: /* instruction: IDENTIFIER OP_ASSIGN_ARR DELIM_LBRAC expr KEYWORD_FOR expr DELIM_COLON data_type KEYWORD_IN IDENTIFIER KEYWORD_OF CONST_INTEGER DELIM_RBRAC DELIM_COLON data_type DELIM_SEMICOLON  */
#line 353 "myanalyzer.y"
        {(yyval.str) = template("%s* %s = (%s*)malloc(%s * sizeof(%s)); \nfor (int array_i = 0; array_i < %s; ++array_i){\n%s[array_i] = %s[array_i];\n}", (yyvsp[-1].str), (yyvsp[-15].str), (yyvsp[-1].str), (yyvsp[-4].str), (yyvsp[-1].str), (yyvsp[-4].str), (yyvsp[-15].str), (yyvsp[-6].str));}
#line 2075 "myanalyzer.tab.c"
    break;

  case 90: /* instruction: KEYWORD_WHILE DELIM_LPAR expr DELIM_RPAR DELIM_COLON statements KEYWORD_ENDWHILE DELIM_SEMICOLON  */
#line 354 "myanalyzer.y"
                                                                                                          {(yyval.str) = template("while (%s){\n%s}", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2081 "myanalyzer.tab.c"
    break;

  case 91: /* instruction: KEYWORD_BREAK DELIM_SEMICOLON  */
#line 355 "myanalyzer.y"
                                       {(yyval.str) = template("break;");}
#line 2087 "myanalyzer.tab.c"
    break;

  case 92: /* instruction: KEYWORD_CONTINUE DELIM_SEMICOLON  */
#line 356 "myanalyzer.y"
                                          {(yyval.str) = template("continue;");}
#line 2093 "myanalyzer.tab.c"
    break;

  case 93: /* instruction: KEYWORD_RETURN DELIM_SEMICOLON  */
#line 357 "myanalyzer.y"
                                        {(yyval.str) = template("return;");}
#line 2099 "myanalyzer.tab.c"
    break;

  case 94: /* instruction: KEYWORD_RETURN expr DELIM_SEMICOLON  */
#line 358 "myanalyzer.y"
                                             {(yyval.str) = template("return %s;", (yyvsp[-1].str));}
#line 2105 "myanalyzer.tab.c"
    break;

  case 95: /* instruction: DELIM_SEMICOLON  */
#line 361 "myanalyzer.y"
                         {(yyval.str) = template("");}
#line 2111 "myanalyzer.tab.c"
    break;

  case 96: /* instruction: expression  */
#line 362 "myanalyzer.y"
                    {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2117 "myanalyzer.tab.c"
    break;

  case 97: /* func_arg: %empty  */
#line 369 "myanalyzer.y"
               {(yyval.str) = template("");}
#line 2123 "myanalyzer.tab.c"
    break;

  case 98: /* func_arg: IDENTIFIER DELIM_COLON data_type  */
#line 370 "myanalyzer.y"
                                          {(yyval.str) = template("%s %s", (yyvsp[0].str), (yyvsp[-2].str));}
#line 2129 "myanalyzer.tab.c"
    break;

  case 99: /* func_arg: IDENTIFIER DELIM_LBRAC DELIM_RBRAC DELIM_COLON data_type  */
#line 371 "myanalyzer.y"
                                                                  {(yyval.str) = template("%s* %s", (yyvsp[0].str), (yyvsp[-4].str));}
#line 2135 "myanalyzer.tab.c"
    break;

  case 100: /* func_arg: func_arg DELIM_COMMA IDENTIFIER DELIM_COLON data_type  */
#line 372 "myanalyzer.y"
                                                               {(yyval.str) = template("%s, %s %s", (yyvsp[-4].str), (yyvsp[0].str), (yyvsp[-2].str));}
#line 2141 "myanalyzer.tab.c"
    break;

  case 101: /* func_arg: func_arg DELIM_COMMA IDENTIFIER DELIM_LBRAC DELIM_RBRAC DELIM_COLON data_type  */
#line 373 "myanalyzer.y"
                                                                                       {(yyval.str) = template("%s, %s* %s", (yyvsp[-6].str), (yyvsp[0].str), (yyvsp[-4].str));}
#line 2147 "myanalyzer.tab.c"
    break;

  case 102: /* var_identifiers: IDENTIFIER  */
#line 377 "myanalyzer.y"
                   {(yyval.str) = (yyvsp[0].str);}
#line 2153 "myanalyzer.tab.c"
    break;

  case 103: /* var_identifiers: var_identifiers DELIM_COMMA IDENTIFIER  */
#line 378 "myanalyzer.y"
                                                {(yyval.str) = template("%s, %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2159 "myanalyzer.tab.c"
    break;

  case 104: /* data_type: KEYWORD_INTEGER  */
#line 383 "myanalyzer.y"
                        {(yyval.str) = template("int");}
#line 2165 "myanalyzer.tab.c"
    break;

  case 105: /* data_type: KEYWORD_SCALAR  */
#line 384 "myanalyzer.y"
                        {(yyval.str) = template("double");}
#line 2171 "myanalyzer.tab.c"
    break;

  case 106: /* data_type: KEYWORD_STR  */
#line 385 "myanalyzer.y"
                     {(yyval.str) = template("char*");}
#line 2177 "myanalyzer.tab.c"
    break;

  case 107: /* data_type: KEYWORD_BOOL  */
#line 386 "myanalyzer.y"
                      {(yyval.str) = template("int");}
#line 2183 "myanalyzer.tab.c"
    break;

  case 108: /* data_type: IDENTIFIER  */
#line 387 "myanalyzer.y"
                    {(yyval.str) = template("%s", (yyvsp[0].str));
//	|IDENTIFIER {$$ = template("ctor_%s", $1);
	comp_type = template("%s", (yyvsp[0].str));}
#line 2191 "myanalyzer.tab.c"
    break;

  case 109: /* data_const: CONST_INTEGER  */
#line 393 "myanalyzer.y"
                      {(yyval.str) = (yyvsp[0].str);}
#line 2197 "myanalyzer.tab.c"
    break;

  case 110: /* data_const: CONST_FLOAT  */
#line 394 "myanalyzer.y"
                     {(yyval.str) = (yyvsp[0].str);}
#line 2203 "myanalyzer.tab.c"
    break;

  case 111: /* data_const: CONST_STRING  */
#line 395 "myanalyzer.y"
                      {(yyval.str) = (yyvsp[0].str);}
#line 2209 "myanalyzer.tab.c"
    break;

  case 112: /* data_const: KEYWORD_TRUE  */
#line 396 "myanalyzer.y"
                      {(yyval.str) = template("1");}
#line 2215 "myanalyzer.tab.c"
    break;

  case 113: /* data_const: KEYWORD_FALSE  */
#line 397 "myanalyzer.y"
                       {(yyval.str) = template("0");}
#line 2221 "myanalyzer.tab.c"
    break;


#line 2225 "myanalyzer.tab.c"

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

#line 401 "myanalyzer.y"

int main ()
{	
   if ( yyparse() == 0 ){
   	//printf("Accepted!\n");
   }
	else
		printf("Rejected!\n");
}


//ERWTHSH PWS KOITAW AN TO INTEGER EINAI THETIK

//ERWTHSH TA ARGS EINAI MONO data_type KAI EMPTY PINAKAS STO FUNCTION INPUT?

//TODO TEST METHOD CASE1 WITH THE RETURN
//TODO TEST FUNCTION
//TODO KSANA RWTHSW GIA TO TI PAIZEI ME TO CIRCLE
