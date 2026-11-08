//有向图求SCC(强连通分量)->缩点/
//无向图求DCC(点/边双连通分量)->割点/割边
//点双:割点间一块内部没有割点的块(边界是割点)
//无向图需要放回头v==fa
//0个割点:一整块全部联通 必须有两个点才能确保
//1个割点:除了割点 建一个就行(n-1)
//>=2个割点:都能走 不用建
#include<bits/stdc++.h>
using namespace std;
const int MAXN=2005;
int n,s,t;
unsigned long long exi,meth=1;
int num=1,timer,top;
int head[MAXN];
long long dcc[MAXN];
long long dfn[MAXN],low[MAXN],stk[MAXN];//点双不需要belong
bool iscut[MAXN],vis[MAXN],re[MAXN];//stk存边序号
struct Node{
    int fro,to,nxt;
}edge[MAXN];//存边
void pre_tarjan(int u,int fa){
    dfn[u]=low[u]=++timer;
    int child=0;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==fa) continue;
        if(dfn[v]==0){//没搜过
            child++;
            pre_tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){//割点->割点前的是一个点双
                iscut[u]=true;
            }
        }
        else{//搜过但不是父亲:祖先
            if(dfn[v]<dfn[u])
            low[u]=min(dfn[v],low[u]);
        }
    }
    if(fa==0&&child>=2)//根节点
        iscut[u]=true;
    if(fa==0&&child<=1)
        iscut[u]=false;//纯环
    return;
}
void tarjan(int u,int fa){
    dfn[u]=low[u]=++timer;
    int child=0;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==fa) continue;
        if(dfn[v]==0){//没搜过
            child++;
            stk[++top]=i;//边进栈
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){//割点->割点前的是一个点双
                memset(vis,0,sizeof(vis));
                memset(re,0,sizeof(re));
                int sum=0;//孩子里面的割点数
                int num=0;//点双里的总点数
                while(true){
                    int x=stk[top--];
                    int uu=edge[x].fro;
                    int vv=edge[x].to;
                    if(re[uu]==false){//记点数
                        re[uu]=true;
                        num++;
                    }
                    if(re[vv]==false){//记点数
                        re[vv]=true;
                        num++;
                    }
                    if(iscut[uu]==true&&vis[uu]==false){
                        sum++;
                        vis[uu]=true;
                    }
                    if(iscut[vv]==true&&vis[vv]==false){
                        sum++;
                        vis[vv]=true;
                    }
                    if(x==i) break;
                }
                if(sum==1) exi+=1,meth*=(num-1);
                else if(sum==0) exi+=2,meth*=num*(num-1)/2;
                else continue;
            }
        }
        else{//搜过但不是父亲:祖先
            if(dfn[v]<dfn[u]){//其实是祖先:防止重边
            stk[++top]=i;//进栈
            low[u]=min(dfn[v],low[u]);
            }
        }
    }
    if(fa==0&&child>=2)
        iscut[u]=true;//是割点
        //不需要再弹了 已经弹空了
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    while(cin>>n&&n!=0){
        memset(head,0,sizeof(head));
        memset(low,0,sizeof(low));
        memset(dfn,0,sizeof(dfn));
        memset(iscut,0,sizeof(iscut));
        exi=0,meth=1;
        int cnt=1;
        int max_node=0;
        for(int i=1;i<=n;i++){
            cin>>s>>t;
            max_node=max(max_node,s);
            max_node=max(max_node,t);
            edge[cnt].fro=s,edge[cnt].to=t;
            edge[cnt].nxt=head[s];
            head[s]=cnt;
            cnt++;
            edge[cnt].fro=t,edge[cnt].to=s;
            edge[cnt].nxt=head[t];
            head[t]=cnt;
            cnt++;
        }
        int flag=0;
        for(int i=1;i<=max_node;i++){
            if(dfn[i]==0) pre_tarjan(i,0);
        }
        for(int i=1;i<=max_node;i++){
            if(iscut[i]==true) flag=1;
        }
        if(flag==0){//无割点
            cout<<"Case "<<num<<": ";
            cout<<"2 "<<max_node*(max_node-1)/2;
            cout<<'\n';
            num++;
            continue;
        }
        else{
            timer=0,top=0;
            memset(low,0,sizeof(low));
            memset(dfn,0,sizeof(dfn));
            for(int i=1;i<=max_node;i++){
            if(dfn[i]==0) tarjan(i,0);
            }
        }
        cout<<"Case "<<num<<": ";
        cout<<exi<<" "<<meth;
        cout<<'\n';
        num++;
    }
    return 0;
}