all: mycompiler

mycompiler: 
	bison -d -v -r all myanalyzer.y 
	flex mylexer.l
	gcc -o mycompiler lex.yy.c myanalyzer.tab.c cgen.c -lfl

	./mycompiler < useless.ka > useless.c
	./mycompiler < prime.ka > prime.c 
	./mycompiler < qsort.ka > qsort.c 
	./mycompiler < qsort_comprehension.ka > qsort_comprehension.c 
	./mycompiler < reverseWithComprehension.ka > reverseWithComprehension.c
	./mycompiler < qsortWithComp.ka > qsortWithComp.c
	./mycompiler < bookstore.ka > bookstore.c

	gcc ./useless.c -o useless
	gcc ./prime.c -o prime
	gcc ./qsort.c -o qsort
	gcc ./qsort_comprehension.c -o qsort_comprehension
	gcc ./reverseWithComprehension.c -o reverseWithComprehension
	gcc ./qsortWithComp.c -o qsortWithComp
	gcc ./bookstore.c -o bookstore

clean:
	rm -f *.o mycompiler
	rm -f lex.yy.c
	rm -f myanalyzer.tab.c
	rm -f myanalyzer.tab.h
	rm -f myanalyzer.output

	rm -f useless.c
	rm -f prime.c
	rm -f qsort.c
	rm -f qsort_comprehension.c
	rm -f reverseWithComprehension.c 
	rm -f qsortWithComp.c
	rm -f bookstore.c

	rm -f useless
	rm -f prime
	rm -f qsort
	rm -f qsort_comprehension
	rm -f reverseWithComprehension
	rm -f qsortWithComp
	rm -f bookstore