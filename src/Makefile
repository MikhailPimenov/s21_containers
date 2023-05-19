CC=g++
# STRICT_CFLAGS=-Wall -std=c++17 -Wextra -pedantic -Werror
STRICT_CFLAGS=-Wall -std=c++17 -Wextra -pedantic


GCOVR_CFLAGS=-fprofile-arcs -ftest-coverage -fPIC
GCOVR_LFLAGS=-lgcov


GTEST_LFLAGS=-lgtest -lgtest_main

REPORT_DIRECTORY=report
VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER=valgrind_report

SOURCES=tests/list/list.cc tests/list/push_back.cc tests/item.cc
BINARIES=$(patsubst %.cc,%.o,$(SOURCES))


#test

all: test

test: run_test gcov_report

tests/tests_main.exe: $(BINARIES)
		$(CC) -o $@ $^ $(GTEST_LFLAGS) $(GCOVR_LFLAGS)

%.o: %.cc tests/item.h tests/list_helpers.h s21_list.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS) $(GTEST_CFLAGS)

run_test: tests/tests_main.exe
		./tests/tests_main.exe





#gcov_report

EXCLUDE_FROM_COVERAGE=--exclude-lines-by-pattern '.*assert.*'

gcov_report: run_test
		mkdir -p $(REPORT_DIRECTORY)
		gcovr . --html --html-details $(EXCLUDE_FROM_COVERAGE) -o $(REPORT_DIRECTORY)/coverage_report.html
		START "" $(REPORT_DIRECTORY)/coverage_report.functions.html  




#valgrind

valgrind: tests/tests_main.exe
		mkdir -p $(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)
		-valgrind --leak-check=full --show-reachable=no --track-origins=yes --log-file=$(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)/valgrind_report.txt -s ./tests/tests_main.exe > $(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)/test_report.txt
		cat $(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)/test_report.txt
		cat $(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)/valgrind_report.txt

valgrind_full: tests/tests_main.exe
		mkdir -p $(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)
		-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=$(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)/valgrind_full_report.txt -s ./tests/tests_main.exe > $(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)/test_report.txt
		cat $(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)/test_report.txt
		cat $(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)/valgrind_full_report.txt




#style

check_style:
		clang-format --style=Google -n *.cc
		clang-format --style=Google -n *.h
		clang-format --style=Google -n tests/*.cc
		clang-format --style=Google -n tests/*.h
		clang-format --style=Google -n tests/*/*.cc
		clang-format --style=Google -n tests/*/*.h
		clang-format --style=Google -n tests/*.cc
		clang-format --style=Google -n tests/*.h

style: style_google

style_google:
		clang-format --style=Google -i *.cc
		clang-format --style=Google -i *.h
		clang-format --style=Google -i tests/*.cc
		clang-format --style=Google -i tests/*.h
		clang-format --style=Google -i tests/*/*.cc
		clang-format --style=Google -i tests/*/*.h
		clang-format --style=Google -i tests/*.cc
		clang-format --style=Google -i tests/*.h

style_microsoft:
		clang-format --style=Microsoft -i *.cc
		clang-format --style=Microsoft -i *.h
		clang-format --style=Microsoft -i tests/*.cc
		clang-format --style=Microsoft -i tests/*.h
		clang-format --style=Microsoft -i tests/*/*.cc
		clang-format --style=Microsoft -i tests/*/*.h
		clang-format --style=Microsoft -i tests/*.cc
		clang-format --style=Microsoft -i tests/*.h

style_llvm:
		clang-format --style=LLVM -i *.cc
		clang-format --style=LLVM -i *.h
		clang-format --style=LLVM -i tests/*.cc
		clang-format --style=LLVM -i tests/*.h
		clang-format --style=LLVM -i tests/*/*.cc
		clang-format --style=LLVM -i tests/*/*.h
		clang-format --style=LLVM -i tests/*.cc
		clang-format --style=LLVM -i tests/*.h

style_chromium:
		clang-format --style=Chromium -i *.cc
		clang-format --style=Chromium -i *.h
		clang-format --style=Chromium -i tests/*.cc
		clang-format --style=Chromium -i tests/*.h
		clang-format --style=Chromium -i tests/*/*.cc
		clang-format --style=Chromium -i tests/*/*.cc
		clang-format --style=Chromium -i tests/*.h
		clang-format --style=Chromium -i tests/*.cc

style_mozilla:
		clang-format --style=Mozilla -i *.cc
		clang-format --style=Mozilla -i *.h
		clang-format --style=Mozilla -i tests/*.cc
		clang-format --style=Mozilla -i tests/*.h
		clang-format --style=Mozilla -i tests/*/*.cc
		clang-format --style=Mozilla -i tests/*/*.h
		clang-format --style=Mozilla -i tests/*.cc
		clang-format --style=Mozilla -i tests/*.h

style_WebKit:
		clang-format --style=WebKit -i *.cc
		clang-format --style=WebKit -i *.h
		clang-format --style=WebKit -i tests/*.cc
		clang-format --style=WebKit -i tests/*.h
		clang-format --style=WebKit -i tests/*/*.cc
		clang-format --style=WebKit -i tests/*/*.h
		clang-format --style=WebKit -i tests/*.cc
		clang-format --style=WebKit -i tests/*.h




#clean

clean:
		rm -rf *.o *.exe *.out *.oa *.a
		rm -rf tests/*.o tests/*.exe tests/*.out tests/*/*.o tests/*.o
		rm -rf *.gcno *.gcda tests/*/*.gcno tests/*/*.gcda tests/*.gcno tests/*.gcda
		rm -rf $(REPORT_DIRECTORY)/*.css $(REPORT_DIRECTORY)/*.html
		rm -rf $(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)/*.txt
