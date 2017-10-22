#include <stdio.h>

int gcd(int a, int b);
int lcm(int a, int b);

int main()
{
	int a, b;

	printf("Enter 2 positive numbers: ");
	scanf("%d %d", &a, &b);

    printf("GCD (%d, %d) = %d\n", a, b, gcd(a, b));
    printf("LCM (%d, %d) = %d\n", a, b, lcm(a, b));

    return 0;
}

int gcd(int a, int b) {	
    if (a == 0)  //a = bq + r
        return b;
    printf("A: %d\n", a);
    return gcd(b%a, a);
    
}

//example b = 10, a = 2
10%2 = 0
now a = 0%2 and b = 0
0%2 = 0 

10%4 != 0


int lcm(int a, int b) {	
	return a * b / (gcd(a, b));
}