/*
vector֧�ֱȽ� 
vector<int>a(4,5),b(3,4);
	bool t;
	t=a<b;
	cout<< t;
	
 deque<int>pp;//˫�˶���  �ٶȳ��� 
    size()
	empty()
	clear()
	front()/back()
	push_front()/pop_back()
	begin()/end()
	
set/multiset ʱ�临�Ӷ���0(logn) ;
   insert()
   find()
   count()
   earse()
   begin(),end() ++,--����ǰ���ͺ�� 
    (1)������һ������ɾ������x;
	(2)����һ����������ɾ�����������
	lower_bound(x) ���ش��ڵ���x����С��һ�������� 
	upper_bound(x)		���ش���x����С���ĵ�����
	 
map/multimap	
    insert()  ���������һ��pair 
    earse()   ����Ĳ�����pair���ߵ�����
	find() 
	[]ʱ�临�Ӷ���0(logn) ;
    lower_bound(x) ���ش��ڵ���x����С��һ�������� 
	upper_bound(x)		���ش���x����С���ĵ�����
	
unordered_set,unordered_map,unordered_multimap,unordered_multiset,��ϣ��
    ���������ƣ���ɾ�Ĳ��ʱ�临�Ӷ���O(1);
	��֧��lower_bound()/upper_bound();	
	
bitset,ѹλ
	 bitset<10000> S; //����Ϊ10000��S
	 ~,&,|,^,>>,<<,==,!= []
	 count() �����ж��ٸ�1
	 any/none()
	 any()�Ƿ�������һ��1
	 none()�ж��Ƿ�ȫΪ0	 
	 set(),������λ�ó�1
	 set(k,v)����kλ���v
	 reset()������λ���0
	 flip()�ȼ���~
	 flip(k)�ѵ�kλȡ�� 
	  
*/
#include<bits/stdc++.h> 
using namespace std;
int main(){
	vector<int>a(4,5),b(3,4);
	bool t;
	t=a<b;
	cout<< t<<endl;
    pair<int ,pair<int,int> >c;
    string sa="yxc";
    sa+="def";
    sa+='c';
    string pq;
    pq=sa.substr(1,3);
    cout<<pq<<endl;
    cout<<sa<<endl;
 //   priority_queue<int,vector<int>,greatr<int> >heap;
    priority_queue<int,vector<int>,greater<int> >heap;
    deque<int>pp;//˫�˶��� 
    set<int>S;
    multiset<int>MS;
    map<string,int>QQQQ;
    QQQQ["yxc"]=1;
    cout<<QQQQ["yxc"]<<endl;
    unordered_multimap<string, int> unQQ;
    
	return 0;
}
