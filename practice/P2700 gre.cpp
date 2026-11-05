#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,k;
int head[MAXN],fa[MAXN];
bool enemy[MAXN];
struct Node{
    int fro,to,nxt,val;
}edge[MAXN];
bool comp(Node x,Node y){
    return x.val>y.val;//先把最大的拿走
}
int find(int x){
    if(fa[x]==x) return fa[x];
    else return fa[x]=find(fa[x]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,k;
    cin>>n>>k;
    int cnt=1;
    for(int i=1;i<=k;i++){
        int x;
        cin>>x;
        enemy[x]=true;
    }
    long long sum=0;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=n-1;i++){
        int a,b,c;
        cin>>a>>b>>c;
        sum+=c;
        edge[cnt].fro=a,edge[cnt].to=b,edge[cnt].val=c;
        edge[cnt].nxt=head[a];
        head[a]=cnt;
        cnt++;
    }
    long long ans=0;
    sort(edge+1,edge+cnt,comp);
    for(int i=1;i<cnt;i++){
        int u=edge[i].fro;
        int v=edge[i].to;
        int w=edge[i].val;
        if(enemy[find(u)]==true&&enemy[find(v)]==true) continue;
        if(fa[find(v)]!=fa[find(u)]){
            if(enemy[find(u)]==true)
                enemy[find(v)]=true;
            if(enemy[find(v)]==true)
                enemy[find(u)]=true;
            fa[find(v)]=fa[find(u)];
            ans+=w;
        }
    }
    cout<<sum-ans;
    return 0;
}