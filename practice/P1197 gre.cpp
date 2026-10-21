//有向图找联通:Floyd传递闭包(邻接矩阵)
//无向图找联通:并查集(链式前向星)
//连通块=初始孤立总数-合并次数
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int fa[400005],head[400005],ans[400005],died[400005];
bool bomb[400005];
struct node{
    int fro,to,nxt;
}edge[400005];
int find(int x){
    if(fa[x]==x) return x;
    else return fa[x]=find(fa[x]);//并查集不能删点
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int cnt=1;
    for(int i=0;i<n;i++) fa[i]=i;
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
    cin>>k;
    int re=0;
    for(int i=1;i<=k;i++){
        int s;
        cin>>s;
        died[re]=s;//记录死的星球是哪个
        bomb[s]=true;//记录哪些被炸死了
        re++;
    }
    for(int i=0;i<n;i++){//先从死完的开始 并查集可以加不能删
        if(bomb[i]==false){//没死
            for(int j=head[i];j;j=edge[j].nxt)
            find(j);
        }
    }
    int num=n-k;
    for(int i=0;i<n;i++)//当前节点
        if(bomb[i]==false){
            for(int j=head[i];j;j=edge[j].nxt){
                int v=edge[j].to;
                if(bomb[v]==false){
                    if(find(v)!=find(i)){//能走到却没有联通
                        fa[find(i)]=find(v);
                        num--;
                }
            }
        }
    }
    ans[k]=num;
    for(int i=k-1;i>=0;i--){
        int u=died[i];
        bomb[u]=false;//复活
        find(u);
        num++;
        for(int j=head[u];j;j=edge[j].nxt){
            int v=edge[j].to;
            if(bomb[v]==false){
                if(find(v)!=find(u)){
                    fa[find(u)]=find(v);
                    num--;
                }
            }
        }
        ans[i]=num;
    }
    for(int i=0;i<=k;i++) cout<<ans[i]<<'\n';
    return 0;
}