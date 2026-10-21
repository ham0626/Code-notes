#include<bits/stdc++.h>
using namespace std;
int n,m;
int fa[100005],head[100005];
struct node{
    int fro,to,val;
}edge[300005];
bool comp(node x,node y){
    return x.val<y.val;
}
int find(int x){
    if(x==fa[x]) return fa[x];
    else return fa[x]=find(fa[x]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int cnt=1;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge[cnt].fro=u,edge[i].to=v,edge[cnt].val=w;
        cnt++;//联通就行
    }
    int num=0;
    sort(edge+1,edge+m+1,comp);
    long long int sum=0;
    for(int i=1;i<=m;i++){
        int u=edge[i].fro;
        int v=edge[i].to;
        if(find(u)!=find(v)){//边权最小而且还没联通(如果find相同，再加就成环了)
            sum+=edge[i].val;
            fa[find(u)]=fa[find(v)];
            num++;
        }
    }
    if(num!=n-1) cout<<"orz";
    else cout<<sum;
    return 0;
}