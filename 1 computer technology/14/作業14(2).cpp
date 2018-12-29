#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
int main()
{
    char input[42];
    int number[2][40],sum[40],point,i,j,k,carry,begin=-1,end=-1;
    
    for(i=0;i<=1;i++) 
     for(j=0;j<40;j++) number[i][j]=0;
        
    for(i=0;i<=1;i++) 
    { 
     printf("Please input number #%d=",i+1);
     scanf("%s",input);
     point=-1 ; 
                     
     for(j=0;j<strlen(input);j++) 
      if(input[j]=='.') point = j;
     if(point==-1)   
      for(k=0,j=strlen(input)-1;j>=0;j--,k++)
       number[i][19-k]= (int)input[j]-48;
       
     else 
     { 
      for(k=0,j=point-1;j>=0;j--,k++) 
      number[i][19-k]= (int)input[j]-48; 
      for(k=0,j=point+1;j<strlen(input);j++,k++) 
      number[i][20+k]= (int)input[j]-48;  
     } 
    } 
    carry=0;
    for(i=0;i<40;i++) 
    { 
      sum[39-i]=number[0][39-i]+number[1][39-i]+carry;
      if(sum[39-i]>9)
      {
        sum[39-i]=sum[39-i]%10; 
       carry=1;              
      } 
      else carry=0; 
    } 
    for(i=0;i<=19;i++) 
     if( sum[i]!=0)  {begin=i; break;}   
    for(i=39;i>19;i--)  
     if( sum[i]!=0)  {end=i;  break;} 
     printf("The sum is ");
     
     if( carry==1) printf("1");
     
     if(begin==-1)  printf("0");
     else for (i=begin;i<=19;i++)
     printf("%d",sum[i]); 
    
    if(end != -1) 
    { 
     printf("."); 
     for(i=20;i<end;i++)
     printf("%d",sum[i]); 
    } 
    system("pause");
    return 0; 
     
}
