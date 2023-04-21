SRC_DIR			=	./src
INC_DIR			=	./includes
CC				=	gcc
RM				=	rm -f
AR				=	ar rcs
ASM				= 	as

UNAME_S			:=	$(shell uname -s)

CFLAGS			=	-g 
PARSER_FILE		=	${SRC_DIR}/parser.y
LEXER_FILE		=	${SRC_DIR}/lexer.l
SRCS			=	${SRC_DIR}/ft_tree/ft_treeadd_f.c\
					${SRC_DIR}/ft_tree/ft_treenew.c\
					${SRC_DIR}/ft_tree/ft_treeprof.c\
					${SRC_DIR}/ast.c\
					${SRC_DIR}/symbol_table.c\
					${SRC_DIR}/asm_generator.c
PARSER			= 	./y.tab.c 

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME			=	compiler

HEADER		=	-I${INC_DIR} -I${INC_DIR}/ft_tree -I./
LDFLAGS		=	-L${SRC_DIR}
FSFLAGS		=	#-fsanitize=address

OBJS				=	${SRCS:.c=.o}
OPARSER_GEN_FILE	=	${PARSER:.c=.o}
%.o				:	%.c
					@echo "~~~~~~~ MAKE PROJECT ~~~~~~~~"
					${CC} -c ${CFLAGS} ${FSFLAGS} -o $@ $< ${HEADER} 

${NAME}			:	lexer parser ${OPARSER_GEN_FILE} ${OBJS}
					@echo "~~~~~~~ COMPILATION ~~~~~~~~~"
					${CC} ${LDFLAGS} ${CFLAGS} ${FSFLAGS} -o ${NAME} ${OBJS} ${OPARSER_GEN_FILE}

all			:	${NAME} 

lexer		:	
				lex ${LEXER_FILE}
parser		:	
				yacc ${PARSER_FILE}
				${CC} -c ${CFLAGS} ${FSFLAGS} ${HEADER} -o ./y.tab.o ./y.tab.c

clean :
				@echo "~~~~~~~~~~ CLEAN ~~~~~~~~~~~~"
				${RM}  ${OBJS} ./lex.yy.c ./y.tab.c ./y.tab.o

fclean		:	clean
				@echo "~~~~~~~~~~ FCLEAN ~~~~~~~~~~"
				${RM} ${NAME}
				${RM} ${NAME_FINAL}

re			:	fclean all

.PHONY		:	all clean fclean re
############### PARTIE TEST ###############
test		:
				make
				@echo "\n~~~~~~~~~~   CPP   ~~~~~~~~~~~"
				./${NAME} ${ARG}

norm		:
				@echo "\n~~~~~ CHECK PROJECT NORM ~~~~~~~"
				norminette ${SRC_DIR}/*.c -R CheckForbiddenSourceHeader
				norminette ${INC_DIR}/*.h -R CheckDefine

flush		:	fclean
				@echo "\n~~~~~~~ Extra-CLEANING  ~~~~~~~~"
				${RM} .DS_STORE
				${RM} *.out
				${RM} *.a
				${RM} ${SRC_DIR}/*.o
				${RM} -R *.dSYM