##
# Solution target
#
# The solution target builds
# the solution executable by
# building the solution.o
# object file and linking it
# into the executable file.
#
solution: solution.o
    g++ solution.o -o solution
    rm solution.o

##
# Solution.o target
#
# The solution.o target builds
# the object file for the
# solution.cpp source code.
#
solution.o: solution.cpp
    g++ -c solution.cpp

##
# Clean target
#
# The clean target removes
# the solution executable.
#
clean:
    rm solution
