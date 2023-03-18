CC = clang++
CFLAGS = -Wall -Werror -O3 -std=c++17

final: main.o helpers.o
	echo "Linking"
	$(CC) $(CFLAGS) main.o helpers.o -o final

main.o: main.cpp
	echo "Compiling main"
	$(CC) $(CFLAGS) -c main.cpp

helpers.o: helpers.cpp
	echo "Compiling helpers"
	$(CC) $(CFLAGS) -c helpers.cpp

clean: 
	echo "cleaning"
	rm *.o final

# .o files are object files.
# The compiler makes these files before linking them together.
# Thats why we compile main.cpp anf helpers.cpp into .o files so that
# their respective .o files can be linked together for the output "final".
# Why don't I just use my mpp function? Doesn't it do this shit already?
#
# Maybe since mpp cant deal with header files well and needs *.cpp hash included 
# for it to work. Make doesnt need that. Why not just use *c as included libraries?


