void edit_meal(){
	int option;
	char mcode[6];
	struct Meal newValues;
    struct Meal meal;
    struct Meal tmp;
    int found = 0;
	FILE *cptr;
	FILE *aptr;
    FILE *temp;
    FILE *atemp;

	printf("----------------------------\n");//function to edit the files structure
    printf("      EDIT MEAL\n");
    printf("----------------------------\n");
    printf("Enter meal code:\n");
    scanf("%s", mcode);   

    cptr = fopen("combo.txt", "r");//creating a new file            
    while(!feof(cptr))
    {                   
        fscanf(cptr, "%[^:]:%[^:]:%f:%[^\n]", meal.mcode, meal.name, &meal.price, meal.description);
        if(strcmp(mcode, meal.mcode) == 0)
        {
            found = 1; //combo
        }       
    }fclose(cptr);
    
    if(found == 0){
        aptr = fopen("addon.txt", "r");                
        while(!feof(aptr))
        {
            fscanf(aptr, "%[^:]:%[^:]:%f:%[^\n]", meal.mcode, meal.name, &meal.price, meal.description);
            if(strcmp(mcode, meal.mcode) == 0)
            {
                found = 2; //addon
            }            
        }fclose(aptr);
    }

    if (found > 0){
        printf("Enter option (1 to 3) to edit: \n");
        printf("[1] Name \n");
        printf("[2] Price \n");
        printf("[3] Description \n");
        scanf("%d", &option);
    }

    switch(found){
        case 1:                      
            cptr = fopen("combo.txt", "r");
            temp = fopen("temp.txt", "w");//opening file    
            while(!feof(cptr)){
                fscanf(cptr, " %[^:]:%[^:]:%f:%[^\n]\n", tmp.mcode,tmp.name,&tmp.price,tmp.description);
                if(strcmp(mcode, tmp.mcode)==0){//compare two values
                    switch(option){
                        case 1:
                            printf("Enter New Meal Name: \n");
                            scanf(" %[^\n]", newValues.name);
                            fprintf(temp, "%s:%s:%.2f:%s\n", mcode, newValues.name, tmp.price, tmp.description);
                            break;
                        case 2:
                            printf("Enter New Meal Price: \n");
                            scanf(" %f", &(newValues.price));
                            fprintf(temp, "%s:%s:%.2f:%s\n", mcode, tmp.name, newValues.price, tmp.description);
                            break;
                        case 3:
                            printf("Enter New Meal Description: \n");
                            scanf(" %[^\n]", newValues.description);
                            fprintf(temp, "%s:%s:%.2f:%s\n", mcode, tmp.name, tmp.price, newValues.description);
                            break;
                        default:
                            break;    
                    }                                        
                }else{
                    fprintf(cptr, "%s:%s:%.2f:%s\n", tmp.mcode, tmp.name, tmp.price, tmp.description);
                }
                // fscanf(combo, "%[^:]:%[^:]:%f:%[^\n]\n", tmp.mcode,tmp.name,&tmp.price,tmp.description);
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
                            printf("Enter New Meal Name: \n");
                            scanf(" %[^\n]", newValues.name);
                            fprintf(atemp, "%s:%s:%.2f:%s\n", mcode, newValues.name, tmp.price, tmp.description);
                            break;
                        case 2:
                            printf("Enter New Meal Price: \n");
                            scanf(" %f", &(newValues.price));
                            fprintf(atemp, "%s:%s:%.2f:%s\n", mcode, tmp.name, newValues.price, tmp.description);
                            break;
                        case 3:
                            printf("Enter New Meal Description: \n");
                            scanf(" %[^\n]", newValues.description);
                            fprintf(temp, "%s:%s:%.2f:%s\n", mcode, tmp.name, tmp.price, newValues.description);
                            break;
                        default:
                            break;    
                    }                                        
                }else{
                    fprintf(aptr, "%s:%s:%.2f:%s\n", tmp.mcode, tmp.name, tmp.price, tmp.description);
                }
                // fscanf(combo, "%[^:]:%[^:]:%f:%[^\n]\n", tmp.mcode,tmp.name,&tmp.price,tmp.description);
            }fclose(cptr);//closing a file
            fclose(atemp);
            remove("combo.txt");//replacing a file with another temporary file
            rename("atemp.txt", "combo.txt"); 
            break;
        default:
            break;    
    }
}
