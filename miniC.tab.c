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
	#define YYDEBUG 1
	#define YYSTYPE int

#line 78 "miniC.tab.c"

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
#line 8 "./src/miniC.y"

	int 	type;
	int		constante;
	char	*id:
	t_tree	*tree;

#line 168 "miniC.tab.c"

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
  YYSYMBOL_fonction = 54,                  /* fonction  */
  YYSYMBOL_type = 55,                      /* type  */
  YYSYMBOL_liste_parms = 56,               /* liste_parms  */
  YYSYMBOL_parm = 57,                      /* parm  */
  YYSYMBOL_liste_instructions = 58,        /* liste_instructions  */
  YYSYMBOL_instruction = 59,               /* instruction  */
  YYSYMBOL_iteration = 60,                 /* iteration  */
  YYSYMBOL_selection = 61,                 /* selection  */
  YYSYMBOL_saut = 62,                      /* saut  */
  YYSYMBOL_affectation = 63,               /* affectation  */
  YYSYMBOL_bloc = 64,                      /* bloc  */
  YYSYMBOL_appel = 65,                     /* appel  */
  YYSYMBOL_variable = 66,                  /* variable  */
  YYSYMBOL_expression = 67,                /* expression  */
  YYSYMBOL_liste_expressions = 68,         /* liste_expressions  */
  YYSYMBOL_condition = 69,                 /* condition  */
  YYSYMBOL_binary_op = 70,                 /* binary_op  */
  YYSYMBOL_binary_rel = 71,                /* binary_rel  */
  YYSYMBOL_binary_comp = 72                /* binary_comp  */
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
#define YYLAST   239

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

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
static const yytype_uint8 yyrline[] =
{
       0,    31,    31,    34,    39,    42,    45,    50,    53,    58,
      61,    68,    76,    83,    91,    92,    95,    96,    99,   107,
     112,   115,   116,   117,   118,   119,   120,   123,   124,   127,
     128,   129,   130,   131,   134,   135,   136,   139,   142,   145,
     148,   155,   158,   159,   160,   161,   166,   167,   170,   171,
     174,   175,   176,   177,   180,   181,   182,   183,   184,   185,
     186,   187,   190,   191,   194,   195,   196,   197,   198,   199
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
  "liste_declarateurs", "declarateur", "fonction", "type", "liste_parms",
  "parm", "liste_instructions", "instruction", "iteration", "selection",
  "saut", "affectation", "bloc", "appel", "variable", "expression",
  "liste_expressions", "condition", "binary_op", "binary_rel",
  "binary_comp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-66)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -66,     2,    44,   -66,   -66,   -66,   108,    44,   -66,   -66,
       5,    10,   -66,    31,   -36,   105,   -66,    -4,    -1,    47,
     -66,   -66,    77,   -66,    38,     1,    48,   -66,    51,   -66,
     100,    65,    79,   166,   -66,   -66,   -66,   -66,   108,    77,
       3,   139,   148,   149,   153,   154,   155,   125,   160,    16,
     -66,   -66,   -66,   -66,   -66,   -66,   161,   -66,   -66,     6,
     -66,   188,    71,    71,    21,   151,    58,   -66,   172,   -66,
      21,   -66,    21,   163,   156,   108,   -66,    21,    21,    73,
     -66,   177,   190,    71,   189,    75,   157,   118,    58,   -66,
     -66,   135,   129,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,    21,    83,   145,   205,    21,   192,    71,    71,
     102,   159,   -66,   -66,   -66,   -66,   -66,   -66,    21,   -66,
     -66,    58,    71,    58,    58,   -66,   150,   -66,   -66,   -66,
     -66,   205,   -66,     7,   162,   -66,   205,   -66,   -66,   193,
     -66,   -66,   188,   -66,    58,   158,   -66,    58,   -66
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     1,    14,    15,     0,     2,     3,     6,
       0,     0,     5,     0,    10,     0,     9,     0,     0,     0,
      17,     7,     0,    17,     0,     0,    10,     8,     0,    11,
       0,     0,     0,     0,    16,     4,    13,    18,    20,     0,
       0,    40,     0,     0,     0,     0,     0,     0,     0,     0,
       4,    12,    19,    21,    22,    23,     0,    25,    26,     0,
      49,     0,     0,     0,     0,     0,     0,    34,    40,    45,
       0,    35,     0,    46,     0,    20,    24,     0,     0,     0,
      40,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      49,    44,     0,    54,    55,    56,    57,    58,    59,    60,
      61,    36,     0,     0,     0,    37,     0,     0,     0,     0,
       0,     0,    64,    65,    66,    67,    68,    69,     0,    62,
      63,     0,     0,     0,     0,    32,     0,    42,    43,    38,
      41,    48,    39,     0,     0,    52,    53,    28,    51,    29,
      31,    47,     0,    50,     0,     0,    30,     0,    27
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -66,   -66,    -8,   -66,   -66,   -66,   208,   225,   103,   210,
     -66,   164,   -65,   -66,   -66,   -66,   -57,   -66,   -66,   -40,
     -42,   144,   -54,   -66,   -66,   -66
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     7,     8,    15,    16,     9,    39,    25,
      34,    40,    52,    53,    54,    55,    56,    57,    58,    73,
      84,    79,    85,   102,   122,   118
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      59,    89,     3,    19,    81,    20,    41,    74,    14,    86,
      42,    43,    44,    17,    45,    46,    47,    48,    49,    68,
      69,    59,    87,   125,    68,    69,    59,    38,    91,   111,
      92,   119,   120,    70,    18,   104,   105,    23,    70,    30,
      20,   110,    75,    31,   142,    77,    50,    51,    59,     4,
       5,    24,    78,    71,   133,   134,   137,    72,   139,   140,
     128,    41,    72,    59,   131,    42,    43,    44,   138,    45,
      46,    47,    48,    49,    68,    69,   136,     6,    29,   146,
      26,    59,   148,    59,    59,   145,    41,    19,    70,    30,
      42,    43,    44,    32,    45,    46,    47,    48,    49,   119,
     120,    50,    59,    82,    59,    10,    33,    59,    35,    11,
      13,   106,    83,     4,     5,   107,    36,   121,    93,    94,
      95,    96,    97,    98,    99,   100,    50,   129,   112,   113,
     114,   115,   116,   117,    93,    94,    95,    96,    97,    98,
      99,   100,    21,    22,   127,    93,    94,    95,    96,    97,
      98,    99,   100,    95,    96,    97,    98,    99,   100,    65,
     124,    93,    94,    95,    96,    97,    98,    99,   100,    37,
      66,   127,    93,    94,    95,    96,    97,    98,    99,   100,
      60,   119,   120,   119,   120,   130,   119,   120,   106,    61,
      62,    80,   141,   101,    63,    64,    88,    67,    76,   123,
     147,   135,    77,   144,   143,    93,    94,    95,    96,    97,
      98,    99,   100,    90,   108,   112,   113,   114,   115,   116,
     117,    93,    94,    95,    96,    97,    98,    99,   100,   132,
      27,   109,    12,    28,   126,     0,     0,     0,     0,   103
};

