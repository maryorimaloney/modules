CFLAGS=-Wall -pedantic -std=c11 -I. -g

# pattern rule
%.o: %.c %.h
	gcc $(CFLAGS) -c $<

# files targeted
all: test2 test1try q_test1 q_test2 q_test3 q_test4 q_test5 q_test6 q_test7 q_test8 q_test9 q_test10 q_test11 q_test12 q_test13 q_test14

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

q_test8: q_test8.o queue.o
	gcc $(CFLAGS) q_test8.o queue.o -o q_test8

q_test9: q_test9.o queue.o
	gcc $(CFLAGS) q_test9.o queue.o -o q_test9

q_test10: q_test10.o queue.o
	gcc $(CFLAGS) q_test10.o queue.o -o q_test10

q_test11: q_test11.o queue.o
	gcc $(CFLAGS) q_test11.o queue.o -o q_test11

q_test12: q_test12.o queue.o
	gcc $(CFLAGS) q_test12.o queue.o -o q_test12

q_test13: q_test13.o queue.o
	gcc $(CFLAGS) q_test13.o queue.o -o q_test13

q_test14: q_test14.o queue.o
	gcc $(CFLAGS) q_test14.o queue.o -o q_test14

# cleaning all
clean:
	rm -f *.o test1try test2 q_test1 q_test2 q_test3 q_test4 q_test5 q_test6 q_test7 q_test8 q_test9 q_test10 q_test11 q_test12 q_test13 q_test14


