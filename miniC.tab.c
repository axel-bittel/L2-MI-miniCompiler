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
#line 1 "./src/miniC.y"

	#include "compiler.h"
	#include <stdio.h>
	#include <unistd.h>
	#define YYDEBUG 1

	t_tree	*ast;
	t_symbol_table	*global_symbol_table;

#line 81 "miniC.tab.c"

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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFICATEUR = 258,          /* IDENTIFICATEUR  */
    CONSTANTE = 259,               /* CONSTANTE  */
    VOID = 260,                    /* VOID  */
    INT = 261,                     /* INT  */
    FOR = 262,                     /* FOR  */
    WHILE = 263,                   /* WHILE  */
    IF = 264,                      /* IF  */
    ELSE = 265,                    /* ELSE  */
    SWITCH = 266,                  /* SWITCH  */
    CASE = 267,                    /* CASE  */
    DEFAULT = 268,                 /* DEFAULT  */
    BREAK = 269,                   /* BREAK  */
    RETURN = 270,                  /* RETURN  */
    PLUS = 271,                    /* PLUS  */
    MOINS = 272,                   /* MOINS  */
    MUL = 273,                     /* MUL  */
    DIV = 274,                     /* DIV  */
    LSHIFT = 275,                  /* LSHIFT  */
    RSHIFT = 276,                  /* RSHIFT  */
    BAND = 277,                    /* BAND  */
    BOR = 278,                     /* BOR  */
    LAND = 279,                    /* LAND  */
    LOR = 280,                     /* LOR  */
    LT = 281,                      /* LT  */
    GT = 282,                      /* GT  */
    GEQ = 283,                     /* GEQ  */
    LEQ = 284,                     /* LEQ  */
    EQ = 285,                      /* EQ  */
    NEQ = 286,                     /* NEQ  */
    NOT = 287,                     /* NOT  */
    EXTERN = 288,                  /* EXTERN  */
    THEN = 289,                    /* THEN  */
    OP = 290,                      /* OP  */
    REL = 291                      /* REL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 11 "./src/miniC.y"

			int 	inttype;
			char	*id;
			t_tree	*tree;
		

#line 171 "miniC.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFICATEUR = 3,             /* IDENTIFICATEUR  */
  YYSYMBOL_CONSTANTE = 4,                  /* CONSTANTE  */
  YYSYMBOL_VOID = 5,                       /* VOID  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_FOR = 7,                        /* FOR  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_SWITCH = 11,                    /* SWITCH  */
  YYSYMBOL_CASE = 12,                      /* CASE  */
  YYSYMBOL_DEFAULT = 13,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 14,                     /* BREAK  */
  YYSYMBOL_RETURN = 15,                    /* RETURN  */
  YYSYMBOL_PLUS = 16,                      /* PLUS  */
  YYSYMBOL_MOINS = 17,                     /* MOINS  */
  YYSYMBOL_MUL = 18,                       /* MUL  */
  YYSYMBOL_DIV = 19,                       /* DIV  */
  YYSYMBOL_LSHIFT = 20,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 21,                    /* RSHIFT  */
  YYSYMBOL_BAND = 22,                      /* BAND  */
  YYSYMBOL_BOR = 23,                       /* BOR  */
  YYSYMBOL_LAND = 24,                      /* LAND  */
  YYSYMBOL_LOR = 25,                       /* LOR  */
  YYSYMBOL_LT = 26,                        /* LT  */
  YYSYMBOL_GT = 27,                        /* GT  */
  YYSYMBOL_GEQ = 28,                       /* GEQ  */
  YYSYMBOL_LEQ = 29,                       /* LEQ  */
  YYSYMBOL_EQ = 30,                        /* EQ  */
  YYSYMBOL_NEQ = 31,                       /* NEQ  */
  YYSYMBOL_NOT = 32,                       /* NOT  */
  YYSYMBOL_EXTERN = 33,                    /* EXTERN  */
  YYSYMBOL_THEN = 34,                      /* THEN  */
  YYSYMBOL_OP = 35,                        /* OP  */
  YYSYMBOL_REL = 36,                       /* REL  */
  YYSYMBOL_37_ = 37,                       /* ';'  */
  YYSYMBOL_38_ = 38,                       /* ','  */
  YYSYMBOL_39_ = 39,                       /* '['  */
  YYSYMBOL_40_ = 40,                       /* ']'  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* '{'  */
  YYSYMBOL_44_ = 44,                       /* '}'  */
  YYSYMBOL_45_ = 45,                       /* ':'  */
  YYSYMBOL_46_ = 46,                       /* '='  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_programme = 48,                 /* programme  */
  YYSYMBOL_liste_declarations = 49,        /* liste_declarations  */
  YYSYMBOL_liste_fonctions = 50,           /* liste_fonctions  */
  YYSYMBOL_declaration = 51,               /* declaration  */
  YYSYMBOL_liste_declarateurs = 52,        /* liste_declarateurs  */
  YYSYMBOL_declarateur = 53,               /* declarateur  */
  YYSYMBOL_name = 54,                      /* name  */
  YYSYMBOL_fonction = 55,                  /* fonction  */
  YYSYMBOL_type = 56,                      /* type  */
  YYSYMBOL_function_param = 57,            /* function_param  */
  YYSYMBOL_liste_parms = 58,               /* liste_parms  */
  YYSYMBOL_parm = 59,                      /* parm  */
  YYSYMBOL_liste_instructions = 60,        /* liste_instructions  */
  YYSYMBOL_instruction = 61,               /* instruction  */
  YYSYMBOL_iteration = 62,                 /* iteration  */
  YYSYMBOL_case_liste_instructions = 63,   /* case_liste_instructions  */
  YYSYMBOL_case_instruction = 64,          /* case_instruction  */
  YYSYMBOL_case_selection = 65,            /* case_selection  */
  YYSYMBOL_selection = 66,                 /* selection  */
  YYSYMBOL_saut = 67,                      /* saut  */
  YYSYMBOL_affectation = 68,               /* affectation  */
  YYSYMBOL_bloc = 69,                      /* bloc  */
  YYSYMBOL_appel = 70,                     /* appel  */
  YYSYMBOL_variable = 71,                  /* variable  */
  YYSYMBOL_expression = 72,                /* expression  */
  YYSYMBOL_parm_call_function_list_expression = 73, /* parm_call_function_list_expression  */
  YYSYMBOL_liste_expressions = 74,         /* liste_expressions  */
  YYSYMBOL_condition = 75,                 /* condition  */
  YYSYMBOL_binary_op = 76,                 /* binary_op  */
  YYSYMBOL_binary_rel = 77,                /* binary_rel  */
  YYSYMBOL_binary_comp = 78                /* binary_comp  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   290

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  172

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
      41,    42,     2,     2,    38,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    37,
       2,    46,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    35,    35,    52,    53,    57,    65,    69,    73,    74,
      78,    85,   109,   113,   132,   144,   145,   149,   150,   154,
     155,   159,   168,   169,   173,   174,   175,   176,   177,   178,
     182,   184,   188,   189,   193,   194,   195,   196,   197,   201,
     202,   203,   207,   208,   209,   210,   215,   219,   220,   221,
     225,   229,   240,   248,   254,   279,   280,   286,   287,   292,
     293,   297,   298,   302,   303,   307,   308,   309,   310,   314,
     315,   316,   317,   318,   319,   320,   321,   325,   326,   330,
     331,   332,   333,   334,   335
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFICATEUR",
  "CONSTANTE", "VOID", "INT", "FOR", "WHILE", "IF", "ELSE", "SWITCH",
  "CASE", "DEFAULT", "BREAK", "RETURN", "PLUS", "MOINS", "MUL", "DIV",
  "LSHIFT", "RSHIFT", "BAND", "BOR", "LAND", "LOR", "LT", "GT", "GEQ",
  "LEQ", "EQ", "NEQ", "NOT", "EXTERN", "THEN", "OP", "REL", "';'", "','",
  "'['", "']'", "'('", "')'", "'{'", "'}'", "':'", "'='", "$accept",
  "programme", "liste_declarations", "liste_fonctions", "declaration",
  "liste_declarateurs", "declarateur", "name", "fonction", "type",
  "function_param", "liste_parms", "parm", "liste_instructions",
  "instruction", "iteration", "case_liste_instructions",
  "case_instruction", "case_selection", "selection", "saut", "affectation",
  "bloc", "appel", "variable", "expression",
  "parm_call_function_list_expression", "liste_expressions", "condition",
  "binary_op", "binary_rel", "binary_comp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-112)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-13)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -112,     1,    63,  -112,  -112,  -112,    27,    63,  -112,  -112,
       3,    10,  -112,    10,   -37,    35,   -24,   -18,  -112,   -11,
    -112,    54,    62,    64,    64,  -112,   -24,    34,    75,    41,
      49,  -112,    58,  -112,  -112,    72,    64,    81,  -112,  -112,
    -112,    27,    54,    32,   -37,    78,    79,    84,   104,   152,
     126,   130,   140,  -112,  -112,   134,  -112,  -112,  -112,  -112,
     136,  -112,   139,   -36,   176,    85,    85,     8,   135,  -112,
    -112,  -112,     8,  -112,     8,  -112,   168,   217,    27,     8,
    -112,  -112,     8,     8,  -112,   172,   178,    85,   245,    -6,
      37,   166,  -112,   203,   267,   174,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,     8,    98,   261,   171,   177,
     209,   261,    85,    85,   132,    56,  -112,  -112,  -112,  -112,
    -112,  -112,     8,  -112,  -112,   125,    85,   125,   125,   203,
     179,   180,  -112,  -112,  -112,  -112,   185,   186,  -112,  -112,
    -112,  -112,     8,  -112,   141,   122,  -112,   261,  -112,  -112,
     231,  -112,    85,     8,  -112,  -112,   261,   176,  -112,   125,
     218,   182,   202,  -112,   125,   125,   125,   235,  -112,  -112,
     125,  -112
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     1,    15,    16,     0,     2,     3,     6,
       0,     0,     5,     0,    10,     0,     9,     0,    12,     0,
       7,     0,     0,    18,    18,    10,     8,     0,     0,     0,
      17,    20,     0,    11,    21,     0,     0,     0,     4,    19,
      14,    23,     0,     0,    53,     0,     0,     0,     0,     0,
       0,     0,     0,     4,    13,     0,    22,    24,    25,    26,
       0,    28,     0,     0,     0,     0,     0,     0,     0,    33,
      47,    58,     0,    48,     0,    60,    59,     0,    23,    62,
      27,    29,     0,     0,    53,     0,     0,     0,     0,     0,
       0,     0,    33,    46,    57,     0,    69,    70,    71,    72,
      73,    74,    75,    76,    49,     0,     0,    64,     0,    61,
       0,    50,     0,     0,     0,     0,    79,    80,    81,    82,
      83,    84,     0,    77,    78,     0,     0,     0,     0,    45,
       0,     0,    34,    32,    35,    36,     0,     0,    55,    56,
      51,    52,     0,    54,     0,     0,    67,    68,    31,    66,
      42,    44,     0,     0,    37,    38,    63,     0,    65,     0,
       0,     0,     0,    43,     0,     0,     0,    39,    41,    30,
       0,    40
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -112,  -112,   -29,  -112,  -112,  -112,   225,   159,   240,    97,
     224,  -112,   214,   173,  -111,   -73,   160,  -112,  -112,  -112,
     -65,   -62,  -112,   -35,   -43,   -45,  -112,  -112,   -61,  -112,
    -112,  -112
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     7,     8,    15,    16,    55,     9,    42,
      29,    30,    31,    43,    56,    57,    93,   133,   134,    58,
      59,    60,    61,    75,    76,    88,   108,   109,    89,   105,
     126,   122
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      63,     3,    85,    82,   -12,    90,    14,    77,    62,    41,
      83,    44,    71,    18,   148,    22,   150,   151,   123,   124,
     132,    63,    91,    23,    78,    72,   115,    94,   135,    95,
      24,   136,     4,     5,   107,    44,   125,   110,   111,    45,
      46,    47,   114,    48,    49,    50,    51,    52,   163,    74,
      63,   144,   145,   167,   168,   169,   132,    25,   137,   171,
     139,   123,   124,    63,   135,   149,    27,   136,     4,     5,
      28,    62,    20,    21,    33,    53,    54,   147,    34,   127,
     123,   124,    63,    35,    63,    63,    63,    36,    44,    71,
      62,   160,    62,    62,   137,   162,     6,   156,   146,    10,
      37,    44,    72,    11,    13,    45,    46,    47,   161,    48,
      49,    50,    51,    52,    63,    38,    63,    86,    40,    64,
      65,    63,    63,    63,    62,    66,    87,    63,    44,    62,
      62,    62,    45,    46,    47,    62,    48,    49,    50,    51,
      52,    53,   140,    44,    71,    67,   123,   124,    96,    97,
      98,    99,   100,   101,   102,   103,    68,    72,   116,   117,
     118,   119,   120,   121,   158,   123,   124,    70,    53,    17,
      19,    69,    17,    80,   138,    79,    81,    73,   157,    84,
      92,    74,    96,    97,    98,    99,   100,   101,   102,   103,
      96,    97,    98,    99,   100,   101,   102,   103,    96,    97,
      98,    99,   100,   101,   102,   103,    44,    82,   128,   112,
      45,    46,   130,   141,   131,   142,   138,    51,    52,   113,
     152,   153,   154,   155,   165,    96,    97,    98,    99,   100,
     101,   102,   103,    96,    97,    98,    99,   100,   101,   102,
     103,   159,   123,   124,   166,   170,    26,    12,    32,   143,
      39,   106,   129,     0,   104,     0,     0,     0,     0,     0,
     164,    96,    97,    98,    99,   100,   101,   102,   103,     0,
       0,   116,   117,   118,   119,   120,   121,    96,    97,    98,
      99,   100,   101,   102,   103,    98,    99,   100,   101,   102,
     103
};

static const yytype_int16 yycheck[] =
{
      43,     0,    64,    39,    41,    66,     3,    52,    43,    38,
      46,     3,     4,     3,   125,    39,   127,   128,    24,    25,
      93,    64,    67,    41,    53,    17,    87,    72,    93,    74,
      41,    93,     5,     6,    79,     3,    42,    82,    83,     7,
       8,     9,    87,    11,    12,    13,    14,    15,   159,    41,
      93,   112,   113,   164,   165,   166,   129,     3,    93,   170,
     105,    24,    25,   106,   129,   126,     4,   129,     5,     6,
       6,   106,    37,    38,    40,    43,    44,   122,     3,    42,
      24,    25,   125,    42,   127,   128,   129,    38,     3,     4,
     125,   152,   127,   128,   129,   157,    33,   142,    42,     2,
      42,     3,    17,     6,     7,     7,     8,     9,   153,    11,
      12,    13,    14,    15,   157,    43,   159,    32,    37,    41,
      41,   164,   165,   166,   159,    41,    41,   170,     3,   164,
     165,   166,     7,     8,     9,   170,    11,    12,    13,    14,
      15,    43,    44,     3,     4,    41,    24,    25,    16,    17,
      18,    19,    20,    21,    22,    23,     4,    17,    26,    27,
      28,    29,    30,    31,    42,    24,    25,    37,    43,    10,
      11,    45,    13,    37,    42,    41,    37,    37,    37,     3,
      45,    41,    16,    17,    18,    19,    20,    21,    22,    23,
      16,    17,    18,    19,    20,    21,    22,    23,    16,    17,
      18,    19,    20,    21,    22,    23,     3,    39,    42,    37,
       7,     8,     9,    42,    11,    38,    42,    14,    15,    41,
      41,    41,    37,    37,    42,    16,    17,    18,    19,    20,
      21,    22,    23,    16,    17,    18,    19,    20,    21,    22,
      23,    10,    24,    25,    42,    10,    21,     7,    24,    40,
      36,    78,    92,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      42,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      -1,    26,    27,    28,    29,    30,    31,    16,    17,    18,
      19,    20,    21,    22,    23,    18,    19,    20,    21,    22,
      23
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    48,    49,     0,     5,     6,    33,    50,    51,    55,
      56,    56,    55,    56,     3,    52,    53,    54,     3,    54,
      37,    38,    39,    41,    41,     3,    53,     4,     6,    57,
      58,    59,    57,    40,     3,    42,    38,    42,    43,    59,
      37,    49,    56,    60,     3,     7,     8,     9,    11,    12,
      13,    14,    15,    43,    44,    54,    61,    62,    66,    67,
      68,    69,    70,    71,    41,    41,    41,    41,     4,    45,
      37,     4,    17,    37,    41,    70,    71,    72,    49,    41,
      37,    37,    39,    46,     3,    68,    32,    41,    72,    75,
      75,    72,    45,    63,    72,    72,    16,    17,    18,    19,
      20,    21,    22,    23,    37,    76,    60,    72,    73,    74,
      72,    72,    37,    41,    72,    75,    26,    27,    28,    29,
      30,    31,    78,    24,    25,    42,    77,    42,    42,    63,
       9,    11,    62,    64,    65,    67,    68,    70,    42,    72,
      44,    42,    38,    40,    75,    75,    42,    72,    61,    75,
      61,    61,    41,    41,    37,    37,    72,    37,    42,    10,
      75,    72,    68,    61,    42,    42,    42,    61,    61,    61,
      10,    61
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    51,    52,    52,
      53,    53,    54,    55,    55,    56,    56,    57,    57,    58,
      58,    59,    60,    60,    61,    61,    61,    61,    61,    61,
      62,    62,    63,    63,    64,    64,    64,    64,    64,    65,
      65,    65,    66,    66,    66,    66,    66,    67,    67,    67,
      68,    69,    70,    71,    71,    72,    72,    72,    72,    72,
      72,    73,    73,    74,    74,    75,    75,    75,    75,    76,
      76,    76,    76,    76,    76,    76,    76,    77,    77,    78,
      78,    78,    78,    78,    78
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     2,     1,     3,     3,     1,
       1,     4,     1,     9,     7,     1,     1,     1,     0,     3,
       1,     2,     2,     0,     1,     1,     1,     2,     1,     2,
       9,     5,     2,     0,     1,     1,     1,     2,     2,     5,
       7,     5,     5,     7,     5,     4,     3,     2,     2,     3,
       3,     4,     4,     1,     4,     3,     3,     2,     1,     1,
       1,     1,     0,     3,     1,     4,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
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
  case 2: /* programme: liste_declarations liste_fonctions  */
