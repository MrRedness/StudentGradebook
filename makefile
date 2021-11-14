CC = clang
CPP = clang++
CFLAGS = -I . -std=c++20 -Wall -Wextra -I src\include\ -Wall -Wextra -Wpedantic -O3 -std=c++2a -pthread -Wconversion
OBJ =  src\cpp\Add.o src\cpp\Check.o src\cpp\Edit.o src\cpp\Gradebook.o src\cpp\Input.o src\cpp\MrRed.o src\cpp\Student.o src\include\PCH.o
OUT = builds\Gradebook


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.cpp $(DEPS)
	$(CPP) -c -o $@ $< $(CFLAGS)

$(OUT) : $(OBJ)
	$(CPP) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	# if exist src\cpp\Add.o (del src\cpp\Add.o);
	# if exist src\cpp\Check.o (del src\cpp\Check.o)
	# if exist src\cpp\Edit.o (del src\cpp\Edit.o)
	# if exist src\cpp\Gradebook.o (del src\cpp\Gradebook.o)
	# if exist src\cpp\Input.o (del src\cpp\Input.o)
	# if exist src\cpp\MrRed.o (del src\cpp\MrRed.o)
	# if exist src\cpp\Student.o (del src\cpp\Student.o)
	# if exist src\include\PCH.o (del src\include\PCH.o)
	rm -f src\cpp\Add.o src\cpp\Check.o src\cpp\Edit.o src\cpp\Gradebook.o src\cpp\Input.o src\cpp\MrRed.o src\cpp\Student.o src\include\PCH.o
