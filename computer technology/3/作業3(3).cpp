#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int num,i,j,a,count=0; 
    
    printf("Please input a number:");
    scanf("%d",&num);   
    for(i=num;i>=2;i--) 
    { 
        a=0; 
        for(j=2;j*j<=i;j++)
        {
             if(i%j==0)
              a=1;
              } 
    
    if(a==0)
    {printf("The prime number is %d\n",i); 
     break; }         
                      }
                      
    
    
    
    
     system("pause");
     return 0 ; 
     }