static const yytype_int16 yycheck[] =
{
      40,    66,     0,    39,    61,    41,     3,    49,     3,    63,
       7,     8,     9,     3,    11,    12,    13,    14,    15,     3,
       4,    61,    64,    88,     3,     4,    66,    35,    70,    83,
      72,    24,    25,    17,     3,    77,    78,    41,    17,    38,
      41,    83,    50,    42,    37,    39,    43,    44,    88,     5,
       6,     4,    46,    37,   108,   109,   121,    41,   123,   124,
     102,     3,    41,   103,   106,     7,     8,     9,   122,    11,
      12,    13,    14,    15,     3,     4,   118,    33,    40,   144,
       3,   121,   147,   123,   124,   142,     3,    39,    17,    38,
       7,     8,     9,    42,    11,    12,    13,    14,    15,    24,
      25,    43,   142,    32,   144,     2,     6,   147,    43,     6,
       7,    38,    41,     5,     6,    42,    37,    42,    16,    17,
      18,    19,    20,    21,    22,    23,    43,    44,    26,    27,
      28,    29,    30,    31,    16,    17,    18,    19,    20,    21,
      22,    23,    37,    38,    42,    16,    17,    18,    19,    20,
      21,    22,    23,    18,    19,    20,    21,    22,    23,     4,
      42,    16,    17,    18,    19,    20,    21,    22,    23,     3,
      45,    42,    16,    17,    18,    19,    20,    21,    22,    23,
      41,    24,    25,    24,    25,    40,    24,    25,    38,    41,
      41,     3,    42,    37,    41,    41,    45,    37,    37,    42,
      42,    42,    39,    10,    42,    16,    17,    18,    19,    20,
      21,    22,    23,    41,    37,    26,    27,    28,    29,    30,
      31,    16,    17,    18,    19,    20,    21,    22,    23,    37,
      22,    41,     7,    23,    90,    -1,    -1,    -1,    -1,    75
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    48,    49,     0,     5,     6,    33,    50,    51,    54,
      55,    55,    54,    55,     3,    52,    53,     3,     3,    39,
      41,    37,    38,    41,     4,    56,     3,    53,    56,    40,
      38,    42,    42,     6,    57,    43,    37,     3,    49,    55,
      58,     3,     7,     8,     9,    11,    12,    13,    14,    15,
      43,    44,    59,    60,    61,    62,    63,    64,    65,    66,
      41,    41,    41,    41,    41,     4,    45,    37,     3,     4,
      17,    37,    41,    66,    67,    49,    37,    39,    46,    68,
       3,    63,    32,    41,    67,    69,    69,    67,    45,    59,
      41,    67,    67,    16,    17,    18,    19,    20,    21,    22,
      23,    37,    70,    58,    67,    67,    38,    42,    37,    41,
      67,    69,    26,    27,    28,    29,    30,    31,    72,    24,
      25,    42,    71,    42,    42,    59,    68,    42,    67,    44,
      40,    67,    37,    69,    69,    42,    67,    59,    69,    59,
      59,    42,    37,    42,    10,    63,    59,    42,    59
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    51,    52,    52,
      53,    53,    54,    54,    55,    55,    56,    56,    57,    58,
      58,    59,    59,    59,    59,    59,    59,    60,    60,    61,
      61,    61,    61,    61,    62,    62,    62,    63,    64,    65,
      66,    66,    67,    67,    67,    67,    67,    67,    68,    68,
      69,    69,    69,    69,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    71,    72,    72,    72,    72,    72,    72
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     2,     1,     3,     3,     1,
       1,     4,     9,     7,     1,     1,     3,     0,     2,     2,
       0,     1,     1,     1,     2,     1,     1,     9,     5,     5,
       7,     5,     4,     3,     2,     2,     3,     3,     4,     5,
       1,     4,     3,     3,     2,     1,     1,     4,     3,     0,
       4,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 31 "./src/miniC.y"
                                                   { (yyval.tree) = create_parent_tree((yyvsp[-1].tree), (yyvsp[0].tree), ROOT_NODE, NULL);}
#line 1329 "miniC.tab.c"
    break;

  case 3: /* liste_declarations: liste_declarations declaration  */
#line 34 "./src/miniC.y"
                                                   { 
												t_tree *node = (yyvsp[0].tree);
											 	node->f_a = (yyvsp[-1].tree);
											 	(yyval.tree) = node;
										   }
#line 1339 "miniC.tab.c"
    break;

  case 4: /* liste_declarations: %empty  */
#line 39 "./src/miniC.y"
                                                                                        {	return NULL;	}
#line 1345 "miniC.tab.c"
    break;

  case 5: /* liste_fonctions: liste_fonctions fonction  */
#line 42 "./src/miniC.y"
                                                                {
												create_parent_tree((yyvsp[-1].tree), (yyvsp[0].tree), LIST_FUNCTION_NODE, NULL);
											}
#line 1353 "miniC.tab.c"
    break;

  case 6: /* liste_fonctions: fonction  */
#line 45 "./src/miniC.y"
                                                                {
												(yyval.tree) = (yyvsp[0].tree);
											}
#line 1361 "miniC.tab.c"
    break;

  case 7: /* declaration: type liste_declarateurs ';'  */
#line 50 "./src/miniC.y"
                                                        {	(yyval.tree) = (yyvsp[-1].tree);	}
#line 1367 "miniC.tab.c"
    break;

  case 8: /* liste_declarateurs: liste_declarateurs ',' declarateur  */
#line 53 "./src/miniC.y"
                                                        {
												t_tree*	dec = (yyvsp[0].tree);
												dec->f_a = (yyvsp[-2].tree);
												(yyval.tree) = dec;
											}
#line 1377 "miniC.tab.c"
    break;

  case 9: /* liste_declarateurs: declarateur  */
#line 58 "./src/miniC.y"
                                                                                {	(yyval.tree) = (yyvsp[0].tree);	}
#line 1383 "miniC.tab.c"
    break;

  case 10: /* declarateur: IDENTIFICATEUR  */
#line 61 "./src/miniC.y"
                                                                                {
													t_declaration* dec = malloc(sizeof(t_declaration));
													dec->type = TYPE_INT;
													dec->name = yylval.id;
													(yyval.tree) = create_parent_tree(NULL, NULL, VAR_DECLARATION_NODE, dec);\
												
												}
#line 1395 "miniC.tab.c"
    break;

  case 11: /* declarateur: IDENTIFICATEUR '[' CONSTANTE ']'  */
#line 68 "./src/miniC.y"
                                                                {	
													t_declaration* dec = malloc(sizeof(t_declaration));
													dec->type = TYPE_TAB_INT;
													dec->name = yylval.id;
													(yyval.tree) = create_parent_tree(NULL, NULL, VAR_DECLARATION_NODE, dec);\
												}
#line 1406 "miniC.tab.c"
    break;

  case 12: /* fonction: type IDENTIFICATEUR '(' liste_parms ')' '{' liste_declarations liste_instructions '}'  */
#line 77 "./src/miniC.y"
                {
			t_declaration *func = malloc(sizeof(t_declaration));
			func->name = yylval.id;
			func->type_dec = (yyvsp[-8].type);
			(yyval.tree) = create_parent_tree((yyvsp[-5].tree), create_parent_tree((yyvsp[-2].tree), (yyvsp[-1].tree), BLOCK_FUN_NODE, NULL), FUNC_NODE, func);
		}
#line 1417 "miniC.tab.c"
    break;

  case 13: /* fonction: EXTERN type IDENTIFICATEUR '(' liste_parms ')' ';'  */
#line 83 "./src/miniC.y"
                                                                        {
																t_declaration	*fun = malloc(sizeof(t_declaration));
																fun->name = yylval.id;
																fun->type = (yyvsp[-5].type);
																create_parent_tree((yyvsp[-2].tree), NULL, EXTERN_FUNCTION_NODE, fun);
															}
#line 1428 "miniC.tab.c"
    break;

  case 14: /* type: VOID  */
#line 91 "./src/miniC.y"
                        { (yyval.type) = TYPE_VOID;}
#line 1434 "miniC.tab.c"
    break;

  case 15: /* type: INT  */
#line 92 "./src/miniC.y"
                                { (yyval.type) = TYPE_INT;}
#line 1440 "miniC.tab.c"
    break;

  case 16: /* liste_parms: liste_parms ',' parm  */
#line 95 "./src/miniC.y"
                                        {}
#line 1446 "miniC.tab.c"
    break;

  case 18: /* parm: INT IDENTIFICATEUR  */
#line 99 "./src/miniC.y"
                                                { 
									t_declaration *arg = malloc(sizeof(t_declaration));
									arg->name = yylval.id;
									arg->type = TYPE_INT;
									(yyval.tree) = create_parent_tree(NULL, NULL, ARG_NODE, arg);
								}
#line 1457 "miniC.tab.c"
    break;

  case 19: /* liste_instructions: liste_instructions instruction  */
#line 107 "./src/miniC.y"
                                                { 
											t_tree	*node = (yyvsp[0].tree);
											node->f_a = (yyvsp[-1].tree);
											(yyval.tree) = node;
										}
#line 1467 "miniC.tab.c"
    break;

  case 21: /* instruction: iteration  */
#line 115 "./src/miniC.y"
                                        { (yyval.tree) = create_parent_tree(NULL, (yyvsp[0].tree), INSTRUCTION_NODE, NULL);}
#line 1473 "miniC.tab.c"
    break;

  case 22: /* instruction: selection  */
#line 116 "./src/miniC.y"
                                        { (yyval.tree) = create_parent_tree(NULL, (yyvsp[0].tree), INSTRUCTION_NODE, NULL);}
#line 1479 "miniC.tab.c"
    break;

  case 23: /* instruction: saut  */
#line 117 "./src/miniC.y"
                                        { (yyval.tree) = create_parent_tree(NULL, (yyvsp[0].tree), INSTRUCTION_NODE, NULL);}
#line 1485 "miniC.tab.c"
    break;

  case 24: /* instruction: affectation ';'  */
#line 118 "./src/miniC.y"
                                { (yyval.tree) = create_parent_tree(NULL, (yyvsp[-1].tree), INSTRUCTION_NODE, NULL);}
#line 1491 "miniC.tab.c"
    break;

  case 25: /* instruction: bloc  */
#line 119 "./src/miniC.y"
                                        { (yyval.tree) = create_parent_tree(NULL, (yyvsp[0].tree), INSTRUCTION_NODE, NULL);}
#line 1497 "miniC.tab.c"
    break;

  case 26: /* instruction: appel  */
#line 120 "./src/miniC.y"
                                        { (yyval.tree) = create_parent_tree(NULL, (yyvsp[0].tree), INSTRUCTION_NODE, NULL);}
#line 1503 "miniC.tab.c"
    break;

  case 29: /* selection: IF '(' condition ')' instruction  */
#line 127 "./src/miniC.y"
                                                                                { (yyval.tree) = create_parent_tree((yyvsp[-2].tree), (yyvsp[0].tree), IF_NODE, NULL); }
#line 1509 "miniC.tab.c"
    break;

  case 30: /* selection: IF '(' condition ')' instruction ELSE instruction  */
#line 128 "./src/miniC.y"
                                                                        { (yyval.tree) = create_parent_tree(create_parent_tree((yyvsp[0].tree), NULL, ELSE_NODE, NULL), (yyvsp[-2].tree), IF_NODE, (yyvsp[-4].tree)); }
#line 1515 "miniC.tab.c"
    break;

  case 34: /* saut: BREAK ';'  */
#line 134 "./src/miniC.y"
                                                        { (yyval.tree) = create_parent_tree(NULL, NULL, BREAK_NODE, NULL); }
#line 1521 "miniC.tab.c"
    break;

  case 35: /* saut: RETURN ';'  */
#line 135 "./src/miniC.y"
                                                        { (yyval.tree) = create_parent_tree(NULL, NULL, RETURN_NODE, NULL); }
#line 1527 "miniC.tab.c"
    break;

  case 36: /* saut: RETURN expression ';'  */
#line 136 "./src/miniC.y"
                                        { (yyval.tree) = create_parent_tree(NULL, (yyvsp[-1].tree), RETURN_NODE, NULL); }
#line 1533 "miniC.tab.c"
    break;

  case 37: /* affectation: variable '=' expression  */
#line 139 "./src/miniC.y"
                                        { (yyval.tree) = create_parent_tree((yyvsp[-2].tree), (yyvsp[0].tree), ASSIGN_NODE, NULL); }
#line 1539 "miniC.tab.c"
    break;

  case 38: /* bloc: '{' liste_declarations liste_instructions '}'  */
#line 142 "./src/miniC.y"
                                                                { (yyval.tree) = create_parent_tree((yyvsp[-2].tree), (yyvsp[-1].tree), BLOCK_NODE, NULL);}
#line 1545 "miniC.tab.c"
    break;

  case 39: /* appel: IDENTIFICATEUR '(' liste_expressions ')' ';'  */
#line 145 "./src/miniC.y"
                                                                { (yyval.tree) = create_parent_tree(yylval.id, (yyvsp[-2].tree), CALL_NODE, NULL); }
#line 1551 "miniC.tab.c"
    break;

  case 40: /* variable: IDENTIFICATEUR  */
#line 148 "./src/miniC.y"
                                                        {
										t_declaration	*dec = malloc(sizeof(t_declaration));
										dec->name = yylval.id;
										dec->name = yylval.id;
										dec->type = TYPE_INT;
										(yyval.tree) = create_parent_tree(NULL, NULL, VAR_NODE, dec);	
									}
#line 1563 "miniC.tab.c"
    break;

  case 41: /* variable: variable '[' expression ']'  */
#line 155 "./src/miniC.y"
                                                {	return NULL;	}
#line 1569 "miniC.tab.c"
    break;

  case 43: /* expression: expression binary_op expression  */
#line 159 "./src/miniC.y"
                                                                { (yyval.tree) = create_parent_tree((yyvsp[-2].tree), (yyvsp[0].tree), (yyvsp[-1].type), NULL);}
#line 1575 "miniC.tab.c"
    break;

  case 44: /* expression: MOINS expression  */
#line 160 "./src/miniC.y"
                                                                                        { (yyval.tree) = create_parent_tree(NULL, (yyvsp[0].tree), OPP_NODE, NULL);}
#line 1581 "miniC.tab.c"
    break;

  case 45: /* expression: CONSTANTE  */
#line 161 "./src/miniC.y"
                                                                                                {
														int *constante = malloc(sizeof(int));
														*constante = yylval.constante;
														(yyval.tree) = create_parent_tree(NULL, NULL, CONST_NODE, yylval.constante);
													}
#line 1591 "miniC.tab.c"
    break;

  case 46: /* expression: variable  */
#line 166 "./src/miniC.y"
                                                                                                { (yyval.tree) = create_parent_tree(NULL, (yyvsp[0].tree), ID_NODE, NULL);}
#line 1597 "miniC.tab.c"
    break;

  case 47: /* expression: IDENTIFICATEUR '(' liste_expressions ')'  */
#line 167 "./src/miniC.y"
                                                                { (yyval.tree) = create_parent_tree(yylval.id, (yyvsp[-1].tree), CALL_NODE, NULL); }
#line 1603 "miniC.tab.c"
    break;

  case 48: /* liste_expressions: liste_expressions ',' expression  */
#line 170 "./src/miniC.y"
                                                                        { (yyval.tree) = create_parent_tree((yyvsp[0].tree), (yyvsp[-2].tree), EXP_LIST_NODE, NULL); }
#line 1609 "miniC.tab.c"
    break;

  case 50: /* condition: NOT '(' condition ')'  */
#line 174 "./src/miniC.y"
                                                                                { (yyval.tree) = create_parent_tree(NULL, (yyvsp[-1].tree), NOT_NODE, NULL);}
#line 1615 "miniC.tab.c"
    break;

  case 51: /* condition: condition binary_rel condition  */
#line 175 "./src/miniC.y"
                                                                { (yyval.tree) = create_parent_tree((yyvsp[-2].tree), (yyvsp[0].tree), (yyvsp[-1].type), NULL);		}
#line 1621 "miniC.tab.c"
    break;

  case 52: /* condition: '(' condition ')'  */
#line 176 "./src/miniC.y"
                                                                                        { (yyval.tree) = create_parent_tree(NULL, (yyvsp[-1].tree), COND_NODE, NULL);)}
