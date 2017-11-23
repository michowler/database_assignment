void delete_meal()
{	
	FILE *fptr;//declaring a file pointer
	FILE *dtemp;
	FILE *cptr;
	FILE *aptr;
	char text_file[200];
	char mcode[6];
	struct Meal meal;
	int type = 0; //Not found	
	
    printf("----------------------------\n");//function for deleting a data in the file
    printf("      DELETE MEAL\n");
    printf("----------------------------\n");
    printf("Enter menu code:\n");
    scanf("%5s", mcode);//user input

    cptr = fopen("combo.txt", "r");//creating a new file            
    while(!feof(cptr))
    {	    	    	
    	fscanf(cptr, "%[^:]:%[^:]:%f:%[^\n]", meal.mcode, meal.name, &meal.price, meal.description);
        if(strcmp(mcode, meal.mcode) == 0)
        {
            type = 1; //combo
        }       
    }fclose(cptr);
    
    if(type == 0){
        aptr = fopen("addon.txt", "r");                
        while(!feof(aptr))
        {
        	fscanf(aptr, "%[^:]:%[^:]:%f:%[^\n]", meal.mcode, meal.name, &meal.price, meal.description);
            if(strcmp(mcode, meal.mcode) == 0)
            {
                type = 2; //addon
            }            
        }fclose(aptr);
    }

    switch(type){//switching to search which value matches the input
        case 1:           
            dtemp = fopen("deletetemp.txt", "w");//opening file for write.            
            cptr = fopen("combo.txt", "r");
            while(!feof(cptr))
            {
                fscanf(cptr, " %[^:]:%[^:]:%f:%[^\n]", meal.mcode, meal.name, &meal.price, meal.description);
                if (strcmp(mcode, meal.mcode) != 0){                
                    fprintf(dtemp, "%s:%s:%.2f:%s\n", meal.mcode, meal.name, meal.price, meal.description);
                }               
            }fclose(cptr);
            remove("combo.txt");//removing one file and replacing it with another
            rename("deletetemp.txt", "combo.txt");
            fclose(dtemp);//file close
            printf("Menu with code %s deleted!\n", mcode);
	        break;
        case 2:            
            dtemp = fopen("deletetemp.txt", "w");
            aptr = fopen("addon.txt", "r");
            while(!feof(aptr))
            {
                fscanf(aptr, " %[^:]:%[^:]:%f:%[^\n]", meal.mcode, meal.name, &meal.price, meal.description);
                if(strcmp(mcode, meal.mcode) != 0)
                {
                    fprintf(dtemp, "%s:%s:%.2f:%s\n", meal.mcode, meal.name, meal.price, meal.description);
                }
            }fclose(aptr);
            remove("addon.txt");
            rename("deletetemp.txt", "addon.txt");
            fclose(dtemp);
            printf("Menu with code %s deleted!\n", mcode);        
	        break;
        default:
            printf("This is an invalid menu code.\n");//for default value            
        	break;
    }
}