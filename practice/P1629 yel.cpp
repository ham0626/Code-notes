//建反图！=无向边
//原图:
//1->2 w=1
//2->1 w=10
//无向边
//1->2 w=1
//2->1 w=10
//2->1 w=1
//1->2 w=10
//反图
//2->1 w=1
//1->2 w=10
#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
    int fro,to,val,nxt;
}edge1[200010];
struct Node{
    int fro,to,val,nxt;
}edge2[200010];
int head1[1010],head2[1010],dis1[1010],dis2[1010];
bool vis[1010];
priority_queue<pair<int,int>> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(dis1,0x3f3f3f3f,sizeof(dis1));//*
    memset(dis2,0x3f3f3f3f,sizeof(dis2));//*
    cin>>n>>m;
    int cnt=1;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge1[cnt].fro=u,edge1[cnt].to=v,edge1[cnt].val=w;
        edge1[cnt].nxt=head1[u];
        head1[u]=cnt;
        edge2[cnt].fro=v,edge2[cnt].to=u,edge2[cnt].val=w;
        edge2[cnt].nxt=head2[v];
        head2[v]=cnt;
        cnt++;//*
    }
    dis1[1]=0,dis2[1]=0;
    q.push({-dis1[1],1});
    while(!q.empty()){
        int cur=q.top().second;
        q.pop();
        if(vis[cur]==true) continue;
        vis[cur]=true;//标记已经是最短路的
        for(int i=head1[cur];i;i=edge1[i].nxt){
            int v=edge1[i].to;
            int w=edge1[i].val;
            if(dis1[v]>dis1[cur]+w){
                dis1[v]=dis1[cur]+w;
                q.push({-dis1[v],v});
            }
        }
    }
    memset(vis,0,sizeof(vis));
    q.push({-dis2[1],1});
    while(!q.empty()){
        int cur=q.top().second;
        q.pop();
        if(vis[cur]==true) continue;
        vis[cur]=true;//标记已经是最短路的
        for(int i=head2[cur];i;i=edge2[i].nxt){
            int v=edge2[i].to;
            int w=edge2[i].val;
            if(dis2[v]>dis2[cur]+w){
                dis2[v]=dis2[cur]+w;
                q.push({-dis2[v],v});
            }
        }
    }
    int sum1=0,sum2=0;
    for(int i=1;i<=n;i++)
        sum1+=dis1[i];
    for(int i=1;i<=n;i++)
        sum2+=dis2[i];
        cout<<sum1+sum2;
    return 0;
}