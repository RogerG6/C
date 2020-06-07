
calc: main.o infix_to_suffix.o calc.o  getop.o stack.o 
	gcc -o calc  main.o infix_to_suffix.o calc.o getop.o stack.o 
main.o:main.c
	gcc -c  main.c
	
calc.o:calc.c
	gcc -c calc.c

getop.o:getop.c
	gcc -c getop.c

stack.o:stack.c
	gcc -c stack.c
infix_to_suffix.o:infix_to_suffix.c
	gcc -c infix_to_suffix.c

clean:
	rm *.o calc
