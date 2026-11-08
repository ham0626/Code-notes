#include<bits/stdc++.h>
using namespace std;
const int MAXN=3e3+5;
int n,p,r;
int timer,top,gro;
int head[MAXN];
int num[MAXN],val[MAXN],in[MAXN],pri[MAXN];
int dfn[MAXN],low[MAXN],belong[MAXN],stk[MAXN];
bool instk[MAXN];
struct Node{
    int fro,to,nxt;
}edge[8005];
void tarjan(int u){
    dfn[u]=low[u]=++timer;
    stk[++top]=u;
    instk[u]=true;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(dfn[v]==0){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instk[v]==true)
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
    memset(pri,0x3f3f3f3f,sizeof(pri));
    cin>>n>>p;
    for(int i=1;i<=p;i++) cin>>num[i]>>val[i];
    cin>>r;
    int cnt=1;
    for(int i=1;i<=r;i++){
        int a,b;
        cin>>a>>b;
        edge[cnt].fro=a,edge[cnt].to=b;
        edge[cnt].nxt=head[a];
        head[a]=cnt;
        cnt++;
    }
    for(int i=1;i<=n;i++){
        if(dfn[i]==0)
        tarjan(i);
    }
    for(int i=1;i<=r;i++){
        int u=edge[i].fro;
        int v=edge[i].to;
        if(belong[u]!=belong[v])
            in[belong[v]]++;
    }
    int flag=0;//能不能全部联通
    int sum=0;
    for(int i=1;i<=p;i++){
        int t=num[i];
        int v=val[i];
        pri[belong[t]]=min(pri[belong[t]],v);
    }
    for(int i=1;i<=gro;i++){
        if(in[i]==0){
            if(pri[i]==0x3f3f3f3f){//贿赂不了
                flag=1;
            }
            else sum+=pri[i];
        }
    }
    if(flag==0){
        cout<<"YES"<<'\n';
        cout<<sum;
    }
    else{
        cout<<"NO"<<"\n";//入度=0判断能不能掌控所有间谍(有没有孤立点)
        //控制不了的得再判一遍
        queue<int> q;
        bool vism[MAXN];
        memset(vism,0,sizeof(vism));
        for(int i=1;i<=p;i++){
            int u=num[i];
            if(vism[u]==false){
                vism[u]=true;
                q.push(u);
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int i=head[u];i;i=edge[i].nxt){
                int v=edge[i].to;
                if(vism[v]==false){
                    vism[v]=true;
                    q.push(v);
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(vism[i]==false){
                cout<<i;
                return 0;
            }
        }
    }
    return 0;
}