#line 1627 "miniC.tab.c"
    break;

  case 53: /* condition: expression binary_comp expression  */
#line 177 "./src/miniC.y"
                                                                        { (yyval.tree) = create_parent_tree((yyvsp[-2].tree), (yyvsp[0].tree), (yyvsp[-1].type), NULL);}
#line 1633 "miniC.tab.c"
    break;

  case 54: /* binary_op: PLUS  */
#line 180 "./src/miniC.y"
                        {(yyval.type) = ADD_NODE;}
#line 1639 "miniC.tab.c"
    break;

  case 55: /* binary_op: MOINS  */
#line 181 "./src/miniC.y"
                        {(yyval.type) = MINUS_NODE;}
#line 1645 "miniC.tab.c"
    break;

  case 56: /* binary_op: MUL  */
#line 182 "./src/miniC.y"
                                {(yyval.type) = MULT_NODE;}
#line 1651 "miniC.tab.c"
    break;

  case 57: /* binary_op: DIV  */
#line 183 "./src/miniC.y"
                                {(yyval.type) = DIV_NODE;}
#line 1657 "miniC.tab.c"
    break;

  case 58: /* binary_op: LSHIFT  */
#line 184 "./src/miniC.y"
                        {(yyval.type) = LSHIFT_NODE;}
