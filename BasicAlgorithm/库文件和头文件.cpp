/*
���ļ���ͷ�ļ� 
int abs(int x) ��������X�ľ���ֵ 
double fabs(double x) �󸡵���X�ľ���ֵ
int ceil(double x) ��С��X����С���� 
double cos(double x) ��X���ȵ����� 
double sin(double x) ��X���ȵ����� 
double sqrt(double x) ��X��ƽ���� 
�ַ�������
int isdigit(int c) �ж�C�Ƿ��������ַ� 
int isalpha(int c) �ж�C�Ƿ���һ����ĸ 
int isalnum(int c)  �ж�C�Ƿ���һ�����ֻ���ĸ 
int islower(int c) �ж�C�Ƿ���һ��Сд��ĸ 
int isupper(int c) �ж�C�Ƿ���һ����д��ĸ 
int toupper(int c) ���C��һ��Сд��ĸ���򷵻ض�Ӧ��д��ĸ 
int tolower(int c) ���C��һ����д��ĸ���򷵻ض�ӦСд��ĸ 
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a;
	if(a<0){
		cout<<"No";
		return 0;
	}
	cout<<int (sqrt(a))<<endl;
	return 0;
}
