CXX = g++
CXXFLAGS  = -g -Wall -std=c++11
src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)

myprog: $(obj)
	$(CXX) $(CXXFLAGS) -o $@.out $^

clean:
	rm -f $(obj) myprog*