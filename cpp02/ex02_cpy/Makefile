SRCS		=		main.cpp		\
					Fixed.cpp		\
					Fixed2.cpp		\
					Fixed3.cpp		\
					Fixed4.cpp

OBJS		= ${SRCS:.cpp=.o}
CC			= c++
CFLAGS		= -std=c++98 -Wall -Wextra -Werror
NAME		= fixed
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