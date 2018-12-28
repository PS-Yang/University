#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int i,j,num,sum=0,count=0;
    printf("Please input a number:");
    scanf("%d",&num);
    
    for(i=1;i<=num;i++)
   {
     sum=0;
     for(j=1;j<i;j++)
     if(i%j==0)
      sum=sum+j; 
               if(sum==i) 
               {
                printf("%d, ",sum); 
                count++; 
                }
                
   }
      
      printf("\nThere are %d perfect numbers!!\n",count);
    
    
    
    
    
     system("pause");
     return 0 ; 
}
