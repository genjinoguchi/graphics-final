all:
	bison -d -o calc++-parser.cc calc++-parser.yy
	flex -o calc++-scanner.cc calc++-scanner.ll
	g++ -DDEBUG -g calc++.cc calc++-driver.cc calc++-scanner.cc calc++-parser.cc

clean:
	rm -f calc++-scanner.cc calc++-parser.cc calc++-parser.hh
	rm -f position.hh location.hh stack.hh
	rm -f a.out
	rm -rf a.out*
