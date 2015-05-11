DEBUG=-DDEBUG -g
WARNING_ALL=-Wall
WARNINGS=$(WARNINGS_QUIET)
CPP_FILES=lex.yy.c yabsl.tab.c

all:
	@bison -d yabsl.y
	@flex yabsl.lex
	@gcc $(DEBUG) $(WARNINGS) $(CPP_FILES) -o ../bin/lang

clean:
	@rm -f yabsl.tab.c yabsl.tab.h
	@rm -f lex.yy.c

