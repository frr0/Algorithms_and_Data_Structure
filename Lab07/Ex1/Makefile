targetInt:
	cp dataInt.c prova.c
	cp dataInt.h prova.h
	gcc -Wall -g -I. -o tree prova.c tree.c treeAddition.c client.c -lm
	./tree

# targetStr:
	cp dataStr.c prova.c
	cp dataStr.h prova.h
	gcc -Wall -g -I. -o tree prova.c tree.c treeAddition.c client.c -lm
	./tree

clean:
	rm -rf tree
	rm -rf *~
	rm -rf #*
	rm -rf *.bak
