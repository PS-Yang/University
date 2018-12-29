#include <stdio.h>
#include <stdlib.h>
void func()
{
    for(int i=1;i<=9;i++) //loopi
    { 
     for(int j=1;j<=9;j++) //loopj
     printf("%dx%d=%d\t",j,i,i*j); 
     
     printf("\n");
    }  
}


int main(){
    
    int n;
    func();
    printf("Please input n(1~9)= ");
    scanf("%d",&n);
    
    for(int i=1;i<=9;i++) //loop2
    {
     for(int j=1;j<n;j++) //loop1
     printf("\t");
     printf("%dx%d=%d\n",n,i,n*i);
    }
    system("PAUSE");
    return 0;    
}
