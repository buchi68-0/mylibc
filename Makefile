##
## EPITECH PROJECT, 2025
## mylibc
## File description:
## compiles
##

SRC = mystrlen.c	\
	mymemset.c	\
	mycalloc.c	\

TEST_SRC = tests/test_one.c

OBJ = $(SRC:.c=.o)

all : $(OBJ)
	ar rc "mylibc.a" $(OBJ)

re : fclean all

fclean : clean
	rm -f "mylibc.a"
	rm -f unit_tests*

clean :
	rm -f $(OBJ)

unit_tests : fclean
	clang -g -o "unit_tests" $(SRC) $(TEST_SRC) -lcriterion --coverage -I.

tests_run : unit_tests
	./unit_tests

coverage :
	gcovr --exclude tests/ --gcov-executable "llvm-cov gcov"
	gcovr --exclude tests/ --branches --gcov-executable "llvm-cov gcov"
