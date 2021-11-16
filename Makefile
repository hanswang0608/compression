all: compression

compression: main.cpp Node.cpp
	g++ main.cpp Node.cpp -o compression -lstdc++

clean:
	rm compression