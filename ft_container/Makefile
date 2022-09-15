# SRCS		=		tests/main_ftvector.cpp
# SRCS		=		tests/main_stdvector.cpp

# SRCS		=		tests/main_ftmap.cpp
# SRCS		=		tests/main_stdmap.cpp

SRCS		=		tests/main_stack.cpp

# SRCS		=		tests/main_intranet.cpp

OBJS		= ${SRCS:.cpp=.o}
CC			= c++
CFLAGS		= -std=c++98 -Wall -Wextra -Werror
NAME		= containers
RM			= rm -f

all:		${NAME}

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