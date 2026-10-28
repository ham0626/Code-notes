#include<bits/stdc++.h>
using namespace std;
int n,m,maxn=0,minn=0x3f3f3f3f;
int mapp[1005][1005],dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
bool vis[1005][1005];
bool check(int lim){
    memset(vis,0,sizeof(vis));
    queue<pair<int,int>> q;//存x y坐标
    for(int i=1;i<=n;i++){
        if(mapp[1][i]<=lim){
            q.push({1,i});
            vis[1][i]=true;
        }
    }
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x==n) return true;
        for(int i=0;i<=3;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<1||nx>n||ny<1||ny>m||vis[nx][ny]==true||mapp[nx][ny]>lim) continue;
            q.push({nx,ny});
            vis[nx][ny]=true;//*
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
        cin>>mapp[i][j];
        minn=min(minn,mapp[i][j]);
        maxn=max(maxn,mapp[i][j]);
        }
    int l=minn,r=maxn;
    int ans=0x3f3f3f3f;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid))//只走伤害值<=mid的格子
            ans=min(ans,mid),r=mid-1;
        else l=mid+1;
    }
    cout<<ans;
    return 0;
}