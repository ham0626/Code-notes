//when双向边,when单边
//有向(单边):谁是谁的父节点(赢 必须从A->B)
//建图:前向星/vector:从当前点开始搜，必须建两条边
//建图:结构体(生成树,只管边权大小):并查集(关心节点 不管方向)
//建图:邻接矩阵:有向
#include<bits/stdc++.h>
using namespace std;
int n,m,b;
int charge[10005],head[10005];
long long dis[10005];
struct node{
    int fro,to,val,nxt;
}edge[1000005];
bool check(int lim){
    if(charge[1]>lim||charge[n]>lim) return false;//根本走不到
    priority_queue<pair<int,int>> q;
    dis[1]=0;//dis是最小扣血量
    q.push({-dis[1],1});
    while(!q.empty()){
        int cur=q.top().second;
        q.pop();
        for(int i=head[cur];i;i=edge[i].nxt){
            int v=edge[i].to;
            int w=edge[i].val;//扣血量
            if(charge[v]>lim) continue;//收费太高,换一条路
            if(dis[v]>dis[cur]+w){
                dis[v]=dis[cur]+w;
                q.push({-dis[v],v});
            }
        }
    }
    if(dis[n]>b) return false;//扣血太多,走不到
    else return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);//memset只能赋0/-1/0x3f3f3f3f
    cin>>n>>m>>b;
    fill(dis+1,dis+n+1,1e18);
    int maxn=0;
    for(int i=1;i<=n;i++) cin>>charge[i],maxn=max(maxn,charge[i]);//最大扣血量
    int cnt=1;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge[cnt].fro=u,edge[cnt].to=v,edge[cnt].val=w;
        edge[cnt].nxt=head[u];
        head[u]=cnt;
        cnt++;
        edge[cnt].fro=v,edge[cnt].to=u,edge[cnt].val=w;
        edge[cnt].nxt=head[v];
        head[v]=cnt;
        cnt++;
    }
    if(check(1e9)==false){
        cout<<"AFK";
        return 0;
    }
    int l=0,r=maxn;
    while(l<=r){
        fill(dis+1,dis+n+1,1e18);
        int mid=(l+r)/2;
        if(check(mid)==true)//给一个过路费上限 能不能走通
            r=mid-1;
        else l=mid+1;
    }
    cout<<l;
    return 0;
}