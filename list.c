/* 
 * list.c --- 
 * 
 * Author: Maryori C. Maloney Lopez
 * Created: 10-05-2024
 * Version: 1.0
 * 
 * Description: this is a module for the interface list.h 
 * 
 */
#include <list.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*________________________________CONSTANTS_____________________________*/
static car_t *front = NULL;

/*______________________________WORKSPACE______________________________*/

/* put(): place a car at the beginning of the list
* returns 0 if successful; nonzero otherwise
*/
int32_t lput(car_t *cp) {
	if (!cp) {
		return -1; // if there's nothing
	}

	cp->next = front; // car being placed points to next
	front = cp; // car placed is in front
	return 0;
}

/* get(): remove and return the first car in the list;
* return NULL if the list is empty
*/
car_t *lget() {
	if (!front) {
		return NULL; // empty list
	}

	car_t *cp = front; // top of the list
	front = front->next; // next object will be in front

	return cp;

}

/* apply a function to every car in the list */
void lapply(void (*fn)(car_t *cp)) {
	car_t *p;

	if (front == NULL) {
		printf("Empty List!");
		return;
	} else {
		for (p = front; p != NULL; p = p->next) {
			fn(p);
		}
	}
}

/* remove(): find, remove, and return any car with
* the designated plate; return NULL if not present
*/
car_t *lremove(char *platep) {
	if (front == NULL) {
		return NULL;
	}

	// tracking pointers
	car_t *previous = NULL;
	car_t *current = front;

	while (current != NULL) {

		if (strcmp(current->plate, platep) == 0) {

			if (previous == NULL) {
				front = current->next; // removing front
			} else {
				previous->next = current->next; // removing somewhere else
			}
			return current;
		}
		previous = current;
		current = current->next;
	}
	return NULL; 
}