#line 35 "./src/miniC.y"
                                                                                        {
																t_tree	*end =  create_parent_tree(NULL, (yyvsp[0].tree), ROOT_NODE, NULL);
																t_symbol_table *table = global_symbol_table;
																// Si on a pas de table globale, on en crée une
																// Peut ne pas exister si pas de extern
																if (!table)
																	table = create_symbol_table(SYMBOL_TYPE_GLOBAL);
																((t_node*)end->content)->table = table;
																symbol_list_declaration_rec((yyvsp[-1].tree), table);
																symbol_list_fonction_rec((yyvsp[0].tree), table);
																// print_tree(end, 0);
																ast = end;
																(yyval.tree) = end;
															}
#line 1382 "miniC.tab.c"
    break;

  case 3: /* liste_declarations: liste_declarations declaration  */
#line 52 "./src/miniC.y"
                                                                                        {	(yyval.tree) = create_parent_tree((yyvsp[-1].tree), (yyvsp[0].tree), LIST_DECLARATION_NODE, NULL);	}
#line 1388 "miniC.tab.c"
    break;

  case 4: /* liste_declarations: %empty  */
#line 53 "./src/miniC.y"
                                                                                                                        {	(yyval.tree) = (t_tree*)0;												}
#line 1394 "miniC.tab.c"
    break;

  case 5: /* liste_fonctions: liste_fonctions fonction  */
