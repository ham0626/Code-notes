#include<bits/stdc++.h>
using namespace std;
int n,m;
int fa[2050],head[2050];
struct Node{
    int fro,to,nxt,val;
}edge[10005];
int find(int x){
    if(x==fa[x]) return x;
    else return fa[x]=find(fa[x]);
}
bool comp(Node x,Node y){
    return x.val<y.val;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int cnt=1;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int a,b,l;
        cin>>a>>b>>l;
        edge[cnt].fro=a,edge[cnt].to=b,edge[cnt].val=l;
        edge[cnt].nxt=head[a];
        head[a]=cnt;
        cnt++;
    }
    int maxx=0;
    sort(edge+1,edge+cnt,comp);
    for(int i=1;i<=m;i++){
        int u=edge[i].fro;
        int v=edge[i].to;
        int w=edge[i].val;
        if(find(u)!=find(v)){
            maxx=max(maxx,w);
            fa[find(u)]=fa[find(v)];
        }
    }
    cout<<maxx;
    return 0;
}