src = $(wildcard ./src/*.cpp)
obj = $(src:.cpp=.o)

SemesterProject: $(obj)
	    g++ -o $@ $^ && ./SemesterProject -d

clean:
	    rm -f $(obj) SemesterProject
