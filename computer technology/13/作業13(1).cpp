#include <stdio.h>
#include <stdlib.h>

void tower(int n,char from,char temp,char to);

int count=0;
 
int main() 
{
     int n ; 
     printf("請輸入A柱中的環個數:"); 
     scanf("%d",&n);
     tower(n,'A','B','C');
     printf("共需%d個步驟\n",count);    
     system("pause");
     return 0 ; 
}
void tower(int n,char from,char temp,char to)
{
  if(n==1)
  { 
  printf("ring %d:%c=>%c\n",n,from,to);
  count++;
  } 
  else  
  {
  tower(n-1,from,to,temp); 
  printf("ring %d:%c=>%c\n",n,from,to);   
  tower(n-1,temp,from,to);   
     
  count++;   
  } 

} 
