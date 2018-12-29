#include  <windows.h>
#include  <time.h>
#include  <math.h>

#include  <string>
#include  <iostream>
#include  <iomanip>


using namespace std;
int stack[1000000], stack_size;  
int stack_d[1000000]; 
string str_stack[1000000];//未走到存著的節點 

int output[1000000],output_size; //輸出節點 
int output_d[1000000]; 
string str_output[1000000];

void initial()
{
  stack_size=0; 
  output_size=0;  
}
int count_w(string str_in,string str_goal)
{
  int w=0;
  for(int i=0;i<=8;i++)   
  {
   if(str_in[i]!=str_goal[i] && str_in[i]!='0')
   {
     w++;
   }
  }       
 return w; 
}
void output_item()
{
  
  output_size++;
   
  output[output_size]=stack[stack_size]; 
  output_d[output_size]=stack_d[stack_size];
  str_output[output_size]=str_stack[stack_size];
  
  stack_size--;   
}
void output_item(string str_in,int d,int w)
{
  output_size++;
  int f=d+w;
  output[output_size]=f; 
  output_d[output_size]=d;
  str_output[output_size]=str_in;
  
}
void output_print()
{
 for(int i=1;i<=output_size;i++)
 {
   string str=str_output[i]; 
   int w=output[i]-output_d[i];
   cout<<"第"<<i-1<<"步"<<endl; 
   cout<<"f=d+w"<<" "<<output[i]<<"=";
   cout<<output_d[i]<<"+"<<w<<endl;
   
   cout<<str[0]<<"  "<<str[1]<<"  "<<str[2]<<"  "<<endl; 
   cout<<str[3]<<"  "<<str[4]<<"  "<<str[5]<<"  "<<endl; 
   cout<<str[6]<<"  "<<str[7]<<"  "<<str[8]<<"  "<<endl<<endl;
 
 }
}
void insert(string str_in,string str_goal,int d,int w)
{
  stack_size++;
  

  int f=d+w;
 // cout<<"d="<<d<<" w="<<w<<" f="<<f<<endl; 
  stack[stack_size]=f;
  stack_d[stack_size]=d;
  str_stack[stack_size]=str_in;
  
  
  /*  cout<<str_in[0]<<"  "<<str_in[1]<<"  "<<str_in[2]<<"  "<<endl; 
   cout<<str_in[3]<<"  "<<str_in[4]<<"  "<<str_in[5]<<"  "<<endl; 
   cout<<str_in[6]<<"  "<<str_in[7]<<"  "<<str_in[8]<<"  "<<endl<<endl;*/
    
  if(stack_d[stack_size]==stack_d[stack_size-1]) 
  { 
    if(stack[stack_size]>stack[stack_size-1]) 
    {
       int temp; 
       string str_temp;
       temp=stack[stack_size];
       stack[stack_size]=stack[stack_size-1];
       stack[stack_size-1]=temp;
       
       str_temp=str_stack[stack_size];
       str_stack[stack_size]=str_stack[stack_size-1];
       str_stack[stack_size-1]=str_temp;
    } 
                                               
  } 
  
}

