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
ll l;
ll dp[202][12];
ll cal(int i, int c){
	if(i == l)return 0;
	if(c == 11)return 1;
	ll &ret = dp[i][c];
	if(ret!=-1)return ret;
	ret = 0;
	ret  = cal(i + 1, c);
	ret += cal(i + 1, c + 1);
	return ret;
}

int main(){
	cin>>l;
	memset(dp, -1, sizeof dp);
	cout<<cal(0, 0)<<endl;

}

