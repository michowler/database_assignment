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

int order(), show_combo_meals(), show_addon(), purchase_meal(), daily_transactions();
float taxing( float price, int quantity);

struct Combo {
	float price;	
	char code[5];
	char description[100];
	char name[50];	
	int combo_trans;	

} combo1, combo2, combo3, combo4, combo5, csum;

struct Addon {
	float price;	
	char code[5];
	char description[100];
	char name[50];		
	int ala_trans;

} addon1, addon2, addon3, addon4, addon5, asum;

struct Meal {
	float total;
	float tax;	
} sum;

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
				show_addon();
				purchase_meal();

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
				puts("------------------------------------");
				printf("Total combo meal transaction : %d\n", csum.combo_trans);
				printf("Total ala-carte transaction : %d\n", asum.ala_trans);
				printf("Total sales : RM %.2f\n", sum.total);
				printf("GST collected : RM %.2f\n", sum.tax);
				puts("------------------------------------");
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

//function to print_order
void print_order(int quantity, char *item, float price, float total) {
	puts("-----------------------------------------------------");									
	puts("|Qty|\t|Item|\t\t\t\t|Price|");
	puts("-----------------------------------------------------");									
	printf("%d\t%s\t\tRM %.2f\n", quantity, item, price);
	puts("-----------------------------------------------------");									
	printf("Total (incl gst): RM %.2f\n", total);	
}


// to calculate the total with tax
float taxing( float price, int quantity) {
	float total;
	total = 0;
	total = (price * 0.06) * quantity;
	return total;
}

