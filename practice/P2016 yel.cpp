#include<bits/stdc++.h>
using namespace std;
int n,cnt=1;
int dp[1510][2];//在某个节点，放/不放
int start[1510];//从哪里开始是编号为x的边//某个节点的父亲是谁
struct node{
    int fro,to;
}tree[3010];
void dfs(int x,int fa){
    dp[x][0]=0;
    dp[x][1]=1;
    for(int i=start[x];i<=2*(n-1);i++){//n-1条无向边 2*(n-1)条有向边
        if(fa==tree[i].to) continue;//重复了
        if(tree[i].fro!=x) break;//换下一组了
        // par[tree[i].to]=x;
        dfs(tree[i].to,x);
        dp[x][0]+=dp[tree[i].to][1];//一直累加并找最小，推到根节点就是最小代价
        dp[x][1]+=min(dp[tree[i].to][1],dp[tree[i].to][0]);//树不是链 不能一个隔一个来
    }
}
bool comp(node x,node y){
    return x.fro<y.fro;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){//n个节点只有n-1条边
        int u,v,w;//标号,边数量,另一端
        cin>>u;
        cin>>v;
        if(v==0){
            // tree[cnt].fro=u;
            // tree[cnt].to=v;
            // cnt++;
            continue;
        }
        else{
            for(int i=1;i<=v;i++){
                cin>>w;
                tree[cnt].fro=u;
                tree[cnt].to=w;
                cnt++;
                tree[cnt].fro=w;
                tree[cnt].to=u;
                cnt++;
            }
        }
    }
    sort(tree+1,tree+cnt+1,comp);
    // cout<<cnt<<'\n';
    // for(int i=1;i<=cnt;i++) cout<<tree[i].fro<<" "<<tree[i].to<<'\n';
    for(int i=1;i<=cnt;i++){
        if(tree[i].fro!=tree[i-1].fro) start[tree[i].fro]=i;
    }
    dfs(0,0);//建树,dp
    cout<<min(dp[0][0],dp[0][1]);
    return 0;
}