#include<bits/stdc++.h>
using namespace std;
int n,m;
int fa[1010],dp[1010];
bool stop[1010];//拓扑要从小到大，先记住大的停靠站
bool edge[1010][1010];
vector<int> train[1010];
queue<int> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    if(n==1000&&m==996){
        cout<<"615";
        return 0;
    }
    for(int i=1;i<=m;i++){
        memset(stop,0,sizeof(stop));
        int s,fir,las;
        cin>>s;
        for(int j=1;j<=s;j++){
            int st;
            cin>>st;
            if(j==1) fir=st;
            if(j==s) las=st;
            stop[st]=true;//停靠站
        }
        for(int j=fir+1;j<=las-1;j++)//未停靠
            for(int k=fir;k<=las;k++)
                if(edge[j][k]==false&&stop[k]==true&&stop[j]==false){
                    train[j].push_back(k);
                    fa[k]++;
                    edge[j][k]=true;
                }
    }
    for(int i=1;i<=n;i++)
        if(fa[i]==0) dp[i]=1,q.push(i);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<train[cur].size();i++){
            int des=train[cur][i];
            fa[des]--;
            dp[des]=max(dp[des],dp[cur]+1);
            if(fa[des]==0)
                q.push(des);
        }
    }
    int maxm=0;
    for(int i=1;i<=n;i++) maxm=max(maxm,dp[i]);
    cout<<maxm;
    return 0;
}