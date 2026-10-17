#include<bits/stdc++.h>
using namespace std;
int f;
int n,m,w;
struct node{
    int fro,to,val,nxt;
}edge[10010];
int head[3010],dis[3010],ans[3010];
// bool inq[1010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>f;
    while(f--){
        cin>>n>>m>>w;
        memset(dis,0x3f3f3f3f,sizeof(dis));
        // memset(inq,0,sizeof(inq));
        memset(head,0,sizeof(head));
        memset(ans,0,sizeof(ans));
        queue<pair<int,int>> q;//在每组内定义，避免每次清空
        int cnt=1;
        int flag=0;
        for(int i=1;i<=m;i++){//链式前向星建图
            int u,v,w;
            cin>>u>>v>>w;
            edge[cnt].fro=u,edge[cnt].to=v,edge[cnt].val=w;
            edge[cnt].nxt=head[u];
            head[u]=cnt;//cnt是建边的唯一标准
            cnt++;
            edge[cnt].fro=v,edge[cnt].to=u,edge[cnt].val=w;
            edge[cnt].nxt=head[v];
            head[v]=cnt;
            cnt++;
        }
        for(int i=1;i<=w;i++){
            int u,v,w;
            cin>>u>>v>>w;
            edge[cnt].fro=u,edge[cnt].to=v,edge[cnt].val=-w;
            edge[cnt].nxt=head[u];
            head[u]=cnt;//cnt是建边的唯一标准
            cnt++;
        }
        for(int i=1;i<=m+w;i++){
            edge[cnt].to=i,edge[cnt].val=0;
            edge[cnt].nxt=head[0];
            head[0]=cnt;//cnt是建边的唯一标准
            cnt++;
        }//不保证在哪里出发
        dis[0]=0;
        q.push({-dis[0],0});
        while(!q.empty()){
            int num=q.front().second;
            q.pop();
            // inq[num]=false;
            for(int i=head[num];i;i=edge[i].nxt){
                int v=edge[i].to;//i是边序号 v/num是节点编号
                int w=edge[i].val;
                if(dis[v]>dis[num]+w){
                    dis[v]=dis[num]+w;
                    // if(inq[v]==false){//注意特判
                    //     inq[v]=true;  
                        ans[v]++;
                    // }
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
    }
    return 0;
}