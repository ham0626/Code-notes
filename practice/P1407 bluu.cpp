#include<bits/stdc++.h>
using namespace std;
const int MAXN=8005;
int n,m,cnt=1;
int timer,top,gro;
int head[MAXN];
int dfn[MAXN],low[MAXN],belong[MAXN],stk[MAXN];
bool instk[MAXN];
int in[MAXN];//入度找环
string wif[4005],hus[4005];
unordered_map<string,int> id;//把名字变成数字
struct Node{
    int fro,to,nxt;
}edge[25000];
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
        else if(instk[v]==true)
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        gro++;
        while(true){
            int x=stk[top--];
            belong[x]=gro;
            instk[x]=false;
            if(x==u) break;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    //妻子->丈夫
    //丈夫->情人
    //如果丈夫和妻子在一个SCC里面(丈夫和情人在一起 妻子和情人的丈夫在一起)
    //那就Unsafe
    int lin=1;
    for(int i=1;i<=n;i++){
        cin>>wif[i]>>hus[i];
        int w,h;
        if(!id.count(wif[i])){
            id[wif[i]]=cnt;
            w=cnt;
            cnt++;
        }
        if(!id.count(hus[i])){
            id[hus[i]]=cnt;
            h=cnt;
            cnt++;
        }
        edge[lin].fro=w,edge[lin].to=h;
        edge[lin].nxt=head[w];
        head[w]=lin;
        lin++;
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        string g,b;
        cin>>g>>b;
        int gg=id[g];//情人的编号
        int bb=id[b];//丈夫的编号
        edge[lin].fro=bb,edge[lin].to=gg;
        edge[lin].nxt=head[bb];
        head[bb]=lin;
        lin++;
    }
    for(int i=1;i<=2*n;i++){
        if(dfn[i]==0) tarjan(i);
    }
    for(int i=1;i<=n;i++){
        int w=edge[i].fro;
        int h=edge[i].to;
        if(belong[w]==belong[h]){//n对婚姻
            cout<<"Unsafe"<<'\n';
        }
        else cout<<"Safe"<<'\n';
    }
    return 0;
}