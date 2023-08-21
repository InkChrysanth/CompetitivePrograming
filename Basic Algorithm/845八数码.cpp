#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int bfs(string state)
{
    queue<string> q;
    unordered_map<string, int> d;

    q.push(state); //��ʼ״̬����� 
    d[state] = 0; //��ʼ����Ϊ0 

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; //�ı��4������ 

    string end = "12345678x"; //Ŀ��״̬ 
    while (q.size())
    {
        auto t = q.front(); 
        q.pop();

        if (t == end) return d[t]; //�ҵ���� 

        int distance = d[t]; //d[t]��ʾ�ڼ��� 
        int k = t.find('x'); //�ҵ�x����һλ 
        int x = k / 3, y = k % 3; //����k������Ŀǰ�ַ�x���±�x,y 
        for (int i = 0; i < 4; i ++ ) //4�������ķ��� 
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3) //�߽��ж� 
            {
                swap(t[a * 3 + b], t[k]); //�������γ��µ��ַ��� 
                if (!d.count(t)) //�ж��µ��ַ�����map����d���Ƿ���ֹ� 
                {
                    d[t] = distance + 1; //û���ֹ���������1�������� 
                    q.push(t);
                }
                swap(t[a * 3 + b], t[k]); //��ԭ�ַ���t 
            }
        }
    }
    return -1;
}

int main()
{
    char s[2];

    string state;
    for (int i = 0; i < 9; i ++ )
    {
        cin >> s;
        state += *s;
    }

    cout << bfs(state) << endl;

    return 0;
}
