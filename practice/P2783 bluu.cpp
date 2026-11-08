#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+5;
int n,m,tot,gro;
int timer,top;
int head[MAXN],head2[MAXN];
int dfn[MAXN],low[MAXN],belong[MAXN];
int dep[MAXN],up[MAXN][25];
static bitset<MAXN> used[MAXN];;//防止重边
bool vis[MAXN],bri[10*MAXN];//第一遍tarjan只标割边(bri)
//点和边都只能属于一个边双->点双/边双要在验证dfn==0的情况压入栈
//点双可以共割点 边双不能共享边和点
struct Node{
    int fro,to,nxt;
}edge[10*MAXN];
struct Node2{
    int fro,to,nxt;
}edge2[10*MAXN];
void tarjan(int u,int fa){
    dfn[u]=low[u]=++timer;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(i==(fa^1)) continue;//处理回边
        if(dfn[v]==0){
            tarjan(v,i);//传父边编号
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]){
                bri[i]=true;
                bri[i^1]=true;
            }
        }
        else{
            if(dfn[v]<dfn[u])//避免重复//*
            low[u]=min(low[u],dfn[v]);
        }
    }
    return;
}
void dfs(int u){
    vis[u]=true;//只能属于一个边双
    belong[u]=gro;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(bri[i]==true) continue;//割边跳过
        if(vis[v]==true) continue;//属于其他边双了
        dfs(v);
    }
}
void pre_LCA(int u,int fa){
    dep[u]=dep[fa]+1;
    up[u][0]=fa;
    for(int i=1;i<=20;i++)
        up[u][i]=up[up[u][i-1]][i-1];
    for(int i=head2[u];i;i=edge2[i].nxt){
        int v=edge2[i].to;
        if(v==fa) continue;
        pre_LCA(v,u);
    }
    return;
}
int LCA(int a,int b){
    if(a==b) return a;
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
string bina(int x){//转二进制模板
    if(x==0) return "0";
    string res="";//初始化
    while(x>0){
        res+=(x%2)+'0';
        x/=2;
    }
    reverse(res.begin(),res.end());
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int cnt=2;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        if(used[u][v]==1) continue;
        used[u][v]=used[v][u]=1;
        edge[cnt].fro=u,edge[cnt].to=v;
        edge[cnt].nxt=head[u];
        head[u]=cnt;
        cnt++;
        edge[cnt].fro=v,edge[cnt].to=u;
        edge[cnt].nxt=head[v];
        head[v]=cnt;
        cnt++;
    }
    for(int i=1;i<=n;i++){
        if(dfn[i]==0)
        tarjan(i,0);
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            gro++;
            dfs(i);
        }
    }
    int lin=1;
    for(int i=2;i<cnt;i+=2){//建新图跑LCA
        int u=edge[i].fro;
        int v=edge[i].to;
        if(belong[u]!=belong[v]){
            u=belong[u];
            v=belong[v];
            edge2[lin].fro=u,edge2[lin].to=v;
            edge2[lin].nxt=head2[u];
            head2[u]=lin;
            lin++;
            edge2[lin].fro=v,edge2[lin].to=u;
            edge2[lin].nxt=head2[v];
            head2[v]=lin;
            lin++;
        }
    }
    for(int i=1;i<=gro;i++){
        if(dep[i]==0) pre_LCA(i,0);
    }
    cin>>tot;
    for(int i=1;i<=tot;i++){
        int a,b;
        cin>>a>>b;
        a=belong[a];
        b=belong[b];
        int l=LCA(a,b);
        int dis=dep[a]+dep[b]-2*dep[l];//边数
        if(l==0) cout<<"0"<<'\n';
        else if(a==b) cout<<"1"<<'\n';
        else cout<<bina(dis+1)<<'\n';
    }
    return 0;
}