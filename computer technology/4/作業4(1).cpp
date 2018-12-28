#include <stdio.h>
#include <stdlib.h>

int main() 
{
     int n,min,max,m,x,sum=0;
     float ave; 
     printf("Please input the number of integers:"); 
     scanf("%d",&n) ; 
     
     for(m=1;m<=n;m++)
    {
      printf("Integer#%d....",m) ; 
      scanf("%d",&x) ; 
      sum=sum+x ; 
      if(m==1)
      { 
        min=x;      
        max=x; 
      } 
       if(x<=min)
        {min=x; 
        } 
       if(x>=max) 
        {max=x; 
        }    
    } 
    ave=(float)sum/n; 
    printf("The average is %.6f\n",ave); 
    printf("The maximum is %d\n",max); 
    printf("The minimum is %d\n",min);
    
    
     
     system("pause");
     return 0 ; 
}
