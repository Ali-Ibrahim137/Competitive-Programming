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
#define mod 1000000007
#define popcount __builtin_popcountll
#define x0 zxcxzcsacasd
#define x1 ghfghujfgfg
#define y0 olkjhdnncvcv
#define y1 bhvgrewm345345435
#define debug(x) std::cerr<<#x<<": "<<(x)<<'\n'
#define all(x) x.begin(), x.end()
using namespace std;
ll p(ll a, ll b){
	if(b==0)return 1;
	ll ret=p(a, b/2);
	ret*=ret;
	ret%=mod;
	if(b%2)ret*=a;
	return ret%mod;
}
int main(){
	int n;
	cin>>n;
	ll ans = p(10, n);
	ans-=2*p(9, n);
	ans%=mod;
	if(ans<0)ans+=mod;
	ans+=p(8, n);
	ans%=mod;
	cout<<ans<<endl;
}

