target:
	# gcc -Wall -g -o program client.c core.c producer.c util.c && valgrind --leak-check=full --show-leak-kinds=all --log-file=Valgrind.txt ./program f1.txt f2.txt
	gcc -Wall -g -o program client.c mat.c paths.c util.c && valgrind --leak-check=full --show-leak-kinds=all --log-file=Valgrind.txt ./program f1.txt
	# gcc -Wall -g -o program client.c mat.c paths.c util.c && ./program f1.txt
clean:
	rm -rf program
	rm -rf *~
	rm -rf #*
	rm -rf *.bak
