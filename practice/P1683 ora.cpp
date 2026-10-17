#include<bits/stdc++.h>
using namespace std;
int w,h,cnt,num[500];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0},pos[25][25];
char mapp[25][25];
bool vis[25][25];
void dfs(int x,int y,int cnt){
    for(int i=0;i<=3;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(mapp[nx][ny]=='#'||nx<=0||nx>h||ny<=0||ny>w) continue;
        else{
            if(vis[nx][ny]==false){
                vis[nx][ny]=true;
                pos[nx][ny]=cnt;
                dfs(nx,ny,cnt);
            }
            else continue;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>w>>h;
    cnt=1;
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
        cin>>mapp[i][j];
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++){
            if(mapp[i][j]!='#'&&vis[i][j]==false){
            dfs(i,j,cnt);
            cnt++;
            }
        }
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++){
            if(mapp[i][j]!='#')
            num[pos[i][j]]++;
        }
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            if(mapp[i][j]=='@'){
            cout<<num[pos[i][j]];
            return 0;
            }
    return 0;
}