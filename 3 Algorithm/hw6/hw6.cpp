#include  <iostream>
#include  <iomanip>
#include  <string>

using namespace std;
void lcs(string str,string str2)
{
  int check[255][255];
  string str_ans=""; 
  for(int i=0;i<=str.length();i++)
  check[i][0]=0;
  for(int j=0;j<=str2.length();j++)
  check[0][j]=0; 
  
  for(int i=1;i<=str.length();i++)
   for(int j=1;j<=str2.length();j++)
   { 
     if(str[i-1]==str2[j-1])
     { 
      check[i][j]=check[i-1][j-1]+1; 
     } 
     else  if(check[i-1][j]>check[i][j-1])//����M�W���ۤ���j�� 
     {
          check[i][j]=check[i-1][j];//�����䪺�� 
     }
     else
     {
         check[i][j]=check[i][j-1];//���W������ 
     } 
   } 
   /*
   for(int i=0;i<=str.length();i++)
   { 
    for(int j=0;j<=str2.length();j++)
    cout<<check[i][j]<<" ";
    cout<<endl;    
   } */
   
    int i=str.length();
    int j=str2.length();
 // cout<<"i="<<i<<"J="<<j<<endl; 
    while(true) 
    { 
     if(str[i-1]==str2[j-1])
     { 
       str_ans=str[i-1]+str_ans;                            
       i=i-1; 
       j=j-1; 
     }
     else 
     {
     if(check[i][j]>check[i][j-1])
     i=i-1;
     else
     j=j-1; 
     }
     //cout<<"i="<<i<<"J="<<j<<endl; 
     if(i==0 ||j==0)
     break; 
    }  
   cout<<"�r��1:"<<str<<endl<<"�r��2:"<<str2<<endl<<endl;
   cout<<"LCS�O:"<<str_ans<<"  ����:"<<str_ans.length()<<endl; 
   
} 
int main()
{
    //string str;
    //string str2;
    string str;
    string str2; 
    char check;
    do{
	cout<<"�п�J�r��1:"; 
	cin>>str; 
    cout<<"�п�J�r��2:"; 
	cin>>str2;
	
    lcs(str,str2); 
   
    cout<<"�O�_�~��<y/n>"<<endl; 
    cin>>check;
    }while(check=='y' || check=='Y');
     
    system("pause"); 
    return 0; 
}