#line 57 "./src/miniC.y"
                                                                                                {
																if ((yyvsp[-1].tree) && (yyvsp[0].tree))
																	(yyval.tree) = create_parent_tree((yyvsp[-1].tree), (yyvsp[0].tree), LIST_FUNCTION_NODE, NULL);
																else if ((yyvsp[-1].tree))
																	(yyval.tree) = (yyvsp[-1].tree);
																else if ((yyvsp[0].tree))
																	(yyval.tree) = (yyvsp[0].tree);
															}
#line 1407 "miniC.tab.c"
    break;

  case 6: /* liste_fonctions: fonction  */
#line 65 "./src/miniC.y"
                                                                                                                {	(yyval.tree) = (yyvsp[0].tree);	}
#line 1413 "miniC.tab.c"
    break;

  case 7: /* declaration: type liste_declarateurs ';'  */
#line 69 "./src/miniC.y"
                                                                                                {	(yyval.tree) = (yyvsp[-1].tree);	}
#line 1419 "miniC.tab.c"
    break;

  case 8: /* liste_declarateurs: liste_declarateurs ',' declarateur  */
#line 73 "./src/miniC.y"
                                                                                        {	(yyval.tree) = create_parent_tree((yyvsp[-2].tree), (yyvsp[0].tree), LIST_DECLARATION_NODE, NULL);	}
