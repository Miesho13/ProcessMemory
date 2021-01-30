deafult:

proc: src/process.cc
	g++ -c src/process.cc -o bin/process.o
test:
	g++ src/process.cc test/test.cc -o test.exe
	test.exe