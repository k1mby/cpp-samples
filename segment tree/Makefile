CXX = clang++
CXXFLAGS = -std=c++17 -pedantic-errors -g

SRCS =  main.cpp segment.cpp
OBJS = ${SRCS:.cpp=.o}
DEPS = ${OBJS:.o=.d}

MAIN = segmentTree

all: ${MAIN}
	@echo "segmentTree" has been compiled

${MAIN}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${MAIN}

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	${RM} ${PROGS} ${OBJS} *.o *~.

-include ${DEPS}