/*------------------------------------------------------------------- */
/* ITS62804– Assignment #1 */
/* Principles of Programming */
/* Student Name: Michelle Ler Hsin Yee */
/* Student ID: 0333120 */
/*------------------------------------------------------------------- */

// ------------------------------------
// Fast Food Ordering System
// ------------------------------------
// 1. Purchase
// 2. Edit Meal
// 3. Add Meal
// 4. Delete Meal
// 5. Show Available Meal 
// 6. Show daily transaction
// 7. Exit

// void introduction()
// {
//     printf("Hi\n");
//     printf("My name is Chaitanya\n");
//     printf("How are you?");
//      There is no return statement inside this function, since its
//      * return type is void
     
// }

// int main()
// {
//      /*calling function*/
//      introduction();
//      return 0;
// }

#include <stdio.h>

int order(), show_meals();

int main() {	
	order();
	return 0;
}

int order() {

	int order_number; //declared variable to store values

	puts("------------------------------------");
	puts("Fast Food Ordering System");
	puts("------------------------------------");
	puts("1. Purchase");
	puts("2. Edit Meal");
	puts("3. Add Meal");
	puts("4. Delete Meal");
	puts("5. Show Available Meal ");
	puts("6. Show daily transaction");
	puts("7. Exit");

	scanf("%d", &order_number);

	switch(order_number) {
		case 1:
			printf("Purchase!\n");
			break;
		case 2:
			printf("This option allows user to edit meals!\n");
			break;
		case 3:
			printf("This option allows user to add meals!\n");
			break;
		case 4:
			printf("This option allows user to delete meals!\n");
			break;
		case 5:
			printf("Available meals!");
			// return show_meals();
			break;		
		case 6:
			printf("Daily transactions!");
			break;
			// Total combo meal transaction
			// Total ala-carte transaction
			// Total sales
			// GST collected
			// : 134
			// : 50
			// : RM 34108.97
			// : RM 2047.60
		case 7:
			printf("Exit!");
			break;				
		default:
			printf("Invalid order!");
	}

	return 0;
}

//create function to purchase a meal
// int purchase_meal() {


// }

int show_meals() {
	int num;
	FILE *fptr;
	if ((fopen("/combo.txt","r+")) == NULL) {
		printf("Error in opening file.\n");		
	}
		
   fscanf(fptr,"%d", &num);

   printf("Value of n = %d", num);
   fclose(fptr); 
  
   return 0;
}

// int daily_transactions() {
	
// }