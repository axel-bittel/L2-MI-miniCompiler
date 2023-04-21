SRC_DIR			=	./src
INC_DIR			=	./include
CC				=	gcc
RM				=	rm -f
AR				=	ar rcs
ASM				= 	as

UNAME_S			:=	$(shell uname -s)

CFLAGS			=	-g 
PARSER_FILE		=	${SRC_DIR}/miniC.y
LEXER_FILE		=	${SRC_DIR}/lexer.l
SRCS			=	${SRC_DIR}/ft_tree/ft_treeadd_f.c\
					${SRC_DIR}/ft_tree/ft_treenew.c\
					${SRC_DIR}/ft_tree/ft_treeprof.c\
					${SRC_DIR}/ast.c\
					${SRC_DIR}/symbol_table.c\
					${SRC_DIR}/stack_symbol_table.c\
					${SRC_DIR}/syntaxic_analys_utils.c
TESTS_FILES 	= 	${shell ls ExampleFiles/*.c}
NAME			=	compiler

HEADER		=	-I${INC_DIR} -I./
LDFLAGS		=	-L${SRC_DIR}
OBJS				=	${SRCS:.c=.o}
%.o				:	%.c
					@echo "~~~~~~~ MAKE PROJECT ~~~~~~~~"
					${CC} -c ${CFLAGS} ${HEADER} ${FSFLAGS} -o $@ $< -g

${NAME}			:	lexer parser ${OPARSER_GEN_FILE} ${OBJS}
					@echo "~~~~~~~ COMPILATION ~~~~~~~~~"
					${CC} ${LDFLAGS} ${CFLAGS} ${FSFLAGS} -o ${NAME} ${OBJS} ./y.tab.o -lfl -g

all			:	${NAME} 

lexer		:	
				lex ${LEXER_FILE}
parser		:	
				bison ${PARSER_FILE} -b "miniC"
				${CC} -c ${CFLAGS} ${FSFLAGS} ${HEADER} -o ./y.tab.o ./miniC.tab.c -g

clean :
				@echo "~~~~~~~~~~ CLEAN ~~~~~~~~~~~~"
				${RM}  ${OBJS} ./lex.yy.c miniC.tab.c ./y.tab.c ./y.tab.o

fclean		:	clean
				@echo "~~~~~~~~~~ FCLEAN ~~~~~~~~~~"
				${RM} ${NAME}
				${RM} ${NAME_FINAL}

re			:	fclean all

test		:
				./${NAME}  ${TESTS_FILES}

.PHONY		:	all clean fclean re
