#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4;
int n,m,top=0,gro=0,timer=0;
int low[MAXN],dfn[MAXN],head[MAXN];
int stk[MAXN];
bool instk[MAXN];
int belong[MAXN],siz[MAXN];
int son[MAXN];//统计出度
struct Node{
    int fro,to,nxt;
}edge[50005];
void tarjan(int u){
    low[u]=dfn[u]=++timer;
    instk[u]=true;
    stk[++top]=u;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(dfn[v]==0){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instk[v]==true)
            low[u]=min(low[u],dfn[v]);//已经搜过
        else continue;
    }
    if(dfn[u]==low[u]){
        gro++;
        while(true){
            int x=stk[top--];//从最后一个弹出
            instk[x]=false;
            belong[x]=gro;
            siz[gro]++;
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
        int a,b;
        cin>>a>>b;
        edge[cnt].fro=a,edge[cnt].to=b;
        edge[cnt].nxt=head[a];
        head[a]=cnt;
        cnt++;
    }
    for(int i=1;i<=n;i++){
        if(dfn[i]==0) tarjan(i);
    }
    for(int i=1;i<cnt;i++){
        int u=edge[i].fro;
        int v=edge[i].to;
        if(belong[u]!=belong[v])
            son[belong[u]]++;
    }
    int ans=0;
    int flag=0;
    for(int i=1;i<=gro;i++){
        if(son[i]==0&&flag==0){
            flag=1;
            ans+=siz[i];
        }
        else if(son[i]==0&&flag==1){
            cout<<"0";
            return 0;
        }
    }
    cout<<ans;
    return 0;
}