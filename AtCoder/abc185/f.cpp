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

int n, q;
int a[300030];
int tree[1 << 21];
void build(int pos, int l, int r){
	if(l == r){
		tree[pos] = a[l];
		return;
	}
	int md = (l + r) / 2;
	build(2 * pos, l, md);
	build(2 * pos + 1, md + 1, r);
	tree[pos] = (tree[2 * pos] ^ tree[2 * pos + 1]);
}
void update(int pos, int l, int r, int tar, int val){
	if(l == r && l == tar){
		tree[pos] = val;
		return;
	}
	int md = (l + r) / 2;
	if(tar >= l && tar <= md)update(2 * pos, l, md, tar, val);
	else update(2 * pos + 1, md + 1, r, tar, val);
	tree[pos] = (tree[2 * pos] ^ tree[2 * pos + 1]);
}
int query(int pos, int l, int r, int st, int en){
	if(l > en || r < st)return 0;
	if(st <= l && en >= r){
		return tree[pos];
	}
	int md = (l + r) / 2;
	int x = query(2 * pos, l, md, st, en);
	int y = query(2 * pos + 1, md + 1, r, st, en);
	return (x ^ y);
}
int main(){
	cin >> n >> q;
	for(int i = 1 ; i <= n;i++)scanf("%d", &a[i]);
	build(1, 1, n);
	while(q--){
		int ty, x, y;
		scanf("%d%d%d", &ty, &x, &y);
		if(ty == 1){
			a[x] = (a[x] ^ y);
			update(1, 1, n, x, a[x]);
		}
		else cout<<query(1, 1, n, x, y)<<Endl;
	}
}

