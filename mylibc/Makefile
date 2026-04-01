##
## EPITECH PROJECT, 2025
## mylibc
## File description:
## compiles
##

NAME = "libmylibc.a"

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

CFLAGS = -I./includes

TEST_SRC = tests/test_one.c	\
	tests/test_mystrchr.c	\
	tests/test_mystrcpy.c	\
	tests/test_mystrlen.c	\

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
	$(CC) $(CFLAGS) -o "unit_tests" $(SRC) $(TEST_SRC)	\
	-lcriterion --coverage

tests_run : unit_tests
	./unit_tests

coverage :
	gcovr --exclude tests/ --gcov-executable "llvm-cov gcov"
	gcovr --exclude tests/ --branches --gcov-executable "llvm-cov gcov"

debug : CC := epiclang
debug : CFLAGS += -g -Wall
debug : all

full_debug : fclean debug

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
