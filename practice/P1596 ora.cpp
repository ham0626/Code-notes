#include<bits/stdc++.h>
using namespace std;
char mapp[110][110];
bool vis[110][110];
int dx[8]={0,0,1,-1,1,1,-1,-1},dy[8]={1,-1,0,0,1,-1,1,-1};
int n,m,color;
struct node{
    int x,y,co;
};
queue<node> q;
void bfs(int x,int y,int co){
    q.push({x,y,co});
    vis[x][y]=true;
    while(!q.empty()){
        node cur=q.front();//一般数列用front
        q.pop();
        for(int i=0;i<=7;i++){
            int nx=cur.x+dx[i],ny=ny=cur.y+dy[i];
            if(nx<1||nx>n||ny<1||ny>m) continue;
            if(mapp[nx][ny]=='W'&&vis[nx][ny]==false) q.push({nx,ny,co}),vis[nx][ny]=true;
            else continue;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>mapp[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(mapp[i][j]=='W'&&vis[i][j]==false){
                color++;
                bfs(i,j,color);
            }
        }
    cout<<color;
    return 0;
}
