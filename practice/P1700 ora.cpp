#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int dis[105][105],ans[105];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        dis[u][v]=1;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(dis[i][k]==1&&dis[k][j]==1)
                dis[i][j]=1;
            }
    int cnt=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans[i]+=dis[j][i];
        }
        if(ans[i]==n-1){
            cnt=i;
            break;
        }
    }
    cout<<cnt;
    return 0;
}