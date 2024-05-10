# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 13:04:38 by ljospin           #+#    #+#              #
#    Updated: 2023/07/05 11:04:01 by ljospin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	myAwesomePhonebook

SRCS		=	main.cpp \
				phoneBook.cpp \
				Contact.cpp \

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