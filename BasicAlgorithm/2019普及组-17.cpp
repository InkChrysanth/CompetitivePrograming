#include<cstdio>
using namespace std;
int n, m;
int a[100], b[100];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        a[i] = b[i] = 0;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (a[x] < y && b[y] < x) {
            if (a[x] > 0)
                b[a[x]] = 0;
            if (b[y] > 0)
                a[b[y]] = 0;
            a[x] = y;
            b[y] = x;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 0)
            ++ans;
        if (b[i] == 0)
            ++ans;
    }
    printf("%d", ans);
    return 0;
}
/*
���������n��m������������x��y�����ڣ�1, n�ݵķ�Χ�ڵ����������������ж���͵�ѡ�⣺
�ж���:
1.��m>0ʱ�������ֵһ��С��2n����true��
2.ִ�����27�е�"++ans"ʱ��ans ������ż������false��
3.a��i�ݺ�b��i�ݲ�����ͬʱ����0����false�� 
4.�ҳ���ִ�е���13��ʱ��x����С��y,��ô��15�в��ᱻִ�С���false��
ѡ����:
1.��m��x������ͬ����m��y������ͬ���������ֵΪ��2n-2m��//С��Χ����ģ�� 
2.��m��x������ͬ����m��y����ȣ��������ֵΪ��2n-2��//С��Χ����ģ�� 
*/
