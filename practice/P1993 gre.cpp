#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
    int fro,to,val,nxt;
}edge[5010];
int head[5010],dis[5010],ans[5010];
bool inq[5010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    memset(dis,0x3f3f3f3f,sizeof(dis));
    memset(inq,0,sizeof(inq));
    memset(head,0,sizeof(head));
    memset(ans,0,sizeof(ans));
    queue<pair<int,int>> q;//在每组内定义，避免每次清空
    int cnt=1;
    int flag=0;
    for(int i=1;i<=m;i++){//链式前向星建图
        int op,u,v,w;
        cin>>op;
        cin>>u>>v>>w;
        if(op==1){//a是终点
            edge[cnt].fro=v,edge[cnt].to=u,edge[cnt].val=w;
            edge[cnt].nxt=head[v];
            head[v]=cnt;//cnt是建边的唯一标准
            cnt++;
        }
        edge[cnt].fro=u,edge[cnt].to=v,edge[cnt].val=w;
        edge[cnt].nxt=head[u];
        head[u]=cnt;//cnt是建边的唯一标准
        cnt++;
        if(w>=0){
            edge[cnt].fro=v,edge[cnt].to=u,edge[cnt].val=w;
            edge[cnt].nxt=head[v];
            head[v]=cnt;
            cnt++;
        }
    }
    dis[1]=0;
    q.push({-dis[1],1});
    while(!q.empty()){
        int num=q.front().second;
        q.pop();
        inq[num]=false;
        for(int i=head[num];i;i=edge[i].nxt){
            int v=edge[i].to;//i是边序号 v/num是节点编号
            int w=edge[i].val;
            if(dis[v]>dis[num]+w){
                dis[v]=dis[num]+w;
                if(inq[v]==false){//注意特判
                    inq[v]=true;  
                    ans[v]++;
                }
                if(ans[v]>=n+1){
                    flag=1;
                    break;
                }
                q.push({-dis[v],v});
            }
            if(flag==1) break;
        }
    }
    if(flag==1) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
    return 0;
}