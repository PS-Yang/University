#include<iostream>
#include<ctime>
#include<cmath> 
using namespace std;

class array{
 private:
 int *ptr;
 int size; 
 int num;
 
 public:
 array(){ size=10; num=100; } 
 array(const array &c)
 {
  size=c.size;
  num=c.num;
  ptr= new int[size];
  if(!ptr)
  {
   cout<<"Memory allocation error!!" ;
   exit(1);       
  }
  for(int i=0;i<size;i++)
  ptr[i]=c.ptr[i];        
 }  
 ~array(){ delete []ptr; }
 void getvalue();
 void allocate(); 
 void printvalue();
 const array &operator=(const array &c);
 void sort_up();
 void sort_down(); 
};
void array::getvalue()
{
 do{ 
  cout <<"請輸入要幾個數字(最多到100)："; 
  cin >> size;
  cout <<"請輸入數字最大到多少(最大到30000)：" ;
  cin >> num;
  if(size>100||num>30000) 
  cout<<"數值過大請重新輸入!!"<<endl; 
 }while(size>100||num>30000);   
}
void array::allocate()
{
 ptr=new int [size];
 if(!ptr)
 {
  cout<<"Memory allocation error!!" ;
  exit(1);       
 }
 srand(time(NULL));
 
 for(int i=0;i<size;i++) 
 ptr[i]=rand()%num+1;   
}
void array::printvalue()
{
  for(int i=0;i<size;i++)
  cout <<ptr[i]<<'\t';
  cout<<endl;
}
const array & array::operator=(const array &c)
{
 if(&c!=this)
 {
  delete []ptr; 
  num=c.num;
  size=c.size; 
  ptr= new int[size];
  if(!ptr)
  {
   cout<<"Memory allocation error!!" ;
   exit(1);       
  }
  for(int i=0;i<size;i++)
  ptr[i]=c.ptr[i];    
 }
 return   *this; 
}  
void array::sort_up()
{
 int temp;
 for(int j=size-1 ; j>0;j-- )
 {
  for(int i=0 ; i<j ;i++)       
  {       
   if(ptr[i]>ptr[i+1])
   {
    temp=ptr[i];
    ptr[i]=ptr[i+1];
    ptr[i+1]=temp;    
   }
  } 
 }
}
void array::sort_down()
{
 int temp;
 for(int j=size-1 ; j>0;j-- )
 {
  for(int i=0 ; i<j ;i++)       
  {       
   if(ptr[i]<ptr[i+1])
   {
    temp=ptr[i];
    ptr[i]=ptr[i+1];
    ptr[i+1]=temp;    
   }
  } 
 }    
} 

int main()
{
 array ob1,ob2,ob3;  
 char yn ,choose;  
 while(true)
 {
  cout<<"原本設定值" <<endl; 
  ob1.allocate();
  cout<<"原本的："<<endl; 
  ob1.printvalue();
  ob2=ob1;
  ob3=ob1;
  ob2.sort_down();
  cout<<"由大到小排列："<<endl; 
  ob2.printvalue();
  ob3.sort_up();
  cout<<"由小到大排列："<<endl;
  ob3.printvalue();  
  
  do{
   cout<<"是否要自行輸入<y/n>"<<endl;
   cin>>yn; 
   cout<<"是否繼續<y/n>"<<endl;
   cin>>choose;
   if( (choose=='n' || choose=='N' || choose=='Y' || choose=='y') && (yn=='n' || yn=='N' || yn=='Y' || yn=='y') )
   break; 
   if(choose!='n' || choose!='N' || choose!='Y' || choose!='y' || yn!='n' || yn!='N' || yn!='Y' || yn!='y')
   cout<<"請輸入Y或N!!" << endl; 
  }while(choose!='n' || choose!='N' || choose!='Y' || choose!='y' || yn!='n' || yn!='N' || yn!='Y' || yn!='y'); 
  if( yn=='y' || yn=='Y' ) 
  {
   while(true)
   { 
    ob1.getvalue(); 
    ob1.allocate();
    cout<<"原本的："<<endl; 
    ob1.printvalue();
    ob2=ob1;
    ob3=ob1;
    ob2.sort_down();
    cout<<"由大到小排列："<<endl; 
    ob2.printvalue();
    ob3.sort_up();
    cout<<"由小到大排列："<<endl;
    ob3.printvalue();  
    
    do{        
     cout<<"是否繼續<y/n>"<<endl;
     cin>>choose;
     if(choose=='n' || choose=='N' || choose=='Y' || choose=='y') 
     break; 
     if(choose!='n' || choose!='N' || choose!='Y' || choose!='y') 
     cout <<"請輸入Y或N!!"<<endl; 
    }while(choose!='n' || choose!='N' || choose!='Y' || choose!='y'); 
    
    if(choose=='n' || choose=='N')
    break; 
   } 
  }
  if(choose=='n' || choose=='N')
  break;
 }  
 system("pause") ;   
 return 0;       
}