#line 1425 "miniC.tab.c"
    break;

  case 9: /* liste_declarateurs: declarateur  */
#line 74 "./src/miniC.y"
                                                                                                                {	(yyval.tree) = (yyvsp[0].tree);														}
#line 1431 "miniC.tab.c"
    break;

  case 10: /* declarateur: IDENTIFICATEUR  */
#line 78 "./src/miniC.y"
                                                                                                        {
																t_declaration* dec = malloc(sizeof(t_declaration));
																dec->type = TYPE_INT;
																dec->name = yylval.id;
																(yyval.tree) = create_parent_tree(NULL, NULL, VAR_DECLARATEUR_NODE, dec);
															
															}
#line 1443 "miniC.tab.c"
    break;

  case 11: /* declarateur: declarateur '[' CONSTANTE ']'  */
#line 85 "./src/miniC.y"
                                                                                        {	
																int	*constante = malloc(sizeof(int));
																*constante = yylval.inttype;
																t_tree	*sub = (yyvsp[-3].tree);
																//IF PREVIOUS STEP WAS AN IDENTIFICATOR
																if (((t_declaration*)((t_node*)sub->content)->datas)->type == TYPE_INT)
																{
																	t_declaration	*dec = malloc(sizeof(t_declaration));
																	dec->name = ((t_declaration*)((t_node*)sub->content)->datas)->name;
																	dec->type = TYPE_TAB_INT;
																	(yyval.tree) = create_parent_tree(create_parent_tree(NULL, NULL, VAR_NODE, dec),create_parent_tree(create_parent_tree(NULL, NULL, CONST_NODE, constante), NULL, TAB_INT_DATA_NODE, NULL), VAR_DECLARATEUR_NODE, dec);
																}
																else if (((t_declaration*)((t_node*)sub->content)->datas)->type == TYPE_TAB_INT)
																{
																	t_tree	*inter = sub;
																	while (inter->f_b)
																		inter = inter->f_b;
																	inter->f_b = create_parent_tree(create_parent_tree(NULL, NULL, CONST_NODE, constante), NULL, TAB_INT_DATA_NODE, NULL);
																	(yyval.tree) = sub;
																}
															}
#line 1469 "miniC.tab.c"
    break;

  case 12: /* name: IDENTIFICATEUR  */
#line 109 "./src/miniC.y"
                                                                                                        {	(yyval.id) = yylval.id;		}
#line 1475 "miniC.tab.c"
    break;

  case 13: /* fonction: type name '(' function_param ')' '{' liste_declarations liste_instructions '}'  */
