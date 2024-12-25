CXX = g++

SRCS = $(wildcard *.cpp)

OBJS = $(SRCS:.cpp=.o)

OUT = main

all: $(OUT)

$(OUT): $(OBJS)
	$(CXX) -o $(OUT) $(OBJS)

%.o: %.cpp
	$(CXX) -c $< -o $@

# Clean object and executable files
clean:
	rm -f $(OBJS) $(OUT)

# Phony targets (not files)
.PHONY: all clean
