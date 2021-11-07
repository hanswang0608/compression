all: compression

compression: main.cpp Tree.cpp Node.cpp Huffman.cpp
	g++ main.cpp Tree.cpp Node.cpp Huffman.cpp -o compression -lstdc++

clean:
	rm compression