#line 114 "./src/miniC.y"
                                                                                                                        {
																t_declaration *func = malloc(sizeof(t_declaration));
																func->name = (yyvsp[-7].id);
																func->type = (yyvsp[-8].inttype);
																func->cst = get_number_args_decl((yyvsp[-5].tree));
																t_tree *res = (yyvsp[-1].tree);
																((t_node*)res->content)->datas = func;
																((t_node*)res->content)->type = FUNCTION_NODE;
																t_symbol_table	*table_function = ((t_node*)res->content)->table;
																if (!table_function)
																{
																	table_function = create_symbol_table(SYMBOL_TYPE_FUNCTION);
																}
																symbol_list_declaration_rec((yyvsp[-2].tree), table_function);
																symbol_list_param_rec((yyvsp[-5].tree), table_function);
																((t_node*)res->content)->table = table_function;
																(yyval.tree) = res;
															}
#line 1498 "miniC.tab.c"
    break;

  case 14: /* fonction: EXTERN type name '(' function_param ')' ';'  */
#line 132 "./src/miniC.y"
                                                                        {
																// Si on a pas de table globale, on en crée une
																// n'existe pas si premier extern
																if (!global_symbol_table)
																	global_symbol_table = create_symbol_table(SYMBOL_TYPE_GLOBAL);
																t_symbol_table_elem *new_elem = create_symbol_table_element((yyvsp[-4].id), (yyvsp[-5].inttype), TYPE_FUNCTION, get_number_args_decl((yyvsp[-2].tree)), 0);
																add_element_in_symbol_table(global_symbol_table, new_elem);
																(yyval.tree) = (t_tree*)0;
															}
#line 1512 "miniC.tab.c"
    break;

  case 15: /* type: VOID  */
#line 144 "./src/miniC.y"
                                                                                                                {	(yyval.inttype) = TYPE_VOID;		}
#line 1518 "miniC.tab.c"
    break;

  case 16: /* type: INT  */
#line 145 "./src/miniC.y"
                                                                                                                        {	(yyval.inttype) = TYPE_INT;		}
#line 1524 "miniC.tab.c"
    break;

  case 17: /* function_param: liste_parms  */
#line 149 "./src/miniC.y"
                                                                                                                {	(yyval.tree) = (yyvsp[0].tree);			}
#line 1530 "miniC.tab.c"
    break;

  case 18: /* function_param: %empty  */
#line 150 "./src/miniC.y"
                                                                                                                {	(yyval.tree) = (t_tree*)0;	}
#line 1536 "miniC.tab.c"
    break;

  case 19: /* liste_parms: liste_parms ',' parm  */
#line 154 "./src/miniC.y"
                                                                                                {	(yyval.tree) = create_parent_tree((yyvsp[-2].tree), (yyvsp[0].tree), LIST_PARAM_NODE, NULL);	}
#line 1542 "miniC.tab.c"
    break;

  case 20: /* liste_parms: parm  */
#line 155 "./src/miniC.y"
                                                                                                                {	(yyval.tree) = (yyvsp[0].tree);												}
#line 1548 "miniC.tab.c"
    break;

  case 21: /* parm: INT IDENTIFICATEUR  */
#line 159 "./src/miniC.y"
                                                                                                        { 
																t_declaration *arg = malloc(sizeof(t_declaration));
																arg->name = yylval.id;
																arg->type = TYPE_INT;
																(yyval.tree) = create_parent_tree(NULL, NULL, ARG_NODE, arg);
															}
#line 1559 "miniC.tab.c"
    break;

  case 22: /* liste_instructions: liste_instructions instruction  */
#line 168 "./src/miniC.y"
                                                                                        {	(yyval.tree) = create_parent_tree((yyvsp[-1].tree), (yyvsp[0].tree), LIST_INSTRUCTION_NODE, NULL);	}
#line 1565 "miniC.tab.c"
    break;

  case 23: /* liste_instructions: %empty  */
#line 169 "./src/miniC.y"
                                                                                                                        {	(yyval.tree) = (t_tree*)0;												}
#line 1571 "miniC.tab.c"
    break;

  case 24: /* instruction: iteration  */
#line 173 "./src/miniC.y"
                                                                                                                {	(yyval.tree) = (yyvsp[0].tree);	}
#line 1577 "miniC.tab.c"
    break;

  case 25: /* instruction: selection  */
#line 174 "./src/miniC.y"
                                                                                                                {	(yyval.tree) = (yyvsp[0].tree);	}
#line 1583 "miniC.tab.c"
    break;

  case 26: /* instruction: saut  */
#line 175 "./src/miniC.y"
                                                                                                                {	(yyval.tree) = (yyvsp[0].tree);	}
#line 1589 "miniC.tab.c"
    break;

  case 27: /* instruction: affectation ';'  */
#line 176 "./src/miniC.y"
                                                                                                        {	(yyval.tree) = (yyvsp[-1].tree);	}
#line 1595 "miniC.tab.c"
    break;

  case 28: /* instruction: bloc  */
#line 177 "./src/miniC.y"
                                                                                                                {	(yyval.tree) = (yyvsp[0].tree);	}
#line 1601 "miniC.tab.c"
    break;

  case 29: /* instruction: appel ';'  */
#line 178 "./src/miniC.y"
                                                                                                                {	(yyval.tree) = (yyvsp[-1].tree);	}
#line 1607 "miniC.tab.c"
    break;

  case 30: /* iteration: FOR '(' affectation ';' condition ';' affectation ')' instruction  */
#line 183 "./src/miniC.y"
                                                                                                                        {	(yyval.tree) = create_parent_tree(create_parent_tree(create_parent_tree((yyvsp[-6].tree), (yyvsp[-4].tree), FOR_DATA_NODE, NULL), (yyvsp[-2].tree), FOR_DATA_NODE, NULL), (yyvsp[0].tree), FOR_NODE, NULL);	}
#line 1613 "miniC.tab.c"
    break;

  case 31: /* iteration: WHILE '(' condition ')' instruction  */
#line 184 "./src/miniC.y"
                                                                                {	(yyval.tree) = create_parent_tree((yyvsp[-2].tree), (yyvsp[0].tree), WHILE_NODE, NULL);				}
#line 1619 "miniC.tab.c"
    break;

  case 32: /* case_liste_instructions: case_liste_instructions case_instruction  */
