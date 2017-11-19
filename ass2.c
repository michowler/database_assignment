/*------------------------------------------------------------------- */
/* ITS62804– Assignment #2 */
/* Principles of Programming */
/* Student Name: <Michelle Ler Hsin Yee>, <Vikneesh a/l Ganesan> */
/* Student ID: <0333120>, <0324370> */
/*------------------------------------------------------------------- */

//prototype of libraries used
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

struct Meal {
	char mcode[6], name[900], description[900];
	float price;
};

//prototype of functions used
void add_meal();
int print_menu(), purchase();
void daily_trans(int combo_trans, int ala_trans, float grand_total);
void order(), print_order(int quantity, char *item, float price, float total), print_receipt(int combo_trans, int ala_trans, int total_quantity, float total);

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
void print_receipt(int combo_trans, int ala_trans, int total_quantity, float total){
	FILE *fp; //pointer for receipt txt file
	int i, trans;
	char text_file[200];	

	fp = fopen("receipt.txt", "r"); 	
	trans = ala_trans + combo_trans; //calculate total trans to print out for each line	
	puts("----------------------------------------------------------");
	puts("=======================YOUR RECEIPT=======================");	
	puts("----------------------------------------------------------");
	puts ("QTY\t|\tITEM\t\t\t|\tTOTAL(RM)");	
	for (i = 0; i < trans; i++) {
		fgets(text_file, 200, (FILE*)fp);
		printf("%s\n", text_file);
	}
	printf("Total Orders : %d\n", total_quantity);
	printf("6%% GST : RM %.2f\n", (total * 1.06) * 0.06);
	printf("Subtotal (excl gst) : RM %.2f\n",total);
	printf("Subtotal (incl gst): RM %.2f\n", total * 1.06);	
	puts("----------------------------------------------------------");
	puts("===================THANKS FOR PURCHASING==================");
	puts("----------------------------------------------------------");
	fclose(fp);
}

void daily_trans(int combo_trans, int ala_trans, float grand_total){
    printf("--------------------------------\n");
    printf("   Daily Transactions\n");
	printf("--------------------------------\n");
	printf("Total combo meal transaction : %d\n", combo_trans);
	printf("Total ala-carte transaction : %d\n", ala_trans);
	printf("Total sales : RM %.2f\n", grand_total);				
	printf("GST collected : RM %.2f\n", grand_total * 0.06);
	puts("------------------------------------");
}

void add_meal(){
	int add, countC1=0,countC2=0, countA1=0, countA2=0 ;	
	struct Meal meal;	
	char menucode[6];
	FILE *cfptr; //pointer for combo text file
	FILE *cfp; //pointer for combo text file	
	FILE *afptr; //pointer for addon text file  
	FILE *afp;

	printf("-------------------------------\n");
	printf("	ADD MEAL\n");
	printf("-------------------------------\n");
	printf("[1] Combo Menu\n");
	printf("[2] Ala Carte Menu\n");
	printf("-------------------------------\n");
	scanf("%d", &add);
	
	switch(add) //start of switch statement
	{
		case 1:
			cfptr = fopen("combo.txt", "a"); //open file
			if(cfptr==NULL)//checking whether the file is empty or not
			{
				printf("File cannot be found\n");
				
			}
			else //else statement
			{
				printf("Add Combo Code:\n");
				scanf("%s", menucode);
				cfp = fopen("combo.txt", "r"); //open file
				while(!feof(cfp))
				{
				    fscanf(cfp, "%5[^:]:%[^:]:%f:%[^\n]\n", meal.mcode, meal.name, &meal.price, meal.description);  
					while(strcmp(menucode, meal.mcode) == 0)
		            {		     
			           printf("Invalid, menu code existed!\n");
			           printf("Add Combo Code:\n");
			           scanf("%s", menucode);
			           ++countC2;
					} 					
				}
				fclose(cfp);
				if(countC1 == 0 || countC2 > 0 ){
					printf("Enter combo name: \n");				
					scanf(" %[^\n]", meal.name);
					printf("Enter combo price: \n");
					scanf(" %f", &(meal.price));
					printf("Enter combo descriptions: \n");
					scanf(" %[^\n]", meal.description);
					fprintf(cfptr,"%s:%s:%.2f:%s\n",menucode,meal.name,meal.price,meal.description);	
				}
										
			}//end else statement
			fclose(cfptr);
			break;		
		case 2:
			afptr = fopen("addon.txt", "a"); //open file
			if(afptr==NULL)//checking whether the file is empty or not
			{
				printf("File cannot be found\n");
				
			}
			else //else statement
			{
				printf("Add Addon Code:\n");
				scanf("%s", menucode);
				afp = fopen("addon.txt", "r"); //open file
				while(!feof(afp))
				{
				    fscanf(afp, "%5[^:]:%[^:]:%f:%[^\n]\n", meal.mcode, meal.name, &meal.price, meal.description);  
					if(strcmp(menucode, meal.mcode) == 0)
		            {		     
			           printf("Invalid, menu code existed!\n");  			           
			           printf("Add Addon Code:\n");
			           scanf("%s", menucode);
			           ++countA2;     			           			           		              			           
					} 					
				}
				fclose(afp);
				if(countA1 == 0 || countA2 > 0 )
				{
					printf("Enter addon name: \n");					
					scanf(" %[^\n]", meal.name);
					printf("Enter addon price: \n");
					scanf(" %f", &(meal.price));
					printf("Enter addon descriptions: \n");
					scanf(" %[^\n]", meal.description);
					fprintf(afptr,"%s:%s:%.2f:%s\n",menucode,meal.name,meal.price,meal.description);
				}		
												
			}//end else statement
			fclose(afptr);
			break;			
		default:
			printf("Invalid option!\n");
	}				
}

