/* 
 * q_test3.c --- 
 * 
 * Author: Maryori C. Maloney Lopez
 * Created: 10-14-2024
 * Version: 1.0
 * 
 * Description:  Holding a queue of strings only
 * 
 */

#include <queue.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
  queue_t *myq4 = qopen(); // opening a queue

  char *first = "John", *second = "Mary", *third = "Paula", *fourth = "Tommy", *fith = "Enrique";

  qput(myq4, first);
  qput(myq4, second);
  qput(myq4, third);
  qput(myq4, fourth);
  qput(myq4, fith);

  printf("Queue content: \n");
  qprint(myq4, print_str);

  // retrieving first element
  qget(myq4);
  printf("Queue content after qget(): \n");
  qprint(myq4, print_str);

  // garbage collector : to free the heap from filling up the memory
  qclose(myq4);
  return 0;
}
