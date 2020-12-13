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

int n, m;
vector<int>a, b;
int dp[1002][1002];
int cal(int i, int j){
	if(i == n || j == m){
		return (n - i) + (m - j);
	}
	int &ret = dp[i][j];
	if(ret != -1)return ret;
	ret = 1000000;
	if(a[i] == b[j])ret = cal(i + 1, j + 1);
	ret = min(ret, 1 + cal(i + 1, j));
	ret = min(ret, 1 + cal(i, j + 1));
	ret = min(ret, 1 + cal(i + 1, j + 1));
	return ret;
}
int main(){
	cin >> n >> m;
	a.resize(n);
	b.resize(m);
	for(auto &x:a)scanf("%d", &x);
	for(auto &x:b)scanf("%d", &x);
	memset(dp, -1, sizeof dp);
	cout<<cal(0, 0)<<endl;
}

