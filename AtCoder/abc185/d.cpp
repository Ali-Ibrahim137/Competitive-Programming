#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define endl '\n'
#define Endl '\n'
#define fi first
#define ii pair<int,int>
#define iil pair<ll,ll>
#define se second
#define ld long double
#define mod 0
#define popcount __builtin_popcountll
#define x0 zxcxzcsacasd
#define x1 ghfghujfgfg
#define y0 olkjhdnncvcv
#define y1 bhvgrewm345345435
#define debug(x) std::cerr<<#x<<": "<<(x)<<'\n'
#define all(x) x.begin(), x.end()
using namespace std;


int main(){
	int n, m;
	cin>>n>>m;
	if(m == 0){
		cout<<1<<endl;
		return 0;
	}
	vector<int>a(m + 2);
	a[0] = 0;
	for(int i = 1; i < m + 1;i++)scanf("%d", &a[i]);
	a[m + 1] = n + 1;
	sort(all(a));
	m+=2;
	int mn = n + 1;
	for(int i = 1;i < m;i++){
		int d = a[i] - a[i - 1] - 1;
		if(d >= 1)mn = min(mn, d);
	}
	if(mn == n + 1){
		cout<<0<<endl;
		return 0;
	}
	ll ans = 0;
	for(int i = 1;i < m;i++){
		ll need = a[i] - a[i - 1] - 1;
		if(need >= 1)ans+=(need + mn - 1) / mn;
	}
	cout<<ans<<endl;
}

