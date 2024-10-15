/* 
 * q_test10.c --- 
 * 
 * Author: Maryori C. Maloney Lopez
 * Created: 10-14-2024
 * Version: 1.0
 * 
 * Description: making use of q_search with a boolean function that finds strings
 * 
 */

#include <queue.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
  queue_t *myq5 = qopen(); // opening a queue
	const char *myKey = "E"; // searching key
  char *first = "A", *second = "B", *third = "C", *fourth = "D", *fith = "E";

  qput(myq5, first);
  qput(myq5, second);
  qput(myq5, third);
  qput(myq5, fourth);
  qput(myq5, fith);

  printf("Queue content: \n");
  qprint(myq5, print_str);

	char *result = (char*)qsearch(myq5, search_string, myKey);

	if (result != NULL) {
    printf("Key Found: %s\n", result);
  } else {
    printf("KEY VALUE: %s NOT FOUND!\n", myKey);
  }
	
  // garbage collector : to free the heap from filling up the memory
  qclose(myq5);
  return 0;
}
