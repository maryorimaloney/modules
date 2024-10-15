/* 
 * q_test7.c --- 
 * 
 * Author: Maryori C. Maloney Lopez
 * Created: 10-14-2024
 * Version: 1.0
 * 
 * Description: using qapply and the summing function to an empty queue
 * 
 */
#include <queue.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
  queue_t *myq = qopen(); // opening a queue

  printf("Queue content: \n");
  qapply(myq, sum_ming); //return the sum
  printf("\n");
  // garbage collector : to free the heap from filling up the memory
  qclose(myq);
  return 0;
}
