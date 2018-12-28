#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main() 
{   
    int n,i,j,a[4],b[4],A=0,B=0,count=0,num; 
    while(100)
    { 
    srand(unsigned(time(NULL)));
    n=rand()%10000;
    a[0]=n/1000;
    a[1]=(n/100)%10;
    a[2]=(n/10)%10; 
    a[3]=n%10;
    if(a[0]==a[1] || a[0]==a[2] || a[0]==a[3] || a[1]==a[2] || a[1]==a[3] || a[2]==a[3] || a[0]==0)
    continue;
    break; 
    } 
    printf("%d\n",n); 
     while(A!=4)
    { 
     count++; 
     A=0;
     B=0; 
     printf("Please input four digits(0~9):"); 
     scanf("%d",&num); 
    
     b[0]=num/1000;
     b[1]=(num/100)%10;
     b[2]=(num/10)%10; 
     b[3]=num%10; 
     for(i=0;i<=3;i++)
      {
        for(j=0;j<=3;j++) 
        {
          if(a[i]==b[j])
          {
           if(i==j)
           A++;
           if(i!=j) 
           B++;  
           break; 
          }                 
        } 
      }  
    if(A==4)
    printf("You got it!! %d times!!\n",count); 
    else
    printf("The result is %dA %dB\n",A,B); 
    } 
     system("pause");
     return 0 ; 
}
