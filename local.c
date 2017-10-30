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
int print_menu(), purchase();
void daily_transactions(int combo_trans, int ala_trans, float grand_total);
void order(), print_order(int quantity, char *item, float price, float total), print_receipt(int combo_trans, int ala_trans, float total);

int main(void) {		
	order(); //entry function
	return 0;
}
//function to print_order
void print_order(int quantity, char *item, float price, float total) {	
	puts("***YOUR ORDER DETAILS***===================================================");	
	printf("%-10s%-30s%-20s%s\n", "|Qty|", "|Item|","|Meal Price|","|Total|");
	puts("--------------------------------------------------------------------------");								
	printf("%-10u%-32sRM %-15.2fRM %.2f\n", quantity, item, price, price*quantity);
	puts("--------------------------------------------------------------------------");								
	printf("Subtotal (excl gst) : RM %.2f\n", total);	
	puts("===========================================================================");
}

//function to print_receipt at the end (-1) of purchase 
void print_receipt(int combo_trans, int ala_trans, float total){
	FILE *fp; //pointer for receipt txt file
	int i, trans;
	char text_file[200];	

	fp = fopen("receipt.txt", "r"); 	
	trans = ala_trans + combo_trans; //calculate total trans to print out for each line	
	puts("----------------------------------------------------------");
	puts("=======================YOUR RECEIPT=======================");	
	puts("----------------------------------------------------------");
	puts ("QTY\t|\tITEM\t\t\t|\tPRICE(RM)");	
	for (i = 0; i < trans; i++) {
		fgets(text_file, 200, (FILE*)fp);
		printf("%s\n", text_file);
	}
	printf("Total Orders : %d\n", trans);
	printf("6%% GST : RM %.2f\n", (total * 1.06) * 0.06);
	printf("Subtotal (excl gst) : RM %.2f\n",total);
	printf("Subtotal (incl gst): RM %.2f\n", total * 1.06);	
	puts("----------------------------------------------------------");
	puts("===================THANKS FOR PURCHASING==================");
	puts("----------------------------------------------------------");
	fclose(fp);
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

//function to display menu
int print_menu(void){
	char meal_code[6], meal_name[25], meal_description[100];
	double meal_price;
	int i;
	FILE *cfp; //pointer for combo text file
	FILE *afp; //pointer for addon text file      

	puts("---------------------------------------------------------------------------------------------------------");
	puts("----------------------------------------COMBO MEALS------------------------------------------------------");
	puts("----------------------------------------------------------------------------------------------------------");
	printf("%-16s%-24s%-19s%-18s\n\n","Menu Code","Meal Name","Meal Price(RM)","Meal Description");
	if ((cfp = fopen("combo.txt", "r"))== NULL){
	   puts("File could not be found");
	} else {
		for (i=0; i< 5; i++){
			fscanf(cfp, "%[^:]:%[^:]:%lf:%[^\n]\n", meal_code,meal_name,&meal_price,meal_description);			
			printf("%-15s%-27s%-17.2f%-12s\n", meal_code,meal_name,meal_price,meal_description);				
		}    
	} 
	puts("----------------------------------------------------------------------------------------------------------\n");
	fclose(cfp); //close the file   

	puts("------------------------------------------------------------------------------");
	puts(" -----------------------------------ADD-ONS---------------------------------- ");
	puts("------------------------------------------------------------------------------");
	printf("%-16s%-24s%-19s%-18s\n\n","Menu Code","Meal Name","Meal Price(RM)","Meal Description");
	if ((afp = fopen("addon.txt", "r"))== NULL){
	   puts("File could not be found");
	} else {
		for (i=0; i< 5; i++){
			fscanf(cfp, "%[^:]:%[^:]:%lf:%[^\n]\n", meal_code,meal_name,&meal_price,meal_description);			
			printf("%-15s%-27s%-17.2f%-12s\n", meal_code,meal_name,meal_price,meal_description);	
		}    
	}  
	puts("------------------------------------------------------------------------------");
	fclose(afp); //close txt file
	return 0;
}

int purchase(void){
	char meal_choice[6]; //user input meal code	
	FILE *fptr; //flie pointer for receipt text file		
	FILE *tfptr; //flie pointer for trans text file	
	FILE *mfptr; //flie pointer for combo text file
	FILE *afptr; //flie pointer for addon text file
	int quantity=0; 	
	float total=0, grand_total=0;	
	unsigned int combo_trans=0, ala_trans=0, i;
	char meal_code[6];
	char meal_name[30];
	double meal_price;
	char meal_description[35];	

	fptr = fopen("receipt.txt", "w"); //clear file before appending for purchase		
	while(strcmp(meal_choice, "-1") != 0) {	//while user's meal code is not sentinel value -1
		printf("Please enter a meal code (-1 to exit purchase). Example: C0001.\n");		
		scanf("%s", meal_choice);
		
		tfptr = fopen("trans.txt", "a"); //open for appending by case
		if (strcmp(meal_choice, "-1") == 0){	//when input sentinel value then print receipt and go back to menu			
			print_receipt(combo_trans, ala_trans, grand_total);										
			order();
		} 		
		else if (strlen(meal_choice) == 5 && (meal_choice[0] == 'C' || meal_choice[0] =='c') && meal_choice[1] == '0' && meal_choice[2] == '0' && meal_choice[3] == '0' && meal_choice[4] >= '1' && meal_choice[4] <= '5'){
			printf("Enter quantity of order. \n");
			scanf("%d", &quantity); 					
			fptr = fopen("receipt.txt", "a"); 
			if( (mfptr = fopen("combo.txt", "r"))==NULL ){
				printf("File not found\n");
			}													
			else {				
				switch (meal_choice[4]) {											
					case '1': // assuming they chose combo 1 with code C0001 				
						mfptr = fopen("combo.txt", "r");
							for (i=0; i<1; i++){
								fscanf(mfptr, "%5[^:]:%[^:]:%lf:%[^\n]\n", meal_code, meal_name, &meal_price, meal_description);	
							}																																					
							total = meal_price * quantity; //speficic total
							grand_total += total; //speficic grand total
							if (quantity >= 1) { //prevent invalid data in receipt and trans
								combo_trans++;
								fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, meal_name, meal_price*quantity);																
								fprintf(tfptr, "%u:%u:%.2f\n", 1, 0, total); //append into file the trans and total			
								print_order(quantity, meal_name, meal_price, grand_total);
							}																							
						fclose(mfptr);									
					    break;
					case '2':
						mfptr = fopen("combo.txt", "r");
							for (i=0; i<2; i++){
								fscanf(mfptr, "%5[^:]:%[^:]:%lf:%[^\n]\n", meal_code, meal_name, &meal_price, meal_description);	
							}													
							total = meal_price * quantity;
							grand_total += total;																																	
							if (quantity >= 1) {
								combo_trans++;
								fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, meal_name, meal_price*quantity);																
								fprintf(tfptr, "%u:%u:%.2f\n", 1, 0, total);
								print_order(quantity, meal_name, meal_price, grand_total);
							}					    
						fclose(mfptr);							
					    break;
					case '3':
						mfptr = fopen("combo.txt", "r");
							for (i=0; i<3; i++){
								fscanf(mfptr, "%5[^:]:%[^:]:%lf:%[^\n]\n", meal_code, meal_name, &meal_price, meal_description);	
							}													
							total = meal_price * quantity;
							grand_total += total;																																
							if (quantity >= 1) {
								combo_trans++;
								fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, meal_name, meal_price*quantity);																
								fprintf(tfptr, "%u:%u:%.2f\n", 1, 0, total);
								print_order(quantity, meal_name, meal_price, grand_total);
							}		
						fclose(mfptr);							    
					    break;
					case '4':
						mfptr = fopen("combo.txt", "r");
							for (i=0; i<4; i++){
								fscanf(mfptr, "%5[^:]:%[^:]:%lf:%[^\n]\n", meal_code, meal_name, &meal_price, meal_description);	
							}													
							total = meal_price * quantity;
							grand_total += total;																	
							if (quantity >= 1) {
								combo_trans++;
								fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, meal_name, meal_price*quantity);																
								fprintf(tfptr, "%u:%u:%.2f\n", 1, 0, total);
								print_order(quantity, meal_name, meal_price, grand_total);
							}		
						fclose(mfptr);						    
					    break;
					case '5':
						mfptr = fopen("combo.txt", "r");
							for (i=0; i<5; i++){
								fscanf(mfptr, "%5[^:]:%[^:]:%lf:%[^\n]\n", meal_code, meal_name, &meal_price, meal_description);
							}														
							total = meal_price * quantity;
							grand_total += total;																									
							if (quantity >= 1) {
								combo_trans++;
								fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, meal_name, meal_price*quantity);																
								fprintf(tfptr, "%u:%u:%.2f\n", 1, 0, total);
								print_order(quantity, meal_name, meal_price, grand_total);
							}		
						fclose(mfptr);												    
					    break;		     
					default:
						total=0, combo_trans=0;																	
				}					
				fclose(fptr); //close the file				
			}		
		} 
		else if (strlen(meal_choice) == 5 && (meal_choice[0] == 'A' || meal_choice[0] =='a') && meal_choice[1] == '0' && meal_choice[2] == '0' && meal_choice[3] == '0' && meal_choice[4] >= '1' && meal_choice[4] <= '5') {
			printf("Enter quantity of order. \n");
			scanf("%d", &quantity); 	
			fptr = fopen("receipt.txt", "a"); 
			if( (afptr = fopen("addon.txt", "r"))==NULL ){
				printf("File not found\n");										
			} else {				
				switch (meal_choice[4]) {											
					case '1': 			// assuming they chose set 1 with code C0001 
						afptr = fopen("addon.txt", "r");
							for (i=0; i<1; i++){
								fscanf(afptr, "%5[^:]:%[^:]:%lf:%[^\n]\n", meal_code, meal_name, &meal_price, meal_description);	
							}								
							total = meal_price * quantity;						
							grand_total += total;																																			
							if (quantity >= 1) {
								ala_trans++;
								fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, meal_name, meal_price*quantity);																
								fprintf(tfptr, "%u:%u:%.2f\n", 0, 1, total); 
								print_order(quantity, meal_name, meal_price, grand_total);
							}				
						fclose(afptr);							
					    break;
					case '2':
						afptr = fopen("addon.txt", "r");
							for (i=0; i<2; i++){
								fscanf(afptr, "%5[^:]:%[^:]:%lf:%[^\n]\n", meal_code, meal_name, &meal_price, meal_description);	
							}													
							total = meal_price * quantity;						
							grand_total += total;																															
							if (quantity >= 1) {
								ala_trans++;
								fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, meal_name, meal_price*quantity);																
								fprintf(tfptr, "%u:%u:%.2f\n", 0, 1, total); 
								print_order(quantity, meal_name, meal_price, grand_total);
							}		
						fclose(afptr);							
					    break;
					case '3':
						afptr = fopen("addon.txt", "r");
							for (i=0; i<3; i++){							
								fscanf(afptr, "%5[^:]:%[^:]:%lf:%[^\n]\n", meal_code, meal_name, &meal_price, meal_description);	
							}													
							total = meal_price * quantity;						
							grand_total += total;							
							if (quantity >= 1) {
								ala_trans++;
								fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, meal_name, meal_price*quantity);																
								fprintf(tfptr, "%u:%u:%.2f\n", 0, 1, total); 
								print_order(quantity, meal_name, meal_price, grand_total);
							}						    						
						fclose(afptr);						
					    break;
					case '4':
						afptr = fopen("addon.txt", "r");
							for (i=0; i<4; i++){
								fscanf(afptr, "%5[^:]:%[^:]:%lf:%[^\n]\n", meal_code, meal_name, &meal_price, meal_description);	
							}													
							total = meal_price * quantity;												
							grand_total += total;																														
							if (quantity >= 1) {
								ala_trans++;
								fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, meal_name, meal_price*quantity);																
								fprintf(tfptr, "%u:%u:%.2f\n", 0, 1, total); 
								print_order(quantity, meal_name, meal_price, grand_total);
							}						    						
						fclose(afptr);						
					    break;
					case '5':
						afptr = fopen("addon.txt", "r");
							for (i=0; i<5; i++){
								fscanf(afptr, "%5[^:]:%[^:]:%lf:%[^\n]\n", meal_code, meal_name, &meal_price, meal_description);	
							}												
							total = meal_price * quantity;						
							grand_total += total;																												
							if (quantity >= 1) {
								ala_trans++;
								fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, meal_name, meal_price*quantity);																
								fprintf(tfptr, "%u:%u:%.2f\n", 0, 1, total);
								print_order(quantity, meal_name, meal_price, grand_total);
							}		
						fclose(afptr);									    
					    break;		     
					default:
						total=0, ala_trans=0;													
				}		
				fclose(fptr); //close the receipt file	
			} //end else for file found			
		} else {			
			printf("Invalid item. \n");
		} //end else for menu option A or C		                				
        fclose(tfptr); //close the trans file	
	} //end of while loop
	return 0;
}

