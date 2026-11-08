#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
int n,m,gro;
int timer,top;
int head[MAXN];
int dfn[MAXN],low[MAXN],belong[MAXN],stk[MAXN];
bool instk[MAXN];
//点和边都只能属于一个边双->点双/边双要在验证dfn==0的情况压入栈
//点双可以共割点 边双不能共享边和点
struct Node{
    int fro,to,nxt;
}edge[2*MAXN];
void tarjan(int u){
    dfn[u]=low[u]=++timer;
    instk[u]=true;
    stk[++top]=u;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(dfn[v]==0){
            tarjan(v);
            low[u]=min(low[u],low[v]);
            }
        else if(instk[v]==true)//*
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        gro++;
        while(true){
            int x=stk[top--];
            instk[x]=false;
            belong[x]=gro;
            if(x==u) break;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int cnt=1;
    //所有输入的下标表示这个点为真 输入下标+n代表这个点为假
    for(int k=1;k<=m;k++){
        int i,a,j,b;
        cin>>i>>a>>j>>b;
        //非A->B和非B->A
        int ri,fi,rj,fj;
        if(a==1){//统一把1~n当成真
            ri=i;
            fi=i+n;
        }
        else{
            ri=i+n;
            fi=i;
        }
        if(b==1){
            rj=j;
            fj=j+n;
        }
        else{
            rj=j+n;
            fj=j;
        }
        edge[cnt].fro=fj,edge[cnt].to=ri;//某一个不成立 另一个必须成立
        edge[cnt].nxt=head[fj];
        head[fj]=cnt;
        cnt++;
        edge[cnt].fro=fi,edge[cnt].to=rj;
        edge[cnt].nxt=head[fi];
        head[fi]=cnt;
        cnt++;
    }
    for(int i=1;i<=2*n;i++){
        if(dfn[i]==0)
        tarjan(i);
    }
    ///要求某一个点同时为真和假就不行
    for(int i=1;i<=n;i++){
        if(belong[i]==belong[i+n]){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    cout<<"POSSIBLE"<<'\n';
    //把i当成真 就是比较i和i+n哪个belong小 输出小的代表的真/假
    //永远谁小选谁
    for(int i=1;i<=n;i++){
        if(belong[i]<belong[i+n]) cout<<"1 ";//真
        else cout<<"0 ";//假
    }
    return 0;
}