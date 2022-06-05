all: compression decompression

compression: main_comp.cpp Node.cpp Tree.cpp
	g++ main_comp.cpp Node.cpp Tree.cpp -o compression -lstdc++

decompression: main_deco.cpp Node.cpp Tree.cpp
	g++ main_deco.cpp Node.cpp Tree.cpp -o decompression -lstdc++

clean:
	rm compression decompression