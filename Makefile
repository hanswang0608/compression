all: compression

compression: main.cpp Node.cpp Tree.cpp
	g++ main.cpp Node.cpp Tree.cpp -o compression -lstdc++

clean:
	rm compression