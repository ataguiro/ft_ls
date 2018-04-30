NAME = ft_ls
SRC = ft_add_disp.c ft_display.c ft_get.c ft_ls.c ft_manage.c ft_prepare.c ft_sort_hard.c ft_upperf.c ft_design.c ft_errors.c ft_lflag.c ft_parsing.c ft_total.c ft_sort.c
OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME): 
		@echo "=== BUILDING ==="
		@make -C libft/ re ; make -C libft/
		@gcc -c -Werror -Wall -Wextra $(SRC)
		@gcc $(OBJ) -L libft/ -lft -o $(NAME)
		@echo "=== OK ==="
clean:
		@echo "=== DELETING OBJECT FILES ==="
		@/bin/rm -rf $(OBJ) &>/dev/null
		@make -C libft/ clean &>/dev/null
fclean: clean
		@echo "=== CLEANING EVERYTHING ==="
		@/bin/rm -rf $(NAME) &>/dev/null
		@make -C libft/ fclean &>/dev/null
		@echo "=== OK ==="
re: fclean all
