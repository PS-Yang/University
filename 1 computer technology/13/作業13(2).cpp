#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main() 
{
     int num[17],i,sum=0,j;
     char input[17]; 
     while(true)
     { 
     printf("�п�J�d��:");
     scanf("%s",input);
     if( strlen(input)<15 || strlen(input)>16 )
     printf("�d�����פ���\n"); 
     else
     break; 
     } 
     
     for(i=0 ; i<=strlen(input) ;i++)
     num[i]=(int)input[i]-(int)'0'; 
     if( strlen(input)==16 )
     {
      for( j=0 ; j<15 ; j++ )    
      {
       if(j%2==1)   
       sum=sum+num[j];
       else
       {
        if( num[j]>=5)  
        sum=sum +(2*num[j])/10 + (2*num[j])%10 ;  
        else 
        sum=sum+2*num[j];   
       }     
      } 
     if( (10-sum%10)==num[15] || ( sum%10==0 && num[15]==0))
     printf("�d�����T!!\n");
     else 
     printf("�d�����~!!\n");  
     } 
     if( strlen(input)==15 )  
     {  
       for( j=0 ; j<14 ; j++ )
       { 
        if(j%2==0)   
        sum=sum+num[j];
        else
        {
         if( num[j]>=5)  
         sum=sum +(2*num[j])/10 + (2*num[j])%10 ;  
         else 
         sum=sum+2*num[j];   
        }     
       } 
     if( (10-sum%10)==num[14] || ( sum%10==0 && num[14]==0))
     printf("�d�����T!!\n");
     else 
     printf("�d�����~!!\n");
     } 
     system("pause");
     return 0 ; 
}
