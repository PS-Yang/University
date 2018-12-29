#include <stdio.h>
#include <stdlib.h>

int main() 
{
     int i , j , k , a , b , c , d , count=0 ;
     
     for(i=10;i<=98;i++) 
     {   
       for(j=10;j<=98;j++) 
       {
         if(i%10!=i/10 && j%10!=j/10 && i<=j) 
         { 
           k=i*j; 
           a=k/1000;
           b=(k/100)%10;
           c=(k/10)%10; 
           d=k%10;
           if(a!=b && b!=c && c!=d && d!=a && a!=c && b!=d )
           { 
             if(a==i/10 || a==i%10 || a==j%10 || a==j/10)
             {
              if(b==i/10 || b==i%10 || b==j%10 || b==j/10)
              { 
                if(c==i/10 || c==i%10 || c==j%10 || c==j/10)
                { 
                  if(d==i/10 || d==i%10 || d==j%10 || d==j/10)  
                   {
                    printf("%d*%d=%d\n",i,j,k);
                    count++;
                   } 
                } 
               } 
             }    
              
  
           } 
         } 
       }  
     }
      printf("%d¦¸\n",count); 
      
     system("pause");
     return 0 ; 
}
