#include<bits/stdc++.h>
using namespace std;
int n;
int fa[100005],to[100005];
queue<int> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int u;
        cin>>u;
        to[i]=u;
        fa[u]++;
    }
    for(int i=1;i<=n;i++)
        if(fa[i]==0)
        q.push(i);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        int v=to[cur];
        fa[v]--;
        if(fa[v]==0) q.push(v);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(fa[i]>0) ans++;
    cout<<ans;
    return 0;
}