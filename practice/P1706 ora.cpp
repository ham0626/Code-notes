#include<bits/stdc++.h>
using namespace std;
int n;
int ans[15];
bool vis[15];
void dfs(int x){//在排第几个
    if(x>n){
        for(int i=1;i<=n;i++) cout<<setw(5)<<ans[i];
        cout<<'\n';
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            ans[x]=i;
            vis[i]=true;
            dfs(x+1);
            vis[i]=false;
        } 
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    dfs(1);
    return 0;
}
