#
#	simple Makefile example
#
helloworld: helloworld.o
	gcc helloworld.o -o helloworld

helloworld.o: helloworld.c
	gcc -c helloworld.c

hellocplusw: hellocplusw.o
	g++ hellocplusw.o -o hellocplusw

hellocplusw.o: hellocplusw.C
	g++ -c hellocplusw.C

all: helloworld hellocplusw

clean:
	rm -f helloworld.o helloworld
	rm -f hellocplusw.o hellocplusw
