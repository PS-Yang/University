#include <stdio.h>
#include <stdlib.h>

int main() 
{
     int b[10],i,s1[10],s2[10];
     char num[11]; 
     printf("Please input an ISBN code:");
     scanf("%s",num);
     for(i=0 ; i<=10 ;i++)
     {
       switch( num[i] )
       {
       case '0': b[i]=0 ;  break;          
       case '1': b[i]=1 ;  break;           
       case '2': b[i]=2 ;  break;          
       case '3': b[i]=3 ;  break;            
       case '4': b[i]=4 ;  break;           
       case '5': b[i]=5 ;  break;           
       case '6': b[i]=6 ;  break;           
       case '7': b[i]=7 ;  break;           
       case '8': b[i]=8 ;  break;          
       case '9': b[i]=9 ;  break;
       case 'x': b[i]=10 ; break;
       case 'X': b[i]=10 ; break;                        
       }
     } 
     
     for(i=0;i<=9;i++)
     { 
     if(i==0)
     s1[i]=b[i];
     else 
     s1[i]=s1[i-1]+b[i]; 
     } 
     for(i=0;i<=9;i++)
     {
     if(i==0)
     s2[i]=s1[i];
     else 
     s2[i]=s2[i-1]+s1[i]; 
     }
     
     if(s2[9]%11==0)
     printf("The ISBN code is correct!!\n");
     else
     printf("The ISBN code is wrong!!\n");
     
     system("pause");
     return 0 ; 
}
