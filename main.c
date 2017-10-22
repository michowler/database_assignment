/*------------------------------------------------------------------- */
/* ITS62804– Assignment #1 */
/* Principles of Programming */
/* Student Name: <Michelle Ler Hsin Yee>, <Vikneesh a/l Ganesan> */
/* Student ID: <0333120>, <0331831> */
/*------------------------------------------------------------------- */

//prototype of libraries used
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "header.c"

int main(void) {	
	order(); //entry function
	return 0;
}

void order() {
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

		printf("Please enter order option (1-7): "); //infinity loop occurs when entered float
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
				exit(0);
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
			    printf("--------------------------------\n");//list of daily transaction
			    printf("   Daily Transactions\n");
				printf("--------------------------------\n");
				printf("Total combo meal transaction : %d\n", csum.combo_trans);
				printf("Total ala-carte transaction : %d\n", asum.ala_trans);
				printf("Total sales : RM %.2f\n", sum.grand_total);				
				printf("GST collected : RM %.2f\n", sum.grand_total * 0.06);
				puts("------------------------------------");
				break;	
			case 7:
				printf("^o^ Thanks for coming! ^o^ \n");
				exit(0);
				break;			
			default:
				printf("Invalid order!");
		}

	} while (order_number != 7);						
}

//function to print_order
void print_order(int quantity, char *item, float price, float total) {
	puts("-----------------------------------------------------");									
	puts("|Qty|\t\t|Item|\t\t\t\t|Price|");
	puts("-----------------------------------------------------");									
	printf("%-15u%-27s RM %-17.2f\n", quantity, item, price);
	puts("-----------------------------------------------------");									
	printf("Total (excl gst) : RM %.2f\n", total);	
}

void print_receipt(){
	FILE *fp; //pointer for receipt txt file
	int i, trans;
	char text_file[250];	
	fp = fopen("receipt.txt", "r"); 
	trans = asum.ala_trans + csum.combo_trans;

	puts("----------------------------------------------------------");
	puts(" ----------------------YOUR RECEIPT---------------------- ");
	puts("----------------------------------------------------------");
	puts ("QTY\t|\tITEM\t\t\t|\tPRICE");

	for (i = 0; i < trans; i++) {
		fgets(text_file, 250, (FILE*)fp);
		printf("%s\n", text_file);
	}

	// printf("6%% GST : RM %.2f\n", (sum.total * 1.06) * 0.06);
	// printf("Subtotal (excl gst) : RM %.2f\n",sum.total);
	// printf("Subtotal (incl gst): RM %.2f\n", sum.total * 1.06);	

	puts("----------------------------------------------------------");
	puts(" -----------------THANKS FOR PURCHASING------------------ ");
	puts("----------------------------------------------------------");
}

