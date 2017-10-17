/*------------------------------------------------------------------- */
/* ITS62804– Assignment #1 */
/* Principles of Programming */
/* Student Name: Michelle Ler Hsin Yee */
/* Student ID: 0333120 */
/*------------------------------------------------------------------- */

//ask how to send the file?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int order(), show_combo_meals(), show_addon(), purchase_meal();
float taxing( float price, int quantity);

struct Meal {
	float price;
	float tax;
	int quantity;
	char code[5];
	char description[100];
	char name[50];	
} meal1, meal2, meal3, meal4, meal5, sum;

int main(void) {	

	order();
	return 0;
}

int order() {

	unsigned int order_number; //declared variable to store order values

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
		printf("Please enter a valid order option (1-7): ");
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
			// printf("Total combo meal transaction : %d\n", combo_trans);
			// printf("Total ala-carte transaction : %d\n", ala_trans);
			// printf("Total sales : %.2f\n", grand_total);
			// printf("GST collected : %.2f\n", sumgst);
		case 7:
			printf("Exit! Thanks for coming!");
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
	float price, total, sumtax, tax;
	int quantity;
	float grand_total;
	grand_total += total;
	int combo_trans, ala_trans;
	
	
	printf("What would you like to purchase and how many?\n");
	scanf("%s %d", meal_choice, &quantity);	


		switch (meal_choice[4]) {
			grand_total += total;
			
			//sumtax+=tax;
			case '1': 			// assuming they chose set 1 with code C0001 
				price = meal1.price;				
				item = meal1.name;
				tax = taxing(price, quantity);
				total = (price * quantity) + tax;
				grand_total += total;
				combo_trans++;

				print_receipt(quantity, item, price, grand_total);				

			    break;
			case '2':
				price = meal2.price;
				item = meal2.name;
				tax = taxing(price, quantity);
				total = price * quantity + tax;
				combo_trans++;
				
				
			    
			    break;
			case '3':
				price = meal3.price;
				item = meal3.name;
				total = price * quantity;	
				
				combo_trans++;
			    
			    break;
			case '4':
				price = meal4.price;
				item = meal4.name;
				total = price * quantity;	
				combo_trans++;
				printf("%.2f\n", total);
			    
			    break;
			case '5':
				price = meal5.price;
				item = meal5.name;
				total = price * quantity;
				printf("%.2f\n", total);	
				combo_trans++;
			    
			    break;		        
			default:
				puts("Invalid meal option!");
				grand_total += total;

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

   // fgets(text_file, 250, (FILE*)fp);
   // printf("%s\n", text_file );

   // fgets(text_file, 250, (FILE*)fp);
   // printf("%s\n", text_file );
   
   // fgets(text_file, 250, (FILE*)fp);
   // printf("%s\n", text_file );

   // fgets(text_file, 250, (FILE*)fp);
   // printf("%s\n", text_file );

   // fgets(text_file, 250, (FILE*)fp);
   // printf("%s\n", text_file );

   fscanf(fp, "%[^:]:%[^:]:%f:%[^ ]\n", meal1.code, meal1.name, &meal1.price, meal1.description);
   fscanf(fp, "\n%[^:]:%[^:]:%f:%[^ ]\n", meal2.code, meal2.name, &meal2.price, meal2.description);
   fscanf(fp, "\n%[^:]:%[^:]:%f:%[^ ]\n", meal3.code, meal3.name, &meal3.price, meal3.description);


   printf("---------------------------------------\n");
   printf("code  :%s\n",meal1.code);
   printf("Name     :%s\n",meal1.name);
   printf("Price    :RM%.2f\n",meal1.price);
   
   printf("---------------------------------------\n");


   printf("---------------------------------------\n");
   printf("code  :%s\n",meal2.code);
   printf("Name     :%s\n",meal2.name);
   printf("Price    :RM%.2f\n",meal2.price);
   
   printf("---------------------------------------\n");

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
float taxing( float price, int quantity) {
	float total;
	total = 0;
	total = (price * 0.06) * quantity;
	return total;
}
