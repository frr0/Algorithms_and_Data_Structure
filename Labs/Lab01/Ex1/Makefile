target:
	# gcc -Wall -g -o program clientA.c util.c && ./program f1.txt f2.txt
	gcc -Wall -g -o program clientA.c && valgrind --leak-check=full --show-leak-kinds=all --log-file=Valgrind.txt ./program f1.txt f2.txt
	# gcc -Wall -g -o program clientB.c util.c && ./program f1.txt f2.txt
	gcc -Wall -g -o program clientB.c && valgrind --leak-check=full --show-leak-kinds=all --log-file=Valgrind.txt ./program f1.txt f2.txt

clean:
	rm -rf program
	rm -rf *~
	rm -rf #*
	rm -rf *.bak
