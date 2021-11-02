src = $(wildcard ./src/*.cpp)
obj = $(src:.cpp=.o)

SemesterProject: $(obj)
	    g++ -o $@ $^

clean:
	    rm -f $(obj) SemesterProject
