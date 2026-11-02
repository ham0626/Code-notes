#include<bits/stdc++.h>
using namespace std;
int n;
int timer=0,top=0,gro=0;
int head[105];
int dfn[105],low[105],stk[105],belong[105];
int mapp[105][105];
bool instk[105];
int in[105],out[105];//入度 出度
struct Node{
    int fro,to,nxt;
}edge[5000];
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
        else if(instk[v]==true)//在队里
            low[u]=min(low[u],dfn[v]);
        else continue;
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
    cin>>n;
    int cnt=1;
    for(int i=1;i<=n;i++){
        while(true){
        int v;
        cin>>v;
        if(v==0) break;
        edge[cnt].fro=i,edge[cnt].to=v;
        edge[cnt].nxt=head[i];
        head[i]=cnt;
        cnt++;
        }
    }
    for(int i=1;i<=n;i++){
        if(dfn[i]==0) tarjan(i);
    }
    if(gro==1){
        cout<<"1"<<'\n'<<"0";
        return 0;
    }
    for(int i=1;i<cnt;i++){
        int u=edge[i].fro;
        int v=edge[i].to;
        if(belong[u]!=belong[v]){
            out[belong[u]]++;
            in[belong[v]]++;
        }
    }
    int ans1=0,ans2=0;
    for(int i=1;i<=gro;i++){
        if(in[i]==0) ans1++;
        if(out[i]==0) ans2++;
    }
    cout<<ans1<<'\n';
    cout<<max(ans1,ans2);
    return 0;
}