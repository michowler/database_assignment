#include <stdio.h>//declaration of the libraries that are gonna be used
#include <stdlib.h>
#include <string.h>

/*-------------------------------------------------------------------*/
/* ITS60304 C Assignment #1 */
/* C Programming */
/* Student Name: <HO KEH RIN> <KHOR MAN YEE> <MEERASHINI MENON> */
/* Student ID: <0326439> <0324125> <0323644>*/
/*-------------------------------------------------------------------*/

struct Product//declaring a structure
{
    char code[25];//variables inside a structure
    char name[25];
    double price;
    int quantity;
};

int editGST(char *itemCode, struct Product product);//creating functions
int editNGST(char *itemCode, struct Product product);

int main(void)//starting the main function
{
    //declaration of the variables
    struct Product product;
    int prompt;
    int qty = 0;
    char icode[6];
    int itemFound = 0;
    int trans=0;
    double gst=0,ngst=0,tax=0,total=0;
    double sumgst=0,sumngst=0,sumtax=0,sum=0;
    int invent;
	int add;
    int option;
	int edit;
    FILE *fptr;//declaring a file pointer for gst
    FILE *nfptr;//declaring a file pointer for non gst
    FILE *pptr;//declaring a file pointer for purchase
    // FILE *temp;
    FILE *dtemp;
    FILE *tempr;

do//start of a do while loop for menu
{
	printf("-----------------------------------\n");
	printf("Grocery Retail\n");
	printf("-----------------------------------\n");
	printf("1. Purchase items\n");
	printf("2. Edit items\n");
	printf("3. Add items\n");
	printf("4. Delete items\n");
	printf("5. Show inventory\n");
	printf("6. Show daily transaction\n");
	printf("7. Exit\n");
	printf("Enter option 1-7:\n");
	scanf("%d",&option);//command to read user input

switch(option)//start of switch statement
{
case 1://options for the switch
printf("Enter item code:(-1 to end purchase)\n");
scanf("%s", icode);

while(strcmp(icode, "-1") != 0)//while loop to compare the input with sentinel value
    {
    fptr = fopen("gst.txt", "r");//command to open a specific file
    while(!feof(fptr))
    {
        fscanf(fptr, " %[^;];%[^;];%lf;%d", product.code, product.name, &product.price, &product.quantity);//prints the data inside the file
        if(strcmp(icode, product.code) == 0)
        {
            printf("Enter the quantity of the item:");
            scanf("%d",&qty);
            if (qty>product.quantity)
            {
               printf("The maximum quantity that can be purchased is %d\n",product.quantity);
            }
            else
            {
                printf("---------------------------------------\n");
                printf("code  :%s\n",product.code);
                printf("Name     :%s\n",product.name);
                printf("Price    :%.2fRM\n",product.price);
                printf("Quantity :%d\n",qty);
                printf("---------------------------------------\n");
                gst= product.price * qty;
                sumgst+=gst;
                total = sumgst + sumngst;
                sum+=total;
                tax= gst*0.06;
                sumtax+=tax;
                itemFound ++;
                trans++;

                struct Product newValues;//calling the structure to input the data from other file
                strcpy(newValues.name, product.name);
                newValues.price = product.price;
                newValues.quantity = product.quantity - qty;
                editGST(icode, newValues);

                pptr = fopen("purchase.txt", "a");
                fprintf(pptr,"%s;%s;%.2f;%d\n", product.code,product.name,product.price,qty);
                fclose(pptr);
            }
        }
    }fclose(fptr);//closes the file after execution

	if(itemFound == 0)//start of if statement
    {
		nfptr = fopen("ngst.txt", "r");
		while(!feof(nfptr))
		{
		    fscanf(nfptr, "%[^;];%[^;];%lf;%d\n", product.code, product.name, &product.price, &product.quantity);
			if(strcmp(icode, product.code) == 0)
            {
                printf("Enter the quantity of the item:");
                scanf("%d",&qty);
                if (qty>product.quantity)
                {
                    printf("The maximum quantity that can be purchased is %d\n",product.quantity);
                }
                else
                {
                    printf("---------------------------------------\n");
                    printf("code  :%s\n",product.code);
                    printf("Name     :%s\n",product.name);
                    printf("Price    :%.2fRM\n",product.price);
                    printf("Quantity :%d\n",qty);
                    printf("---------------------------------------\n");
                    ngst= product.price * qty;//calculation to count the values of the variables
                    sumngst+=ngst;
                    total = sumgst + sumngst;
                    tax= gst*0.06;
                    sumtax+=tax;
                    itemFound ++;
                    trans++;

                    struct Product newValues;//calling structure
                    strcpy(newValues.name, product.name);
                    newValues.price = product.price;//fetching data for the structure
                    newValues.quantity = product.quantity - qty;
                    editNGST(icode, newValues);


                    pptr = fopen("purchase.txt", "a");
                    fprintf(pptr,"%s;%s;%.2f;%d\n", product.code,product.name,product.price,qty);
                    fclose(pptr);
                }
			}
		}fclose(nfptr);
	}//end of if statement

	if(itemFound == 0)
        {
        printf("Item cannot be found! Try again\n");
        }
        itemFound = 0;
        printf("Enter item code:(-1 to end purchase)\n");
        scanf("%s", icode);
    };//end of while loop
	
					printf("***********************************\n");//output receipt for every transaction
                    printf("Total transaction : %d\n",trans);
                    printf("Sales with GST    : %.2fRM\n",sumgst);
                    printf("Sales without GST : %.2fRM\n",sumngst);
                    printf("GST collected     : %.2fRM\n",sumtax);
                    printf("Total bill        : %.2fRM\n",total);
                    printf("***********************************\n");
					
break;//end of a case in switch statement

case 2:
	printf("----------------------------\n");//function to edit the files structure
    printf("      EDIT INFO\n");
    printf("----------------------------\n");
    printf("Enter item code:\n");
    scanf("%s", icode);

    struct Product newValues;//user input
    printf("Enter name:\n");
    scanf("%s", newValues.name);
    printf("Enter price:\n");
    scanf("%lf", &newValues.price);
    printf("Enter quantity:\n");
    scanf("%d", &newValues.quantity);
    if(editGST(icode, newValues) == 1){//comparing the function with the new data
        printf("Product edited.\n");
    }else if(editNGST(icode, newValues) == 1){
        printf("Product edited.\n");
    }else{
        printf("Product does not exist.\n");
    }
break;

case 3:
	printf("-------------------------------\n");
	printf("	ADD ITEM\n");
	printf("-------------------------------\n");
	printf("1.GST Items\n");
	printf("2.Non-GST Items\n");
	scanf("%d",&add);
	
	switch(add) //start of switch statement
	{
		case 1:
		fptr = fopen("gst.txt", "a"); //open file
		if(fptr==NULL)//checking whether the file is empty or not
		{
			printf("File cannot be found\n");
			
		}
		else //else statement
		{
			printf("Add Item Code:\n");
			scanf("%s", product.code);
			printf("Item name:\n");
			scanf(" %[^\n]", product.name);
			printf("Item price:\n");
			scanf("%lf",&product.price);
			printf("Item quantity:\n");
			scanf("%d", &product.quantity);
			
			fprintf(fptr,"%s;%s;%.2f;%d\n",product.code,product.name,product.price,product.quantity);
		fclose(fptr);
		}//end else statement
		break;
		
		case 2:
		nfptr = fopen("ngst.txt", "a"); //open file
		if(nfptr==NULL)//checking whether the file is empty or not
		{
			printf("File cannot be found\n");
			
		}
		else //else statement
		{
			printf("Add Item Code:\n");
			scanf("%s", product.code);
			printf("Item name:\n");
			scanf(" %[^\n]", product.name);
			printf("Item price:\n");
			scanf("%lf",&product.price);
			printf("Item quantity:\n");
			scanf("%d", &product.quantity);
			
			fprintf(nfptr,"%s;%s;%.2f;%d\n",product.code,product.name,product.price,product.quantity);
		fclose(nfptr);
		}//end else statement
		break;
	}
	break;
				
           
case 4:
    printf("----------------------------\n");//function for deleting a data in the file
    printf("      DELETE INFO\n");
    printf("----------------------------\n");
    printf("Enter item code:\n");
    scanf("%s", icode);//user input
    int type = 0; //Not found
    struct Product product;

    FILE *check = fopen("gst.txt", "r");//creating a new file
    fscanf(check, "%[^;];%[^;];%lf;%d\n", product.code, product.name, &product.price, &product.quantity);
    while(!feof(check))
    {
        if(strcmp(icode, product.code) == 0)
        {
            type = 1; //GST
        }
        fscanf(check, "%[^;];%[^;];%lf;%d\n", product.code, product.name, &product.price, &product.quantity);
    }fclose(check);

    //Couldn't found it yet, look for this item in the ngst.txt
    if(type == 0){
        check = fopen("ngst.txt", "r");
        fscanf(check, "%[^;];%[^;];%lf;%d\n", product.code, product.name, &product.price, &product.quantity);
        while(!feof(check))
        {
            if(strcmp(icode, product.code) == 0)
            {
                type = 2; //NGST
            }
            fscanf(check, "%[^;];%[^;];%lf;%d\n", product.code, product.name, &product.price, &product.quantity);
        }fclose(check);
    }

    switch(type){//switching to search which value matches the input
        case 1:
            if(product.quantity==0)
            {
            dtemp = fopen("deletetemp.txt", "w");//opening file for write.
            int found = 0;
            fptr = fopen("gst.txt", "r");
            while(!feof(fptr))
            {
                fscanf(fptr, "%[^;];%[^;];%lf;%d\n", product.code, product.name, &product.price, &product.quantity);//reading from the file
                if(strcmp(icode, product.code) != 0)
                {
                    fprintf(dtemp, "%s;%s;%lf;%d\n", product.code, product.name, product.price, product.quantity);
                }
            }fclose(fptr);
            remove("gst.txt");//removing one file and replacing it with another
            rename("deletetemp.txt", "gst.txt");
            fclose(dtemp);//file close
            printf("Deletion was successful.\n");
            }
            else
            {
                printf("Cannot delete the product as quantity is not 0.\n");
            }
        break;

        case 2:
            if (product.quantity==0)
            {
            dtemp = fopen("deletetemp.txt", "w");
            fptr = fopen("ngst.txt", "r");//opening a file to read from it
            while(!feof(fptr))
            {
                fscanf(fptr, "%[^;];%[^;];%lf;%d\n", product.code, product.name, &product.price, &product.quantity);
                if(strcmp(icode, product.code) != 0)
                {
                    fprintf(dtemp, "%s;%s;%lf;%d\n", product.code, product.name, product.price, product.quantity);
                }
            }fclose(fptr);
            remove("ngst.txt");
            rename("deletetemp.txt", "ngst.txt");
            fclose(dtemp);
            printf("Deletion was successful.\n");
            }
            else
            {
                printf("Cannot delete the product as quantity is not 0.\n");
            }
        break;

        default:
            printf("This is an invalid item.\n");//for default value
        break;
    }

break;
				
case 5:
    printf("--------------------\n");//inventory function
    printf("      Inventory     \n");
    printf("--------------------\n\n");
    printf("1. GST Items\n");
    printf("2. Non-GST Items\n");
    scanf("%d",&invent);

    switch(invent)//start of switch statement
    {
        case 1:
            fptr = fopen("gst.txt", "r");//opening a file
            if(fptr==NULL)//checking whether the file is empty or not
                {
                    printf("File cannot be found\n");
            }
            else//else statement
                {
                    printf("***********************************\n");
                    printf("         GST Items\n");
                    printf("***********************************\n");
                    while(!feof(fptr))
                    {
                        fscanf(fptr," %[^;];%[^;];%lf;%d\n", product.code, product.name, &product.price, &product.quantity);
                        printf(" %s %s %.2f %d\n", product.code, product.name, product.price, product.quantity);
                    }fclose(fptr); //close file pointer
                };//end else statement
        break;

        case 2:
            nfptr = fopen("ngst.txt", "r");//file operation
            if(nfptr==NULL)//start of if else statement
                {
                    printf("File cannot be found\n");
            }
            else//else statement
                {
                    printf("***********************************\n");
                    printf("         Non-GST Items\n");
                    printf("***********************************\n");
                    while(!feof(nfptr))
                    {
                        fscanf(nfptr," %[^;];%[^;];%lf;%d\n", product.code, product.name, &product.price, &product.quantity);
                        printf(" %s %s %.2f %d\n", product.code, product.name, product.price, product.quantity);
                    }fclose(nfptr);//closing the file pointer
                };//end else
        break;

        default: printf("Invalid input! Choose only 1 or 2\n");//error message if no value matches

        break;
        }
break;

case 6:
    printf("--------------------------------\n");//list of daily transaction
    printf("   Daily Transactions\n");
	printf("--------------------------------\n");
    printf("Total transaction     :%d\n", trans);
	printf("Sales with GST        :%.2f\n", sumgst);
	printf("Sales without GST     :%.2f\n", sumngst);
	printf("GST collected         :%.2f\n", sumtax);
	printf("\n");
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


int editGST(char *itemCode, struct Product product)//declaring function
{
    struct Product tmp;//declaring structure
    int found = 0;
    FILE *gst = fopen("gst.txt", "r");
    FILE *temp = fopen("temp.txt", "w");//opening file
    fscanf(gst, "%[^;];%[^;];%lf;%d\n", tmp.code, tmp.name, &tmp.price, &tmp.quantity);
    while(!feof(gst)){
        if(strcmp(tmp.code, itemCode)==0){//compare two values
            fprintf(temp, "%s;%s;%lf;%d\n", itemCode, product.name, product.price, product.quantity);
            found = 1;
        }else{
            fprintf(temp, "%s;%s;%lf;%d\n", tmp.code, tmp.name, tmp.price, tmp.quantity);
        }
        fscanf(gst, "%[^;];%[^;];%lf;%d\n", tmp.code, tmp.name, &tmp.price, &tmp.quantity);
    }fclose(gst);//closing a file
    fclose(temp);

    remove("gst.txt");//replacing a file with another temporary file
    rename("temp.txt", "gst.txt");

    return found;
}

int editNGST(char *itemCode, struct Product product)//declaring function
{
    struct Product tmp;//declaring structure
    int found = 0;
    FILE *gst = fopen("ngst.txt", "r");//opening file
    FILE *temp = fopen("temp.txt", "w");
    fscanf(gst, "%[^;];%[^;];%lf;%d\n", tmp.code, tmp.name, &tmp.price, &tmp.quantity);
    while(!feof(gst)){//to read until the end of file
        if(strcmp(tmp.code, itemCode)==0)
        {
            fprintf(temp, "%s;%s;%lf;%d\n", itemCode, product.name, product.price, product.quantity);
            found = 1;
        }
        else
        {
            fprintf(temp, "%s;%s;%lf;%d\n", tmp.code, tmp.name, tmp.price, tmp.quantity);
        }
        fscanf(gst, "%[^;];%[^;];%lf;%d\n", tmp.code, tmp.name, &tmp.price, &tmp.quantity);
    }fclose(gst);
    fclose(temp);//closing the files

    remove("ngst.txt");
    rename("temp.txt","ngst.txt");

    return found;//returns the value back
}
