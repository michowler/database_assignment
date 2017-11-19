// 1. Write a c program that can help users to input their usernames. And print out
// the all usernames when the users stopped.

#include <stdio.h>
#include <string.h>

int compare(char *usptr, char *usrptr);

int main(){
	char username[20], usr[20];
	int i, count;
	FILE *fp;
	fp = fopen("username.txt", "w");
	while (strcmp(username, "#") != 0) {
		printf("Enter a new username (input # to stop) : ");
		if (strcmp(username, "#") != 0){
			scanf("%s", username);
			fprintf(fp, "%s\n", username);
			count++;
		} else {
			fp = fopen("username.txt", "r");
				for (i=0;i<count;i++){
					fscanf(fp, "%s\n", usr);							
				}
				while (compare(&username, &usr) == 1) {
					printf("Sorry, the username has been taken, please enter a different name.\n");
				}
			fclose(fp);
			scanf("%s", username);
			break;			
		}			
	}
	fclose(fp);

	fp = fopen("username.txt", "r");
	//rewind(fp);
	printf("The usernames: \n");	
	while (!feof(fp)){
		fgets(username, 20, (FILE*)fp);
		printf("%s", username);
	}		
	fclose(fp);
}

int compare(char *usptr, char *usrptr){
	if (usptr == usrptr){
		return 1;
	} else if (usptr != usrptr){
		return 0;
	}
}