#line 1663 "miniC.tab.c"
    break;

  case 59: /* binary_op: RSHIFT  */
#line 185 "./src/miniC.y"
                        {(yyval.type) = RSHIFT_NODE;}
#line 1669 "miniC.tab.c"
    break;

  case 60: /* binary_op: BAND  */
#line 186 "./src/miniC.y"
                        {(yyval.type) = BAND_NODE;}
#line 1675 "miniC.tab.c"
    break;

  case 61: /* binary_op: BOR  */
#line 187 "./src/miniC.y"
                                {(yyval.type) = BOR_NODE;}
#line 1681 "miniC.tab.c"
    break;

  case 62: /* binary_rel: LAND  */
#line 190 "./src/miniC.y"
                        { (yyval.type) = LAND_NODE;}
#line 1687 "miniC.tab.c"
    break;

  case 63: /* binary_rel: LOR  */
#line 191 "./src/miniC.y"
                                { (yyval.type) = LOR_NODE; }
#line 1693 "miniC.tab.c"
    break;

  case 64: /* binary_comp: LT  */
#line 194 "./src/miniC.y"
                                { (yyval.type) = BOOL_L_NODE;}
#line 1699 "miniC.tab.c"
    break;

  case 65: /* binary_comp: GT  */
#line 195 "./src/miniC.y"
                                { (yyval.type) = BOOL_G_NODE;}
