DEBUG=-DDEBUG -g
WARNING_ALL=-Wall
WARNINGS=$(WARNINGS_QUIET)
CPP_FILES=yabsl-scanner.cc yabsl-driver.cc main.cc yabsl-parser.cc
HEADER_FILES=yabsl-parser.hh yabsl-driver.hh \
			 location.hh stack.hh position.hh

all:
	bison -d -o yabsl-parser.cc yabsl-parser.yy
	flex -o yabsl-scanner.cc yabsl-scanner.ll
	g++ $(DEBUG) $(CPP_FILES)
	make clean
	make test

sources:
	bison -d -o yabsl-parser.cc yabsl-parser.yy
	flex -o yabsl-scanner.cc yabsl-scanner.ll

test:
	./a.out ../../tests/test.yabsl

clean:
	rm -f yabsl-scanner.cc yabsl-parser.cc yabsl-parser.hh
	rm -f position.hh location.hh stack.hh

superclean:
	make clean
	rm -rf a.out*
