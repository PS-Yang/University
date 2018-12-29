#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
int heap[100000], heap_size;
string heap_name[100000];
int minobject;
string name_min;  

void start() //設定初始值  
{ 
   heap_size=0;        //size大小先設為0  
} 
void insert(int object,string name) //插入值 
{
   heap_size++;
   heap[heap_size] = object; 
   heap_name[heap_size] = name;
   
   int now_size= heap_size;
    
   while( now_size>1 )  //比到heap[1] 
   {
       if (object < heap[now_size/2])  //如果進來的點比父節點小  
       { 
        heap[now_size] = heap[now_size/2]; //兩者值交換 
        heap[now_size/2] = object; 
        
        heap_name[now_size] = heap_name[now_size/2];//兩者名稱交換 
        heap_name[now_size/2] = name; 
       } 
       
       now_size = now_size/2;
   } 
   
     
} 
void del_findmin()
{
    
     int lastobject,child,now;
     string name_last; 
    
     minobject = heap[1];
     name_min = heap_name[1];
     
     lastobject = heap[heap_size];
     name_last = heap_name[heap_size]; 
     heap_size--; //要把minobject輸出 所以size-1
      
      
     heap[1]= lastobject;
     heap_name[1]= name_last;
     for(int s=1;s*2<=heap_size;s++)
     {  
      if(heap[2*s]<heap[2*s+1] && heap[s]>heap[2*s])  // 左邊child<右邊child且parent比左邊child大 
      {
         heap[s]=heap[2*s];                            //parent和左邊child互換 
         heap[2*s]=lastobject;     
         heap_name[s]=heap_name[2*s];
         heap_name[2*s]=name_last;                                           
      }
      else if(heap[2*s] > heap[2*s+1] && heap[s]>heap[2*s+1]) //左邊child>右邊child且parent比右邊child大 
      {
         heap[s]=heap[2*s+1];                           //parent和右邊child互換  
         heap[2*s+1]=lastobject;     
         heap_name[s]=heap_name[2*s+1];
         heap_name[2*s+1]=name_last;   
      } 
      else  
      {
        if(heap[s]>heap[2*s])  //如果只有左邊child且  parent比左邊child大
        {
         heap[s]=heap[2*s];    //parent和左邊child互換  
         heap[2*s]=lastobject;     
         heap_name[s]=heap_name[2*s];
         heap_name[2*s]=name_last;                      
        } 
      }
     } 
    
     
} 

int main()
{
	fstream fin;
	string str,name; 
	string s1,s2;
	int num,count=0; 
	string lin_nam[10000];
	int lin_value[10000],lin_value_b[10000];
	
	int min1[10000],min2[10000];
	string name_min1[10000],name_min2[10000];
     
	int i=1;
	cout<<"請輸入檔名(包含副檔名)"; 
	cin>>name;
	
  
    fin.open(name.c_str(),ios::in);//開啟檔案 
   
     while(fin>>str)
    {
      lin_nam[i]= str.c_str();
      if(fin >> str)
      lin_value[i]= atoi(str.c_str());
      i++;
    }  
    num=i-1;
    fin.close();
  
    start();
    for(int i=1 ;i<=num;i++)  //把檔案讀入的都丟到陣列 
    {
     insert( lin_value[i],lin_nam[i] ); 
    }  
    
    
    
    for(int j=1 ;j<num;j++) 
    { 
     del_findmin(); 
     min1[j]= minobject;   //heap內最小的 值 
     name_min1[j]= name_min;//heap內最小的 名稱 
      
     del_findmin();
     min2[j]= minobject;      //heap內最小的 值
     name_min2[j]= name_min; //heap內最小的 名稱  
      
     lin_value_b[j]=min1[j]+min2[j]; //相加得到的新值 
     count=count+lin_value_b[j]-1;  //計算次數 
    
     stringstream ss; 
     ss << j; //將j轉成字串 
     insert( lin_value_b[j],"B"+ss.str()); //把新值insert回去 
    }  
    
     cout <<"1.合併次數: "<<count<<endl;
     cout <<"2.合併順序"<<endl;
    for(int k=1 ;k<num;k++) 
    {
     cout << "(" << name_min1[k] << " " << name_min2[k] << ")="; 
     cout << "(" << min1[k] << " " << min2[k] << ")"; 
     cout << "->B" << k << "," << lin_value_b[k] << endl;  
    } 
	system("pause");
	return 0;
}
