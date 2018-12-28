#include<iostream>
#include <iomanip>
using namespace std;

class  spacecraft
{
  private:      
  float v0x,v0y,ax,ay,time;
 
  public:   
  void getvalue();
  void printvalue();
};

  void spacecraft::getvalue()
  {
   cout<<"Vox=";
   cin >>v0x;
   cout<<"Voy=";
   cin >>v0y;
   cout<<"ax=";
   cin >>ax;
   cout<<"ay=";
   cin >> ay;
   cout<<"time=";
   cin>>time;
  }
  void spacecraft::printvalue()
  {
   for(int t=1 ; t<=time ; t++)
   {
    int s=t-1;       
    cout <<"Xx" << t << "=" << v0x*t+ (ax*t*t)/2 -( v0x*s+ (ax*s*s)/2 ) <<'\t';
    cout <<"Xy" << t << "=" << v0y*t+ (ay*t*t)/2 -( v0y*s+ (ay*s*s)/2 ) << '\t';
    cout <<"Vx" << t << "=" << v0x+ ax*t << '\t';
    cout <<"Vy" << t << "=" << v0y+ ay*t << endl;
   }
  }
int main()
{
  
  spacecraft a;
  a.getvalue();  
  a.printvalue(); 

 system("pause") ;  
 return 0; 
        
}
 
