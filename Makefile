all: compressor

compressor: compressor.cpp Tree.cpp
	g++ compressor.cpp Tree.cpp -o compressor -lstdc++

clean:
	rm compressor