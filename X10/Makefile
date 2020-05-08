all: pi vector clean

pi: MonteCarlo_pi.x10
	./x10/bin/x10c++ MonteCarlo_pi.x10 -o pi

vector: Vector.x10
	./x10/bin/x10c++ Vector.x10 -o vector

clean:
	rm *.cc *.h
