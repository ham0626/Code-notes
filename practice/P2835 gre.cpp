#include<bits/stdc++.h>
using namespace std;
int n;
int timer,gro,top;
int head[205];
int dfn[205],low[205],belong[205],stk[205];
bool instk[205];
int in[205];
struct Node{
    int fro,to,nxt;
}edge[10005];
void tarjan(int u){
    dfn[u]=low[u]=++timer;
    stk[++top]=u;
    instk[u]=true;
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
            instk[x]=false;
            belong[x]=gro;
            if(x==u) break;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    int cnt=1;
    for(int i=1;i<=n;i++){
        int v;
        cin>>v;
        if(v==0) break;
        edge[cnt].fro=i,edge[cnt].to=v;
        edge[cnt].nxt=head[i];
        head[i]=cnt;
        cnt++;
    }
    for(int i=1;i<=n;i++){
        if(dfn[i]==0) tarjan(i);
    }
    for(int i=1;i<cnt;i++){
        int u=edge[cnt].fro;
        int v=edge[cnt].to;
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