#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define endl '\n'
#define Endl '\n'
#define fi first
#define ii pair<int,int>
#define iil pair<ll,ll>
#define iii pair<pair<int, int>, int >
#define iiil pair<pair<ll, ll>, ll >
#define se second
#define ld long double
#define mod 1000000007
#define popcount __builtin_popcountll
#define x0 zxcxzcsacasd
#define x1 ghfghujfgfg
#define y0 olkjhdnncvcv
#define y1 bhvgrewm345345435
using namespace std;
multiset<ll>ms[5];
void add(ll x, ll y){
    ms[1].insert(x + y);
    ms[2].insert(-x + y);
    ms[3].insert(-x - y);
    ms[4].insert(x - y);
}

ll query(ll x, ll y){
    if(ms[1].empty())return -1;
    ll ret = 0;
    ret = max(ret, *ms[1].rbegin() + (-x - y));
    ret = max(ret, *ms[2].rbegin() + (x - y));
    ret = max(ret, *ms[3].rbegin() + (x + y));
    ret = max(ret, *ms[4].rbegin() + (-x + y));
    return ret;
}
ll a[1<<20];
ll b[1<<20];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%lld%lld", &a[i], &b[i]);
		add(a[i], b[i]);
	}
	ll ans = 0;
	for(int i=0;i<n;i++){
		ans = max(ans, query(a[i], b[i]));
		add(a[i], b[i]);
	}
	cout<<ans<<endl;
}

