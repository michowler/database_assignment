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
	char mcode[6], name[100], description[100];
	float price;
};

//prototype of functions used
int print_menu(), purchase();
void add_meal(), order();
void daily_trans(int combo_trans, int ala_trans, float grand_total),print_order(int quantity, char *item, float price, float total);
void print_receipt(int combo_trans, int ala_trans, int total_quantity, float total);

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
		printf("%s", text_file);
	}
	printf("\nTotal Orders : %d\n", total_quantity);
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

int print_menu(void) //function to display menu
{
	struct Meal meal;	
	int c, d;	
	FILE *cfp; //pointer for combo txt file
	FILE *afp; //pointer for addon txt file      

	puts("------------------------------------------------------------------------------------------------------");
	puts("----------------------------------------COMBO MEALS---------------------------------------------------");
	puts("------------------------------------------------------------------------------------------------------");
	printf("%-16s%-24s%-19s%-18s\n\n","Menu Code","Meal Name","Meal Price(RM)","Meal Description");
	if ((cfp = fopen("combo.txt", "r"))== NULL){
	   puts("File could not be found!");
	} else {
		c = fgetc(cfp);
		if (c == EOF) {
		    printf("No combo meals available!\n"); //print error message if file is empty
		} else {
			ungetc(c, cfp);	
			while(!feof(cfp)){
				fscanf(cfp, "%[^:]:%[^:]:%f:%[^\n]\n", meal.mcode,meal.name,&meal.price,meal.description);			
				printf("%-15s%-27s%-17.2f%-12s\n", meal.mcode,meal.name,meal.price,meal.description);			
			}  
		}  
	} 
	puts("----------------------------------------------------------------------------------------------------\n");
	fclose(cfp); //close the file   

	puts("------------------------------------------------------------------------------");
	puts(" -----------------------------------ADD-ONS---------------------------------- ");
	puts("------------------------------------------------------------------------------");
	printf("%-16s%-24s%-19s%-18s\n\n","Menu Code","Meal Name","Meal Price(RM)","Meal Description");
	if ((afp = fopen("addon.txt", "r"))== NULL){
	   puts("File could not be found!");
	} else {
		d = fgetc(afp);
		if (d == EOF) {
		    printf("No addon meals available!\n");	
		} else {
			ungetc(d, afp);	
			while(!feof(afp)){
				fscanf(afp, "%[^:]:%[^:]:%f:%[^\n]\n", meal.mcode,meal.name,&meal.price,meal.description);			
				printf("%-15s%-27s%-17.2f%-12s\n", meal.mcode,meal.name,meal.price,meal.description);			
			}    
		}		
	}  
	puts("------------------------------------------------------------------------------");
	fclose(afp); //close txt file
	return 0;
}

