#include <stdio.h>
#include <stdlib.h>

int main() 
{
     int num,n[20],i,j,k,count=0,a[7],sum;
     long n2; 
     printf("Please input a decimal number:");
     scanf("%d",&num);
     
     for(i=0;i<=19;i++)
     {
      n[i]=num%2;                 
      num=num/2;
      if(num!=0) 
      count++;                
     } 
     for(j=count;j>=0;j--)
     printf("%d",n[j]);
     
     printf("\nPlease input a binary number:"); 
     scanf("%d",&n2);
     for(k=0;k<=7;k++)
     {
      a[k]=n2%10;                 
      n2=n2/10;    
     }  
     sum=a[0]*1+a[1]*2+a[2]*4+a[3]*8+a[4]*16+a[5]*32+a[6]*64+a[7]*128; 
     printf("%d",sum); 


     system("pause");
     return 0 ; 
}