//function to purchase a meal
int purchase_meal() {
	FILE *fptr; //flie pointer for receipt text file
	char meal_choice[5]; //user input meal code
	char *item;
	float price;
	unsigned int quantity=0;	
	float total=0, grand_total=0;	
	
	while(strcmp(meal_choice, "-1") != 0) {		

		printf("Please enter a meal order option (-1 to exit). Example: C0001.\n");		
		scanf("%s", meal_choice);

		if (meal_choice[0] == '-' && meal_choice[1] == '1') {	//when input sentinel value then print receipt and go back to menu
			print_receipt();				
			order();
		} 
		else if (strlen(meal_choice) == 5 && meal_choice[0] == 'C' && meal_choice[1] == '0' && meal_choice[2] == '0' && meal_choice[3] == '0'){
			printf("Enter quantity of order. \n");
			scanf("%d", &quantity);
			
			fptr = fopen("receipt.txt", "a+"); //opens receipt txt file and appends
			if(fptr == NULL) //check whether the file is empty or not
			{
				printf("File cannot be found\n");
				
			} 
			else {				
				switch (meal_choice[4]) {											
					case '1': // assuming they chose combo 1 with code C0001 				
						price = combo1.price;				
						item = combo1.name;											
						total = combo1.price * quantity;
						grand_total += total;						
						csum.combo_trans++;
						fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, combo1.name, combo1.price);					
						print_order(quantity, item, price, grand_total);				
					    break;
					case '2':
						price = combo2.price;
						item = combo2.name;						
						total = combo2.price * quantity;
						grand_total += total;						
						csum.combo_trans++;																				
						fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, combo2.name, combo2.price);
						print_order(quantity, item, price, grand_total);						    
					    break;
					case '3':
						price = combo3.price;
						item = combo3.name;						
						total = combo3.price * quantity;
						grand_total += total;					
						csum.combo_trans++;																							
						fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, combo3.name, combo3.price);
						print_order(quantity, item, price, grand_total);						    
					    break;
					case '4':
						price = combo4.price;
						item = combo4.name;						
						total = combo4.price * quantity;
						grand_total += total;						
						csum.combo_trans++;							
						fprintf(fptr, "%-15u%-40s%-17.2f\n", quantity, combo4.name, combo4.price);
						print_order(quantity, item, price, grand_total);					    
					    break;
					case '5':
						price = combo5.price;
						item = combo5.name;						
						total = combo5.price * quantity;
						grand_total += total;						
						csum.combo_trans++;																
						fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, combo5.name, combo5.price);
						print_order(quantity, item, price, grand_total);					    
					    break;		     
					default:
						total =0;																	
				}					
				fclose(fptr); //close the file				
			}		
		} 
		else if (strlen(meal_choice) == 5 && meal_choice[0] == 'A' && meal_choice[1] == '0' && meal_choice[2] == '0' && meal_choice[3] == '0') {
			printf("Enter quantity of order. \n");
			scanf("%d", &quantity);

			fptr = fopen("receipt.txt", "a"); //opens txt file and READS only
			if(fptr == NULL) //check whether the file is empty or not
			{
				printf("File cannot be found\n");
				
			} else {				
				switch (meal_choice[4]) {											
					case '1': 			// assuming they chose set 1 with code C0001 
						price = addon1.price;				
						item = addon1.name;									
						total = addon1.price * quantity;
						asum.ala_trans++;
						grand_total += total;																															
						fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, addon1.name, addon1.price);					
						print_order(quantity, item, price, grand_total);				
					    break;
					case '2':
						price = addon2.price;
						item = addon2.name;						
						total = addon2.price * quantity;
						asum.ala_trans++;
						grand_total += total;																																	
						fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, addon2.name, addon2.price);
						print_order(quantity, item, price, grand_total);						    
					    break;
					case '3':
						price = addon3.price;
						item = addon3.name;						
						total = addon3.price * quantity;
						asum.ala_trans++;
						grand_total += total;																									
						fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, addon3.name, addon3.price);
						print_order(quantity, item, price, grand_total);						    
					    break;
					case '4':
						price = addon4.price;
						item = addon4.name;						
						total = addon4.price * quantity;						
						asum.ala_trans++;
						grand_total += total;																									
						fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, addon4.name, addon4.price);
						print_order(quantity, item, price, grand_total);					    
					    break;
					case '5':
						price = addon5.price;
						item = addon5.name;						
						total = addon5.price * quantity;
						asum.ala_trans++;
						grand_total += total;																											
						fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, addon5.name, addon5.price);
						print_order(quantity, item, price, grand_total);					    
					    break;		     
					default:
						total =0;													
				}		
				fclose(fptr); //close the file												
			} //end else for file found			
		} else {
			quantity = 0; //declare quantity 0 because to prevent dummy data
			price = 0; //declare price of certain order 0 because to prevent added into total
			total =0; //declare total in order 0 because to prevent added into grand total
			printf("Invalid meal code. \n");
		} //end else for menu option A or C			
		sum.total = grand_total;
		sum.grand_total += total;					
	} //end of while loop		
	return 0;
}

