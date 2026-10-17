#include<bits/stdc++.h>
using namespace std;
int n,m;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int door[26][4];
char mapp[305][305];
bool vis[305][305];
struct node{
    int x,y,step;
};
queue<node> q;
void bfs(int a,int b){
    q.push({a,b,0});
    vis[a][b]=true;
    while(!q.empty()){
        node cur=q.front();
        q.pop();
        // cout<<cur.x<<" "<<cur.y<<" "<<cur.step<<'\n';
        if(mapp[cur.x][cur.y]=='='){
            cout<<cur.step;//输入当前的
            return;
        }
        for(int i=0;i<=3;i++){
            int nx=cur.x+dx[i],ny=cur.y+dy[i];
            if(nx<1||nx>n||ny<1||ny>m||mapp[nx][ny]=='#'||vis[nx][ny]==true) continue;
            else if(mapp[nx][ny]=='.'||mapp[nx][ny]=='='){
                q.push({nx,ny,cur.step+1});
                vis[nx][ny]=true;
            }
            else if('A'<=mapp[nx][ny]&&mapp[nx][ny]<='Z'){
                int ans=mapp[nx][ny]-'A';
                if(door[ans][0]==nx&&door[ans][1]==ny){
                    if(vis[door[ans][2]][door[ans][3]]==false){
                        q.push({door[ans][2],door[ans][3],cur.step+1});
                        // vis[nx][ny]=true;//不能当单行道，默认bfs自己就能走到最短吧……
                        // vis[door[ans][2]][door[ans][3]]=true;
                    }
                }
                else{ 
                    if(vis[door[ans][0]][door[ans][1]]==false){
                    q.push({door[ans][0],door[ans][1],cur.step+1});
                    // vis[nx][ny]=true;
                    // vis[door[ans][0]][door[ans][1]]=true;
                    }
                }
            }
            else continue;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin>>mapp[i][j];
            if(mapp[i][j]!='.'&&mapp[i][j]!='#'&&mapp[i][j]!='@'&&mapp[i][j]!='='){
                int ans=mapp[i][j]-'A';
                if(door[ans][0]==0&&door[ans][1]==0) door[ans][0]=i,door[ans][1]=j;
                else door[ans][2]=i,door[ans][3]=j;
            }
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(mapp[i][j]=='@') bfs(i,j);
    return 0;
}