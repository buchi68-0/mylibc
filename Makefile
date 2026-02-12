##
## EPITECH PROJECT, 2025
## mylibc
## File description:
## compiles
##

SRC = mylibc/src/mystrlen.c	\
	mylibc/src/mymemset.c	\
	mylibc/src/mycalloc.c	\
	mylibc/src/mystrnlen.c	\
	mylibc/src/mymemmem.c	\
	mylibc/src/mystrdup.c	\
	mylibc/src/mystrcmp.c	\
	mylibc/src/newstrlen.c	\
	mylibc/src/mystrchr.c	\

CC := clang
CFLAGS := 

TEST_SRC = mylibc/tests/test_one.c

OBJ = $(SRC:.c=.o)

all : fclean re

re : $(OBJ)
	ar rc "libmylibc.a" $(OBJ)

fclean : clean
	@rm -f "libmylibc.a"
	@rm -f unit_tests*

clean :
	@rm -f $(OBJ)

unit_tests : fclean
	clang -g -o "unit_tests" $(SRC) $(TEST_SRC) -lcriterion --coverage -I.

tests_run : unit_tests
	./unit_tests

coverage :
	gcovr --exclude tests/ --gcov-executable "llvm-cov gcov"
	gcovr --exclude tests/ --branches --gcov-executable "llvm-cov gcov"

debug : CC := epiclang
debug : CFLAGS := -g
debug : all

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
