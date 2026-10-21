#include<bits/stdc++.h>
using namespace std;
int n,m;
int fa[100005],dp[100005];
vector<int> city[100005];
queue<int> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);//memset只能赋0/-1/0x3f3f3f3f
    cin>>n>>m;
    for(int i=1;i<=n;i++) dp[i]=1;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        fa[y]++;
        city[x].push_back(y);
    }
    for(int i=1;i<=n;i++)
        if(fa[i]==0)
        q.push(i);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<city[cur].size();i++){
            int v=city[cur][i];
            fa[v]--;
            dp[v]=max(dp[v],dp[cur]+1);
            if(fa[v]==0) q.push(v);
        }
    }
    for(int i=1;i<=n;i++) cout<<dp[i]<<'\n';
    return 0;
}