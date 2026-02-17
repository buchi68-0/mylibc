##
## EPITECH PROJECT, 2025
## mylibc
## File description:
## compiles
##

SRC = 	src/mystrlen.c			\
		src/mymemset.c			\
		src/mycalloc.c			\
		src/mystrnlen.c			\
		src/mymemmem.c			\
		src/mystrdup.c			\
		src/mystrcmp.c			\
		src/newstrlen.c			\
		src/mystrchr.c			\
		src/mystrncopycat.c		\
		src/mystrtointegers.c	\

CC := clang
CFLAGS := 

TEST_SRC = tests/test_one.c	\
	tests/test_mystrchr.c	\
	tests/test_mystrcpy.c	\
	tests/test_mystrlen.c	\

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
