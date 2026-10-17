//传递闭包:有向图
#include<bits/stdc++.h>
using namespace std;
int n;
int dis[110][110];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        cin>>dis[i][j];
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(dis[i][j]==1) continue;//已经联通
                else{
                    if(dis[i][k]+dis[k][j]==2) dis[i][j]=1;
                    else continue;
                }
            }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        cout<<dis[i][j]<<" ";     
        cout<<'\n';   
    }
    return 0;
}