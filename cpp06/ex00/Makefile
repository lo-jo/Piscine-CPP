# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 12:25:50 by ljospin           #+#    #+#              #
#    Updated: 2023/09/11 12:25:51 by ljospin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	convert

SRCS		=	main.cpp \
				ScalarConverter.cpp \
				typeDetection.cpp \
				typeConversion.cpp \
				displayResults.cpp \

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