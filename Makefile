all: main

main: main.cpp Tree.cpp Node.cpp Simple.cpp
	g++ main.cpp -o main Tree.cpp Node.cpp Simple.cpp -lstdc++

clean:
	rm main