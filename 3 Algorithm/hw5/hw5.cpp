#include  <fstream>
#include  <string>
#include  <iostream>
#include  <iomanip>
#include  <windows.h>
#include  <time.h>
#include  <math.h>
using namespace std;

int upper_best=0;
int lower_best=0;
string str_best=""; 

int stack_up[10000], stack_size=0;  
int stack_low[10000]; 
int stack_length[10000]; 
string str_stack[10000];

int out_up;
int out_low;
int out_length;
string out_str; 


int low_bound(int w[],int p[],float value[],int max,string choose,int num)
{
  float lower_bound=0;
  int length=choose.length();
  int current_w=0; 
  
  for(int i=0;i<choose.length();i++)
  {
   if(choose[i]=='1')
   {
     current_w=current_w+w[i+1]; 
     lower_bound=lower_bound+p[i+1];       
   } 
  }
           
  if(current_w<=max) 
  { 
   for(int i=choose.length()+1;i<=num;i++)     
   {
     if( (current_w+w[i]<=max)) 
     { 
         
      lower_bound=lower_bound+p[i];
      current_w=current_w+w[i];  
     } 
     else if( (current_w<max) ) 
     {  
      lower_bound=lower_bound+(float)(max-current_w)/w[i] *p[i]; 
      current_w=max; 
     } 
   }
  }
  else
  lower_bound=-1; 
  
  return (int)lower_bound;                                          
} 

int up_bound(int w[],int p[],float value[],int max,string choose,int num)
{
  int upper_bound=0;
  int length=choose.length();
  int current_w=0; 
 
  
  for(int i=0;i<choose.length();i++)
  {
   if(choose[i]=='1')
   {
    current_w=current_w+w[i+1];   
    upper_bound=upper_bound+p[i+1];    
   } 
  } 
          
  if(current_w<=max) 
  {
   for(int i=choose.length()+1;i<=num;i++)     
   {
     if( (current_w+w[i]<=max)) 
     { 
      upper_bound=upper_bound+p[i];
      current_w=current_w+w[i];     
     } 
   } 
  }
  else
  upper_bound=-1;
   
  return upper_bound;                                              
}
void insert(int up,int low,string str)
{
  stack_size++;
  
  stack_up[stack_size]=up; 
  stack_low[stack_size]=low;   
  stack_length[stack_size]=str.length();
  str_stack[stack_size]=str; 
}
 
void output()
{
 out_up=stack_up[stack_size]; 
 out_low=stack_low[stack_size]; 
 out_length=stack_length[stack_size]; 
 out_str=str_stack[stack_size]; 

 if(stack_size-1 !=-1)
 {
  cout<<"choose: "<<str_stack[stack_size]<<"\t\t目前最佳值:"<<upper_best<<endl; 
  cout<<"upper bound=-"<<stack_up[stack_size]<<"\t\tlower bound=-"<< stack_low[stack_size]<<endl;
  
 
 }
 stack_size--; 
} 
int main()
{
   int num,weight_max;  
   
   fstream fin;
   string str,name; 
   
   cout<<"請輸入檔名(包含副檔名)"<<endl; 
   cin>>name; 
   fin.open(name.c_str(),ios::in);//開啟檔案 
   
   /*--確定第一排的n 為多少 -*/ 
   if(fin >> str)
   {
     num = atoi(str.c_str());//找出num 
   } 
   if(fin >> str)
   {
     weight_max = atoi(str.c_str());//找出num 
   } 
   int p[num]; //p
   int w[num]; //w
   float value[num];
   int item[num];//編號 
   
   string choose=""; 
   for(int t=1 ;t<=num;t++)
   {
      if(fin >> str)
      w[t]= atoi(str.c_str());
   }  
   for(int t=1 ;t<=num;t++)
   {
      if(fin >> str)
      p[t]= atoi(str.c_str());
   }
   for(int t=1 ;t<=num;t++)
   {
     value[t] = (float)p[t]/w[t];
     item[t]=t; 
   }
   
   /*cout<<"n="<<num<<"M="<<weight_max<<endl; 
   for(int t=1 ;t<=num;t++)
   {
      cout<<"第"<<item[t]<<"項: w="<< w[t]<<" p="<<p[t]<<" w/p="<<value[t]<<endl;   
   }*/ 
   
   /*------ sort--------*/ 
   for(int t=1 ;t<=num;t++)
   {
     for(int u=1 ;u<=num-t;u++)  
     { 
      if(value[u]<value[u+1])
      {
       int tem_p=p[u];
       p[u]=p[u+1];
       p[u+1]=tem_p;
       
       int tem_w=w[u];
       w[u]=w[u+1];
       w[u+1]=tem_w;
       
       int tem_item=item[u];
       item[u]=item[u+1];
       item[u+1]=tem_item;
       
       float tem_v=value[u];
       value[u]=value[u+1];
       value[u+1]=tem_v;  
      }
     }    
   } 
   
   
   /*cout<<"n="<<num<<"M="<<weight_max<<endl; 
   for(int t=1 ;t<=num;t++)
   {
      cout<<"第"<<item[t]<<"項: w="<< w[t]<<" p="<<p[t]<<" w/p="<<value[t]<<endl;   
   } */ 
   
   int low=low_bound(w,p,value,weight_max,choose,num);
   int up=up_bound(w,p,value,weight_max,choose,num);
   lower_best=low;
   upper_best=up;
   insert(up,low,choose); 
   output(); 
   string choose2;
  // cout<<"choose="<<choose<<" length="<<choose.length();
   choose2=out_str; 
     
   do
   {
    if(choose2.length()<num )
    {
     choose2=out_str+"0"; 
    
     low=low_bound(w,p,value,weight_max,choose2,num);                            
     up=up_bound(w,p,value,weight_max,choose2,num); 
     if(low!=-1 && up!=-1)
     insert(up,low,choose2); 
   
     choose2=out_str+"1"; 
     low=low_bound(w,p,value,weight_max,choose2,num);                            
     up=up_bound(w,p,value,weight_max,choose2,num);
     if(low!=-1 && up!=-1) 
     insert(up,low,choose2); 
    }
     
    output();
    choose2=out_str;   
    if( /*(out_low-out_up)<=(lower_best-upper_best) && */out_up>=upper_best) 
    {
     upper_best=out_up;
     lower_best=out_low;
    }
   } while( stack_size!=-1);
   
   
   cout<<endl; 
   cout<<"best upper bound=-"<<upper_best<<"\tbest lower bound=-"<< lower_best<<endl;
   cout<<"最佳獲利:"<< upper_best<<" \t\t使用DFS"<<endl; 
   
   
   system("pause"); 
   return 0; 
}
 
