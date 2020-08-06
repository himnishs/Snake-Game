all: run
run: main.cpp snake.cpp 
	g++ snake.cpp main.cpp -o something -lncurses
clean:
	rm something