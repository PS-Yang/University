#include<iostream>
#include <iomanip>
using namespace std;

class number 
{
  private:
  int *iptr;
  int temp; 
  int i;
  int j;   
  int n;
  
  public:  
  number (int num)
  {
    n=num;
    iptr= new int [n]; 
    if(!iptr) 
    {
     cout<<"Memory allocation error!";
     exit(1); 
    } 
    for(i=0 ; i<n ; i++) 
     cin >>iptr[i]; 
  } 
  
  number( number &a)
  { 
    n=a.n;
    iptr= new int [n];   
    
    for(i=0 ; i<n ; i++)
    iptr[i]=a.iptr[i];
    
    for(i=n-1 ; i>0 ; i--) 
    { 
      for(j=0 ; j<i ; j++) 
      { 
        if(iptr[j]>iptr[j+1]) 
        { 
         temp=iptr[j]; 
         iptr[j]=iptr[j+1]; 
         iptr[j+1]=temp; 
        } 
      } 
    } 
  }
  ~number()
  {
   delete []iptr;         
  }
  void sort()
  {
   for(i=n-1 ; i>0 ; i--) 
    { 
      for(j=0 ; j<i ; j++) 
      { 
        if(iptr[j]<iptr[j+1]) 
        { 
         temp=iptr[j]; 
         iptr[j]=iptr[j+1]; 
         iptr[j+1]=temp; 
        } 
      } 
    } 
  }
  void printvalue() 
  { 
    for(i=0 ; i<n ; i++)
    cout << iptr[i]<< '\t';
    cout << endl; 
  } 
  
   
};   

  int main()
  {
   int num; 
   cout <<" 要輸入幾個數字:" ; 
   cin >> num; 
   number a(num);
   a.sort();
   a.printvalue(); 
   number b=a;
   b.printvalue();
   system("pause") ;  
   return 0;     
  }
 
