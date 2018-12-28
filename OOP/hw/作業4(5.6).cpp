#include<iostream>
#include <string> 

using namespace std;

class buffer
{
 private:
 static string str;    
 string s1,s2,s3;  
  
 public:
 void putmessage(string st1,string st2,string st3) 
 {
  s1=st1;
  s2=st2;
  s3=st3;  
  str=str+s1+s2+s3; 
 }      
 static void  clearBuf(buffer &n)
 {
  str.clear();              
 }
 static void  display(buffer &n)
 {
  cout << str << endl;        
 } 
};
string buffer::str;

int main()
{
 string s1,s2,s3;    
 buffer o1;
 cout << " 請輸入字串1:" ; 
 getline(cin,s1); 
 cout << " 請輸入字串2:" ; 
 getline(cin,s2);
 cout << " 請輸入字串3:" ; 
 getline(cin,s3);
 o1.putmessage(s1,s2,s3);
 buffer::display(o1) ; 
 buffer::clearBuf(o1);
 buffer::display(o1) ;
 
 system("pause") ;   
 return 0;       
}
