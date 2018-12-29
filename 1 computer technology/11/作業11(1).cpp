#include <stdio.h>
#include <stdlib.h>

int main() 
{
     int d[10],i,y,check;
     char num[11]; 
     printf("請輸入身分證字號:");
     scanf("%s",num);
     
     for(i=0 ; i<=10 ;i++)
     d[i]=(int)num[i]-(int)'0'; 
     
     if(d[0]<=24) 
     d[0]=d[0]-7;
     if(d[0]>=26 && d[0]<=30)
     d[0]=d[0]-8; 
     if(d[0]>=32 && d[0]<=38)
     d[0]=d[0]-9;
     if(d[0]==40 || d[0]==41)
     d[0]=d[0]-10;
     
     y=d[0]/10+d[0]%10*9+d[1]*8+d[2]*7+d[3]*6+d[4]*5+d[5]*4+d[6]*3+d[7]*2+d[8]; 
     
     check=10-y%10; 
     
     if(check%10==d[9]) 
     printf("身分證字號正確!! ^^\n");
     else
     printf("身分證字號錯誤!! QQ\n"); 
     
     
     system("pause");
     return 0 ; 
}
