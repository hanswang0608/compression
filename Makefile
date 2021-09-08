all: compressor

compressor: compressor.cpp Tree.cpp Node.cpp
	g++ compressor.cpp Tree.cpp Node.cpp -o compressor -lstdc++

clean:
	rm compressor