/*This option allows user to edit the information of the menu. When this option is
	selected, the user will be asked to enter the menu code to indicate the menu need
	to be edited. If the menu is found, then the user will be given the option to choose
	the data that need to be edited. There are only three fields can be edit; there are
	menu name, price and descriptions. Menu code is not allowed to be edited. If the
	menu could not be found, print message “Item not found”.
	Once user confirmed the changes, the new data will be stored at the text file.*/
	

//function to display menu
int print_menu(void)
{
	struct Meal meal;	
	int i;
	FILE *cfp; //pointer for combo text file
	FILE *afp; //pointer for addon text file      

	puts("------------------------------------------------------------------------------------------------------");
	puts("----------------------------------------COMBO MEALS---------------------------------------------------");
	puts("------------------------------------------------------------------------------------------------------");
	printf("%-16s%-24s%-19s%-18s\n\n","Menu Code","Meal Name","Meal Price(RM)","Meal Description");
	if ((cfp = fopen("combo.txt", "r"))== NULL){
	   puts("File could not be found");
	} else {
		while(!feof(cfp)){
			fscanf(cfp, "%[^:]:%[^:]:%f:%[^\n]\n", meal.mcode,meal.name,&meal.price,meal.description);			
			printf("%-15s%-27s%-17.2f%-12s\n", meal.mcode,meal.name,meal.price,meal.description);			
		}    
	} 
	puts("----------------------------------------------------------------------------------------------------\n");
	fclose(cfp); //close the file   

	puts("------------------------------------------------------------------------------");
	puts(" -----------------------------------ADD-ONS---------------------------------- ");
	puts("------------------------------------------------------------------------------");
	printf("%-16s%-24s%-19s%-18s\n\n","Menu Code","Meal Name","Meal Price(RM)","Meal Description");
	if ((afp = fopen("addon.txt", "r"))== NULL){
	   puts("File could not be found");
	} else {
		while(!feof(afp)){
			fscanf(afp, "%[^:]:%[^:]:%f:%[^\n]\n", meal.mcode,meal.name,&meal.price,meal.description);			
			printf("%-15s%-27s%-17.2f%-12s\n", meal.mcode,meal.name,meal.price,meal.description);			
		}    
	}  
	puts("------------------------------------------------------------------------------");
	fclose(afp); //close txt file
	return 0;
}

