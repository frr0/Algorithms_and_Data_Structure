target:
	#gcc -Wall -g -o program client.c && ./program fileIn.txt fileArea.txt filePerimeter.txt
	gcc -Wall -g -o program client.c && valgrind --leak-check=full --show-leak-kinds=all --log-file=Valgrind.txt ./program fileIn.txt fileArea.txt filePerimeter.txt

clean:
	rm -rf program
	rm -rf *~
	rm -rf #*
	rm -rf *.bak
