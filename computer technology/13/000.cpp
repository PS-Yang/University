#include<stdio.h>
#include<stdlib.h>
void hanoi(int,char,char,char);
void doublehanoi(int n);
int move=0;
int main(){
int n;
printf("請輸入A柱中的環個數: ");
scanf("%d",&n);
doublehanoi(n);
printf("共需%d個步驟\n",move);
system("pause");
return 0;
}
void hanoi(int n,char start,char end,char other){
if(n>1)
hanoi(n-1,start,other,end);
printf("ring %d: %c => %c\n",n,start,end);
move++;
if(n>1)
hanoi(n-1,other,end,start);
return;
}
void doublehanoi(int n){ 
char A='A',B='B',C='C';
while(n>1){
hanoi(n-1,A,B,C);
printf("ring %d: %c => %c\n",n,A,C); move++; 
n-=2;
if(n<1) break;
if(n>1)
hanoi(n-1,B,A,C);
printf("ring %d: %c => %c\n",n,B,C); move++;
n--;
if(n<1) break;
if(n>1)
hanoi(n-1,A,C,B);
printf("ring %d: %c => %c\n",n,A,B); move++;
n-=2;
if(n<1) break;
if(n>1)
hanoi(n-1,C,A,B);
printf("ring %d: %c => %c\n",n,C,B); move++;
n--;
}
}
