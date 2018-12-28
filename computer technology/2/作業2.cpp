#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int a;
    printf("Please input a positive integer:");
    scanf("%d",&a);
    
    if(a<0) 
     printf("%d is not a positive integer!!\n",a); 
    else  
    { if(a>=1,a<=9)
      printf("%d is a small integer.\n",a);
     else
      { if(a>=10,a<=99) 
       {printf("%d的十位數為%d\n",a,a/10); 
       printf("%d的個位數為%d\n",a,a%10);} 
        else
        {  printf("%d is a large integer.\n",a) ;
        
         switch(a%5)
         { case 0 :printf("%d is divisible by 5. \n",a); 
          break; 
          case 1 :printf("%d+5=%d \n",a,a+5);  
          break;
          case 2 :printf("%d-5=%d \n",a,a-5); 
          break;
          case 3 :printf("%d*5=%d \n",a,a*5); 
          break;
          case 4 :printf("%d/5=%0.2f \n",a,(float)a/5); 
          break; 
          } 
          } 
        }
         
      }   
        
     system("pause");
     return 0 ; 
     }