int purchase(void){
	char menu_code[6]; //user input meal code	
	FILE *fptr; //flie pointer for receipt text file		
	FILE *tfptr; //flie pointer for trans text file	
	FILE *mfptr; //flie pointer for combo text file
	FILE *afptr; //flie pointer for addon text file
	int quantity=0, itemFound=0,total_quantity=0; 	
	float total=0, grand_total=0;
	unsigned int combo_trans=0, ala_trans=0, i;
	struct Meal meal;

	printf("Please enter a meal code (-1 to exit purchase). Example: C0001.\n");
	scanf("%s", menu_code);

	fptr = fopen("receipt.txt", "w"); //clear file before appending for purchase		
	while(strcmp(menu_code, "-1") != 0)//while loop to compare the input with sentinel value
	    {
	    mfptr = fopen("combo.txt", "r");//command to open a specific file
	    while(!feof(mfptr))
	    {
	        fscanf(mfptr, "%5[^:]:%[^:]:%f:%[^\n]\n", meal.mcode, meal.name, &meal.price, meal.description);    
	        if(strcmp(menu_code, meal.mcode) == 0)
	        {
	            printf("Enter the quantity of the meal: ");
	            scanf("%d",&quantity);          
	            quantity = (quantity <= 0) ? 0 : quantity;
	            	          
	            total = meal.price * quantity;
	            grand_total += total;	 
	            total_quantity += quantity;           
	            
	            itemFound ++;
	            combo_trans++;	       	            
	            print_order(quantity, meal.name, meal.price, grand_total); 

	            tfptr = fopen("trans.txt", "a+");
	            fprintf(tfptr, "%u:%u:%.2f\n", quantity, 0, total); 
	            fclose(tfptr);
	            fptr = fopen("receipt.txt", "a+");
	            fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, meal.name, meal.price*quantity);
	            fclose(fptr);
	            
	        }
	    }fclose(mfptr);//closes the file after execution

		if(itemFound == 0)//start of if statement
	    {
			afptr = fopen("addon.txt", "r");
			while(!feof(afptr))
			{
			    fscanf(afptr, "%5[^:]:%[^:]:%f:%[^\n]\n", meal.mcode, meal.name, &meal.price, meal.description);  
				if(strcmp(menu_code, meal.mcode) == 0)
	            {
	               printf("Enter the quantity of the meal: ");
	               scanf("%d",&quantity);          
	               quantity = (quantity <= 0) ? 0 : quantity;
	               	          
	               total = meal.price * quantity;
	               grand_total += total;
	               total_quantity += quantity;	            
	               
	               itemFound ++;
	               ala_trans++;	       	            
	               print_order(quantity, meal.name, meal.price, grand_total); 

	               tfptr = fopen("trans.txt", "a+");
	               fprintf(tfptr, "%u:%u:%.2f\n", 0, quantity, total); 
	               fclose(tfptr);
	               fptr = fopen("receipt.txt", "a+");
	               fprintf(fptr, "%-15u%-34s%-17.2f\n", quantity, meal.name, meal.price*quantity);
	               fclose(fptr);
				}
			}fclose(afptr);
		}//end of if statement

		if(itemFound == 0)
	        {
	            printf("Invalid menu code!\n");
	        }
	        itemFound = 0;
	        printf("Enter menu code:(-1 to end purchase)\n");
	        scanf("%s", menu_code);
	    };//end of while loop

		fclose(fptr);
		print_receipt(ala_trans, combo_trans, total_quantity, grand_total);
		order();
		return 0;
}

void order(void) {
	FILE *tfptr; //flie pointer for trans text file	
	int order_number, ch; 
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
		printf("Please enter order option (1-7): "); 
		scanf("%d", &order_number);		
		
		while (order_number > 7 || order_number < 1) { //validation of user input
			printf("Please enter a valid order option (1-7): ");
		    if (scanf("%d", &order_number) < 0 || order_number < 0 || ((ch = getchar()) != EOF && ch != '\n')) {		             
		        clearerr(stdin);
		        do
		            ch = getchar();
		        while (ch != EOF && ch != '\n'); //clears the std input of buffered non-numeric characters following case
		        clearerr(stdin);    
		    } else {
		    	order_number = (order_number <= 0) ? 0 : order_number;
		        break;
		    }
		}

		switch(order_number){
			case 1:			
				print_menu(); 
				purchase();
				exit(0); //exit function when 0 is returned 
			case 2:
				//edit_meal();
				break;
			case 3:
				add_meal();
				// printf("This option allows user to add meals!\n");
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
					    sscanf(str, "%u:%u:%f", &cTrans, &aTrans, &trans_total); //parse the string in str 
					    c_trans += cTrans;
					    a_trans += aTrans;				    
					    gTotal += trans_total;
					} 					
					daily_trans(c_trans, a_trans, gTotal);                                                                                  
				fclose(tfptr);									
				order();
				exit(0); //exit to prevent duplicate data in daily trans when re-enter 6
			case 7:				
				tfptr = fopen("trans.txt", "w"); //clear file before exiting
				fclose(tfptr);
				printf("^o^ Thanks for coming. Have a nice day! ^o^ \n");
				exit(0);								
			default:
				break;
		}
	} while (order_number != 7);						
}