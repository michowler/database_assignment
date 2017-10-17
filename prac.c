#include <stdio.h>

int main() //<menu code>;<meal name>;<meal price>;<meal descriptions>
{   
	typedef {
		float meal_price;  
		int meal_code;
		char meal_code, meal_name, meal_description;
	} meal	

	FILE *fptr;

	if ((fptr = fopen("combo.txt","rb")) == NULL){
		printf("Error opening file!");

	} else {
		
		printf("Enter meal code: (-1 to end purchase)\n");
		scanf("%s", meal_code);

		while(strcmp(meal_code, "-1") != 0)//while loop to compare the input with sentinel value
		    {
		    fptr = fopen("combo.txt", "r");//command to open a specific file
		    while(!feof(fptr))
		    {
		        fscanf(fptr, "%[^:]:%[^:]:%lf:%[^:]", meal.code, meal.name, &meal.price, meal.descriptions);//prints the data inside the file
		        if(strcmp(meal_code, meal.code) == 0) 
		        //the %[^\n] conversion specification, which matches a string of all characters not equal to the new line character ('\n') 
		        //and stores it (plus a terminating '\0' character) in str. REGEX
		        {
		            printf("Enter the quantity of the item:");
		            scanf("%d",&qty);
		          		            
		                printf("---------------------------------------\n");
		                printf("code  : %s\n", meal.code);
		                printf("Name     : %s\n", meal.name);
		                printf("Price    : RM%.2f\n", meal.price);
		                printf("Quantity : %d\n", qty);
		                printf("---------------------------------------\n");

		                gst = meal.price * qty;
		                sumgst += gst;
		                total = sumgst + meal.price
		                sum += total;
		                tax = gst * 0.06;
		                sumtax += tax;		                
		            
		        }
		    }

		fclose(fptr);//closes the file after execution							
		
		printf("Enter meal code, meal name, meal price and meal descriptions.\n");
		scanf("%s %s %s %d %s", meal_code, meal_name, &meal_price, meal_descriptions);
	}


	fclose(fptr); 

	return 0;
}