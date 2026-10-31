#include<bits/stdc++.h>
using namespace std;
int n,m;
int tim[55][55];
int mapp[55][55][35];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    memset(tim,0x3f3f3f3f,sizeof(tim));//初始化
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        mapp[u][v][0]=1;
        tim[u][v]=1;
    }
    for(int k=1;k<=31;k++){//2的平方数
        for(int i=1;i<=n;i++){//中间站
            for(int j=1;j<=n;j++){//起点
                if(mapp[j][i][k-1]==0) continue;//走不通
                for(int t=1;t<=n;t++){
                    if(mapp[i][t][k-1]==1){//每次走一半
                        mapp[j][t][k]=1;
                        tim[j][t]=1;
                    }
                }
            }
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(tim[i][k]!=0x3f3f3f3f&&tim[k][j]!=0x3f3f3f3f)
                tim[i][j]=min(tim[i][j],tim[i][k]+tim[k][j]);
            }
    cout<<tim[1][n];
    return 0;
}