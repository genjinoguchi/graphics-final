all:
	bison -d -o yabsl-parser.cc yabsl-parser.yy
	flex -o yabsl-scanner.cc yabsl-scanner.ll
	g++ -DDEBUG -g main.cc yabsl-driver.cc yabsl-scanner.cc yabsl-parser.cc

clean:
	rm -f yabsl-scanner.cc yabsl-parser.cc yabsl-parser.hh
	rm -f position.hh location.hh stack.hh
	rm -rf a.out*
