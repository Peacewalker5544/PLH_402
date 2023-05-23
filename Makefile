all: mycompiler

mycompiler: 
	bison -d -v -r all myanalyzer.y
	flex mylexer.l
	gcc -o mycompiler lex.yy.c myanalyzer.tab.c cgen.c -lfl
clean:
	rm -f *.o mycompiler
	rm -f lex.yy.c
	rm -f myanalyzer.tab.c
	rm -f myanalyzer.tab.h
	rm -f myanalyzer.output