#line 188 "./src/miniC.y"
                                                                                {	(yyval.tree) = create_parent_tree((yyvsp[-1].tree), (yyvsp[0].tree), LIST_INSTRUCTION_NODE, NULL);	}
#line 1625 "miniC.tab.c"
    break;

  case 33: /* case_liste_instructions: %empty  */
#line 189 "./src/miniC.y"
                                                                                                                        {	(yyval.tree) = (t_tree*)0;												}
#line 1631 "miniC.tab.c"
    break;

  case 34: /* case_instruction: iteration  */
#line 193 "./src/miniC.y"
                                                                                                                {	(yyval.tree) = (yyvsp[0].tree);	}
#line 1637 "miniC.tab.c"
    break;

  case 35: /* case_instruction: case_selection  */
#line 194 "./src/miniC.y"
                                                                                                        {	(yyval.tree) = (yyvsp[0].tree);	}
#line 1643 "miniC.tab.c"
    break;

  case 36: /* case_instruction: saut  */
#line 195 "./src/miniC.y"
                                                                                                                {	(yyval.tree) = (yyvsp[0].tree);	}
#line 1649 "miniC.tab.c"
    break;

  case 37: /* case_instruction: affectation ';'  */
#line 196 "./src/miniC.y"
                                                                                                        {	(yyval.tree) = (yyvsp[-1].tree);	}
#line 1655 "miniC.tab.c"
    break;

  case 38: /* case_instruction: appel ';'  */
#line 197 "./src/miniC.y"
                                                                                                                {	(yyval.tree) = (yyvsp[-1].tree);	}
#line 1661 "miniC.tab.c"
    break;

  case 39: /* case_selection: IF '(' condition ')' instruction  */
#line 201 "./src/miniC.y"
                                                                                { 	(yyval.tree) = create_parent_tree((yyvsp[-2].tree), (yyvsp[0].tree), IF_NODE, NULL);			}
#line 1667 "miniC.tab.c"
    break;

  case 40: /* case_selection: IF '(' condition ')' instruction ELSE instruction  */
#line 202 "./src/miniC.y"
                                                                        { 	(yyval.tree) = create_parent_tree(create_parent_tree((yyvsp[-4].tree),(yyvsp[-2].tree),IF_DATA_NODE, NULL),create_parent_tree((yyvsp[0].tree), NULL, ELSE_NODE, NULL),IF_NODE,NULL); }
#line 1673 "miniC.tab.c"
    break;

  case 41: /* case_selection: SWITCH '(' expression ')' instruction  */
#line 203 "./src/miniC.y"
                                                                                { 	(yyval.tree) = create_parent_tree((yyvsp[-2].tree), (yyvsp[0].tree), SWITCH_NODE, NULL);		}
#line 1679 "miniC.tab.c"
    break;

  case 42: /* selection: IF '(' condition ')' instruction  */
#line 207 "./src/miniC.y"
                                                                                { 	(yyval.tree) = create_parent_tree((yyvsp[-2].tree), (yyvsp[0].tree), IF_NODE, NULL);			}
#line 1685 "miniC.tab.c"
    break;

  case 43: /* selection: IF '(' condition ')' instruction ELSE instruction  */
#line 208 "./src/miniC.y"
                                                                        { 	(yyval.tree) = create_parent_tree(create_parent_tree((yyvsp[-4].tree),(yyvsp[-2].tree),IF_DATA_NODE, NULL),create_parent_tree((yyvsp[0].tree), NULL, ELSE_NODE, NULL),IF_NODE,NULL); }
#line 1691 "miniC.tab.c"
    break;

  case 44: /* selection: SWITCH '(' expression ')' instruction  */
#line 209 "./src/miniC.y"
                                                                                { 	(yyval.tree) = create_parent_tree((yyvsp[-2].tree), (yyvsp[0].tree), SWITCH_NODE, NULL);		}
#line 1697 "miniC.tab.c"
    break;

  case 45: /* selection: CASE CONSTANTE ':' case_liste_instructions  */
#line 210 "./src/miniC.y"
                                                                                { 
																int	*constante = malloc(sizeof(int));
																*constante = yylval.inttype;
																(yyval.tree) = create_parent_tree(create_parent_tree(NULL, NULL, CONST_NODE, constante), (yyvsp[0].tree), CASE_NODE, constante);
															}
#line 1707 "miniC.tab.c"
    break;

  case 46: /* selection: DEFAULT ':' case_liste_instructions  */
#line 215 "./src/miniC.y"
                                                                                        {	(yyval.tree) = create_parent_tree(NULL, (yyvsp[0].tree), DEFAULT_NODE, NULL);	}
#line 1713 "miniC.tab.c"
    break;

  case 47: /* saut: BREAK ';'  */
#line 219 "./src/miniC.y"
                                                                                                                {	(yyval.tree) = create_parent_tree(NULL, NULL, BREAK_NODE, NULL);	}
#line 1719 "miniC.tab.c"
    break;

  case 48: /* saut: RETURN ';'  */
#line 220 "./src/miniC.y"
                                                                                                                {	(yyval.tree) = create_parent_tree(NULL, NULL, RETURN_NODE, NULL);	}
#line 1725 "miniC.tab.c"
    break;

  case 49: /* saut: RETURN expression ';'  */
#line 221 "./src/miniC.y"
                                                                                                {	(yyval.tree) = create_parent_tree(NULL, (yyvsp[-1].tree), RETURN_NODE, NULL);	}
#line 1731 "miniC.tab.c"
    break;

  case 50: /* affectation: variable '=' expression  */
#line 225 "./src/miniC.y"
                                                                                                {	(yyval.tree) = create_parent_tree((yyvsp[-2].tree), (yyvsp[0].tree), ASSIGN_NODE, NULL);		}
#line 1737 "miniC.tab.c"
    break;

  case 51: /* bloc: '{' liste_declarations liste_instructions '}'  */
