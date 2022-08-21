SRCS	=	$(wildcard	*.c)
OBJS	=	$(SRCS:.c=.o)
CC		= clang
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra -fsanitize=thread
LFLAGS	= -pthread
NAME	= philo

all: 	${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME} 

%.o	:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LFLAGS) -o $(NAME)

re: fclean all
.PHONY:	all clean fclean re
