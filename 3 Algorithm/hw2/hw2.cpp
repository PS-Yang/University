#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
int heap[100000], heap_size;
string heap_name[100000];
int minobject;
string name_min;  

void start() //�]�w��l��  
{ 
   heap_size=0;        //size�j�p���]��0  
} 
void insert(int object,string name) //���J�� 
{
   heap_size++;
   heap[heap_size] = object; 
   heap_name[heap_size] = name;
   
   int now_size= heap_size;
    
   while( now_size>1 )  //���heap[1] 
   {
       if (object < heap[now_size/2])  //�p�G�i�Ӫ��I����`�I�p  
       { 
        heap[now_size] = heap[now_size/2]; //��̭ȥ洫 
        heap[now_size/2] = object; 
        
        heap_name[now_size] = heap_name[now_size/2];//��̦W�٥洫 
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
     heap_size--; //�n��minobject��X �ҥHsize-1
      
      
     heap[1]= lastobject;
     heap_name[1]= name_last;
     for(int s=1;s*2<=heap_size;s++)
     {  
      if(heap[2*s]<heap[2*s+1] && heap[s]>heap[2*s])  // ����child<�k��child�Bparent����child�j 
      {
         heap[s]=heap[2*s];                            //parent�M����child���� 
         heap[2*s]=lastobject;     
         heap_name[s]=heap_name[2*s];
         heap_name[2*s]=name_last;                                           
      }
      else if(heap[2*s] > heap[2*s+1] && heap[s]>heap[2*s+1]) //����child>�k��child�Bparent��k��child�j 
      {
         heap[s]=heap[2*s+1];                           //parent�M�k��child����  
         heap[2*s+1]=lastobject;     
         heap_name[s]=heap_name[2*s+1];
         heap_name[2*s+1]=name_last;   
      } 
      else  
      {
        if(heap[s]>heap[2*s])  //�p�G�u������child�B  parent����child�j
        {
         heap[s]=heap[2*s];    //parent�M����child����  
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
	cout<<"�п�J�ɦW(�]�t���ɦW)"; 
	cin>>name;
	
  
    fin.open(name.c_str(),ios::in);//�}���ɮ� 
   
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
    for(int i=1 ;i<=num;i++)  //���ɮ�Ū�J�������}�C 
    {
     insert( lin_value[i],lin_nam[i] ); 
    }  
    
    
    
    for(int j=1 ;j<num;j++) 
    { 
     del_findmin(); 
     min1[j]= minobject;   //heap���̤p�� �� 
     name_min1[j]= name_min;//heap���̤p�� �W�� 
      
     del_findmin();
     min2[j]= minobject;      //heap���̤p�� ��
     name_min2[j]= name_min; //heap���̤p�� �W��  
      
     lin_value_b[j]=min1[j]+min2[j]; //�ۥ[�o�쪺�s�� 
     count=count+lin_value_b[j]-1;  //�p�⦸�� 
    
     stringstream ss; 
     ss << j; //�Nj�ন�r�� 
     insert( lin_value_b[j],"B"+ss.str()); //��s��insert�^�h 
    }  
    
     cout <<"1.�X�֦���: "<<count<<endl;
     cout <<"2.�X�ֶ���"<<endl;
    for(int k=1 ;k<num;k++) 
    {
     cout << "(" << name_min1[k] << " " << name_min2[k] << ")="; 
     cout << "(" << min1[k] << " " << min2[k] << ")"; 
     cout << "->B" << k << "," << lin_value_b[k] << endl;  
    } 
	system("pause");
	return 0;
}
