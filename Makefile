all: compressor

compressor: compressor.cpp
	g++ compressor.cpp -o compressor -lstdc++

clean:
	rm compressor