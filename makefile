main: main.cpp
	g++ main.cpp -o main -O3
	./main
	rm main

plot: plot.py
	python3 plot.py