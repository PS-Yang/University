#include <stdio.h>
#include <stdlib.h>

int main() 
{
     int n,x=0,y=1,m,z;
     printf("Please input a number:"); 
     scanf("%d",&n); 

     printf("%d",x); 
     printf(",%d",y); 
     for(m=3;m<=n;m++)        
     {
      z=x+y;
      printf(",%d",z);
      x=y; 
      y=z;                        
                              
     } 
    
     
     system("pause");
     return 0 ; 
}
