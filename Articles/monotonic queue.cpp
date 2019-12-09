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

deque<int>dq;
void add(int val){
    while(!dq.empty() && dq.back()>=val){
        dq.pop_back();
    }
    dq.push_back(val);
}
void del(int val){
    if(!dq.empty() && dq.front()==val)dq.pop_front();
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
            add(h[i][j]);
        }
        int c = 1;
        temp[i][c++] = dq.front();
        for(int j=b+1;j<=m;j++){
            del(h[i][j-b]);
            add(h[i][j]);
            temp[i][c++] = dq.front();
        }
    }
    init();
    for(int j=1;j<=(m-b+1);j++){
        init();
        for(int i=1;i<=a;i++){
            add(temp[i][j]);
        }
        ans+=dq.front();
        for(int i=a+1;i<=n;i++){
            del(temp[i-a][j]);
            add(temp[i][j]);
            ans+=dq.front();
        }
    }
    return ans;
}
void gen(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int idx = (i-1)*m + j - 1;
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
