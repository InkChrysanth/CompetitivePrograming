/*
lowbit���������������n������λ�ϵ����λ��1�������0 
lowbit(11100010000)=10000;


*/
int lowbit(n)
{
	// return (~n+1)&n;
	return (-n)&n;
}
