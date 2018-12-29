#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <time.h>
using namespace std;

 void part(int begin,int end,float coordi_y[],int rank[])
{  
   int len=end-begin+1;
   if(len==2)
    {
      if(coordi_y[begin]>coordi_y[end])
      {
       rank[begin]=1;
       rank[end]=0;
      }
      else if(coordi_y[end]>coordi_y[begin])
      {
       rank[begin]=0;
       rank[end]=1;     
      }
      else
      {
        rank[begin]=0;
        rank[end]=0;   
      }
    }
   else
    rank[begin]=0; 
}
void merge(int l_b,int l_e,int r_b,int r_e,float y[],int rank[])
{
   for(int i=l_b;i<=l_e;i++)
     for(int j=r_b;j<=r_e;j++)
     {
       if(y[j]>y[i])
        rank[j]=rank[j]+1;     
     }
}
void findmid(int begin,int end,int n,float coordi_x[],float coordi_y[],int rank[])
{
  int mid;

  if(n%2==1)
  mid=n/2+1;
  else
  mid=n/2;
  
  mid=mid+begin-1;
  int len_l=mid-begin+1;
  int len_r=n-mid;
  if(len_l>2)
  findmid(begin,mid,len_l,coordi_x,coordi_y,rank);  
  if(len_r>2)
  findmid(mid+1,end,len_r,coordi_x,coordi_y,rank); 
  
  part (begin,mid,coordi_y,rank); //LEFT 
  part (mid+1,end,coordi_y,rank); //RIGHT 
  merge(begin,mid,mid+1,end,coordi_y,rank); //�X�� 
   
}
 
int main()
{
   int num,rank_max;  
   float mid_x,tem_x=0,tem_y=0;
   int tem_items=0; 
   LARGE_INTEGER start_time,end_time,freq;
   double time; //�ŧi�ɶ�
   QueryPerformanceFrequency(&freq); //���oCPU�W�v
   
   fstream fin;
   string str,name; 
	 
	cout<<"�п�J�ɦW(�]�t���ɦW)"<<endl; 
	cin>>name; 
    
    fin.open(name.c_str(),ios::in);//�}���ɮ� 
    QueryPerformanceCounter(&start_time);//�ɶ��}�l 
  
   /*--�T�w�Ĥ@�ƪ�n ���h�� -*/ 
    if(fin >> str)
    {
     num = atoi(str.c_str());
     cout<<num<<endl;  //��Xnum 
    } 
    float coordi_x[num]; //�ŧix�y�� 
    float coordi_y[num]; //�ŧiy�y��
    int items[num];
    int rank[num];
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
    
   findmid(1,num,num,coordi_x,coordi_y,rank); //�I�s�禡 findmid 
   
   QueryPerformanceCounter(&end_time);// �ɶ����� 
   cout<<"CPU�ɶ�: "; 
   time=((double)end_time.QuadPart-(double)start_time.QuadPart)/freq.QuadPart;
   cout << time << "s"<< endl; 
   /*----------------��rank�̤j���I-----------------------------*/
   cout<<"�̤jrank���I: ";
   rank_max=rank[1];
  
   for(int t=1 ; t<=num; t++) //��X�̤jrank 
    if(rank_max<rank[t])  
        rank_max=rank[t];
    
   for(int t=1 ; t<=num; t++)
   {
    if(rank[t]==rank_max)
    cout <<items[t]<<"("<< coordi_x[t] <<"," << coordi_y[t] <<")\t";
   }
    cout<<endl; 
   /*---------------------�L�X�Ҧ����I-----------------------------*/
   cout<<"�Ҧ��I"<<endl;
    for(int t=1 ;t<=num;t++)
   { 
     cout <<items[t]<<"("<< coordi_x[t] <<"," << coordi_y[t] <<") "<<rank[t]<<"\t";
     if(t%5==0)
     cout <<endl; 
   }
   
  
   system("pause"); 
   return 0; 
}

