SRCS		=		main.cpp	\
					Weapon.cpp	\
					HumanA.cpp	\
					HumanB.cpp	\

OBJS		= ${SRCS:.cpp=.o}
CC			= c++
CFLAGS		= -std=c++98 -Wall -Wextra -Werror
NAME		= game
RM			= rm -f

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

${NAME}:	${OBJS}
			$(CC) $(CFLAGS) -o $(NAME) ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

run:		
			./${NAME}

.PHONY:		all clean fclean re run