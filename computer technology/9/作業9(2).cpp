#include <stdio.h>
#include <stdlib.h>

int main() 
{
     int n,i,j,a[10][10],b[10][10],sum,d,e,f; 
      
     printf("Please input the size of matrix:");
     scanf("%d",&n);
     printf("Please input matrix1:\n");
     for(i=1;i<=n;i++) 
      for(j=1;j<=n;j++)  
      scanf("%d",&a[i][j]); 
     printf("Please input matrix2:\n");
     for(i=1;i<=n;i++) 
      for(j=1;j<=n;j++)  
      scanf("%d",&b[i][j]);
     printf("matrix1 * matrix2 =\n"); 
     for(d=1;d<=n;d++) 
     {
       for(e=1;e<=n;e++) 
       { 
       sum=0; 
       for(f=1;f<=n;f++)          
       sum=sum+a[d][f]*b[f][e];
       printf("%d ",sum); 
       }
     printf("\n");  
     }  
     system("pause");
     return 0 ; 
}
