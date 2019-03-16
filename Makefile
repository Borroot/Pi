make: pi

pi: pi.cpp
	g++ -o pi pi.cpp

clean:
	rm pi
