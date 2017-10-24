int show_combo_meals(), show_addon(), purchase_meal();
float taxing(float price, int quantity);
void order(), print_order(int quantity, char *item, float price, float total), print_receipt();

struct Combo { 
	float price;	
	char code[6];
	char description[100];
	char name[50];	
	int combo_trans;	

} combo, combo1, combo2, combo3, combo4, combo5, csum;

struct Addon {
	float price;	
	char code[6];
	char description[100];
	char name[50];		
	int ala_trans;

} addon1, addon2, addon3, addon4, addon5, asum;

struct Meal {
	float total;	
	int trans;
	float grand_total;
} sum;