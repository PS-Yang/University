#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
     int n,sum=0,a,i;
     srand(unsigned(time(NULL)));
     while(1) 
     {
      n=rand()%100;
      if( n>=10 && n<=40 )
      break; 
     } 
     n=33; 
     printf("N=%d\n",n);
     
     while(1)
    {
     a = n - sum;
     printf("Sum=%d,",sum);
     i=(a-1)%4;
     if(i==0)
     i = 3;
     printf("Computer add %d",i);
     sum = sum+i;
     printf("\nSum=%d,",sum);
     if(sum>=n)
     {
     printf("\nSum=%d,",sum);
     printf("You win!!\n");
     break;
     }
     printf("You add ");
     do
     {
      scanf("%d",&i);
      if(i<=0||i>=4)
      {
      printf("You input a wrong number!!");
      printf("\nSum=%d,",sum);
      printf("You add ");
      }
     }while(i<=0||i>=4);
     sum = sum+i;
     if(sum>=n)
     {
      printf("\nSum=%d,",sum);
      printf("You lose!!\n");
      break;
     }
    }
     system("pause");
     return 0 ; 
}
