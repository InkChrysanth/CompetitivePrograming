#include<bits/stdc++.h>
using namespace std;
double a[5];
#define EPS 1e-6
bool isZero(double x){
	return fabs(x)<=EPS;
}
bool cout24(double a[],int n){ //���������n���� ����24 
	if(n==1) {
		if(isZero(a[0]-24)) return true;
		else return false;
	}
	double b[5];
	for(int i=0;i<n;i++)
	   for(int j=i+1;j<n;j++){ //ö������������� 
	   	    int m=0;//��¼��ʣ�µ��� 
	   	    for(int k=0;k<n;k++){
	   	    	if(k!=i && k!=j) b[m++]=a[k]; // ��ʣ������������b�� 
			   }
			b[m]  =a[i] +a[j];
			if(cout24(b,m+1)) return true;
			b[m]=a[i]-a[j];
			if(cout24(b,m+1)) return true;
			b[m]=a[j]-a[i] ;
			if(cout24(b,m+1)) return true;
			b[m]=a[i]*a[j];
			if(cout24(b,m+1)) return true;
			if(!isZero(a[i])){
				b[m]=a[j]/a[i];
				if(cout24(b,m+1)) return true;
			}
			if(!isZero(a[j])){
				b[m]=a[i]/a[j];
				if(cout24(b,m+1)) return true;
			}
	   }
	   return false;
}
int main(){
//	int n;
//	cin>>n;
	for(int i=0;i<4;i++)cin>>a[i];
	if(cout24(a,4)) cout<<"YES"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
