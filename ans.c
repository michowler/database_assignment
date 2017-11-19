#include <stdio.h>//declaration of the libraries that are gonna be used
#include <stdlib.h>
#include <string.h>

struct Meal//declaring a structure
{
    char code[25];//variables inside a structure
    char name[25];
    float price;
    char descriptions[50];
};

int editCombo(char *itemCode, struct Meal meal);//creating functions
int editAddon(char *itemCode, struct Meal meal);
void print_menu();

int main(void)//starting the main function
{
    //declaration of the variables
    struct Meal meal;
    int prompt;
    int qty = 0;
    char mcode[6];
    int itemFound = 0;
    int combo_trans=0, ala_trans=0;
    double gst=0,ngst=0,tax=0,total=0;
    double sumgst=0,sumngst=0,sumtax=0,sum=0;
    int invent;
	int add;
    int option;
	int edit;
    FILE *fptr;//declaring a file pointer for gst
    FILE *nfptr;//declaring a file pointer for non gst
    FILE *pptr;//declaring a file pointer for purchase
    
    FILE *dtemp;
    FILE *tempr;

do//start of a do while loop for menu
{
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
    scanf("%d", &option);     

switch(option)//start of switch statement
{
case 1://options for the switch
printf("Enter item code:(-1 to end purchase)\n");
scanf("%s", mcode);

while(strcmp(mcode, "-1") != 0)//while loop to compare the input with sentinel value
    {
    fptr = fopen("combo.txt", "r");//command to open a specific file
    while(!feof(fptr))
    {
        fscanf(fptr, "%5[^:]:%[^:]:%f:%[^\n]\n", meal.code, meal.name, &meal.price, meal.descriptions);    
        if(strcmp(mcode, meal.code) == 0)
        {
            printf("Enter the quantity of the item:");
            scanf("%d",&qty);          
            qty = (qty <= 0) ? 0 : qty;
            
            printf("---------------------------------------\n");
            printf("code  : %s\n",meal.code);
            printf("Name     : %s\n",meal.name);
            printf("Price    : RM %.2f\n",meal.price);
            printf("Quantity : %d\n",qty);
            printf("---------------------------------------\n");
            gst= meal.price * qty;
            sumgst+=gst;
            total = sumgst + sumngst;
            sum+=total;
            tax= gst*0.06;
            sumtax+=tax;
            itemFound ++;
            combo_trans++;

            struct Meal newValues;//calling the structure to input the data from other file
            strcpy(newValues.name, meal.name);
            newValues.price = meal.price;            
            editCombo(mcode, newValues);

            pptr = fopen("purchase.txt", "a");
            fprintf(pptr,"%s:%s:%.2f:%s\n", meal.code,meal.name,meal.price,meal.descriptions);
            fclose(pptr);
            
        }
    }fclose(fptr);//closes the file after execution

	if(itemFound == 0)//start of if statement
    {
		nfptr = fopen("addon.txt", "r");
		while(!feof(nfptr))
		{
		    fscanf(fptr, "%5[^:]:%[^:]:%f:%[^\n]\n", meal.code, meal.name, &meal.price, meal.descriptions);  
			if(strcmp(mcode, meal.code) == 0)
            {
                printf("Enter the quantity of the item:");
                scanf("%d",&qty);
                qty = (qty <= 0) ? 0 : qty;
               
                printf("---------------------------------------\n");
                printf("code  : %s\n",meal.code);
                printf("Name     : %s\n",meal.name);
                printf("Price    : RM %.2f\n",meal.price);
                printf("Quantity : %d\n",qty);
                printf("---------------------------------------\n");
                ngst= meal.price * qty;//calculation to count the values of the variables
                sumngst+=ngst;
                total = sumgst + sumngst;
                tax= gst*0.06;
                sumtax+=tax;
                itemFound ++;
                ala_trans++;

                struct Meal newValues;//calling structure
                strcpy(newValues.name, meal.name);
                newValues.price = meal.price;//fetching data for the structure                
                editAddon(mcode, newValues);

                pptr = fopen("purchase.txt", "a");
                fprintf(pptr,"%s:%s:%.2f:%s\n", meal.code,meal.name,meal.price,meal.descriptions);
                fclose(pptr);
            
			}
		}fclose(nfptr);
	}//end of if statement

	if(itemFound == 0)
        {
            printf("Item cannot be found! Try again\n");
        }
        itemFound = 0;
        printf("Enter item code:(-1 to end purchase)\n");
        scanf("%s", mcode);
    };//end of while loop
	
					printf("***********************************\n");//output receipt for every transaction
                    printf("Total transaction : %d\n",combo_trans + ala_trans);
                    printf("Sales with GST    : RM %.2f\n",sumgst);                    
                    printf("GST collected     : RM %.2f\n",sumtax);                    
                    printf("***********************************\n");
					
break;//end of a case in switch statement

case 2:
	printf("----------------------------\n");//function to edit the files structure
    printf("      EDIT MEAL\n");
    printf("----------------------------\n");
    printf("Enter item code:\n");
    scanf("%s", mcode);

    struct Meal newValues;//user input

    printf("Enter name:\n");
    scanf("%s", newValues.name);
    printf("Enter price:\n");
    scanf("%f", &newValues.price);        
    printf("Enter description:\n");
    scanf("%s", newValues.descriptions);
    if(editCombo(mcode, newValues) == 1){//comparing the function with the new data
        printf("meal edited.\n");
    }else if(editAddon(mcode, newValues) == 1){
        printf("meal edited.\n");
    }else{
        printf("meal does not exist.\n");
    }
break;

case 3:
	printf("-------------------------------\n");
	printf("	ADD MEAL\n");
	printf("-------------------------------\n");
	printf("1. Combo Menu\n");
	printf("2. Ala Carte Menu\n");
	scanf("%d",&add);
	
	switch(add) //start of switch statement
	{
		case 1:
		fptr = fopen("combo.txt", "a"); //open file
		if(fptr==NULL)//checking whether the file is empty or not
		{
			printf("File cannot be found\n");
			
		}
		else //else statement
		{
			printf("Add Meal Code:\n");
			scanf("%s", meal.code);
			printf("Meal name:\n");
			scanf(" %[^\n]", meal.name);
			printf("Meal price:\n");
			scanf("%f",&meal.price);
			printf("Meal descriptions:\n");
			scanf("%s", meal.descriptions);
			
			fprintf(fptr,"%s:%s:%.2f:%s\n",meal.code,meal.name,meal.price,meal.descriptions);
		fclose(fptr);
		}//end else statement
		break;
		
		case 2:
		nfptr = fopen("addon.txt", "a"); //open file
		if(nfptr==NULL)//checking whether the file is empty or not
		{
			printf("File cannot be found\n");
			
		}
		else //else statement
		{
			printf("Add Meal Code:\n");
			scanf("%s", meal.code);
			printf("Meal name:\n");
			scanf(" %[^\n]", meal.name);
			printf("Meal price:\n");
			scanf("%f",&meal.price);
			printf("Meal descriptions:\n");
			scanf("%s", meal.descriptions);
			
			fprintf(nfptr,"%s:%s:%.2f:%s\n",meal.code,meal.name,meal.price,meal.descriptions);
		fclose(nfptr);
		}//end else statement
		break;
	}
	break;
				
case 4:
    printf("----------------------------\n");//function for deleting a data in the file
    printf("      DELETE MEAL\n");
    printf("----------------------------\n");
    printf("Enter meal code:\n");
    scanf("%s", mcode);//user input
    int type = 0; //Not found
    struct Meal meal;

    FILE *check = fopen("combo.txt", "r");//creating a new file
    fscanf(fptr, "%5[^:]:%[^:]:%f:%[^\n]\n", meal.code, meal.name, &meal.price, meal.descriptions);    
    while(!feof(check))
    {
        if(strcmp(mcode, meal.code) == 0)
        {
            type = 1; //combo
        }
        fscanf(fptr, "%5[^:]:%[^:]:%f:%[^\n]\n", meal.code, meal.name, &meal.price, meal.descriptions);    
    }fclose(check);

    //Couldn't found it yet, look for this item in the addon.txt
    if(type == 0){
        check = fopen("addon.txt", "r");
        fscanf(fptr, "%5[^:]:%[^:]:%f:%[^\n]\n", meal.code, meal.name, &meal.price, meal.descriptions);    
        while(!feof(check))
        {
            if(strcmp(mcode, meal.code) == 0)
            {
                type = 2; //adoon
            }
            fscanf(fptr, "%5[^:]:%[^:]:%f:%[^\n]\n", meal.code, meal.name, &meal.price, meal.descriptions);    
        }fclose(check);
    }

    switch(type){//switching to search which value matches the input
        case 1:            
            dtemp = fopen("deletetemp.txt", "w");//opening file for write.
            int found = 0;
            fptr = fopen("combo.txt", "r");
            while(!feof(fptr))
            {
                fscanf(fptr, "%5[^:]:%[^:]:%f:%[^\n]\n", meal.code, meal.name, &meal.price, meal.descriptions);    //reading from the file
                if(strcmp(mcode, meal.code) != 0)
                {
                    fscanf(fptr, "%5[^:]:%[^:]:%f:%[^\n]\n", meal.code, meal.name, &meal.price, meal.descriptions);    
                }
            }
            fclose(fptr);
            remove("combo.txt");//removing one file and replacing it with another
            rename("deletetemp.txt", "combo.txt");
            fclose(dtemp);//file close
            printf("Deletion was successful.\n");         
            break;

        case 2:            
            dtemp = fopen("deletetemp.txt", "w");
            fptr = fopen("addon.txt", "r");//opening a file to read from it
            while(!feof(fptr))
            {
                fscanf(fptr, "%5[^:]:%[^:]:%f:%[^\n]\n", meal.code, meal.name, &meal.price, meal.descriptions);    
                if(strcmp(mcode, meal.code) != 0)
                {
                    fprintf(dtemp, "%s:%s:%f:%s\n", meal.code, meal.name, meal.price, meal.descriptions);
                }
            }
            fclose(fptr);
            remove("addon.txt");
            rename("deletetemp.txt", "addon.txt");
            fclose(dtemp);
            printf("Deletion was successful.\n");          
            break;

        default:
            printf("This is an invalid item.\n");//for default value
            break;
    }

break;
				
case 5:
    print_menu();
    break;

case 6:
    printf("--------------------------------\n");//list of daily transaction
    printf("   Daily Transactions\n");
	printf("--------------------------------\n");
    printf("Total Combo Trans     :%d\n", combo_trans);
	printf("Total Ala Trans       :%d\n", ala_trans);
	printf("Sales without GST     :%.2f\n", sumngst);
	printf("GST collected         :%.2f\n", sumtax);
	printf("--------------------------------\n");
break;

case 7:
    printf("Exit\n");
    exit(0);//statement for exiting the program
break;

default:
    printf("Invalid option!\n");//error message when invalid option is chosen
break;
}//end of switch statement for menu function
} while (option != 6);//end of menu do while loop
// return;//returns the value back to the main function
}//end of main function