#line 229 "./src/miniC.y"
                                                                        { 
																t_tree	*res = (yyvsp[-1].tree);
																((t_node*)res->content)->type = BLOCK_NODE;
																t_symbol_table	*table = create_symbol_table(SYMBOL_TYPE_LOCAL);
																((t_node*)res->content)->table = table;
																symbol_list_declaration_rec((yyvsp[-2].tree), table);
																(yyval.tree) = (yyvsp[-1].tree);
															}
#line 1750 "miniC.tab.c"
    break;

  case 52: /* appel: name '(' parm_call_function_list_expression ')'  */
#line 240 "./src/miniC.y"
                                                                        {
																t_declaration	*dec = malloc(sizeof(t_declaration));
																dec->name = (yyvsp[-3].id);
																(yyval.tree) = create_parent_tree(NULL, (yyvsp[-1].tree), CALL_NODE, dec);
															}
#line 1760 "miniC.tab.c"
    break;

  case 53: /* variable: IDENTIFICATEUR  */
#line 248 "./src/miniC.y"
                                                                                                        {
																t_declaration	*dec = malloc(sizeof(t_declaration));
																dec->name = yylval.id;
																dec->type = TYPE_INT;
																(yyval.tree) = create_parent_tree(NULL, NULL, VAR_NODE, dec);	
															}
#line 1771 "miniC.tab.c"
    break;

  case 54: /* variable: variable '[' expression ']'  */
#line 254 "./src/miniC.y"
                                                                                                {	
																t_tree	*sub = (yyvsp[-3].tree);
																//IF PREVIOUS STEP WAS AN IDENTIFICATOR
																if (((t_declaration*)((t_node*)sub->content)->datas)->type == TYPE_INT)
																{
																	t_declaration	*dec = malloc(sizeof(t_declaration));
																	dec->name = ((t_declaration*)((t_node*)sub->content)->datas)->name;
																	dec->type = TYPE_TAB_INT;
																	t_declaration	*dec_id = malloc(sizeof(t_declaration));
																	dec->name = ((t_declaration*)((t_node*)sub->content)->datas)->name;
																	dec->type = TYPE_INT; // FAKE
																	(yyval.tree) = create_parent_tree(create_parent_tree(NULL, NULL, VAR_NODE, dec_id), (yyvsp[-1].tree), VAR_NODE, dec);		
																}
																else if (((t_declaration*)((t_node *)sub->content)->datas)->type == TYPE_TAB_INT)
																{
																	t_tree	*inter = sub;
																	while (inter->f_b)
																		inter = inter->f_b;
																	inter->f_b = create_parent_tree((yyvsp[-1].tree), NULL, TAB_INT_DATA_NODE, NULL);
																	(yyval.tree) = sub;
																}
															}
#line 1798 "miniC.tab.c"
    break;

  case 55: /* expression: '(' expression ')'  */
#line 279 "./src/miniC.y"
                                                                                                        {	(yyval.tree) = (yyvsp[-1].tree);														}
#line 1804 "miniC.tab.c"
    break;

  case 56: /* expression: expression binary_op expression  */
#line 280 "./src/miniC.y"
                                                                                { 
																t_tree *node1 = (yyvsp[-2].tree);
																int type = (yyvsp[-1].inttype);
																t_tree *node3 = (yyvsp[0].tree);
																(yyval.tree) = create_parent_tree(node1, node3, type, NULL);
															}
#line 1815 "miniC.tab.c"
    break;

  case 57: /* expression: MOINS expression  */
#line 286 "./src/miniC.y"
                                                                                                        {	(yyval.tree) = create_parent_tree(NULL, (yyvsp[0].tree), MINUS_NODE, NULL);			}
#line 1821 "miniC.tab.c"
    break;

  case 58: /* expression: CONSTANTE  */
#line 287 "./src/miniC.y"
                                                                                                                {
																int *constante = malloc(sizeof(int));
																*constante = yylval.inttype;
																(yyval.tree) = create_parent_tree(NULL, NULL, CONST_NODE, constante);
															}
#line 1831 "miniC.tab.c"
    break;

  case 59: /* expression: variable  */
#line 292 "./src/miniC.y"
                                                                                                                {	(yyval.tree) = (yyvsp[0].tree); 														}
#line 1837 "miniC.tab.c"
    break;

  case 60: /* expression: appel  */
#line 293 "./src/miniC.y"
                                                                                                                {	(yyval.tree) = (yyvsp[0].tree);														}
#line 1843 "miniC.tab.c"
    break;

  case 61: /* parm_call_function_list_expression: liste_expressions  */
#line 297 "./src/miniC.y"
                                                                                                        {	(yyval.tree) = (yyvsp[0].tree);			}
#line 1849 "miniC.tab.c"
    break;

  case 62: /* parm_call_function_list_expression: %empty  */
#line 298 "./src/miniC.y"
                                                                                                                        {	(yyval.tree) = (t_tree*)0;	}
#line 1855 "miniC.tab.c"
    break;

  case 63: /* liste_expressions: liste_expressions ',' expression  */
#line 302 "./src/miniC.y"
                                                                                        {	(yyval.tree) = create_parent_tree((yyvsp[0].tree), (yyvsp[-2].tree), LIST_EXPRESSION_NODE, NULL);	}
#line 1861 "miniC.tab.c"
    break;

  case 64: /* liste_expressions: expression  */
#line 303 "./src/miniC.y"
                                                                                                                {	(yyval.tree) = (yyvsp[0].tree);														}
#line 1867 "miniC.tab.c"
    break;

  case 65: /* condition: NOT '(' condition ')'  */
#line 307 "./src/miniC.y"
                                                                                                {	(yyval.tree) = create_parent_tree(NULL, (yyvsp[-1].tree), NOT_NODE, NULL);	}
#line 1873 "miniC.tab.c"
    break;

  case 66: /* condition: condition binary_rel condition  */
#line 308 "./src/miniC.y"
                                                                                {	(yyval.tree) = create_parent_tree((yyvsp[-2].tree), (yyvsp[0].tree), (yyvsp[-1].inttype), NULL);			}
#line 1879 "miniC.tab.c"
    break;

  case 67: /* condition: '(' condition ')'  */
#line 309 "./src/miniC.y"
                                                                                                        {	(yyval.tree) = (yyvsp[-1].tree); 											}
