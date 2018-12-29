#include<stdio.h>
#include <stdlib.h>                                                                          
int main()
{
    int mon[12]={12,31,28,31,30,31,30,31,31,30,31,30}; 
    int i,j,y,week,count=0,ryear;
    printf("Please input the century: ");
    scanf("%i",&y);
    for(i=(y-1)*100+1;i<=y*100;i++)
    {
        ryear=0;
        if((i%4==0&&i%100!=0)||i%400==0) //¶|¦~ 
            ryear=1;
        week=(i+(int)((i-1)/4)-(int)((i-1)/100)+(int)((i-1)/400))%7;
        for(j=0;j<12;j++)
        {
            week+=mon[j];
            if(j==2)
                week+=ryear;
            week%=7;
            if(week==5)
                count++;
        }
    }
    printf("%i times!!\n",count);
    system("PAUSE");
    return 0;
}
