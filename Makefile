deafult:

proc: src/process.cc
	g++ -c src/process.cc -o bin/process.o
rwcp: src/readwrite.cc
	g++ -c src/readwrite.cc -o bin/ReadWrite.o
test:
	g++ src/process.cc src/readwrite.cc test/test.cc -o test.exe
	test.exe