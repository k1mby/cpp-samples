CXX = clang++
CXXFLAGS = -std=c++17 -pedantic-errors -g

SRCS =  main.cpp dijkstra.cpp
OBJS = ${SRCS:.cpp=.o}
DEPS = ${OBJS:.o=.d}

MAIN = dijkstra

all: ${MAIN}
	@echo "dijkstra" has been compiled

${MAIN}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${MAIN}

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	${RM} ${PROGS} ${OBJS} *.o *~.

-include ${DEPS}