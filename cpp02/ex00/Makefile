NAME		=	fixed

SRCS		=	main.cpp \
				Fixed.cpp \

OBJDIR	=	objs

OBJS = $(addprefix ${OBJDIR}/, ${SRCS:.cpp=.o})

CC			=	c++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

RM			=	rm -rf
	

${OBJDIR}/%.o:%.cpp
	@mkdir -p ${@D}
	${CC} ${CFLAGS} -c $< -o $@

all:			${NAME}
	
$(NAME):	${OBJS}
				${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS} ${OBJDIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re