/* 
 * q_test5.c --- 
 * 
 * Author: Maryori C. Maloney Lopez
 * Created: 10-14-2024
 * Version: 1.0
 * 
 * Description: testing qapply
 * 
 */
#include <queue.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
  queue_t *myq = qopen(); // opening a queue

  int first = 12, second = 13, third = 14;

  qput(myq, &first);
  qput(myq, &second);
  qput(myq, &third);

  printf("Queue content: \n");
  qapply(myq, print_int);
	printf("\n");
  // garbage collector : to free the heap from filling up the memory
  qclose(myq);
  return 0;
}
