//SCC:强联通分量(有向图) low[u]==dfn[u]弹栈
//scc是每一个belong里面的那堆点
//BCC:双联通分量(无向图)->
//V-BCC(点) low[v]>=dfn[u]
//E-BCC(边) low[v]>dfn[u]
//关于=:
//1.low[v]<dfn[u]:v有一条边回到u,v共同的祖先了 u可能不是割点
//2.low[v]==dfn[u]:v最前只能回到u u一断v就不连通了 u绝对是割点
//但是u->v v->…->u都是通的 u->v不是割边
//3.low[v]>dfn[u]:v甚至连u都回不到(只能u->v) u是割点 且u->v是割边
//点双和边双是是割点/割边之间内部无割点割边的一坨
//DCC：双连通分量统称
#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,m;
int timer,top,gro;
int head[MAXN],low[MAXN],dfn[MAXN];
int stk[4000005];
int vis[MAXN];
vector<int> bcc[MAXN];
struct Node{
    int fro,to,nxt;
}edge[4000005];
void tarjan(int u,int fa){//传父边编号
    dfn[u]=low[u]=++timer;
    int child=0;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(i==(fa^1)) continue;//处理回边
        if(dfn[v]==0){
            child++;
            stk[++top]=i;//存边序号
            tarjan(v,i);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                int siz=0;//节点数
                gro++;//个数
                while(true){
                    int x=stk[top--];
                    int uu=edge[x].fro;
                    int vv=edge[x].to;
                    if(vis[uu]!=gro){
                        siz++;
                        bcc[gro].push_back(uu);
                        vis[uu]=gro;
                    }
                    if(vis[vv]!=gro){
                        siz++;
                        bcc[gro].push_back(vv);
                        vis[vv]=gro;
                    }
                    if(x==i){
                        bcc[gro].push_back(siz);
                        break;
                    }
                }
            }
        }
        else{
            if(dfn[v]<dfn[u]){//是之前的边 避免重复处理
            stk[++top]=i;
            low[u]=min(low[u],dfn[v]);
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int cnt=2;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        if(v==u)
            continue;
        edge[cnt].fro=u,edge[cnt].to=v;
        edge[cnt].nxt=head[u];
        head[u]=cnt;
        cnt++;
        edge[cnt].fro=v,edge[cnt].to=u;
        edge[cnt].nxt=head[v];
        head[v]=cnt;
        cnt++;
    }
    for(int i=1;i<=n;i++){
        if(dfn[i]==0){
            if(head[i]==0){
                gro++;//处理孤立点
                bcc[gro].push_back(i);
                bcc[gro].push_back(1);
                dfn[i]=low[i]=++timer;
            }
            else tarjan(i,0);
        }
    }
    cout<<gro<<'\n';
    for(int i=1;i<=gro;i++){
        cout<<bcc[i][bcc[i].size()-1]<<" ";//节点个数
        for(int j=0;j<bcc[i].size()-1;j++)
        cout<<bcc[i][j]<<" ";
        cout<<'\n';
    }
    return 0;
}