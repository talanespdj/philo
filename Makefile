NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread -O3 -g3 

#CFLAGS += -Wno-unused-but-set-variable
#CFLAGS += -fsanitize=thread

SRC = philo.c \
	wgas.c \
	utils.c \
	state.c \
	routine.c \
	process.c \

OBJS = $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< 

all: $(NAME)
        
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	echo "\033[1mphilosophers ready\033[0m"

clean:
	rm -rf $(OBJS)
	echo "c'est clean"

fclean: clean
	rm -rf $(NAME)
	echo "c'est fclean"

re: fclean all

.PHONY: all, clean, fclean, re

.SILENT:
