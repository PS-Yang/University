#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int num,i,j,a,count=0,n1=2; 
    
    printf("Please input a number:");
    scanf("%d",&num);   
    for(i=3;i<=num;i++) 
    { 
        a=0; 
        for(j=2;j<=i-1;j++)
        {
              
             if(i%j==0)
             { a=1;
               break;
             } 
        } 
     
     if(a==0)
     {
      if(i==n1+2) 
      {
       printf("(%d,%d)",n1,i);             
       count++;      
      }
      n1=i;  
                 
     } 
    } 
    printf("\n%d times!!\n",count); 
    
    
    
    
     system("pause");
     return 0 ; 
}
