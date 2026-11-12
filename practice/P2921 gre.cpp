#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int n;
int timer,top,gro;
int head[MAXN],head2[MAXN];
int dfn[MAXN],low[MAXN],belong[MAXN],stk[MAXN];
bool instk[MAXN];
int dp[MAXN],siz[MAXN],in[MAXN];//入度找环
struct Node{
    int fro,to,nxt;
}edge[MAXN];
struct Node2{
    int fro,to,nxt;
}edge2[MAXN];
void tarjan(int u){
    dfn[u]=low[u]=++timer;
    instk[u]=true;
    stk[++top]=u;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(dfn[v]==0){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instk[v]==true)
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        gro++;
        while(true){
            int x=stk[top--];
            siz[gro]++;
            belong[x]=gro;
            instk[x]=false;
            if(x==u) break;
        }
    }
    return;
}
void dfs(int u){
    for(int i=head2[u];i;i=edge2[i].nxt){
        int v=edge2[i].to;
        dp[v]=dp[u]+siz[v];
        dfs(v);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int v;
        cin>>v;
        edge[i].fro=i,edge[i].to=v;
        edge[i].nxt=head[i];
        head[i]=i;
    }
    for(int i=1;i<=n;i++){
        if(dfn[i]==0) tarjan(i);
    }
    //确保环与环之间不连通 然后环指向单点 不然会绕进环里
    //把判断放到dfs前面
    int cnt=1;
    for(int i=1;i<=n;i++){
        int u=edge[i].fro;
        int v=edge[i].to;
        if(belong[u]!=belong[v]){
            u=belong[u];
            v=belong[v];
            edge2[cnt].fro=v,edge2[cnt].to=u;
            edge2[cnt].nxt=head2[v];
            head2[v]=cnt;
            cnt++;
            in[u]++;//建反图
        }
    }
    for(int i=1;i<=gro;i++){
        dp[i]=siz[i];
    }
    for(int i=1;i<=gro;i++){
        if(in[i]==0)//从环开始搜
        dfs(i);
    }
    for(int i=1;i<=n;i++)
        cout<<dp[belong[i]]<<'\n';
    return 0;
}