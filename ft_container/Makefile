SRCS1		=		tests/main_ftvector.cpp 	\
					class_test/Test.cpp
SRCS2		=		tests/main_stdvector.cpp 	\
					class_test/Test.cpp

# SRCS1		=		tests/main_ftmap.cpp	 	\
# 					class_test/Test.cpp
# SRCS2		=		tests/main_stdmap.cpp	 	\
# 					class_test/Test.cpp

OBJS1		= ${SRCS1:.cpp=.o}
OBJS2		= ${SRCS2:.cpp=.o}
CC			= c++
CFLAGS		= -std=c++98 -Wall -Wextra -Werror
NAME1		= ft_containers
NAME2		= std_containers
RM			= rm -f

all:		${NAME1}

${NAME1}:	${OBJS1}
			${OBJS2}
			$(CC) $(CFLAGS) -o $(NAME1) ${OBJS1}
			$(CC) $(CFLAGS) -o $(NAME2) ${OBJS2}

clean:
			${RM} ${OBJS1}
			${RM} ${OBJS2}

fclean:		clean
			${RM} ${NAME1}
			${RM} ${NAME2}

re:			fclean all

run:		
			./${NAME1}

.PHONY:		all clean fclean re run