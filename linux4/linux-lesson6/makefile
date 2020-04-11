#目标对象:依赖对象
#	编译命令
#coretest:coretest.c
#	gcc coretest.c -o coretest

#test:linux.o
#	gcc linux.o -o test

#linux.o:test.c
#	gcc -c test.c -o linux.o
#test.o:test.c
#	gcc -c test.c -o test.o
#

BIN=out

# *代表任意字符
SRC=$(wildcard *.c) # a.c b.c c.c test.c
OBJ=$(patsubst %.c, %.o, $(SRC))  # a.o b.o c.o test.o
CFLAGS=-g

.PHONY:$(BIN)
$(BIN):$(OBJ) #a.o b.o c.o test.o
	gcc $^ -o $@

%.o:%.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm $(BIN) $(OBJ)
