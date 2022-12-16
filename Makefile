SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all : x.a

x.a : $(OBJ)
	ar -rcs x.a $(OBJ)
	printf "\n	Executable \n\n\n"
	./a.out | cat -e

%.o : %.c get_next_line.h
	@cc -Wall -Werror -Wextra -c $<

deb :
	cc $(SRC)
	printf "\n	Executable \n\n\n"
	./a.out | cat -e

ca :
	cc $(SRC) -D REALLOC
	printf "\n	Executable \n\n\n"
	./a.out | cat -e

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf x.a

re : fclean all

.SILENT : x.a all re fclean clean deb ca
.PHONY : x.a all re fclean clean deb ca