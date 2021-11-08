src = $(wildcard ./src/*.cpp)
obj = $(src:.cpp=.o)

SemesterProject: $(obj)
	    g++ -o $@ $^ && ./SemesterProject

clean:
	    rm -f $(obj) SemesterProject
