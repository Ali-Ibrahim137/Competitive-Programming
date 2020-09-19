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
void test_case(){
	
}
int main(){
	ll n, x, m;
	cin>>n>>x>>m;
	ll ans = x;
	map<int, int>id;
	vector<int>v;
	v.pb(x);
	ll rem = n - 1;
	for(int i=1;i<n;i++){
		ll a = v[i-1];
		id[a] = i - 1;
		a*=a;
		a = a%m;
		if(id.count(a)){
			int len = 0;
			ll sum = 0;
			int l = v.size();
			for(int j = id[a];j<l;j++){
				sum+=v[j];
				len++;
			}
			ll c = rem / len;
			ans+=c * sum;
			rem%=len;
			for(int j = id[a];rem;j++, rem--){
				ans+=v[j];
			}
			break;
		}
		rem--;
		ans+=a;
		v.pb(a);
	}
	cout<<ans<<endl;
}
