#include<bits/stdc++.h>
using namespace std;
const int MAXN=400;
int n,m;
int ans;
vector<int> mat[MAXN];
int match[MAXN];
bool vis[MAXN];//这一轮有没有找过
bool dfs(int u){//没有对象的男生
    for(int i=0;i<mat[u].size();i++){
        int v=mat[u][i];//女生
        if(vis[v]==true) continue;
        vis[v]=true;//女生访问过
        if(match[v]==0||dfs(match[v])==true){
            //这个女生(v)的男朋友(match[v])可以换人
            match[v]=u;//配对
            return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){//mat下标是牛
        int s;
        cin>>s;
        for(int j=1;j<=s;j++){
            int k;
            cin>>k;
            mat[i].push_back(k);
        }
    }
    for(int i=1;i<=n;i++){//match下标是牛栏
        memset(vis,0,sizeof(vis));
        if(dfs(i)==true)//能找到对象
        ans++;
    }
    cout<<ans;
    return 0;
}