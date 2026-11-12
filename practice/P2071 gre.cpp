#include<bits/stdc++.h>
using namespace std;
const int MAXN=5000;
int n;
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
    cin>>n;
    for(int i=1;i<=2*n;i++){//mat下标是人
        int p1,p2;
        cin>>p1>>p2;
        mat[i].push_back(2*p1-1);
        mat[i].push_back(2*p1);
        mat[i].push_back(2*p2-1);
        mat[i].push_back(2*p2);
    }
    for(int i=1;i<=2*n;i++){//match下标是排
        memset(vis,0,sizeof(vis));
        if(dfs(i)==true)//能找到对象
        ans++;
    }
    cout<<ans;
    return 0;
}