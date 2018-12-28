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
  cout<<"��b�|R=";
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
   cout<<"��ߨ�(����)="; 
   cin>>angle;
   if(angle<0 || angle>2*PI)
   cout<<"���פ���0~2�k����!!"<<endl; 
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
   cout <<"h�ȭn�p��b�|R!!!"<<endl; 
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
  cout<<"**  ��P�v�k=3.141592  **"<<endl; 
  s1.setr();
  cout<<"��A�����n="<<s1.area_circle()<<endl;
  cout<<endl;
  s2.setr();
  s2.setangle();
  cout<<"����B�����n="<<s2.area_sector()<<endl; 
  cout<<endl; 
  s3.setr();
  s3.seth();
  cout<<"�}��C�����n="<<s3.area_segment()<<endl; 
  while(true)
  { 
   cout<<"�O�_�n�~��<y/n>"; 
   cin>>choose;
   if(choose=='y' || choose=='n' || choose=='Y' || choose=='N')
   break; 
   if ( ( choose!='y' || choose!='n') && (choose!='Y' || choose!='N'))
   cout<<"�п�JY��N"<<endl; 
  }
   if(choose=='N'||choose=='n')
   break; 
 } 
 
 system("pause") ;   
 return 0;       
}
