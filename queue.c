
/* 
 * queue.c --- 
 * 
 * Author: Maryori C. Maloney Lopez
 * Created: 10-13-2024
 * Version: 1.0
 * 
 * Description: 
 * 
 */
#include <queue.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
/* the queue representation is hidden from users of the module */

/* creating node*/
typedef struct Node {
	void *data;
	struct Node *next;
} node_t;

/* creating a queue */
typedef struct Queue {
	struct Node *front;
	struct Node *back;
} pqueue_t;

//typedef pqueue_t queue_t;

/* create an empty queue */
queue_t* qopen(void) {
	pqueue_t *qp = (pqueue_t*)malloc(sizeof(pqueue_t));							 						 									 
	qp->front = NULL;
	qp->back = NULL;

	return (queue_t*) qp;
}

/* deallocate a queue, frees everything in it */
void qclose(queue_t *qp) {
	printf("Running qclose: memory freed\n");
	pqueue_t* pq = (pqueue_t*) qp;
	node_t* current = pq->front;
	node_t* next;
	
	while(current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	free(pq);
}

/* put element at the end of the queue
* returns 0 is successful; nonzero otherwise
*/
int32_t qput(queue_t *qp, void *elementp) {
/* get the first first element from queue, removing it from the queue */
	pqueue_t* pq = (pqueue_t*) qp;

	node_t *new_element = (node_t*)malloc(sizeof(node_t));
	if (new_element == NULL) {
		return 1; // allocation problem failure 
	}

	new_element->data = elementp; // giving data to new node
	new_element->next = NULL;

	if (pq->back == NULL) {
		pq->front = pq->back = new_element;
	} else {
		pq->back->next = new_element;
		pq->back = new_element;
	}
	return 0;
}

/* get the first element from the queue, removing it from the queue*/
void* qget(queue_t *qp) {
	pqueue_t* pq = (pqueue_t*) qp;

	if (pq->front == NULL) {
		return NULL; 
	}

	node_t* curr = pq->front;
	void* data = curr->data;

	pq->front = pq->front->next;
	
	// set back to null
	if (pq->front == NULL) {
		pq->back = NULL;
	}
	free(curr);
	return data; // returning data from dequeued node
}

/* apply a function to every element of the queue */

void qapply(queue_t *qp, void (*fn)(void* elementp)) {

	pqueue_t* pq = (pqueue_t*) qp; // pointer for pq
	node_t* current = pq->front; // placeholder pointer to front

	// Checking for Empty queue or no data on the element
	if (current == NULL) {
		printf("Empty: Nothing to apply a function to\n");
		return;
	}
	
	// go through the queue and print
	while (current != NULL) {
		fn(current->data); // apply func to the current element
		printf("\n");
		current = current->next; // go to the next node
	} 
}

void* qsearch(queue_t *qp, bool (*searchfn)(void* elementp,const void* keyp), const void* skeyp) {
	pqueue_t* pq = (pqueue_t*) qp; // pointer for pq
	node_t* current = pq->front; // placeholder pointer to front

	/* search through the queue */
	while (current != NULL) {

		// applying the function to the current node
		if (searchfn(current->data, skeyp)) {
			return current->data; // return pointer to the element
		}
		current = current->next;
	}
	return NULL; // no matching elements found
}

void* qremove(queue_t *qp, bool (*searchfn)(void* elementp,const void* keyp), const void* skeyp) {
	pqueue_t* pq = (pqueue_t*) qp; // pointer for pq
	node_t* current = pq->front;
	node_t* previous = NULL;

	/* traversing the queue */
	while (current != NULL) {

		if (searchfn(current->data, skeyp)) {
			/* if is the front */
			if (previous == NULL) {
				pq->front = current->next;
			} else {
				previous->next = current->next; // link previous to next node
			}

			/* if element is in the back*/
			if (current->next == NULL) {
				pq->back = previous; //update pointer
			}

			void* data = current->data;
			free(current);

			return data;
		}
		/* Moving to next element */
		previous = current;
		current = current->next;
	}

	return NULL;
}

/* concatenatenates elements of q2 into q1
 * q2 is dealocated, closed, and unusable upon completion
 */
void qconcat(queue_t *q1p, queue_t *q2p) {
	pqueue_t* q1 = (pqueue_t*) q1p;
	pqueue_t* q2 = (pqueue_t*) q2p;
	/* checking if q2 is empty */
	if (q2->front == NULL) {
		printf("Second Queue is Empty!");
		free(q2);
		return;
	}

	/* checking q1 (empty?) */
	if (q1->front == NULL) {
		// if empty we will point to q2
		q1->front = q2->front;
		q1->back = q2->back;
	} else {
		// if q1 is not empty we will concatenate it with q2
		q1->back->next = q2->front;
		q1->back = q2->back; // the new end of the queue
	}

	free(q2); //freeing it 
}

/*__________________ADDITIONAL FUNCTIONS_____________________ */

/* function for printing content in the queue */
void qprint(queue_t* qp, void (*print_func)(void*)) {
	pqueue_t* pq = (pqueue_t*) qp;
	node_t* current = pq->front;

	if (current == NULL) {
		printf("Empty\n");
		return;
	}

	// go through the queue and print
	while (current != NULL) {
		print_func(current->data);
		printf("\n");
		current = current->next;
	}
	printf("\n");
}

/* function to print int  */
void print_int(void* data) {
	printf("%d", *(int*)data);
	
}
/* function to print strings */
void print_str(void* data) {
	printf("%s", (char*)data);
}

// function that sums integers in the queue
void sum_ming(void *elementp) {

	static int total_sum = 0;
  int *value = (int*)elementp;
  total_sum += *value;
  printf("Total Sum: %d\n", total_sum);
}

// search function for integers [if int are equal it returns TRUE otherwise FALSE]
bool search_integer(void* elementp, const void* keyp) {
	int *element = (int*)elementp; // casting element pointer
	int *key = (int*)keyp; // casting key pointer

	return (*element == *key);
}
// search function for string
bool search_string(void* elementp, const void* keyp) {
  char *element = (char*)elementp; // casting element pointer
  char *key = (char*)keyp; // casting key pointer

  return (strcmp(element, key) == 0);
}
