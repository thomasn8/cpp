SRCS		=		main.cpp		\
					Bureaucrat.cpp	\
					Form.cpp		\
					ShrubberyCreationForm.cpp	\
					RobotomyRequestForm.cpp		\
					PresidentialPardonForm.cpp	\

OBJS		= ${SRCS:.cpp=.o}
CC			= c++
CFLAGS		= -std=c++98 -Wall -Wextra -Werror
NAME		= bureau
RM			= rm -f

all:		${NAME}

.cpp.o:
			${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

${NAME}:	${OBJS}
			$(CC) $(CFLAGS) -o $(NAME) ${OBJS}

clean:
			${RM} ${OBJS}
			${RM} *_shrubbery

fclean:		clean
			${RM} ${NAME}

re:			fclean all

run:		
			./${NAME}

.PHONY:		all clean fclean re run