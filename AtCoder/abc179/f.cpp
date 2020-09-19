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
int n, q;
struct Segment_tree{
	int tree[1<<20];
	int lazy[1<<20];
	void build(int pos, int l, int r){
		if(l == r){
			tree[pos] = 1;
			return;
		}
		int md = (l + r)/2;
		build(2*pos, l, md);
		build(2*pos + 1, md + 1, r);
		tree[pos] = 1;
	}
	void push(int pos, int l, int r){
		if(lazy[pos]==0)return;
		tree[pos] = max(tree[pos], lazy[pos]);
		if(l!=r){
			lazy[2 * pos] = max(lazy[2 * pos], lazy[pos]);
			lazy[2 * pos + 1] = max(lazy[2 * pos + 1], lazy[pos]);
		}
		lazy[pos] = 0;
	}
	void update(int pos, int l, int r, int s, int e, int v){
		if(l > e || s > r)return;
		push(pos, l, r);
		if(l >= s && r <= e){
			tree[pos] = max(tree[pos], v);
			if(l!=r){
				lazy[2 * pos] = max(lazy[2 * pos], v);
				lazy[2 * pos + 1] = max(lazy[2 * pos + 1], v);
			}
			return;
		}
		int md = (l + r)/2;
		update(2*pos, l, md, s, e, v);
		update(2*pos + 1, md + 1, r, s, e, v);
		tree[pos] = max(tree[2*pos], tree[2*pos + 1]);
	}
	int query(int pos, int l, int r, int tar){
		push(pos, l, r);
		if(l == r && l == tar){
			return tree[pos];
		}
		int md = (l + r)/2;
		if(tar >= l && tar <= md)return query(2 * pos, l, md, tar);
		else return query(2 * pos + 1, md + 1, r, tar);
	}
}Xs, Ys;
int main(){
	scanf("%d%d", &n, &q);
	ll black = 1ll * (n - 2) * (n - 2);
	Xs.build(1, 1, n);
	Ys.build(1, 1, n);
	while(q--){
		int t, x;
		scanf("%d%d", &t, &x);
		// x = n - x + 1;
		if(t == 1){
			int idx = Ys.query(1, 1, n, x);
			debug(idx);
			int diff = n - idx - 1;
			debug(diff);
			black-=diff;
			debug(black);
			Xs.update(1, 1, n, 1, idx, x);
			continue;
		}
		int idx = Xs.query(1, 1, n, x);
		debug(idx);
		int diff = n - idx - 1;
		debug(diff);
		black-=diff;
		debug(black);
		Ys.update(1, 1, n, 1, idx, x);
	}
	cout<<black<<endl;
}
