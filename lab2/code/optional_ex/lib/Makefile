NAME		=	libs
FLAGS		=	-Wall -Wextra -Werror
CC			=	gcc


LIBROOT		=	.
LIB_DIRS	=	$(LIBROOT)/matrix $(LIBROOT)/graph

$(NAME):
	$(foreach d, $(LIB_DIRS), make -C $d;)

clean:
	$(foreach d, $(LIB_DIRS), make clean -C $d;)

fclean:
	$(foreach d, $(LIB_DIRS), make fclean -C $d;)

re:
	$(foreach d, $(LIB_DIRS), make re -C $d;)