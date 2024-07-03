#include <bits/stdc++.h>
#define int int64_t
using namespace std;
constexpr int N = 1e5+5;
vector<int> adj[N],color(N,0);
//0 for none,1 for red,2 for blue
bool dfs(int cur,int c){
    if(color[cur])return (color[cur] == c);
    color[cur] = c;
    for(int &u : adj[cur]){
        bool valid = dfs(u,3-c);
        if(!valid)return false;
    }
    return true;
}
int32_t main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    for(int i=1;i<=n;i++){
        if(color[i]!=0)continue;
        if(!dfs(i,1)){
            cout << "NO'\n";
            return 0;
        }
    }
    cout << "YES\n";
}
