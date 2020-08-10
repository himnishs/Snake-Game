all: run
run: main.cpp snake.cpp 
	g++ snake.cpp main.cpp -o snake_game -lncurses
clean:
	rm snake_game