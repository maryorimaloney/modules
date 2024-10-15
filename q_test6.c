/* 
 * q_test6.c --- 
 * 
 * Author: Maryori C. Maloney Lopez
 * Created: 10-14-2024
 * Version: 1.0
 * 
 * Description: testing q_apply by creating a function that sums up the numbers per iteration
 * 
 */
#include <queue.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
  queue_t *myq = qopen(); // opening a queue

  int first = 12, second = 13, third = 14, fourth = 230, fith = 1000, sixth = 3409;

  qput(myq, &first);
  qput(myq, &second);
  qput(myq, &third);
	qput(myq, &fourth);
	qput(myq, &fith);
	qput(myq, &sixth);

  printf("Queue content: \n");
  qapply(myq, sum_ming); //return the sum
  printf("\n");
  // garbage collector : to free the heap from filling up the memory
  qclose(myq);
  return 0;
}
