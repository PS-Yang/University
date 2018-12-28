#include <stdio.h>
#include <stdlib.h>

int main() 
{
     int a,b,c,d; 
     printf ("Please input two intrgers:") ; 
     scanf("%d %d",&a,&b) ; 
      while(1000) 
      { 
       a=a%b;
       if(a==0)
       { printf("The GCD is %d",b) ; 
         break;  
       } 
       b=b%a;
       if(b==0)
       { printf("The GCD is %d",a); 
         break;     
       } 
       
       
     } 
     system("pause");
     return 0 ; 
}
