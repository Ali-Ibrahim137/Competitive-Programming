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
ll dp[3030];

int main(){
	int s;
	cin>>s;
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 0;
	dp[3] = 1;
	for(int i=4;i<=s;i++){
		dp[i] = dp[i-1] + dp[i-3];
		dp[i]%=mod;
	}
	cout<<dp[s]<<endl;
}

