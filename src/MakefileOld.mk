CC=g++
STRICT_CFLAGS=-Wall -std=c++17 -Wextra -pedantic -Werror


GCOVR_CFLAGS=-fprofile-arcs -ftest-coverage -fPIC
GCOVR_LFLAGS=-lgcov


GTEST_LFLAGS=-lgtest -lgtest_main

REPORT_DIRECTORY=report
VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER=valgrind_report

all: s21_matrix_oop.a test gcov_report

s21_matrix_oop.a: s21_matrix_oop.oa 
		ar rcs $@ $^

tests/tests_helpers.o: tests/tests_helpers.cc s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/tests_constructor_assignment.o: tests/tests_constructor_assignment.cc s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/tests_getset.o: tests/tests_getset.cc s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/tests_brace.o: tests/tests_brace.cc s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/tests_multiply.o: tests/tests_multiply.cc s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/tests_subtract.o: tests/tests_subtract.cc s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/tests_sum.o: tests/tests_sum.cc s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/tests_inverse.o: tests/tests_inverse.cc s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/tests_calc_complements.o: tests/tests_calc_complements.cc s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/tests_determinant.o: tests/tests_determinant.cc s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/tests_sum_subscript.o: tests/tests_sum_subscript.cc s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/tests_subtract_subscript.o: tests/tests_subtract_subscript.cc s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/tests_multiply_subscript.o: tests/tests_multiply_subscript.cc s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/tests_equal.o: tests/tests_equal.cc s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/tests_transpose.o: tests/tests_transpose.cc s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)

tests/tests_main.o: tests/tests_main.cc s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)

test: tests/tests_main.exe
		./tests/tests_main.exe

gcov_report: test
		mkdir -p $(REPORT_DIRECTORY)
		gcovr . --html --html-details --exclude-lines-by-pattern '.*assert.*' -o $(REPORT_DIRECTORY)/coverage_report.html
		START "" $(REPORT_DIRECTORY)/coverage_report.functions.html  

tests/tests_main.exe: s21_matrix_oop.o tests/tests_main.o tests/tests_sum_subscript.o tests/tests_subtract_subscript.o tests/tests_multiply_subscript.o tests/tests_equal.o tests/tests_transpose.o tests/tests_determinant.o tests/tests_calc_complements.o tests/tests_inverse.o tests/tests_sum.o tests/tests_subtract.o tests/tests_multiply.o tests/tests_brace.o tests/tests_getset.o tests/tests_constructor_assignment.o tests/tests_getset.o tests/tests_helpers.o
		$(CC) -o $@ $^ $(GTEST_LFLAGS) $(GCOVR_LFLAGS)

s21_matrix_oop.o: s21_matrix_oop.cc s21_matrix_oop.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS)

s21_matrix_oop.oa: s21_matrix_oop.cc s21_matrix_oop.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@


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



check_style:
		clang-format --style=Google -n *.cc
		clang-format --style=Google -n *.h
		clang-format --style=Google -n tests/*.cc
		clang-format --style=Google -n tests/*.h

style: style_google

style_google:
		clang-format --style=Google -i *.cc
		clang-format --style=Google -i *.h
		clang-format --style=Google -i tests/*.cc
		clang-format --style=Google -i tests/*.h

style_microsoft:
		clang-format --style=Microsoft -i *.cc
		clang-format --style=Microsoft -i *.h
		clang-format --style=Microsoft -i tests/*.cc
		clang-format --style=Microsoft -i tests/*.h

style_llvm:
		clang-format --style=LLVM -i *.cc
		clang-format --style=LLVM -i *.h
		clang-format --style=LLVM -i tests/*.cc
		clang-format --style=LLVM -i tests/*.h

style_chromium:
		clang-format --style=Chromium -i *.cc
		clang-format --style=Chromium -i *.h
		clang-format --style=Chromium -i tests/*.cc
		clang-format --style=Chromium -i tests/*.h

style_mozilla:
		clang-format --style=Mozilla -i *.cc
		clang-format --style=Mozilla -i *.h
		clang-format --style=Mozilla -i tests/*.cc
		clang-format --style=Mozilla -i tests/*.h

style_WebKit:
		clang-format --style=WebKit -i *.cc
		clang-format --style=WebKit -i *.h
		clang-format --style=WebKit -i tests/*.cc
		clang-format --style=WebKit -i tests/*.h

clean:
		rm -rf *.o *.exe *.out *.oa *.a
		rm -rf tests/*.o tests/*.exe tests/*.out
		rm -rf *.gcno *.gcda
		rm -rf $(REPORT_DIRECTORY)/*.css $(REPORT_DIRECTORY)/*.html
		rm -rf $(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)/*.txt
