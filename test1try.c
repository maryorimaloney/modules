/* 
 * test1try.c --- 
 * 
 * Author: Gustavo Lopez-Fleming Jr.
 * Created: 10-07-2024
 * Version: 1.0
 * 
 * Description: 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <list.h>
#include <string.h>
car_t *make_car(char *platep,double price,int year); 
// Sample function to apply to each car
void print_car(car_t *cp) {
    printf("Car Plate: %s, Price: %.2f, Year: %d\n", cp->plate, cp->price, cp->year);
}

int main() {
    // Test 1: put() to an empty list
    printf("Test 1: put() to an empty list\n");
    car_t *new_car1 = make_car("ABC123", 15000.00, 2020);

		if (new_car1) { // Only proceed if new_car1 is not NULL
			if (lput(new_car1) == 0) {  
				printf("Successfully added car %s to the empty list.\n", new_car1->plate);
			} else {
				printf("Failed to add car to the empty list.\n");
			}
    } else {
			printf("Failed to create new car.\n");
    }
		
    // Test 2: get() from the list
    printf("\nTest 2: get() from the list\n");
 
    car_t *car_from_empty = NULL;
    if (lget(car_from_empty) == 0) {
        printf("Got car plate: %s from get().\n", car_from_empty->plate);
    } else {
        printf("Successfully returned NULL from get() on an empty list.\n");
    }

    // Test 3: apply() a function to the list
    printf("\nTest 3: apply() a function to the list\n");
    lapply(print_car);  // Should not print anything as the list is now empty

    // Test 4: remove() from an empty list
    printf("\nTest 4: remove() from an empty list\n");
    car_t *removed_car = lremove("XYZ789");
    if (removed_car == NULL) {
        printf("Successfully returned NULL from remove() on an empty list.\n");
    } else {
        printf("Error: expected NULL, got car plate %s.\n", removed_car->plate);
    }

    return 0; // No need for explicit free here as all memory should be managed inside the list functions
}

car_t *make_car(char *platep,double price,int year) {                                                                                                                 
  car_t *cp;                                                                                                                                                          
  if(!(cp = (car_t*)malloc(sizeof(car_t)))) {                                                                                                                         
    printf("[Error: malloc failed allocating car]\n");                                                                                                                
    return NULL;                                                                                                                                                      
  }                                                                                                                                                                   
  cp->next = NULL;                                                                                                                                                    
  strcpy(cp->plate,platep);                                                                                                                                           
  cp->price=price;                                                                                                                                                    
  cp->year=year;                                                                                                                                                      
  return cp;                                                                                                                                                          
} 
