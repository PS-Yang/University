#include<stdio.h>
#include<stdlib.h>

int main()
{
  char name[10], de[2];
  int  sc1,sc2;
  printf("Please input your name....");
  scanf("%s",name); 
  printf("Please select your department....< a:資工 b:電機 c:電子>");
  scanf("%s",de);
  printf("Please input your score on test 1....");
  scanf("%d",sc1);
  printf("Please input your score on test 2....");
  scanf("%d",sc2);
  printf("|--------------------------------------"); 
  system("pause"); 
  return 0; 
}
