CPP = clang++
CFLAGS = -I . -std=c++20 -Wall -Wextra -I src/include/ -Wall -Wextra -Wpedantic -O3 -std=c++2a -pthread -Wno-sign-conversion -Wno-sign-compare
OBJ =  src/cpp/Add.o src/cpp/Check.o src/cpp/Edit.o src/cpp/Gradebook.o src/cpp/Input.o src/cpp/MrRed.o src/cpp/Student.o src/include/PCH.o
OUT = builds/Gradebook


%.o: %.cpp $(DEPS)
	$(CPP) -c -o $@ $< $(CFLAGS)

gradebook: $(OBJ)
	$(CPP) -o builds/Gradebook.exe $^ $(CFLAGS)

windows: $(OBJ)
	$(CPP) -o builds/Gradebook-windows.exe $^ $(CFLAGS)

ubuntu: $(OBJ)
	$(CPP) -o builds/Gradebook-ubuntu.exe $^ $(CFLAGS)

arch: $(OBJ)
	$(CPP) -o builds/Gradebook-arch.exe $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f  $(OBJ)
