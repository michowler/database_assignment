#include <stdio.h>
 
void daily_transactions(int combo_trans, int ala_trans, float grand_total){
    printf("--------------------------------\n");
    printf("   Daily Transactions\n");
    printf("--------------------------------\n");
    printf("Total combo meal transaction : %d\n", combo_trans);
    printf("Total ala-carte transaction : %d\n", ala_trans);
    printf("Total sales : RM %.2f\n", grand_total);                     
    puts("------------------------------------");
}
 
int main(void) {
    FILE *tfptr;
    char str[32];
    unsigned combo_trans, ala_trans;
    float total;
    unsigned c_trans = 0, a_trans = 0;
    float grand_total = 0;
    tfptr = fopen("trans.txt", "r");
    while( fgets(str, sizeof(str), tfptr)!=NULL ){
        sscanf(str, "%u:%u:%f", &combo_trans, &ala_trans, &total);
        c_trans += combo_trans;
        a_trans += ala_trans;
        grand_total += total;
    }                                           
    daily_transactions(c_trans, a_trans, grand_total);                                                                                  
    fclose(tfptr);
}