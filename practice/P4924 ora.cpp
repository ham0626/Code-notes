#include<bits/stdc++.h>
using namespace std;
int mapp[505][505];
int temp[505][505];
int n,m;
void turn0(int x,int y,int r){//顺时针
    for(int i=x-r;i<=x+r;i++)
        for(int j=y-r;j<=y+r;j++){
            temp[i][j]=mapp[i][j];
        }
    for(int i=-r;i<=r;i++)
        for(int j=-r;j<=r;j++){
            // cout<<mapp[x+j][y-i]<<" ";
            mapp[x+j][y-i]=temp[x+i][y+j];
            // cout<<mapp[x+j][y-i]<<'\n';
        }
    return;
}
void turn1(int x,int y,int r){//逆时针
    for(int i=x-r;i<=x+r;i++)
        for(int j=y-r;j<=y+r;j++){
            temp[i][j]=mapp[i][j];
        }
    for(int i=-r;i<=r;i++)
        for(int j=-r;j<=r;j++){
            // cout<<mapp[x+j][y-i]<<" ";
            mapp[x-j][y+i]=temp[x+i][y+j];
            // cout<<mapp[x+j][y-i]<<'\n';
        }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        mapp[i][j]=(i-1)*n+j;
    for(int i=1;i<=m;i++){
        int x,y,r,z;
        cin>>x>>y>>r>>z;
        if(z==0) turn0(x,y,r);
        else turn1(x,y,r);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        cout<<mapp[i][j]<<" ";
        cout<<'\n';
    }
    return 0;
}