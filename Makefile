TEST=testapp

all: clean $(TEST)

$(TEST):
	$(CXX) *.cpp -c
	$(CXX) *.o -o $(TEST)

clean:
	rm testapp *.o
