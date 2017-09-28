/*------------------------------------------------------------------- */
/* ITS62804– Assignment #1 */
/* Principles of Programming */
/* Student Name: Michelle Ler Hsin Yee */
/* Student ID: 0333120 */
/*------------------------------------------------------------------- */

#include <stdio.h>

int order(), show_meals(), purchase_meal();

int main() {	
	order();
	return 0;
}

int order() {

	int order_number; //declared variable to store order values

	puts("------------------------------------");
	puts("Fast Food Ordering System");
	puts("------------------------------------");
	puts("1. Purchase");
	puts("2. Edit Meal");
	puts("3. Add Meal");
	puts("4. Delete Meal");
	puts("5. Show Available Meals");
	puts("6. Show daily transaction");
	puts("7. Exit");

	scanf("%d", &order_number);

	switch(order_number) {
		case 1:
			purchase_meal();
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
			show_meals();						
			break;		
		case 6:
			printf("Daily transactions!\n");
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
int purchase_meal() {


}

//create function to display all combo meals available
int show_meals() {

   FILE *fp;
   char text_file[250];

   fp = fopen("combo.txt", "r"); //opens txt file and READS only

   puts("----------------------------------------------");
   puts("HERE ARE THE COMBO MEALS:");
   puts("----------------------------------------------");

   fgets(text_file, 250, (FILE*)fp);
   printf("%s\n", text_file );

   fgets(text_file, 250, (FILE*)fp);
   printf("%s\n", text_file );
   
   fgets(text_file, 250, (FILE*)fp);
   printf("%s\n", text_file );

   fgets(text_file, 250, (FILE*)fp);
   printf("%s\n", text_file );

   fgets(text_file, 250, (FILE*)fp);
   printf("%s\n", text_file );

   fclose(fp); //close the file
   return 0;

}

// int daily_transactions() {
	
// }