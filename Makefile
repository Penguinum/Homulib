TEST=testapp
CXXFLAGS=-Wall

all: clean $(TEST)

$(TEST):
	$(CXX) $(CXXFLAGS) *.cpp -c
	$(CXX) $(CXXFLAGS) *.o -o $(TEST)

clean:
	rm testapp *.o
