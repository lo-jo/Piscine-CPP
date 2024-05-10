NAME		=	PureAbstraction

SRCS		=	main.cpp \
				srcs/AMateria.cpp \
				srcs/Character.cpp \
				srcs/Cure.cpp \
				srcs/Ice.cpp \
				srcs/MateriaSource.cpp \

OBJDIR	=	objs

OBJS = $(addprefix ${OBJDIR}/, ${SRCS:.cpp=.o})

CXX			=	c++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

RM			=	rm -rf
	

${OBJDIR}/%.o:%.cpp
	@mkdir -p ${@D}
	${CXX} ${CFLAGS} -c $< -o $@

all:			${NAME}
	
$(NAME):	${OBJS}
				${CXX} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS} ${OBJDIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re