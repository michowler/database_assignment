/*-------------------------------------------------------------------*/
/* ITS60304â€“ Assignment #1 */
/* C Programming */
/* Student Name: <CHONG HAO JUN> <CHANG CHOON KIT> */
/* Student ID: <0330320> <0331184>*/
/*-------------------------------------------------------------------*/

#include <stdio.h>

//functions' prototype
void postcode(char end);
void registration (char end, char file_user[25], char bd[9], char ph[12], char ptcode[6]);
void adminlogin (char end, char file_user[25], char bd[9], char ph[12], char ptcode[6], char s);
char ending (char end);

//main function begins
int main(void)
{	
	char s;//switch input
	char end = 'z';//end input
	//int id = 0;
	//char admin[20];//to scan admin username in admin.txt
	//char password[20];//to scan password in admin.txt
	//char login[20];//insert username in "ADMIN LOGIN"
	//char pass[20];//insert password in "ADMIN LOGIN"
	//char user[35];//input username in "REGISTRATION"
	char file_user[25];//scan username from user.txt
	char bd[9];//birthday date info from users input or scan from user.txt
	char ph[12];//phone number info from users input or scan from user.txt
	char ptcode[6];//postal code info from users input or scan from user.txt
	//int insert_id;//insert id in "ADMIN LOGIN"
	int user_check;//user string compare value in "REGISTRATION"
	//int name_check;//name string compare value in "ADMIN LOGIN"
	//int password_check;//password string compare value in "ADMIN LOGIN"
	char skip[100];//use to scan text file in "ADMIN LOGIN" 
	//FILE *fptr;//file pointer for admin.txt and user.txt
	
    
	do
	{
	printf("------------------------------------\n");
	printf("Delivery checker\n");
	printf("------------------------------------\n");
	
	printf("1. Check Malaysia State\n");
	printf("2. Register\n");
	printf("3. Update profile\n");
	printf("4. Admin Login\n");
	printf("5. Exit\n");
	
	printf("Please select a number: " );
	scanf(" %c", &s);
	 
	
		switch(s)
		{
			case'1' :
			printf("------------------------------\n"
			"POSTAL CODE.\n"
			"------------------------------\n");
	
		postcode(end); //postcode function call
		break;
		
		case '2' :
		registration(end, file_user, bd, ph, ptcode);//registration function call
		break;
		
		case '3' :printf("This option allows user to change their profile.\n");
		break;
		
		case '4' :
		adminlogin(end, file_user, bd, ph, ptcode, s);//admin_login function call
		break;
		
		case '5' :
		break;
		
		default:
		printf("Do not recognise, please try again.\n");
			
	}//end switch
	}while(s!= '5');//end while
	return 0;
	}//end main

//postcode function
void postcode(char end)
{
	int pcode;
	
	do
		{
		printf("Enter a postcode: ");
		scanf("%d", &pcode);
		pcode =pcode/1000;
		
		if((pcode>=40 && pcode<=48) || (pcode>=62 && pcode<=64))
		{
			printf("Selangor (Shah Alam)\n");
		}
		
		else if(pcode>=20 && pcode<=24)
		{
			printf("Terengganu (Kuala Terengganu)\n");
		}
		
		else if(pcode>=93 && pcode<=98)
		{
			printf("Sarawak (Kuching)\n");
		}
		
		else if(pcode>=88 && pcode<=91)
		{
			printf("Sabah (Kota Kinabalu)\n");
		}
		
		else if((pcode>=2 && pcode<3) || (pcode>=5 && pcode<=9))
		{
			printf("Kedah (Alor Setar)\n");
		}
		
		else if(pcode>=15 && pcode<=18)
		{
			printf("Kelantan (Kota Bharu)\n");
		}
		
		else if(pcode>=70 && pcode<=73)
		{
			printf("Negeri Sembilan (Seremban)\n");
		}
		
		else if(pcode>=10 && pcode<=14)
		{
			printf("Pulau Pinang (George town)\n");
		}
		
		else if(pcode>=79 && pcode<=86)
		{
			printf("Johor (Johor Bahru)\n");
		}
		
		else if(pcode>=75 && pcode<=78)
		{
			printf("Melaka (Melaka\n");
		}
		
		else if(pcode>=1 && pcode<2)
		{
			printf("Perlis (Kangsar)\n");
		}
		
		else if((pcode>=30 && pcode<=36) || (pcode>=39 && pcode<40))
		{
			printf("Perak (Ipoh)\n");
		}
		
		else if(pcode>=25 && pcode<=28)
		{
			printf("Pahang (Kuantan)\n");
		}
		
		else
		{
			printf("---------------------------------\n");
			printf("!!INVALID POSTALCODE!!\n");
			printf("---------------------------------\n");
		}
		
		end = ending(end);//function call
		
		}while(end == 'y');//end while

		} // postcode function ends
	
