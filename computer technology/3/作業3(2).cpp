#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int num,i,j,a,count=0; 
    
    printf("Please input a number:");
    scanf("%d",&num);   
    for(i=2;i<=num;i++) 
    { 
        a=0; 
        for(j=2;j*j<=i;j++)
        {
             if(i%j==0)
             {a=1;
             break;} } 
    
    if(a==0)
    {
     printf("%d ",i); 
     count++; }         
                        } 
    printf("\n%d times!!\n",count); 
    
    
    
    
     system("pause");
     return 0 ; 
     }
