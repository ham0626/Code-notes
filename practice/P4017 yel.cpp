#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e3+5;
const int mod=80112002;
int n,m;
int head[MAXN],fa[MAXN],dp[MAXN],son[MAXN];
queue<int> q;
struct Node{
    int fro,to,nxt;
}edge[MAXN*1000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int cnt=1;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        edge[cnt].fro=u,edge[cnt].to=v;
        edge[cnt].nxt=head[u];
        head[u]=cnt;
        fa[v]++,son[u]++;
        cnt++;
    }
    for(int i=1;i<=n;i++)
        if(fa[i]==0) dp[i]=1,q.push(i);//入度
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=head[cur];i;i=edge[i].nxt){
            int v=edge[i].to;
            fa[v]--;
            if(fa[v]==0) q.push(v);
            dp[v]=(dp[v]+dp[cur])%mod;//v可以通过cur走到
        }
    }
    int maxn=0;
    for(int i=1;i<=n;i++)
        if(son[i]==0)//出度为0 生产者
        maxn=(maxn+dp[i])%mod;
    cout<<maxn;
    return 0;
}