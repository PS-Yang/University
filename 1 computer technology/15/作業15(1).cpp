#include <stdio.h>
#include <stdlib.h>
int pos[1024];

int huzhi(int m,int n)
{
int big = (m>n)?m:n;
int small = m+n-big;
int tmp;

while(small>1)
{
tmp = small;
if((small=big%small) == 0)
return 0;
big = tmp;
}
return 1;
}

void bubble_sort(double *p,int num)
{
int i,j;
int tmp;
for(i=0;i<num-1;i++)
for(j=i+1;j<num;j++)
{
if(p[i]>p[j])
{

double a;
a = p[i];
p[i] = p[j];
p[j] = a;

tmp = pos[i];
pos[i] = pos[j];
pos[j] = tmp;
}
}
}

int main()
{
int n,i,j,cnt=0;
int parent[1024],child[1024];
double fra[1024];

printf("please input a number:");
scanf("%d",&n);
if(n<1 || n>100)
{
printf("input err!\n");
return 0;
}
parent[cnt] = 1;
child[cnt] = 0;
fra[cnt] = 0;
cnt++;
parent[cnt] = 1;
child[cnt] = 1;
fra[cnt] = 1;
cnt++;

for(i=2;i<=n;i++)
{
for(j=1;j<i;j++)
{
if(huzhi(i,j) == 1)
{
parent[cnt] = i;
child[cnt] = j;
fra[cnt] = j/(double)i;
cnt++;
}
}
}


for(i=0;i<cnt;i++)
{
pos[i]=i;
}

bubble_sort(fra,cnt);
printf("0 ,");
for(i=1;i<cnt-1;i++)
{
printf("%d/%d ,",child[pos[i]],parent[pos[i]]);

}
printf("1");
printf("\n"); 
system("pause");
return 0;
}
