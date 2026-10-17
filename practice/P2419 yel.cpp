//传递闭包:有向图
#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=0;
int dis[110][110],ans[110];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int w,l;
        cin>>w>>l;
        dis[w][l]=1;//只走排名能串起来的
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(dis[i][j]==1) continue;//已经知道结果
                else{
                    if(dis[i][k]+dis[k][j]==2) dis[i][j]=1;
                    else continue;
                }
            }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++)
    //     cout<<dis[i][j]<<" ";
    //     cout<<'\n';
    // }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            ans[i]+=dis[i][j],ans[i]+=dis[j][i];
    for(int i=1;i<=n;i++)
        if(ans[i]==n-1) cnt++;//和其他的都比过了
    cout<<cnt;
    return 0;
}