void order(void) {
	FILE *tfptr; //flie pointer for receipt text file	
	unsigned int order_number; 
	unsigned int c_trans = 0, a_trans = 0, cTrans, aTrans; //declared variable to store total trans values
	float trans_total, gTotal=0;
	char str[32];

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

		while (order_number > 7 || order_number < 1) { //prompt user for purchase again until enters exit option (7)			
			printf("Please enter a valid order option (1-7): ");
			scanf("%d", &order_number);		
		} 		
		switch(order_number){
			case 1:			
				print_menu(); 
				purchase();
				exit(0); //exit function when 0 is returned 
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
				print_menu();
				break;		
			case 6:																	
				tfptr = fopen("trans.txt", "r");
					while( fgets(str, sizeof(str), tfptr)!=NULL ){ //fgets will equal to null when it reaches last line
					    sscanf(str, "%u:%u:%f", &cTrans, &aTrans, &trans_total); //parse the string in str with sscanf()
					    c_trans += cTrans;
					    a_trans += aTrans;				    
					    gTotal += trans_total;
					} 					
					daily_transactions(c_trans, a_trans, gTotal);                                                                                  
				fclose(tfptr);									
				break;	
			case 7:
				printf("^o^ Thanks for coming. Have a nice day! ^o^ \n");
				tfptr = fopen("trans.txt", "w"); //clear file before exiting
				fclose(tfptr);
				exit(0);										
			default:
				break;
		}
	} while (order_number != 7);						
}