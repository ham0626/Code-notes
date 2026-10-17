#include<bits/stdc++.h>
using namespace std;
int n,r;
int ans[25];
bool vis[25];
void dfs(int x){//当前在排第几个
    if(x>r){
        for(int i=1;i<=r;i++) cout<<setw(3)<<ans[i];
        cout<<'\n';
        return;
    }
    for(int i=ans[x-1];i<=n;i++){
        if(vis[i]==false){
            ans[x]=i;
            vis[i]=true;
            dfs(x+1);
            vis[i]=false;
        }
        else continue;
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>r;
    ans[0]=1;
    dfs(1);
    return 0;
}