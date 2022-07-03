CC = g++#compiler

CXXFLAGS =  -std=c++11 -Wall -lncurses#compile option for C++ Wall(complie warning) 02(optimize level 2)

TARGET = test

OBJS1 = main.cpp

OBJS2 = figure.cpp

$(TARGET) : $(OBJS1) $(OBJS2)
		$(CC) -o $@ $(CXXFLAGS) $(OBJS1) $(OBJS2)

clean:
	rm $(TARGET)