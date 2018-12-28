#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int num1 , num2 ,sum=0;
    char choice='Y'; 
    while(choice=='Y' || choice=='y')
    {  
    printf("Number1:"); 
    scanf("%d",&num1); 
    printf("Number2:"); 
    scanf("%d",&num2); 
    
     
    if(num1>num2)
    {
     printf("Error!!Number 1 > Number 2!!\n"); 
     continue ;  }
     for(sum=0; num1<=num2;num1++)
     sum=sum+num1;
     printf("Sum = %d\n",sum); 
     printf("Again(Y/N)??");
     scanf("%*c%c",&choice); 
     }    
        
        
         
    
    
    
     system("pause");
     return 0 ; 
     }
