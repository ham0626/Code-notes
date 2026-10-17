#include<bits/stdc++.h>
using namespace std;
int n,m;
int way[10010],dan[110][110];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>way[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        cin>>dan[i][j];
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                dan[i][j]=min(dan[i][j],dan[i][k]+dan[k][j]);
            }
    int ans=0;
    for(int i=2;i<=m;i++){
        ans+=dan[way[i-1]][way[i]];
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++)
    //     cout<<dan[i][j]<<" ";
    //     cout<<'\n';
    // }
    cout<<ans;
    return 0;
}