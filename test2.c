/* 
 * test2.c --- 
 * 
 * Author: Gustavo Lopez-Fleming Jr.
 * Created: 10-06-2024
 * Version: 1.0
 * 
 * Description: 
 * 
 */

//put() to an empty list
//o put() to a non-empty list
//o get() from an empty list
//o get() from a not-empty list
//o apply() a function to an empty list
//o apply() a function to a non-empty list
//3
//o remove() from an empty list
//o remove() from a non-empty list at the end
//o remove() from a non-empty list at the beginning
//o remove() from a non-empty list somewhere in the middle

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list.h>

car_t *make_car(char *platep,double price,int year);
// Helper function for lapply - prints car details
void print_car(car_t* car) {
    if (car != NULL) {
        printf("Car plate: %s, price: %.2f, year: %d\n", car->plate, car->price, car->year);
    }
}

void print_list() {
    printf("\n-- Current List of Cars --\n");
    lapply(print_car);
    printf("-- End of List --\n\n");
}

int main() {
    // Test 1: Add cars to the list
    car_t *car1 = make_car("ABC123", 20000.0, 2010);
    car_t *car2 = make_car("XYZ789", 15000.0, 2012);
    car_t *car3 = make_car("LMN456", 18000.0, 2011);
    
    lput(car1);  // Add car1
    lput(car2);  // Add car2
    lput(car3);  // Add car3
    
    printf("Cars added to the list:\n");
		print_list();
		

    // Test 2: Apply print_car function to all cars in the list
    printf("\nTest 2: Applying function to print all cars in the list...\n");
    lapply(print_car);

    // Test 3: Remove and return a car by its plate number
    printf("\nTest 3: Removing car with plate 'XYZ789'...\n");
    car_t *removed_car = lremove("XYZ789");
    if (removed_car != NULL) {
        printf("Removed car: %s, price: %.2f, year: %d\n", removed_car->plate, removed_car->price, removed_car->year);
    } else {
        printf("Car not found.\n");
    }
    // Apply function again to show remaining cars
    printf("\nRemaining cars in the list after removal:\n");
    lapply(print_car);

		//removing at the beginning
		lput(car2);
		printf("List after adding car2 back:\n");
		lapply(print_car);
		
		car_t *removed_car2 = lremove("XYZ789");
    if (removed_car != NULL) {
        printf("Removed car: %s, price: %.2f, year: %d\n", removed_car2->plate, removed_car2->price, removed_car2->year);
    } else {
        printf("Car not found.\n");
    }

		printf("\nRemaining cars in the list after removal:\n");                                                                                                                                                                                                                                             
    lapply(print_car);

		//removing at the endLMN456
		car_t *removed_car3 = lremove("ABC123");
    if (removed_car != NULL) {
        printf("Removed car: %s, price: %.2f, year: %d\n", removed_car3->plate, removed_car3->price, removed_car3->year);
    } else {
        printf("Car not found.\n");
    }

		printf("Resulting list");
		lapply(print_car);

		

    // Test 4: Get the first car (FIFO)
    printf("\nTest 4: Removing the first car from the list...\n");
    car_t *first_car = lget();
    if (first_car != NULL) {
        printf("Got car: %s, price: %.2f, year: %d\n", first_car->plate, first_car->price, first_car->year);

    } else {
        printf("List is empty.\n");
    }

    // Apply function again to show remaining cars
    printf("\nRemaining cars in the list after getting the first car:\n");
    lapply(print_car);

    // Cleanup remaining cars in the list
    while ((first_car = lget()) != NULL) {
			free(car1);
			free(car2);
			free(car3);
    }
    printf("\nTest completed. All cars removed and list cleaned up.\n");
    return 0;
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

