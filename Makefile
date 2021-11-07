all: compression

compression: main.cpp Tree.cpp Node.cpp Simple.cpp
	g++ main.cpp Tree.cpp Node.cpp Simple.cpp -o compression -lstdc++

clean:
	rm compression