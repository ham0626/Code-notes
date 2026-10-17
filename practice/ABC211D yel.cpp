#include<bits/stdc++.h>
using namespace std;
int n,m;
int mod=1e9+7;
struct node{
    int fro,to,nxt;
}edge[4000010];
int head[1000010],dis[1000010],ans[1000010];//距离，条数
queue<int> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(dis,-1,sizeof(dis));
    cin>>n>>m;
    int cnt=1;
    for(int i=1;i<=m;i++){
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
    ans[1]=1;
    dis[1]=0;
    q.push(1);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=head[cur];i;i=edge[i].nxt){
            int v=edge[i].to;
            if(dis[v]==-1){//没访问过
                dis[v]=dis[cur]+1;
                ans[v]=ans[cur];
                q.push(v);
            }
            else{
                if(dis[v]==dis[cur]+1){
                    ans[v]=(ans[v]+ans[cur])%mod;
                }
                else continue;
            }
        }
    }
    cout<<ans[n];
    return 0;
}