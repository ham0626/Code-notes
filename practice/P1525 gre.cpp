#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e4+5;
int n,m;
int head[MAXN],col[MAXN];//0没颜色 1/2
struct Node{
    int fro,to,val;
}tmp[200005];
struct Node2{
    int fro,to,nxt,val;
}edge[200005];
bool dfs(int u){
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(col[v]==0){
            if(col[u]==1) col[v]=2;
            else col[v]=1;
            if(dfs(v)==false) return false;
        }
        else if(col[v]==col[u]) return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    long long sum=0;
    //所有输入的下标表示这个点为真 输入下标+n代表这个点为假
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        sum+=c;
        tmp[i].fro=a,tmp[i].to=b,tmp[i].val=c;
    }
    long long l=0,r=sum;
    long long ans=1e18;
    while(l<=r){
        long long mid=(l+r)/2;
        memset(head,0,sizeof(head));
        memset(edge,0,sizeof(edge));
        memset(col,0,sizeof(col));
        int cnt=1;
        for(int i=1;i<=m;i++){
            int u=tmp[i].fro,v=tmp[i].to,w=tmp[i].val;
            if(w>mid){
                edge[cnt].fro=u,edge[cnt].to=v,edge[cnt].val=w;
                edge[cnt].nxt=head[u];
                head[u]=cnt;
                cnt++;
                edge[cnt].fro=v,edge[cnt].to=u,edge[cnt].val=w;
                edge[cnt].nxt=head[v];
                head[v]=cnt;
                cnt++;
            }
        }
        int flag=0;
        for(int i=1;i<=n;i++){
            if(col[i]==0){
                col[i]=1;
                if(dfs(i)==false){
                    flag=1;
                    break;//不能满足
                }
            }
        }
        if(flag==1) l=mid+1;
        else{
            r=mid-1;
            ans=min(ans,mid);
        }
    }
    cout<<ans;//都能分开会一直往小猜 直到0
    return 0;
}