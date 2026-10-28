#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,m;
int head[MAXN],dep[MAXN];
int up[MAXN][25];
struct Node{
    int fro,to,nxt;
}edge[2*MAXN];
void dfs(int u,int fa){
    dep[u]=dep[fa]+1;
    up[u][0]=fa;
    for(int i=1;i<=20;i++)
        up[u][i]=up[up[u][i-1]][i-1];
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==fa) continue;
        dfs(v,u);
    }
    return;
}
int query(int a,int b){//a深
    if(dep[a]<dep[b]) swap(a,b);
    for(int i=20;i>=0;i--){
        int v=up[a][i];
        if(dep[v]>=dep[b])
            a=v;
    }
    if(a==b) return a;
    for(int i=20;i>=0;i--){
        if(up[a][i]!=up[b][i])
            a=up[a][i],b=up[b][i];
    }
    return up[a][0];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int cnt=1;
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;
        edge[cnt].fro=a,edge[cnt].to=b;
        edge[cnt].nxt=head[a];
        head[a]=cnt;
        cnt++;
        edge[cnt].fro=b,edge[cnt].to=a;
        edge[cnt].nxt=head[b];
        head[b]=cnt;
        cnt++;
    }
    dfs(1,0);
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        int num;
        int ans1=query(x,y);//ans是节点
        int dans1=dep[ans1];//求深度
        int ans2=query(y,z);
        int dans2=dep[ans2];
        int ans3=query(x,z);
        int dans3=dep[ans3];
        int maxn=max({dans1,dans2,dans3});//最大深度
        if(maxn==dans1) num=ans1;
        else if(maxn==dans2) num=ans2;
        else num=ans3;//找节点
        //在树上,距离不等于深度差
        //dist(u,v)=dep[u]+dep[v]-2*dep[lca(u,v)]
        cout<<num<<" "<<abs(dep[x]+dep[y]+dep[z]-dep[ans1]-dep[ans2]-dep[ans3])<<'\n';
    }
    return 0;
}