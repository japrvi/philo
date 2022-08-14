SRCS	=	$(wildcard	*.c)
OBJS	=	$(SRCS:.o=.c)
CC		= clang
RM		= rm -rf
CFLAGS	= -Wall -Werror -Wextra -fsanitize=addres -fsanitize=thread
LFLAGS	= -pthread
NAME	= philo


clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} 

%.o	:	%.co
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LFLAGS) -o $(NAME)

.PHONY:	all clean fclean re
