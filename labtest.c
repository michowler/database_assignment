// Name : Michelle Ler Hsin Yee
// ID   : 0333120

#include <stdio.h>

struct Movies {
	char title[50];
	char Director[50];
	int cost;
	int month;
	int year;
};

int main(){
	int i;
	FILE *fptr;
	struct Movies movie[5];	

	fptr = fopen("mov.txt", "w");
	for(i=0; i<5;i++){
		printf("Movie title: ");		
		scanf(" %[^\n]", movie[i].title);
		printf("Movie director: ");
		scanf(" %[^\n]", movie[i].Director);
		printf("Movie cost: ");
		scanf(" %d", &movie[i].cost);
		printf("Movie month and year, Ex: 10-2014: "); //10-2014 month-year
		scanf(" %d%*c%d", &movie[i].month, &movie[i].year);		
		fprintf(fptr, "%s\t%s\t%d\t%d\t%d\n", movie[i].title, movie[i].Director, movie[i].cost, movie[i].month, movie[i].year);
	}
	fclose(fptr);
	return 0;
}