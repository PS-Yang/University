#include <iostream>
#include <iomanip> 
#include <algorithm> 
#include <vector>
#include <numeric>
using namespace std;


int main()
{
 vector<float> vfl1;
 vector<float> vfl2;
 vector<float> vfl3;
 int n1,n2,so1,so2;
 int swap_n1,swap_n2,swap1,swap2;
 int search_n; 
 int sum_v,sum_n; 
 float sum; 
 float max_1,max_2,max_3; 
 float *a;
 float *b;
 float *c;
 //--------�]�wvector1���ƭ�---- 
 cout<<"vector1���X�ӼƦr:";
 cin>>n1;
 a=new float [n1];
 if(!a) 
 {
  cout<<"Memory allocation error!";
  exit(1); 
 }
 cout<<"\n�п�Jvector1��"<<n1<<"�ӼƦr����:"<<endl;  
 for(int i=0 ; i<n1 ; i++) 
  cin >>a[i]; 
 for(int i=0; i<n1; i++) 
  vfl1.push_back(a[i]); 
 //--------�]�wvector2���ƭ�---- 
 cout<<"\nvector2���X�ӼƦr:";
 cin>>n2;  
 b=new float [n2];
 if(!b) 
 {
  cout<<"Memory allocation error!";
  exit(1); 
 }  
 cout<<"\n�п�Jvector2��"<<n2<<"�ӼƦr����:"<<endl;  
 for(int i=0 ; i<n2 ; i++) 
  cin >>b[i]; 
 for(int i=0; i<n2; i++) 
  vfl2.push_back(b[i]);
 //-------vector1�Ƨ�--------- 
 do{ 
  cout<<"\n�п�Jvector1�n�ƨ�ĴX�ӼƦr:";
  cin>>so1;
  if(so1>n1)
  cout<<"�Ȥ���W�L"<<n1<<"��!!\n"; 
 }while(so1>n1);
 sort(vfl1.begin(),vfl1.begin()+so1);
 //-------vector2�Ƨ�---------- 
 do{  
  cout<<"\n�п�Jvector2�n�ƨ�ĴX�ӼƦr:"; 
  cin>>so2;
  if(so2>n2)
  cout<<"�Ȥ���W�L"<<n2<<"��!!\n"; 
 }while(so2>n2);
 sort(vfl2.begin(),vfl2.begin()+so2);
 //-------��X�Ƨǫ᪺��----------
 cout<<"\n----vector1�Ƨǫ�----\n"; 
 for(int i=0;i<vfl1.size();i++)
  cout << vfl1[i]<<"\t";
  cout<<endl;
 cout<<"\n----vector2�Ƨǫ�----\n";  
 for(int i=0;i<vfl2.size();i++)
  cout << vfl2[i]<<"\t";
  cout<<endl; 
 // --------�]�wvector3----
 c=new float[so1+so2];
 if(!c) 
 {
  cout<<"Memory allocation error!";
  exit(1); 
 }   
  for(int i=0; i<(so1+so2); i++) 
  vfl3.push_back(c[i]); 
 //-------merge sorted numbers---------- 
 merge(vfl1.begin() , vfl1.begin()+so1 , vfl2.begin() , vfl2.begin()+so2 , vfl3.begin()); 
 cout<<"\n----merge vector1 and vector2----\n"; 
 cout<<"----vector3----\n"; 
 for(int i=0;i<vfl3.size();i++)
 cout<< vfl3[i]<<"\t";
 cout<<endl;
 //-------��ܨ��vector---------- 
 while(true)
 { 
  cout<<"�n������vector:"; 
  cin>>swap1;
  cin>>swap2; 
  if( swap1>3 || swap1<1 )
  cout<<"�п�1��2��3!!!\n"; 
  if( swap2>3 || swap2<1)
  cout<<"�п�1��2��3!!!\n"; 
  if( swap1>swap2 )
  cout<<"�Ĥ@�Ӫ��Ȥ����ĤG�Ӥj!!!\n";
  if(swap1==swap2)
  cout<<"�����P�@��!!!\n"; 
  if( (swap1==1 || swap1==2 || swap1==3) && (swap2==1 || swap2==2 || swap2==3) && swap1<swap2 ) 
  break; 
 } 
 //-------��ܨ��vector���ĴX�ӼƦr---------- 
 if(swap1==1 && swap2==2) //vector1 vector2 
 { 
  do{  
   cout<<"vector"<<swap1<<"�����ĴX�ӼƦr:"; 
   cin>>swap_n1;
   if( swap_n1 > n1 )
   cout<<"�䤣��o�ӼƦr!!\n"; 
  }while( swap_n1 > n1 ); 
  do{ 
   cout<<"vector"<<swap2<<"�����ĴX�ӼƦr:"; 
   cin>>swap_n2; 
   if( swap_n2 > n2 )
   cout<<"�䤣��o�ӼƦr!!\n";
  }while( swap_n2 > n2 ); 
  iter_swap( vfl1.begin()+swap_n1-1 , vfl2.begin()+swap_n2-1 ); 
  cout<<"\n----�洫����----\n"; //��X�洫�᪺�� 
  cout<<"----vector1----\n"; 
  for(int i=0;i<vfl1.size();i++)
   cout << vfl1[i]<<"\t";
  cout<<"\n\n----vector2----\n";  
  for(int i=0;i<vfl2.size();i++)
   cout << vfl2[i]<<"\t";
  cout<<endl; 
 } 
 if(swap1==1 && swap2==3) //vector1 vector3 
 { 
  do{ 
   cout<<"vector"<<swap1<<"�����ĴX�ӼƦr:"; 
   cin>>swap_n1;
   if( swap_n1 > n1 )
   cout<<"�䤣��o�ӼƦr!!\n"; 
  }while( swap_n1 > n1 ); 
  do{ 
   cout<<"vector"<<swap2<<"�����ĴX�ӼƦr:"; 
   cin>>swap_n2; 
   if( swap_n2 > (so1+so2) ) 
   cout<<"�䤣��o�ӼƦr!!\n";
  }while( swap_n2 > (so1+so2) ) ; 
  iter_swap( vfl1.begin()+swap_n1-1 , vfl3.begin()+swap_n2-1 );
  cout<<"\n----�洫����----\n"; //��X�洫�᪺�� 
  cout<<"----vector1----\n"; 
  for(int i=0;i<vfl1.size();i++)
   cout << vfl1[i]<<"\t";
  cout<<"\n\n----vector3----\n";  
  for(int i=0;i<vfl3.size();i++)
   cout << vfl3[i]<<"\t";
  cout<<endl; 
 } 
 if(swap1==2 && swap2==3) //vector2 vector3 
 { 
  do{ 
   cout<<"vector"<<swap1<<"�����ĴX�ӼƦr:"; 
   cin>>swap_n1;
   if( swap_n1 > n2)
   cout<<"�䤣��o�ӼƦr!!\n"; 
  }while( swap_n1 > n2 ); 
  do{ 
   cout<<"vector"<<swap2<<"�����ĴX�ӼƦr:"; 
   cin>>swap_n2; 
   if( swap_n2 > (so1+so2) )
   cout<<"�䤣��o�ӼƦr!!\n";
  }while( swap_n2 > (so1+so2) ); 
  iter_swap( vfl2.begin()+swap_n1-1 , vfl3.begin()+swap_n2-1 );
  cout<<"\n----�洫����----\n"; //��X�洫�᪺�� 
  cout<<"----vector2----\n"; 
  for(int i=0;i<vfl2.size();i++)
   cout << vfl2[i]<<"\t";
  cout<<"\n\n----vector3----\n";  
  for(int i=0;i<vfl3.size();i++)
   cout << vfl3[i]<<"\t";
  cout<<endl; 
 }
 //-------�j�M�ϥΪ̩ҿ�J���Ʀr----------   
  cout<<"�п�J�n�j�M���Ʀr:"; 
  cin>>search_n ; 
  
  sort(vfl1.begin(),vfl1.end()); //-------�n�ϥ�binary search �ҥH�n���Ʀn----------
  sort(vfl2.begin(),vfl2.end()); //-------�n�ϥ�binary search �ҥH�n���Ʀn----------
  cout<<"\n\n----�ƧǹL��vector----\n"; 
  cout<<"----vector1----\n";  
  for(int i=0;i<vfl1.size();i++)
   cout << vfl1[i]<<"\t";
  cout<<"\n----vector2----\n";  
  for(int i=0;i<vfl2.size();i++)
   cout << vfl2[i]<<"\t";
  cout<<"\n----vector3----\n";  
  for(int i=0;i<vfl3.size();i++)
   cout << vfl3[i]<<"\t";
  cout<<endl; 
  
  if(binary_search( vfl1.begin() , vfl1.end() , search_n ) || binary_search( vfl2.begin() , vfl2.end() , search_n ) || binary_search( vfl3.begin() , vfl3.end() , search_n ) ) 
  { 
   if( binary_search( vfl1.begin() , vfl1.end() , search_n ) ) 
   cout<<"\n"<< search_n <<"is found in vector1!!\n"; 
   if( binary_search( vfl2.begin() , vfl2.end() , search_n ) ) 
   cout<<"\n"<< search_n <<"is found in vector2!!\n";  
   if( binary_search( vfl3.begin() , vfl3.end() , search_n ) ) 
   cout<<"\n"<< search_n <<"is found in vector3!!\n"; 
  } 
  else
  cout<<"\n"<< search_n <<"is not found in any vector!!\n";  
 //-------�j�M�̤j���Ʀr---------- 
 max_1=*max_element( vfl1.begin() , vfl1.begin()+vfl1.size() ); 
 max_2=*max_element( vfl2.begin() , vfl2.begin()+vfl2.size() ); 
 max_3=*max_element( vfl3.begin() , vfl3.begin()+vfl3.size() );
 if( max_1>=max_2 && max_1>=max_3) 
 cout<<"\n�T��vector�̭��̤j����:"<<max_1; 
 else if( max_2>=max_3 && max_2>=max_1) 
 cout<<"\n�T��vector�̭��̤j����:"<<max_2; 
 else if( max_3>=max_2 && max_3>=max_1) 
 cout<<"\n�T��vector�̭��̤j����:"<<max_3;  
 //-------���`�M----------
 while(true)
 { 
  cout<<"\n�n�[��ĴX��vector:"; 
  cin>>sum_v; 
  if( sum_v!=1 && sum_v!=2 && sum_v!=3 )
   cout<<"�п�1��2��3!!!\n"; 
  if( sum_v==1 || sum_v==2 || sum_v==3 ) 
   break; 
 }  
  if( sum_v==1) //-------�u�[���1��vector�����Y��---------- 
  { 
   do{ 
    cout<<"\n�n�[��vector1�����ĴX�ӼƦr:"; 
    cin>>sum_n; 
    if( sum_n>vfl1.size() ) 
     cout<<"vector1�u��"<<vfl1.size()<<"�ӼƦr��!!\n"; 
   }while(sum_n>vfl1.size()); 
   sum=accumulate( vfl1.begin() , vfl1.begin()+sum_n , 0.0) ; 
   cout<<"\n�qvector��1�ӼƦr�[��vector1������"<<sum_n<<"�ӼƦr���`�X��:"<<sum; 
  } 
  if( sum_v==2) //-------�u�[���2��vector�����Y��----------
  { 
   do{ 
    cout<<"\n�n�[��vector2�����ĴX�ӼƦr:"; 
    cin>>sum_n; 
    if( sum_n>vfl2.size() ) 
     cout<<"vector2�u��"<<vfl2.size()<<"�ӼƦr��!!\n"; 
   }while(sum_n>vfl2.size()); 
   sum=accumulate( vfl1.begin() , vfl1.begin()+vfl1.size() , 0.0) ; 
   sum=sum+accumulate( vfl2.begin() , vfl2.begin()+sum_n , 0.0); 
   cout<<"\n�qvector��1�ӼƦr�[��vector2������"<<sum_n<<"�ӼƦr���`�X��:"<<sum; 
  }  
  if( sum_v==3) //-------�u�[���3��vector�����Y��----------
  { 
   do{ 
   cout<<"\n�n�[��vector3�����ĴX�ӼƦr:"; 
   cin>>sum_n; 
   if( sum_n>vfl3.size() ) 
    cout<<"vector3�u��"<<vfl3.size()<<"�ӼƦr��!!\n"; 
   }while(sum_n>vfl3.size()); 
   
    sum=accumulate( vfl1.begin() , vfl1.begin()+vfl1.size() , 0.0) ;  
    sum=sum+accumulate( vfl2.begin() , vfl2.begin()+vfl2.size() , 0.0); 
    sum=sum+accumulate( vfl3.begin() , vfl3.begin()+sum_n , 0.0);
   cout<<"\n�qvector��1�ӼƦr�[��vector3������"<<sum_n<<"�ӼƦr���`�X��:"<<sum; 
  } 
   
 system("pause") ;   
 return 0;       
}


 
