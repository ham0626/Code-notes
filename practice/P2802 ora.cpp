// #include<bits/stdc++.h>
// using namespace std;
// int n,m,mint=1000;
// int mapp[15][15];
// int vis[15][15][7];
// int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
// void dfs(int tim,int blo,int x,int y){
//     if(x>n||x<1) return;
//     if(y>m||y<1) return;
//     vis[x][y][blo]=tim;
//     if(blo==0&&mapp[x][y]!=3) return;
//     if(blo>0&&mapp[x][y]==3){//最后一步体力1->0到家也不行 回家blo>0
//         mint=min(mint,tim);
//         return;
//     }
//     if(tim>mint&&mapp[x][y]!=3) return;
//     for(int i=0;i<=3;i++){
//         if(mapp[x+dx[i]][y+dy[i]]==4&&vis[x+dx[i]][y+dy[i]][6]>=tim&&blo>=2) dfs(tim+1,6,x+dx[i],y+dy[i]);
//         else if(mapp[x+dx[i]][y+dy[i]]!=0&&mapp[x+dx[i]][y+dy[i]]!=4&&vis[x+dx[i]][y+dy[i]][blo-1]>=tim) dfs(tim+1,blo-1,x+dx[i],y+dy[i]);
//     }
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//         for(int j=1;j<=m;j++)
//             for(int k=0;k<=6;k++)
//                 vis[i][j][k]=1000;
//     for(int i=1;i<=n;i++)
//         for(int j=1;j<=m;j++)
//             cin>>mapp[i][j];
//     for(int i=1;i<=n;i++)
//         for(int j=1;j<=m;j++){
//             if(mapp[i][j]==2) dfs(0,6,i,j);
//         }
//     if(mint==1000) cout<<"-1";
//     else cout<<mint;
//     return 0;
// }
//BFS
#include<bits/stdc++.h>
using namespace std;
int mapp[15][15];
bool vis[15][15][7];//找最短，不走重复路
int n,m;
bool flag=false;
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
struct node{
    int x,y,tim,bol;
};
queue<node> q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>mapp[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(mapp[i][j]==2) q.push({i,j,0,6}),vis[i][j][6]=true;
    while(!q.empty()){
        node cur=q.front();
        q.pop();
        if(mapp[cur.x][cur.y]==3&&cur.bol>0){
            flag=true;
            cout<<cur.tim;
            return 0;
        }
        if(cur.bol==0) continue;
        for(int i=0;i<=3;i++){
            int nx=cur.x+dx[i],ny=cur.y+dy[i];
            if(nx<1||nx>n||ny<1||ny>m) continue;
            if(mapp[nx][ny]==4&&cur.bol>=2&&flag==false&&vis[nx][ny][6]==false){
                q.push({nx,ny,cur.tim+1,6});
                vis[nx][ny][6]=true;
            }
            else if(mapp[nx][ny]!=0&&flag==false&&vis[nx][ny][cur.bol-1]==false){
                q.push({nx,ny,cur.tim+1,cur.bol-1});
                vis[nx][ny][cur.bol-1]=true;
            }
        }
    }
    if(flag==false) cout<<"-1";
    return 0;
}