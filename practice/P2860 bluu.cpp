#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e3+5;
int f,r;
int timer,top,gro;
int dfn[MAXN],low[MAXN],belong[MAXN],stk[MAXN];
int head[MAXN];
bool instk[MAXN];
int out[MAXN];//找叶子节点
struct Node{
    int fro,to,nxt;
}edge[20005];
void tarjan(int u,int num){//传入父子之间的边
    dfn[u]=low[u]=++timer;
    stk[++top]=u;
    instk[u]=true;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(i==(num^1))  continue;//反边
        if(dfn[v]==0){
            tarjan(v,i);
            low[u]=min(low[u],low[v]);
        }
        else low[u]=min(low[u],dfn[v]);
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
    cin>>f>>r;
    int cnt=2;
    for(int i=1;i<=r;i++){
        int u,v;
        cin>>u>>v;
        edge[cnt].fro=u,edge[cnt].to=v;
        edge[cnt].nxt=head[u];
        head[u]=cnt;
        cnt++;
        edge[cnt].fro=v,edge[cnt].to=u;
        edge[cnt].nxt=head[v];
        head[v]=cnt;
        cnt++;
    }
    for(int i=1;i<=f;i++){
        if(dfn[i]==0) tarjan(i,0);
    }
    for(int i=2;i<=2+2*r;i+=2){
        int u=edge[i].fro;
        int v=edge[i].to;
        if(belong[u]!=belong[v]){
            out[belong[u]]++,out[belong[v]]++;
        }
    }
    int ans=0;
    for(int i=1;i<=gro;i++){
        if(out[i]==1) ans++;
    }
    ans=(ans+1)/2;
    cout<<ans;
    return 0;
}