#line 1705 "miniC.tab.c"
    break;

  case 66: /* binary_comp: GEQ  */
#line 196 "./src/miniC.y"
                                { (yyval.type) = BOOL_GE_NODE;}
#line 1711 "miniC.tab.c"
    break;

  case 67: /* binary_comp: LEQ  */
#line 197 "./src/miniC.y"
                                { (yyval.type) = BOOL_LE_NODE;}
#line 1717 "miniC.tab.c"
    break;

  case 68: /* binary_comp: EQ  */
#line 198 "./src/miniC.y"
                                { (yyval.type) = BOOL_EQ_NODE;}
#line 1723 "miniC.tab.c"
    break;

  case 69: /* binary_comp: NEQ  */
#line 199 "./src/miniC.y"
                        { (yyval.type) = BOOL_NEQ_NODE;}
#line 1729 "miniC.tab.c"
    break;


#line 1733 "miniC.tab.c"

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

#line 201 "./src/miniC.y"


#include "lex.yy.c"

void yyerror(char *s)
{
	printf("erreur : %s, ligne %d\n", s, yylineno);
}

int main(int argc, char **argv)
{
	yydebug = 1;
	for (int i = 1; i < argc; i++)
	{
		yyin = fopen(argv[i], "r");
		if (yyin == NULL)
		{
			fprintf(stderr, "compiler: impossible d'ouvrir le fichier %s\n", argv[i]);
			continue ; 
		}
		yyparse();
		fclose(yyin);
	}
	return 0;
}
