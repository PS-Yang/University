#include <stdio.h>
#include <stdlib.h>

int main() 
{
     int i,j,n,k,a; 
     printf("Please input a number:"); 
     scanf("%d",&n); 
     for(i=1;i<=n;i++) 
     { 
     for(j=i; j<n;j++)
     printf(" ");
     for(k=1; k<=i; k++) 
     printf("%d",k%10);
     for(a=(i-1);a>=1;a--)
     printf("%d",a%10); 
        
     printf("\n");
 
     }    
      
    
     
     system("pause");
     return 0 ; 
}
