#include<bits/stdc++.h>
using namespace std;
int n,m,k,s,t;
int head[10005],dp[10005][15];//城市x,白嫖了几次
struct Node{
    int fro,to,nxt,val;
}edge[100005];
priority_queue<pair<int,pair<int,int>>> q;//路径 序号 白嫖数
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k>>s>>t;
    memset(dp,0x3f3f3f3f,sizeof(dp));
    int cnt=1;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edge[cnt].fro=a,edge[cnt].to=b,edge[cnt].val=c;
        edge[cnt].nxt=head[a];
        head[a]=cnt;
        cnt++;
        edge[cnt].fro=b,edge[cnt].to=a,edge[cnt].val=c;
        edge[cnt].nxt=head[b];
        head[b]=cnt;
        cnt++;
    }
    dp[s][0]=0;
    q.push({-dp[s][0],{s,0}});
    while(!q.empty()){
        int cost=-q.top().first;
        int cur=q.top().second.first;//序号
        int free=q.top().second.second;//白嫖次数
        q.pop();
        for(int i=head[cur];i;i=edge[i].nxt){
            int v=edge[i].to;
            int w=edge[i].val;
            if(dp[v][free]>dp[cur][free]+w){//正常走
                dp[v][free]=dp[cur][free]+w;
                q.push({-dp[v][free],{v,free}});
                
            }
            if(free<k){
                if(dp[v][free+1]>cost){
                dp[v][free+1]=cost;
                q.push({-dp[v][free+1],{v,free+1}});
                }
            }
        }
    }
    int minn=0x3f3f3f3f;
    for(int i=0;i<=k;i++) minn=min(minn,dp[t][i]);
    cout<<minn;
    return 0;
}