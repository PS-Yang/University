#include  <fstream>
#include  <string>
#include  <iostream>
#include  <iomanip>
#include  <windows.h>
#include  <time.h>
#include  <math.h>
using namespace std;
float d_min=100000;
float min;
float xa,ya,xb,yb; 
float distance(float x1,float x2, float y1,float y2)
{
 float d;
 d=sqrt( fabs(x1-x2)*fabs(x1-x2) + fabs(y1-y2)*fabs(y1-y2));
 return d;    
}

 float part(int begin,int end,float coordi_x[],float coordi_y[])
{  
  int len=end-begin+1;
  float dist;
  if(len==2)
  {
   dist=distance(coordi_x[begin],coordi_x[end],coordi_y[begin],coordi_y[end]);
   
  }
  else if(len==1)
  {
   dist=100000;
  }
 
  return dist;
}
void merge(int l_b,int l_e,int r_b,int r_e,float coordi_x[],float coordi_y[])
{
  float mid;
  int begin,end; 
  mid=(coordi_x[l_e]+coordi_x[r_b])/2; 
  
  cout<<"merge的點:"; 
  for(int t=l_b;t<=r_e;t++)
  cout<<"("<<coordi_x[t]<<","<<coordi_y[t]<<") ";
  cout<<endl;  
  
  cout<<"落在L+D和L-D之間的點: "; 
  
  int count=0; 
  for(int t=l_b;t<=r_e;t++) 
  { 
   
   if(coordi_x[t]<(mid+d_min) && coordi_x[t]>(mid-d_min))
   {
    cout<<"("<<coordi_x[t]<<","<<coordi_y[t]<<") ";
    count++; //算個數 
    end=t; //結束位址 
   } 
  } 
  cout<<endl;
  begin= end-count+1; 

  for(int t=begin;t<end-1;t++) 
  {
      for(int u=t+1;u<=end;u++)     
      {
       float dist=distance(coordi_x[t],coordi_x[u],coordi_y[t],coordi_y[u]) ;   
       
       if(dist<d_min)
       {
        xa=coordi_x[t]; 
        xb=coordi_x[u];
        ya=coordi_y[t]; 
        yb=coordi_y[u]; 
        d_min=dist; 
        
       
       }
       
      } 
  } 
  cout<<"min distance="<<d_min; 
  cout<<"  此兩點座標:"<<"("<< xa <<"," << ya <<") ";
  cout<<"("<< xb <<"," << yb<<")"<<endl<<endl; 
}

void  mid_line(int begin,int end,int num,float coordi_x[],float coordi_y[])
{
   
  int mid;
  float d_l,d_r; 
  //float d_min;
 
  
  if(num%2==1)
  mid=num/2+1;
  else
  mid=num/2;
  
  mid=mid+begin-1;
  int len_l=mid-begin+1;
  int len_r=end-mid;
   
  if(len_l>2)
  mid_line(begin,mid,len_l,coordi_x,coordi_y);  
  if(len_r>2)    
  mid_line(mid+1,end,len_r,coordi_x,coordi_y);  
   
  
  d_l=part (begin,mid,coordi_x,coordi_y); //LEFT 
  d_r=part (mid+1,end,coordi_x,coordi_y); //RIGHT 
  
  if( d_min > d_l )
  { 
   d_min=d_l;
   if((mid-begin)==1)//當是兩個點的時候 
   {
    xa=coordi_x[begin]; 
    xb=coordi_x[mid];
    ya=coordi_y[begin]; 
    yb=coordi_y[mid];                                     
   } 
  } 
  if( d_min > d_r )
  { 
   d_min=d_r;
    if((end-mid)==2)//當是兩個點的時候 
   {
    xa=coordi_x[mid+1]; 
    xb=coordi_x[end];
    ya=coordi_y[mid+1]; 
    yb=coordi_y[end];                                     
   }  
  } 
  
  merge(begin,mid,mid+1,end,coordi_x,coordi_y); //合併 
  
      
}
int main()
{
   int num,l_end;  
   float tem_x=0,tem_y=0;
   int tem_items=0; 
   LARGE_INTEGER start_time,end_time,freq;
   double time; //宣告時間
   QueryPerformanceFrequency(&freq); //取得CPU頻率
  
   fstream fin;
   string str,name; 
	 
	cout<<"請輸入檔名(包含副檔名)"<<endl; 
	cin>>name; 
    
    fin.open(name.c_str(),ios::in);//開啟檔案 
    QueryPerformanceCounter(&start_time);//時間開始 
  
   /*--確定第一排的n 為多少 -*/ 
    if(fin >> str)
    {
     num = atoi(str.c_str());//找出num 
    } 
    float coordi_x[num]; //宣告x座標 
    float coordi_y[num]; //宣告y座標
    int items[num];
 
    for(int t=1 ;t<=num;t++)
    {
      if(fin >> str)
      coordi_x[t]= atof(str.c_str());
      if(fin >> str)
      coordi_y[t]= atof(str.c_str());
      items[t]=t;
    }  
   
    
    
   /*------ sort--------*/ 
   for(int t=1 ;t<=num;t++)
   {
     for(int u=1 ;u<=num-t;u++)  
     { 
      if(coordi_x[u]>coordi_x[u+1])
      {
       tem_x=coordi_x[u];
       coordi_x[u]=coordi_x[u+1];
       coordi_x[u+1]=tem_x;
       
       tem_y=coordi_y[u];
       coordi_y[u]=coordi_y[u+1];
       coordi_y[u+1]=tem_y;
         
       tem_items=items[u];
       items[u]=items[u+1];
       items[u+1]=tem_items;              
      }
     }    
   } 
 
   cout<<"1."<<endl; 
   mid_line(1,num,num,coordi_x,coordi_y);  //呼叫函式 mid_line 

   
   QueryPerformanceCounter(&end_time);// 時間結束 
   cout<<"2.CPU時間: "; 
   time=((double)end_time.QuadPart-(double)start_time.QuadPart)/freq.QuadPart;
   cout << time << "s"<< endl<<endl; 
 
   cout<<"3.最近的距離:"<<d_min;
   cout<<"  此兩點座標:"<<"("<< xa <<"," << ya <<") ";
   cout<<"("<< xb <<"," << yb<<")"<<endl; 
   system("pause"); 
   return 0; 
}

