#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,q;
int head[MAXN],dep[MAXN],dis[MAXN],up[MAXN][25];
struct Node{
    int fro,to,nxt,val;
}edge[2*MAXN];
void dfs(int u,int fa,int val){
    dep[u]=dep[fa]+1;
    dis[u]=dis[fa]^val;//记录边权
    up[u][0]=fa;
    for(int i=1;i<=24;i++)
        up[u][i]=up[up[u][i-1]][i-1];
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        int w=edge[i].val;
        if(v==fa) continue;
        dfs(v,u,w);
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    int cnt=1;
    for(int i=1;i<=n-1;i++){
        int a,b,l;
        cin>>a>>b>>l;
        edge[cnt].fro=a,edge[cnt].to=b,edge[cnt].val=l;
        edge[cnt].nxt=head[a];
        head[a]=cnt;
        cnt++;
        edge[cnt].fro=b,edge[cnt].to=a,edge[cnt].val=l;
        edge[cnt].nxt=head[b];
        head[b]=cnt;
        cnt++;
    }
    dfs(1,0,0);
    cin>>q;
    for(int i=1;i<=q;i++){
        int a,b;
        cin>>a>>b;
        cout<<(dis[a]^dis[b])<<'\n';
    }
    return 0;
}