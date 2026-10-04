#include<bits/stdc++.h>
using namespace std;
int n,m;
// bool flag=false;
char mapp[1510][1510];//浪费时间
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int vis[1510][1510][3];//存绝对坐标才能看出有没有绕一圈
// void dfs(int x,int y,int lx,int ly){//x,y绝对坐标，lx，ly相对(0,0)坐标
//     // if(lx>=n) lx=lx-n;//相对坐标，确保在访问时不越界
//     // if(ly>=m) ly=ly-m;//数字可能累加到很大
//     // if(lx<0) lx=lx+n;
//     // if(ly<0) ly=ly+m;
//     if(flag==true) return;
//     lx=(lx%n+n)%n;
//     ly=(ly%m+m)%m;
//     if(vis[lx][ly][1]!=0x3f3f3f3f&&vis[lx][ly][2]!=0x3f3f3f3f&&vis[lx][ly][0]==0){//来过
//         if(x-vis[lx][ly][1]!=0||y-vis[lx][ly][2]!=0){//绕圈循环了
//             flag=true;
//             return;
//         }
//         else return;//来过不绕圈
//     }
//     vis[lx][ly][0]=0;//标记来过
//     vis[lx][ly][1]=x;
//     vis[lx][ly][2]=y;//存绝对坐标
//     for(int i=0;i<=3;i++){
//         int nx=lx+dx[i],ny=ly+dy[i];//相对坐标改变
//         if(nx>=n) nx=nx-n;
//         if(ny>=m) ny=ny-m;
//         if(nx<0) nx=nx+n;
//         if(ny<0) ny=ny+m;
//         if(mapp[nx][ny]=='#') continue;
//         dfs(x+dx[i],y+dy[i],nx,ny);
//     }
//     return;
// }
struct node{
    int x,y,lx,ly;
};
bool bfs(int x,int y,int lx,int ly){
    queue<node> q;//局部队列
    q.push({x,y,lx,ly});
    vis[lx][ly][0]=0;//标记来过
    vis[lx][ly][1]=x;
    vis[lx][ly][2]=y;
    while(!q.empty()){
        node cur=q.front();
        q.pop();
        cur.lx=(cur.lx%n+n)%n;
        cur.ly=(cur.ly%m+m)%m;//调用当前q的元素
        vis[cur.lx][cur.ly][0]=0;//标记来过
        vis[cur.lx][cur.ly][1]=cur.x;
        vis[cur.lx][cur.ly][2]=cur.y;//存绝对坐标
        for(int i=0;i<=3;i++){
            int nx=cur.lx+dx[i],ny=cur.ly+dy[i];//相对坐标改变
            nx=(nx%n+n)%n;
            ny=(ny%m+m)%m;
            if(mapp[nx][ny]=='#') continue;
            if(vis[nx][ny][0]==0x3f3f3f3f){
                vis[nx][ny][0]=0;
                vis[nx][ny][1]=cur.x+dx[i];
                vis[nx][ny][2]=cur.y+dy[i];
                q.push({cur.x+dx[i],cur.y+dy[i],nx,ny});
            }
            else{
                if (vis[nx][ny][1]!=cur.x+dx[i]||vis[nx][ny][2]!=cur.y+dy[i]) return true;
            }
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    while(cin>>n>>m){
        // flag=false;
        memset(mapp,0,sizeof(mapp));
        memset(vis,0x3f3f3f3f,sizeof(vis));//***绝对坐标可以为负，换成极大值确保安全
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>mapp[i][j];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(mapp[i][j]=='S'){
                    // dfs(i,j,i,j);
                    if(bfs(i,j,i,j)) cout<<"Yes"<<'\n';
                    else cout<<"No"<<'\n';
                }
            }
    }
    return 0;
}
