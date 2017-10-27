/*------------------------------------------------------------------- */
/* ITS62804– Assignment #1 */
/* Principles of Programming */
/* Student Name: <Michelle Ler Hsin Yee>, <Vikneesh a/l Ganesan> */
/* Student ID: <0333120>, <0324370> */
/*------------------------------------------------------------------- */

//prototype of libraries used
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

//prototype of functions used
int print_menu(char meal_code[6], char meal_name[25], double meal_price, char meal_description[100]);
void daily_transactions(int combo_trans, int ala_trans, float grand_total);
void order(), print_order(int quantity, char *item, float price, float total), print_receipt(int combo_trans, int ala_trans, float total);

int main(void) {		
	order(); //entry function
	return 0;
}

void daily_transactions(int combo_trans, int ala_trans, float grand_total){
    printf("--------------------------------\n");
    printf("   Daily Transactions\n");
	printf("--------------------------------\n");
	printf("Total combo meal transaction : %d\n", combo_trans);
	printf("Total ala-carte transaction : %d\n", ala_trans);
	printf("Total sales : RM %.2f\n", grand_total);				
	printf("GST collected : RM %.2f\n", grand_total * 0.06);
	puts("------------------------------------");
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

//function to print_receipt at the end (-1) of purchase 
void print_receipt(int combo_trans, int ala_trans, float total){
	FILE *fp; //pointer for receipt txt file
	int i, trans;
	char text_file[250];	
	fp = fopen("receipt.txt", "r"); 
	trans = ala_trans + combo_trans;

	puts("----------------------------------------------------------");
	puts(" ----------------------YOUR RECEIPT---------------------- ");
	puts("----------------------------------------------------------");
	puts ("QTY\t|\tITEM\t\t\t|\tPRICE");

	for (i = 0; i < trans; i++) {
		fgets(text_file, 250, (FILE*)fp);
		printf("%s\n", text_file);
	}

	printf("6%% GST : RM %.2f\n", (total * 1.06) * 0.06);
	printf("Subtotal (excl gst) : RM %.2f\n",total);
	printf("Subtotal (incl gst): RM %.2f\n", total * 1.06);	

	puts("----------------------------------------------------------");
	puts(" -----------------THANKS FOR PURCHASING------------------ ");
	puts("----------------------------------------------------------");
}

//function to display all combo meals available
int print_menu(char meal_code[6], char meal_name[25], double meal_price, char meal_description[100]){
	
	int i;
	FILE *cfp; //pointer for combo text file
	FILE *afp; //pointer for addon text file      

	puts("------------------------------------------------------------------------------");
	puts("---------------------------------COMBO MEALS----------------------------------");
	puts("------------------------------------------------------------------------------");

	if ((cfp = fopen("combo.txt", "r"))== NULL)
	{
	   puts("File could not be found");
	} else {
		for (i=0; i< 5; i++){
			fscanf(cfp, "%[^:]:%[^:]:%lf:%[^\n]\n", meal_code,meal_name,&meal_price,meal_description);			
			printf("%-15s%-27s%-17.2f%-12s\n", meal_code,meal_name,&meal_price,meal_description);				
		}    
	} 
	puts("------------------------------------------------------------------------------\n");
	fclose(cfp); //close the file   

	puts("------------------------------------------------------------------------------");
	puts(" -----------------------------------ADD-ONS---------------------------------- ");
	puts("------------------------------------------------------------------------------");

	if ((afp = fopen("addon.txt", "r"))== NULL)
	{
	   puts("File could not be found");
	} else {
		for (i=0; i< 5; i++){
			fscanf(cfp, "%[^:]:%[^:]:%lf:%[^\n]\n", meal_code,meal_name,&meal_price,meal_description);			
			printf("%-15s%-27s%-17.2f%-12s\n", meal_code,meal_name,&meal_price,meal_description);	
		}    
	}  
	puts("------------------------------------------------------------------------------");
	fclose(afp); //close txt file
	return 0;
}

void order() {
	FILE *fptr; //flie pointer for receipt text file
	FILE *mfptr; //flie pointer for combo text file
	FILE *afptr; //flie pointer for addon text file
	unsigned int order_number; //declared variable to store order values	
	char meal_choice[6]; //user input meal code	
	unsigned int quantity=0, i;	
	float total=0, grand_total=0;	
	unsigned int combo_trans=0, ala_trans=0;
	
	char meal_code[6];
	char meal_name[25];
	double meal_price;
	char meal_description[100];

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
		puts("------------------------------------");

		printf("Please enter order option (1-7): "); //infinity loop occurs when entered float
		scanf("%d", &order_number);

		while (order_number > 7 || order_number < 1) {
			printf("Please enter a valid order option (1-7): ");
			scanf("%d", &order_number);		
		} 
		//prompt user for purchase again until enters exit option (7)
		switch(order_number) {
			case 1:				
				fptr = fopen("receipt.txt", "w");
				
				while(strcmp(meal_choice, "-1") != 0) {		
					printf("Please enter a meal code (-1 to exit purchase). Example: C0001.\n");		
					scanf("%s", meal_choice);

					if (meal_choice[0] == '-' && meal_choice[1] == '1') {	//when input sentinel value then print receipt and go back to menu
						print_receipt(combo_trans, ala_trans, grand_total);				
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
									mfptr = fopen("combo.txt", "r");
									for (i=0; i<2; i++){
										fscanf(mfptr, "%5[^:]:%[^:]:%lf:%[^\n]\n", meal_code, meal_name, &meal_price, meal_description);	
									}																											
									total = meal_price * quantity;
									grand_total += total;																	
									fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, meal_name, meal_price);					
									print_order(quantity, meal_name, meal_price, grand_total);
									fclose(mfptr);	
									combo_trans++;			
								    break;
								case '2':
									mfptr = fopen("combo.txt", "r");
									for (i=0; i<3; i++){
										fscanf(mfptr, "%5[^:]:%[^:]:%lf:%[^\n]\n", meal_code, meal_name, &meal_price, meal_description);	
									}						
									total = meal_price * quantity;
									grand_total += total;				
									combo_trans++;																				
									fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, meal_name, meal_price);					
									print_order(quantity, meal_name, meal_price, grand_total);					    
									fclose(mfptr);	
								    break;
								case '3':
									mfptr = fopen("combo.txt", "r");
									for (i=0; i<4; i++){
										fscanf(mfptr, "%5[^:]:%[^:]:%lf:%[^\n]\n", meal_code, meal_name, &meal_price, meal_description);	
									}						
									total = meal_price * quantity;
									grand_total += total;				
									combo_trans++;																							
									fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, meal_name, meal_price);					
									print_order(quantity, meal_name, meal_price, grand_total);
									fclose(mfptr);							    
								    break;
								case '4':
									mfptr = fopen("combo.txt", "r");
									for (i=0; i<5; i++){
										fscanf(mfptr, "%5[^:]:%[^:]:%lf:%[^\n]\n", meal_code, meal_name, &meal_price, meal_description);	
									}							
									total = meal_price * quantity;
									grand_total += total;				
									combo_trans++;							
									fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, meal_name, meal_price);					
									print_order(quantity, meal_name, meal_price, grand_total);
									fclose(mfptr);						    
								    break;
								case '5':
									mfptr = fopen("combo.txt", "r");
									for (i=0; i<6; i++){
										fscanf(mfptr, "%5[^:]:%[^:]:%lf:%[^\n]\n", meal_code, meal_name, &meal_price, meal_description);	
									}							
									total = meal_price * quantity;
									grand_total += total;				
									combo_trans++;																
									fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, meal_name, meal_price);					
									print_order(quantity, meal_name, meal_price, grand_total);
									fclose(mfptr);						    
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
									afptr = fopen("addon.txt", "r");
									for (i=0; i<2; i++){
										fscanf(afptr, "%5[^:]:%[^:]:%lf:%[^\n]\n", meal_code, meal_name, &meal_price, meal_description);	
									}		
									total = meal_price * quantity;
									ala_trans++;
									grand_total += total;																															
									fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, meal_name, meal_price);					
									print_order(quantity, meal_name, meal_price, grand_total);				
									fclose(afptr);	
								    break;
								case '2':
									afptr = fopen("addon.txt", "r");
									for (i=0; i<3; i++){
										fscanf(afptr, "%5[^:]:%[^:]:%lf:%[^\n]\n", meal_code, meal_name, &meal_price, meal_description);	
									}							
									total = meal_price * quantity;
									ala_trans++;
									grand_total += total;																															
									fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, meal_name, meal_price);
									print_order(quantity, meal_name, meal_price, grand_total);
									fclose(afptr);	
								    break;
								case '3':
									afptr = fopen("addon.txt", "r");
									for (i=0; i<4; i++){
										fscanf(afptr, "%5[^:]:%[^:]:%lf:%[^\n]\n", meal_code, meal_name, &meal_price, meal_description);	
									}						
									total = meal_price * quantity;
									ala_trans++;
									grand_total += total;	
									fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, meal_name, meal_price);
									print_order(quantity, meal_name, meal_price, grand_total);						    
									fclose(afptr);
								    break;
								case '4':
									afptr = fopen("addon.txt", "r");
									for (i=0; i<5; i++){
										fscanf(afptr, "%5[^:]:%[^:]:%lf:%[^\n]\n", meal_code, meal_name, &meal_price, meal_description);	
									}						
									total = meal_price * quantity;						
									ala_trans++;
									grand_total += total;																								
									fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, meal_name, meal_price);
									print_order(quantity, meal_name, meal_price, grand_total);					    
									fclose(afptr);
								    break;
								case '5':
									afptr = fopen("addon.txt", "r");
									for (i=0; i<6; i++){
										fscanf(afptr, "%5[^:]:%[^:]:%lf:%[^\n]\n", meal_code, meal_name, &meal_price, meal_description);	
									}					
									total = meal_price * quantity;
									ala_trans++;
									grand_total += total;																							
									fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, meal_name, meal_price);
									print_order(quantity, meal_name, meal_price, grand_total);	
									fclose(afptr);				    
								    break;		     
								default:
									total =0;													
							}		
							fclose(fptr); //close the file												
						} //end else for file found			
					} else {
						//quantity = 0; //declare quantity 0 because to prevent dummy data
						//price = 0; //declare price of certain order 0 because to prevent added into total
						//total = 0; //declare total in order 0 because to prevent added into grand total
						printf("Invalid item. \n");
					} //end else for menu option A or C			
					//grand_total += total;	
				} //end of while loop					
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
				print_menu(meal_code, meal_name, meal_price, meal_description);										
				break;		
			case 6:
		        daily_transactions(combo_trans, ala_trans, grand_total);	      
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