void registration (char end, char file_user[25], char bd[9], char ph[12], char ptcode[6])
{
	char user[35];//input username in "REGISTRATION"
	int user_check;//user string compare value in "REGISTRATION"
	FILE *fptr;//file pointer for admin.txt and user.txt
	char skip[100];//use to scan text file in "ADMIN LOGIN" 

	
	
	
	fptr = fopen("user.txt", "a+");
		
		printf("---------------------------------\n"
		"REGISTERATION.\n"
		"---------------------------------\n");
		
		do
		{
		printf("Username(Max 34 Char):");
		scanf(" %[^\n]s", user); //scan user's username input
		while(!feof(fptr))//when not end of the file
		{
		fscanf(fptr,"%[^;];%[^;];%[^;];%s", file_user, bd, ph, ptcode);//scan the username, birthday,phone no and postalcode in user.txt
		fgets(skip, 100, (FILE*)fptr);// buffer as to make sure the line has been scanned completely
		user_check = strcmp(user, file_user);// compare the username in the user.txt with the user's username input in each row of the user.txt's username
		
		if(user_check == 0)//if the value = 0 or means the user's username input same as the each row of the user.txt's username
		{
			rewind(fptr);//rewind the file pointer
			printf("The username has been taken.\n");//tell user that the username is same as in the one of the username in the user.txt
			break;
		}
		}//end while
		}while(user_check == 0);//repeat the user's username input procedure since the username cannot be the same
		
		printf("The username is available.\n");
		printf("Birthday(ddmmyyyy):");
		scanf("%8s", bd);//scan users' birthday input
		printf("Contact Number:(+6");
		scanf("%11s", ph);//scan users' phone number input
		printf("Postcode:");
		scanf("%5s", ptcode);//scan users' postal code input
		
		fprintf(fptr,"%s;%8s;%9s;%5s\n", user, bd, ph, ptcode);//print users' info into the user.txt
		printf("Thank You!\n"
		"You have completed the reqisteration!\n");
		
		fclose(fptr);
	
}//register function ends
	
	
void adminlogin (char end, char file_user[25], char bd[9], char ph[12], char ptcode[6], char s)
{
	int name_check;//name string compare value in "ADMIN LOGIN"
	int password_check;//password string compare value in "ADMIN LOGIN"
	char login[20];//insert username in "ADMIN LOGIN"
	char pass[20];//insert password in "ADMIN LOGIN"
	char skip[100];//use to scan text file in "ADMIN LOGIN" 
	char admin[20];//to scan admin username in admin.txt
	char password[20];//to scan password in admin.txt
	int insert_id;//insert id in "ADMIN LOGIN"
	FILE *fptr;//file pointer for admin.txt and user.txt
	int id = 0;//count users in user.txt
	
		do
		{
			printf("---------------------------------\n"
			"ADMIN LOGIN.\n"
			"---------------------------------\n");
			fptr = fopen("admin.txt", "r");
			
			
			if(fptr == NULL)//if admin.txt does not exist
			{
			printf("You do not have an admin account.\n");
			printf("do you want to create an admin account?\n");
			
			do
			{
				scanf(" %c", &s);
			
				switch(s)
				{
					//admin registration (create a admin.txt)
					case'y' : //when users input 'y'
					printf("---------------------------------\n");
					printf("Admin REGISTRATION\n");
					printf("---------------------------------\n");
					printf("ADMIN USERNAME:");
					scanf("%s", login);
					printf("ADMIN PASSWORD:");
					scanf("%s", pass);
					
					fptr = fopen("admin.txt","a+");
					
					fprintf(fptr,"%s;%s\n", login, pass);
					
					fclose(fptr);
					
					printf("The Admin Registration Has Completed.\n");
					
					break;
					
					case'n' : //when users' input 'n'
					printf("Proceed to Main Menu.\n");
					break;
					
					default:
					printf("---------------------------------\n");
					printf("Invalid Input, Please Try Again.\n");
					printf("---------------------------------\n");
				
				}//end switch
			
			}while(s !='y' && s !='n');//end do while loop
				
				break;
				
			}
			
	
			else
		{		
		printf("Username:");
		scanf("%s", login);
		printf("Password:");
		scanf("%s", pass);
		
		fscanf( fptr,"%[^;];%s", admin, password);
		
		name_check = strcmp(login, admin); //compare between user's username input and username from admin.txt
		password_check = strcmp(pass, password); //compare between user's password input and password from admin.txt
	
		if ( name_check == 0 && password_check == 0 ) // if the username compare and password compare is all matched.
		{

			do
			{
				end = 'n'; //just to make sure to exit the all loop and back to the main menu switch
			if((fptr = fopen("user.txt", "r")) == NULL && end == 'n' )// when there is no user.txt
			
			{
				printf("--------------------------------------------------------------\n");
				printf("There is no user in the user info\n");
				printf("Please register some infomation in the Registration Section.\n");
				printf("--------------------------------------------------------------\n");
				
				break;				

			}//end if

			fptr = fopen("user.txt", "r");
			id = 0;
			printf("---------------------------------\n");
			printf("USER INFO.\n");
			printf("---------------------------------\n");
			printf("ID \tUsers\n");
			while(!feof(fptr)) //while file pointer is not end of the file
			{
			fscanf(fptr,"%[^;];%[^;];%[^;];%s", file_user, bd, ph, ptcode);//scan value till reached the smicolon and skip the semicolon symbol, 
			fgets(skip, 100, (FILE*)fptr);//as to make sure the scan is in the next line
			id++;//just id 
			
			//to print out a list of user's name for admin to choose
			if(!feof(fptr)) //as to make sure if the file pointer is not yet reached to the end of the file
			{
			printf("%d.\t", id); //auto create id as to let admin to choose whice user's info to check
			printf("%s\n", file_user);
			}//end if
			
			}//end while
			printf("---------------------------------\n");
			fclose(fptr);
			
			printf("Enter id to check User's info:");
			scanf("%d", &insert_id);
			
			fptr = fopen("user.txt", "r");
			
			for(id=1; id<insert_id; id++)//id will set as 1, then it will increase when having a loop untill the id is same is the is that user input
			{
				fgets(skip, 100, (FILE*)fptr); //scan the whole line in the user.txt as to make the file pointer to the next row.
				
				if(feof(fptr)) //if already reached to the end of the file,
				{
					id = -10; //put id into a random number example '-10'
					break;
				}
				
			}
				
			if(id != -10) //if it is not the '-10', it will be printed out the user's info
			{

				

					fscanf(fptr,"%[^;];%[^;];%[^;];%s", file_user, bd, ph, ptcode);
					fgets(skip, 100, (FILE*)fptr);
				if(!feof(fptr))//just to make sure if the file pointer is not yet in the end of the file.
				{		
					printf("---------------------------------\n");
					printf("User : %s\n", file_user);
					printf("Bithday(DDMMYYYY) : %s\n", bd);
					printf("Contact Number : +6%s\n", ph);
					printf("Postal Code : %5s\n", ptcode);
					printf("---------------------------------\n");
					rewind(fptr);
				}
				
				else //or else, it is invalid
				{	
					printf("---------------------------------\n");
					printf("!! INVALID ID. !!\n");
					printf("---------------------------------\n");
					rewind(fptr);
				}
			}
		
			else //if it is '-10', means the id that user input is not available in the list of the id in the users info (please refer line 320)
			{	
				printf("---------------------------------\n");
				printf("\t!! INVALID ID. !!\n");
				printf("---------------------------------\n");
				rewind(fptr);
			}
						
				end = ending(end);//function call
			
			fclose(fptr);	
		}while(end == 'y'); //end while
			

			
			
		}//end if
		else
		{
			printf("--------------------------------------------\n");
			printf("Invalid Username or Incorrect Password.\n");
			printf("Do you want to try again?\n");
			printf("--------------------------------------------\n");			
			fscanf( fptr,"%s%s", admin, password);

			end = ending(end);//function call
			
		}
	
		}//end else
	}while(end == 'y');//end while
		
}//adminlogin function ends	
	
char ending(char end)
{	
do
{
	printf("Press 'y' to try again or 'n' to back to menu.\n");
	scanf(" %c", &end);
			
	switch(end)
	{
		case 'y' :
		break;
				
		case 'n' :
		break;
				
		default : 
		printf("---------------------------------\n");
		printf("Invalid Input, Please Try Again.\n");
		printf("---------------------------------\n");
				
	}//end switch
}while(end!='y' && end!='n');//end do while loop

return end;
}//ending functions ends
		
