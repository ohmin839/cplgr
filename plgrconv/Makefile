.PHONY: init
init:
	test -d ./bin || mkdir ./bin

.PHONY: clean
clean:
	rm -fR ./bin/*

bin/mapping.o: src/mapping.c src/mapping.h
	gcc -I./src \
		-fPIC \
		./src/mapping.c \
		-c -o./bin/mapping.o

bin/parser.o: src/parser.y
	bison src/parser.y -osrc/parser.c -d
	gcc \
		-I./src \
		-fPIC \
		./src/parser.c \
		-c -o./bin/parser.o

bin/lexer.o: src/lexer.l src/parser.h
	flex -osrc/lexer.c src/lexer.l
	gcc \
		-I./src \
		-fPIC \
		./src/lexer.c \
		-c -o./bin/lexer.o

bin/test: test/test_unichar.c bin/mapping.o
	gcc -I./src \
		-fPIC \
		./test/test_unichar.c \
		./bin/mapping.o \
		-o./bin/test
	bin/test

.PHONY: test
test: bin/test

bin/plgrconv: bin/parser.o bin/lexer.o bin/mapping.o
	gcc -I./src \
		-fPIC \
		./bin/parser.o \
		./bin/lexer.o \
		./bin/mapping.o \
		-o./bin/plgrconv \
		-lfl -ly

.PHONY: build
build: bin/plgrconv
