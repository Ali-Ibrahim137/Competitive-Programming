// #include "testlib.h"
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define endl '\n'
#define Endl '\n'
#define fi first
#define ii pair<ll,ll>
#define se second
#define double long double
#define mod 1000000007
#define popcount __builtin_popcountll
const double PI = acos(-1.0);
using namespace std;
#define MXN 3005
int n, m, a, b ;
int h[MXN][MXN];
ll temp[MXN][MXN];
ll g0, x, y, z;

deque<ii>dq;
void add(int val, int idx){
    while(!dq.empty() && dq.back().first>=val){
        dq.pop_back();
    }
    dq.push_back({val, idx});
}
void del(int idx){
    if(!dq.empty() && dq.front().second==idx)dq.pop_front();
}
ll ans;
void init(){
    while(!dq.empty())dq.pop_front();
    return;
}

ll solve(){
    for(int i=1;i<=n;i++){
        init();
        for(int j=1;j<=b;j++){
            add(h[i][j], i);
        }
        int c = 1;
        temp[i][c++] = dq.front().first;
        for(int j=b+1;j<=m;j++){
            del(i-b);
            add(h[i][j], j);
            temp[i][c++] = dq.front().first;
        }
    }
    init();
    for(int j=1;j<=(m-b+1);j++){
        init();
        for(int i=1;i<=a;i++){
            add(temp[i][j], i);
        }
        ans+=dq.front().first;
        for(int i=a+1;i<=n;i++){
            del(i-a);
            add(temp[i][j], i);
            ans+=dq.front().first;
        }
    }
    return ans;
}
void gen(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            h[i][j] = g0;
            g0 = g0*x + y;
            g0%=z;
        }
    }
}
int main(){
    cin>>n>>m>>a>>b;
    cin>>g0>>x>>y>>z;
    gen();
    cout<<solve()<<endl;
}
