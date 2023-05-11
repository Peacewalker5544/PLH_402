all: mylexer

mylexer: mylexer.l
	flex mylexer.l
	gcc -o mylexer lex.yy.c -lfl

clean:
	rm -f *.o mylexer
	rm -f lex.yy.c