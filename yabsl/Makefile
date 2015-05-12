all:
	bison -d -o yabsl-parser.cc yabsl-parser.yy
	flex -o yabsl-scanner.cc yabsl-scanner.ll
	g++ yabsl-scanner.cc yabsl-parser.cc yabsl.cc yabsl-driver.cc

clean:
	rm -f location.hh stack.hh position.hh
	rm -f yabsl-scanner.cc yabsl-parser.cc yabsl-parser.hh
	rm -f a.out

