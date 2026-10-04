#include<bits/stdc++.h>
using namespace std;
char mapp[1010][1010];
bool visited[1010][1010];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int maxh,minh,maxz,minz,cnt;
void dfs(int x,int y){
    maxz=max(maxz,x);
    minz=min(minz,x);
    maxh=max(maxh,y);
    minh=min(minh,y);
    visited[x][y]=true,cnt++;
    for(int i=0;i<=3;i++){
        if(mapp[x+dx[i]][y+dy[i]]=='#'&&visited[x+dx[i]][y+dy[i]]==false)
        dfs(x+dx[i],y+dy[i]);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int r,c,ans=0;
    cin>>r>>c;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            cin>>mapp[i][j];
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++){
            if(mapp[i][j]=='#'&&visited[i][j]==false){
                cnt=0,maxh=0,minh=j,maxz=0,minz=i;
                dfs(i,j);
                if(cnt==(maxh-minh+1)*(maxz-minz+1)) ans++;
                else if(cnt==1) ans++;
                else{
                    cout<<"Bad placement.";
                    return 0;
                }
            }
        }
    cout<<"There are "<<ans<<" ships.";
    return 0;
}