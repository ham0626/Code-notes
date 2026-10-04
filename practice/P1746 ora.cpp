#include<bits/stdc++.h>
using namespace std;
int n,fx,fy,tx,ty;
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
char pos[1010][1010];
int mapp[1010][1010];
bool vis[1010][1010];
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
        if(cur.x==tx&&cur.y==ty){
            cout<<cur.step;
            return;
        }
        for(int i=0;i<=3;i++){
            int nx=cur.x+dx[i],ny=cur.y+dy[i];
            if(cur.x<1||cur.x>n||cur.y<1||cur.y>n) continue;//避免越界元素进队列
            if(mapp[nx][ny]==0&&vis[nx][ny]==false){
                q.push({nx,ny,cur.step+1});//不要++,每个节点会累计
                vis[nx][ny]=true;
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>pos[i][j],mapp[i][j]=pos[i][j]-'0';
    cin>>fx>>fy>>tx>>ty;
    bfs(fx,fy);
    return 0;
}
