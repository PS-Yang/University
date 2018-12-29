#include <stdio.h>
#include <stdlib.h>
int count=0; 
void single(int num,char go,char to,char end)
{
    if(num==1)
     { 
       printf("ring %d : %c  =>  %c\n",num,go,end);
       count++;    
     } 
    else if(num>1) 
     {  
       single(num-1,go,end,to);
       printf("ring %d : %c  =>  %c\n",num,go,end);         
       single(num-1,to,go,end); 
       count++;   
      }  
} 
void three(int num,char go,char to,char end)
{
     
    if(num>0) 
     {
       single(num-1,go,end,to);
       printf("ring %d : %c  =>  %c\n",num,go,end);
       count++;
       single(num-3,to,go,end);       
       printf("ring %d : %c  =>  %c\n",num-2,to,go);
       count++;
       if(num>3)
        {
            single(num-5,end,go,to);
            printf("ring %d : %c  =>  %c\n",num-4,end,to); 
            count++;
            three(num-6,go,to,end); 
        }           
     } 
} 
int main(void)
{
    int num;
    printf("請輸入A柱中的環個數:");
    scanf("%d",&num);
    three(num,'A','B','C');
    printf("共需%d個步驟\n",count); 
    system("pause");
    return 0; 
}
