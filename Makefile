CFLAGS=-Wall -pedantic -std=c11 -I. -g

# pattern rule
%.o: %.c %.h
	gcc $(CFLAGS) -c $<

# files targeted
all: test2 test1try q_test1 q_test2 q_test3 q_test4 q_test5 q_test6 q_test7

# linking the files
test1try: test1try.o list.o
	gcc $(CFLAGS) test1try.o list.o -o test1try

test2: test2.o list.o
	gcc $(CFLAGS) test2.o list.o -o test2

q_test1: q_test1.o queue.o
	gcc $(CFLAGS) q_test1.o queue.o -o q_test1

q_test2: q_test2.o queue.o
	gcc $(CFLAGS) q_test2.o queue.o -o q_test2

q_test3: q_test3.o queue.o
	gcc $(CFLAGS) q_test3.o queue.o -o q_test3

q_test4: q_test4.o queue.o
	gcc $(CFLAGS) q_test4.o queue.o -o q_test4

q_test5: q_test5.o queue.o
	gcc $(CFLAGS) q_test5.o queue.o -o q_test5

q_test6: q_test6.o queue.o
	gcc $(CFLAGS) q_test6.o queue.o -o q_test6

q_test7: q_test7.o queue.o
	gcc $(CFLAGS) q_test7.o queue.o -o q_test7

# cleaning all
clean:
	rm -f *.o test1try test2 q_test1 q_test2 q_test3 q_test4 q_test5 q_test6 q_test7


