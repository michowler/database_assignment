#include <stdio.h>

int taxing( int price, int quantity);

int main() {		
	taxing(10, 20);
	return 0;
}

// to calculate the total with tax
int taxing( int price, int quantity) {
	int total;
	total = 0;
	total = (price * 60 / 100) * quantity;
	return printf("Total is RM %d\n", total);
}