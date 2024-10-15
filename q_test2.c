/* 
 * q_test2.c --- 
 * 
 * Author: Maryori C. Maloney Lopez
 * Created: 10-14-2024
 * Version: 1.0
 * 
 * Description:  Holding a queue of numbers only and erasing the top node
 * 
 */
#include <queue.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
  queue_t *myq2 = qopen(); // opening a queue

  int first = 120, second = 135, third = 149, fourth = 125, fith = 186;

  qput(myq2, &first);
  qput(myq2, &second);
  qput(myq2, &third);
	qput(myq2, &fourth);
	qput(myq2, &fith);

  printf("Queue content: \n");
  qprint(myq2, print_int);

	// retrieving first element
	qget(myq2);
	printf("Queue content after qget(): \n");
	qprint(myq2, print_int);
	
  // garbage collector : to free the heap from filling up the memory
  qclose(myq2);
  return 0;
}
