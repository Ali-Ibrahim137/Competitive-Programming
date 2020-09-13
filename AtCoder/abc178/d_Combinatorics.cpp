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
ll C[1010][3030];
ll fac[6060];
ll inv[6060];
ll p(ll a, ll b){
	if(b==0)return 1;
	ll r = p(a, b/2);
	r*=r;
	r%=mod;
	if(b%2)r*=a;
	return r%mod;
}
ll get(int a, int b){
	ll ret = fac[a];
	ret*=inv[b];
	ret%=mod;
	ret*=inv[a-b];
	ret%=mod;
	return ret;
}
int main(){
	fac[0] = 1;
	inv[0] = 1;
	for(ll i=1;i<6060;i++){
		fac[i] = fac[i-1] * i;
		fac[i]%=mod;
		inv[i] = p(fac[i], mod - 2);
	}
	ll ans = 0;
	int s;
	cin>>s;
	for(int i = 1;i<=1000;i++){
		int r = s - 3 * i;
		if(r < 0)break;
		ans+=get(s - 2*i - 1, i-1);
		ans%=mod;
	}
	cout<<ans<<endl;
}

