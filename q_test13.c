/* 
 * q_test13.c --- 
 * 
 * Author: Maryori C. Maloney Lopez
 * Created: 10-15-2024
 * Version: 1.0
 * 
 * Description: concat two queues containing numbers
 * 
 */
#include <queue.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
  queue_t *myq2 = qopen(); // opening a queue
	queue_t *myq1 = qopen();

  int first = 120, second = 135, third = 149, fourth = 125, fith = 186;
	int p = 3, a = 5, e = 9;
	
  qput(myq2, &first);
  qput(myq2, &second);
  qput(myq2, &third);
  qput(myq2, &fourth);
  qput(myq2, &fith);
	qput(myq1, &p);
	qput(myq1, &a);
	qput(myq1, &e);
	
  printf("Queue 2 content: \n");
  qprint(myq2, print_int);

	printf("Queue 1 content: \n");
  qprint(myq1, print_int);

	
  qconcat(myq1, myq2);
	printf("Queue after concat: \n");
	qapply(myq1, print_int);

  // garbage collector : to free the heap from filling up the memory
  qclose(myq1);
  return 0;
}
