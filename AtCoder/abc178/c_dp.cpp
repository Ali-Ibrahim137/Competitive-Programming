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
ll dp[1000010][2][2];
int n;
ll cal(int i, int f, int ff){
	if(i==n)return f&&ff;
	ll &ret=dp[i][f][ff];
	if(ret!=-1)return ret;
	ret++;
	ret += 8*cal(i + 1, f, ff); ret%=mod;
	ret += cal(i + 1, 1, ff); ret%=mod;
	ret += cal(i + 1, f, 1); ret%=mod;
	return ret;
}
int main(){
	cin>>n;
	memset(dp,-1,sizeof dp);
	cout<<cal(0, 0, 0)<<endl;
}

