UTIL=util.c
CLT=cliente.c
AVR=binarytree.c
MAIN=main.c
EXEC=executavel

all:
	gcc -Wall -g $(UTIL) $(CLT) $(AVR) $(MAIN) -o $(EXEC) -lm

run:
	./$(EXEC)
	
debug:
	gcc -DDEBUG -Wall $(MAIN) $(UTIL) $(CLT) $(AVR) -o $(EXEC)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes -s ./$(EXEC)
	
zip:
	zip Projeto05.zip main.c util.c util.h cliente.c cliente.h binarytree.c binarytree.h Makefile

clean:
	@rm *.o