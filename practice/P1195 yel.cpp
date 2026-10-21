#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int fa[1005],ans[1005];
struct node{
    int fro,to,val;
}edge[10010];
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
    cin>>n>>m>>k;
    int cnt=1;
    if(k==n){//不需要选
        cout<<"0";
        return 0;
    }
    if(k>n){//选不了
        cout<<"No Answer";
        return 0;
    }
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        edge[cnt].fro=u,edge[cnt].to=v,edge[cnt].val=c;
        cnt++;
    }
    int num=0,sum=0;
    sort(edge+1,edge+m+1,comp);
    for(int i=1;i<=m;i++){
        int u=edge[i].fro;
        int v=edge[i].to;
        int w=edge[i].val;
        if(find(v)!=find(u)){//直接查找*
            fa[find(v)]=find(u);//一整个子树都得改*
            sum+=w;
            num++;//最开始n个连通块，选一次-1，最后k个连通块
            if(num==n-k) break;//选n-k条边
        }
    }
    if(num!=n-k){
        cout<<"No Answer";
        return 0;
    }
    else cout<<sum;
    return 0;
}