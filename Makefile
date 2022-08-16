SRCS	=	$(wildcard	*.c)
OBJS	=	$(SRCS:.o=.c)
CC		= clang
RM		= rm -rf
CFLAGS	= -Wall -Werror -Wextra -fsanitize=thread
LFLAGS	= -pthread
NAME	= philo

all: 	${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME} 

%.o	:	%.co
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LFLAGS) -o $(NAME)

.PHONY:	all clean fclean re
