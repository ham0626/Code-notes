#include<bits/stdc++.h>
using namespace std;
int n;
int cnth,cntv;
int mapp[255][255],match[255];
bool vis[255];
struct Line{
    int x1,y1,x2,y2;
}H[255],V[255];
bool dfs(int u){//u是行
    for(int i=1;i<=cntv;i++){
        if(mapp[u][i]==0) continue;//不认识 外校生
        if(vis[i]==true) continue;
        vis[i]=true;
        if(match[i]==0||dfs(match[i])==true){
            match[i]=u;//i相当于本校生的床
            return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if(y1==y2){
            cnth++;//横着的//y1==y2
            H[cnth]={min(x1,x2),y1,max(x1,x2),y2};
        }
        if(x1==x2){
            cntv++;//竖着的//x1==x2
            V[cntv]={x1,min(y1,y2),x2,max(y1,y2)};
        }
    }
    for(int i=1;i<=cntv;i++){//竖
        for(int j=1;j<=cnth;j++){//横
            if((H[j].x1<=V[i].x1&&V[i].x1<=H[j].x2)&&(V[i].y1<=H[j].y1&&H[j].y1<=V[i].y2)){
                mapp[j][i]=1;//横 竖
            }
        }
    }
    int ans=0;
    for(int i=1;i<=cnth;i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i)==true) ans++;
    }
    cout<<n-ans;
    return 0;
}