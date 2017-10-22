   void print_receipt(){
    FILE *fp;
    char text_file[250];

    fp = fopen("receipt.txt", "r"); //opens txt file and READS only

    puts("----------------------------------------------");
    puts(" ---------------YOUR RECEIPT----------------- ");
    puts("----------------------------------------------");

    fgets(text_file, 250, (FILE*)fp);
    printf("%s\n", text_file );

    fgets(text_file, 250, (FILE*)fp);
    printf("%s\n", text_file );
    
    fgets(text_file, 250, (FILE*)fp);
    printf("%s\n", text_file );

    fgets(text_file, 250, (FILE*)fp);
    printf("%s\n", text_file );

    fgets(text_file, 250, (FILE*)fp);
    printf("%s\n", text_file );
    printf("Total (incl gst): RM %.2f\n", sum.total); 

    puts(" ----------THANKS FOR PURCHASING-------------- ");
   }

   
   // printf("%-16s%-24s%-19s%-18s\n\n","Meal Code","Meal Name","Meal Price","Meal Description");         
   // printf(" %-15s%-27s RM %-17.2f %-27s\n",combo1.code,combo1.name,combo1.price,combo1.description);        
   // printf(" %-15s%-27s RM %-17.2f %-27s\n",combo2.code,combo2.name,combo2.price,combo2.description);     
   // printf(" %-15s%-27s RM %-17.2f %-27s\n",combo3.code,combo3.name,combo3.price,combo1.description);
   // printf(" %-15s%-27s RM %-17.2f %-27s\n",combo4.code,combo4.name,combo4.price,combo4.description);
   // printf(" %-15s%-27s RM %-17.2f %-27s\n",combo5.code,combo5.name,combo5.price,combo5.description);


//fscanf(cfp, "%[^:]:%[^:]:%f:%[^\n]\n",menu_code,name,&price,description);

   // printf("Code  : %s\n",combo1.code);
   // printf("Name     : %s\n",combo1.name);
   // printf("Price    : RM %.2f\n",combo1.price);
   // printf("Description    : %s\n",combo1.description);
   // printf("---------------------------------------\n");
   // printf("Code  : %s\n",combo2.code);
   // printf("Name     : %s\n",combo2.name);
   // printf("Price    : RM %.2f\n",combo2.price);
   // printf("Description    : %s\n",combo2.description);
   // printf("---------------------------------------\n");   
   // printf("Code  : %s\n",combo3.code);
   // printf("Name     : %s\n",combo3.name);
   // printf("Price    : RM %.2f\n",combo3.price);
   // printf("Description    : %s\n",combo3.description);
   // printf("---------------------------------------\n");
   // printf("Code  : %s\n",combo4.code);
   // printf("Name     : %s\n",combo4.name);
   // printf("Price    : RM %.2f\n",combo4.price);
   // printf("Description    : %s\n",combo4.description);
   // printf("---------------------------------------\n");
   // printf("Code  : %s\n",combo5.code);
   // printf("Name     : %s\n",combo5.name);
   // printf("Price    : RM %.2f\n",combo5.price);
   // printf("Description    : %s\n",combo5.description);