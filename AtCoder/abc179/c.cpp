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

int main(){
	int n;
	cin>>n;
	int ans = 0;
	for(int a = 1; a <= n; a++){
		for(int b = 1; b <= n; b++){
			int c = n - a * b;
			if(c>0)ans++;
			else break;
		}
	}
	cout<<ans<<endl;
}
