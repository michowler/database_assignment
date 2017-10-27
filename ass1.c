//
//  main.c
//  assignment1
//
//  Created by macbook on 25/10/2017.
//  Copyright © 2017 louissa. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define SIZE 200 //array size 200
#define NUM_COMBOITEMS 5
#define NUM_ALAITEMS 5


//prototype
void fileprocess(char menuCode[6],char name[40],double price,char description[SIZE]);



int main(void){
    
    //array data
    char name[40];
    char menuCode[6];
    char description[SIZE];
    double price;
    
    int code;
    int i,j,qty;
    double combosubt;
    double alasubt;
    
    FILE *repPtr;
    FILE *comPtr;
    FILE *addPtr;
    
    do{
        printf("--------------------------------------\n");
        printf("Fast Food Ordering System");
        printf("\n--------------------------------------\n\n");
        printf("1. Purchase\n");
        printf("2. Edit Meal\n");
        printf("3. Add Meal\n");
        printf("4. Delete Meal\n");
        printf("5. Show Available Meal\n");
        printf("6. Show Daily Transaction\n");
        printf("7. Exit\n\n");
        
        printf("Enter menu: ");
        scanf("%d",&code);
    
    switch (code) {
        case 1:
            do{
                printf("Hi, what would you like to order?\n");
                printf("Insert meal code:\n");
                scanf("%s",menuCode);
                
                if (strcmp(menuCode,"C0001")==0 || strcmp(menuCode,"c0001")==0){
                    printf("Quantity: \n");
                    scanf("%d",&qty);
                    repPtr = fopen("receipt.txt", "a+");
                    comPtr = fopen("combo.txt", "r");
                    for(i=0;i<1;i++){
                        fscanf(comPtr,"%[^:]:%[^:]:%lf:%[^\n]\n",menuCode,name,&price,description);
                    }
                    combosubt = qty *price;
                    printf("\t--MenuCode: %s\n\t--Name: %s\n\t--Price(per set): $%.2f\n\t--Description: %s\n\t--Qty: %d\n\t--Total price: $%.2f\n",menuCode,name,price,description,qty,combosubt);
                    fprintf(repPtr,"%s:%s:%.2f:%s:%d:%.2f\n",menuCode,name,price,description,qty,combosubt);
                    fclose(comPtr);
                    fclose(repPtr);
                    
                    
                }else if
                    (strcmp(menuCode,"C0002")==0 || strcmp(menuCode,"c0002")==0){
                        printf("Quantity: \n");
                        scanf("%d",&qty);
                        
                        comPtr = fopen("combo.txt", "r");
                            for(i=0;i<2;i++){
                                fscanf(comPtr,"%[^:]:%[^:]:%lf:%[^\n]\n",menuCode,name,&price,description);
                            }
                        combosubt =qty*price;
                        printf("\t--MenuCode: %s\n\t--Name: %s\n\t--Price(per set): %.2f\n\t--Description: %s\n\t--Qty: %d\n\t--Total price: $%.2f\n",menuCode,name,price,description,qty,combosubt);
                        
                        fclose(comPtr);
                }else if
                    (strcmp(menuCode,"C0003")==0 || strcmp(menuCode,"c0003")==0){
                        printf("Quantity: \n");
                        scanf("%d",&qty);
                       
                        comPtr = fopen("combo.txt", "r");
                            for(i=0;i<3;i++){
                                fscanf(comPtr,"%[^:]:%[^:]:%lf:%[^\n]\n",menuCode,name,&price,description);
                            }
                                combosubt = qty *price;
                                printf("\t--MenuCode: %s\n\t--Name: %s\n\t--Price(per set): %.2f\n\t--Description: %s\n\t--Qty: %d\n\t--Total price: $%.2f\n",menuCode,name,price,description,qty,combosubt);
                            
                            fclose(comPtr);
                            
                }else if
                    (strcmp(menuCode,"C0004")==0 || strcmp(menuCode,"c0004")==0){
                        printf("Quantity: \n");
                        scanf("%d",&qty);
                        
                        comPtr = fopen("combo.txt", "r");
                            for(i=0;i<4;i++){
                                fscanf(comPtr,"%[^:]:%[^:]:%lf:%[^\n]\n",menuCode,name,&price,description);
                            }
                                combosubt = qty *price;
                                printf("\t--MenuCode: %s\n\t--Name: %s\n\t--Price(per set): %.2f\n\t--Description: %s\n\t--Qty: %d\n\t--Total price: $%.2f\n",menuCode,name,price,description,qty,combosubt);
                                
                                fclose(comPtr);
                                
              }else if
                    (strcmp(menuCode,"C0005")==0 || strcmp(menuCode,"c0005")==0){
                        printf("Quantity: \n");
                        scanf("%d",&qty);
                        
                        comPtr = fopen("combo.txt", "r");
                            for(i=0;i<5;i++){
                                fscanf(comPtr,"%[^:]:%[^:]:%lf:%[^\n]\n",menuCode,name,&price,description);
                            }
                                combosubt = qty *price;
                                printf("\t--MenuCode: %s\n\t--Name: %s\n\t--Price(per set): %.2f\n\t--Description: %s\n\t--Qty: %d\n\t--Total price: $%.2f\n",menuCode,name,price,description,qty,combosubt);
                                    
                                fclose(comPtr);
                                    
             }else if
                   (strcmp(menuCode,"A0001")==0 || strcmp(menuCode,"a0001")==0){
                        printf("Quantity: \n");
                        scanf("%d",&qty);
                       
                        addPtr = fopen("addon.txt", "r");
                            for(i=0;i<1;i++){
                                fscanf(addPtr,"%[^:]:%[^:]:%lf:%[^\n]\n",menuCode,name,&price,description);
                            }
                               alasubt = qty *price;
                                printf("\t--MenuCode: %s\n\t--Name: %s\n\t--Price(per set): %.2f\n\t--Description: %s\n\t--Qty: %d\n\t--Total price: $%.2f\n",menuCode,name,price,description,qty,alasubt);
                                        
                                fclose(addPtr);
                                        
            }else if
                (strcmp(menuCode,"A0002")==0 || strcmp(menuCode,"a0002")==0){
                        printf("Quantity: \n");
                        scanf("%d",&qty);
                    
                        addPtr = fopen("addon.txt", "r");
                            for(i=0;i<2;i++){
                                fscanf(addPtr,"%[^:]:%[^:]:%lf:%[^\n]\n",menuCode,name,&price,description);
                            }
                                alasubt = qty *price;
                                printf("\t--MenuCode: %s\n\t--Name: %s\n\t--Price(per set): %.2f\n\t--Description: %s\n\t--Qty: %d\n\t--Total price: $%.2f\n",menuCode,name,price,description,qty,alasubt);
                                            
                                fclose(addPtr);
                                            
                                        }else if
                                            (strcmp(menuCode,"A0003")==0 || strcmp(menuCode,"a0003")==0){
                                                printf("Quantity: \n");
                                                scanf("%d",&qty);
                                                
                                                addPtr = fopen("addon.txt", "r");
                                                for(i=0;i<3;i++){
                                                    fscanf(addPtr,"%[^:]:%[^:]:%lf:%[^\n]\n",menuCode,name,&price,description);
                                                }
                                                alasubt = qty *price;
                                                printf("\t--MenuCode: %s\n\t--Name: %s\n\t--Price(per set): %.2f\n\t--Description: %s\n\t--Qty: %d\n\t--Total price: $%.2f\n",menuCode,name,price,description,qty,alasubt);
                                                
                                                fclose(addPtr);
                                                
                                            }else if
                                                (strcmp(menuCode,"A0004")==0 || strcmp(menuCode,"a0004")==0){
                                                    printf("Quantity: \n");
                                                    scanf("%d",&qty);
                                                    
                                                    addPtr = fopen("addon.txt", "r");
                                                    for(i=0;i<4;i++){
                                                        fscanf(addPtr,"%[^:]:%[^:]:%lf:%[^\n]\n",menuCode,name,&price,description);
                                                    }
                                                    alasubt = qty *price;
                                                    printf("\t--MenuCode: %s\n\t--Name: %s\n\t--Price(per set): %.2f\n\t--Description: %s\n\t--Qty: %d\n\t--Total price: $%.2f\n",menuCode,name,price,description,qty,alasubt);
                                                    
                                                    fclose(addPtr);
                                                    
                                                }else if
                                                    (strcmp(menuCode,"A0005")==0 || strcmp(menuCode,"a0005")==0){
                                                        printf("Quantity: \n");
                                                        scanf("%d",&qty);
                                                        
                                                        addPtr = fopen("addon.txt", "r");
                                                        for(i=0;i<5;i++){
                                                            fscanf(addPtr,"%[^:]:%[^:]:%lf:%[^\n]\n",menuCode,name,&price,description);
                                                        }
                                                        alasubt = qty *price;
                                                        printf("\t--MenuCode: %s\n\t--Name: %s\n\t--Price(per set): %.2f\n\t--Description: %s\n\t--Qty: %d\n\t--Total price: $%.2f\n",menuCode,name,price,description,qty,alasubt);
                                                        
                                                        fclose(addPtr);
                                                    }
                
            }while (strcmp(menuCode,"z")!=0);
            
            //print receipt
            
            if(combosubt!=0 || alasubt!=0){
                printf("====Your orders====");
                printf("\n%s\t%s\t%s\t%s\t%s\t%s\n","Menu Code","Name","Price(per set)","Des","qty","total");
                repPtr = fopen("receipt.txt", "r");
                
                fscanf(comPtr,"%[^:]:%[^:]:%lf:%[^:]:%d:%lf\n",menuCode,name,&price,description,qty,combosubt);
            
            
            printf("\n%s\t%s\t$%.2f\t%s\t%d\t$%.2f\n",menuCode,name,price,description,qty,combosubt);
    
    }
           
            break;
            
        case 2:
            printf("This option allows user to edit meals\n\n");
            break;
        case 3:
            printf("This option allows user to add meals\n\n");
            break;
        case 4:
            printf("This option allows user to delete meals\n\n");
            break;
        case 5:
            //show available meal
            fileprocess(menuCode,name,price,description);
            break;
        case 6:
            //show daily transactions
            break;
        case 7:
            break;
            
        default:
            printf("Invalid Code!\n");
            break;
    }//end switch menuCode
       
    
    
    
    }while (code!=7);//end system
    
  
}//end main


