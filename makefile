
hex : src/main.cpp
	c++ -std=c++17 src/main.cpp -o hex

clean : 
	rm -f hex