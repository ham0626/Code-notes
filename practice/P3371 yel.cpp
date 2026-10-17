#include<bits/stdc++.h>
using namespace std;
int n,m,s;//链式前向星
//每读入一条边，就把它插到“以这个点为起点的那串边”的最前面
int head[10005];//初始化成0，遇到空的直接停下
int dis[10005];//起点到某一点的已知最短距离
bool vis[10005];
struct node{
    int fro,to,val,nxt;
}edge[5000005];
priority_queue<pair<int,int>> q;//默认按first从大到小，first相同比second
//-dis[y],y(节点)
//每次挑当前 dis 最小的点
//就可以断定它的最短距离已经确定了(每次都和+……比较)，以后不会再被改小
//所以不能有负边权
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>s;
    int cnt=1;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge[cnt].fro=u,edge[cnt].to=v,edge[cnt].val=w;
        edge[cnt].nxt=head[u];//nxt记录数组下标
        head[u]=cnt;//head内容记数组下标，head下标记from节点
        cnt++;
    }
    memset(dis,0x3f3f3f3f,sizeof(dis));//最开始都到不了
    dis[s]=0;
    q.push({-dis[s],s});
    while(!q.empty()){
        int num=q.top().second;//点节点
        q.pop();
        for(int i=head[num];i;i=edge[i].nxt){
            vis[num]=true;//i是边序号 要检查节点
            int v,w;
            v=edge[i].to;//点节点
            w=edge[i].val;
            if(dis[v]>dis[num]+w&&vis[v]==false){
            dis[v]=dis[num]+w;//点节点
            q.push({-(dis[num]+w),v});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dis[i]!=0x3f3f3f3f) cout<<dis[i]<<" ";
        else cout<<"2147483647 ";
    }
    return 0;
}