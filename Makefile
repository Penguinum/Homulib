CXXFLAGS=-Wall
BINARY=testapp

all: build

build:
	$(CXX) $(CXXFLAGS) *.cpp -c
	$(CXX) $(CXXFLAGS) *.o -o $(BINARY)

check:
	cppcheck -q -j4 --enable=performance,portability,warning,style ./

clean:
	rm testapp *.o
