#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // ����n�β�������c�ӵ�x��
    map<int, int> pos_num; 
    while (n --)
    {
        int x, c;
        cin >> x >> c;
        pos_num[x] += c;
    }

    // ��ֵ����Ϊǰ׺��
    int last = 0;
    map<int, int>::iterator it;
    for (  it = pos_num.begin(); it != pos_num.end(); ++ it)
    {
        pos_num[it->first] += last; 
        last = it->second;
    }

    // ����m��ѯ�ʲ�������
    while(m --)
    {
        int l, r;
        cin >> l >> r;
        int l_val = (-- pos_num.lower_bound(l))->second; // �൱��ǰ׺��s[l - 1]
        int r_val = (-- pos_num.upper_bound(r))->second; // �൱��ǰ׺��s[r]
        cout << r_val - l_val << endl;
    }

    return 0;
}

