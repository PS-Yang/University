#include<iostream>
#include<iomanip> 

using namespace std;
//---------Abstract Base Class-------------------
class Vehicle{
  protected:
  float cap;
  float consum;
  float distance;
  float distance_avg;
  float time;
  
  public: 
  virtual void getvalue()=0; //pure virtual function 
  virtual float distan()=0 ; //pure virtual function 
  virtual float times()=0 ;  //pure virtual function 
};

//-----------Derived Classes-----------------
class Car:public Vehicle{
 
  public:  
  void getvalue()
  {
   cout<<"---The car---"<<endl; 
   cout<<"the fuel tank capacity=";
   cin>>cap;
   cout<<"average fuel consumption(per 100km)=";
   cin>>consum;
   cout<<"the total distance(單位:km)"; 
   cin>>distance;
  }
  float distan() 
  {
   distance_avg=cap/consum*100;
   return distance_avg;
  } 
   float times() 
  {
   time=distance/distance_avg;
   if(time!=(int)time)   
   return (int)time+1;
   else
   return time;             
  }  
};

class Truck:public Vehicle{
  
  public: 
  void getvalue()
  {
   cout<<"---The truck---"<<endl; 
   cout<<"the fuel tank capacity=";
   cin>>cap;
   cout<<"average fuel consumption(per 100km)=";
   cin>>consum;
   cout<<"the total distance(單位:km)"; 
   cin>>distance;
  }
  float distan() 
  {
   distance_avg=cap/consum*100;
   return distance_avg;
  } 
   float times() 
  {
   time=distance/distance_avg;
   if(time!=(int)time)   
   return (int)time+1;
   else
   return time;       
  }     
      
};
int main()
{
 Vehicle *ptr; //a base-class pointer 
 Car obj1;
 Truck obj2;
 char choose;
 do{
 
  ptr=&obj1;
  ptr->getvalue();
  cout<<"\nthe distance a car can travel on full tank=" << ptr->distan() << endl; 
  cout<<"The car has to be refueled  " << ptr->times() <<"  times"<< endl<<endl;

  ptr=&obj2;
  ptr->getvalue();
  cout<<"\nthe distance a truck can travel on full tank=" << ptr->distan() << endl; 
  cout<<"The truck has to be refueled  "<< ptr->times()<<"  times"<< endl<<endl;
  while(true)
  { 
   cout<<"是否繼續<y/n>";
   cin>>choose;
   if(choose=='n'||choose=='y')
   break;
   else if(choose=='N'||choose=='Y')
   break; 
   else
   cout<<"please input y or n" << endl; 
  } 
 }while(choose=='Y' || choose=='y');
 system("pause") ;   
 return 0;       
}
