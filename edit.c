void edit_meal(){
	int option;
	char mcode[6];
	struct Meal newValues;//user input
	struct Meal meal;//user input
    int found = 0;
	FILE *cptr;
	FILE *aptr;
    FILE *temp;

	printf("----------------------------\n");//function to edit the files structure
    printf("      EDIT MEAL\n");
    printf("----------------------------\n");
    printf("Enter meal code:\n");
    scanf("%s", mcode);   

    struct Meal tmp;
    int found = 0;

    cptr = fopen("combo.txt", "r");
    temp = fopen("temp.txt", "w");
    while(!feof(cptr)){
        fscanf(cptr, " %[^:]:%[^:]:%f:%[^\n]\n", tmp.mcode,tmp.name,&tmp.price,tmp.description);
        if(strcmp(menuCode, tmp.mcode)==0){//compare two values
            fprintf(temp, "%s:%s:%.2f:%s\n", menuCode, meal.name, tmp.price, tmp.description);
            found = 1;
        }else{
            fprintf(temp, "%s:%s:%.2f:%s\n", tmp.mcode, tmp.name, tmp.price, tmp.description);
        }
        // fscanf(combo, "%[^:]:%[^:]:%f:%[^\n]\n", tmp.mcode,tmp.name,&tmp.price,tmp.description);
    }fclose(combo);//closing a file
    fclose(temp);
    remove("combo.txt");//replacing a file with another temporary file
    rename("temp.txt", "combo.txt");
    
    switch (option) {
    	case 1:			    		
    		printf("Enter name:\n");
    		scanf(" %[^\n]", newValues.name);
    		if(editCombo(mcode, newValues) == 1){//comparing the function with the new data
    		    printf("Meal code %s edited!\n", mcode);
    		}else if(editAddon(mcode, newValues) == 1){
    		    printf("Meal code %s edited!\n", mcode);
    		}else{
    		    printf("Invalid meal code!\n");
    		}	
    		break;
    	case 2:
    		printf("Enter price:\n");
    		scanf(" %f", &(newValues.price));
    		if(editCombo(mcode, newValues) == 1){//comparing the function with the new data
    		    printf("Meal code %s edited!\n", mcode);
    		}else if(editAddon(mcode, newValues) == 1){
    		    printf("Meal code %s edited!\n", mcode);
    		}else{
    		    printf("Invalid meal code!\n");
    		}			    		
    		break;
    	case 3:
    		printf("Enter description:\n");
    		scanf(" %[^\n]", newValues.description);
    		if(editCombo(mcode, newValues) == 1){//comparing the function with the new data
    		    printf("Meal code %s edited!\n", mcode);
    		}else if(editAddon(mcode, newValues) == 1){
    		    printf("Meal code %s edited!\n", mcode);
    		}else{
    		    printf("Invalid meal code!\n");
    		}
    		break;	
    	default:
    		printf("Invalid meal code!\n");
    		break;		
    }			    			    	
}

int editCombo(char *menuCode, struct Meal meal)
{
    struct Meal tmp;//declaring structure
    int found = 0;
    FILE *combo = fopen("combo.txt", "r");
    FILE *temp = fopen("temp.txt", "w");//opening file    
    while(!feof(combo)){
    	fscanf(combo, "%[^:]:%[^:]:%f:%[^\n]\n", tmp.mcode,tmp.name,&tmp.price,tmp.description);
        if(strcmp(menuCode, tmp.mcode)==0){//compare two values
            fprintf(temp, "%s:%s:%.2f:%s\n", menuCode, meal.name, tmp.price, tmp.description);
            found = 1;
        }else{
            fprintf(temp, "%s:%s:%.2f:%s\n", tmp.mcode, tmp.name, tmp.price, tmp.description);
        }
        // fscanf(combo, "%[^:]:%[^:]:%f:%[^\n]\n", tmp.mcode,tmp.name,&tmp.price,tmp.description);
    }fclose(combo);//closing a file
    fclose(temp);
    remove("combo.txt");//replacing a file with another temporary file
    rename("temp.txt", "combo.txt");

    return found;
}

int editAddon(char *menuCode, struct Meal meal)//declaring function
{
    struct Meal tmp;//declaring structure
    int found = 0;
    FILE *addon = fopen("addon.txt", "r");
    FILE *temp = fopen("temp.txt", "w");//opening file    
    while(!feof(addon)){
    	fscanf(addon, "%[^:]:%[^:]:%f:%[^\n]\n", tmp.mcode,tmp.name,&tmp.price,tmp.description);
        if(strcmp(menuCode, tmp.mcode)==0){//compare two values
            fprintf(temp, "%s:%s:%.2f:%s\n", menuCode, meal.name, meal.price, meal.description);
            found = 1;
        }else{
            fprintf(temp, "%s:%s:%.2f:%s\n", tmp.mcode, tmp.name, tmp.price, tmp.description);
        }
        // fscanf(addon, "%[^:]:%[^:]:%f:%[^\n]\n", tmp.mcode,tmp.name,&tmp.price,tmp.description);
    }fclose(addon);//closing a file
    fclose(temp);
    remove("addon.txt");//replacing a file with another temporary file
    rename("temp.txt", "addon.txt");

    return found;
}