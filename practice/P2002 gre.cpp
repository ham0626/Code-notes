#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,m;
int timer,top,gro;
int head[MAXN];
int dfn[MAXN],low[MAXN],belong[MAXN],stk[MAXN];
bool instk[MAXN];
int in[MAXN];
//点和边都只能属于一个边双->点双/边双要在验证dfn==0的情况压入栈
struct Node{
    int fro,to,nxt;
}edge[5*MAXN];
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
            belong[x]=gro;
            instk[x]=false;
            if(x==u) break;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int cnt=1;
    for(int i=1;i<=m;i++){
        int b,e;
        cin>>b>>e;
        edge[cnt].fro=b,edge[cnt].to=e;
        edge[cnt].nxt=head[b];
        head[b]=cnt;
        cnt++;
    }
    for(int i=1;i<=n;i++){
        if(dfn[i]==0) tarjan(i);
    }
    for(int i=1;i<cnt;i++){
        int u=edge[i].fro;
        int v=edge[i].to;
        if(belong[u]!=belong[v])
            in[belong[v]]++;
    }
    int ans=0;
    for(int i=1;i<=gro;i++){
        if(in[i]==0) ans++;
    }
    cout<<ans;
    return 0;
}