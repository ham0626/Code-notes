#include<bits/stdc++.h>
using namespace std;
int n,m;
int fa[1050];
bool vis[1050];
int find(int x){
    if(x==fa[x]) return x;
    else return fa[x]=find(fa[x]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    while(cin>>n&&n!=0){
        cin>>m;
        int ans=0;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++) fa[i]=i;
        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            fa[find(u)]=find(v);
        }
        for(int i=1;i<=n;i++){
            if(vis[find(i)]==false){
                ans++;
                vis[find(i)]=true;
            }
        }
        cout<<ans-1<<'\n';//n个块 n-1条路
    }
    return 0;
}