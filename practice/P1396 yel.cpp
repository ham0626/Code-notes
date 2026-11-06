#include<bits/stdc++.h>
using namespace std;
int n,m,s,t;
int head[10005],fa[10005];
struct Node{
    int fro,to,nxt,val;
}edge[20005];
bool comp(Node x,Node y){
    return x.val<y.val;
}
int find(int x){
    if(x==fa[x]) return fa[x];
    else return fa[x]=find(fa[x]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>s>>t;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge[i].fro=u,edge[i].to=v,edge[i].val=w;
        edge[i].nxt=head[u];
        head[u]=i;
    }
    int ans=0;
    sort(edge+1,edge+1+m,comp);
    for(int i=1;i<=m;i++){
        int u=edge[i].fro;
        int v=edge[i].to;
        int w=edge[i].val;
        if(find(u)!=find(v)){
            fa[find(u)]=fa[find(v)];
            ans=w;
            if(find(s)==find(t)) break;
        }
    }
    cout<<ans;
    return 0;
}