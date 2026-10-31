#include<bits/stdc++.h>
using namespace std;
int n,m;
int head[100005],num[100005],dep[100005];
int up[100005][25];
struct info{
    int sum0;//G
    int sum1;//H
}tree[100010];
struct Node{
    int fro,to,nxt;
}edge[200010];
void dfs(int u,int fa){
    dep[u]=dep[fa]+1;
    up[u][0]=fa;
    for(int i=1;i<=20;i++)//必须从小到大
        up[u][i]=up[up[u][i-1]][i-1];
    if(num[u]==0){
        tree[u].sum0=tree[fa].sum0+1;
        tree[u].sum1=tree[fa].sum1;
    }
    if(num[u]==1){
        tree[u].sum1=tree[fa].sum1+1;
        tree[u].sum0=tree[fa].sum0;
    }
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==fa) continue;
        dfs(v,u);
    }
    return;
}
int LCA(int a,int b){
    if(dep[a]<dep[b]) swap(a,b);
    for(int i=20;i>=0;i--){//二进制拆分 从大到小
        int v=up[a][i];
        if(dep[v]>=dep[b])//等于等于等于
        a=v;
    }
    if(a==b) return a;
    for(int i=20;i>=0;i--){
        if(up[a][i]!=up[b][i])
        a=up[a][i],b=up[b][i];
    }
    return up[a][0];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int cnt=1;
    for(int i=1;i<=n;i++){
        char ch;
        cin>>ch;
        if(ch=='G') num[i]=0;
        else num[i]=1;
    }
    cnt=1;
    for(int i=1;i<=n-1;i++){
        int x,y;
        cin>>x>>y;
        edge[cnt].fro=x,edge[cnt].to=y;
        edge[cnt].nxt=head[x];
        head[x]=cnt;
        cnt++;
        edge[cnt].fro=y,edge[cnt].to=x;
        edge[cnt].nxt=head[y];
        head[y]=cnt;
        cnt++;
    }
    dfs(1,0);
    for(int i=1;i<=m;i++){
        int a,b;
        char c;
        cin>>a>>b>>c;
        int l=LCA(a,b);
        int cntg=tree[a].sum0+tree[b].sum0-2*tree[l].sum0;
        int cnth=tree[a].sum1+tree[b].sum1-2*tree[l].sum1;
        if(num[l]==1) cnth++;
        else cntg++;
        if(c=='G'){
            if(cntg>0) cout<<"1";
            else cout<<"0";
        }
        else{
            if(cnth>0) cout<<"1";
            else cout<<"0";
        }
    }
    return 0;
}