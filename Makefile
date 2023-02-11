NONE='\033[0m'
BLUE = '\x1b[36m'
YELLOW= '\x1b[32m'
MAGENTA ='\x1b[35m'

#PREFIX = $(shell find ${HOME} -name lm-readline 2>/dev/null)
NAME		= minishell
SRCS		= $(wildcard src/*/*.c)
#SRCS		+= $(wildcard src/*.c)
OBJS		= $(SRCS:.c=.o)
INCLUDES	= ./includes
CFLAGS		=  -Wall -Wextra -Werror #-fsanitize=address #-lreadline  
RM			= rm -f
CC			= cc

#INCLUDES_READLINE = -I./lm-readline/include

#LINKERS	= -lreadline -L./lm-readline/lib 

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

#readline:
#	cd readline-master && make clean && bash ./configure --prefix=$(PREFIX) && make && make install

re		:fclean all
.PHONY: all clean fclean re