NAME		=	push_swap
NAME_B		=	checker

CC			=	gcc 
CFLAGS		=	-Wall -Wextra -Werror 

SRCS_DIR	=	./srcs/
OBJ_DIR		=	./objs/

SRCS 	=push_swap.c pile_utils.c operations.c  operations2.c utils3.c for_sort.c sort3_5.c check_argv.c stack_to_index.c 
SRCS_B   = checker.c get_next_line.c get_next_line_utils.c  operations.c sort3_5.c operations2.c  utils3.c pile_utils.c check_argv.c for_sort.c stack_to_index.c

OBJ			=	$(addprefix $(OBJ_DIR),$(SRCS:.c=.o))
OBJ_B		=	$(addprefix $(OBJ_DIR),$(SRCS_B:.c=.o))

RM			=	/bin/rm -f
RM_DIR		=	/bin/rm -rf

$(OBJ_DIR)%.o:$(SRCS_DIR)%.c
	$(CC) $(CFLAGS)	$(INC) -c $< -o $@

all:
	@mkdir -p $(OBJ_DIR)
	@make $(NAME) 

make_libfts:
	@make -C libfts/ 

$(NAME): $(OBJ)  make_libfts
	@$(CC) $(CFLAGS) $(OBJ) ./libfts/libfts.a -o $(NAME)

bonus:
	@mkdir -p $(OBJ_DIR)
	@make $(NAME_B) 

$(NAME_B): $(OBJ_B)  make_libfts
	@$(CC) $(CFLAGS) $(OBJ_B) ./libfts/libfts.a   -o $(NAME_B)

clean:
	@make clean -C libfts/ 
	$(RM_DIR) $(OBJ_DIR)

fclean: clean
	rm -rf ${NAME_B} ${NAME}
	@make fclean -C libfts/ 
re: clean all
