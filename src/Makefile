CC=g++
# STRICT_CFLAGS=-Wall -std=c++17 -Wextra -pedantic -Werror
STRICT_CFLAGS=-Wall -std=c++17 -Wextra -pedantic -g


GCOVR_CFLAGS=-fprofile-arcs -ftest-coverage -fPIC
GCOVR_CFLAGS=--coverage
GCOVR_LFLAGS=-lgcov
GCOVR_LFLAGS=--coverage

GTEST_LFLAGS=-lgtest -lgtest_main


REPORT_DIRECTORY=report
VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER=valgrind_report

SOURCES=tests/item.cc 

# SOURCES+=tests/stack/constructors.cc
# SOURCES+=tests/stack/methods.cc

# SOURCES+=tests/queue/constructors.cc
# SOURCES+=tests/queue/methods.cc

# SOURCES+=tests/vector/constructors.cc
# SOURCES+=tests/vector/modifiers.cc
# SOURCES+=tests/vector/access.cc
# SOURCES+=tests/vector/capacity.cc
# SOURCES+=tests/vector/iterator.cc
# SOURCES+=tests/vector/other.cc

# SOURCES+=tests/map/constructors.cc
# SOURCES+=tests/map/capacity.cc
# SOURCES+=tests/map/modifiers.cc
# SOURCES+=tests/map/erase.cc
# SOURCES+=tests/map/iterator.cc
# SOURCES+=tests/map/balance.cc
# SOURCES+=tests/map/lookup.cc

SOURCES+=tests/multiset/constructors.cc

SOURCES+=tests/multimap/constructors.cc
# SOURCES+=tests/multimap/capacity.cc
# SOURCES+=tests/multimap/erase.cc

# SOURCES+=tests/list/list.cc 
# SOURCES+=tests/list/push_back.cc 
# SOURCES+=tests/list/push_front.cc
# SOURCES+=tests/list/access.cc 
# SOURCES+=tests/list/assign.cc
# SOURCES+=tests/list/insert.cc
# SOURCES+=tests/list/emplace.cc
# SOURCES+=tests/list/swap.cc
# SOURCES+=tests/list/erase.cc

# SOURCES+=tests/set/constructors.cc
# SOURCES+=tests/set/capacity.cc
# SOURCES+=tests/set/modifiers.cc
# SOURCES+=tests/set/erase.cc
# SOURCES+=tests/set/iterator.cc
# SOURCES+=tests/set/lookup.cc


# SOURCES=*/*.cc
BINARIES=$(patsubst %.cc,%.o,$(SOURCES))


#test

all: test

test: run_tests gcov_report

tests/tests_main.exe: $(BINARIES)
		$(CC) -o $@ $^ $(GTEST_LFLAGS) $(GCOVR_LFLAGS) -g

%.o: %.cc tests/item.h tests/list_helpers.h s21_list.h tests/stack_helpers.h s21_stack.h tests/queue_helpers.h s21_queue.h tests/vector_helpers.h s21_vector.h tests/map_helpers.h s21_map.h s21_tree.h s21_set.h s21_multimap.h s21_multiset.h tests/set_helpers.h tests/multiset_helpers.h tests/multimap_helpers.h s21_multitree.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS) $(GTEST_CFLAGS) -g

run_tests: tests/tests_main.exe
		./tests/tests_main.exe





#gcov_report

EXCLUDE_FROM_COVERAGE=--exclude-lines-by-pattern '.*assert.*' --exclude-throw-branches

gcov_report: run_tests
		mkdir -p $(REPORT_DIRECTORY)
		gcovr . --html --html-details $(EXCLUDE_FROM_COVERAGE) -o $(REPORT_DIRECTORY)/coverage_report.html
# open "" $(REPORT_DIRECTORY)/coverage_report.functions.html  
# START "" $(REPORT_DIRECTORY)/coverage_report.functions.html  




#valgrind

valgrind: run_tests
		mkdir -p $(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)
		-valgrind --leak-check=full --show-reachable=no --track-origins=yes --log-file=$(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)/valgrind_report.txt -s ./tests/tests_main.exe > $(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)/test_report.txt
		cat $(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)/test_report.txt
		cat $(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)/valgrind_report.txt

