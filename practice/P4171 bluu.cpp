#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
int timer,top,gro;
int head[2*MAXN];
int dfn[2*MAXN],low[2*MAXN],stk[2*MAXN],belong[2*MAXN];
bool instk[2*MAXN];
struct Node{
    int fro,to,nxt;
}edge[2005];
int n,m,k;
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
    cin.tie(0),cout.tie(0);//i满 i+n汉
    cin>>k;
    while(k--){
        cin>>n>>m;
        memset(head,0,sizeof(head));
        memset(edge,0,sizeof(edge));
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(belong,0,sizeof(belong));
        memset(instk,0,sizeof(instk));
        timer=0,top=0,gro=0;
        int cnt=1;
        for(int i=1;i<=m;i++){
            string op1,op2;
            cin>>op1>>op2;
            int u=stoi(op1.substr(1));//第一道菜的序号
            int v=stoi(op2.substr(1));//第二道菜的序号
            int t1,t2,f1,f2;
            if(op1[0]=='m'){//第一道是满
                t1=u;//第一道菜满是真
                f1=u+n;
            }
            else{
                t1=u+n;
                f1=u;
            }
            if(op2[0]=='m'){//第二道是满
                t2=v;
                f2=v+n;
            }
            else{
                t2=v+n;
                f2=v;
            }
            edge[cnt].fro=f1,edge[cnt].to=t2;
            edge[cnt].nxt=head[f1];
            head[f1]=cnt;
            cnt++;
            edge[cnt].fro=f2,edge[cnt].to=t1;
            edge[cnt].nxt=head[f2];
            head[f2]=cnt;
            cnt++;
        }
        for(int i=1;i<=n;i++){
            if(dfn[i]==0) tarjan(i);
        }
        int flag=0;
        for(int i=1;i<=n;i++){
            if(belong[i]==belong[i+n]){
                flag=1;
                break;
            }
        }
        if(flag==0) cout<<"GOOD"<<'\n';
        else cout<<"BAD"<<'\n';
    }
    return 0;
}