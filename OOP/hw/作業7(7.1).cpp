#include<iostream>
#include<iomanip> 
#include<cmath>

#define PI 3.141592 
using namespace std;

class Circle
{
 protected:
 float r;
 float area_cir;
  
 public:
 Circle(float cr=0){ r=cr;};
 void setr()
 {
  cout<<"圓半徑R=";
  cin >>r; 
 }; 
 float area_circle()
 {
   area_cir=r*r*PI; 
   return area_cir;
 };
};

class Sector:public Circle{ 
 protected: 
 float area_sec;
 float angle;
 
 public:
 Sector(float cangle=0 ,float cr=0):Circle(cr){ r=cr; angle=cangle;} 
 void setangle()
 {
  do{ 
   cout<<"圓心角(弧度)="; 
   cin>>angle;
   if(angle<0 || angle>2*PI)
   cout<<"弧度介於0~2π之間!!"<<endl; 
   }while(angle<0 || angle>2*PI);    
 }; 
 float area_sector()
 {
  area_sec=(r*r*angle)/2;
  return  area_sec; 
 }; 

}; 

class Segment:public Circle{ 
 protected: 
 float area_seg;
 float h;
 
 public:
 Segment(float length=0 ,float cr=0):Circle(cr){ r=cr; h=length;} 
 void seth()
 {
  do{ 
   cout<<"h=";     
   cin>>h;
   if(h>r || h<0 ) 
   cout <<"h值要小於半徑R!!!"<<endl; 
  }while( h>r || h<0 ); 
 }; 
 float area_segment() 
 {
  area_seg=r*r*acos( (r-h)/r )-( (r-h)*sqrt(2*r*h-h*h) );
  return area_seg; 
 }; 
 
}; 
int main()
{
 Circle s1;
 Sector s2;
 Segment s3;
 char choose; 
 while(true)
 { 
  cout<<"**  圓周率π=3.141592  **"<<endl; 
  s1.setr();
  cout<<"圓A的面積="<<s1.area_circle()<<endl;
  cout<<endl;
  s2.setr();
  s2.setangle();
  cout<<"扇形B的面積="<<s2.area_sector()<<endl; 
  cout<<endl; 
  s3.setr();
  s3.seth();
  cout<<"弓形C的面積="<<s3.area_segment()<<endl; 
  while(true)
  { 
   cout<<"是否要繼續<y/n>"; 
   cin>>choose;
   if(choose=='y' || choose=='n' || choose=='Y' || choose=='N')
   break; 
   if ( ( choose!='y' || choose!='n') && (choose!='Y' || choose!='N'))
   cout<<"請輸入Y或N"<<endl; 
  }
   if(choose=='N'||choose=='n')
   break; 
 } 
 
 system("pause") ;   
 return 0;       
}