//function to purchase a meal
int purchase_meal() {

	FILE *fptr;	
	fptr = fopen("receipt.txt", "a"); //opens txt file and READS only

	char meal_choice[5];
	char *item;
	float price, sumtax, tax;
	int quantity;
	float total = 0, grand_total = 0;		
	
	while (meal_choice[0] != '-') {

		printf("What and how many would you like to purchase? Example: C0001 2 \n");
		scanf("%s %d", meal_choice, &quantity);

		if (meal_choice[0] == '-' && meal_choice[1] == '1') {
			puts("-----------------------------------------------------");	
			//print_order(quantity=0, item, price=grand_total, total=grand_total);
			printf("Total (incl gst) : %.2f\n", grand_total);
			order();
		} 
		else if (meal_choice[0] == 'C') {			
			switch (meal_choice[4]) {											
				case '1': 			// assuming they chose set 1 with code C0001 
					price = combo1.price;				
					item = combo1.name;
					tax = taxing(combo1.price, quantity);					
					total = (combo1.price * quantity) + tax;
					grand_total += total;
					sumtax += tax;
					csum.combo_trans++;
					sum.total = grand_total;
					sum.tax = sumtax;

					//fprintf(fptr, "%d\t:%s\t\t:%.2f\n", quantity, combo1.name, combo1.price);
					print_order(quantity, item, price, grand_total);				

				    break;
				case '2':
					price = combo2.price;
					item = combo2.name;
					tax = taxing(combo2.price, quantity);
					total = (combo2.price * quantity) + tax;
					grand_total += total;
					sumtax += tax;
					csum.combo_trans++;
					sum.total = grand_total;
					sum.tax = sumtax;
					
					print_order(quantity, item, price, grand_total);	
				    
				    break;
				case '3':
					price = combo3.price;
					item = combo3.name;
					tax = taxing(combo3.price, quantity);
					total = (combo3.price * quantity) + tax;
					grand_total += total;
					sumtax += tax;
					csum.combo_trans++;
					sum.total = grand_total;
					sum.tax = sumtax;
					
					print_order(quantity, item, price, grand_total);	
				    
				    
				    break;
				case '4':
					price = combo4.price;
					item = combo4.name;
					tax = taxing(combo4.price, quantity);
					total = (combo4.price * quantity) + tax;
					grand_total += total;
					sumtax += tax;
					csum.combo_trans++;
					sum.total = grand_total;
					sum.tax = sumtax;
					
					print_order(quantity, item, price, grand_total);
				    
				    break;
				case '5':
					price = combo5.price;
					item = combo5.name;
					tax = taxing(combo5.price, quantity);
					total = (combo5.price * quantity) + tax;
					grand_total += total;
					sumtax += tax;
					csum.combo_trans++;
					sum.total = grand_total;
					sum.tax = sumtax;
					
					print_order(quantity, item, price, grand_total);
				    
				    break;		     
				default:
					puts("Invalid meal option!");
					grand_total += total;
					sumtax += tax;
					sum.total = grand_total;
					sum.tax = sumtax;

					print_order(quantity, item, price, grand_total);

			}		

		} 
		else if (meal_choice[0] == 'A') {
			switch (meal_choice[4]) {											
				case '1': 			// assuming they chose set 1 with code C0001 
					price = addon1.price;				
					item = addon1.name;
					tax = taxing(addon1.price, quantity);					
					total = (addon1.price * quantity) + tax;
					grand_total += total;
					sumtax += tax;
					asum.ala_trans++;
					sum.total = grand_total;
					sum.tax = sumtax;

					//fprintf(fptr, "%d\t:%s\t\t:%.2f\n", quantity, addon1.name, addon1.price);
					print_order(quantity, item, price, grand_total);				

				    break;
				case '2':
					price = addon2.price;
					item = addon2.name;
					tax = taxing(addon2.price, quantity);
					total = (addon2.price * quantity) + tax;
					grand_total += total;
					sumtax += tax;
					asum.ala_trans++;
					sum.total = grand_total;
					sum.tax = sumtax;
					
					print_order(quantity, item, price, grand_total);	
				    
				    break;
				case '3':
					price = addon3.price;
					item = addon3.name;
					tax = taxing(addon3.price, quantity);
					total = (addon3.price * quantity) + tax;
					grand_total += total;
					sumtax += tax;
					asum.ala_trans++;
					sum.total = grand_total;
					sum.tax = sumtax;
					
					print_order(quantity, item, price, grand_total);	
				    
				    
				    break;
				case '4':
					price = addon4.price;
					item = addon4.name;
					tax = taxing(addon4.price, quantity);
					total = (addon4.price * quantity) + tax;
					grand_total += total;
					sumtax += tax;
					asum.ala_trans++;
					sum.total = grand_total;
					sum.tax = sumtax;
					
					print_order(quantity, item, price, grand_total);
				    
				    break;
				case '5':
					price = addon5.price;
					item = addon5.name;
					tax = taxing(addon5.price, quantity);
					total = (addon5.price * quantity) + tax;
					grand_total += total;
					sumtax += tax;
					asum.ala_trans++;
					sum.total = grand_total;
					sum.tax = sumtax;
					
					print_order(quantity, item, price, grand_total);
				    
				    break;		     
				default:
					puts("Invalid meal option!");
					grand_total += total;
					sumtax += tax;
					sum.total = grand_total;
					sum.tax = sumtax;

					print_order(quantity, item, price, grand_total);

			}		
											
		}	
		
	}	

	fclose(fptr); //close the file
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

   fscanf(fp, "%[^:]:%[^:]:%f:%[^ ]\n", combo1.code, combo1.name, &combo1.price, combo1.description);
   fscanf(fp, "\n%[^:]:%[^:]:%f:%[^ ]\n", combo2.code, combo2.name, &combo2.price, combo2.description);
   fscanf(fp, "\n%[^:]:%[^:]:%f:%[^ ]\n", combo3.code, combo3.name, &combo3.price, combo3.description);
   fscanf(fp, "\n%[^:]:%[^:]:%f:%[^ ]\n", combo4.code, combo4.name, &combo4.price, combo4.description);
   fscanf(fp, "\n%[^:]:%[^:]:%f:%[^ ]\n", combo5.code, combo5.name, &combo5.price, combo5.description);

   printf("Code  :%s\n",combo1.code);
   printf("Name     :%s\n",combo1.name);
   printf("Price    :RM%.2f\n",combo1.price);
   printf("Description    :%s\n",combo1.description);
   printf("---------------------------------------\n");
   printf("Code  :%s\n",combo2.code);
   printf("Name     :%s\n",combo2.name);
   printf("Price    :RM%.2f\n",combo2.price);
   printf("Description    :%s\n",combo2.description);
   printf("---------------------------------------\n");   
   printf("Code  :%s\n",combo3.code);
   printf("Name     :%s\n",combo3.name);
   printf("Price    :RM%.2f\n",combo3.price);
   printf("Description    :%s\n",combo3.description);
   printf("---------------------------------------\n");
   printf("Code  :%s\n",combo4.code);
   printf("Name     :%s\n",combo4.name);
   printf("Price    :RM%.2f\n",combo4.price);
   printf("Description    :%s\n",combo4.description);
   printf("---------------------------------------\n");
   printf("Code  :%s\n",combo5.code);
   printf("Name     :%s\n",combo5.name);
   printf("Price    :RM%.2f\n",combo5.price);
   printf("Description    :%s\n",combo5.description);
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

   printf("%s\n", text_file );
   fscanf(fp, "%[^:]:%[^:]:%f:%[^ ]\n", addon1.code, addon1.name, &addon1.price, addon1.description);
   fscanf(fp, "\n%[^:]:%[^:]:%f:%[^ ]\n", addon2.code, addon2.name, &addon2.price, addon2.description);
   fscanf(fp, "\n%[^:]:%[^:]:%f:%[^ ]\n", addon3.code, addon3.name, &addon3.price, addon3.description);
   fscanf(fp, "\n%[^:]:%[^:]:%f:%[^ ]\n", addon4.code, addon4.name, &addon4.price, addon4.description);
   fscanf(fp, "\n%[^:]:%[^:]:%f:%[^ ]\n", addon5.code, addon5.name, &addon5.price, addon5.description);

   printf("Code  :%s\n",addon1.code);
   printf("Name     :%s\n",addon1.name);
   printf("Price    :RM%.2f\n",addon1.price);
   printf("Description    :%s\n",addon1.description);
   printf("---------------------------------------\n");
   printf("Code  :%s\n",addon2.code);
   printf("Name     :%s\n",addon2.name);
   printf("Price    :RM%.2f\n",addon2.price);
   printf("Description    :%s\n",addon2.description);
   printf("---------------------------------------\n");   
   printf("Code  :%s\n",addon3.code);
   printf("Name     :%s\n",addon3.name);
   printf("Price    :RM%.2f\n",addon3.price);
   printf("Description    :%s\n",addon3.description);
   printf("---------------------------------------\n");
   printf("Code  :%s\n",addon4.code);
   printf("Name     :%s\n",addon4.name);
   printf("Price    :RM%.2f\n",addon4.price);
   printf("Description    :%s\n",addon4.description);
   printf("---------------------------------------\n");
   printf("Code  :%s\n",addon5.code);
   printf("Name     :%s\n",addon5.name);
   printf("Price    :RM%.2f\n",addon5.price);
   printf("Description    :%s\n",addon5.description);
   printf("---------------------------------------\n");
   puts("----------------------------------------------");

   fclose(fp); //close txt file
   return 0;

}
