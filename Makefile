compile:
	g++ -o src/main src/main.cpp -std=c++11
run:
	src/main < data/tes.in

clean:
	rm -f src/main
