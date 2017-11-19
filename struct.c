// #include <stdio.h>
// struct student
// {
//     char name[50];
//     int roll;
// };

// void display(struct student stu);
// // function prototype should be below to the structure declaration otherwise compiler shows error

// int main()
// {
//     struct student stud;
//     printf("Enter student's name: ");
//     scanf("%s", stud.name);
//     printf("Enter roll number:");
//     scanf("%d", &stud.roll);
//     display(stud);   // passing structure variable stud as argument
//     return 0;
// }
// void display(struct student stu){
//   printf("Output\nName: %s\n",stu.name);
//   printf("Roll: %d\n",stu.roll);
// }

#include <stdio.h>
struct distance
{
    int feet;
    float inch;
};
void add(struct distance d1,struct distance d2, struct distance *d3); 

int main()
{
    struct distance dist1, dist2, dist3;

    printf("First distance\n");
    printf("Enter feet: ");
    scanf("%d", &dist1.feet);
    printf("Enter inch: ");
    scanf("%f", &dist1.inch);

    printf("Second distance\n");
    printf("Enter feet: ");
    scanf("%d", &dist2.feet);
    printf("Enter inch: ");
    scanf("%f", &dist2.inch);

    add(dist1, dist2, &dist3); 

    //passing structure variables dist1 and dist2 by value whereas passing structure variable dist3 by reference
    printf("\nSum of distances = %d\'-%.1f\"\n", dist3.feet, dist3.inch);

    return 0;
}
void add(struct distance d1,struct distance d2, struct distance *d3) 
{
     //Adding distances d1 and d2 and storing it in d3
     d3->feet = d1.feet + d2.feet; 
     d3->inch = d1.inch + d2.inch;

     if (d3->inch >= 12) {     /* if inch is greater or equal to 12, converting it to feet. */
         d3->inch -= 12;
         ++d3->feet;
    }
}

// struct foo
// {
//   int x;
//   float y;
// };

// struct foo var;
// struct foo* pvar;

// var.x = 5;
// (&var)->y = 14.3;
// pvar->y = 22.4;
// (*pvar).x = 6;