attempt: template.c
	cc -I.. ../lib.c template.c -lSDL2 -o attempt

solution: solution.c
	cc -g -I.. ../lib.c solution.c -lSDL2 -lm -o solution

clean:
	-rm solution attempt
