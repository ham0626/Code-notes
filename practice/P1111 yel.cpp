#include<bits/stdc++.h>
using namespace std;
int n,m;
int fa[1005];
struct Node{
    int fro,to,val;
}edge[100005];
bool comp(Node x,Node y){
    return x.val<y.val;
}
int find(int x){
    if(fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int cnt=1;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int x,y,t;
        cin>>x>>y>>t;
        edge[cnt].fro=x,edge[cnt].to=y,edge[cnt].val=t;
        cnt++;
    }
    int num=0,ans=0;
    sort(edge+1,edge+cnt,comp);
    for(int i=1;i<=m;i++){
        int u=edge[i].fro;
        int v=edge[i].to;
        int w=edge[i].val;
        if(find(u)!=find(v)){
            num++;
            ans=max(ans,w);//最早修完
            // cout<<num<<'\n';
            fa[find(u)]=fa[find(v)];
            if(num==n-1) break;//最快联通
        }
    }
    if(num!=n-1) cout<<"-1";
    else cout<<ans;
    return 0;
}