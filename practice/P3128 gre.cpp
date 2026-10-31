#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e4+5;
int n,k;
long long maxn=0;
struct Node{
    int fro,to,nxt;
}edge[2*MAXN];
long long head[MAXN],dep[MAXN],up[MAXN][25],diff[MAXN];
void dfs(int u,int fa){//LCA预处理
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
int LCA(int a,int b){
    if(dep[a]<dep[b]) swap(a,b);//a更深
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
void add(int u,int fa){
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==fa) continue;
        add(v,u);
        diff[u]+=diff[v];
    }
    maxn=max(maxn,diff[u]);
    return;
}
//树上差分=tree[u]-tree[2*u]-tree[2*u+1]
//差分数组修改起点终点
//但是记数时需要计算某一边到lca的长度
//lca也要处理
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    int cnt=1;
    for(int i=1;i<=n-1;i++){
        int x,y;
        cin>>x>>y;
        edge[cnt].fro=x,edge[cnt].to=y;
        edge[cnt].nxt=head[x];
        head[x]=cnt;
        cnt++;
        edge[cnt].fro=y,edge[cnt].to=x;
        edge[cnt].nxt=head[y];
        head[y]=cnt;
        cnt++;
    }
    dfs(1,0);
    for(int i=1;i<=k;i++){
        int s,t;
        cin>>s>>t;
        int l=LCA(s,t);
        diff[s]++;
        diff[t]++;
        diff[l]--;//减去多算的1
        diff[up[l][0]]--;//l可能只是途径,减去l对其父节点的影响
    }
    add(1,0);
    cout<<maxn;
    return 0;
}