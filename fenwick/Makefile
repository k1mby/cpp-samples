CXX = clang++
CXXFLAGS = -std=c++17 -pedantic-errors -g

SRCS =  main.cpp fenwick.cpp
OBJS = ${SRCS:.cpp=.o}
DEPS = ${OBJS:.o=.d}

MAIN = fenwick

all: ${MAIN}
	@echo "fenwick" has been compiled

${MAIN}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${MAIN}

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	${RM} ${PROGS} ${OBJS} *.o *~.

-include ${DEPS}