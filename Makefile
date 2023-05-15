CC				=		gcc
RM				=		rm -f
UNAME_S			:=		$(shell uname -s)

SRC_DIR			=		./src
INC_DIR			=		./include
TESTS_DIR		= 		./ExampleFiles

TESTS_FILES 	=		${shell ls ExampleFiles/*.c}
TESTS_ERROR_FILES = 	${shell ls TestErrorFiles/*/*.c}
NAME			=		compiler

HEADER			=		-I${INC_DIR} -I./
LDFLAGS			=		-L${SRC_DIR}
OBJS			=		${SRCS:.c=.o}

PARSER_FILE		=		${SRC_DIR}/miniC.y
LEXER_FILE		=		${SRC_DIR}/lexer.l
SRCS			=		${SRC_DIR}/ft_tree/ft_treeadd_f.c\
						${SRC_DIR}/ft_tree/ft_treenew.c\
						${SRC_DIR}/ft_tree/ft_treeprof.c\
						${SRC_DIR}/ast.c\
						${SRC_DIR}/symbol_table.c\
						${SRC_DIR}/stack_symbol_table.c\
						${SRC_DIR}/sementic_analys.c\
						${SRC_DIR}/sementic_symbol_table.c\
						${SRC_DIR}/dim.c\
						${SRC_DIR}/dot.c

%.o				:	%.c
					@echo "~~~~~~~ MAKE PROJECT ~~~~~~~~"
					${CC} -c ${CFLAGS} ${HEADER} ${FSFLAGS} -o $@ $<

${NAME}			:	lexer parser ${OPARSER_GEN_FILE} ${OBJS}
					@echo "~~~~~~~ COMPILATION ~~~~~~~~~"
					${CC} ${LDFLAGS} ${FSFLAGS} -o ${NAME} ${OBJS} ./y.tab.o -lfl

all			:	${NAME} 

lexer		:	
				lex ${LEXER_FILE}
parser		:	
				bison ${PARSER_FILE} -b "miniC"
				${CC} -c ${CFLAGS} ${FSFLAGS} ${HEADER} -o ./y.tab.o ./miniC.tab.c -g

clean :
				@echo "~~~~~~~~~~ CLEAN ~~~~~~~~~~~~"
				${RM}  ${OBJS} ./lex.yy.c miniC.tab.c ./y.tab.c ./y.tab.o
				${RM} ${TESTS_DIR}/*.dot

fclean		:	clean
				@echo "~~~~~~~~~~ FCLEAN ~~~~~~~~~~"
				${RM} ${NAME}
				${RM} ${NAME_FINAL}

re			:	fclean all

test : test_good test_error

test_good	:
				./${NAME}  ${TESTS_FILES}
test_error  :
				./${NAME}  ${TESTS_ERROR_FILES}

.PHONY		:	all clean fclean re
