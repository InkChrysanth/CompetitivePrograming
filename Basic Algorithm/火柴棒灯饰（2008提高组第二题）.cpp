/*
�������Σ�NOIP2008������2�⣩
1������n<=24������ȷ��ö��A��B�ķ�Χ��
2�����ÿ�μ���ÿ�����ֵĻ���������Է����ظ������ˣ�Ԥ���������
ͨ���ǽ��ز���������������ý����㷶Χ�ڵ����������õĻ����Ŀ�����
 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
int f[2005]={6,2,5,5,4,5,6,3,7,6},n;
int main(){
	cin>>n;
	for(int i=10;i<=maxn*2;i++){
		int x=i;
		while(x>0){
			f[i]+=f[x%10];
			x/=10;
		}
	}
	int ans=0;
	n=n-4; //�ܻ�������ȥ'+'��'='����Ļ����� 
	for(int i=0;i<=maxn;i++){ //ö��A 
		if(f[i]>=n) continue ;//��֦������iѭ�� 
		for(int j=0;j<=maxn;j++) {//ö��B
			if(f[i]+f[j]>=n) continue ;//��֦������jѭ��
			int k=i+j;
			if(f[i]+f[j]+f[k]==n) {
				cout<<i<<"+"<<j<<"="<<k<<endl;
			    ans++;	//����������������1 
			}
		}
	}
	cout<<ans;
    return 0;
}
