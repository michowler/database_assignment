#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include <stdint.h>





void combo();
void addon();
int main_menu();
void main_function();
int purchase();
float receipt();

void available_meal();
void daily_transactions();
int main()
{
    main_function();
  return 0;
}



void combo(){
    int i=1;

char combo_code[200];
char combo_name[200];
double combo_price;
char combo_desc[200];

FILE *cfPtr = fopen ("combo.txt", "r");
if (cfPtr == NULL ){
    puts ("File could not be opened");

}
else {
    printf ("%70s\n", "Combo Meals");
    printf ("================================================================================================================================\n");
    printf ("%s%30s%30s%40s\n","COMBO_CODE", "MEAL_NAME", "MEAL_PRICE", "MEAL_DESCRIPTION" );
    printf ("----------                  -------------------         --------------------            ----------------------------\n");
    for (i =1; i <= 5; i++)
    {
        fscanf (cfPtr, "%[^:]:%[^:]:%lf:%[^\n]\n", combo_code, combo_name, &combo_price, combo_desc);
        printf ("%-30s%-30s%-30.2f%-30s\n", combo_code, combo_name, combo_price, combo_desc);
    }

    }
    fclose (cfPtr);
    printf ("\n");

}


void addon(){
    int j=1;
char addon_code[200];
char addon_name[200];
double addon_price;
char addon_desc[200];

FILE *dfPtr = fopen ("addon.txt", "r");

if (dfPtr == NULL ){
    puts ("File could not be opened");

}
else {
    printf ("%80s\n", "Ala- Carte Meals / Add-On Meals");
    printf ("==============================================================================================================================\n");
    printf ("%s%30s%30s%40s\n","ADDON_CODE", "ADDON_NAME", "MEAL_PRICE", "MEAL_DESCRIPTION" );
    printf ("----------                  -------------------         --------------------            ----------------------------\n");
    for (j=1; j <=5 ; j++){
        fscanf (dfPtr, "%[^:]:%[^:]:%lf:%[^\n]\n", addon_code, addon_name, &addon_price, addon_desc);
        printf ("%-30s%-30s%-30.2f%-30s\n", addon_code, addon_name, addon_price, addon_desc);

    }
}
    fclose (dfPtr);
    printf ("\n");

}


int main_menu(){
int option;

printf ("\n---------------------------------------\n");
printf ("\nFast Food Ordering System\n");
printf ("\n---------------------------------------\n");
printf ("\t 1. Purchase \n");
printf ("\t 2. Edit Meal\n");
printf ("\t 3. Add Meal\n");
printf ("\t 4. Delete Meal\n");
printf ("\t 5. Show Available Meal\n");
printf ("\t 6. Show Daily Transaction\n");
printf ("\t 7. Exit\n");
printf ("\nPlease choose an option to proceed (enter -1 to end):\n");
scanf ("%d", &option);

return option;
}





