//Tarjan:强连通分量
//传递闭包:两点之间是否联通 n的3次方 
//tarjan分组:可以把一堆互相成环的点看成一个
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+5;
int n,m,top=0,gro=0,timer=0;//指针
int num[MAXN],head[100005],head2[100005];
int low[MAXN];//到这一组的最早时间
int dfn[MAXN];//每个来的时间(访问过必然!=0)
int belong[MAXN];//分组
int stk[MAXN];//这个组里有哪些元素
bool instk[MAXN];//检查在不在当前栈中
int sum[MAXN];//缩点以后总权值
//dfn一直不变(到达时间)
//low会变小
int fa[MAXN],dp[MAXN];
struct Node{
    int fro,to,nxt;
}edge[100005];
struct Node2{
    int fro,to,nxt;
}edge2[100005];
queue<int> q;
void tarjan(int u){
    dfn[u]=low[u]=++timer;
    stk[++top]=u;//入栈
    instk[u]=true;//标记入栈
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(dfn[v]==0){//没访问过
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instk[v]==true){//访问过 是一组 成环了
            low[u]=min(low[u],dfn[v]);
        }
        else continue;//访问过在其他组
    }
    if(dfn[u]==low[u]){//缩点
        gro++;
        int x;
        while(true){
            int x=stk[top--];
            instk[x]=false;//出栈
            belong[x]=gro;
            sum[gro]+=num[x];
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
    for(int i=1;i<=n;i++) cin>>num[i];
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        edge[cnt].fro=u,edge[cnt].to=v;
        edge[cnt].nxt=head[u];
        head[u]=cnt;
        cnt++;
    }
    for(int i=1;i<=n;i++){
        if(dfn[i]==0) tarjan(i); 
    }
    int lin=1;
    for(int i=1;i<=m;i++){
        int u=edge[i].fro;
        int v=edge[i].to;
        if(belong[u]!=belong[v]){
            u=belong[u];//看一个组
            v=belong[v];
            edge2[lin].fro=u,edge2[lin].to=v;
            edge2[lin].nxt=head2[u];
            head2[u]=lin;
            lin++;
            fa[v]++;
        }
    }
    for(int i=1;i<=gro;i++){
        dp[i]=sum[i];//初始化
        if(fa[i]==0) q.push(i);
    }
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=head2[cur];i;i=edge2[i].nxt){
            int v=edge2[i].to;
            fa[v]--;
            dp[v]=max(dp[v],dp[cur]+sum[v]);
            if(fa[v]==0) q.push(v);
        }
    }
    int maxn=0;
    for(int i=1;i<=gro;i++) maxn=max(maxn,dp[i]);
    cout<<maxn;
    return 0;
}