#include <stdio.h>
#include <stdlib.h>

int main() 
{
     int n1,n2,i,sum=0,n,max=0,N=0;
     
     printf("Please input the LowerBound and the UpperBound:");
     scanf("%d %d",&n1,&n2); 
     for(i=n1 ; i<=n2 ; i++) 
     { 
        n=i; 
        sum=0; 
       do 
       {  
          if(n%2==0) 
          { 
           sum=sum+n ; 
           n=n/2;   
          } 
          else 
          { 
          sum=sum+n; 
          n=3*n+1;   
          } 
       }while(n!=1); 
       if(sum>=max)
       {
        max=sum;
        N=i;
       } 
     } 
     printf("N=%d  Sum=%d\n",N,max+1); 
     system("pause");
     return 0 ; 
}
