//*made by ekansh agarwal//*
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<ctype.h>
#include<process.h>


//* to print time at top center of my code //*
int main()
{   time_t t;
    time(&t);
    printf("\t\t\t\tThe time right now is (date and time): %s", ctime(&t));
//* basic phone system//*
int a;
int row,col,r,c,q;
printf("\n\t\t1.press 1 to contact book\n");
printf("\t\t10.press 2 to play game\n");
printf("\t\t10.press 3 to listen music\n");
printf("\n\n\t\tChoose from[1,2,3]");
scanf("%d",&a);
switch(a)
{
  case 1 :first();
  break;
  case 2 :second();
  break;
  case 3 :third();
  default: printf("input a number between 1 and 10");
}
return 0;




}
