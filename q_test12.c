/* 
 * q_test12.c --- 
 * 
 * Author: Maryori C. Maloney Lopez
 * Created: 10-15-2024
 * Version: 1.0
 * 
 * Description: testing qremove on a queue of numbers
 * 
 */
#include <queue.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
  queue_t *myq2 = qopen(); // opening a queue
  int myKey = 135; // searching key

  int first = 120, second = 135, third = 149, fourth = 125, fith = 186;

  qput(myq2, &first);
  qput(myq2, &second);
  qput(myq2, &third);
  qput(myq2, &fourth);
  qput(myq2, &fith);

  printf("Queue content: \n");
  qprint(myq2, print_int);

  int *result = (int*)qremove(myq2, search_integer, &myKey);

  if (result != NULL) {
    printf("Key removed: %d\n", *result);
  } else {
    printf("KEY VALUE: %d NOT FOUND!\n", myKey);
  }

	printf("Queue content after removal: \n");
  qprint(myq2, print_int);

  // garbage collector : to free the heap from filling up the memory
  qclose(myq2);
  return 0;
}
