SERV		=	server
CLNT		=	client

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -f

SERVU		=	server.c utils.c 
CLNTU		=	client.c utils.c 

OBJS1		=	$(SERVU:.c=.o)
OBJS2		=	$(CLNTU:.c=.o)

all			:	$(SERV) $(CLNT)

$(SERV)	:	$(OBJS1)
				$(CC) $(CFLAGS) -o $@ $^

$(CLNT)	:	$(OBJS2)
				$(CC) $(CFLAGS) -o $@ $^

%.o     	:	%.c minitalk.h
				$(CC) $(CFLAGS) -c $<

clean		:
				$(RM) $(OBJS1) $(OBJS2)

fclean		:	clean
				$(RM) $(SERV) $(CLNT)

re			:	fclean all

.PHONY		:	all clean fclean re