#line 1885 "miniC.tab.c"
    break;

  case 68: /* condition: expression binary_comp expression  */
#line 310 "./src/miniC.y"
                                                                                        {	(yyval.tree) = create_parent_tree((yyvsp[-2].tree), (yyvsp[0].tree), (yyvsp[-1].inttype), NULL);			}
#line 1891 "miniC.tab.c"
    break;

  case 69: /* binary_op: PLUS  */
#line 314 "./src/miniC.y"
                                                                                                                {	(yyval.inttype) = ADD_NODE;		}
#line 1897 "miniC.tab.c"
    break;

  case 70: /* binary_op: MOINS  */
#line 315 "./src/miniC.y"
                                                                                                                {	(yyval.inttype) = MINUS_NODE;	}
#line 1903 "miniC.tab.c"
    break;

  case 71: /* binary_op: MUL  */
#line 316 "./src/miniC.y"
                                                                                                                        {	(yyval.inttype) = MULT_NODE;		}
#line 1909 "miniC.tab.c"
    break;

  case 72: /* binary_op: DIV  */
#line 317 "./src/miniC.y"
                                                                                                                        {	(yyval.inttype) = DIV_NODE;		}
#line 1915 "miniC.tab.c"
    break;

  case 73: /* binary_op: LSHIFT  */
#line 318 "./src/miniC.y"
                                                                                                                {	(yyval.inttype) = LSHIFT_NODE;	}
#line 1921 "miniC.tab.c"
    break;

  case 74: /* binary_op: RSHIFT  */
#line 319 "./src/miniC.y"
                                                                                                                {	(yyval.inttype) = RSHIFT_NODE;	}
#line 1927 "miniC.tab.c"
    break;

  case 75: /* binary_op: BAND  */
#line 320 "./src/miniC.y"
                                                                                                                {	(yyval.inttype) = BAND_NODE;		}
#line 1933 "miniC.tab.c"
    break;

  case 76: /* binary_op: BOR  */
#line 321 "./src/miniC.y"
                                                                                                                        {	(yyval.inttype) = BOR_NODE;		}
#line 1939 "miniC.tab.c"
    break;

  case 77: /* binary_rel: LAND  */
#line 325 "./src/miniC.y"
                                                                                                                {	(yyval.inttype) = BOOL_AND_NODE;	}
#line 1945 "miniC.tab.c"
    break;

  case 78: /* binary_rel: LOR  */
#line 326 "./src/miniC.y"
                                                                                                                        {	(yyval.inttype) = BOOL_OR_NODE; 	}
#line 1951 "miniC.tab.c"
    break;

  case 79: /* binary_comp: LT  */
#line 330 "./src/miniC.y"
                                                                                                                        {	(yyval.inttype) = BOOL_L_NODE;	}
#line 1957 "miniC.tab.c"
    break;

  case 80: /* binary_comp: GT  */
#line 331 "./src/miniC.y"
                                                                                                                        {	(yyval.inttype) = BOOL_G_NODE;	}
#line 1963 "miniC.tab.c"
    break;

  case 81: /* binary_comp: GEQ  */
#line 332 "./src/miniC.y"
                                                                                                                        {	(yyval.inttype) = BOOL_GE_NODE;	}
#line 1969 "miniC.tab.c"
    break;

  case 82: /* binary_comp: LEQ  */
#line 333 "./src/miniC.y"
                                                                                                                        {	(yyval.inttype) = BOOL_LE_NODE;	}
#line 1975 "miniC.tab.c"
    break;

  case 83: /* binary_comp: EQ  */
#line 334 "./src/miniC.y"
                                                                                                                        {	(yyval.inttype) = BOOL_EQ_NODE;	}
#line 1981 "miniC.tab.c"
    break;

  case 84: /* binary_comp: NEQ  */
#line 335 "./src/miniC.y"
                                                                                                                {	(yyval.inttype) = BOOL_NEQ_NODE;	}
#line 1987 "miniC.tab.c"
    break;


#line 1991 "miniC.tab.c"

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

#line 338 "./src/miniC.y"


#include "lex.yy.c"

void yyerror(char *s)
{
	printf("erreur : %s, ligne %d\n", s, yylineno);
	exit (1);
}

int main(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		char	buffer[4096] = {0};
  	    
		yyin = fopen(argv[i], "r");
		if (yyin == NULL)
		{
			fprintf(stderr, "compiler: impossible d'ouvrir le fichier %s\n", argv[i]);
			continue ; 
		}
		// Create the declaration file
		sprintf(buffer, "./%s_decla.dot", argv[i]);
		fileResult_decla = fopen(buffer, "w+");

		// Create the link file
		sprintf(buffer, "./%s_link.dot", argv[i]);
		fileResult_link = fopen(buffer, "w+");

		// Create the final file
		sprintf(buffer, "./%s.dot", argv[i]);
		fileResult = fopen(buffer, "w+");
		#ifdef YYDEBUG
			fprintf(stdout, "\n#compiler: compilation du fichier %s\n", argv[i]);
		#endif
		yyparse();
		fprintf(fileResult, "digraph mon_programme {\n");
		fflush(fileResult);
		conver_and_sementic_analys(ast);

		int bytesRead;
		fseek(fileResult_decla, 0, SEEK_SET);
		while ((bytesRead = fread(buffer, 1, 4096, fileResult_decla)) > 0)
			fwrite(buffer, 1, bytesRead, fileResult);
		fseek(fileResult_link, 0, SEEK_SET);
		while ((bytesRead = fread(buffer, 1, 4096, fileResult_link)) > 0)
			fwrite(buffer, 1, bytesRead, fileResult);
		ast = NULL;
		global_symbol_table = NULL;
		fprintf(fileResult, "\n}");
		fclose(fileResult);
		fclose(fileResult_decla);
		sprintf(buffer, "./%s_decla.dot", argv[i]);
		remove(buffer);
		fclose(fileResult_link);
		sprintf(buffer, "./%s_link.dot", argv[i]);
		remove(buffer);
		fclose(yyin);
	}
	return 0;
}
