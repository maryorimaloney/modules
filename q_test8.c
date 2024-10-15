/* 
 * q_test8.c --- 
 * 
 * Author: Maryori C. Maloney Lopez
 * Created: 10-14-2024
 * Version: 1.0
 * 
 * Description: using q_search to find a the number 125
 * 
 */
#include <queue.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
  queue_t *myq2 = qopen(); // opening a queue
	int myKey = 125; // searching key
	
  int first = 120, second = 135, third = 149, fourth = 125, fith = 186;

  qput(myq2, &first);
  qput(myq2, &second);
  qput(myq2, &third);
  qput(myq2, &fourth);
  qput(myq2, &fith);

  printf("Queue content: \n");
  qprint(myq2, print_int);

	int *result = (int*)qsearch(myq2, search_integer, &myKey);

	if (result != NULL) {
		printf("Key Found: %d\n", *result);
	} else {
		printf("KEY NOT FOUND!");
	}

  // garbage collector : to free the heap from filling up the memory
  qclose(myq2);
  return 0;
}