int purchase(int sentinelValue){

char meal_code[200];
char combo_desc[200];
char addon_desc[200];
int i = 1;
int j = 1;

int Tcombo = 0;
int Taddon = 0;
double Tsales;
int quantity;
double cost = 0;
int loopC = 0;
int ctrl = 1;
    double GST;/*tax */
    double total_order;
    double subtotal = 0;
    double total = 0;


int C1, C2, C3, C4, C5, A1, A2, A3, A4, A5, c1, c2, c3, c4, c5, a1, a2, a3, a4, a5;
double returnVal;

if (sentinelValue == 1)
    {
     returnVal = C1;
    }
else if (sentinelValue == 2)
    {
     returnVal = C2;
    }
else if (sentinelValue == 3)
    {
    returnVal = C3;
    }
else if (sentinelValue == 4)
    {
     returnVal = C4;
    }
else if (sentinelValue == 5)
    {
     returnVal = C5;
    }
else if (sentinelValue == 6)
    {
     returnVal = A1;
    }
else if (sentinelValue == 7)
    {
     returnVal = A2;
    }
else if (sentinelValue == 8)
    {
     returnVal = A3;
    }
else if (sentinelValue == 9)
   {
    returnVal = A4;
   }
else if (sentinelValue == 10)
   {
    returnVal = A5;
   }

   else {

           while (sentinelValue != -1){
                ctrl = 1;
                if (ctrl == 1){
            printf ("\nPlease enter meal code (enter -1 to end) : \n");
            scanf ("%s", meal_code);

            total = quantity * cost;




            if (strcmp(meal_code, "C0001")== 0 || strcmp(meal_code, "c0001")== 0)
            {
             printf ("\nEnter number of quantities per meal\n");
             scanf ("%d", &quantity);
             cost = 10.99;

             Tcombo++;
            }

            else if (strcmp(meal_code, "C0002")== 0 || strcmp(meal_code, "c0002")== 0)
            {
             printf ("\nEnter number of quantities per meal\n");
             scanf ("%d", &quantity);
             cost = 12.99;

             Tcombo++;
            }

            else if (strcmp(meal_code, "C0003")== 0 || strcmp(meal_code, "c0003")== 0)
            {
             printf ("\nEnter number of quantities per meal\n");
             scanf ("%d", &quantity);
             cost = 6.99;

             Tcombo++;
            }

            else if (strcmp(meal_code, "C0004")== 0 || strcmp(meal_code, "c0004")== 0)
            {
             printf ("\nEnter number of quantities per meal\n");
             scanf ("%d", &quantity);
             cost = 12.99;

             Tcombo++;
            }

            else if (strcmp(meal_code, "C0005")== 0 || strcmp(meal_code, "c0005")== 0)
            {
             printf ("\nEnter number of quantities per meal\n");
             scanf ("%d", &quantity);
             cost = 14.99;

             Tcombo++;
            }

            else if (strcmp(meal_code, "A0001")== 0 || strcmp(meal_code, "a0001")== 0)
            {
             printf ("\nEnter number of quantities per meal\n");
             scanf ("%d", &quantity);
             cost = 3.99;

             Taddon++;
            }
            else if (strcmp(meal_code, "A0002")== 0 || strcmp(meal_code, "a0002")== 0)
            {
             printf ("\nEnter number of quantities per meal\n");
             scanf ("%d", &quantity);
             cost = 3.99;

             Taddon++;
            }

            else if (strcmp(meal_code, "A0003")== 0 || strcmp(meal_code, "a0003")== 0)
            {
             printf ("\nEnter number of quantities per meal\n");
             scanf ("%d", &quantity);
             cost = 6.99;

             Taddon++;
            }

            else if (strcmp(meal_code, "A0004")== 0 || strcmp(meal_code, "a0004")== 0)
            {
             printf ("\nEnter number of quantities per meal\n");
             scanf ("%d", &quantity);
             cost = 4.99;

             Taddon++;
            }

            else if (strcmp(meal_code, "A0005")== 0 || strcmp(meal_code, "a0005")== 0)
             {
              printf ("\nEnter number of quantities per meal\n");
             scanf ("%d", &quantity);
             cost = 8.99;

             Taddon++;

             }




             else if (strcmp(meal_code,"-1") == 0)
             {
               ctrl = 0;
             }

             else {
                ctrl = 0;
                printf ("Invalid Item\n");
             }

             if (loopC == 0){
                C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0, A1 = 0, A2 = 0, A3 = 0, A4 = 0, A5 = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0;
             }


             printf ("\nThe meal code %s, price per meal is %.2f ,quantity of per meal is %d and subtotal of the meal is %d\n", meal_code, cost, quantity, total);


              }
             else {

    FILE *cfPtr = fopen ("combo.txt", "r");
    FILE *dfPtr = fopen ("addon.txt", "r");



    if (cfPtr == NULL){
        puts ("File could not be opened");

    }
    else {
    printf ("%30s\n", "FAST FOOD RESTAURANT");
    printf ("=======================================================================\n");
    printf ("%s%30s%30s", "QTY","ITEM", "TOTAL\n");
    printf ("-----                --------------------             -----------------\n");
    fscanf (cfPtr, "%[^:]\n", combo_desc);
    printf ("%d%s%d", quantity, combo_desc,total);

    fscanf (dfPtr, "%[^:]\n", addon_desc);
    printf ("%-100d%-100s%-100d", quantity, combo_desc,total);


     GST = total * 0.06;
     Tsales += total;


    printf ("\n=================\n");
    printf ("%12s%15.2f\n", "Total Order",  Tsales);
    printf ("%10s%15.2f\n", "Tax (GST):", GST);


    }
    fclose(cfPtr);
    fclose(dfPtr);
    printf ("\n");

}
           }
   }
}
















void daily_transactions(int Tcombo, int Taddon, double Tsales, double GST)
{



    printf ("%-60s%-10s%d\n", "Total combo meal transaction",":", Tcombo);
    printf ("%-60s%-10s%d\n", "Total ala-carte transaction",":", Taddon);
    printf ("%-60s%-10s%d\n", "Total sales",":", Tsales);
    printf ("%-60s%-10s%d\n", "GST collected",":", GST);
}



void main_function(){
int option = main_menu();
int sentinelValue;
double Tsales = 0;
double Tgst = 0;
int Tcombo =0;
int alaT = 0;


while (option != 8)
{
    switch (option)
    {

    case 1:
        purchase(sentinelValue);
        break;

    case 2:
        printf ("\nThis option allows edit meals.\n");
        break;

    case 3:
        printf ("\nThis option allows user to add meals\n");
        break;

    case 4:
        printf ("\nThis option allows user to delete meals\n");
        break;

    case 5:
        combo();
        addon();

        break;

    case 6:
        daily_transactions(Tcombo,alaT, Tsales,  Tgst);
        break;

    case 7:
        printf("\nThank You Very Much !\n ");
        exit(0);
        break;

    default:
        printf ("\nInvalid option.\nPlease try again.\n");
        break;
    }

    option = main_menu();
}
}







