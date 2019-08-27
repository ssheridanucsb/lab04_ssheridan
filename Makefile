test_intbst: test_intbst.o intbst.o
	g++ test_intbst.o intbst.o -o test_intbst

test_intbst.o: test_intbst.cpp
	g++ test_intbst.cpp -c

intbst.o: intbst.cpp intbst.h
	g++ intbst.cpp -c

testbst: testbst.o intbst.o
	g++ testbst.o intbst.o -o testbst

testbst.o: testbst.cpp
	g++ testbst.cpp -c

clean:
	rm testbst test_intbst *.o
