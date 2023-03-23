CXX      ?= g++
CXXFLAGS ?= -std=c++20
CPPFLAGS ?= -O3 -Wall -I $(PWD)/include
EXEC = main
SRCS = $(PWD)/src/main.cpp 

$(EXEC):
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(SRCS) -o $(EXEC)

plot: $(EXEC)
	./main
	./plot.sh
