#include <stdio.h>
#include <stdlib.h>
int main() 
{
     int i,j;
    
     for (j=1;j<=9;j++)
      {  for(i=1;i<=9;i++)
        printf("%d*%d=%d \t",i,j,i*j) ;
        printf("\n") ; 
        
      }  
    
     
    
     system("pause");
     return 0 ; 
     }
