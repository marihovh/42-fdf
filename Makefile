NAME=fdf.a
HEADER=fdf.h 
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
FRAME_FLAGS = -lmlx -framework OpenGL -framework AppKit
G_FLAG = -Imlx
CC=cc
LIBFT = libft/libft.a
CFLAGS= -Wall -Werror -Wextra
RM=rm -f

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(FRAME_FLAGS) $(OBJ)  -o $(NAME)

%.c : %.o 
	$(CC) $(G_FLAG) -c $< -o $@

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(OBJ)

re : fclean all

.PHONY : all, clean, fclean, all