//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define all(x) x.begin(), x.end()
#define each(i,x) for(auto &i:(x))
#define sz(x) int((x).size())
#define fi first
#define se second
#define endl '\n'
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int MOD=998244353;

int qmi(int a, int k)
{
    int res=1;
    while(k)
    {
        if(k&1) res=(ll)res*a%MOD;
        a=(ll)a*a%MOD;
        k>>=1;
    }
    return res;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
    cin>>n>>m;
    cout<<(((n&1)?qmi(m-1, n)-m+1:qmi(m-1, n)+m-1)+MOD)%MOD<<endl;
	return 0;
}
