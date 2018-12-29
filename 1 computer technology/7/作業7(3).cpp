#include <stdio.h>
#include <stdlib.h>

int main() 
{
     int n,i,j;
     printf("Please input a number:");
     scanf("%d",&n);
     for(i=1;i<=n;i++)
    { for(j=1;j<=4*n+1;j++)
     {printf("$") ; 
     printf("\n") ; 
      } 
     } 
      
     system("pause");
     return 0 ; 
}
