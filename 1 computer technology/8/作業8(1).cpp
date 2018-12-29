#include <stdio.h>
#include <stdlib.h>

int main() 
{
     int i,j, n,sum=0,a,b;
     printf("Please input a number:");
     scanf("%d",&n);
     for(i=1;i<=n;i++) 
     {   
      if( i>=10 && i<=99) 
      { 
        a=i/10 ; 
        b=i%10 ;
        if( (a+b)*(a+b)==i )
        {
         printf("%d,",i); 
         sum++; 
        } 
      } 
      if( i>=1000 && i<=9999) 
      { 
       a=i/100 ; 
       b=i%100 ;
       if( (a+b)*(a+b)==i )
       {
        printf("%d,",i); 
        sum++; 
       }
      }   
      if( i>=100000 && i<=999999) 
      { 
         a=i/1000 ; 
         b=i%1000 ;
         if( (a+b)*(a+b)==i )
         {
          printf("%d,",i); 
          sum++; 
         }   
      } 
     }   
     printf("\n%d times!!\n",sum); 
     system("pause");
     return 0 ; 
}
