# COMPILER SETUP

CC = gcc
C_FLAGS = -Wall -Werror -Wextra -std=c11
T_FLAGS = -lcheck -lsubunit -lm -L.
V_FLAGS = -fprofile-arcs -ftest-coverage -fPIC -fPIC -O0

# FILE LISTS

C_FILES = $(wildcard helpers/*.c) $(wildcard subroutines/*.c)
O_FILES = $(patsubst %.c, %.o, $(C_FILES))
T_FILES = $(wildcard tests/*.c)

# FIGURING OUT OPEN

ifeq ($(shell uname -s),Linux)
	OPEN = xdg-open
else ifeq($(shell uname -s), Darwin)
	OPEN = open
endif

# MAIN TARGETS

.PHONY: all clean gcov_report

all: s21_matrix.a test gcov_report

clean: clean_test_files
	rm -rf *.a *.o subroutines/*.o helpers/*.o tests/*.o tests/test tests/tests *.gcno *.gcda *.info

test: build_tests
	./tests/test

s21_matrix.a: $(O_FILES)
	ar -rcs -o $@ $^

gcov_report: clean_test_files
	$(CC) $(C_FLAGS) $(V_FLAGS) $(T_FILES) $(C_FILES) -o ./tests/gcov_tests $(T_FLAGS)
	./tests/gcov_tests
	@gcov -f tests/*.gcda
	@lcov -t "gcov_report" -o tests/gcov.info -c -d .
	@genhtml -o ./tests/report tests/gcov.info
	@rm -f tests/*.gcno tests/*.gcda *.gcov
	$(OPEN) tests/report/index.html

# SUPPLEMENTARY TARGETS

$(O_FILES): %.o: %.c
	$(CC) -c $(C_FLAGS) $< -o $@ -lm

build_tests: $(T_FILES) tests/s21_matrix_tests.h s21_matrix.a
	$(CC) $(T_FILES) tests/s21_matrix_tests.h $(T_FLAGS) s21_matrix.a -o tests/test

clean_test_files:
	rm -rf ./tests/*.gcda
	rm -rf ./tests/*.gcno
	rm -rf ./tests/report
	rm -rf ./tests/gcov_tests
	rm -rf ./tests/*.info
	rm -rf ./*.gcov

rebuild: clean all

# DEVELOPER'S TARGETS

vg: s21_matrix.a test
	valgrind --tool=memcheck --leak-check=yes ./tests/test
	@rm -rf *.a *.o subroutines/*.o helpers/*.o tests/*.o tests/test tests/tests *.gcno *.gcda *.info

