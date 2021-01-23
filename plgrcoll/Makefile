.PHONY: init
init:
	test -d ./bin || mkdir ./bin

.PHONY: clean
clean:
	rm -fR ./bin/*

bin/action.o: src/action.c
	gcc \
		-I./src \
		-fPIC \
		./src/action.c \
		-c -o./bin/action.o

bin/lexer.o: src/lexer.l
	flex -osrc/lexer.c src/lexer.l
	gcc \
		-I./src \
		-fPIC \
		./src/lexer.c \
		-c -o./bin/lexer.o

bin/utf8conv: assist/utf8conv.c
	gcc -I./src \
		-fPIC \
		./assist/utf8conv.c \
		-o./bin/utf8conv

bin/plgrcoll: bin/action.o bin/lexer.o
	gcc -I./src \
		-fPIC \
		./bin/action.o \
		./bin/lexer.o \
		-o./bin/plgrcoll \
		-lfl

.PHONY: build
build: bin/plgrcoll

.PHONY: install
install: build
	test -d ${HOME}/.local/bin && mkdir -p ${HOME}/.local/bin
	cp bin/plgrcoll ${HOME}/.local/bin/

