#include<bits/stdc++.h>
using namespace std;
int minn=1000;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
struct node{
    int x,y;
}tap[9];
int mapp[4][4];
void dfs(int t,int cnt){
    int flag=0;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
        if(mapp[i][j]!=1){
            flag=1;//有没开的
            break;
        }
    if(flag==0){
        minn=min(minn,cnt);
        return;
    }
    if(t==9) return;
    int x=tap[t].x,y=tap[t].y;
    dfs(t+1,cnt);//不选
    if(mapp[x][y]==1) mapp[x][y]=0;
    else mapp[x][y]=1;
    for(int i=0;i<=3;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<1||nx>3||ny<1||ny>3) continue;
        if(mapp[nx][ny]==1) mapp[nx][ny]=0;
        else mapp[nx][ny]=1;
    }
    dfs(t+1,cnt+1);//选
    if(mapp[x][y]==1) mapp[x][y]=0;
    else mapp[x][y]=1;
    for(int i=0;i<=3;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<1||nx>3||ny<1||ny>3) continue;
        if(mapp[nx][ny]==1) mapp[nx][ny]=0;
        else mapp[nx][ny]=1;
    }//还原
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
        cin>>mapp[i][j];
    tap[0].x=1,tap[0].y=1;
    tap[1].x=1,tap[1].y=2;
    tap[2].x=1,tap[2].y=3;
    tap[3].x=2,tap[3].y=1;
    tap[4].x=2,tap[4].y=2;
    tap[5].x=2,tap[5].y=3;
    tap[6].x=3,tap[6].y=1;
    tap[7].x=3,tap[7].y=2;
    tap[8].x=3,tap[8].y=3;
    dfs(0,0);
    cout<<minn;
    return 0;
}