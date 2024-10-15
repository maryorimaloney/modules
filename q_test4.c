/* 
 * q_test4.c --- 
 * 
 * Author: Maryori C. Maloney Lopez
 * Created: 10-14-2024
 * Version: 1.0
 * 
 * Description: Holding a queue of Characters only
 * 
 */
#include <queue.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
  queue_t *myq5 = qopen(); // opening a queue

  char *first = "A", *second = "B", *third = "C", *fourth = "D", *fith = "E";

  qput(myq5, first);
  qput(myq5, second);
  qput(myq5, third);
  qput(myq5, fourth);
  qput(myq5, fith);

  printf("Queue content: \n");
  qprint(myq5, print_str);

  // retrieving first element
  qget(myq5);
  printf("Queue content after qget(): \n");
  qprint(myq5, print_str);

	// retrieving next element
	qget(myq5);
  printf("Queue content after second time: \n");
  qprint(myq5, print_str);
	
  // garbage collector : to free the heap from filling up the memory
  qclose(myq5);
  return 0;
}