//function to display all combo meals available
int show_combo_meals() {		
   FILE *cfp; //pointer for combo text file
   char text_file[250];

   cfp = fopen("combo.txt", "r"); //opens txt file and READS only

   puts("----------------------------------------------------");
   puts("----------------COMBO MEALS------------------------");
   puts("----------------------------------------------------");
   fscanf(cfp, "%5[^:]:%[^:]:%f:%[^\n]\n", combo1.code, combo1.name, &combo1.price, combo1.description);
   fscanf(cfp, "%5[^:]:%[^:]:%f:%[^\n]\n", combo2.code, combo2.name, &combo2.price, combo2.description);
   fscanf(cfp, "%5[^:]:%[^:]:%f:%[^\n]\n", combo3.code, combo3.name, &combo3.price, combo3.description);
   fscanf(cfp, "%5[^:]:%[^:]:%f:%[^\n]\n", combo4.code, combo4.name, &combo4.price, combo4.description);
   fscanf(cfp, "%5[^:]:%[^:]:%f:%[^\n]\n", combo5.code, combo5.name, &combo5.price, combo5.description);

   if ((cfp = fopen("combo.txt", "r"))== NULL)
    {
       puts("File could not be found");
    } else {
    	printf("Code  : %s\n",combo1.code);
    	printf("Name     : %s\n",combo1.name);
    	printf("Price    : RM %.2f\n",combo1.price);
    	printf("Description    : %s\n",combo1.description);
    	printf("---------------------------------------\n");
    	printf("Code  : %s\n",combo2.code);
    	printf("Name     : %s\n",combo2.name);
    	printf("Price    : RM %.2f\n",combo2.price);
    	printf("Description    : %s\n",combo2.description);
    	printf("---------------------------------------\n");   
    	printf("Code  : %s\n",combo3.code);
    	printf("Name     : %s\n",combo3.name);
    	printf("Price    : RM %.2f\n",combo3.price);
    	printf("Description    : %s\n",combo3.description);
    	printf("---------------------------------------\n");
    	printf("Code  : %s\n",combo4.code);
    	printf("Name     : %s\n",combo4.name);
    	printf("Price    : RM %.2f\n",combo4.price);
    	printf("Description    : %s\n",combo4.description);
    	printf("---------------------------------------\n");
    	printf("Code  : %s\n",combo5.code);
    	printf("Name     : %s\n",combo5.name);
    	printf("Price    : RM %.2f\n",combo5.price);
    	printf("Description    : %s\n",combo5.description);
    }  
   puts("------------------------------------------------------------------------------\n");
   fclose(cfp); //close the file
   return 0;
}

int show_addon() {
   FILE *afp; //pointer for addon text file
   char text_file[250];

   afp = fopen("addon.txt", "r"); //opens txt file and READS only

   puts("----------------------------------------------------");
   puts(" --------------------ADD-ONS----------------------- ");
   puts("----------------------------------------------------");

   // printf("%s\n", text_file );
   fscanf(afp, "%5[^:]:%[^:]:%f:%[^\n]\n", addon1.code, addon1.name, &addon1.price, addon1.description);
   fscanf(afp, "%5[^:]:%[^:]:%f:%[^\n]\n", addon2.code, addon2.name, &addon2.price, addon2.description);
   fscanf(afp, "%5[^:]:%[^:]:%f:%[^\n]\n", addon3.code, addon3.name, &addon3.price, addon3.description);
   fscanf(afp, "%5[^:]:%[^:]:%f:%[^\n]\n", addon4.code, addon4.name, &addon4.price, addon4.description);
   fscanf(afp, "%5[^:]:%[^:]:%f:%[^\n]\n", addon5.code, addon5.name, &addon5.price, addon5.description);

   if ((afp = fopen("addon.txt", "r"))== NULL)
   {
       puts("File could not be found");
    } else {     
	   printf("Code  : %s\n",addon1.code);
	   printf("Name     : %s\n",addon1.name);
	   printf("Price    : RM %.2f\n",addon1.price);
	   printf("Description    : %s\n",addon1.description);
	   printf("---------------------------------------\n");
	   printf("Code  : %s\n",addon2.code);
	   printf("Name     : %s\n",addon2.name);
	   printf("Price    : RM %.2f\n",addon2.price);
	   printf("Description    : %s\n",addon2.description);
	   printf("---------------------------------------\n");   
	   printf("Code  : %s\n",addon3.code);
	   printf("Name     : %s\n",addon3.name);
	   printf("Price    : RM %.2f\n",addon3.price);
	   printf("Description    : %s\n",addon3.description);
	   printf("---------------------------------------\n");
	   printf("Code  : %s\n",addon4.code);
	   printf("Name     : %s\n",addon4.name);
	   printf("Price    : RM %.2f\n",addon4.price);
	   printf("Description    : %s\n",addon4.description);
	   printf("---------------------------------------\n");
	   printf("Code  : %s\n",addon5.code);
	   printf("Name     : %s\n",addon5.name);
	   printf("Price    : RM %.2f\n",addon5.price);
	   printf("Description    : %s\n",addon5.description);
    }  
   puts("------------------------------------------------------------------------------");

   fclose(afp); //close txt file
   return 0;
}
