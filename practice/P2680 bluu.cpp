#include<bits/stdc++.h>
using namespace std;
const int MAXN=3e5+5;
int n,m;
int exceed,maxx;//超过的边数,公共边最大边权
int head[MAXN],fa[MAXN],up[MAXN][30],dep[MAXN],dis[MAXN];
int diff[MAXN],tofa[MAXN];
bool enemy[MAXN];
int dfn[MAXN], idx = 0;
struct Node{
    int fro,to,nxt,val;
}edge[2*MAXN];
struct Tran{
    int fro,to,lca,len;
}tran[MAXN];
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}//抄一个快读板子
void dfs(int u,int fa){
        dfn[++idx] = u;
    dep[u]=dep[fa]+1;
    up[u][0]=fa;
    for(int i=1;i<21;i++)
        up[u][i]=up[up[u][i-1]][i-1];
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==fa) continue;
        tofa[v]=edge[i].val;
        dis[v]=dis[u]+edge[i].val;
        dfs(v,u);
    }
    return;
}
int LCA(int a,int b){
    if(dep[a]<dep[b]) swap(a,b);
    for(int i=20;i>=0;i--){
        int v=up[a][i];
        if(dep[v]>=dep[b]) 
        a=v;
    }
    if(a==b) return b;
    for(int i=20;i>=0;i--){
        if(up[a][i]!=up[b][i])
        a=up[a][i],b=up[b][i];
    }
    return up[a][0];
}
bool check(int lim){
    memset(diff,0,sizeof(int)*(n+1)); 
    exceed=0,maxx=0;
    int longest=0;//最大边权和
    for(int i=1;i<=m;i++){
        if(tran[i].len>lim){
            exceed++;//条数多一条
            longest=max(longest,tran[i].len);
            diff[tran[i].fro]++;
            diff[tran[i].to]++;//diff记录走了多少次
            diff[tran[i].lca]-=2;
        }
    }
    if(exceed==0) return true;
    for(int i = idx; i >= 1; i--){
        int u = dfn[i];
        if(diff[u] == exceed) {
            maxx = max(maxx, tofa[u]);
        }
        diff[up[u][0]] += diff[u];
    }
    
    if(longest - maxx <= lim) return true;
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    n=read(),m=read();
    int cnt=1;
    for(int i=1;i<=n-1;i++){
        int a,b,t;
        a=read(),b=read(),t=read();
        edge[cnt].fro=a,edge[cnt].to=b,edge[cnt].val=t;
        edge[cnt].nxt=head[a];
        head[a]=cnt;
        cnt++;
        edge[cnt].fro=b,edge[cnt].to=a,edge[cnt].val=t;
        edge[cnt].nxt=head[b];
        head[b]=cnt;
        cnt++;
    }//先遍历边 预处理长度
    dfs(1,0);
    int lin=1;
    int maxlen=0;
    for(int i=1;i<=m;i++){
        int u,v;
        u=read(),v=read();
        tran[lin].fro=u,tran[lin].to=v;
        tran[lin].lca=LCA(u,v);
        tran[lin].len=dis[u]+dis[v]-2*dis[tran[lin].lca];
        lin++;
        maxlen=max(maxlen,tran[i].len);
    }
    int l=0,r=maxlen;
    int ans=0x3f3f3f3f;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=min(ans,mid);
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans;
    return 0;
}