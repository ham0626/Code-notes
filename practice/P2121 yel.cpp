#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Node{
    int fro,to,nxt,val;
}edge[100005];
int head[100005],fa[100005];
int find(int x){
    if(fa[x]==x) return fa[x];
    else return fa[x]=find(fa[x]);
}
bool comp(Node x,Node y){
    return x.val>y.val;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    int sum=0,ans=0,num=0;
    int cnt=1;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge[cnt].fro=u,edge[cnt].to=v,edge[cnt].val=w;
        edge[cnt].nxt=head[u];
        head[u]=cnt;
        cnt++;
        sum+=w;
    }
    sort(edge+1,edge+cnt,comp);
    for(int i=1;i<=m;i++){
        int u=edge[i].fro;
        int v=edge[i].to;
        if(find(u)!=find(v)){
            ans+=edge[i].val;
            num++;
            fa[find(v)]=fa[find(u)];
            if(num==k) break;
        } 
    }
    cout<<ans;
    return 0;
}