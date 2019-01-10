# Example makefile

# Let FLTK return the compiler
CXX = $(shell fltk-config --cxx)

# Save lib path in variable
LIB=../../lib

# Let FLTK set the system specific compiler flags
CXXFLAGS = $(shell fltk-config --cxxflags) -g -std=c++14 -I $(LIB)

# Set app name
FNAME=program_03_11

# Set dependencies needed to compile
HEADERS = $(LIB)/analysis.hpp
DEPS = $(LIB)/analysis.cpp


app:
	$(CXX) $(CXXFLAGS) $(DEPS) $(FNAME).cpp -o $(FNAME)