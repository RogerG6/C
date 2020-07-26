# win下Makefile

ifeq ($(OS),Windows_NT) 
RM = del /Q /F
CP = copy /Y
ifdef ComSpec
SHELL := $(ComSpec)
endif
ifdef COMSPEC
SHELL := $(COMSPEC)
endif
else
RM = rm -rf
CP = cp -f
endif


obj= getch.o getop.o main.o stack.o

calc: $(obj)
	gcc -o calc $(obj)
	
getch.o : getch.c calc.h
	gcc -c $^

getop.o : getop.c calc.h
	gcc -c $^

main.o : main.c calc.h
	gcc -c $^

stack.o : stack.c calc.h
	gcc -c $^


clean:
	$(RM) *.exe	*.o

.PHONY: clean	


