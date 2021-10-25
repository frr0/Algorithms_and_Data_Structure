target:
	# gcc -Wall -g -o program client.c && ./program f1.txt Giallo_Antonio ---+
	gcc -Wall -g -o program client.c && valgrind --leak-check=full --show-leak-kinds=all --log-file=Valgrind.txt ./program f1.txt Giallo_Antonio ---+

clean:
	rm -rf program
	rm -rf *~
	rm -rf #*
	rm -rf *.bak
