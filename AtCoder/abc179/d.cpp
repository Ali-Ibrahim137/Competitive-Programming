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
#define mod 998244353
#define popcount __builtin_popcountll
#define x0 zxcxzcsacasd
#define x1 ghfghujfgfg
#define y0 olkjhdnncvcv
#define y1 bhvgrewm345345435
#define debug(x) std::cerr<<#x<<": "<<(x)<<'\n'
#define all(x) x.begin(), x.end()
using namespace std;
int n, k;
ll tree[1600010];
ll lazy[1600010];
void push(int pos, int l, int r){
	if(lazy[pos]==0)return;
	tree[pos] += lazy[pos]; // Update it
	tree[pos]%=mod;
	if(l != r) {
		lazy[pos*2] += lazy[pos]; // Mark child as lazy
		lazy[pos*2+1] += lazy[pos]; // Mark child as lazy
		lazy[2*pos]%=mod;
		lazy[2*pos + 1]%=mod;
	}
	lazy[pos] = 0;
}
void update(int pos, int l, int r, int st, int en, int v){
	if(l > en || st > r)return;
	push(pos, l, r);
	if(l>=st && r<=en){
		tree[pos]+=v;
		tree[pos]%=mod;
		if(l!=r){
			lazy[2*pos]+=v;
			lazy[2*pos + 1]+=v;
			lazy[2*pos]%=mod;
			lazy[2*pos + 1]%=mod;
		}
		return;
	}
	int md = (l+r)/2;
	update(2*pos, l, md, st, en, v);
	update(2*pos+1, md+1, r, st, en, v);
}
ll query(int pos, int l, int r, int tar){
	push(pos, l, r);
	if(l==r && l==tar)return tree[pos];
	int md = (l+r)/2;
	if(tar>=l && tar<=md)return query(2*pos, l, md, tar);
	return query(2*pos+1, md+1, r, tar);
}

int main(){
	scanf("%d%d", &n, &k);
	vector<ii>segs(k);
	for(int i=0;i<k;i++){
		int l, r;
		scanf("%d%d", &l, &r);
		segs[i] = {l, r};
	}
	update(1, 1, 2*n, 1 , 1, 1);
	for(int i=1;i<=n;i++){
		for(auto s:segs){
			int l = s.fi, r = s.se;
			ll value = query(1, 1, 2 * n, i);
			value%=mod;
			update(1, 1, 2 * n, i + l, i + r, value);
		}
	}
	cout<<query(1, 1, 2 * n, n)%mod<<endl;
}