void move(string str_in,string str_goal,int d)
{
     int zero_loc=str_in.find("0", 0);
     int w1,w2,w3,w4;
     int count=0;
     string str; 
     str=str_in; 
     /*cout<<str[0]<<"  "<<str[1]<<"  "<<str[2]<<"  "<<endl; 
     cout<<str[3]<<"  "<<str[4]<<"  "<<str[5]<<"  "<<endl; 
     cout<<str[6]<<"  "<<str[7]<<"  "<<str[8]<<"  "<<endl<<endl; */
     
     if(zero_loc%3!=0) //left
     { 
      str=str_in;
      str[zero_loc]=str_in[zero_loc-1];
      str[zero_loc-1]=str_in[zero_loc];
      
     /* cout<<"str="<<str<<endl;
      cout<<str[0]<<"  "<<str[1]<<"  "<<str[2]<<"  "<<endl; 
      cout<<str[3]<<"  "<<str[4]<<"  "<<str[5]<<"  "<<endl; 
      cout<<str[6]<<"  "<<str[7]<<"  "<<str[8]<<"  "<<endl<<endl; */
      
      w1=count_w(str,str_goal);  
      if(w1!=0)
      { 
       int str_tf=0; //true
       for(int i=1;i<=stack_size;i++) 
       {
        if(count_w(str_stack[i],str)==0)
        str_tf=1;   //false   
       }
       for(int i=1;i<=output_size;i++) 
       {
        if(count_w(str_output[i],str)==0)
         str_tf=1;  //false       
       }
       if(str_tf==0)//true
       {
        insert(str,str_goal,d,w1); 
        count=count+1;
       }
      }
      else
      output_item(str,d,0);
     }
     if(zero_loc/3!=0)//up
     {
      str=str_in;
      str[zero_loc]=str_in[zero_loc-3];
      str[zero_loc-3]=str_in[zero_loc];
     /* cout<<"str="<<str<<endl;
      cout<<str[0]<<"  "<<str[1]<<"  "<<str[2]<<"  "<<endl; 
      cout<<str[3]<<"  "<<str[4]<<"  "<<str[5]<<"  "<<endl; 
      cout<<str[6]<<"  "<<str[7]<<"  "<<str[8]<<"  "<<endl<<endl; */
     
      w2=count_w(str,str_goal);  
      if(w2!=0) 
      { 
       int str_tf=0; //true
       for(int i=1;i<=stack_size;i++) 
       {
        if(count_w(str_stack[i],str)==0)
        str_tf=1;   //false   
       }
       for(int i=1;i<=output_size;i++) 
       {
        if(count_w(str_output[i],str)==0)
         str_tf=1;  //false       
       }
       if(str_tf==0)//true
       {
        insert(str,str_goal,d,w2); 
        count=count+1;
       }
      }
      else
      output_item(str,d,0);
     }
     if(zero_loc%3!=2)//right
     { 
      str=str_in;
      str[zero_loc]=str_in[zero_loc+1];
      str[zero_loc+1]=str_in[zero_loc];
     /* cout<<"str="<<str<<endl;
      cout<<str[0]<<"  "<<str[1]<<"  "<<str[2]<<"  "<<endl; 
      cout<<str[3]<<"  "<<str[4]<<"  "<<str[5]<<"  "<<endl; 
      cout<<str[6]<<"  "<<str[7]<<"  "<<str[8]<<"  "<<endl<<endl; */
      
      w3=count_w(str,str_goal);  
      if(w3!=0) 
      { 
       int str_tf=0; //true
       for(int i=1;i<=stack_size;i++) 
       {
        if(count_w(str_stack[i],str)==0)
        str_tf=1;   //false   
       }
       for(int i=1;i<=output_size;i++) 
       {
        if(count_w(str_output[i],str)==0)
         str_tf=1;  //false       
       }
       if(str_tf==0)//true
       {
        insert(str,str_goal,d,w3); 
        count=count+1;
       } 
      }
      else
      output_item(str,d,0); 
     }
     if(zero_loc/3!=2)//down
     {  
      str=str_in;
      str[zero_loc]=str_in[zero_loc+3];
      str[zero_loc+3]=str_in[zero_loc];
      /*cout<<"str="<<str<<endl;
      cout<<str[0]<<"  "<<str[1]<<"  "<<str[2]<<"  "<<endl; 
      cout<<str[3]<<"  "<<str[4]<<"  "<<str[5]<<"  "<<endl; 
      cout<<str[6]<<"  "<<str[7]<<"  "<<str[8]<<"  "<<endl<<endl; */
      
      w4=count_w(str,str_goal);  
      if(w4!=0) 
      { 
       int str_tf=0; //true
       for(int i=1;i<=stack_size;i++) 
       {
        if(count_w(str_stack[i],str)==0)
        str_tf=1;   //false   
       }
       for(int i=1;i<=output_size;i++) 
       {
        if(count_w(str_output[i],str)==0)
         str_tf=1;  //false       
       }
       if(str_tf==0)//true
       {
        insert(str,str_goal,d,w4); 
        count=count+1;
       } 
      }
      else
       output_item(str,d,0);
     }  
     if((w1!=0 && w2!=0 && w3!=0 && w4!=0) )  
     {
      output_item();
      move(str_output[output_size],str_goal,output_d[output_size]+1);
     }
     else 
     output_print();
     
     
} 
int main()
{
    string str_in,str_goal; 
    int d=0;
    do{ 
	cout<<"請輸入起始狀態(initial state):"; 
	cin>>str_in; 
    cout<<"請輸入目標狀態(goal state):"; 
	cin>>str_goal;
	
	}while(str_in.size()!=9 || str_goal.size()!=9) ; 
	int count=0; 
    for(int i=1;i<=8;i++) 
    {
     int loc_in=str_in.find(i+'0', 0);  
     int loc_out=str_goal.find(i+'0', 0);   
      
      for(int j=loc_in+1;j<=8;j++) 
       for(int k=loc_out-1;k>=0;k--)
       if(str_in[j]==str_goal[k] && str_in[j]!='0' ) //
        count++; 
    } 
   
	if(count%2==1)
    {
     cout<<"無法到達"<<endl;    
    } 
    else
    { 
	 initial();
     int w=count_w(str_in,str_goal);
     output_item(str_in,0,w);
	 if(w!=0) 
	 {
      move(str_in,str_goal,1); 
	 } 
     else
     {
      output_print();
     }     
    } 
     
    system("pause"); 
    return 0; 
}

 