void add_meal(){
	int add, countC1=0,countC2=0, countA1=0, countA2=0;	
	struct Meal meal;	
	char menucode[6];
	FILE *cfptr; //pointer for combo text file to append
	FILE *cfp; //pointer for combo text file to write	
	FILE *afptr; //pointer for addon text file to append
	FILE *afp; //pointer for addon text file to write	

	printf("---------------------\n");
	printf("    ADD MEAL\n");
	printf("---------------------\n");	
	printf("[1] Combo Menu\n");
	printf("[2] Ala Carte Menu\n");
	printf("[3] Exit\n");
	printf("----------------------\n");
	printf("Choose an option 1 or 2 to add meal.\n");
	scanf("%d", &add);
	
	switch(add){
		case 1:
			cfptr = fopen("combo.txt", "a"); //to append new meal 
			if(cfptr==NULL){
				printf("File cannot be found\n");				
			}
			else {
				printf("Add Combo Code:\n");
				scanf("%s", menucode);
				cfp = fopen("combo.txt", "r");
				while(!feof(cfp)){
				    fscanf(cfp, "%5[^:]:%[^:]:%f:%[^\n]\n", meal.mcode, meal.name, &meal.price, meal.description);  
					while(strcmp(menucode, meal.mcode) == 0){		     
			           printf("Invalid, menu code %s existed!\n", menucode);
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
					printf("Enter combo description: \n");
					scanf(" %[^\n]", meal.description);
					fprintf(cfptr,"\n%s:%s:%.2f:%s\n",menucode,meal.name,meal.price,meal.description);	
				}
				printf("Meal %s successfully added!\n", menucode);
			}//end else statement
			fclose(cfptr);
			break;		
		case 2:
			afptr = fopen("addon.txt", "a"); //open file
			if(afptr==NULL){
				printf("File cannot be found\n");				
			}
			else{
				printf("Add Addon Code:\n");
				scanf("%s", menucode);
				afp = fopen("addon.txt", "r"); //open file
				while(!feof(afp)){
				    fscanf(afp, "%5[^:]:%[^:]:%f:%[^\n]\n", meal.mcode, meal.name, &meal.price, meal.description);  
					if(strcmp(menucode, meal.mcode) == 0){		     
			           printf("Invalid, menu code %s existed!\n", menucode);
			           printf("Add Addon Code:\n");
			           scanf("%s", menucode);
			           ++countA2;     			           			           		              			           
					} 					
				}
				fclose(afp);
				if(countA1 == 0 || countA2 > 0 ){
					printf("Enter addon name: \n");					
					scanf(" %[^\n]", meal.name);
					printf("Enter addon price: \n");
					scanf(" %f", &(meal.price));
					printf("Enter addon description: \n");
					scanf(" %[^\n]", meal.description);
					fprintf(afptr,"\n%s:%s:%.2f:%s\n",menucode,meal.name,meal.price,meal.description);
				}
				printf("Meal %s successfully added!\n", menucode);
			}//end else statement
			fclose(afptr);
			break;	
		case 3:
			order(); //go back to order
			break;			
		default:
			printf("Invalid option!\n");
			add_meal();
	}				
}

void delete_meal(){		
	FILE *dtemp;
	FILE *cptr;
	FILE *aptr;	
	char mcode[6];
	struct Meal meal;
	int type = 0; //Not found	
	
    printf("--------------------------\n");
    printf("     DELETE MEAL\n");
    printf("--------------------------\n");
    printf("Enter menu code, example C0001. (-1 to exit)\n");
    scanf("%s", mcode);
    if (strcmp(mcode, "-1") == 0){
    	order();
    }

    cptr = fopen("combo.txt", "r");
    while(!feof(cptr)){	    	    	
    	fscanf(cptr, " %[^:]:%[^:]:%f:%[^\n]\n", meal.mcode, meal.name, &meal.price, meal.description);
        if(strcmp(mcode, meal.mcode) == 0){
            type = 1; //combo
        }       
    }
    fclose(cptr);
    
    if(type == 0){
        aptr = fopen("addon.txt", "r");                
        while(!feof(aptr)){
        	fscanf(aptr, " %[^:]:%[^:]:%f:%[^\n]\n", meal.mcode, meal.name, &meal.price, meal.description);
            if(strcmp(mcode, meal.mcode) == 0){
                type = 2; //addon
            }            
        }
        fclose(aptr);
    }

    switch(type){//switching to search which value matches the input
        case 1:           
            dtemp = fopen("deletetemp.txt", "w");//opening file for write.            
            cptr = fopen("combo.txt", "r");
            while(!feof(cptr)){
                fscanf(cptr, " %[^:]:%[^:]:%f:%[^\n]\n", meal.mcode, meal.name, &meal.price, meal.description);
                if (strcmp(mcode, meal.mcode) != 0){                
                    fprintf(dtemp, "%s:%s:%.2f:%s\n", meal.mcode, meal.name, meal.price, meal.description);
                }               
            }
            fclose(cptr);
            remove("combo.txt");//removing one file and replacing it with another
            rename("deletetemp.txt", "combo.txt");
            fclose(dtemp);//file close
            printf("Menu with code %s deleted!\n", mcode);
	        break;
        case 2:            
            dtemp = fopen("deletetemp.txt", "w");
            aptr = fopen("addon.txt", "r");
            while(!feof(aptr)){
                fscanf(aptr, " %[^:]:%[^:]:%f:%[^\n]\n", meal.mcode, meal.name, &meal.price, meal.description);
                if(strcmp(mcode, meal.mcode) != 0){
                    fprintf(dtemp, "%s:%s:%.2f:%s\n", meal.mcode, meal.name, meal.price, meal.description);
                }
            }
            fclose(aptr);
            remove("addon.txt");
            rename("deletetemp.txt", "addon.txt");
            fclose(dtemp);
            printf("Menu with code %s deleted!\n", mcode);        
	        break;
        default:
            printf("Invalid, %s not found!\n", mcode);
            delete_meal();
        	break;
    }
}

void edit_meal(){
	int option;
	char mcode[6], confirm;
	struct Meal newValues;
    struct Meal meal;
    struct Meal tmp;
    int found = 0;
	FILE *cptr;
	FILE *aptr;
    FILE *temp;
    FILE *atemp;

	printf("----------------------\n");//function to edit the files structure
    printf("     EDIT MEAL\n");
    printf("----------------------\n");
    printf("Enter menu code to edit, example C0001. (-1 to exit) \n");
    scanf("%s", mcode);
    if (strcmp(mcode, "-1") == 0){
    	order();
    }

    cptr = fopen("combo.txt", "r");
    rewind(cptr);
    while(!feof(cptr)){                   
        fscanf(cptr, " %[^:]:%[^:]:%f:%[^\n]", meal.mcode, meal.name, &meal.price, meal.description);
        if(strcmp(mcode, meal.mcode) == 0){
            found = 1; //combo
        }       
    }
    fclose(cptr);
    
    if(found == 0){ //if combo not found
        aptr = fopen("addon.txt", "r");
        rewind(aptr);                
        while(!feof(aptr)){
            fscanf(aptr, " %[^:]:%[^:]:%f:%[^\n]", meal.mcode, meal.name, &meal.price, meal.description);
            if(strcmp(mcode, meal.mcode) == 0){
                found = 2; //addon
            }
        }
        fclose(aptr);
    }

    if (found > 0){
        printf("Enter option (1 to 3) to edit: \n");
        printf("[1] Name \n");
        printf("[2] Price \n");
        printf("[3] Description \n");        
        scanf("%d", &option);
    } else {
    	printf("Item not found. \n");    	
    	printf("Please add meal %s before editing!\n", mcode);
    	edit_meal();
    }

    switch(found){
        case 1:                      
            cptr = fopen("combo.txt", "r");
            temp = fopen("temp.txt", "w");
            while(!feof(cptr)){
                fscanf(cptr, " %[^:]:%[^:]:%f:%[^\n]\n", tmp.mcode,tmp.name,&tmp.price,tmp.description);
                if(strcmp(mcode, tmp.mcode)==0){
                    switch(option){
                        case 1:
                            printf("Enter a new name for %s: \n", mcode);
                            scanf(" %[^\n]", newValues.name);
                            fprintf(temp, "%s:%s:%.2f:%s\n", mcode, newValues.name, tmp.price, tmp.description);
                            break;
                        case 2:
                            printf("Enter a new price for %s: \n", mcode);
                            scanf(" %f", &(newValues.price));
                            fprintf(temp, "%s:%s:%.2f:%s\n", mcode, tmp.name, newValues.price, tmp.description);
                            break;
                        case 3:
                            printf("Enter a new description for %s: \n", mcode);
                            scanf(" %[^\n]", newValues.description);
                            fprintf(temp, "%s:%s:%.2f:%s\n", mcode, tmp.name, tmp.price, newValues.description);                                                                         
                            break;
                        default:
	                        printf("Invalid option to edit!\n");
                            break;    
                    }
                    printf("Edit successful!\n");
                }else {
                    fprintf(temp, "%s:%s:%.2f:%s\n", tmp.mcode, tmp.name, tmp.price, tmp.description);
                }                
            }fclose(cptr);//closing a file
            fclose(temp);
            remove("combo.txt");//replacing a file with another temporary file
            rename("temp.txt", "combo.txt");
            break;
        case 2:                        
            aptr = fopen("addon.txt", "r");
            atemp = fopen("atemp.txt", "w");//opening file    
            while(!feof(aptr)){
                fscanf(aptr, " %[^:]:%[^:]:%f:%[^\n]\n", tmp.mcode,tmp.name,&tmp.price,tmp.description);
                if(strcmp(mcode, tmp.mcode)==0){//compare two values
                    switch(option){
                        case 1:
                            printf("Enter a new name for %s: \n", mcode);
                            scanf(" %[^\n]", newValues.name);
                            fprintf(atemp, "%s:%s:%.2f:%s\n", mcode, newValues.name, tmp.price, tmp.description);
                            break;
                        case 2:
                            printf("Enter a new price for %s: \n", mcode);
                            scanf(" %f", &(newValues.price));
                            fprintf(atemp, "%s:%s:%.2f:%s\n", mcode, tmp.name, newValues.price, tmp.description);
                            break;
                        case 3:
                            printf("Enter a new description for %s: \n", mcode);
                            scanf(" %[^\n]", newValues.description);
                            fprintf(atemp, "%s:%s:%.2f:%s\n", mcode, tmp.name, tmp.price, newValues.description);
                            break;
                        default:
	                        printf("Invalid option to edit!\n");
                            break;    
                    }
                    printf("Edit successful!\n");                                 
                }else {
                    fprintf(atemp, "%s:%s:%.2f:%s\n", tmp.mcode, tmp.name, tmp.price, tmp.description);
                }                
            }fclose(aptr);//closing a file
            fclose(atemp);
            remove("addon.txt");//replacing a file with another temporary file
            rename("atemp.txt", "addon.txt"); 
            break;
        default:        	
            break;    
    }
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

	fptr = fopen("receipt.txt", "w"); //clear file before appending for each purchase		
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
	            quantity = (quantity <= 0) ? 0 : quantity; //accepting valid values for quantity            	          
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

		if(itemFound == 0){
	            printf("Invalid menu code!\n");
	    }
        itemFound = 0;
        printf("Please enter a meal code (-1 to exit purchase). Example: C0001.\n");
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
	char mcode[6];	

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
		    if (scanf("%d", &order_number) < 0 || order_number < 0 || ((ch = getchar()) != EOF && ch != '\n')) {
		    	printf("Please enter a valid order option (1-7): ");
		        clearerr(stdin);
		        do
		            ch = getchar();
		        while (ch != EOF && ch != '\n'); //clears the std input of buffered non-numeric characters
		        	clearerr(stdin);    
		    } else {
			    order_number = (order_number <= 0) || (order_number > 7 || order_number < 1) ? 0 : order_number;		    	
		        break;
		    }
		}

		switch(order_number){
			case 1:			
				print_menu(); 
				purchase();
				exit(0); //exit function when 0 is returned 
			case 2:
				edit_meal();
				break;
			case 3:
				add_meal();				
				break;
			case 4:
				delete_meal();
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