#include <stdio.h>
#include <stdlib.h>

int main() 
{
     int y,n,week,more,i,count=0;
     int mon[12]={12,31,28,31,30,31,30,31,31,30,31,30}; 
     printf("Please input the century:");
     scanf("%d",&n); 
     
     for(y=n*100-99 ; y<=n*100 ; y++) 
     {
       more=0;             
       if( (y%4==0&&y%100!=0) || y%400==0 )
       more=1; 
       week=(y+(y-1)/4-(y-1)/100+(y-1)/400 )%7; 
     
       for( i=0 ; i<12 ; i++ )  
       { 
        week=week+mon[i] ; 
        if(i==2)
        week=week+more; 
        week=week%7; 
        if(week==5)
        count++; 
       } 
     } 
     printf("%dtimes!!\n",count); 
     system("pause");
     return 0 ; 
}
