
printf("Enter item code:(-1 to end purchase)\n");
scanf("%s", meal_choice);

while(strcmp(meal_choice, "-1") != 0)//while loop to compare the input with sentinel value
    {
    fptr = fopen("combo.txt", "r");//command to open a specific file
    while(!feof(fptr))
    {
        fscanf(fptr, "%[^:]:%[^:]:%f:%[^\n]\n", combo.code, combo.name, &combo.price, combo.description);//prints the data inside the file
        if(strcmp(meal_choice, combo.code) == 0)
        {
            printf("Enter the quantity of the item:");
            scanf("%d", &quantity);

            price = combo.price;				
            item = combo.name;
            tax = taxing(combo.price, quantity);					           					             
			      
			total = (combo.price * quantity) + tax;
			grand_total += total;
			sumtax += tax;
			sum.trans++;
			sum.total = grand_total;
			sum.tax = sumtax;

			struct Combo newValues;//calling the structure to input the data from other file
			strcpy(newValues.name, combo.name);
			newValues.price = combo.price;                                

			fptr = fopen("receipt.txt", "a");
			print_order(quantity, item, price, grand_total);	
			fprintf(fptr, "%-15d%-27s%-17.2f\n", quantity, combo.name, combo.price);					
			fclose(fptr);
            
        }
    }fclose(fptr);//closes the file after execution			
exit(0);