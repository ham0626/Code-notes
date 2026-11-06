#include<bits/stdc++.h>
using namespace std;
int n,m;
int cnt1,cnt2;//对每个连接块统计
int head[10005];
int col[10005];//0没颜色 1/2
struct Node{
    int fro,to,nxt;
}edge[200005];
bool dfs(int u){
    if(col[u]==1) cnt1++;
    else cnt2++;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(col[v]==0){
            if(col[u]==1) col[v]=2;
            else col[v]=1;
            if(dfs(v)==false) return false;
        }
        else{
            if(col[u]==col[v]) return false;
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int cnt=1;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        edge[cnt].fro=u,edge[cnt].to=v;
        edge[cnt].nxt=head[u];
        head[u]=cnt;
        cnt++;
        edge[cnt].fro=v,edge[cnt].to=u;
        edge[cnt].nxt=head[v];
        head[v]=cnt;
        cnt++;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(col[i]==0){
            col[i]=1;
            cnt1=0,cnt2=0;
            if(dfs(i)==false){
                cout<<"Impossible";
                return 0;
            }
            ans+=min(cnt1,cnt2);
        }
    }
    cout<<ans;
    return 0;
}