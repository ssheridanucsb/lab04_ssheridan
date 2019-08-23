
intbst.o: intbst.cpp intbst.h
	g++ intbst.cpp -c

testbst: testbst.o intbst.o
	g++ testbst.o intbst.o -o testbst

testbst.o: testbst.cpp
	g++ testbst.cpp -c

clean:
	rm testbst *.o
