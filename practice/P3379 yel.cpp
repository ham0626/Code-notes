#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,m,s;
int head[MAXN],dep[MAXN];
int up[MAXN][25];//不能每层都记,不然[maxn][maxn]必爆炸
//二进制->每层都能跳到
struct Node{
    int fro,to,nxt;
}edge[2*MAXN];
void dfs(int u,int fa){
    dep[u]=dep[fa]+1;
    up[u][0]=fa;//往上跳2的0次方(1)就是父亲
    for(int i=1;i<=20;i++)
        up[u][i]=up[up[u][i-1]][i-1];
        //u是起点,i是跳2^i步
        //从u跳2^i步=先从u跳2^(i-1)步到v:v=up[u][i-1]
        //再从v跳2^(i-1)步up[v][i-1]
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==fa) continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
    }
    return;
}
int query(int a,int b){//a深b浅 a往上跳找b
    if(dep[a]<dep[b]) swap(a,b);
    for(int i=20;i>=0;i--){
        int v=up[a][i];//往上跳后的节点
        if(dep[v]>=dep[b])
            a=v;//v更深,还能跳
    }
    if(a==b) return a;//b就是a的祖先
    //现在a b在一层了 继续往上搜
    for(int i=20;i>=0;i--){
        if(up[a][i]!=up[b][i]){//没找到公共祖先
            a=up[a][i];
            b=up[b][i];
        }
    }//最后被卡在祖先下面一层
    return up[a][0];//再往上走一步
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>s;
    int cnt=1;
    for(int i=1;i<=n-1;i++){
        int x,y;
        cin>>x>>y;
        edge[cnt].fro=x;
        edge[cnt].to=y;
        edge[cnt].nxt=head[x],head[x]=cnt;
        cnt++;
        edge[cnt].to=x;
        edge[cnt].fro=y;
        edge[cnt].nxt=head[y],head[y]=cnt;
        cnt++;
    }
    dfs(s,0);//传入当前节点和其父节点
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        cout<<query(a,b)<<'\n';
    }
    return 0;
}