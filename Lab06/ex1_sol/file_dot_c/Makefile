target:
	# gcc -Wall -g -o program client.c && ./program
	gcc -Wall -g -o program client.c && valgrind --leak-check=full --show-leak-kinds=all --log-file=Valgrind.txt ./program f1.txt

clean:
	rm -rf program
	rm -rf *~
	rm -rf #*
	rm -rf *.bak
