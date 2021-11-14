CC = clang
CPP = clang++
CFLAGS = -I . -std=c++20 -Wall -Wextra -I src/include/ -Wall -Wextra -Wpedantic -O3 -std=c++2a -pthread -Wconversion
OBJ =  src/cpp/Add.o src/cpp/Check.o src/cpp/Edit.o src/cpp/Gradebook.o src/cpp/Input.o src/cpp/MrRed.o src/cpp/Student.o src/include/PCH.o
OUT = builds/Gradebook.exe
OUTWindows = builds/Gradebook-windows.exe
OUTUbuntu = builds/Gradebook-ubuntu.exe


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.cpp $(DEPS)
	$(CPP) -c -o $@ $< $(CFLAGS)

$(OUT): $(OBJ)
	$(CPP) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f  $(OBJ)

.PHONY: windows
windows:
	$(OUTWINDOWS): $(OBJ)
		$(CPP) -o $@ $^ $(CFLAGS)

.PHONY: ubuntu
ubuntu:
	$(OUTUbuntu): $(OBJ)
		$(CPP) -o $@ $^ $(CFLAGS)
