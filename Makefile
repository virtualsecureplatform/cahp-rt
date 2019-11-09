all: crt0.o libc.a

crt0.o: crt0.s
	$(CC) -target cahp -c $^ -o $@

libc.a: __divhi3.o __modhi3.o __mulhi3.o __udivhi3.o
	$(AR) rcs $@ $^

%.o: %.c
	$(CC) -target cahp -Oz -c $^ -o $@

clean:
	rm -f *.o *.a

.PHONY: clean all
