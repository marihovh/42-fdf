NAME=fdf.a
HEADER=fdf.h 
SRC=fdf_main.c read_map.c get_next_line.c get_next_line_utils.c $(wildcard libft/*.c)
OBJ=$(SRC:.c=.o)
CC=cc 
CFLAGS= -Wall -Werror -Wextra
AR=ar -rcs
RM=rm -f

all : $(NAME)

%.c : %.o 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(OBJ)

re : fclean all

.PHONY : all, clean, fclean, all