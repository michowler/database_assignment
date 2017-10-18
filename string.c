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