int editCombo(char *itemCode, struct Meal meal)//declaring function
{
    struct Meal tmp;//declaring structure    
    int found = 0;
    FILE *combo = fopen("combo.txt", "r");
    FILE *temp = fopen("temp.txt", "w");//opening file
    fscanf(combo, "%5[^:]:%[^:]:%f:%[^\n]\n", tmp.code, tmp.name, &tmp.price, tmp.descriptions);    
    while(!feof(combo)){
        if(strcmp(tmp.code, itemCode)==0){//compare two values
            fprintf(temp, "%s:%s:%f:%s\n", itemCode, meal.name, meal.price, meal.descriptions);
            found = 1;
        }else{
            fprintf(temp, "%s:%s:%f:%s\n", tmp.code, tmp.name, tmp.price, tmp.descriptions);
        }
        fscanf(combo, "%5[^:]:%[^:]:%f:%[^\n]\n", tmp.code, tmp.name, &tmp.price, tmp.descriptions);    
    }fclose(combo);//closing a file
    fclose(temp);

    remove("combo.txt");//replacing a file with another temporary file
    rename("temp.txt", "combo.txt");

    return found;
}

int editAddon(char *itemCode, struct Meal meal)//declaring function
{
    struct Meal tmp;//declaring structure
    int found = 0;
    FILE *addon = fopen("addon.txt", "r");//opening file
    FILE *temp = fopen("temp.txt", "w");
    fscanf(addon, "%5[^:]:%[^:]:%f:%[^\n]\n", tmp.code, tmp.name, &tmp.price, tmp.descriptions);    
    while(!feof(addon)){//to read until the end of file
        if(strcmp(tmp.code, itemCode)==0)
        {
            fprintf(temp, "%s:%s:%f:%s\n", itemCode, meal.name, meal.price, meal.descriptions);
            found = 1;
        }
        else
        {
            fprintf(temp, "%s:%s:%f:%s\n", itemCode, meal.name, meal.price, meal.descriptions);
        }
        fscanf(addon, "%5[^:]:%[^:]:%f:%[^\n]\n", tmp.code, tmp.name, &tmp.price, tmp.descriptions);    
    }fclose(addon);
    fclose(temp);//closing the files

    remove("addon.txt");
    rename("temp.txt","addon.txt");

    return found;//returns the value back
}

//function to display menu
void print_menu(void){
    char meal_code[6], meal_name[25], meal_description[100];
    double meal_price;
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
        for (i=0; i< 5; i++){
            fscanf(cfp, "%[^:]:%[^:]:%lf:%[^\n]\n", meal_code,meal_name,&meal_price,meal_description);          
            printf("%-15s%-27s%-17.2f%-12s\n", meal_code,meal_name,meal_price,meal_description);                
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
        for (i=0; i< 5; i++){
            fscanf(afp, "%[^:]:%[^:]:%lf:%[^\n]\n", meal_code,meal_name,&meal_price,meal_description);          
            printf("%-15s%-27s%-17.2f%-12s\n", meal_code,meal_name,meal_price,meal_description);    
        }    
    }  
    puts("------------------------------------------------------------------------------");
    fclose(afp); //close txt file    
}
