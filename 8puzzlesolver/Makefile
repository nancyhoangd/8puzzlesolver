# Nancy Hoang ndh9tsj

CXXFLAGS = -Wall -O2
CXX = clang++ $(CXXFLAGS) 
DEBUG = -g

OBJECTS = 8puzzleSolver.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)
	doxygen

.PHONY: clean
clean:
	-rm -f *.o *a.out *~

8puzzleSolver.o: 8puzzleSolver.cpp
	$(CXX) -c 8puzzleSolver.cpp