#include<bits/stdc++.h>
using namespace std;
int n,k;
int match[510];//下标是行
int head[510];
bool vis[510];//下标是列
vector<int> planet[510];//下标是列
struct Node{
    int fro,to,nxt;
}edge[250005];
bool dfs(int u){
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(vis[v]==true) continue;
        vis[v]=true;
        if(match[v]==0||dfs(match[v])==true){
            match[v]=u;
            return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    int cnt=1;
    for(int i=1;i<=k;i++){//左:行 右:列
        int u,v;
        cin>>u>>v;
        edge[cnt].fro=u,edge[cnt].to=v;
        edge[cnt].nxt=head[u];
        head[u]=cnt;
        cnt++;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i)==true) ans++;
    }
    cout<<ans;
    return 0;
}