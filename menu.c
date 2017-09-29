/*------------------------------------------------------------------- */
/* ITS62804– Assignment #1 */
/* Principles of Programming */
/* Student Name: Michelle Ler Hsin Yee */
/* Student ID: 0333120 */
/*------------------------------------------------------------------- */

#include <stdio.h>

int order(), show_combo_meals(), show_addon(), purchase_meal();

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

	printf("Please enter order option (1-7): ");
	scanf("%d", &order_number);

	while (order_number > 7 || order_number < 1) {
		printf("Please enter a CORRECT order option (1-7): ");
		scanf("%d", &order_number);		
	} 

	//prompt user for purchase again until enters exit option (7)
	switch(order_number) {
		case 1:
			show_combo_meals();	
			purchase_meal();

			// a function for adding on meals

			// puts("--------------------------------------------");
			// printf("Would you like to addon?");
			// puts("--------------------------------------------");
			// puts("(1) YES ");
			// puts("(2) NO ");

			// scanf("%d", &addon_number);

			// if (addon_number == 1) {
			// 	show_addon();
			// } else {
			// 	printf("Have a nice meal! Your purchases are: %s\n", purchases)
			// }

			printf("Thanks for purchasing!\n");
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
			show_combo_meals();
			show_addon();							
			break;		
		case 6:
			printf("Daily transactions!\n");
			break;
			// Total combo meal transaction :
			// Total ala-carte transaction :
			// Total sales :
			// GST collected :
		case 7:
			printf("Exit!");
			break;				
		default:
			printf("Invalid order!");
	}

	return 0;
}

//function to print_receipt
void print_receipt(int quantity, char *item, float price, float total) {
	puts("-----------------------------------------------------");									
	puts("|Qty|\t|Item|\t\t\t\t|Price|");
	puts("-----------------------------------------------------");									
	printf("%d\t%s\t\tRM %.2f\n", quantity, item, price);
	puts("-----------------------------------------------------");									
	printf("TOTAL: RM%.2f\n", total);
}

//function to purchase a meal
int purchase_meal() {

	char meal_choice[5];
	char *item;
	float price, total;
	int quantity;
	
	printf("What would you like to purchase and how many?\n");
	scanf("%s %d", meal_choice, &quantity);	

	switch (meal_choice[4]) {
		case '1': 			// assuming they chose set 1 with code C0001 
			price = 10.99;
			item = "Lunch Deal Set A";
			total = price * quantity;

			print_receipt(quantity, item, price, total);

		    break;
		case '2':
			price = 12.99;
			item = "Lunch Deal Set B";
			total = price * quantity;
			printf("%.2f\n", total);	
		    
		    break;
		case '3':
			price = 6.99;
			item = "Teatime Saver";
			total = price * quantity;	
			printf("%.2f\n", total);
		    
		    break;
		case '4':
			price = 12.99;
			item = "Dinner Deal Set A";
			total = price * quantity;	
			printf("%.2f\n", total);
		    
		    break;
		case '5':
			price = 14.99;
			item = "Dinner Deal Set B";
			total = price * quantity;
			printf("%.2f\n", total);	
		    
		    break;		        
		default:
			puts("Invalid meal option!");
	}

	return 0;
	
}

//function to display all combo meals available
int show_combo_meals() {

   FILE *fp;
   char text_file[250];

   fp = fopen("combo.txt", "r"); //opens txt file and READS only

   puts("----------------------------------------------");
   puts(" COMBO MEALS: ");
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

   puts("----------------------------------------------");

   fclose(fp); //close the file
   return 0;

}

int show_addon() {

   FILE *fp;
   char text_file[250];

   fp = fopen("addon.txt", "r"); //opens txt file and READS only

   puts("----------------------------------------------");
   puts(" ADD-ONS: ");
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

   puts("----------------------------------------------");

   fclose(fp); //close txt file
   return 0;

}

// int daily_transactions() {
	
// }

// to calculate the total with tax
// int tax(int price, int quantity) {
// 	int taxed_total, total;
// 	taxed_total += (total * 60 / 100);
// 	return taxed_total;
// }