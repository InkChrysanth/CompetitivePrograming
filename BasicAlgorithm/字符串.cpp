/*
�ַ��� 
strlen��������÷�
char s[100]="test" ;
for(int i=0;i<strlen(s);++i{
s[i]=s[i]+1;
strlen������ִ������Ҫʱ��ģ���ʱ����ַ����ĳ��ȳ�����
ÿ��ѭ����������strlen����������Ч���ϵĺܴ��˷� 
��Ϊ 
char s[100]="test" ;
int len=strlen(s); 
for(int i=0;i<len;++i{
s[i]=s[i]+1;
��
for(int i=0;s[i];i++{ //s[i]==0��'\0' 
s[i]=s[i]+1;
}
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	char buf[10];
	cin.getline(buf,sizeof(buf));//�Զ����'\0' 
//	getline(cin,buf);
	cout<<buf;
	char s[110];
	while(gets(s)){
		printf("%s\n",s);
	}
	return 0;
}
