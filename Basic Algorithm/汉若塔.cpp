/*
���������� 
*/
#include<bits/stdc++.h>
using namespace std;
void Han(int n,char src ,char mid,char dest){
	//��src���ϵ�n�����ӣ���midΪ��ת���ƶ���dest�� 
	if(n==1) { //ֻ���ƶ�һ������ 
		cout<<src<<"->"<<dest<<endl;
		//ֱ�ӽ����Ӵ�src�ƶ���dest���� 
		return ; //�ݹ���ֹ 
	}
	Han(n-1,src,dest,mid); //�Ƚ�n-1�����Ӵ�src�ƶ���mid 
	cout<<src<<"->"<<dest<<endl;
	//�ٽ�һ�����Ӵ�src�ƶ���dest 
	Han(n-1,mid,src,dest);//���n-1�����Ӵ�mid�ƶ���dest 	
}
int main(){
	int n;
	cin>>n;
	Han(n,'A','B','C');
	return 0;
}
