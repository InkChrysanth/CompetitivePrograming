/*
��̬����staticʾ�� 
*/
#include<iostream> 
using namespace std;
void Func()
{
	static int n=4; //��̬����ֻ�ڵ�һ�ε�ʱ���ʼ�������������øú�����ʱ�������û���� 
	cout<<n<<endl;
	++n;
}
int main()
{
	Func();Func();Func();
	//���4,5,6 
}
