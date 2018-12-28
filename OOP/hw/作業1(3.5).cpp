#include <iostream>

using namespace std;

inline void memEr()
{
 cout<<"Memory allocation error!";
 exit(1);
}
int main()
{
   float **a ,sum[3]={}; 
   int day,i,j ; 
   cout << "Please input days: ";
   cin >> day ;
  
   a= new float*[3];
   
   
   if(!a)
    memEr();
   for(i=0 ; i < 3; i++)
   {
    a[i]=new float [day];
    if(!a[i])
     memEr();
   } 
    
   
   cout << "Please input temperature: " ;
   for(j=0 ; j<day ;j++)
   cin>> a[0][j];
   
   cout << "Please input humidity: " ;
   for(j=0 ; j<day ; j++)
   cin>> a[1][j];
   
   cout << "Please input barometric pressure: " ;
   for(j=0 ; j<day ; j++)
   cin>> a[2][j];   
   
   for(int k=0 ; k<3 ; k++)
  {  
    for(i=day-1 ; i>0 ; i--)
    {
      for(j=0 ; j<i ; j++)
      {
        if( a[k][j]<a[k][j+1] )
        {
            float temp;
            temp= a[k][j];
            a[k][j]=a[k][j+1];
            a[k][j+1]=temp;
        }
      }        
    }
  }
  
  
   for(i=0 ; i<=2 ; i++) 
   for(j=0 ; j<day ; j++)
   sum[i]=sum[i]+a[i][j];
   
   
   for(i=0 ; i<3 ; i++)
   {
     for(j=0 ; j<day ; j++)
     cout << a[i][j] << '\t';   
     cout << "average" << sum[i]/day << '\n' ;
   }
   
   for(i=0 ; i<3 ; i++)
   delete []a[i];
   
   system("pause"); 
   return 0; 
}

