//不等式：dis[u](终点)<=dis[v](起点)+w;
#include<bits/stdc++.h>
using namespace std;
int t;
int n,m;//点，边，起点
struct node{
    int fro,to,val,nxt;
}edge[10010];
int dis[10010];
int head[10010],cnt[10010];
bool inq[10010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(dis,0x3f3f3f3f,sizeof(dis));
    memset(head,0,sizeof(head));
    memset(inq,0,sizeof(inq));
    memset(cnt,0,sizeof(cnt));
    queue<pair<int,int>> q;
    int lin=1;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
    int u,v,w;//
    cin>>u>>v>>w;
    edge[lin].fro=v,edge[lin].to=u,edge[lin].val=w;
    edge[lin].nxt=head[v];
    head[v]=lin;
    lin++;
    }
    for(int i=1;i<=n;i++){
        edge[lin].to=i,edge[lin].val=0;
        edge[lin].nxt=head[0];
        head[0]=lin;
        lin++;
    }
    dis[0]=0;
    q.push({-dis[0],0});
    while(!q.empty()){
        int num=q.front().second;
        q.pop();
        inq[num]=false;
        for(int i=head[num];i;i=edge[i].nxt){
            int v=edge[i].to;
            int w=edge[i].val;
            if(dis[v]>dis[num]+w){//有更短路就更新
                dis[v]=dis[num]+w;
                if(inq[v]==false){
                inq[v]=true;
                cnt[v]++;//入队次数
                if(cnt[v]>=n+1){
                    cout<<"NO"<<'\n';
                    return 0;
                }
                q.push({-(dis[v]),v});
                }
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
    return 0;
}