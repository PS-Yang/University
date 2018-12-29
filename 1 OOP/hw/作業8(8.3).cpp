#include<iostream>
#include<iomanip> 

using namespace std;

class Coil
{
 private:
 float cur_coil;
 float vo_coil; 
 float n_coil;
 public:
 Coil(float i=0,float v=0,float n=0)
 {
  cur_coil=i;
  vo_coil=v;
  n_coil=n;
 }
 void getvalue1()
 {
  cout<<"--The primary coil!--"<<endl;
  cout<<"Please input the number of turns:";
  cin >> n_coil; 
  cout<<"Please input current:";
  cin >> cur_coil;
  cout<<"Please input voltage:";
  cin >> vo_coil;
 } 
 void getvalue2()
 {
  cout<<"--The second coil!--"<<endl;  
  cout<<"Please input the number of turns:";
  cin >> n_coil; 
 } 
 void printvalue1()
 {
  cout<<"--The primary coil!--"<<endl;  
  cout << "turn=" << n_coil << endl;
  cout << "current=" << cur_coil << endl;     
  cout << "voltage=" << vo_coil << endl;
 } 
 void printvalue2()
 {
  cout<<"--The second coil!--"<<endl; 
  cout << "turn=" << n_coil << endl;       
 } 
 float geti(){return cur_coil; }
 float getv(){return vo_coil; }
 float getn(){return n_coil; } 
};

class Transformer
{
 private:
 float cur1_tran;
 float vo1_tran; 
 float n1_tran;
 float cur2_tran;
 float vo2_tran; 
 float n2_tran;
 float n; 
 public:
 Coil ob1;
 Coil ob2;       
 Transformer (float i1=0, float v1=0, float n1=0, float n2=0) : ob1(i1,v1,n1) ,ob2(n2)      
 {
  cur1_tran=i1;
  vo1_tran=v1;
  n1_tran=n1; 
  n2_tran=n2;      
 } 
 void computeN()
 {
  n1_tran=ob1.getn();
  n2_tran=ob2.getn(); 
  n=(n2_tran / n1_tran); 
   
  cout<<endl<<"The N="<<n<<endl; 
 } 
 float v2()
 {
  n1_tran=ob1.getn();
  n2_tran=ob2.getn(); 
  vo1_tran=ob1.getv(); 
  n=(n2_tran / n1_tran); 
  vo2_tran= n*vo1_tran; 
  return vo2_tran; 
 } 
 float i2()
 {
  n1_tran=ob1.getn();
  n2_tran=ob2.getn(); 
  cur1_tran=ob1.geti(); 
  n=(n2_tran / n1_tran); 
  cur2_tran=cur1_tran/n; 
  return  cur2_tran; 
 }  
 
};

int main()
{
 Transformer ob;
 char choose; 
 do{
  cout <<"a.求secondary current"<<endl;
  cout <<"b.求secondary voltage"<<endl;
  cout <<"c.求secondary curren和secondary voltage"<<endl;
  cout <<"d.離開系統"<<endl; 
  cin >> choose; 
  switch(choose)
  {
   case 'a':
    ob.ob1.getvalue1();
    ob.ob2.getvalue2(); 
    ob.computeN();  
    cout << "current=" << ob.i2() << endl ;
    cout<<endl<<endl;
    break; 
   case 'b':
    ob.ob1.getvalue1();
    ob.ob2.getvalue2(); 
    ob.computeN();     
    cout << "voltage=" << ob.v2() << endl;
    cout<<endl<<endl;     
    break; 
   case 'c': 
    ob.ob1.getvalue1();
    ob.ob2.getvalue2(); 
    ob.computeN(); 
    ob.ob1.printvalue1(); 
    ob.ob2.printvalue2(); 
    cout << "current=" << ob.i2() << endl;     
    cout << "voltage=" << ob.v2() << endl;
    cout<<endl<<endl;
    break;   
   case 'd':
    cout<<"--Exit--"<<endl;   
    break; 
   default:
   cout<<"請輸入abcd!!"<<endl<<endl;  
  }
 
 }while(choose!='d');
  
 system("pause") ;   
 return 0;       
}
