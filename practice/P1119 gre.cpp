#include<bits/stdc++.h>
using namespace std;
int n,m,q,now=0;
int mapp[205][205],tim[205];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(mapp,0x3f3f3f3f,sizeof(mapp));
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>tim[i];
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        mapp[u][v]=w,mapp[v][u]=w;
    }
    cin>>q;
    for(int i=1;i<=q;i++){
        int x,y,t;
        cin>>x>>y>>t;
        while(tim[now]<=t&&now<n){
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++){
                    if(mapp[j][k]>mapp[j][now]+mapp[now][k])
                    mapp[j][k]=mapp[j][now]+mapp[now][k];
                }
            now++;
        }
        if(mapp[x][y]==0x3f3f3f3f||tim[x]>t||tim[y]>t) cout<<"-1"<<'\n';
        else cout<<mapp[x][y]<<'\n';
    }
    return 0;
}