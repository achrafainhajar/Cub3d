SRC = main.c get_next_line.c get_next_line_utils.c
CC = gcc 
NAME = cub3d
all : $(NAME)
$(NAME):$(SRC)
	$(CC) $(SRC) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean :
	rm -rf $(NAME)
fclean :clean

re : fclean all