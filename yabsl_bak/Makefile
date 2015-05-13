DEBUG=-DDEBUG -g
WARNING_ALL=-Wall
WARNINGS=$(WARNINGS_QUIET)
CPP_FILES=yabsl_scanner.cc yabsl_driver.cc main.cc yabsl_parser.cc
HEADER_FILES=yabsl_parser.hh yabsl_driver.hh \
			 location.hh stack.hh position.hh

all:
	@bison -d -o yabsl_parser.cc yabsl_parser.yy
	@flex -o yabsl_scanner.cc yabsl_scanner.ll
	@g++ $(DEBUG) $(WARNINGS) $(CPP_FILES)
	@make clean

test:
	./a.out test.yabsl

clean:
	@rm -f location.hh
	@rm -f stack.hh
	@rm -f position.hh
	@rm -f yabsl_parser.hh
	@rm -f yabsl_parser.cc
	@rm -f yabsl_scanner.cc

superclean:
	@make clean
	@rm -rf a.out*
