#include<bits/stdc++.h>
  #include<string>
  using namespace std;
  
  //ack function definition
  int ack(int m,int n)
  {
      if(m == 0)
      {
         return n+1;
     }
     else if(n == 0)     {
        return ack(m - 1, 1);
     }
     else
     {
         return ack(m - 1, ack(m, n - 1));
     }
 }
 
 int main()
 {
     cout<<"***********************************"<<endl;
     cout<<"��������е�i�е�j�е�ֵΪack(i,j)"<<endl;
     cout<<"i,j��ȡֵ��0��ʼ,��һ��Ϊack(0,0)"<<endl;
     cout<<"***********************************"<<endl;
     for(int i = 0;i <= 4;i++)
     {
         for(int j = 0;j <= 3;j++)
         {
             cout<<ack(i,j)<<"\t";
         }
         cout<<endl;
     }
     
     return 0;
 }
