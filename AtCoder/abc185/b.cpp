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
	ll n, m , rem, pos = 0;
	cin >> n >> m >> rem;
	ll mx = n;
	for(int i = 0; i < m;i++){
		ll a, b;
		cin >> a >> b;
		n-=(a - pos);
		if(n <= 0){
			puts("No");
			return 0;
		}
		n += (b - a);
		n = min(n, mx);
		pos = b;
	}
	n-=(rem - pos);
	if(n <= 0){
		puts("No");
		return 0;
	}
	puts("Yes");
}

