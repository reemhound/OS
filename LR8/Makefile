all: compile run-signal-function run-sigaction-function

compile: sigaction-function.c signal-function.c
	gcc sigaction-function.c -o sigaction-function.out
	gcc signal-function.c -o signal-function.out

run-signal-function: signal-function.out
	./signal-function.out

run-sigaction-function: sigaction-function.out
	./sigaction-function.out