valgrind_full: run_tests
		mkdir -p $(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)
		-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=$(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)/valgrind_full_report.txt -s ./tests/tests_main.exe > $(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)/test_report.txt
		cat $(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)/test_report.txt
		cat $(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)/valgrind_full_report.txt

#style

check_style:
		-clang-format --style=Google -n *.cc
		-clang-format --style=Google -n *.h
		-clang-format --style=Google -n tests/*.cc
		-clang-format --style=Google -n tests/*.h
		-clang-format --style=Google -n tests/*/*.cc
		-clang-format --style=Google -n tests/*/*.h
		-clang-format --style=Google -n tests/*.cc
		-clang-format --style=Google -n tests/*.h

style: style_google

style_google:
		-clang-format --style=Google -i *.cc
		-clang-format --style=Google -i *.h
		-clang-format --style=Google -i tests/*.cc
		-clang-format --style=Google -i tests/*.h
		-clang-format --style=Google -i tests/*/*.cc
		-clang-format --style=Google -i tests/*/*.h
		-clang-format --style=Google -i tests/*.cc
		-clang-format --style=Google -i tests/*.h

style_microsoft:
		-clang-format --style=Microsoft -i *.cc
		-clang-format --style=Microsoft -i *.h
		-clang-format --style=Microsoft -i tests/*.cc
		-clang-format --style=Microsoft -i tests/*.h
		-clang-format --style=Microsoft -i tests/*/*.cc
		-clang-format --style=Microsoft -i tests/*/*.h
		-clang-format --style=Microsoft -i tests/*.cc
		-clang-format --style=Microsoft -i tests/*.h

style_llvm:
		-clang-format --style=LLVM -i *.cc
		-clang-format --style=LLVM -i *.h
		-clang-format --style=LLVM -i tests/*.cc
		-clang-format --style=LLVM -i tests/*.h
		-clang-format --style=LLVM -i tests/*/*.cc
		-clang-format --style=LLVM -i tests/*/*.h
		-clang-format --style=LLVM -i tests/*.cc
		-clang-format --style=LLVM -i tests/*.h

style_chromium:
		-clang-format --style=Chromium -i *.cc
		-clang-format --style=Chromium -i *.h
		-clang-format --style=Chromium -i tests/*.cc
		-clang-format --style=Chromium -i tests/*.h
		-clang-format --style=Chromium -i tests/*/*.cc
		-clang-format --style=Chromium -i tests/*/*.cc
		-clang-format --style=Chromium -i tests/*.h
		-clang-format --style=Chromium -i tests/*.cc

style_mozilla:
		-clang-format --style=Mozilla -i *.cc
		-clang-format --style=Mozilla -i *.h
		-clang-format --style=Mozilla -i tests/*.cc
		-clang-format --style=Mozilla -i tests/*.h
		-clang-format --style=Mozilla -i tests/*/*.cc
		-clang-format --style=Mozilla -i tests/*/*.h
		-clang-format --style=Mozilla -i tests/*.cc
		-clang-format --style=Mozilla -i tests/*.h

style_webkit:
		-clang-format --style=WebKit -i *.cc
		-clang-format --style=WebKit -i *.h
		-clang-format --style=WebKit -i tests/*.cc
		-clang-format --style=WebKit -i tests/*.h
		-clang-format --style=WebKit -i tests/*/*.cc
		-clang-format --style=WebKit -i tests/*/*.h
		-clang-format --style=WebKit -i tests/*.cc
		-clang-format --style=WebKit -i tests/*.h




#clean

clean:
		rm -rf *.o *.exe *.out *.oa *.a *.gcov
		rm -rf tests/*.o tests/*.exe tests/*.out tests/*/*.o tests/*.o 
		rm -rf *.gcno *.gcda tests/*/*.gcno tests/*/*.gcda tests/*.gcno tests/*.gcda tests/*.gcov tests/*/*.gcov
		rm -rf $(REPORT_DIRECTORY)/*.css $(REPORT_DIRECTORY)/*.html
		rm -rf $(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)/*.txt
