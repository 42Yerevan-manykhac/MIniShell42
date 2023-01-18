NONE='\033[0m'
BLUE = '\x1b[36m'
YELLOW= '\x1b[32m'
MAGENTA ='\x1b[35m'

NAME		= minishell
SRCS		= $(wildcard src/*/*.c)
#SRCS		+= $(wildcard src/*.c)
OBJS		= $(SRCS:.c=.o)
INCLUDES	= ./includes
CFLAGS		= -Wall -Wextra -Werror -lreadline  -fsanitize=address
RM			= rm -f
CC			= cc


%.o:%.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJS)
		@echo $(NONE)$(BLUE) "\n\t\t🤹 Compiling $(NAME)... \n" $(NONE)
		$(CC) $(CFLAGS) -I $(INCLUDES)  $(OBJS) -o $(NAME)  -lreadline
		@echo $(NONE)$(BLUE)"\n\t\t😱 Compiled   $(NAME)\n"$(NONE)

clean	:
		@echo $(YELLOW) "\n\t\t🙀 Removing object files...\n" $(NONE)
		$(RM) $(OBJS)

fclean	: 	clean
			@echo $(MAGENTA) "\n\t\t🙀 Removing $(NAME)...\n" $(NONE)
			$(RM) $(NAME)  
			rm -rf ~/LIbrary/Caches

re		:fclean all
.PHONY: all clean fclean re