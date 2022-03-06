# Author: Cooper Nasiedlak
# NETID: nasiedlak
# ID#: 9082213803

CXX = g++
CXXFLAGS = -Wall

demo: demo.o BookDB.o
	$(CXX) $(CXXFLAGS) -o demo demo.o BookDB.o

demo.o: demo.cpp BookDB.h
	$(CXX) $(CXXFLAGS) -c demo.cpp

BookDB.o: BookDB.h

clean:
	-rm BookDB.o
	-rm demo.o
	-rm demo