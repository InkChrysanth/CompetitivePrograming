/*
ֱ�Ӳ������򡢶��֡�ϣ�����ַ��� 
ϣ�������㷨Ч�����������е�ȡֵ�й� 
ֱ�Ӳ�������Ͷ�������Ϊ�ȶ����� 
ϣ������Ϊ���ȶ������� 
*/

#include<bits/stdc++.h>
using namespace std;

const int maxn=100005;
int i,j,a[maxn],n;
void kin(int a[]){  //ֱ�Ӳ�������
	for(i=2;i<=n;i++){
	   if(a[i]<a[i-1]) {
		    a[0]=a[i];//�����ڱ�
		    for(j=i-1;a[0]<a[j];j--) //�Ӻ���ǰ�Ƚ� 
                 a[j+1]=a[j];
            a[j+1]=a[0];
	    }	 
    }
}
void erfenin(int a[]){  //�������� 
	for(i=2;i<=n;i++){
	   if(a[i]<a[i-1]) {
		    a[0]=a[i];//�����ڱ�
		    int low=1,high=i-1;
		    while(low<=high){ //�������� 
		    	int mid=low+(high-low)/2;
		        if(a[0]<a[mid]) high=mid-1;
		        else low=mid+1;
			}
		    for(j=i-1;j>=low;--j) a[j+1]=a[j]; //�ƶ������λ�� 
		    a[low]=a[0]; //��a[0]�����ҵ��Ĳ���λ�� 
	    }	 
    }
}
int b[3]={7,3,1};//����ʱ��Ԫ�ؼ������ 
void ShellInsert(int a[],int t){ //ϣ������,tΪ������� 
	for(i=t+1;i<=n;i++) //���Ϊt�Ĳ������� ��ԭ�����������1����t�Ϳ� 
	   if(a[i]<a[i-t]){
	   	a[0]=a[i];
	   	for(j=i-t;a[0]<a[j];j-=t)
	   	   a[j+t]=a[j];
	   	a[j+t]=a[0];   
	   }	   
}
void ShellSort(int a[],int b[]){ //������bΪ���������е�ϣ������ 
	int t=sizeof(b);
	for(int k=0;k<t;k++)
	  ShellInsert(a,b[k]);
}

int main(){
	
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	//kin(a);
    //erfenin(a);
    ShellSort(a,b); 
    for(i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}


 
