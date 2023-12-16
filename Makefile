CC=gcc
STDFLAGS=-Wall -Werror -Wextra -std=c11 
TST_CFLAGS:= -g $(STDFLAGS)
GCOV_FLAGS?=-fprofile-arcs -ftest-coverage
LINUX_FLAGS=-lsubunit -lrt -lpthread -lm `pkg-config --cflags --libs check`
LIBS=-lcheck

TARGET=s21_math.a

SRC=$(wildcard s21_*.c)
OBJ=$(patsubst %.c,%.o, ${SRC})

PREF_TEST_SRC=./s21_tests/
TEST_SRC=$(wildcard $(PREF_TEST_SRC)/s21_*.c)

OS := $(shell uname -s)
USERNAME=$(shell whoami)

ifeq ($(OS),Linux)
  OPEN_CMD = xdg-open
endif
ifeq ($(OS),Darwin)
	OPEN_CMD = open
endif

s21_math.a:
all: $(TARGET)

$(TARGET): ${SRC}
	$(CC) -c $(STDFLAGS) $(SRC)
	ar rcu $@ s21_*.o
	ranlib $@
	cp $@ lib$@
	make clean_obj

test: $(TARGET)
ifeq ($(OS), Darwin)
	${CC} $(STDFLAGS) ${TEST_SRC} $< -o unit_test $(LIBS)
else
	${CC} $(STDFLAGS) ${TEST_SRC} $< -o unit_test $(LIBS) $(LINUX_FLAGS)
endif
	./unit_test

gcov_report: clean_test
ifeq ($(OS), Darwin)
	$(CC) $(STDFLAGS) $(GCOV_FLAGS) ${TEST_SRC} ${SRC} -o test $(LIBS)
else
	$(CC) $(STDFLAGS) $(GCOV_FLAGS) ${TEST_SRC} ${SRC} -o test $(LIBS) $(LINUX_FLAGS)
endif
	./test
	lcov -t "s21_report" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	$(OPEN_CMD) ./report/index.html

clang:
	cp ../materials/linters/.clang-format ../src/.clang-format
	clang-format -style=Google -i s21_*.c s21_*.h s21_*/*.h s21_*/*.c
	clang-format -style=Google -n s21_*.c s21_*.h s21_*/*.h s21_*/*.c
	rm .clang-format

brsw:
	-eval /opt/goinfre/$(USERNAME)/homebrew/bin/brew shellenv; \
	-brew update --force --quiet; \
	-chmod -R go-w "$(brew --prefix)/share/zsh"

install_brew:
	-cd /opt/goinfre/$(USERNAME); \
	-mkdir homebrew; \
	-git clone https://github.com/Homebrew/brew homebrew; \
	-make brsw

lcov: install_brew brsw
	-brew install lcov

clean_obj:
	rm -rf *.o

clean_lib: 
	rm -rf *.a

clean_test:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test
	rm -rf report
	rm -rf *.html
	rm -rf *.png
	rm -rf *.css

clean: clean_lib clean_lib clean_test clean_obj
	rm -rf unit_test
	rm -rf RESULT_VALGRIND.txt

.PHONY: all lcov test