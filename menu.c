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

	do {

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
				
				//printf("Total combo meal transaction : %d\n", combo_trans);
				//printf("Total ala-carte transaction : %d\n", ala_trans);
				//printf("Total sales : %.2f\n", grand_total);

				// printf("GST collected : %.2f\n", sumgst);
				break;	
			case 7:
				break;			
			default:
				printf("Invalid order!");
		}

	} while (order_number != 7);

	printf("Thanks for coming!\n");				

	return 0;
}

//function to print_receipt
void print_receipt(int quantity, char *item, float price, float total) {
	puts("-----------------------------------------------------");									
	puts("|Qty|\t|Item|\t\t\t\t|Price|");
	puts("-----------------------------------------------------");									
	printf("%d\t%s\t\tRM %.2f\n", quantity, item, price);
	puts("-----------------------------------------------------");									
	printf("TOTAL: RM %.2f\n", total);	
}

//function to purchase a meal
int purchase_meal() {

	char meal_choice[5];
	char *item;
	float price, sumtax, tax;
	int quantity;
	float total = 0, grand_total = 0;	
	int *combo_trans, *ala_trans;

	grand_total += total;
	sumtax += tax;
	
	
	do {
		printf("What would you like to purchase and how many?\n");
		scanf("%s", meal_choice);
		printf("%c\n", meal_choice[0]);	
		printf("How many would you like to purchase?\n");
		scanf("%d", &quantity);	

		if (meal_choice[0] == '-') {
			order();
		}
		else {
				switch (meal_choice[4]) {			
					
					//sumtax+=tax;
					case '1': 			// assuming they chose set 1 with code C0001 
						price = meal1.price;				
						item = meal1.name;
						tax = taxing(meal1.price, quantity);
						total = (meal1.price * quantity) + tax;
						grand_total += total;
						combo_trans++;

						print_receipt(quantity, item, price, total);				

					    break;
					case '2':
						price = meal2.price;
						item = meal2.name;
						tax = taxing(meal2.price, quantity);
						total = (meal2.price * quantity) + tax;
						grand_total += total;
						combo_trans++;
						
						print_receipt(quantity, item, price, grand_total);	
					    
					    break;
					case '3':
						price = meal3.price;
						item = meal3.name;
						tax = taxing(meal3.price, quantity);
						total = (meal3.price * quantity) + tax;
						grand_total += total;
						combo_trans++;
						
						print_receipt(quantity, item, price, grand_total);	
					    
					    
					    break;
					case '4':
						price = meal4.price;
						item = meal4.name;
						tax = taxing(meal4.price, quantity);
						total = (meal4.price * quantity) + tax;
						grand_total += total;
						combo_trans++;
						
						print_receipt(quantity, item, price, grand_total);
					    
					    break;
					case '5':
						price = meal5.price;
						item = meal5.name;
						tax = taxing(meal5.price, quantity);
						total = (meal5.price * quantity) + tax;
						grand_total += total;
						combo_trans++;
						
						print_receipt(quantity, item, price, grand_total);
					    
					    break;		     
					default:
						puts("Invalid meal option!");
						grand_total += total;

						print_receipt(quantity, item, price, grand_total);

				}
				grand_total += total;
			
		}	

	} while (meal_choice[0] != '-');		

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
   fscanf(fp, "\n%[^:]:%[^:]:%f:%[^ ]\n", meal4.code, meal4.name, &meal4.price, meal4.description);
   fscanf(fp, "\n%[^:]:%[^:]:%f:%[^ ]\n", meal5.code, meal5.name, &meal5.price, meal5.description);


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

   printf("---------------------------------------\n");
   printf("code  :%s\n",meal3.code);
   printf("Name     :%s\n",meal3.name);
   printf("Price    :RM%.2f\n",meal3.price);
   
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
	// int ala_trans, combo_trans;

	// if (meal_choice[0] == 'C') {
	// 	ala_trans++
	// } else if (meal_choice[0] == 'A') {
	// 	combo_trans++;
	// }
	// return 0;
 // }

// to calculate the total with tax
float taxing( float price, int quantity) {
	float total;
	total = 0;
	total = (price * 0.06) * quantity;
	return total;
}
