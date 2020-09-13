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
	vector<int>a(n), b(n), amid(n);
	vector<int>cnt(n + 1, 0);
	for(auto &x:a)scanf("%d", &x), cnt[x]++;
	for(auto &x:b)scanf("%d", &x), cnt[x]++;
	for(int i = 1;i<=n;i++){
		if(cnt[i]>n){
			cout<<"No"<<endl;
			return 0;
		}
	}
	reverse(all(b));
	int l = 0, r = n-1;
	for(int i=0;i<n;i++){
		if(a[i]==b[i]){
			if(b[l]!=a[i] && a[l]!=a[i]){
				swap(b[l], b[i]);
				l++;
			}else{
				swap(b[r], b[i]);
				r--;
			}
		}
	}
	cout<<"Yes"<<endl;
	for(int i=0;i<n;i++){
		assert(a[i]!=b[i]);
		cout<<b[i]<<" ";
	}
}

