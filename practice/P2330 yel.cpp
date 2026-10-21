#include<bits/stdc++.h>
using namespace std;
int n,m;
int fa[305],ans[305];
struct node{
    int fro,to,val;
}edge[8010];
bool comp(node x,node y){
    return x.val<y.val;
}
int find(int x){
    if(x==fa[x]) return x;
    else return fa[x]=find(fa[x]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int cnt=1;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        edge[cnt].fro=u,edge[cnt].to=v,edge[cnt].val=c;
        cnt++;
    }
    int num=0;
    sort(edge+1,edge+m+1,comp);
    for(int i=1;i<=m;i++){
        int u=edge[i].fro;
        int v=edge[i].to;
        int w=edge[i].val;
        if(find(v)!=find(u)){//直接查找*
            fa[find(v)]=fa[find(u)];//一整个子树都得改*
            num++;
            ans[num]=w;
        }
    }
    cout<<num<<" "<<ans[num];
    return 0;
}