void fileprocess(char menuCode[6],char name[40],double price,char description[SIZE]){
    
// combo menu
    printf("--------------------------------------- COMBO MEAL MENU -------------------------------------------\n\n");
    
    FILE *comPtr;
    if ((comPtr = fopen("combo.txt", "r"))== NULL)
    {
        puts("File could not be opened");
    }else{
        
        printf("%-16s%-24s%-19s%-18s\n\n","Menu Code","Meal Name","Meal Price","Meal Description");
        
        while (!feof(comPtr)){
            
            fscanf(comPtr, "%[^:]:%[^:]:%lf:%[^\n]\n",menuCode,name,&price,description);
            
            printf("%-15s%-27s%-17.2f%-12s\n",menuCode,name,price,description);
            
        }
        fclose(comPtr);
        
    } printf("\n---------------------------------------------------------------------------------------------------\n\n");
    
    
    
//ala carte menu

    printf("----------------------------------------- ADD ON MENU ---------------------------------------------\n\n");
    FILE *addPtr;
    if ((addPtr = fopen("addon.txt", "r"))== NULL)
    {
        puts("File could not be opened");
    }else{
        printf("%-16s%-24s%-19s%-18s\n\n","Menu Code","Meal Name","Meal Price","Meal Description");
        
        while (!feof(addPtr)){
            fscanf(addPtr, "%[^:]:%[^:]:%lf:%[^\n]\n",menuCode,name,&price,description);
            printf("%-15s%-27s%-17.2f%-12s\n",menuCode,name,price,description);
            
        }
        fclose(addPtr);
    }
    printf("\n---------------------------------------------------------------------------------------------------\n\n");
    
}//end file process


