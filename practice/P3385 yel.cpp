//SPFA:有负边权没有1负环(不锁点)
//一个点入队次数超过n次，就说明图中存在负环(n个点,n-1条边)
#include<bits/stdc++.h>
using namespace std;
int t;
int n,m;//点，边，起点
struct node{
    int fro,to,val,nxt;
}edge[8010];
int dis[8010];
int head[8010],cnt[8010];
bool inq[8010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int flag;
    cin>>t;
    while(t--){
        memset(dis,0x3f3f3f3f,sizeof(dis));
        memset(head,0,sizeof(head));
        memset(inq,0,sizeof(inq));
        memset(cnt,0,sizeof(cnt));
        queue<pair<int,int>> q;
        int lin=1,flag=0;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            edge[lin].fro=u,edge[lin].to=v,edge[lin].val=w;
            edge[lin].nxt=head[u];
            head[u]=lin;
            lin++;
            if(w>=0){
                edge[lin].fro=v,edge[lin].to=u,edge[lin].val=w;
                edge[lin].nxt=head[v];
                head[v]=lin;
                lin++;
            }
        }
        dis[1]=0;
        q.push({-dis[1],1});
        while(!q.empty()){
            int num=q.front().second;
            q.pop();
            inq[num]=false;
            for(int i=head[num];i;i=edge[i].nxt){
                flag=0;
                int v=edge[i].to;
                int w=edge[i].val;
                if(dis[v]>dis[num]+w){//有更短路就更新
                    dis[v]=dis[num]+w;
                    if(inq[v]==false){
                    inq[v]=true;
                    cnt[v]++;//入队次数
                    if(cnt[v]>=n+1){
                        flag=1;
                        cout<<"YES"<<'\n';
                        break;
                    }
                    q.push({-(dis[v]),v});
                    }
                }
                if(flag==1) break;
            }
            if(flag==1) break;
        }
        if(flag==1) continue;
        else cout<<"NO"<<'\n';
    }
    return 0;
}