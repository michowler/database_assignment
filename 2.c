/*------------------------------------------------------------------*/
/* ITS62804– Assignment #1 */
/* Principles of Programming */
/* Student Name: <Muhammad Hariz bin Hassan Kuthus> <Khor Pooi Teng > */
/* Student ID: <0328090> <0333477> */
/*------------------------------------------------------------------
*/ 
#include <stdio.h>
void main_menu();
void purchase(); //function prototypes
void edit_meal(); //function prototypes
void add_meal(); //function prototypes
void delete_meal(); //function prototypes
void available_meal();//function prototypes 
void daily_transactions();//function prototypes 
void exit();
int tax(int y);

int option;
int customer_order;
char menu_code[6];
float meal_price;
float total;
float ala;
float Stotal;
float tax;
float Tcombo;
char choice;
char meal_name[30];
char meal_desc [20];
int again;
FILE *combo;
FILE *addon;

int main(){
	
	int option;
	printf ("------------------------------------");
	printf ("\n Fast Food Ordering System\n");
	printf ("------------------------------------\n");
	printf ("\t 1. Purchase\n");
	printf ("\t 2. Edit Meal\n");
	printf ("\t 3. Add Meal\n");
	printf ("\t 4. Delete Meal\n");
	printf ("\t 5.Show Available Meal\n");
	printf ("\t 6. Show daily transaction\n");
	printf ("\t 7.Exit\n");
	
	printf ("Please choose a number to proceed: ");
	scanf ("%d", &option);
	printf ("----------------\n");
	while (option != -1)
	{
		printf ("Enter option -1 to end:" );
		scanf ("%d",&option);
		switch (option)
		{
			case 1:
			purchase();
			return;
			break;
			
			case 2:
			edit_meal();
			return;
			break;
			
			case 3:
			add_meal();
			return;
			break;
			
			case 4:
			delete_meal();
			return;
			break;
			
			case 5:
			available_meal();
			return;
			break;
			
			case 6:
			daily_transactions();
			return;
			break;
			
			case 7:
			end();
			return;
			break;
			
			default:
			printf ("Invalid choice. Please choose again \n");
			break;
		}// end switch
	}// end main_menu
	
	void purchase(){
		printf ("Please enter your order from the 		display.");
		scanf ("%d", &customer_order);
	}
	
	void edit_meal(){
		printf ("This option allows user to edit meals");
	}
	
	void add_meal(){
		printf ("This option allows user to add meals");
	}
	
	void delete_meal(){
		printf ("This option allows user to delete meals");
	}
	
	void available_meal(){
		char code[6];
		char meal_name[30];
		double meal_price;
		char meal_desc[20];
		
		FILE *combo;
		FILE *addon;
		
		if ((combo = fopen("combo.txt", "r")) == NULL) {
			puts ("File could not be opened");
		} // end if
		else {
			printf ("%-10s%-13s%-10s%-13s", menu_code, meal_name, meal_price, meal_desc);
		    fscanf (combo, "%s%s%lf", &code, &meal_name, &meal_price, &meal_desc);
	}// end while
	
	fclose (combo);
} // end else
	} // end show available_meal

void daily_transactions(){
	printf ("Total combo meal transaction: %d\n");
	scanf ("%lf",&Tcombo);
	printf ("Total ala-carte transaction: %d\n");
	scanf ("%lf", &ala);
	printf ("Total sales:%d \n");
	scanf ("%lf", &Stotal);
	printf ("GST collected:%d \n");
	scanf ("%lf", &tax);
}

void exit(){
	int option;
	while (option > = 1 && option < = 7) {
			printf("\nInvalid option.\nPlease again. ");
				
		} 
}

//Function GST
int tax (int y)
{
	y = Stotal;
	tax = 0.06 * Stotal;
	return tax;
}
return 0;
}



	



		