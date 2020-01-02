// amiD
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define endl '\n'
#define Endl '\n'
#define fi first
#define ii pair<ll,ll>
#define se second
#define ld long double
#define mod 1000000007
#define popcount __builtin_popcountll
#define PI acos(-1.0)
#define MX 555
using namespace std;
vector<int>graph[MX];
int match[MX];
bool vis[MX];
int n, m;

bool dfs(int node){
	if(vis[node])return 0;
	vis[node] = 1;
	for(auto nx:graph[node]){
		if(match[nx]==-1 || dfs(match[nx])){
			match[node] = nx;
			match[nx] = node;
			return 1;
		}
	}
	return 0;
}
void cal(int node){
    if(vis[node])return;
    vis[node] = 1;
    if(node>n){     // node from the right side, can only traverse matched edge
        cal(match[node]);
        return;
    }
    for(auto nx:graph[node]){
        if(nx==match[node])continue;
        cal(nx);
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d", &k);
        for(int j=0;j<k;j++){
            char c;
            scanf(" %c", &c);
            int idx = (c-'A') + n + 1;
            graph[i].pb(n+c-'A' + 1);
            graph[n+c-'A' + 1].pb(i);
        }
    }
    memset(match, -1, sizeof match);
    while(1){
        memset(vis, 0, sizeof vis);
        bool cont = 0;
        for(int i=1;i<=n;i++){
            if(match[i]==-1)cont|=dfs(i);
        }
        if(cont==0)break;
    }
    memset(vis,0,sizeof vis);
    for(int i=1;i<=n;i++){
        if(match[i]!=-1)continue;       // matched node from the left side
        cal(i);
    }
    vector<int>mvc, MaxIS;
    for(int i=1;i<=n;i++){
        // Left side nodes
        // Visited nodes are part of the mvc
        // Unvisited nodes are part of the MaxIS
        if(vis[i])MaxIS.pb(i);
        else mvc.pb(i);
    }
    for(int i=n+1;i<=n+m;i++){
        // Right side nodes
        // Visited nodes are part of the MaxIS
        // Unvisited nodes are part of the mvc
        if(!vis[i])MaxIS.pb(i);
        else mvc.pb(i);
    }
    cout<<"MVC nodes:\n";
    for(auto x:mvc){
        if(x<=n)cout<<x<<" ";
        else cout<<char(x-n+'A'-1)<<" ";
    }
    cout<<endl;
    cout<<"MaxIS nodes:\n";
    for(auto x:MaxIS){
        if(x<=n)cout<<x<<" ";
        else cout<<char(x-n+'A'-1)<<" ";
    }
}
/*
4 5
2 A B
3 A C E
1 D
1 D
*/

