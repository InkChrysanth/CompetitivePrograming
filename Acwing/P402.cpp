// Problem: 杀人游戏
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/404/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
using pli=pair<ll, int>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=100010;

vector<int> g[N];

int n, m, deg[N];
int dfn[N], low[N], dn=0;
int stk[N], top=0;
int c[N], sz[N], scc_cnt=0;
bool ins[N];


void tarjan(int u)
{
	dfn[u]=low[u]=++dn;
	stk[++top]=u, ins[u]=1;
	each(v, g[u])
	{
		if(!dfn[v]) tarjan(v), cmin(low[u], low[v]);
		else if(ins[v]) cmin(low[u], dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		scc_cnt++;
		int t;
		do
		{
			t=stk[top--], ins[t]=0;
			c[t]=scc_cnt, sz[scc_cnt]++;
		}while(t!=u);
	}
}

signed main()
{
	cout<<fixed<<setprecision(6);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1, u, v; i<=m; i++)
	{
		cin>>u>>v;
		g[u].eb(v);
	}
	for(int i=1; i<=n; i++)
		if(!dfn[i])
			tarjan(i);
	vector<vector<int>> G(scc_cnt+1, vector<int>());
	
	set<pii> edges;
	for(int u=1; u<=n; u++)
	{
		each(v, g[u])
		{
			int a=c[u], b=c[v];
			if(a==b || edges.count(mp(a, b))) continue;
			edges.insert(mp(a, b));
			G[a].eb(b);
			deg[b]++;
		}
	}
	int cnt=0;
	for(int i=1; i<=scc_cnt; i++)
		if(!deg[i]) cnt++;
	auto check=[&](int u)
	{
		if(deg[u]!=0 || sz[u]!=1) return 0;
		each(v, G[u])
			if(deg[v]<2)
				return 0;
		return 1;
	};
	for(int i=1; i<=scc_cnt; i++)
		if(check(i))
		{
			cnt--;
			break;
		}
	cout<<((double)(n-cnt)/n)<<endl;
	return 0;
}