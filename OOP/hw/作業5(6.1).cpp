#include<iostream>
#include<iomanip> 
#include<cmath>
using namespace std;

class Impedance
{
 private:
 double r,x; 
 public:
 Impedance(float R=0,float X=0)
 {
  r=R; x=X;    
 }       
 friend istream &operator >>(istream &inst,Impedance &c);
 friend ostream &operator <<(ostream &outst,const Impedance &c);
 Impedance operator+(const Impedance & c)const;
 Impedance operator||(const Impedance & c)const;
 Impedance operator-();
};
istream &operator >>(istream &inst,Impedance &c)
{       
 cout<<"Please input R=";
 inst >>c.r;
 cout<<"Please input X=";
 inst >>c.x; 
 return inst;      
} 
ostream &operator <<(ostream &outst,const Impedance &c)
{
 if(c.r>0 && c.x>0)
 outst<<c.r<<"+"<<c.x<<"i";
 else if(c.r>0 && c.x==0)
 outst<<c.r;
 else if(c.r>0 && c.x<0)
 outst<<c.r<<c.x<<"i";
 else if(c.r==0 && ( c.x>0 ||c.x<0 ))
 outst<<c.x<<"i";
 else if(c.r==0 && c.x==0)
 outst<<c.r;
            
 return outst;       
} 
 
Impedance Impedance::operator+(const Impedance & c) const 
{ 
  Impedance temp;  
  temp.r=r+c.r; 
  temp.x=x+c.x; 
  return temp; 
} 
Impedance Impedance::operator||(const Impedance & c) const
{ 
 Impedance temp; 
 temp.r=( (x*c.r+c.x*r)*(x+c.x)+ (r*c.r-x*c.x)*(r+c.r) )/ ((r+c.r)*(r+c.r)+(x+c.x)*(x+c.x)) ;
 temp.x=( (x*c.r+c.x*r)*(r+c.r)- (r*c.r-x*c.x)*(x+c.x) )/ ((r+c.r)*(r+c.r)+(x+c.x)*(x+c.x)) ;
 return temp;
} 
Impedance Impedance::operator-()
{ 
 x=-x;
 return *this;
} 

int main()
{
 Impedance c1,c2,c3;
 cin >>c1>>c2>>c3; 
 cout<<"\nZ1="<<c1<<"\t"<<"Z2="<<c2<<"\t"<<"Z3="<<c3<<"\n\n";
 cout<<"Zs = Z1+Z2+Z3 = " <<(c1+c2+c3); 
 cout<<"\nZp = Z1||Z2||Z3 = " <<(c1||c2||c3); 
 cout<<"\n\n X=-X\n";
 cout<<"\nZs = Z1+Z2+Z3 = " <<-(c1+c2+c3); 
 cout<<"\nZp = Z1||Z2||Z3 = " <<-(c1||c2||c3);
 system("pause") ;   
 return 0;       
}
