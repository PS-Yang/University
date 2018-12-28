#include<stdlib.h>
#include<stdio.h.>



int main()
{
int n,i,j,k,circle;
printf("Please input a number: ");
scanf("%d",&n);
for(circle=n;circle>=2;circle--)
{
for(i=n;i>=circle+1;i--)
printf("%d ",i%10);
for(j=1;j<=4*circle-3;j++)
printf("%d",circle%10);
for(k=circle+1;k<=n;k++)
printf(" %d",k%10);
printf("\n");
for(i=n;i>=circle;i--)
printf("%d ",i%10);
for(j=4*(circle-1)-3;j>=1;j--)
printf(" ");
for(k=circle;k<=n;k++)
printf(" %d",k%10);
printf("\n");

}
for(circle=n;circle>=2;circle--)
printf("%d ",circle%10);
printf("1");
for(circle=2;circle<=n;circle++)
printf(" %d",circle%10);
printf("\n");
for(circle=2;circle<=n;circle++)
{
for(i=n;i>=circle;i--)
printf("%d ",i%10);
for(j=1;j<=4*(circle-1)-3;j++)
printf(" ");
for(k=circle;k<=n;k++)
printf(" %d",k%10);
printf("\n");
for(i=n;i>=circle+1;i--)
printf("%d ",i%10);
for(j=1;j<=4*(circle)-3;j++)
printf("%d",circle%10);
for(k=circle+1;k<=n;k++)
printf(" %d",k%10);
printf("\n");

} 

system("PAUSE");
return 0;

}
