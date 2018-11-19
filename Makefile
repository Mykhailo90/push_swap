PROGRAMS = push_swap checker
SRC = ./src/
POINT = ./mains/
ALLS = $(shell ls $(SRC) | grep -E ".+\.c")
INC = ./
OBJ = ./obj/
OBJECTS = $(addprefix $(OBJ), $(ALLS:.c=.o))
LIB = ./libft/
LIBFT = ./libft/libft.a
LIBINC = ./libft/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(POINT) $(OBJ) $(PROGRAMS) 

$(OBJ):
	@ mkdir obj

$(OBJ)%.o:$(POINT)%.c
	@ $(CC) $(CFLAGS) -I $(LIBINC) -I $(INC) -o $@ -c $<

$(OBJ)%.o:$(SRC)%.c
	@ $(CC) $(CFLAGS) -I$(LIBINC) -I$(INC) -o $@ -c $<

$(PROGRAMS): $(LIBFT) ./obj/push_swap.o ./obj/checker.o $(OBJECTS) 
	@ $(CC) $(CFLAGS) -o push_swap $(OBJECTS) ./obj/push_swap.o $(LIBFT)
	@ $(CC) $(CFLAGS) -o checker $(OBJECTS) ./obj/checker.o $(LIBFT)

$(LIBFT):
	@ make -C $(LIB)

clean:
	@ rm -rf $(OBJ)
	@ make clean -C $(LIB)

fclean: clean
	@ rm -rf $(PROGRAMS)
	@ rm -f log.txt
	@ make fclean -C $(LIB)

re: fclean all
