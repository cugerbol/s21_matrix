NAME = s21_matrix
CC = gcc
CC_FLAGS = -std=c11 -Wall -Werror -Wextra
TEST_PATH = ./tests/unit_tests/
MODULES_PATH = ./modules/*
GCOVFLAGS =  -L. $(NAME).a --coverage

OS = $(shell uname)
ifeq ($(OS), Linux)
	CHECK_FLAGS = -lcheck -pthread -lrt -lm -lsubunit
	OPEN_CMD = open
else
	CHECK_FLAGS = -lcheck
	OPEN_CMD = xdg-open
endif

all: clean test gcov_report

create_tests: clang
	checkmk clean_mode=1 $(TEST_PATH)*.check >$(TEST_PATH)tests.c 
 
clean:
	rm -f ./a.out *.o *.a
	rm -rf report
	clear

gcov_report: test
	$(CC) $(CC_FLAGS) $(NAME).a $(TEST_PATH)tests.c $(MODULES_PATH)*.c $(CHECK_FLAGS) $(GCOVFLAGS)
	./a.out
	lcov -t a.out -o rep.info -c -d .
	genhtml rep.info --output-directory report
	genhtml -o report rep.info --include src/*
	open ./report/index.html
	rm -rf *.gcda *.gcno s21_tests s21_tests.info
	rm -f a.out rm -f s21_matrix.a rep.info


test: s21_matrix.a
	$(CC) $(CC_FLAGS) $(NAME).a $(TEST_PATH)tests.c $(CHECK_FLAGS)
	./a.out
	
s21_matrix.a: s21_matrix.o
	ar rcs $(NAME).a *.o
	ranlib $(NAME).a
	rm -rf *.o

s21_matrix.o: clean clang
	$(CC) $(CC_FLAGS) -c modules/s21*.c

clang:
	cp ../materials/linters/.clang-format .
	clang-format -i ./modules/*.c
	clang-format -i ./tests/unit_tests/*
	clang-format -n ./modules/*.c
	clang-format -n ./tests/unit_tests/*
	clang-format -i  *.h
	clang-format -n  *.h

check:
	leaks -atExit -- ./a.out






	
	
	



