#include <stdio.h>
#include <stdlib.h>

int main() 
{
     int i,j,n,k; 
     printf("Please input a number:"); 
     scanf("%d",&n); 
     for(i=1;i<=n;i++) 
     { 
     for(j=n-i; j>=1; j--)
     printf(" ");
     for(k=1; k<=2*i-1; k++) 
     printf("%d",i%10);
     printf("\n");
 
}    
      
    
     
     system("pause");
     return 0 ; 
}
