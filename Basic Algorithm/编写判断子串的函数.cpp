/*
���⣺��д�ж��Ӵ��� ����
��дһ������ ��int Strstr(char s1[],char s2[]);
���S2����S1���Ӵ�������-1��
���s2��s1���Ӵ�����������s1�е�һ�γ��ֵ�λ��
�մ����κδ����Ӵ����ҳ���λ��Ϊ0 
*/
#include<bits/stdc++.h>
using namespace std;
 char s1[105],s2[100];
int Strstr(char s1[],char s2[]){
	if(s2[0]==0) return 0; //�жϿմ� 
	for(int i=0;s1[i];++i){ //ö�ٱȽ����s1[i]==0��ʾ�ߵ������ 
	    int k=i,j=0;
	    for(;s2[j];++j,++k){ //s2[j]==0�ߵ�ĩβ 
	    	if(s1[k]!=s2[j]) break; //ʧ���˳���ǰѭ�� 
		}
		if(s2[j]==0) return i; //s2[j]==0�ߵ�ĩβƥ�� 		
	}
	return -1;
}
int main(){
	scanf("%s",s1);
	scanf("%s",s2);
	cout<<Strstr(s1,s2)<<endl;
	return 0;
}
