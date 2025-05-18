NAME = ex02
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Base.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -fr $(OBJ)

fclean: clean
	rm -fr $(NAME)

re: fclean all

.PHONY: all clean fclean re
