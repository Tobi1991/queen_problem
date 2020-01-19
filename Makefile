prog:
	gcc -std=c99 -o queen_problem queen_problem.c
	
debug:
	gcc -std=c99 -g -o queen_problem queen_problem.c
	
run:
	./queen_problem
	
clean:
	rm queen_problem