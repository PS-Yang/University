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
 //--------設定vector1的數值---- 
 cout<<"vector1有幾個數字:";
 cin>>n1;
 a=new float [n1];
 if(!a) 
 {
  cout<<"Memory allocation error!";
  exit(1); 
 }
 cout<<"\n請輸入vector1中"<<n1<<"個數字的值:"<<endl;  
 for(int i=0 ; i<n1 ; i++) 
  cin >>a[i]; 
 for(int i=0; i<n1; i++) 
  vfl1.push_back(a[i]); 
 //--------設定vector2的數值---- 
 cout<<"\nvector2有幾個數字:";
 cin>>n2;  
 b=new float [n2];
 if(!b) 
 {
  cout<<"Memory allocation error!";
  exit(1); 
 }  
 cout<<"\n請輸入vector2中"<<n2<<"個數字的值:"<<endl;  
 for(int i=0 ; i<n2 ; i++) 
  cin >>b[i]; 
 for(int i=0; i<n2; i++) 
  vfl2.push_back(b[i]);
 //-------vector1排序--------- 
 do{ 
  cout<<"\n請輸入vector1要排到第幾個數字:";
  cin>>so1;
  if(so1>n1)
  cout<<"值不能超過"<<n1<<"喔!!\n"; 
 }while(so1>n1);
 sort(vfl1.begin(),vfl1.begin()+so1);
 //-------vector2排序---------- 
 do{  
  cout<<"\n請輸入vector2要排到第幾個數字:"; 
  cin>>so2;
  if(so2>n2)
  cout<<"值不能超過"<<n2<<"喔!!\n"; 
 }while(so2>n2);
 sort(vfl2.begin(),vfl2.begin()+so2);
 //-------輸出排序後的值----------
 cout<<"\n----vector1排序後----\n"; 
 for(int i=0;i<vfl1.size();i++)
  cout << vfl1[i]<<"\t";
  cout<<endl;
 cout<<"\n----vector2排序後----\n";  
 for(int i=0;i<vfl2.size();i++)
  cout << vfl2[i]<<"\t";
  cout<<endl; 
 // --------設定vector3----
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
 //-------選擇兩個vector---------- 
 while(true)
 { 
  cout<<"要選哪兩個vector:"; 
  cin>>swap1;
  cin>>swap2; 
  if( swap1>3 || swap1<1 )
  cout<<"請選1或2或3!!!\n"; 
  if( swap2>3 || swap2<1)
  cout<<"請選1或2或3!!!\n"; 
  if( swap1>swap2 )
  cout<<"第一個的值不能比第二個大!!!\n";
  if(swap1==swap2)
  cout<<"不能選同一個!!!\n"; 
  if( (swap1==1 || swap1==2 || swap1==3) && (swap2==1 || swap2==2 || swap2==3) && swap1<swap2 ) 
  break; 
 } 
 //-------選擇兩個vector中第幾個數字---------- 
 if(swap1==1 && swap2==2) //vector1 vector2 
 { 
  do{  
   cout<<"vector"<<swap1<<"中的第幾個數字:"; 
   cin>>swap_n1;
   if( swap_n1 > n1 )
   cout<<"找不到這個數字!!\n"; 
  }while( swap_n1 > n1 ); 
  do{ 
   cout<<"vector"<<swap2<<"中的第幾個數字:"; 
   cin>>swap_n2; 
   if( swap_n2 > n2 )
   cout<<"找不到這個數字!!\n";
  }while( swap_n2 > n2 ); 
  iter_swap( vfl1.begin()+swap_n1-1 , vfl2.begin()+swap_n2-1 ); 
  cout<<"\n----交換之後----\n"; //輸出交換後的值 
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
   cout<<"vector"<<swap1<<"中的第幾個數字:"; 
   cin>>swap_n1;
   if( swap_n1 > n1 )
   cout<<"找不到這個數字!!\n"; 
  }while( swap_n1 > n1 ); 
  do{ 
   cout<<"vector"<<swap2<<"中的第幾個數字:"; 
   cin>>swap_n2; 
   if( swap_n2 > (so1+so2) ) 
   cout<<"找不到這個數字!!\n";
  }while( swap_n2 > (so1+so2) ) ; 
  iter_swap( vfl1.begin()+swap_n1-1 , vfl3.begin()+swap_n2-1 );
  cout<<"\n----交換之後----\n"; //輸出交換後的值 
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
   cout<<"vector"<<swap1<<"中的第幾個數字:"; 
   cin>>swap_n1;
   if( swap_n1 > n2)
   cout<<"找不到這個數字!!\n"; 
  }while( swap_n1 > n2 ); 
  do{ 
   cout<<"vector"<<swap2<<"中的第幾個數字:"; 
   cin>>swap_n2; 
   if( swap_n2 > (so1+so2) )
   cout<<"找不到這個數字!!\n";
  }while( swap_n2 > (so1+so2) ); 
  iter_swap( vfl2.begin()+swap_n1-1 , vfl3.begin()+swap_n2-1 );
  cout<<"\n----交換之後----\n"; //輸出交換後的值 
  cout<<"----vector2----\n"; 
  for(int i=0;i<vfl2.size();i++)
   cout << vfl2[i]<<"\t";
  cout<<"\n\n----vector3----\n";  
  for(int i=0;i<vfl3.size();i++)
   cout << vfl3[i]<<"\t";
  cout<<endl; 
 }
 //-------搜尋使用者所輸入的數字----------   
  cout<<"請輸入要搜尋的數字:"; 
  cin>>search_n ; 
  
  sort(vfl1.begin(),vfl1.end()); //-------要使用binary search 所以要先排好----------
  sort(vfl2.begin(),vfl2.end()); //-------要使用binary search 所以要先排好----------
  cout<<"\n\n----排序過的vector----\n"; 
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
 //-------搜尋最大的數字---------- 
 max_1=*max_element( vfl1.begin() , vfl1.begin()+vfl1.size() ); 
 max_2=*max_element( vfl2.begin() , vfl2.begin()+vfl2.size() ); 
 max_3=*max_element( vfl3.begin() , vfl3.begin()+vfl3.size() );
 if( max_1>=max_2 && max_1>=max_3) 
 cout<<"\n三個vector裡面最大的值:"<<max_1; 
 else if( max_2>=max_3 && max_2>=max_1) 
 cout<<"\n三個vector裡面最大的值:"<<max_2; 
 else if( max_3>=max_2 && max_3>=max_1) 
 cout<<"\n三個vector裡面最大的值:"<<max_3;  
 //-------算總和----------
 while(true)
 { 
  cout<<"\n要加到第幾個vector:"; 
  cin>>sum_v; 
  if( sum_v!=1 && sum_v!=2 && sum_v!=3 )
   cout<<"請選1或2或3!!!\n"; 
  if( sum_v==1 || sum_v==2 || sum_v==3 ) 
   break; 
 }  
  if( sum_v==1) //-------只加到第1個vector中的某數---------- 
  { 
   do{ 
    cout<<"\n要加到vector1中的第幾個數字:"; 
    cin>>sum_n; 
    if( sum_n>vfl1.size() ) 
     cout<<"vector1只有"<<vfl1.size()<<"個數字喔!!\n"; 
   }while(sum_n>vfl1.size()); 
   sum=accumulate( vfl1.begin() , vfl1.begin()+sum_n , 0.0) ; 
   cout<<"\n從vector第1個數字加到vector1中的第"<<sum_n<<"個數字的總合為:"<<sum; 
  } 
  if( sum_v==2) //-------只加到第2個vector中的某數----------
  { 
   do{ 
    cout<<"\n要加到vector2中的第幾個數字:"; 
    cin>>sum_n; 
    if( sum_n>vfl2.size() ) 
     cout<<"vector2只有"<<vfl2.size()<<"個數字喔!!\n"; 
   }while(sum_n>vfl2.size()); 
   sum=accumulate( vfl1.begin() , vfl1.begin()+vfl1.size() , 0.0) ; 
   sum=sum+accumulate( vfl2.begin() , vfl2.begin()+sum_n , 0.0); 
   cout<<"\n從vector第1個數字加到vector2中的第"<<sum_n<<"個數字的總合為:"<<sum; 
  }  
  if( sum_v==3) //-------只加到第3個vector中的某數----------
  { 
   do{ 
   cout<<"\n要加到vector3中的第幾個數字:"; 
   cin>>sum_n; 
   if( sum_n>vfl3.size() ) 
    cout<<"vector3只有"<<vfl3.size()<<"個數字喔!!\n"; 
   }while(sum_n>vfl3.size()); 
   
    sum=accumulate( vfl1.begin() , vfl1.begin()+vfl1.size() , 0.0) ;  
    sum=sum+accumulate( vfl2.begin() , vfl2.begin()+vfl2.size() , 0.0); 
    sum=sum+accumulate( vfl3.begin() , vfl3.begin()+sum_n , 0.0);
   cout<<"\n從vector第1個數字加到vector3中的第"<<sum_n<<"個數字的總合為:"<<sum; 
  } 
   
 system("pause") ;   
 return 0;       
}


 
