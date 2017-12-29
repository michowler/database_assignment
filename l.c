#include <stdio.h>
#include <string.h>
#define SIZE 10

struct Item {
	int itemCode;
	char itemName[50];
	float itemPrice;
	int itemQuantity;
};

int find_longestString(char str1[], char str2[]);

int main(){
	int x=30, *y,*z;
	y=&x;
	z=y;
	*y++ = *z++;
	x++;	
	printf("X:%d, Y:%d, Z:%d\n", x,*y,*z);
	// struct Item item;
	// FILE * fptr;
	// int i;
	// fptr = fopen("food.txt", "r");
	// printf("Out-of-stock items: \n");
	// printf("-----------------------------\n");

	// for (i=0; i<4; i++){
	// 	fscanf(fptr, " %d,%[^,],%f,%d\n", &item.itemCode, item.itemName, &item.itemPrice, &item.itemQuantity);
	// 	if(item.itemQuantity == 0){
	// 		printf("%u\t%s\t%.2f\n", item.itemCode, item.itemName, item.itemPrice);
	// 	}
	// }
	// fclose(fptr);

	// char s1[20];
	// char s2[20];
	// int length;
	// printf("Enter 2 strings: \n");
	// scanf("%s%s", s1, s2);
	// length = find_longestString(s1,s2);

	// if(length==1){
	// 	printf("String 1 is longer than string 2.\n");
	// } else if (length==2) {
	// 	printf("String 2 is longer than string 1.\n");
	// } else if (length==3) {
	// 	printf("String 2 is same as string 1.\n");
	// }

	return 0;
}	

int find_longestString(char str1[], char str2[]){
	int result;
	int s1 = strlen(str1);
	int s2 = strlen(str2);
	
	if(s1 >s2) {
		result = 1;
	} else if (s2 > s1) {
		result = 2;
	} else if (s1==s2) {
		result = 3;
	}
	return result;
}