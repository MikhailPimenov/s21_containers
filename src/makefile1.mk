# OBJ_DIR = obj
SOURCE=tests/item.cc 

# SOURCE+=tests/stack/constructors.cc
# SOURCE+=tests/stack/methods.cc

# SOURCE+=tests/queue/constructors.cc
# SOURCE+=tests/queue/methods.cc

# SOURCE+=tests/vector/constructors.cc
# SOURCE+=tests/vector/modifiers.cc
# SOURCE+=tests/vector/access.cc
# SOURCE+=tests/vector/capacity.cc
# SOURCE+=tests/vector/iterator.cc
SOURCE+=tests/vector/other.cc


# SOURCE+=tests/list/list.cc 
# SOURCE+=tests/list/push_back.cc 
# SOURCE+=tests/list/push_front.cc
# SOURCE+=tests/list/access.cc 
# SOURCE+=tests/list/assign.cc
# SOURCE+=tests/list/insert.cc
# SOURCE+=tests/list/emplace.cc
# SOURCE+=tests/list/swap.cc
# SOURCE+=tests/list/erase.cc

# SOURCE=*/*.cc
OBJ = *.o
CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++17 -pthread
GCOVFLAGS =  -g -lgtest -lgcov -lpthread -coverage
ifeq ($(shell uname -s),Darwin)
OPEN = open
MEM_TEST = CK_FORK=no leaks --atExit -- ./test
else
OPEN = xdg-open
MEM_TEST = valgrind --leak-check=full --show-leak-kinds=all ./test
endif

all: clean test gcov_report


# $(OBJ_DIR)/%.o: %.cc
# 	$(CC) $(CFLAGS) -c -o $@ $<

test:
	$(CC) $(GCOVFLAGS) $(SOURCE) tests/tests_main.cc -c -std=c++17
	$(CC) $(OBJ) -o test $(GCOVFLAGS) 
	./test

gcov_report: clean test
	gcovr .
	gcovr --html-details -o report.html
	$(OPEN) ./report.html

clean:
	rm -rf *.o ./test ./a.out ./s21_matrix_oop.a ./*.gc* ./report* ./.clang-format

check: test

	$(MEM_TEST)

stylecheck:
	cp ../materials/linters/.clang-format ./

	clang-format -n *.cc *.h
	cppcheck --language=c++ --std=c++17 *.cc *.h