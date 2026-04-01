##
## EPITECH PROJECT, 2025
## mylibc
## File description:
## compiles
##

NAME = "libmylibc.a"

SRC = 	mylibc/src/mystrlen.c			\
		mylibc/src/mymemset.c			\
		mylibc/src/mycalloc.c			\
		mylibc/src/mystrnlen.c			\
		mylibc/src/mymemmem.c			\
		mylibc/src/mystrdup.c			\
		mylibc/src/mystrcmp.c			\
		mylibc/src/newstrlen.c			\
		mylibc/src/mystrchr.c			\
		mylibc/src/mystrncopycat.c		\
		mylibc/src/mystrtointegers.c	\

CFLAGS = -I./mylibc/includes

TEST_SRC =  mylibc/tests/test_one.c	\
	mylibc/tests/test_mystrchr.c	\
	mylibc/tests/test_mystrcpy.c	\
	mylibc/tests/test_mystrlen.c	\

OBJ = $(SRC:.c=.o)

all : $(OBJ)
	ar rc $(NAME) $(OBJ)

re : fclean all

fclean : clean
	@rm -f $(NAME)
	@rm -f unit_tests*

clean :
	@rm -f $(OBJ)

unit_tests : fclean
	$(CC) $(CFLAGS) -o "unit_tests" $(SRC) $(TEST_SRC) 	\
	-lcriterion --coverage

tests_run : unit_tests
	./unit_tests

coverage :
	gcovr --exclude mylibc/tests/ --gcov-executable "llvm-cov gcov"
	gcovr --exclude mylibc/tests/ --branches --gcov-executable "llvm-cov gcov"

debug : CC = epiclang
debug : CFLAGS += -g -Wall
debug : all

full_debug : fclean debug

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
