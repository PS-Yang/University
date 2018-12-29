#include <stdio.h>
#include <stdlib.h>

int main() 
{
     int ca=0,ce=0,ci=0,co=0,cu=0; 
     char ch ; 
     printf("Please input a paragraph(Enter # to quit):"); 
     
     while(100)
    { 
     scanf("%c",&ch);
      switch(ch) 
      { 
      case'A': 
      case'a': ca++ ;  
      break; 
      case'E': 
      case'e': ce++ ;
      break;
      case'I': 
      case'i': ci++ ; 
      break;
      case'O': 
      case'o': co++ ; 
      break;
      case'U': 
      case'u': cu++ ; 
      break; 
      } 
      if(ch=='#')
      break; 
      
    }  
     
     printf("A  E  I  O  U  \n");
     printf("%d  %d  %d  %d  %d  ",ca,ce,ci,co,cu) ; 
     
     
     system("pause");
     return 0 ; 
}
