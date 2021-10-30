all: main

main: main.cpp Tree.cpp Node.cpp
	g++ main.cpp Tree.cpp Node.cpp -o main -lstdc++

clean:
	rm main