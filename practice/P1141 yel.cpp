#include<bits/stdc++.h>
using namespace std;
char mapp[1010][1010];
int pos[1010][1010],ans[1010][1010],co[1000005];
int n,m,color;
bool flag=false;
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
struct node{
    int x,y,step;
};
queue<node> q;
void bfs(int x,int y,int col){
    co[col]=1;//自己是个色块
    q.push({x,y,0});
    ans[x][y]=col;
    while(!q.empty()){
        node cur=q.front();
        q.pop();
        if(pos[cur.x][cur.y]==1){
            for(int l=0;l<=3;l++){
                int nx=cur.x+dx[l],ny=cur.y+dy[l];
                if(nx<1||nx>n||ny<1||ny>n) continue;
                if(pos[nx][ny]==0&&ans[nx][ny]==0){
                    q.push({nx,ny,cur.step+1});
                    ans[nx][ny]=col;
                    co[col]++;
                }
                else continue;
            }
        }
        else{
            for(int i=0;i<=3;i++){
                int nx=cur.x+dx[i],ny=cur.y+dy[i];
                if(nx<1||nx>n||ny<1||ny>n) continue;
                if(pos[nx][ny]==1&&ans[nx][ny]==0){//必须为0，要不然联通但是颜色不同就说不过去了
                    q.push({nx,ny,cur.step+1});
                    ans[nx][ny]=col;
                    co[col]++;
                }
                else continue;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin>>mapp[i][j];
            pos[i][j]=mapp[i][j]-'0';
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(ans[i][j]==0) color++,bfs(i,j,color);
        }
    for(int i=1;i<=m;i++){
        int x,y,re;
        cin>>x>>y;
        re=ans[x][y];
        cout<<co[re]<<'\n';
    }
    return 0;
}